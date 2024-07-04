#ifndef _HS_AT24C128_
#define _HS_AT24C128_




#ifndef DOT_DEFAULT_I2C
#define DOT_DEFAULT_I2C i2c0
#endif

#ifndef DOT_DEFAULT_I2C_SDA_PIN
#define DOT_DEFAULT_I2C_SDA_PIN   8 
#endif

#ifndef DOT_DEFAULT_I2C_SCL_PIN
#define DOT_DEFAULT_I2C_SCL_PIN   9
#endif

// By default these LCD display drivers are on bus address 0x27
// By default these LCD display drivers are on bus address 0x27

#define AT24C_128_ADDR  (0xD0)

extern void i2c_write_byte(uint8_t val); 

extern void i2c_read_byte(uint8_t val); 

extern int save_eep (ui16 * oaddr);
extern int load_eep(ui16 * oaddr);
extern ui16 eep_addr(ui16 * addr);
 
extern int at24_write_byte (ui16 addr ,uc08 val);
extern int at24_write_word(ui16 addr ,ui16 val);
extern int at24_read_byte (ui16 addr ,char *  dest);
extern int at24_read_word (ui16 addr ,ui16 * dest);
int save_eep_page (void);
int load_eep_page (void);


extern see ee;

#endif
