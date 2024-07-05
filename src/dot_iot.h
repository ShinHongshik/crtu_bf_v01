
#ifndef _DOTCORE_IOT_
#define _DOTCORE_IOT_

#include "hs_global.h"


enum IOT_CHECK_FLAG{
       CLOCK_ICF
      ,RECEIVEM_MSG_ICF
      ,SEND_MSGIN_ICF
      ,QUERY_CHECK_ICF
      ,TCPSENDDATA_ICF
      ,NEWMSGCHECK_ICF
      ,READMSG_ICF
      };


enum STATE_IOT_MODUAL{   
       CSQUERY_STIOT
      ,DEVICE_READY_STIOT  
      ,DNSQUERY_STIOT                                
      ,TIMECHECK_STIOT
      ,WSOCREATE_STIOT
      ,WSOCOPEN_STIOT
      ,APP_READY
      };


//---------------------------------------
//#define CDMA_RELAY_OFF  gpio_put(22, 1)
//#define CDMA_RELAY_ON   gpio_put(22, 0)
extern uc08 dbgLevel;
extern uc08 swUsart4dbgshow;
extern int gSysCnt;
extern char SendTestPkt;
extern uc08 iotSendSw;
extern uc08 iotState;
extern char gMode_232;
extern ui16 gDbgFuseCnt;
extern char gImd_reaction;

extern char	gdataSaveFlag; 
extern char	gdataLoadFlag; 

//----------------------------------
extern char txdataInv[];
extern char txdataIot[];
extern char txdatadbg[];

extern see ee;

extern my_dev devInfo;
extern uc08 passThroughFlag;
extern ui16 nml35State;
extern char gLoraTossFlag;

extern float gNowBattLv; 
extern float gNowtemp;   
extern float gNowBLack_V; 
extern ui16 gflcdsleep_n;

//----------------------------
extern int eeSave_eepValue_all(ui16 i);

extern int eeLoad_eepValue_all(ui16 i);
extern void eeSave_eeVal_once(void);
extern void drv_eep_at24c128(void);
extern void drv_key_check(void);


extern void get_time(char* str_clk);
extern void sendWSOWR_T(char inv_number);
extern int save_eep (ui16 * oaddr);
extern int load_eep(ui16 * oaddr);
extern int  at24_write_word (ui16 addr ,ui16 val);
extern int  at24_read_word (ui16 addr ,ui16 * dest);
extern void i2c_write_byte(uint8_t val); 
extern void i2c_read_byte(uint8_t val); 
extern void h_Flash_cmd(void);
extern void drv_lora_nml35(void);
extern int save_eep_page (void);
extern int load_eep_page (void);
//----------------------------------------------------------------------



#endif


