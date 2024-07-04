
#ifndef _HS_GLOBAL_
#define _HS_GLOBAL_


#include "pico/stdlib.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hs_type.h"
//---------------------------


#include "hardware/uart.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "string.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "hardware/watchdog.h"
#include "hardware/flash.h"
#include "tusb_config.h"
#include "cdc_device.h"


//-------def-----------------
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t


#define USE_DEV_LIB 1


///--------------------------
#define ALARM_NUM 0
#define ALARM_IRQ TIMER_IRQ_0

///----------uart----------------
#define UART_ID_0 uart0
#define BAUD_RATE_0 115200

#define UART_TX_PIN_0 0
#define UART_RX_PIN_0 1

#define DATA_BITS_0 8
#define STOP_BITS_0 1
#define PARITY_0    UART_PARITY_NONE


#define TX0_OPTION_SEL 7
#define UART_485_ENABLE 6


#define UART_ID_1 uart1
#define BAUD_RATE_1 115200

#define UART_TX_PIN_1 4
#define UART_RX_PIN_1 5

#define DATA_BITS_1 8
#define STOP_BITS_1 1
#define PARITY_1    UART_PARITY_NONE

#define DOT_LCD_SPI_ID spi1

///----------------------------------
// --- I2C ---
//#define I2C_PORT i2c1
#define I2C_SDA1 2
#define I2C_SCL1 3
#define I2C_SDA0 8
#define I2C_SCL0 9


enum {ToIot,ToINV,ToDbg,W107_PORT};
enum {SK_IOT,KT_M2M};
enum {IOT_MODEM,LORA_MODULE};
//--------------------------------------------


// --- spi ---
#ifndef DOT_DEFAULT_SPI
#define DOT_DEFAULT_SPI spi1
#endif
#ifndef DOT_DEFAULT_SPI_RX_PIN
#define DOT_DEFAULT_SPI_RX_PIN 12
#endif
#ifndef DOT_DEFAULT_SPI_SCK_PIN
#define DOT_DEFAULT_SPI_SCK_PIN 10
#endif
#ifndef DOT_DEFAULT_SPI_TX_PIN
#define DOT_DEFAULT_SPI_TX_PIN 11
#endif
#ifndef DOT_DEFAULT_SPI_CSN_PIN
#define DOT_DEFAULT_SPI_CSN_PIN 13
#endif 
#ifndef DOT_DEFAULT_DEV_SEL_PIN
#define DOT_DEFAULT_DEV_SEL_PIN 22
#endif 





enum{SELDEV_SDCARD,SELDEV_LCD};
static inline void cs_select(uint cs_pin) {
    asm volatile("nop \n nop \n nop"); // FIXME
    gpio_put(cs_pin, 0);
    asm volatile("nop \n nop \n nop"); // FIXME
}

static inline void cs_deselect(uint cs_pin) {
    asm volatile("nop \n nop \n nop"); // FIXME
    gpio_put(cs_pin, 1);
    asm volatile("nop \n nop \n nop"); // FIXME
}

static inline void dev_select_cs1(uint cs_pin) {
	if(cs_pin == SELDEV_SDCARD){
		gpio_put(DOT_DEFAULT_DEV_SEL_PIN, 0);
	}else if(cs_pin == SELDEV_LCD){
		gpio_put(DOT_DEFAULT_DEV_SEL_PIN, 1);	
	}
}

//---------g val --------------------
typedef struct	{
	unsigned int stDummy;
	unsigned int PortNumber;
	unsigned int TcpPort;
	unsigned int SendDelay;
	unsigned int SendTimer;
	unsigned char InverterCount;	
	char IpAddress[4];
	char ModelInverter;
	char P_MODE_232;
	char P_BPS_485;
}see; 

typedef struct	{
	si16 aeePortNumber; 
	si16 aeetcpport; 
	si16 aeemode; 
	si16 aeeIpAddress;
}sss;

typedef struct	{
	ui16 eest_dummy ;
	ui16 eePortNumber; 
	ui16 eeTcpPort; 
	ui16 eeSendDelay;
	ui16 eeSendTimer;
	ui16 eeInverterCount;  
	ui16 eeIpAddress[4];
	ui16 eeModelInverter;
	ui16 EEP_MODE_232;
	ui16 EEP_BPS_485;
	ui16 eemode;
	ui16 dummy_endof_eepval;
}ssu;


typedef struct {
     unsigned int inverter_temp[4];
     unsigned int inverter_status[4];
     
     unsigned int solar_cell_voltage;
     unsigned int solar_cell_current;    
     
     unsigned int inv_u_voltage;
     unsigned int inv_v_voltage;
     unsigned int inv_w_voltage;
     unsigned int inv_u_current;
     unsigned int inv_v_current;
     unsigned int inv_w_current;
     unsigned int inv_frequency;
     
     unsigned int power_solar;
     unsigned long int power_inv_total;
     unsigned int power_inv_now;
 //    unsigned int power_inv_max;
     unsigned long int power_inv_day_total;   
     unsigned int power_inv_pf;
     
 }sInv_val;

 //sInv_val inverter[21];



typedef union {
	uc08 addb[2048];
	ui16 addi[1024];
	ssu su;
}uEE;

typedef union {
	long int dl;
	int  di[2];
	char dc[4];
}sni;

 
typedef union {
	unsigned long int dl;
	unsigned int  di[2];
	unsigned char dc[4];
}uni;


//--------------------------------------
#include "eep_at24c128.h"
#include "ex_io_pi4.h"


extern void i2c_ini_dot(void);

int reg_write(i2c_inst_t *i2c, 
                const uint addr, 
                const uint8_t reg, 
                uint8_t *buf,
                const uint8_t nbytes);

int reg_read(   i2c_inst_t *i2c,
                const uint addr,
                const uint8_t reg,
                uint8_t *buf,
                const uint8_t nbytes);

//---------------------------------------

void my_puts_string(char port );
void my_nputs_string (char port,char * cmdbuf, int length );
uc08 Cmd_judge(char * dest);
void drv_sendTcpControlM2M(void);
 void drv_sendTcpControlLTE(void);
void drv_temp_check(void);

//---------------------------------------------------
void rs_rece_uart0_iot(void);
void rs_rece_uart1_inv(void);
void rs_rece_usb_0(void);	

void spi_ini_dot(void);

void uart_ini_rx_int(void);
void proc_1ms_tic(void);
void tx_onoff485(char onoff);
void tx_op_selector(char onoff);

void opr_send485tx(void);
void on_uart_rx_1();
void on_uart_rx_0();
void on_stdio_usb_rx();

void showHL(void);

char getchar1_h(void);

static void alarm_irq(void);
static void alarm_in_us(uint32_t delay_us);

extern float read_onboard_temperature(const char unit);
extern void drv_eep_at24c128(void);
extern void OLED_1in5_rgb_Init(void);
extern void drv_lcd_1in5_oled(void);
extern int OLED_1in5_rgb_test(void);


//-----------------------------------------------------------------------
extern int gSysCnt;
extern char gValIniFalg;

#endif



