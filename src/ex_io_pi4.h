#ifndef _EX_IO_PI4IOE5V_
#define _EX_IO_PI4IOE5V_


#ifndef DOT_EXIO_I2C
#define DOT_EXIO_I2C i2c0
#endif

#ifndef DOT_EXIO_I2C_SDA_PIN
#define DOT_EXIO_I2C_SDA_PIN   8
#endif

#ifndef DOT_EXIO_I2C_SCL_PIN
#define DOT_EXIO_I2C_SCL_PIN   9
#endif

// By default these LCD display drivers are on bus address 0x27
// By default these LCD display drivers are on bus address 0x27

enum EXIOR{
	 INPUT_PORT0
	 ,INPUT_PORT1
	 ,OUTPUT_PORT0
	 ,OUTPUT_PORT1
	 ,POL_INV_PORT0
	 ,POL_INV_PORT1
	 ,CONFIG_PORT0
	 ,CONFIG_PORT1
	 ,OUTPUT_DRV_STR_REG00 = 0X40  // 64
	 ,OUTPUT_DRV_STR_REG01
	 ,OUTPUT_DRV_STR_REG10
	 ,OUTPUT_DRV_STR_REG11
	 ,INPUT_LATCH_REG0
	 ,INPUT_LATCH_REG1
	 ,PULL_UPDOWN_EN_REG0
	 ,PULL_UPDOWN_EN_REG1
	 ,PULL_UPDOWN_SEL_REG0
	 ,PULL_UPDOWN_SEL_REG1
	 ,INTR_MASK_REG0
	 ,INTR_MASK_REG1
	 ,INTR_STATUS_REG0
	 ,INTR_STATUS_REG1
	 ,OUTPUT_PORT_CONFIG_REG
	 
};

#define PI4IOE5V_ADDR  (0x21)
//-------------------------------------
extern uc08 sw_exio_p0_out; 
extern uc08 sw_exio_p1_in;
//-------------------------------------
void exio_ini_dot(void);

extern void drv_exio_pi4(void);
int PI4_write_byte (uint8_t reg_addr ,uc08 val);

int PI4_read_byte (uint8_t reg_addr ,char *  dest);


#endif 
