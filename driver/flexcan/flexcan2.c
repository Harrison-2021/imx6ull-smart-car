// #include "imx6ull.h"

// typedef struct{
//     int index;
//     int id;
//     int word0;
//     int word1;
//     int size;
// }mb_data_t;

// void flexcan_gpio_init(void)
// {
//     //0010 ALT2 — Select mux mode: ALT2 mux port: FLEXCAN2_TX of instance: flexcan2
//     IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO22 &= ~(0xf << 0);
//     IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO22 |=  (0x2 << 0);
    
//     //0010 ALT2 — Select mux mode: ALT2 mux port: FLEXCAN2_RX of instance: flexcan2
//     IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO23 &= ~(0xf << 0);
//     IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO23 |=  (0x2 << 0);

//     return;
// }

// void flexcan_clock_init(void)
// {
//     //0 pll3_main_clk : 480MHZ
//     CCM_CCSR &= ~(1 << 0);

//     //00 derive clock from pll3_sw_clk divided clock (60M)
//     CCM_CSCMR2 &= ~(0x3 << 8);
//     //000000 divide by 1
//     CCM_CSCMR2 &= ~(0x3f << 2);

//     //can2_clk_enable
//     //can2_serial_clk_enable
//     CCM_CCGR0  |= (0x33 << 18);

//     return;
// }

// void flexcan_can_init(CAN_Type *base)
// {
//     /*
//      MDIS [31] 0 Enable the FLEXCAN module
//     */
//     base->MCR &= ~(1 << 31);

//     /*
//      SOFT_RST [25] 1 Reset the registers
//      The SOFT_RST bit remains asserted while reset is pending, and is
//      automatically negated when reset completes.
//     */
//     base->MCR |= (1 << 25);
//     while(base->MCR & (1 << 25))
//     {

//     }

//     /*
//      FRZ  [30] 1 Enabled to enter Freeze Mode
//      HALT [28] 1 Enters Freeze Mode if the FRZ bit is asserted.
//     */
//     base->MCR |= (1 << 30) | (1 << 28);
 
//     /*
//      SRX_DIS [17] 1 Self reception disabled
//     */
//     base->MCR |= (1 << 17);

//     /*
//      MAXMB [6:0] Number of the last MB = MAXMB
//     */
//     base->MCR &= ~(0x7f << 0);
//     base->MCR |=  (63 << 0  );

//     /*
//      FRZ  [30] 0 Not enabled to enter Freeze Mode
//      HALT [28] 0 No Freeze Mode request.
//     */
//     base->MCR &= ~((1 << 30) | (1 << 28));

//     return;
// }

// void flexcan_bit_timing_init(CAN_Type *base)
// {

// #if 0
// set CAN bit-rate 500000 = 500K,75% sample rate
// FLEXCAN_TIME_QUANTA_NUM = 1 + (PSEG1 + 1) + (PSEG2 + 1) + (PROPSEG + 1);
//                         = 1 + (6 + 1) + (4 + 1) + (6 + 1)
//                         = 20

// bit-rate = fTq/(number of Time Quanta)
// fTq      = bit-rate * (number of Time Quanta)
//          = 500000   * 20
//          = 10000000

// fCANCLK  = 60MHZ
// fTq      = fCANCLK / (Prescaler value);
//          = 60MHZ   / PV
        
// PV       = 60MHZ/fTq = 60MHZ/10000000 = 6
// #endif
//     /*
//      FRZ  [30] 1 Enabled to enter Freeze Mode
//      HALT [28] 1 Enters Freeze Mode if the FRZ bit is asserted.
//     */
//     base->MCR |= (1 << 30) | (1 << 28);


//     /*
//      PRESDIV [31–24]  Sclock frequency = CPI clock frequency / (PRESDIV+1)
//      RJW     [23–22]  Resync Jump Width = RJW + 1. 
//                       The valid programmable values are 0-3.

//      PSEG1   [21–19]  Phase Buffer Segment 1 = (PSEG1 + 1) x Time-Quanta.
//                       The valid programmable values are 0-7

//      PSEG2   [18–16]  Phase Buffer Segment 2 = (PSEG2 + 1) x Time-Quanta.
//                       The valid programmable values are 1-7
//      PROP_SEG [2-0 ]  Propagation Segment Time = (PROPSEG + 1) * Time-Quanta
//                       The valid programmable values are 0-7                 
//     */
//     base->CTRL1 = (5 << 24) |(0 << 22) | (6 << 19) | (4 << 16) | (6 << 0);

//     /*
//      FRZ  [30] 0 Not enabled to enter Freeze Mode
//      HALT [28] 0 No Freeze Mode request.
//     */
//     base->MCR &= ~((1 << 30) | (1 << 28));

//     return;
// }

// void flexcan_tx_MB_config(CAN_Type *base,mb_data_t *mb)
// {
//     /*
//      CODE [27:24] 0b1000: INACTIVE - MB is not active
//                   0b1100: DATA -MB is a Tx Data Frame (MB RTR must be 0)
//      DLC  [19:16] Length of Data in Bytes
//     */
//    base->MB[mb->index].CS  = (0x8 << 24) | (mb->size << 16);

//    /*
//     ID Standard [28:18]  Frame Identifier
//    */
//    base->MB[mb->index].ID = (mb->id << 18);
  
//    base->MB[mb->index].WORD0 = mb->word0;
//    base->MB[mb->index].WORD1 = mb->word1;

//    /*Active MB*/
//    base->MB[mb->index].CS |= (0xc << 24); // 注意是|=,否则会清空前面的cs值

//    return ;
// }

// void flexcan_rx_MB_config(CAN_Type *base,int index,int id)
// {
//     /*
//      CODE [27:24] 0b0000: INACTIVE - MB is not active.
//                   0b0100: EMPTY - MB is active and empty.
//     */
//    base->MB[index].CS =  0x0;


//    base->MB[index].WORD0 = 0;
//    base->MB[index].WORD1 = 0;

//    /*Active MB*/
//    base->MB[index].CS |= (0x4 << 24);

//    /*
//     ID Standard [28:18]  Frame Identifier
//    */
//    base->MB[index].ID = (id << 18);

//    return;
// }

// void flexcan_send_data(CAN_Type *base,int can_id,uint8_t *buf,int size)
// {
//     int i;
//     int flag;
//     mb_data_t mb;
//     uint32_t word0 = 0;
//     uint32_t word1 = 0;
  
//     mb.id    = can_id;
//     /*MB8 for tx*/
//     mb.index = 8;
//     mb.size  = size;
    
//     /*
//      word0 : DATA BYTE 0 |  DATA BYTE 1 |  DATA BYTE 2 | DATA BYTE 3
//      word1 : DATA BYTE 4 |  DATA BYTE 5 |  DATA BYTE 6 | DATA BYTE 7
//     */
//    if(size - 4 > 0){
//       for(i = 0;i < 4;i ++){
//         word0 |= (buf[i] << (24 - i * 8));
//       }

//       for(i = 0;i < size - 4;i ++){
//         word1 |= (buf[4 + i] << (24 - i * 8));
//       }
//    }else{
//       for(i = 0;i < size;i ++){
//         word0 |= (buf[i] << (24 - i * 8));
//       }
//    }

//    mb.word0 = word0;
//    mb.word1 = word1;

//    flexcan_tx_MB_config(base,&mb);
   
//    /*1 The corresponding MB has successfully completed transmission or reception*/
//    do{
//         flag = base->IFLAG1 & (1 << 8);
//    }while(!flag);

//    /* The Interrupt flag must be cleared by writing it to '1'.*/
//    base->IFLAG1 |= (1 << 8);

//    return;
// }

// int flexcan_recv_data(CAN_Type *base,int can_id,uint8_t *buf,int size)
// {
//     int i;
//     int rx_size;
//     int flag;
//     uint8_t code;
//     uint32_t word0 = 0;
//     uint32_t word1 = 0;

//     /*1 The corresponding MB has successfully completed transmission or reception*/
//     do{
//         flag = base->IFLAG1 & (1 << 9);
//     }while(!flag);

//     /*0b0010: FULL - MB is full.*/
//     code = (base->MB[9].CS  >> 24) & 0xf;
//     if(code != 2){
//         uart_printf("Fail to flexcan recv data\r\n");
//         return -1;
//     }

//     rx_size  = (base->MB[9].CS  >> 16) & 0xf;
//     if(rx_size > size){
//         uart_printf("recv buf is too small\r\n");
//         return -1; 

//     }
//     word0 = base->MB[9].WORD0;
//     word1 = base->MB[9].WORD1;

//     /*
//      word0 : DATA BYTE 0 |  DATA BYTE 1 |  DATA BYTE 2 | DATA BYTE 3
//      word1 : DATA BYTE 4 |  DATA BYTE 5 |  DATA BYTE 6 | DATA BYTE 7
//     */
//     if(rx_size > 4){
//         for(i = 0;i < 4;i ++){
//             buf[i] = word0 >> 24;
//             word0  = word0 <<  8;
//         }

//         for(i = 0;i < rx_size - 4;i ++){
//             buf[i + 4] = word1 >> 24;
//             word1      = word1 <<  8;  
//         }
//     }else{
//         for(i = 0;i < rx_size;i ++){
//             buf[i] = word0 >> 24;
//             word0  = word0 <<  8;
//         }
//     }

//    /* The Interrupt flag must be cleared by writing it to '1'.*/
//    base->IFLAG1 |= (1 << 9);

//    /*MB9 for rx*/
//    flexcan_rx_MB_config(base,9,can_id);

//    return rx_size;
// }

// void flexcan_loopback_enable(CAN_Type *base)
// {
//     /*
//      FRZ  [30] 1 Enabled to enter Freeze Mode
//      HALT [28] 1 Enters Freeze Mode if the FRZ bit is asserted.
//     */
//     base->MCR |= (1 << 30) | (1 << 28); 
//     /*
//      LPB  [12] 1 Loop Back enabled
//                0 Loop Back disabled
//     */
//     base->CTRL1 |= (1 << 12);

//      /*
//      FRZ  [30] 0 Not enabled to enter Freeze Mode
//      HALT [28] 0 No Freeze Mode request.
//     */
//     base->MCR &= ~((1 << 30) | (1 << 28));

//     return;
// }

// void flexcan_loopback_disable(CAN_Type *base)
// {
//     /*
//      FRZ  [30] 1 Enabled to enter Freeze Mode
//      HALT [28] 1 Enters Freeze Mode if the FRZ bit is asserted.
//     */
//     base->MCR |= (1 << 30) | (1 << 28); 
//     /*
//      LPB  [12] 1 Loop Back enabled
//                0 Loop Back disabled
//     */
//     base->CTRL1 &= ~(1 << 12);

//      /*
//      FRZ  [30] 0 Not enabled to enter Freeze Mode
//      HALT [28] 0 No Freeze Mode request.
//     */
//     base->MCR &= ~((1 << 30) | (1 << 28));

//     return;
// }

// void flexcan_loopback_test(void)
// {
//     int i;
//     int j;
//     int size;
//     uint8_t rx_buf[8];
//     uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

//     flexcan_gpio_init();
//     flexcan_clock_init();
//     flexcan_can_init(CAN2);
//     flexcan_bit_timing_init(CAN2);
//     flexcan_loopback_enable(CAN2);

//     /*MB9 for rx*/
//     flexcan_rx_MB_config(CAN2,9,0x520);

//     while(1){
//         for(i = 0;i < sizeof(tx_buf);i ++){
//             flexcan_send_data(CAN2,0x520,tx_buf,i + 1);
//             uart_printf("flexcan send data ok\r\n");
//             size = flexcan_recv_data(CAN2,0x520,rx_buf,sizeof(rx_buf));
//             uart_printf("can rx:");
//             for(j = 0;j < size;j ++){
//                 uart_printf("%x ",rx_buf[j]);
//             }
//             uart_printf("\r\n");
//             flexcan_rx_MB_config(CAN2,9,0x520);
//             gpt_delay_ms(500);
//         }
//     }

//     return;
// }


// int flexcan_interrupt_handler(int id)
// {
//     int j;
//     int size;
//     uint8_t rx_buf[8];

//     size = flexcan_recv_data(CAN2,0x120,rx_buf,sizeof(rx_buf));
//     uart_printf("can rx:");
//     for(j = 0;j < size;j ++){
//         uart_printf("%x ",rx_buf[j]);
//     }
//     uart_printf("\r\n");

//     return;
// }

// void flexcan_interrupt_init(CAN_Type *base,int mb_index)
// {
//     /*Enable flexcan interrupt*/
//     if(mb_index < 32){
//         base->IMASK1 |= (1 << (mb_index));
//     }else{
//         base->IMASK2 |= (1 << (mb_index - 32));
//     }
//     request_irq(CAN2_IRQn,flexcan_interrupt_handler);
//     enable_irq();

//     return;
// }

// void flexcan_normal_test(void)
// {
//     int i;
//     int j;
//     uint8_t tx_buf[ ] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};

//     flexcan_gpio_init();
//     flexcan_clock_init();
//     flexcan_bit_timing_init(CAN2);
//     flexcan_loopback_disable(CAN2);
//     flexcan_interrupt_init(CAN2,9);

//     /*MB9 for rx*/
//     flexcan_rx_MB_config(CAN2,9,0x120);

//     while(1){
//         for(i = 0;i < sizeof(tx_buf);i ++){
//             flexcan_send_data(CAN2,0x520,tx_buf,i + 1);
//             uart_printf("flexcan send data ok\r\n");
     
//             gpt_delay_ms(1000);
//         }
//     }

//     return;
// }
