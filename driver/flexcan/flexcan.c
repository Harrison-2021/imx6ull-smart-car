#include"flexcan.h"

void flexcan_gpio_init() {
    //0010 ALT2 — FLEXCAN2_TX of instance
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO22 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO22 |=  (0x2 << 0);

    // 0010 ALT2 — FLEXCAN2_RX of instance
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO23 &= ~(0xf << 0);
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO23 |=  (0x2 << 0);
}

void flexcan_clock_init() {
    // 1.[0] 0 pl3_main_clk: 480MHz
    CCM_CCSR &= ~(1 << 0);

    // 2.[9-8] 0b00 can_clk_sel: /8 = 60MHz
    //   [7-2] 0b000000 can_clk_podf: divide by 1: 60MHz
    CCM_CSCMR2 &= ~((0x3 << 8) | (0x3f << 2));

    // 3.enable can2 clock
    // [21-20] 11 can2_serial clock
    // [19-18] 11 can2 clock
    CCM_CCGR0 |= (0xf << 18);

}

void flexcan_can_init(CAN_Type *base) {
    /* 1.MDIS[31] 0 enable flexcan mode*/
    base->MCR &= ~(1 << 31);

    /*
     2.SOFT_RST[25] 1 Reset the registers
     it may take some time to fully propagate its effect,
     The SOFT_RST bit remains asserted while reset is pending, 
     and is automatically negated when reset completes.
    */
    base->MCR |= (1 << 25);
    while(base->MCR & (1 << 25)) {
        uart_printf("wait reset \r\n");
    }

    /*
     3.在进行一些can配置时，要求必须进入冻结模式，配置完后，再解除冻结模式
       FRZ[30] 1 Enabled to enter Freeze Mode
      HALT[28] 1 Enters Freeze Mode if the FRZ bit is asserted.
    */
    flexcan_freeze_enable(base);

    /*
     4.SRX_DIS [17] 1 Self reception disabled-开启的话，MB无法使用
    */
    base->MCR |= (1 << 17);

    /*
     5.MAXMB [6:0] Number of the last MB = MAXMB
    */
    base->MCR &= ~(0x7f << 0);
    base->MCR |=  (63 << 0); // [0-63],共64个buffer

    /*
     6.配置完后，再解除冻结模式
     FRZ [30] 0 Not enabled to enter Freeze Mode
    HALT [28] 0 No Freeze Mode request.
    */
    flexcan_freeze_disable(base);
}

void flexcan_freeze_enable(CAN_Type *base) {
    /*
     在进行一些can配置时，要求必须进入冻结模式，配置完后，再解除冻结模式
       FRZ[30] 1 Enabled to enter Freeze Mode
      HALT[28] 1 Enters Freeze Mode if the FRZ bit is asserted.
    */
    base->MCR |= (1 << 28) | (1 << 30);
}

void flexcan_freeze_disable(CAN_Type *base) {
    /*
     配置完后，再解除冻结模式
     FRZ [30] 0 Not enabled to enter Freeze Mode
    HALT [28] 0 No Freeze Mode request.
    */
    base->MCR &= ~((1 << 30) | (1 << 28));
}

void flexcan_sample_bitRate_init(CAN_Type *base) {
    #if 0
    set CAN bit-rate 500000 = 500K,75% sample rate
    FLEXCAN_TIME_QUANTA_NUM = 1 + (PSEG1 + 1) + (PSEG2 + 1) + (PROPSEG + 1);
                            = 1 + (6 + 1) + (4 + 1) + (6 + 1)
                            = 20

    bit-rate = fTq/(number of Time Quanta)
       ->fTq = bit-rate * (number of Time Quanta)
             = 500000   * 20
             = 10000000 = 10MHz-->Tq = 0.1us

    fCANCLK  = 60MHZ
    fTq      = fCANCLK / (Prescaler value);
             = 60MHZ   / PV
            
        ->PV = 60MHZ/fTq = 60MHZ/10000000 = 6
    #endif
    
    /*1.控制器配置前，要先进入冻结模式,结束配置后，解冻
     FRZ  [30] 1 Enabled to enter Freeze Mode
     HALT [28] 1 Enters Freeze Mode if the FRZ bit is asserted.
    */
    flexcan_freeze_enable(base);

    /*2.控制器设置
     PRESDIV [31–24]  Sclock frequency = CPI clock frequency / (PRESDIV+1)
     RJW     [23–22]  Resync Jump Width = RJW + 1. 
                      The valid programmable values are 0-3.
                      通过对相位缓冲段加减`SJW`吸收误差。SJW加大后允许误差加大，但通信速度下降

     PSEG1   [21–19]  Phase Buffer Segment 1 = (PSEG1 + 1) x Time-Quanta.
                      The valid programmable values are 0-7

     PSEG2   [18–16]  Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta.
                      The valid programmable values are 1-7
     PROP_SEG [2-0 ]  Propagation Segment Time = (PROPSEG + 1) * Time-Quanta
                      The valid programmable values are 0-7                 
    */
    base->CTRL1 = (5 << 24) | (0 << 22) | (6 << 19) | (4 << 16) | (6 << 0);

    /*3.解冻 */
    flexcan_freeze_disable(base);
}

void flexcan_tx_MB_config(CAN_Type *base, mb_data_t *mb) {
    /* 1.先inactive,准备发送数据
     CODE [27:24] 0b1000: INACTIVE - MB is not active
    */
    base->MB[mb->index].CS = (0x8 << 24);

    /*2.发送id，size,数据
    DLC         [19:16] Length of Data in Bytes
    ID Standard [28:18]  Frame Identifier
   */
    base->MB[mb->index].CS |= (mb->size << 16);
    base->MB[mb->index].ID = (mb->id << 18);
    base->MB[mb->index].WORD0 = mb->word0;
    base->MB[mb->index].WORD1 = mb->word1;

    /*3.数据准备好后，进行Active MB,发送完成后，会触发中断标志位
    CODE [27:24] 0b1100: DATA -MB is a Tx Data Frame (MB RTR must be 0)
   */
    base->MB[mb->index].CS |= (0xc << 24);// 注意是|=,否则会清空前面的cs值
}

void flexcan_rx_MB_config(CAN_Type *base, int index, int id) {
    /*1.inactiveMB,准备接收数据
     CODE [27:24] 0b0000: INACTIVE - MB is not active.
    */
    base->MB[index].CS = 0;

    /*2.写入iD,接收指定ID的帧数据
    ID Standard [28:18]  Frame Identifier
    */
    base->MB[index].ID = (id << 18);
    base->MB[index].WORD0 = 0;
    base->MB[index].WORD1 = 0;

    /*3.Active MB，开始接收数据，接收成功后code会变为0010 full状态
    CODE [27:24] 0b0100: EMPTY - MB is active and empty.-开启MB,初始的CODE字段状态为empty*/ 
    base->MB[index].CS |= (0x4 << 24);
}

void flexcan_send_data(CAN_Type *base, int id, uint8_t *buf, int size) {
    /*
    1.先准备要发送的数据，要以帧格式写入MB中
    word0 : DATA BYTE 0 |  DATA BYTE 1 |  DATA BYTE 2 | DATA BYTE 3
    word1 : DATA BYTE 4 |  DATA BYTE 5 |  DATA BYTE 6 | DATA BYTE 7
    */
    mb_data_t mb;
    mb.id = id;
    mb.size = size;
    mb.index = TX_MB_INDEX; // 读写buffer的index不同，读写都要经过缓冲区
    uint32_t word0 = 0;
    uint32_t word1 = 0;
    int i,flag;
    if(size > 4) { // 要放入两个32位的内存中
        for(i = 0; i < 4; i++) { // 字节序大端模式，低字节放在高位
            word0 |= (buf[i] << (24 - i * 8));
        }
        for(i = 4; i < size; i++) {
            word1 |= (buf[i] << (24 - (i - 4) * 8));
        }
    } else {
        for(i = 0; i < size; i++) { // 字节序大端模式，低字节放在高位
            word0 |= (buf[i] << (24 - i * 8));
        }
    }
    mb.word0 = word0;
    mb.word1 = word1;

    /* 2.将准备好的数据写入MB中 */
    flexcan_tx_MB_config(base, &mb);

    /* 3.等待发送，直到发送完成，产生中断标志位（轮循方式判定），
         并非产生中断，要产生中断，需要设置mask寄存器
   [31-8] Each bit flags the respective MB(MB8 to MB31) interrupt
   1 responding MB has successfully completed transmission or reception*/
   do {
        flag = base->IFLAG1 & (1 << TX_MB_INDEX);
        // uart_printf("wait iflag1: ");
   } while(!flag);


   /* 4.发送完成后，要清除中断标志位，写1清除
   CPU must clear the corresponding IFLAG before starting to prepare this MB for a 	newtransmission or reception.
   The Interrupt flag must be cleared by writing it to '1'.*/
   base->IFLAG1 |= (1 << TX_MB_INDEX);
}

/* 在接收数据前，要先配置好MB,才能开始接收数据 */
int flexcan_recv_data(CAN_Type *base, int id, uint8_t *buf, int size) {
    /* 1.等待接收，直到接收完成，产生中断标志位（轮循方式判定）
   [31-8] Each bit flags the respective MB(MB8 to MB31) interrupt
   1 responding MB has successfully completed transmission or reception*/
    int flag, i;
    do {
        flag = base->IFLAG1 & (1 << RX_MB_INDEX);
        // uart_printf("wait reve iflag1: \r\n");
    } while(!flag);

   /*2.同时判断MB是否接收成功，full标志
    0b0010: FULL - MB is full.*/
    int code = (base->MB[RX_MB_INDEX].CS >> 24) & 0xf;
    if(code != 2) {
        uart_printf("Fail to flexcan recv data\r\n");
        return -1;
    }

    /* 3.接收成功后，进行处理数据（打印接收的字节）
    注意需求接收的字节数不能超高实际MB中的大小*/
    int rev_size = 0;
    rev_size = (base->MB[RX_MB_INDEX].CS >> 16) & 0xf;
    
    if(rev_size > size) {
        uart_printf("recv buf is too small\r\n");
        return -1;
    }
    int word0 = base->MB[RX_MB_INDEX].WORD0;
    int word1 = base->MB[RX_MB_INDEX].WORD1;
    /*
     word0 : DATA BYTE 0 |  DATA BYTE 1 |  DATA BYTE 2 | DATA BYTE 3
     word1 : DATA BYTE 4 |  DATA BYTE 5 |  DATA BYTE 6 | DATA BYTE 7
    */
    if(rev_size > 4) {
        for(i = 0; i < 4; i++) {
            buf[i] = word0 >> 24;
            word0  <<= 8;
        }
        for(i = 4; i < rev_size; i++) {
            buf[i] = word1 >> 24;
            word1  <<= 8;
        } 
    } else {
        for(i = 0; i < rev_size; i++) {
            buf[i] = word0 >> 24;
            word0 <<=  8;
        }
    }

    /* 4.清除中断位
   The Interrupt flag must be cleared by writing it to '1'.*/
    base->IFLAG1 |= (1 << RX_MB_INDEX);

    /* 5.重新配置接收MB,准备接收下一帧数据
   MB9 for rx*/
    flexcan_rx_MB_config(base, RX_MB_INDEX, id);

    return rev_size;
}

/* 回环测试 */
void flexcan_loopback_enable(CAN_Type *base) {
    /* 1.进入冻结模式，控制进行设置 */
    flexcan_freeze_enable(base);

    /* 2.回环模式开启 
    LPB  [12] 1 Loop Back enabled
              0 Loop Back disabled
    */
    base->CTRL1 |= (1 << 12);

    /* 3.解冻 */
    flexcan_freeze_disable(base);
}

void flexcan_loopback_disable(CAN_Type *base) {
    /* 1.进入冻结模式，控制进行设置 */
    flexcan_freeze_enable(base);

    /* 2.回环模式开启 
    LPB  [12] 1 Loop Back enabled
              0 Loop Back disabled
    */
    base->CTRL1 &= ~(1 << 12);

    /* 3.解冻 */
    flexcan_freeze_disable(base);
}

void flexcan_loopback_test() {
    int size = 0;
    uint8_t rx_buf[8];
    uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

    flexcan_gpio_init();
    flexcan_clock_init();
    // flexcan_can_init(CAN2);
    // flexcan_freeze_enable(CAN2);
    // flexcan_freeze_disable(CAN2);
    flexcan_sample_bitRate_init(CAN2); // 注意，采样率和波特率要设置
    flexcan_loopback_enable(CAN2);

    flexcan_rx_MB_config(CAN2, RX_MB_INDEX, 0x233);

    int i, j;
    while(1) {
        for(i = 0; i < sizeof(tx_buf); i++) {
            // 回环测试的id，发送与接受一定要相同
            flexcan_send_data(CAN2, 0x233, tx_buf, i + 1); 
            uart_printf("flexcan send data ok\r\n");
            size = flexcan_recv_data(CAN2,0x233,rx_buf,sizeof(rx_buf));
            uart_printf("can rx: ");
            for(j = 0;j < size;j ++){
                uart_printf("%x ",rx_buf[j]);
            }
            uart_printf("\r\n");
            gpt_delay_ms(500);
        }
    }
}

/* 正常收发测试 */
void flexcan_interrupt_init(CAN_Type *base, int mb_index) {
    /*Enable flexcan interrupt*/
    if(mb_index < 32) {
        base->IMASK1 |= (1 << (mb_index));
    } else {
        base->IMASK2 |= (1 << (mb_index - 32));
    }
    /* 注册中断 */
    request_irq(CAN2_IRQn, flexcan_interrupt_handler);
    /* arm使能中断 */
    enable_irq();
}

/* 注意，此id是中断号，不是报文id */
int flexcan_interrupt_handler(int id) {
    int j, size;
    uint8_t rx_buf[8];

    /* 发送和接受到数据后，会产生中断，在中断函数中打印接收的数据 */
    size = flexcan_recv_data(CAN2, 0x120, rx_buf, sizeof(rx_buf));
    uart_printf("can rx:");
    for(j = 0;j < size;j ++){
        uart_printf("%x ",rx_buf[j]);
    }
    uart_printf("\r\n");
}

void flexcan_normal_test() {
    int i;
    int j;
    uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

    flexcan_gpio_init();
    flexcan_clock_init();
    flexcan_sample_bitRate_init(CAN2);
    flexcan_loopback_disable(CAN2);
    flexcan_interrupt_init(CAN2,RX_MB_INDEX);

    /*MB9 for rx*/
    flexcan_rx_MB_config(CAN2,RX_MB_INDEX,0x120);

    while(1){
        for(i = 0;i < sizeof(tx_buf);i ++){
            flexcan_send_data(CAN2,0x230,tx_buf,i + 1);
            // uart_printf("flexcan send data ok\r\n");
     
            gpt_delay_ms(1000);
        }
    }
}