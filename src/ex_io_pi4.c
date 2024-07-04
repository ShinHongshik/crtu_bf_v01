
#include "hs_global.h"

uint8_t addr_pi4_i2c = PI4IOE5V_ADDR;

/*
void i2c_write_byte(uint8_t val) {
//#ifdef i2c_default
    i2c_write_blocking(DOT_DEFAULT_I2C, addr_24c_high, &val, 1, false);
//#endif
}

void i2c_read_byte(uint8_t val) {
   i2c_read_blocking(DOT_DEFAULT_I2C,  addr_24c_high, &val, 1, false) ;
}
*/

void exio_ini_dot(void){
	i2c_init(DOT_EXIO_I2C, 50 * 1000);
	gpio_set_function(DOT_EXIO_I2C_SDA_PIN, GPIO_FUNC_I2C);
	gpio_set_function(DOT_EXIO_I2C_SCL_PIN, GPIO_FUNC_I2C);
	gpio_pull_up(DOT_EXIO_I2C_SDA_PIN);
	gpio_pull_up(DOT_EXIO_I2C_SCL_PIN);

}


int PI4_write_byte (uint8_t reg_addr ,uc08 val){
	uint8_t arr[3] = {0};
	
	arr[0] = reg_addr;
	arr[1] = (uint8_t)val;
	arr[2] = 0;
	// i2c start

	return i2c_write_blocking(DOT_EXIO_I2C, PI4IOE5V_ADDR , arr, 3, false) ;
	
}

int PI4_read_byte (uint8_t reg_addr ,char *  dest){
	int val_i;
	uc08 arr[3] = {0};
	
	arr[0] = (uc08)reg_addr;
	arr[1] = 0;
	// arr[2] = val;
	// i2c start
	
	i2c_write_blocking(DOT_EXIO_I2C,  PI4IOE5V_ADDR, arr, 1, true) ;

	val_i  = i2c_read_blocking(DOT_EXIO_I2C,  PI4IOE5V_ADDR, dest, 1, false) ;
	// write addr0
	// write addr1 
	// write val 
	return val_i ;
}


uc08 sw_exio_p0_out = 0;
uc08 sw_exio_p1_in = 0;

void drv_exio_pi4(void){
	static uc08 p0_in,p0_out = 0,p0_inout = 0x00;
	static uc08 p1_in,p1_out,p1_inout = 0xff;
	static uc08 opr_de = 99;
	static int de_cnt;

	switch(opr_de){
		case 99:
			exio_ini_dot();
			opr_de = 98;
			de_cnt = gSysCnt;
			break;
		case 98:
			if((gSysCnt - de_cnt ) < 1000) break;
			opr_de = 0;
			break;
		case 0:
			PI4_write_byte(CONFIG_PORT0, 0x0);
			//PI4_write_byte(PULL_UPDOWN_EN_REG0, 0xff);
		  //PI4_write_byte(PULL_UPDOWN_EN_REG0, 0xff);
			//PI4_write_byte(PULL_UPDOWN_SEL_REG0, 0xFF);
			de_cnt = gSysCnt;
			//PI4_read_byte(INPUT_PORT1, &p1_in);
			opr_de++ ;
			break;
		case 1:
			if((gSysCnt - de_cnt ) < 100) break;
			de_cnt = gSysCnt;
			if(sw_exio_p0_out != p0_out){ 
			  p0_out = sw_exio_p0_out;
			  opr_de = 2 ;
			  }
			break;
		case 2:
			PI4_write_byte(OUTPUT_PORT0, p0_out);
			PI4_write_byte(CONFIG_PORT0, 0x0);
			opr_de = 1;
			break;
		case 3:
			// key_check 
			PI4_read_byte(INPUT_PORT1, &p1_in);	 
			sw_exio_p1_in  = p1_in;
			opr_de  = 1;
			break;
		default:
			opr_de = 99;
			break;
		
	}
	
}
