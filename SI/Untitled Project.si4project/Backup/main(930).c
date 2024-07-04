/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "hs_global.h"
#include "test.h"
//------------------
static int chars_rxed = 0;
static int  chars_rxed_0 = 0;
static int  chars_rxed_u = 0;

static volatile bool alarm_fired;
bool gCmdCheckFlag = false;
int sledSW = 0;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

const uint SEL_UART1_OUT = 8;

ui16 gNowBattLv =0;
ui16 gNowtemp   =0;

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_ModuleExit();

    exit(0);
}


int OLED_1in5_rgb_test_1(void);
extern void drv_lcd_1in5_oled(void);
extern void drv_send_inv();
extern void drv_recev_inv_tV7(void);
extern void drv_send_nml35(void);	

void gpwr (const uint gpNum, char onoff ){
	switch(onoff)	{
		case 1:
			gpio_put(gpNum, ON);
			break;
		case 0:
		default:
			gpio_put(gpNum, OFF);
			break;
	}
	
}	
//---------------------------
 unsigned long long gSysTimer = 0;

 int gSysCnt = 1;
 ui16 gDbgFuseCnt = 0;
 uc08 dbgLevel = 2;

 uc08 sendReactionTriger = 0;
 uc08 noRx_idleCnt = 0;
 uc08 swUsart4dbgshow = 0;

 uc08 iotSendSw=0;
 char SendTestPkt=0;
 uc08 iotState=0;
 char gMode_232=0;
 char gImd_reaction=0;
//------------------
 char	gdataSaveFlag = 0;
 char	gdataLoadFlag = 0;
 char   gLastChar_inv = 0;
 char   gNewCharInFlag = 0;
 char   gFlcdIni = 0;
 char   gfUse_iot = 0;
//---------------------------

//---------------------------
#define TEMPERATURE_UNITS 'C'

#define RX_BUFFER_SIZE0 1024
char rx_buffer0[RX_BUFFER_SIZE0];
unsigned int rx_wr_index0=0,rx_rd_index0=0,rx_counter0=0;
bool rx_buffer_overflow0 = false;


#define RX_BUFFER_SIZE1 1024
char rx_buffer1[RX_BUFFER_SIZE1];
unsigned int rx_wr_index1=0,rx_rd_index1=0,rx_counter1=0;
bool rx_buffer_overflow1= false;

#define DBG_BUFFER_SIZE 1024
char rx_buffer2[DBG_BUFFER_SIZE];
unsigned int rx_wr_index2=0,rx_rd_index2=0,rx_counter2=0;
bool rx_buffer_overflow2= false;

#define DBG_BUFFER_SIZE 1024
char rx_buffer3[DBG_BUFFER_SIZE];
unsigned int rx_wr_index3=0,rx_rd_index3=0,rx_counter3=0;
bool rx_buffer_overflow3= false;

#define USB_BUFFER_SIZE 1024
char rx_buffer_usb[USB_BUFFER_SIZE];
unsigned int rx_wr_index_u=0,rx_rd_index_u=0,rx_counter_u=0;
bool rx_buffer_overflow4= false;


char txdataInv[1024]={0};
char txdataIot[1024]={0};
char txdatadbg[1024]={0};

const uint8_t rarr[5] = {0xa0,0x02,0xa0,0xa0,0xa0};
extern uint8_t addr_24c_high;

 /* 12-bit conversion, assume max value == ADC_VREF == 3.3 V */
const float conversionFactor = 3.3f / (1 << 12);
 
int main() {
#ifndef PICO_DEFAULT_LED_PIN
//  #warning blink example requires a board with a regular LED
#else
//  #not ..  
#endif
	
    int i2c_errcode = 0;
	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
	//const uint i2c_default = i2c1_inst ;
	stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    tx_onoff485(INIT);
    tx_onoff485(ON);

	tx_op_selector(INIT);
	if(gfUse_iot == IOT_MODEM)
		tx_op_selector(OFF);
    else tx_op_selector(ON);  
		
    uart_ini_rx_int();

	if(dbgLevel > 0){
	// Send out a character without any conversions
	uart_putc_raw(UART_ID_0, 'A');
	// Send out a character but do CR/LF conversions
	uart_putc(UART_ID_0, 'B');
	// Send out a string, with CR/LF conversions
	uart_puts(UART_ID_0, " Hello, UART!\n");

	printf("Hello, world!\n");
	//uart_tx_program_init(pio, sm, offset, PIN_TX, SERIAL_BAUD);
	}
	
	alarm_fired = false;
	gSysCnt = 0;
	alarm_in_us(1000000 * 2);
	uart_puts(UART_ID_1, " Hello, UART!\n");




	spi_ini_dot();
	i2c_ini_dot();
	//exio_ini_dot();
	adc_init();
	
//	    gpio_init(SEL_UART1_OUT);
//	    gpio_set_dir(SEL_UART1_OUT, GPIO_OUT);
//		gpio_put(SEL_UART1_OUT, 0);

	load_eep_page();

	
	
    while (true) {
        //---------- 1ms tic --call back int.---------------- 
        if(alarm_fired == true) {
            alarm_fired = false;
            alarm_in_us(1000);
            gSysCnt++;
        }
        //--------------------------------------------------
            
       proc_1ms_tic();
	   on_uart_rx_0();	 
	   on_uart_rx_1();	
	   on_stdio_usb_rx();
	   
	   showHL();
	   drv_temp_check();	

	   #if 0
	   if(gMode_232 == KT_M2M){
	       drv_sendTcpControlM2M(); 
		}else{
		   drv_sendTcpControlLTE();
	    }
		#else
		   drv_send_nml35();	
		#endif
//------recive_app----------------- 	   		   	
       rs_rece_uart1_inv();
       rs_rece_uart0_iot();
	   rs_rece_usb_0();		
	   
	   drv_eep_at24c128();
	   //drv_send_uart0_inv();	
	   drv_lcd_1in5_oled();
	   //OLED_1in5_rgb_test_1();

//-----------------------------
	   if(gNewCharInFlag){ 	
		  gNewCharInFlag = 0;	
		  drv_recev_inv_tV7();
	   	}
	   drv_send_inv();
	   //drv_exio_pi4();
       opr_send485tx();
    }
}


void drv_send_uart0_inv(void){
		
}



void spi_ini_dot(void){
	// Enable SPI 0 at 1 MHz and connect to GPIOs
    spi_init(spi1, 200 * 1000);
    gpio_set_function(DOT_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(DOT_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(DOT_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
	//gpio_set_function(DOT_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);
    // Make the SPI pins available to picotool
	bi_decl(bi_3pins_with_func(DOT_DEFAULT_SPI_RX_PIN, DOT_DEFAULT_SPI_SCK_PIN, DOT_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI));
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(DOT_DEFAULT_SPI_CSN_PIN);
	gpio_set_dir(DOT_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
	gpio_put(DOT_DEFAULT_SPI_CSN_PIN, 1);
	bi_decl(bi_1pin_with_name(DOT_DEFAULT_SPI_CSN_PIN, "SPI CS"));
    
	gpio_init(DOT_DEFAULT_DEV_SEL_PIN);
	gpio_set_dir(DOT_DEFAULT_DEV_SEL_PIN, GPIO_OUT);
//	gpio_put(DOT_DEFAULT_DEV_SEL_PIN, 1);
	// Make the CS pin available to picotool
    
}

float cal_temp(float volt){
	float Tinfl;
	float tc ;
	float Voffs;
	float temp;
	
    if(volt < 1.5f){
	    Tinfl = 0;
		tc =  0.01;
	 	Voffs = 0.5;
    }else if(volt <= 1.7525f){
	    Tinfl = 100;
		tc =  0.0101;
	 	Voffs = 1.5;
    }else{
	    Tinfl = 125;
		tc =  0.0106;
	 	Voffs = 1.7525f;
    }

	temp = (volt - Voffs ) / tc + Tinfl ;

	return temp;
	
}

float cal_btl(float volt){
	float tmp_btl;
	const float devider_batt_val = 1.999f;
	tmp_btl = (volt / devider_batt_val);
	return tmp_btl;
}


ui16 sort_val(ui16 * arr , int cnt)
{
  unsigned int tempval_temp[10]= {0};	
  int y = 0;
  ui16 temp;
  ul32 valt;

  while(y < cnt){	
  	tempval_temp[y] = *arr++;
	y++;
  }
  for(y=0;y<8;y++)
  {
  	
    if(tempval_temp[y] > tempval_temp[y+1])
    {
        temp = tempval_temp[y];
        tempval_temp[y] = tempval_temp[y+1];
        tempval_temp[y+1] = temp;
    }
  }
  valt =(ul32)tempval_temp[2]+(ul32)tempval_temp[3]+(ul32)tempval_temp[4]+(ul32)tempval_temp[5];
  valt >>=2; 
   return (ui16)valt;  
}



void drv_temp_check(void){
		  float temperature;
		  float battLevel;
		  float volt ;
		  uint16_t result;
		  static ui16 i =0;
		  static ui16 tmp_table[10] = {0};
		  const float conversion_factor = 3.3f / (1 << 12);
		  static int dtSqc = 0;
		  static int tmp_cnt = 0;

		  if((gSysCnt - tmp_cnt) < 100) return;
		  tmp_cnt = gSysCnt;
		  
		  switch(dtSqc){
		  	case 0:
			  adc_gpio_init(26);
			  adc_select_input(0);
			  i = 0;
			  dtSqc++;
		  	break;
		    case 1:
			  result  = adc_read();
			  tmp_table[i++] = result;
			  if(i>= 8){
			  	dtSqc++;
			  	tmp_table[9] =  sort_val(tmp_table, 8);
			  	}
			break;
			case 2:
			  volt = tmp_table[9] * conversion_factor;
			  temperature = cal_temp(volt);
			  gNowtemp = temperature;
			  if(dbgLevel > 2)
			  printf("adVal: 0x%03x, voltage: %f V , tmp:%0.2f \n", result, volt , temperature);
			  
			  dtSqc++;	
		  	break;
			case 3:
				i = 0;
				adc_gpio_init(27);
				adc_select_input(1);
				dtSqc++;
			break;	
		    case 4:
	 			tmp_table[i++]	= adc_read();
				if(i >= 8){
					tmp_table[9] =	sort_val(tmp_table, 8);
		 		 	dtSqc++;		
					}
		  	break;
		    case 5:
				volt = tmp_table[9] * conversion_factor;
				battLevel = cal_btl(volt);
				gNowBattLv = battLevel;
				if(dbgLevel > 2)
			  	printf("adVal: 0x%03x, voltage: %f V , BATT:%0.2f \n", result, volt , battLevel);
				dtSqc++;	
		  	break;
		    case 6:
				dtSqc++;	
		  	break;
			default:
				dtSqc = 0;
			break;
			
		  }
	//result  = adc_read();
    //temperature =   read_onboard_temperature(TEMPERATURE_UNITS);
	
}

static void alarm_irq(void) {
    // Clear the alarm irq
    hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);

    // Assume alarm 0 has fired
    //printf("Alarm IRQ fired\n");
    alarm_fired = true;
}

static void alarm_in_us(uint32_t delay_us) {
    // Enable the interrupt for our alarm (the timer outputs 4 alarm irqs)
    hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);
    // Set irq handler for alarm irq
    irq_set_exclusive_handler(ALARM_IRQ, alarm_irq);
    // Enable the alarm irq
    irq_set_enabled(ALARM_IRQ, true);
    // Enable interrupt in block and at processor

    // Alarm is only 32 bits so if trying to delay more
    // than that need to be careful and keep track of the upper
    // bits
    uint64_t target = timer_hw->timerawl + delay_us;

    // Write the lower 32 bits of the target time to the alarm which
    // will arm it
    timer_hw->alarm[ALARM_NUM] = (uint32_t) target;
}

char getchar0_h(void){
    char data;
    while (rx_counter0==0);
    data=rx_buffer0[rx_rd_index0++];
//#if RX_BUFFER_SIZE1 != 256
    if (rx_rd_index0 == RX_BUFFER_SIZE0) rx_rd_index0=0;
//#endif
//#asm("cli")
    irq_set_enabled((uint)UART_ID_0, false); 
    --rx_counter0;
    irq_set_enabled((uint)UART_ID_0, true);
//#asm("sei")
    return data;

}

char getchar1_h(void){
    char data;
    while (rx_counter1==0);
    data=rx_buffer1[rx_rd_index1++];
	gLastChar_inv = data;  // INV: dot u1 > v7 u0 
//#if RX_BUFFER_SIZE1 != 256
    if (rx_rd_index1 == RX_BUFFER_SIZE1) rx_rd_index1=0;
//#endif
//#asm("cli")
    irq_set_enabled((uint)UART_ID_1, false); 
    --rx_counter1;
    irq_set_enabled((uint)UART_ID_1, true);
//#asm("sei")
    return data;

}

char getchar_usb_h(void){
    char data;
    while (rx_counter_u==0);
    data=rx_buffer_usb[rx_rd_index_u++];

//#if RX_BUFFER_SIZE1 != 256
    if (rx_rd_index_u == USB_BUFFER_SIZE) rx_rd_index_u=0;
//#endif
//#asm("cli")
//    irq_set_enabled((uint)UART_ID_1, false); 
    --rx_counter_u;
//    irq_set_enabled((uint)UART_ID_1, true);
//#asm("sei")
    return data;

}


void on_uart_rx_0() {
    static char olddata = 0;
    
    while (uart_is_readable(UART_ID_0)) {
        uint8_t ch = uart_getc(UART_ID_0);
        // Can we send it back?
         rx_buffer0[rx_wr_index0++]=ch;
         if (rx_wr_index0 == RX_BUFFER_SIZE0) rx_wr_index0=0;
         if (++rx_counter0 == RX_BUFFER_SIZE0)
            {
            rx_counter0=0;
            rx_buffer_overflow0=1;
            }
            olddata = ch;    
//        if (uart_is_writable(UART_ID_0)) {
            // Change it slightly first!
            //ch++;
           // printf("%c",ch);
//        }
        chars_rxed_0++;
        
    }
}

// RX interrupt handler
void on_uart_rx_1() {
    static char olddata = 0;
    while (uart_is_readable(UART_ID_1)) {
        uint8_t ch = uart_getc(UART_ID_1);
        // Can we send it back?
         rx_buffer1[rx_wr_index1++]=ch;
         if (rx_wr_index1 == RX_BUFFER_SIZE1) rx_wr_index1=0;
         if (++rx_counter1 == RX_BUFFER_SIZE1)
            {
            rx_counter1=0;
            rx_buffer_overflow1=1;
            }
            olddata = ch;    
//        if (uart_is_writable(UART_ID)) {
            // Change it slightly first!
            //ch++;
            //uart_putc(UART_ID, ch);
//        }
        chars_rxed++;
        
    }
}

//Rx int 
void on_stdio_usb_rx() {
    static char olddata = 0;
    while ( tud_cdc_available()) {
        uint8_t ch = tud_cdc_read_char();
        // Can we send it back?
         rx_buffer_usb[rx_wr_index_u++]=ch;
         if (rx_wr_index_u == USB_BUFFER_SIZE) rx_wr_index_u=0;
         if (++rx_counter_u == USB_BUFFER_SIZE)
            {
            rx_counter_u=0;
            rx_buffer_overflow4=1;
            }
            olddata = ch;    
//        if (uart_is_writable(UART_ID)) {
            // Change it slightly first!
            //ch++;
            //uart_putc(UART_ID, ch);
//        }

        chars_rxed_u++;
        
    }
}

void my_puts_string(char port ){
     uc08 * addr; 
     char dummy_port;
     
     switch(port){
        case ToINV:
            //irq_set_enabled((uint)UART_ID, false);
            // if( uart_is_writable(UART_ID_0) == 0) return;
            if(dbgLevel > 3) {
				sprintf(txdatadbg, ">1:%s",txdataInv);
				printf("%s",txdatadbg);
				memset(txdatadbg,0,sizeof(txdatadbg)); 
            	}
            addr = &txdataInv[0];
            while(uart_is_writable(UART_ID_1)){
                if(*addr == 0)break;
        		uart_putc(UART_ID_1, *addr);
        		*addr++=0;
            }
            //irq_set_enabled((uint)UART_ID, true);
        break;
        case ToIot:
            if(dbgLevel > 3) {
				sprintf(txdatadbg, ">0:%s",txdataIot);
				printf("%s",txdatadbg);
				memset(txdatadbg,0,sizeof(txdatadbg)); 
            	}
            addr = &txdataIot[0];
            while(*addr)
        	{
        		uart_putc(UART_ID_0, *addr);
        		*addr++=0;
        	}
        break;
        case ToDbg:
            printf("%s",&txdatadbg[0]);
            memset(txdatadbg,0,sizeof(txdatadbg)); 
        break;    
        default:
         memset(txdataInv,0,sizeof(txdataInv));
         memset(txdataIot,0,sizeof(txdataIot)); 
         
        break;    
    }
}

void my_nputs_string (char port,char * cmdbuf, int length ){
    int send_size;
    char * addr = cmdbuf;
    

    if(port > 2) return;
    if(length <= 0 )return;
    send_size =  length ;

    switch(port){
        case ToINV:
            if(send_size >= RX_BUFFER_SIZE1) send_size = RX_BUFFER_SIZE1;
            while(send_size--){
    		uart_putc(UART_ID_1, *addr);
    		*addr++=0;
            }
            break;
        case ToIot:
            if(send_size >= RX_BUFFER_SIZE0) send_size = RX_BUFFER_SIZE0;
            while(send_size--){
    		uart_putc(UART_ID_0, *addr);
    		*addr++=0;
            }
            break;
        case ToDbg:                        
            printf("%s\r\n",addr);
			memset(addr,0,sizeof(addr)); 
            break;
        default:
            
            break;
        }
        
}

void tx_onoff485(char onoff)
{
    switch(onoff)
    {
      case ON:
          gpio_put(UART_485_ENABLE, 1);
          break;
      case OFF:
          gpio_put(UART_485_ENABLE, 0);
          break;
      default: 
          gpio_init(UART_485_ENABLE);
          gpio_set_dir(UART_485_ENABLE,GPIO_OUT);
          break;
    };
}

void tx_op_selector(char onoff){

	switch(onoff)
	{
	  case ON:
		  gpio_put(TX0_OPTION_SEL, 1);
		  break;
	  case OFF:
		  gpio_put(TX0_OPTION_SEL, 0);
		  break;
	  default: 
		  gpio_init(TX0_OPTION_SEL);
		  gpio_set_dir(TX0_OPTION_SEL,GPIO_OUT);
		  break;
	};

}
void opr_send485tx(void)
{
    static int send_replay_timer=0;
    static uc08 send_replay_state=0;
    switch(send_replay_state)
        {
        case 0:
            if ((sendReactionTriger == 1) &&(noRx_idleCnt == 0) )
            {    
                send_replay_state++;
                send_replay_timer = gSysCnt ; 
            }    
            break;
        case 1:
            if((gSysCnt - send_replay_timer) < 20) break;
            tx_onoff485(ON);
            send_replay_timer = gSysCnt ; 
            send_replay_state++;
            break;
        case 2:
   // #if (__DEBUG_MODE_)
   			if(0) //dbg_show_flag == 1)
			{	
          	 	 if((gSysCnt - send_replay_timer) < 20) break;
           		 send_replay_timer = 20;
           		 //my_puts_string(dbg_data);
			}
  //  #endif    
            send_replay_state++;
        case 3:
            if((gSysCnt - send_replay_timer) < 100) break;
            my_puts_string(ToINV);
            send_replay_timer = gSysCnt ; 
            send_replay_state++;
            break;
        case 4:
            //if(tx_counter0 > 0) break;
            send_replay_timer = gSysCnt ; 
            send_replay_state++;
            //rx_counter0=0;
            //rx_rd_index0=0;
            //rx_wr_index0=0;
            break;
        case 5:
            if((gSysCnt - send_replay_timer) < 50) break;
//#if !(__DEBUG_MODE_)
//			if(dbg_show_flag == 0)
            tx_onoff485(OFF);
//#endif        
            send_replay_state=0;
            send_replay_timer = gSysCnt ; 
            sendReactionTriger = 0;
            break;
        default:
            send_replay_state = 0;
            sendReactionTriger = 0;
            break;
        
        }
}



void proc_1ms_tic(void) // no intterupt 
{
  static  int proc_100ms =0;
  static  int tic_10ms = 0;
  static  int proc_1s = 0;
  static  int tic_1ms = 0;
  static  int tic_60s =0 ;
  static  int tic_60m = 0;
  static  int timechcnt = 0;
  static  uc08 tgl = 0;	
  
  if(gSysCnt == tic_1ms ) return;
  tic_1ms = gSysCnt;
  

  if(tic_10ms++ < 9) return;
  //----proc 10ms --------{ 
 	tic_10ms = 0;
    
  //----proc 10ms --------}
  if(proc_100ms++ < 9) return;
  //----proc 100ms --------{    
    proc_100ms = 0 ;
    if(sledSW) {
        gpio_put(LED_PIN, 1);
        sledSW = 0;
        }else{
        sledSW = 1;
        gpio_put(LED_PIN, 0);
            }
    
  //----proc 100ms --------}
  if(proc_1s++ < 9) return;
  //----proc 1000ms -------- { 
    proc_1s = 0;
    gSysTimer++;
	

    //--------------------------
    DEC(gDbgFuseCnt);

  //----proc 1000ms -------- }
  if(tic_60s++ < 59) return;
  //----proc 60s -------- { 
    tic_60s = 0;
 
  //----proc 1t -------- }
  if(tic_60m++ < 59) return;
  tic_60m = 0;
  
}


void showHL(void){
    static uc08 opr_show;
	  static int tic_1000ms =  0;
		static signed int year = 0 , day = 0, TT =0 , mimu =0 , sec = 0 , temp;
		int timelevel = 0 ;

	if(gDbgFuseCnt > 0) return;
	
	if(gSysCnt - tic_1000ms < 1000) return;
  	tic_1000ms = gSysCnt;

  if(gSysTimer >= 31536000) timelevel++;
	if(gSysTimer >= 86400) timelevel++;
	if(gSysTimer >= 3600) timelevel++;


	switch (timelevel)
		{
		case 3:
				  year = gSysTimer / 31536000;
		case 2:
			      temp = gSysTimer % 31536000;
						day = 	temp / 86400;
		case 1:
			      temp = gSysTimer % 86400;
						TT = 	temp / 3600; 
		default:
			      temp = gSysTimer % 3600;
						mimu = 	temp / 60;
						sec =   temp % 60;
		break;
		}
	
    switch(dbgLevel){
        case 4:  
            //uart_putc_raw(UART_ID_0, '0');
						if(dbgLevel > 4){
							sprintf(txdataInv,"test0");
							sendReactionTriger = 1;
							}
            break;
        case 3:
							if(dbgLevel > 4 ){ 
				            sprintf(txdataIot,"test1");
				            my_puts_string(ToIot );
							}
        case 2:
            //printf("%s","test_d\r\n");
		case 1:		
        default:
					  sprintf(txdatadbg,"[%02d:%03d:%02d:%02d:%02d]\r\n",year,day,TT,mimu,sec);
				    my_puts_string(ToDbg);

						
            opr_show=0;
        break;    
        }
    //threading.Timer(1,showHL).start();
    }

void uart_ini_rx_int(void){
	uart_init(UART_ID_1, 115200);
	uart_init(UART_ID_0, 115200);
	

	// Set the TX and RX pins by using the function select on the GPIO
	// Set datasheet for more information on function select
	gpio_set_function(UART_TX_PIN_1, GPIO_FUNC_UART);
	gpio_set_function(UART_RX_PIN_1, GPIO_FUNC_UART);

	gpio_set_function(UART_TX_PIN_0, GPIO_FUNC_UART);
	gpio_set_function(UART_RX_PIN_0, GPIO_FUNC_UART);

	// Actually, we want a different speed
	// The call will return the actual baud rate selected, which will be as close as
	// possible to that requested
//	int __unused actual = uart_set_baudrate(UART_ID_0, BAUD_RATE_0);
//    int __unused actual_0 = uart_set_baudrate(UART_ID_0, BAUD_RATE_0);

	// Set UART flow control CTS/RTS, we don't want these, so turn them off
//	uart_set_hw_flow(UART_ID_0, false, false);
//	uart_set_hw_flow(UART_ID_0, false, false);

	// Set our data format
//	uart_set_format(UART_ID_0, DATA_BITS_0, STOP_BITS_0, PARITY_0);
//	  uart_set_format(UART_ID_0, DATA_BITS, STOP_BITS, PARITY);

	// Turn off FIFO's - we want to do this character by character
//	uart_set_fifo_enabled(UART_ID_0, false);
//	  uart_set_fifo_enabled(UART_ID_0, false);

	// Set up a RX interrupt
	// We need to set up the handler first
	// Select correct interrupt for the UART we are using
//	int UART_IRQ = UART_ID_0 == uart0 ? UART0_IRQ : UART1_IRQ;
//	  int UART_IRQ0 = UART_ID_0 == uart1 ? UART0_IRQ : UART1_IRQ;

	// And set up and enable the interrupt handlers
//	irq_set_exclusive_handler(UART_IRQ, on_uart_rx_0);
//	  irq_set_exclusive_handler(UART_IRQ0, on_uart_rx_0);
	
//	irq_set_enabled(UART_IRQ, true);
//	  irq_set_enabled(UART_IRQ0, true);

	// Now enable the UART to send interrupts - RX only
//	uart_set_irq_enables(UART_ID_0, true, false);
//	  uart_set_irq_enables(UART_ID_0, true, false);
	

	// OK, all set up.
	// Lets send a basic string out, and then run a loop and wait for RX interrupts
	// The handler will count them, but also reflect the incoming data back with a slight change!
//	uart_puts(UART_ID_0, "\nHello, uart interrupts\n");
//	  uart_puts(UART_ID_0, "\nHello, uart interrupts\n");
}

unsigned int  rp_cmd_len1;
unsigned char  rp_cmd_sqc1;
unsigned int  rp_cmd_idx1;

char rp_cmd_buf1[RX_BUFFER_SIZE1] = {0};

void rs_rece_uart1_inv(void)
  {
    char data , dtBuf  ;
    static char predata ;
    static uc08 index_r=0;
    char cmdbuf[RX_BUFFER_SIZE1+5] = {0} ;
	static unsigned char  rp_cmd_sub_sqc1;
	static int receive_timeout1;
    
    switch(rp_cmd_sqc1)
    {
    case 0:
      rp_cmd_len1 = 0;
      rp_cmd_idx1 = 0;
      rp_cmd_sub_sqc1 = 0;
      rp_cmd_sqc1++;
	  receive_timeout1 = gSysCnt;
      break;
    case 1:
       if(rx_wr_index1 != rx_rd_index1)  {
       	 gDbgFuseCnt = 5;	
         data = getchar1_h ();
	   	 gNewCharInFlag = 1;
		 receive_timeout1 = gSysCnt;
		 
         switch(data)
         {
         case 0x0a:  //CR
           if(predata == 0x0d) rp_cmd_sqc1++;
           //auto_read_cnt = 7;

		 default:  
           if(rp_cmd_len1 > (RX_BUFFER_SIZE1-2)) rp_cmd_len1 = (RX_BUFFER_SIZE1-2);
		   rp_cmd_buf1[rp_cmd_len1++] = data;
           rp_cmd_buf1[rp_cmd_len1] = 0;
		   predata = data;
          break;
         }
       }
	   if((gSysCnt - receive_timeout1) > 250)
	   	rp_cmd_sqc1 = 0;
       break;
     case 2:
        // flagUart3ReactionPasingComp = wiz_pasing_data(wiz_cmd_buf);
         if( dbgLevel >= 0  ){
			printf("\r\n<0:%s",rp_cmd_buf1);
			memset(rp_cmd_buf1,0,sizeof(rp_cmd_buf1));
         	}
           //my_Nput_string (DBG_PORT, wiz_cmd_buf, wiz_cmd_len );
           //sbi (flagSendData , DBG_PORT);
        
       rp_cmd_sub_sqc1 = 0;
       rp_cmd_sqc1 = 0;
       break;
     case 3:
 //      if(swUsart4dbgshow & bv(USARTDBGSWHOW_IN0))
 //      {
 //        sprintf(cmdbuf,"0<"); 
 //        strncpy(cmdbuf+2,wiz_cmd_buf,wiz_cmd_len);
 //        my_Nput_string (DBG_PORT, cmdbuf, wiz_cmd_len + 2 );
 //      }
 //      if(cmdPasingFromW107() == CMD_CONT ) wiz_cmd_sqc = 1;
 //      else wiz_cmd_sqc = 0; 
 //      break;
     default:
       rp_cmd_sqc1 = 0;
       break;
    }
  }






char rp_cmd_buf0[RX_BUFFER_SIZE0] = {0};

void rs_rece_uart0_iot(void)
     {
       char data , dtBuf  ;
       static ui16 subCmdStatPosition= 0;
       static char olddata;
       static int receive_timeout;
       unsigned char  rp_cmd_sub_sqc0;
       char cmdbuf[RX_BUFFER_SIZE0+5] = {0} ;

	   static unsigned int  rp_cmd_len0;
	   static unsigned char rp_cmd_sqc0;
	   static unsigned int  rp_cmd_idx0;

       switch(rp_cmd_sqc0)
       {
       case 0:
         rp_cmd_len0 = 0;
         rp_cmd_idx0 = 0;
         rp_cmd_sub_sqc0 = 0;
         subCmdStatPosition = 0;
         rp_cmd_sqc0++; 
         receive_timeout  = gSysCnt;
         break;
       case 1:
           if(rx_wr_index0 != rx_rd_index0) {
               gDbgFuseCnt = 5; 
               data = getchar0_h ();
               receive_timeout = gSysCnt;
             
               switch(data)
               {
               case ' ':  //CR                //--  check < 
                   if(olddata == '>') gImd_reaction = 1;
               case 0x0a:
                   if(olddata == 0x0d) rp_cmd_sqc0++;
               
               default:
         //        if(dbgLevel > 0)
         //          putchar1 (data);
                 if(rp_cmd_len0 >= (RX_BUFFER_SIZE0 - 2)) rp_cmd_len0 = (RX_BUFFER_SIZE0 - 2);
                 rp_cmd_buf0[rp_cmd_len0++] = data;
                 rp_cmd_buf0[rp_cmd_len0] = 0;
                 olddata = data;
                break;
               }
             }
             if((gSysCnt - receive_timeout ) > 250)
              rp_cmd_sqc0 = 0;        
         break;
       case 2:
         if(dbgLevel >= 0){
               sprintf(cmdbuf,"\r\n<1:");
               strncpy(&cmdbuf[5],rp_cmd_buf0,rp_cmd_len0);
               my_nputs_string (ToDbg, cmdbuf, rp_cmd_len0 + 3 );
            }
         Cmd_judge (rp_cmd_buf0);
         rp_cmd_sub_sqc0 = 0;
         rp_cmd_sqc0 = 0;
         break;
       case 3:
       default:
         rp_cmd_sqc0 = 0;
         break;
       }
     }


void rs_rece_usb_0(void)	  {
						 char data , dtBuf	;
						 static ui16 subCmdStatPosition= 0;
						 static char olddata;
						 static int receive_timeout;
						 unsigned char	rp_cmd_sub_sqc0;
					 static unsigned int sCntuCnt = 0;
					 
						 char cmdbuf[USB_BUFFER_SIZE+5] = {0} ;
		  
					 static unsigned int  rp_cmd_len0;
					 static unsigned char rp_cmd_sqc0;
					 static unsigned int  rp_cmd_idx0;
		  
						 switch(rp_cmd_sqc0)
						 {
						 case 0:
							 rp_cmd_len0 = 0;
							 rp_cmd_idx0 = 0;
							 rp_cmd_sub_sqc0 = 0;
							 subCmdStatPosition = 0;
							 rp_cmd_sqc0++; 
							 receive_timeout  = gSysCnt;
					 sCntuCnt = 0;
							 break;
						 case 1:
								 if(rx_wr_index_u != rx_rd_index_u) {
										 gDbgFuseCnt = 3; 
										 data = getchar_usb_h ();
										 receive_timeout = gSysCnt;
							 if(sCntuCnt == 0){
								  sCntuCnt = 200;
								sprintf(cmdbuf,"<U:");
								  printf("%s", cmdbuf );
							  }
							 
										 switch(data)
										 {
										 case ' ':	//CR							  //--	check < 
											  // if(olddata == '>') gImd_reaction = 1;
										 case 0x0a:
												 if(olddata == 0x0d) rp_cmd_sqc0++;
										 
										 default:
							 // 			 if(dbgLevel > 0)
							 // 				 putchar1 (data);
											 if(rp_cmd_len0 >= (USB_BUFFER_SIZE - 2)) rp_cmd_len0 = (USB_BUFFER_SIZE - 2);
											 rp_cmd_buf0[rp_cmd_len0++] = data;
											 rp_cmd_buf0[rp_cmd_len0] = 0;
											 olddata = data;
										  break;
										 }
		  
									 }
									 if(gSysCnt != receive_timeout ){
									  receive_timeout = gSysCnt;
									  DEC(sCntuCnt);
									  }
						 if(sCntuCnt == 0){
							 if(rp_cmd_len0 != 0)
							 rp_cmd_sqc0++;
						  }  
							 break;
						 case 2:
							 memcpy(cmdbuf,rp_cmd_buf0,rp_cmd_len0);
						   my_nputs_string (ToDbg, cmdbuf, rp_cmd_len0 );
		  //			 memcpy(txdataInv,cmdbuf,rp_cmd_len0);
		  //				 sendReactionTriger = 1;
					 
							 Cmd_judge (rp_cmd_buf0);
							 
							 rp_cmd_sub_sqc0 = 0;
							 rp_cmd_sqc0 = 0;
							 break;
						 case 3:
						 default:
							 rp_cmd_sqc0 = 0;
							 break;
						 }
					 }


