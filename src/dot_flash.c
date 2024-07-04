
#include "dot_flash.h"
#include "hardware/flash.h"

#define FLASH_SECTOR_MAX            1


typedef struct
{
  uint32_t addr;
  uint32_t length;
} flash_tbl_t;

static flash_tbl_t flash_tbl[FLASH_SECTOR_MAX] =
    {
        {XIP_BASE + 0x20000,  PICO_FLASH_SIZE_BYTES - 128*1024},
    };
		
static bool flashInSector(uint16_t sector_num, uint32_t addr, uint32_t length);


void h_Flash_cmd(void)
{
  bool ret = false;
  char num = 0;	
  
	
  	 uint8_t txbuf[6] = {0};
	 uint8_t rxbuf[6] = {0};
	 uint8_t id_tbl[3];
  
//	 __disable_irq();
	 txbuf[0] = 0x90;
	 flash_get_unique_id(6);
	 for (int i = 0; i < 3; i++)
	 {
	   id_tbl[i] = rxbuf[i + 1 + 2];
	 }
//	 __enable_irq();
  
	 for (int i=0; i<3; i++)
	 {
	   printf("DevID[%d] 0x%X\n", i, id_tbl[i]);
	 }
  
	 for (int i=0; i<FLASH_SECTOR_MAX; i++)
	 {
	   printf("0x%X : %dKB\n", flash_tbl[i].addr, flash_tbl[i].length/1024);
	 }

    printf("flash info\n");
    printf("flash read  addr length\n");
    printf("flash erase addr length\n");
    printf("flash write addr data\n");
}


