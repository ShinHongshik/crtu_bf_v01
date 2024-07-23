


#include "hs_global.h"
#include "eep_at24c128.h"


typedef union {
	unsigned long int dl;
	unsigned int  di[2];
	unsigned char dc[4];
}uni2;


extern uEE uEepv ;

uint8_t addr_24c_high = 0xD0;



void i2c_write_byte(uint8_t val) {
//#ifdef i2c_default
    i2c_write_blocking(DOT_DEFAULT_I2C, addr_24c_high, &val, 1, false);
//#endif
}

void i2c_read_byte(uint8_t val) {
   i2c_read_blocking(DOT_DEFAULT_I2C,  addr_24c_high, &val, 1, false) ;
}


void i2c_ini_dot(void){
	i2c_init(DOT_DEFAULT_I2C, 100 * 1000);
	gpio_set_function(DOT_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
	gpio_set_function(DOT_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
	gpio_pull_up(DOT_DEFAULT_I2C_SDA_PIN);
	gpio_pull_up(DOT_DEFAULT_I2C_SCL_PIN);

	
	// Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
}




int at24_write_byte (ui16 addr ,uc08 val){
	ui16 temp;
	uc08 arr[3] = {0};

	temp = addr; 
	arr[0] = (uc08)(temp >> 8);
	arr[1] = (uc08)(temp & 0xFF);
	arr[2] = val;
	// i2c start
	
	return i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, arr, 3, false) ;
	// write addr0
	// write addr1 
	// write val 
	
}

int at24_read_byte (ui16 addr ,char *  dest){
	int val_i;
	uc08 arr[3] = {0};
	ui16 temp;
	
	temp = addr; 
	arr[0] = (uc08)(temp >> 8);
	arr[1] = (uc08)(temp & 0xFF);
	// arr[2] = val;
	// i2c start
	
	i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, arr, 2, true) ;

	val_i  = i2c_read_blocking(DOT_DEFAULT_I2C,  addr_24c_high, dest, 1, false) ;
	// write addr0
	// write addr1 
	// write val 
	return val_i ;
}

int at24_write_word (ui16 addr ,ui16 val){
	ui16 temp;
	uc08 arr[5] = {0};
	uni2 tmp_u ;

	temp = addr;
	arr[0] = (uc08)(temp >> 8);
	arr[1] = (uc08)(temp & 0xFF);

	temp = val;
	arr[2] = (uc08)(temp >> 8);
	arr[3] = (uc08)(temp & 0xFF);
	
	// i2c start
	
	temp = i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, arr, 4, false) ;
	//i2c_write_blocking(i2c_default,  addr_24c_high, &arr[1], 1, true) ;
	// write addr0
	// write addr1 
	//printf("%s",arr);
	// write val 
	return temp;
}



int at24_read_word (ui16 addr ,ui16 * dest){
	ui16 temp;
	uc08 arr[5] = {0};
	ui16 val;
	
	temp = addr;
	arr[0] = (uc08)(temp >> 8);
	arr[1] = (uc08)(temp & 0xFF);

	// i2c start
	
	i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, &arr[0], 2, true) ;

	temp = i2c_read_blocking(DOT_DEFAULT_I2C,  addr_24c_high, &arr[2], 2, false) ;

	val = arr[2];
	val <<= 8;
	val += arr[3];
	
	*dest = val ; 
	// write addr0
	// write addr1 
	// write val 
	return temp;
}

ui16 eep_addr(ui16 * addr){
	ui16 * start  = &(uEepv.addi[0]) ;
	ui16 m_add;
	m_add = (ui16)( addr - start );
	return m_add;
}

int save_eep (ui16 * oaddr){
	ui16 m_add ;
	int err_code;
	m_add = eep_addr(oaddr);
	err_code = at24_write_word( m_add, *oaddr);
	return err_code;
}

int load_eep (ui16 * oaddr){
	ui16 addr;
	int val ; 

	addr = eep_addr(oaddr);
	val =  at24_read_word(addr, oaddr);
	return val; 
}


int save_eep_page (void){
	ui16 temp;
	uc08 data[2048] = {0};
	uni2 tmp_u ;
	int i  = 0 , err_code;


	uEepv.su.eePortNumber =   ee.PortNumber;
	uEepv.su.eeSendDelay = ee.SendDelay;
	uEepv.su.eeInverterCount = ee.InverterCount;	
	uEepv.su.eeTcpPort = ee.TcpPort;
	uEepv.su.eeSendTimer = ee.SendTimer;
	uEepv.su.eeIpAddress[0] = ee.IpAddress[0];
	uEepv.su.eeIpAddress[1] = ee.IpAddress[1];
	uEepv.su.eeIpAddress[2] = ee.IpAddress[2];
	uEepv.su.eeIpAddress[3] = ee.IpAddress[3];
	uEepv.su.eeModelInverter  = ee.ModelInverter;
	uEepv.su.EEP_MODE_232  = ee.P_MODE_232;
	uEepv.su.EEP_BPS_485  = ee.P_BPS_485;
	uEepv.su.eeDevNum_485comm = (ui16)devInfo.devNum_485comm ;

	data[0] = 0;
	data[1] = 0;

	
	// i2c start
	while (1)
		{
		data[i+2] = uEepv.addb[i];
		i++;
		if(i > 20)break;
		}
	//temp = i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, arr, 4, false) ;
	//i2c_write_blocking(i2c_default,  addr_24c_high, &arr[1], 1, true) ;
	// write addr0
	// write addr1 
	//printf("%s",arr);
	// write val 
	//i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, &data[0], 2, true) ;
	
	err_code = i2c_write_blocking(DOT_DEFAULT_I2C, addr_24c_high, data , 64, false);
//	printf("%d,[%x],%d,[%x]\r\n",m_add,err_code,uEepv.addi[numberOfsaveVal],uEepv.addi[numberOfsaveVal]);
	return err_code;
}

int load_eep_page (void){
	ui16 temp;
	uc08 data[2048] = {0};
	uni2 tmp_u ;
	int i  = 0 , err_code;

	data[0] = 0;
	data[1] = 0;

	
	// i2c start

	//temp = i2c_write_blocking(DOT_DEFAULT_I2C,  addr_24c_high, arr, 4, false) ;
	//i2c_write_blocking(i2c_default,  addr_24c_high, &arr[1], 1, true) ;
	// write addr0
	// write addr1 
	//printf("%s",arr);
	// write val 
	i2c_write_blocking(DOT_DEFAULT_I2C, addr_24c_high, data , 2, true);
	err_code = i2c_read_blocking(DOT_DEFAULT_I2C, addr_24c_high, &data[2] , 62, false);
//	printf("%d,[%x],%d,[%x]\r\n",m_add,err_code,uEepv.addi[numberOfsaveVal],uEepv.addi[numberOfsaveVal]);
	
	while (1)
		{
		uEepv.addb[i]  = data[i+2] ;
		i++;
		if(i > 20)break;
		}

	ee.PortNumber =    uEepv.su.eePortNumber ;	 
	ee.SendDelay =	  uEepv.su.eeSendDelay ; 
	ee.InverterCount =	  (char) uEepv.su.eeInverterCount ;    
	ee.TcpPort =   uEepv.su.eeTcpPort		; 
	ee.SendTimer =	 uEepv.su.eeSendTimer	; 
	ee.IpAddress[0] =  (char) uEepv.su.eeIpAddress[0] ; 
	ee.IpAddress[1] =	(char)uEepv.su.eeIpAddress[1] ; 
	ee.IpAddress[2] =	(char)uEepv.su.eeIpAddress[2] ; 
	ee.IpAddress[3] =	(char)uEepv.su.eeIpAddress[3] ; 
	ee.ModelInverter =	 (uc08)uEepv.su.eeModelInverter ; 
	ee.P_MODE_232 = (char) uEepv.su.EEP_MODE_232	; 
	ee.P_BPS_485 =	 (char)uEepv.su.EEP_BPS_485 	; 
  devInfo.devNum_485comm = (int)uEepv.su.eeDevNum_485comm;
	return err_code;
}


// I2C address
static const uint8_t ADXL343_ADDR = 0x53;

// Registers
static const uint8_t REG_DEVID = 0x00;
static const uint8_t REG_POWER_CTL = 0x2D;
static const uint8_t REG_DATAX0 = 0x32;

// Other constants
static const uint8_t DEVID = 0xE5;
static const float SENSITIVITY_2G = 1.0 / 256;  // (g/LSB)
static const float EARTH_GRAVITY = 9.80665;     // Earth's gravity in [m/s^2]

/*******************************************************************************
 * Function Declarations

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
 */ //Function Definitions

// Write 1 byte to the specified register
int reg_write(  i2c_inst_t *i2c, 
                const uint addr, 
                const uint8_t reg, 
                uint8_t *buf,
                const uint8_t nbytes) {

    int num_bytes_read = 0;
    //uint8_t msg[nbytes +  1];
	uint8_t *msg = malloc(nbytes +  1);

    // Check to make sure caller is sending 1 or more bytes
    if (nbytes < 1) {
        return 0;
    }

    // Append register address to front of data packet
    msg[0] = reg;
    for (int i = 1; i < (nbytes + 1); i++  ) {
        msg[i] = buf[i - 1];
    }

    // Write data to register(s) over I2C
    i2c_write_blocking(i2c, addr, msg, (nbytes +  1), false);
	//i2c_write_blocking_until(i2c, addr, msg, (nbytes +  1), true , 100 * 1000);

    return num_bytes_read;
}

// Read byte(s) from specified register. If nbytes > 1, read from consecutive
// registers.
int reg_read(  i2c_inst_t *i2c,
                const uint addr,
                const uint8_t reg,
                uint8_t *buf,
                const uint8_t nbytes) {

    int num_bytes_read = 0;

    // Check to make sure caller is asking for 1 or more bytes
    if (nbytes < 1) {
        return 0;
    }

    // Read data from register(s) over I2C
    i2c_write_blocking(i2c, addr, &reg, 1, true);
    num_bytes_read = i2c_read_blocking(i2c, addr, buf, nbytes, false);

    return num_bytes_read;
}

/*******************************************************************************
 * Main
 */


