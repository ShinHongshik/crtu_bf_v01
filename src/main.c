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
static int chars_rxed_u =0 ;
static volatile bool alarm_fired;
bool gCmdCheckFlag = false;
int sledSW = 0;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

const uint SEL_UART1_OUT = 8;

float gNowBattLv =0;
float gNowtemp   =0;
float gNowBLack_V = 0;
int   gfBlackOut = 0;

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_ModuleExit();

    exit(0);
}

void adc_ini_crtu(void);
int OLED_1in5_rgb_test_1(void);
extern void drv_lcd_1in5_oled(void);
extern void drv_send_inv();
extern void drv_recev_inv_tV7(void);
extern void drv_send_nml35(void);	
extern int save_eep_page (void);
extern int load_eep_page (void);
//extern void drv_lora_nml35(void);
extern uc08 Cmd_judge_lora(char * dest);
extern void drv_key_check(void);
extern void drv_adc_internal(void);
void vib_check(void);
void black_out_check(void);
void pwrsw_check(void);

//-----------------------------------------------------

volatile int itrt_cnt = 0;

void gpio_callback(uint gpio, uint32_t events){
	itrt_cnt++;
}


//----------------------------------------------------- 
 unsigned long long gSysTimer = 0;

 int gSysCnt = 1;
 ui16 gDbgFuseCnt = 0;
 uc08 dbgLevel = 0;
 int  gResetSw =0;
 uc08 sendReactionTriger = 0;
 uc08 noRx_idleCnt = 0;
 uc08 swUsart4dbgshow = 0;

 uc08 iotSendSw=0;
 char SendTestPkt=0;
 uc08 iotState=0;
 char gMode_232=0;
 char gImd_reaction=0;
 char gIotDev = 0 ;
//------------------
 char	gdataSaveFlag = 0;
 char	gdataLoadFlag = 0;
 char   gLastChar_inv = 0;
 char   gNewCharInFlag = 0;
 //---------------------
 char gfLcdRefash = 0;
 char   gFlcdIni = 0;
 ui16 gflcdsleep_n = 0;
 
 char   gfUse_iot = 0;
 int 	gkey = 0 ;
ui16 nml35State = 0; 
//---------------------------
my_dev devInfo = {0};

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


#define PK_BUFFER_SIZE 1024
char rx_buffer_pk[PK_BUFFER_SIZE];
unsigned int rx_wr_index_pk =0,rx_rd_index_pk=0,rx_counter_pk=0;
bool rx_buffer_overflow_pk= false;


char txdataInv[1024]={0};
char txdataIot[1024]={0};
char txdatadbg[1024]={0};


const uint8_t rarr[5] = {0xa0,0x02,0xa0,0xa0,0xa0};
extern uint8_t addr_24c_high;

 /* 12-bit conversion, assume max value == ADC_VREF == 3.3 V */
const float conversionFactor = 3.3f / (1 << 12);

enum OPR_STAS{OPR_ON_IS,SYSPOWER_IS,PORTINIT_IS,VALLOAD_IS,SYSTIMER_IS
	,UART_IS,I2C_IS,SPISET_IS,LCDSET_IS,ADC_IS};
int gfSystem_state = 0 ;
 
int main() {
#ifndef PICO_DEFAULT_LED_PIN
//  #warning blink example requires a board with a regular LED
#else
//  #not ..  
#endif
  
  int i2c_errcode = 0;
	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
	//const uint i2c_default = i2c1_inst ;
	sbi(gfSystem_state,SYSPOWER_IS);
	alarm_fired = false;
	gSysCnt = 0;
	alarm_in_us(1000000 * 2);
	gflcdsleep_n = 3000;
  uart_ini_rx_int();
//----------------ini-------------------------------------	
	//const uint i2c_default = i2c1_inst ;
	stdio_init_all();
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
	
    tx_onoff485(INIT);
    tx_onoff485(OFF);

	sbi(gfSystem_state,PORTINIT_IS);

	sbi(gfSystem_state,UART_IS);
	spi_ini_dot();
	i2c_ini_dot();
	adc_ini_crtu();
	load_eep_page();

	
	itrt_cnt = 0;
	gpio_set_irq_enabled_with_callback(22, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
	

	//uart_puts(UART_ID_0, " Hello, UART!\n");
	gpio_init(HW_WATCHDOG);
	gpio_set_dir(HW_WATCHDOG, GPIO_OUT);

   while (true) {
        //---------- 1ms tic --call back int.---------------- 
     if(alarm_fired == true) {
            alarm_fired = false;
            alarm_in_us(1000);
            gSysCnt++;
     	}
     //---sys handle-----------------------------------------------
       proc_1ms_tic();
	   on_uart_rx_0();	 
	   on_uart_rx_1();	
	   on_stdio_usb_rx();
		 //------------------------------------------
	   showHL();
	   //drv_temp_check();	
//-----------------------------
      

     if(gfUse_iot == IOT_MODEM){
	 		if(gMode_232 == KT_M2M){
	 		 	drv_sendTcpControlM2M(); 
	 		}else{
	 			drv_sendTcpControlLTE();
	 		}
	 		if(gNewCharInFlag){  
	 			 gNewCharInFlag = 0;  
	 			 drv_recev_inv_tV7();
	 		}
			rs_rece_uart0_iot();
	 		drv_send_inv();
	 	}
//-----------------------------
		rs_rece_usb_0();
		rs_rece_uart1_inv();
    
//---------------------------
    //drv_send_uart0_inv();	
    //OLED_1in5_rgb_test_1();
    
    pwrsw_check(); //  pwr off  -> on :  lcd ini at usb used 
    vib_check();
		black_out_check();
    drv_key_check();
		drv_adc_internal();
    drv_eep_at24c128();
    drv_lcd_1in5_oled();
    opr_send485tx();
		
    }
}

//	
//	void drv_send_uart0_inv(void){
//			
//	}
//	

void pwrsw_check(void){
	static sDrv_val sqc_pc = {0};
	
	if((gSysCnt - sqc_pc.cnt) < sqc_pc.delay ) return;
	sqc_pc.cnt  = gSysCnt; 
	
	switch(sqc_pc.sqc){
		case 0: // wait_boot on 
			sqc_pc.delay = 5000;
			sqc_pc.sqc++;
			break;
		case 1:
			sqc_pc.delay = 1000;
			sqc_pc.sqc++;
			break;
		case 2:	
			if(gNowtemp < -30.0f) sqc_pc.sqc++;
			break;
		case 3:
			if(gNowtemp > -30.0f) sqc_pc.sqc++;
			break;
		case 4:
			if(gFlcdIni == 0)gFlcdIni = 1;
			sqc_pc.sqc = 0;
		default:
			sqc_pc.sqc = 0;
			break;
			
	}
		
}
void vib_check(void){
	static int itrt_cnt_old =0;
	static int interv = 1000;
	static uc08 sqc_vc = 0;

	if((gSysCnt - itrt_cnt_old) < 1000 ) return;
	itrt_cnt_old  = gSysCnt; 

	if(itrt_cnt > 5){
		printf("%d/1s_vib!!",itrt_cnt);
		gflcdsleep_n = 3000;
	}	
	itrt_cnt = 0;
};

void black_out_check(void){
	static int sqc_boc = 0;
	static int cnt_boc = 0;
	
	if((gSysCnt - cnt_boc) < 1000 ) return;
	cnt_boc  = gSysCnt; 

	switch(sqc_boc){
		case 0:
			if(gfBlackOut == 1) sqc_boc++;
		break;	
		case 1:
			DEC(gflcdsleep_n);
			if(gfBlackOut == 0) sqc_boc++;
		break;	
		case 2:  
			// go lcd sleep 
			if(gfBlackOut == 0) sqc_boc = 0 ;
			gFlcdIni = 1;
		break;
		default:
		break;	
	}

}



void adc_ini_crtu(void){
	adc_init();
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
    
//	gpio_init(DOT_DEFAULT_DEV_SEL_PIN);
//	gpio_set_dir(DOT_DEFAULT_DEV_SEL_PIN, GPIO_OUT);
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
	const float devider_batt_val = 0.499f;
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


ui16 read_adc_th(void){
		return adc_read();
}

void drv_temp_check(void){
		  float volt ;
		  uint16_t result;
		  static ui16 i =0;
		  static ui16 tmp_table[10] = {0};
		  const float conversion_factor = 3.3f / (1 << 12);
		  static int dtSqc = 0;
			static sDrv_val sDtc = {0};

				
		  if((gSysCnt - sDtc.cnt) < sDtc.delay) return;
		  sDtc.cnt = gSysCnt;
		  
		  switch(sDtc.sqc){
		  	case 0:
			  adc_gpio_init(26);
			  adc_select_input(0);
			  i = 0;
			  sDtc.sqc++;
				sDtc.delay = 0;
		  	break;
		    case 1:
			  result  = read_adc_th();
			  tmp_table[i++] = result;
			  if(i>= 8){
			  	sDtc.sqc++;
			  	tmp_table[9] =  sort_val(tmp_table, 8);
			  	}
			break;
			case 2:
			  volt = tmp_table[9] * conversion_factor;
			  gNowtemp = cal_temp(volt);
			  if(dbgLevel > 2)
			  printf("adVal: 0x%03x, voltage: %f V , tmp:%0.2f \n", result, volt , gNowtemp);
			  
			  sDtc.sqc++;	
		  	break;
			case 3:
				i = 0;
				adc_gpio_init(27);
				adc_select_input(1);
				sDtc.sqc++;
			break;	
		    case 4:
	 			tmp_table[i++]	= read_adc_th();
				if(i >= 8){
					tmp_table[9] =	sort_val(tmp_table, 8);
		 		 	sDtc.sqc++;		
					}
		  	break;
		    case 5:
				volt = tmp_table[9] * conversion_factor;
				gNowBattLv = cal_btl(volt);
				if(dbgLevel > 2)
			  	printf("adVal: 0x%03x, voltage: %f V , BATT:%0.2f \n", result, volt , gNowBattLv);
				sDtc.sqc++;	
		  	break;
		    case 6:
				sDtc.sqc++;	
		  	break;
			default:
				sDtc.sqc = 0;
			break;
			
		  }
	//result  = adc_read();
    //temperature =   read_onboard_temperature(TEMPERATURE_UNITS);
	
}


void drv_adc_internal(void){
	static int tmp_cnt = 0;
	static int sqc_ai;
	ui16 result;
	const float conversion_factor = 3.3f / (1 << 12);
	static ui16 tmp_table[11] = {0};
	static ui16 avg_val[3] = {0};
	static ui16 i = 0;
	float volt,batt,temp,BL_L;
	static int bl_cnt = 0;
	
	if((gSysCnt - tmp_cnt) < 100) return;
	tmp_cnt = gSysCnt;

	switch(sqc_ai){
		case 0:
			adc_select_input(0);
			sqc_ai++;
		break;
		case 1:
			tmp_table[i++] = adc_read();
			if(i >= 8){
				i = 0;
				avg_val[0] =	sort_val(tmp_table, 8);
				adc_select_input(1);
				sqc_ai++;
			}
		break;
		case 2:
			tmp_table[i++] = adc_read();
			if(i >= 8){
				i = 0;
				avg_val[1] =	sort_val(tmp_table, 8);
				adc_select_input(2);
				sqc_ai++;
			}
		break;
		case 3:
			tmp_table[i++] = adc_read();
			if(i >= 8){
				i = 0;
				avg_val[2] =	sort_val(tmp_table, 8);
				adc_select_input(0);
				sqc_ai++;
			}
		break;
		case 4:
			volt =	avg_val[0] * conversion_factor;
			gNowtemp = cal_temp(volt);
			volt = avg_val[1] * conversion_factor;
			gNowBattLv = cal_btl(volt);
			volt = avg_val[2] * conversion_factor;
			gNowBLack_V = volt;
			printf("batt: %0.2f, BL : %0.2f V , tmp:%0.2f \n",gNowBattLv, gNowBLack_V, gNowtemp);
			
			if(gNowBLack_V > 1) bl_cnt++;
			else DEC(bl_cnt);
			if(bl_cnt > 5) gfBlackOut = 1;
			else gfBlackOut = 0;
			
			sqc_ai++;			
		break;	
		case 5:	
			if(i-- == 0) sqc_ai = 0;
		break;	
		default:
			adc_gpio_init(26);
			adc_gpio_init(27);
			adc_gpio_init(28);
		break;

	}
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

char getchar1_pk(void){
    char data;
    //while (rx_counter_pk==0);
    data=rx_buffer_pk[rx_rd_index_pk++];
//	gLastChar_inv = data;  // INV: dot u1 > v7 u0 
//#if RX_BUFFER_SIZE1 != 256
    if (rx_rd_index_pk == PK_BUFFER_SIZE) rx_rd_index_pk=0;
//#endif
//#asm("cli")
//    irq_set_enabled((uint)UART_ID_1, false); 
    --rx_counter_pk;
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



void stack_to_pkbuf(char * addr , int num){
    static char olddata = 0;
		int len = num ;
       // uint8_t ch = uart_getc(UART_ID_1);
        // Can we send it back?
         while(len--){
	         rx_buffer_pk[rx_wr_index_pk++]=*addr++;
	         if (rx_wr_index_pk == PK_BUFFER_SIZE) rx_wr_index_pk=0;
	         if (++rx_counter_pk == PK_BUFFER_SIZE)
	            {
	            rx_counter_pk=0;
	            rx_buffer_overflow_pk=1;
	            }
	           // olddata = ch;
         	} 
	//        if (uart_is_writable(UART_ID)) {
	            // Change it slightly first!
	            //ch++;
	            //uart_putc(UART_ID, ch);
	//        	}
  //      chars_rxed++;
        
}


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
            if(dbgLevel >= 2) {
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

  
  if(gSysCnt == tic_1ms ) return;
  tic_1ms = gSysCnt;
  

  if(tic_10ms++ < 9) return;
  tic_10ms = 0;
	//----proc 10ms -------- 
 	
    
  if(proc_100ms++ < 9) return;
  proc_100ms = 0 ;
	//----proc 100ms --------    
  if(sledSW) {
      gpio_put(LED_PIN, 1);
      sledSW = 0;
  }else{
      sledSW = 1;
      gpio_put(LED_PIN, 0);
  }
  
  
  if(proc_1s++ < 9) return;
  proc_1s = 0;
//----proc 1000ms --------  
  gSysTimer++;
  DEC(gDbgFuseCnt);
	DEC(gflcdsleep_n);
	//watch-dog 
  if(gSysTimer % 2)
			gpio_put(HW_WATCHDOG, ON);
	else 
			gpio_put(HW_WATCHDOG, OFF);	

  if(tic_60s++ < 59) return;
	tic_60s = 0;
  //----proc 60s --------  
 

	
  if(tic_60m++ < 59) return;
  tic_60m = 0;
  //----proc 1t -------- 


	
  
}


void showHL(void)	{
			static uc08 opr_show;
			static int tic_1000ms =  0;
			static signed int year = 0 , day = 0, TT =0 , mimu =0 , sec = 0 , temp;
			int timelevel = 0 ;
			static int gkey_old = 0;
	
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
							TT =	temp / 3600; 
			default:
							temp = gSysTimer % 3600;
							mimu =	temp / 60;
							sec = 	temp % 60;
			break;
			}
		 
		
			switch(dbgLevel){
					case 5:
						// Send out a character without any conversions
						uart_putc_raw(UART_ID_0, '0');
						// Send out a character but do CR/LF conversions
						uart_putc(UART_ID_1, '1');
						// Send out a string, with CR/LF conversions
						printf("Hello, world!\n");
						//uart_tx_program_init(pio, sm, offset, PIN_TX, SERIAL_BAUD);
						
						break;
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
							sprintf(txdatadbg,"\r\n[%02d:%03d:%02d:%02d:%02d]",year,day,TT,mimu,sec);
							if(gkey != NO_KEY){
								my_puts_string(ToDbg);
								sprintf(txdatadbg,"KEYON:%X",gkey);
								gkey = NO_KEY;
							}
							my_puts_string(ToDbg);
					case 0:
					break;	
					default:
							DEC(dbgLevel);
							//sprintf(txdataIot,"[%02d:%03d:%02d:%02d:%02d]\r\n",year,day,TT,mimu,sec);
							//my_puts_string(ToIot);
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
uc08 passThroughFlag = 0;
char gLoraTossFlag = 0;

void rs_rece_uart1_inv(void)
  {
    char data , dtBuf  ;
    static char predata ;
    static uc08 index_r=0;
    char cmdbuf[RX_BUFFER_SIZE1+5] = {0} ;
	static unsigned char  rp_cmd_sub_sqc1;
	static int receive_timeout1;
    static char toss_dateInFlag;
		int devNum = 0;
		char * buf_addr;
		static ui16 divNum ;
	
    switch(rp_cmd_sqc1)
    {
    case 0:
      rp_cmd_len1 = 0;
      rp_cmd_idx1 = 0;
      rp_cmd_sub_sqc1 = 0;
      rp_cmd_sqc1++;
	  	receive_timeout1 = gSysCnt;
	  	toss_dateInFlag = 0 ;
			divNum = 0 ;
      break;
    case 1:
       if(rx_wr_index1 != rx_rd_index1){
       	 gDbgFuseCnt = 5;	
         data = getchar1_h ();

				 if(passThroughFlag){
				 	 uart_putc(UART_ID_0, data);
					 printf("%c",data);
					 break;
				 	}
				 if(( rp_cmd_len1 == 0 ) && (data == '$')){
					toss_dateInFlag = 1; 
				 }
				 if(toss_dateInFlag)
			   	 	gNewCharInFlag = 0;
				 else gNewCharInFlag =1;	
			 	
			   receive_timeout1 = gSysCnt;
			 
	         switch(data)
	         {
	         case 0x0a:  //CR
	            if(predata == 0x0d) rp_cmd_sqc1++;
							
	           //auto_read_cnt = 7;
	         case '$':
			 	 
			 default:  
	           if(rp_cmd_len1 > (RX_BUFFER_SIZE1-2)) rp_cmd_len1 = (RX_BUFFER_SIZE1-2);
			   rp_cmd_buf1[rp_cmd_len1++] = data;
	           rp_cmd_buf1[rp_cmd_len1] = 0;
			   predata = data;
	          break;
	         }
       }
	     if((gSysCnt - receive_timeout1) > 250){
				 if(rp_cmd_len1 > 0) rp_cmd_sqc1++;
				 else rp_cmd_sqc1 = 0; 
			 }
       break;
     case 2:
        // flagUart3ReactionPasingComp = wiz_pasing_data(wiz_cmd_buf);
        if(gLoraTossFlag){ rp_cmd_sqc1++ ; break;}
		     if(toss_dateInFlag == 1){
		       toss_dateInFlag = 0;
			     devNum = atoi(&rp_cmd_buf1[1]);
			      if(devNum == devInfo.devNum_485comm){
		          strncpy(cmdbuf,&rp_cmd_buf1[4],rp_cmd_len1-6);
							printf("%s",cmdbuf);
				      strcpy(txdataIot,cmdbuf);
				      my_puts_string(ToIot);
					 }
	 			}
         if( dbgLevel >= 0  ){
			   sprintf(txdatadbg ,"\r\n<0:%s",rp_cmd_buf1);
			   memset(rp_cmd_buf1,0,sizeof(rp_cmd_buf1));
			   my_puts_string (ToDbg);
         }
           //my_Nput_string (DBG_PORT, wiz_cmd_buf, wiz_cmd_len );
           //sbi (flagSendData , DBG_PORT);
        
       rp_cmd_sub_sqc1 = 0;
       rp_cmd_sqc1 = 0;
       break;
     case 3:    //  lora q_buf
		 		 buf_addr = &rp_cmd_buf1[divNum];
				 sprintf(txdataIot,"AT=U");
		     if((rp_cmd_len1 - divNum) > 90){
					 strncat(txdataIot,buf_addr,90);
					 rp_cmd_sqc1++;
				 }else{
				 	strncat(txdataIot,buf_addr,(rp_cmd_len1-divNum));
					rp_cmd_sqc1= 5;
				 }
				 cbi(nml35State,12);
				 strcat(txdataIot,"\r");
				 my_puts_string(ToIot);
				 receive_timeout1 = gSysCnt ;
 //      if(swUsart4dbgshow & bv(USARTDBGSWHOW_IN0))
 //      {
 //        sprintf(cmdbuf,"0<"); 
 //        strncpy(cmdbuf+2,wiz_cmd_buf,wiz_cmd_len);
 //        my_Nput_string (DBG_PORT, cmdbuf, wiz_cmd_len + 2 );
 //      }
 //      if(cmdPasingFromW107() == CMD_CONT ) wiz_cmd_sqc = 1;
 //      else wiz_cmd_sqc = 0; 
       break;
     case 4:
		 	 if((gSysCnt - receive_timeout1) < 800) break;
			 //if(!isb(nml35State, 12)) break;
			 divNum += 90;
		   rp_cmd_sqc1 = 3;
		 	 break;
     default:
       memset(rp_cmd_buf1,0,sizeof(rp_cmd_buf1));
       rp_cmd_sqc1 = 0;
       break;
    }
  }






char rp_cmd_buf0[RX_BUFFER_SIZE0] = {0};
char pk_buf[PK_BUFFER_SIZE] = {0};

void rs_rece_uart0_iot(void)
     {
       char data , dtBuf  ;
       static ui16 subCmdStatPosition= 0;
       static char olddata;
       static int receive_timeout;
       unsigned char  rp_cmd_sub_sqc0;
	   static unsigned int sCntuCnt = 0;
	   
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
		 sCntuCnt = 0;
         break;
       case 1:
           if(rx_wr_index0 != rx_rd_index0) {
               gDbgFuseCnt = 5; 
               data = getchar0_h ();
               receive_timeout = gSysCnt;
			   if(sCntuCnt == 0){
			   	  sCntuCnt = 200;
				  sprintf(cmdbuf,"<1:");
			      my_nputs_string (ToDbg, cmdbuf, 3 );
			   	}
			   
               switch(data)
               {
               case ' ':  //CR                //--  check < 
                  // if(olddata == '>') gImd_reaction = 1;
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
//		     sendReactionTriger = 1;
	   
         //Cmd_judge (rp_cmd_buf0);
         
         rp_cmd_sub_sqc0 = 0;
         rp_cmd_sqc0 = 0;
         break;
       case 3:
       default:
         rp_cmd_sqc0 = 0;
         break;
       }
     }

	 
	 void rs_rece_uart0_lora(void)
		  {
		  int tmp_i;
			char data , dtBuf  ;
			static ui16 subCmdStatPosition= 0;
			static char olddata , olddata2;
			static int receive_timeout;
			unsigned char  rp_cmd_sub_sqc0;
			static unsigned int sCntuCnt = 0;
			static ui16 pkStartFlag = 0;
			
			char cmdbuf[RX_BUFFER_SIZE0+5] = {0} ;
	 
			static unsigned int  rp_cmd_len0;
			static unsigned char rp_cmd_sqc0;
			static unsigned int  rp_cmd_idx0;

			static unsigned int  pk_cmd_len0 = 0;
			static unsigned int  pk_cmd_idx0 = 0 ;
			
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
				if(rx_wr_index0 != rx_rd_index0) {
					gDbgFuseCnt = 5; 
					data = getchar0_h ();
					receive_timeout = gSysCnt;
					if(sCntuCnt == 0){
					   sCntuCnt = 200;
					   
					 }
					
					switch(data)
					{
					case 0x0d:
					case 0x0a:
						 //if(olddata == 0x0d) rp_cmd_sqc0++;
						    rp_cmd_sqc0++;
					default:
			  //		if(dbgLevel > 0)
			  //		  putchar1 (data);
					  if(rp_cmd_len0 >= (RX_BUFFER_SIZE0 - 2)) rp_cmd_len0 = (RX_BUFFER_SIZE0 - 2);
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
	 // 		  memcpy(txdataInv,cmdbuf,rp_cmd_len0);
	 // 		  sendReactionTriger = 1;
	      if(dbgLevel > 1)
	      {
	      	if(rp_cmd_len0 > 2) printf("<1:");
				  memcpy(cmdbuf,rp_cmd_buf0,rp_cmd_len0);
				  my_nputs_string (ToDbg, cmdbuf, rp_cmd_len0 );
				}
				

				if( Cmd_judge_lora (rp_cmd_buf0)) rp_cmd_sqc0++;
				else rp_cmd_sqc0 = 0; 
			  //rp_cmd_sub_sqc0 = 0;
			  break;
			case 3:
				if(rx_wr_index_pk != rx_rd_index_pk){
	        gDbgFuseCnt = 3;
					data = getchar1_pk();
					switch(data)
					{
						case 'E':
							 if(olddata2 == 'S') pkStartFlag = 1;
						default:
					//		if(dbgLevel > 0)
					//			putchar1 (data);
							if(pk_cmd_len0 >= (PK_BUFFER_SIZE - 2)) pk_cmd_len0 = (PK_BUFFER_SIZE - 2);
							pk_buf[pk_cmd_len0++] = data;
							pk_buf[pk_cmd_len0] = 0;
							olddata2 = data;
					 break;
					}
				}else{ 
			    rp_cmd_sqc0 = 0;
					if(pk_cmd_len0 < 8) break;
					if(pk_buf[0] != 'S') break;
					if(pk_buf[1] != 'E') break;
					memcpy(cmdbuf,&pk_buf[2], 3);
					//if((atoi(cmdbuf) + 5 ) > pk_cmd_len0) break;
					rp_cmd_sqc0 = 4;
				}
				break;
      case 4:
//				parsing_pk_cmd();
				if(dbgLevel > 1)
	      {
	      	printf("<pkcmd:");
				  memcpy(cmdbuf,pk_buf,pk_cmd_len0);
				  my_nputs_string (ToDbg, cmdbuf, pk_cmd_len0 );
				}
				if(1){   // pk check 
				  sprintf(txdataInv,"%s",pk_buf);
					sendReactionTriger = 1;
				}
				pk_cmd_len0 = 0;
				pkStartFlag = 0;
				rp_cmd_sqc0 = 0;
				break;
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
					 
						   Cmd_judge_usb(rp_cmd_buf0);
							 
							 rp_cmd_sub_sqc0 = 0;
							 rp_cmd_sqc0 = 0;
							 break;
						 case 3:
						 default:
							 rp_cmd_sqc0 = 0;
							 break;
						 }
					 }

 
 



