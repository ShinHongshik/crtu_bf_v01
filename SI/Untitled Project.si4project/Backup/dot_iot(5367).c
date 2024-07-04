
#include "hs_global.h"
#include "dot_iot.h"
#include "hs_type.h"
enum HS_CMD{ 
	NO_CMD = 0
	,DBG_HSCMD = 11
	//-----...
	,OK_HSC = 22
	,SAVE_HSC
	,LOAD_HSC
	,SEV_HSC
	,IVMODE_HSC
	,FI = 29
	,SOFT_RESET
	,SET_COMMMNUM
	,TOSS_232
	,LORA_RST_CMD
	,HELP
	,MAX_NUM_FROMPCCMD
};

char *frompccmd_str_m2m[MAX_NUM_FROMPCCMD]=
{
  //--------------lte--------------
  //--------------m2m--------------
   "no_cmd",              //	0     
	 "\r\n",             //	1     
	 "+QCDS: ",                //	2     
	 "+CSQ: ",           //	3     
	 "$v2t",          //	4     
	 "APP RDY",             //	5     
	 "+SKTOTA: ",           //	6     
	 "+QIOPEN: 0,",         //	7     
	 "set_iot",     //	8     
	 "sendtpk",           //	9     
	 "setmcno:",           //	10    
	 "dbg",                //	11    
	 "+WSOCO:",             //	12    
	 "+WSOCR:",      //	13    
	 "$$STAT:READY",    //	14    
	 "+WDNSQ:0,",        //	15    
	 "*SKT*READMT: ",             //	16    
	 "+CMTI: ",            //	17    
	 "+CMGR: ",             //	18    
	 "*SMSALERT",           //	19    
	 "+QIRD: ",             //	20    
	 "+CCLK: ",              //	21  -- comm 
	 "OK",                   // 22
     "$save",				 // 23
     "$load",				 //  24
     "sev",					 //  25
     "$ivmode", 		     // 26
     "$lcdrst",				// 27
     "reset run_boot ",       // 28
     "$fi",						//29
     "$srst",         //30 
     "$scm",					//31
     "$sto",         //32
     "$lrst",         //33
	 "help"                 //MAX_NUM_FROMPCCMD - 1
};

enum HS_CMD_USB{ 
	 NO_HSC_USB = 0
	,END_CHAR_HSC_USB
	,OK_HSC_USB 
	,DBG_HSC_USB 
	,SAVE_HSC_USB
	,LOAD_HSC_USB
	,SEV_HSC_USB
	,RESET_HSC_USB
	,SET_COMMMNUM_HSC_USB
	,TOSS_232_HSC_USB
	,HELP_HSC_USB
	,MAX_NUM_FROMUSB
};

char *frompccmd_str_usb[MAX_NUM_FROMUSB]={
	"no_cmd", 						 //  0		 
	"\r\n", 						// 1		 
	"OK", 									// 2
	"dbg",								// 3 	 
	"$save",				// 4
	"$load",				//	5
	"$setdn",					//	6
	"$rst",				 //8  
	"$scm", 				 //9
	"$sto", 				//10
	"help"								 //MAX_NUM_FROMPCCMD - 1
};
	





extern sInv_val inverter[21];


int rssiLevel = 0;


ui16 gPortNumber = 0 ;

char ipAddress[30]={0};
char resetSw = 0;
char itoMsgInFlag=0;
char bRxOk=0;
char datetime[30];



uEE uEepv ={0};



//	unsigned int ee.PortNumber = 8906;
//	unsigned int ee.SendDelay;
//	unsigned char ee.InverterCount = 1;	
//	char eeIpAddress[4];
//	unsigned int ee.TcpPort;
//	unsigned int eeSendTimer;
//	unsigned char eeModelInverter=0;
//	char ee.P_MODE_232;
//	char ee.P_BPS_485;

see ee = {0};

void gpio_hs (const uint gpNum, char onoff ){
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

void gp_ini_h(const uint PINNUM ,bool in_out ){
		gpio_init(PINNUM);
		gpio_set_dir(PINNUM, in_out);  
}

void my_putc( uart_inst_t *uart , char val){
		uart_putc(uart, val);
}


uc08 Cmd_judge(char * dest){
	char tcmd_code = 0;
    char tmp_c ;
	char cmd_buf[50] = {0};
  int subCmdValIndex = 0 , tmp_iii;
  ui16 tmp_i ;
  char gsktota ;
  char * addr = dest;
	char * subval_addr = dest;
	char i=0; 
  static char * dbgSendbuf = txdatadbg;
  static char dbgSndPort = ToDbg;
  int i2c_errcode ;
  sni buff = {0} ;
  
	// match 1cmd
    	i  = (MAX_NUM_FROMPCCMD - 1);
			while(i)
			{
        //strcpyf(cmd_buf,frompccmd_str_m2m[i]);
        //subCmdValIndex = strcspn(frompccmd_str_m2m[i],srt_4comp_prompc);
        subCmdValIndex =  strlen(frompccmd_str_m2m[i]);
				addr = dest;
				while(*addr){
				 if(*addr ==	*frompccmd_str_m2m[i]) break;
				 addr++;
				} 
				if(strncmp(addr,frompccmd_str_m2m[i],subCmdValIndex) == 0) break;
        DEC (i);
			}
			subval_addr = addr;
			while(subCmdValIndex--) subval_addr++;
			while(*subval_addr){
				if(*subval_addr != ' ')break;
				subval_addr++;
			} 

      //if((i != 11) && (dbgLevel == 0)) dbgSndPort = 0xff;

      switch(i){
          case 0:
                sprintf(dbgSendbuf,"No_cmd,%d",i);
                my_puts_string (dbgSndPort);
            break;
          case 1:  // 0x0d0x0a -> not action 
            break;
          case 3 :
                strcpy(cmd_buf,subval_addr);
                rssiLevel = atoi(cmd_buf );
                //----------
                sbi (iotState, CSQUERY_STIOT);
                sprintf(dbgSendbuf,"mCSQ->%d",rssiLevel);
                my_puts_string (dbgSndPort);
            break;
          case 4 :
                if(swUsart4dbgshow == 1){
                  swUsart4dbgshow = 0;
                }else{
                  swUsart4dbgshow = 1;  
                  sprintf(txdataInv,"Now invIn->iotOut.. ");
                  //tossflagIot2Pi = 2;
                }
                if(dbgLevel > 0) {
                  my_puts_string (ToIot);
                }
            break;
          case 5:
                sbi (iotState, APP_READY);
            break;
		  		case 6:
                strncpy(cmd_buf,subval_addr,3 );
                if((*subval_addr >= '0') && (*subval_addr < '9')){
                  gsktota = (char)(atoi(subval_addr));
                  if(gsktota > 9) gsktota = 9;
                }
                sprintf(dbgSendbuf,"skota=%d",gsktota);
                my_puts_string (ToIot);			
		  			break;
		  		case 7:
                strncpy(cmd_buf,subval_addr,3 );
                if(*subval_addr == '0') {
					//fSoketOpend = 1;
	                sprintf(dbgSendbuf,"QO=OK");
	                my_puts_string (ToIot);
                }
		  			break;
          case 8:   //  "set_iot",     //	8     
              strncpy(cmd_buf,subval_addr,3 );
              if((*subval_addr >= '0') && (*subval_addr < '9')){
                tmp_c = (char)(atoi(subval_addr));
                if(tmp_c > 5) tmp_c = 5;
                if(tmp_c != gMode_232){
                  //ee.P_MODE_232 = gMode_232;
				  				sprintf ( cmd_buf,  (gMode_232 == KT_M2M)?("KT"):("SK"));
                  sprintf(dbgSendbuf,"iot=%s,sys_reset!",cmd_buf );
                  my_puts_string (dbgSndPort);
                  while(1);
                }
              }
              sprintf(dbgSendbuf,(gMode_232 == KT_M2M)?("KT"):("SK"));
              my_puts_string (dbgSndPort);
            break;
          case 9:
		  	    if(SendTestPkt == 0){
	                SendTestPkt = 1;
	                sbi(iotSendSw ,TCPSENDDATA_ICF );
		  	    	}
            break;
          case 10:
                strcpy(cmd_buf,subval_addr);
                tmp_i = (ui16)atoi(cmd_buf );
                if((tmp_i > 6000) && (tmp_i <10000) ){
                   gPortNumber =   tmp_i ;
                   //ee.PortNumber = gPortNumber;
                }
                sprintf(dbgSendbuf,"Mn=%d",gPortNumber);
                my_puts_string (dbgSndPort);
            break;
          case DBG_HSCMD:
                strncpy(cmd_buf,subval_addr,3 );
                
                if((*subval_addr >= '0') && (*subval_addr < '9')){
                  dbgLevel = (char)(atoi(subval_addr));
                  if(dbgLevel > 9) dbgLevel = 9;
                }
                sprintf(dbgSendbuf,"dbgLv=%d",dbgLevel);
                my_puts_string (dbgSndPort);
            break;
          case 13:
                  strncpy(cmd_buf,subval_addr,30 );
                  
                  if(cmd_buf[0] == '1'){
                    sbi (iotState, DEVICE_READY_STIOT);
                    i = 4;
                    while(i--) subval_addr++;
                    strcpy(ipAddress,cmd_buf+4);
                    
                    subval_addr = strtok (ipAddress ,"/\0"); 

                    sprintf(dbgSendbuf," iP=%s",ipAddress);
                    my_puts_string (dbgSndPort);
                  }
                  else{
                    sprintf(dbgSendbuf,"s=%s",cmd_buf);
                    my_puts_string (dbgSndPort);
                  }
            break;   
          case 14:
                sbi (iotState, DEVICE_READY_STIOT);
            break;
          case 15:
                //strncpy(ipAddress,"%s",) ipAddress[]
            break;
          case 16:
                i = 0;
                while(1)
                {
                  if(*addr == '#')break;
                  addr++;
                  subCmdValIndex++;
                  if(subCmdValIndex > (1024))break; 
                }
                strcpy(cmd_buf, "5552FFFF*AA");
                if( strncmp (cmd_buf, addr,11) == 0) sbi(resetSw, 0);
                
                sprintf(dbgSendbuf,"resetSW=%x,s:%d",resetSw,subCmdValIndex);
                my_puts_string (dbgSndPort);
            break;
          case 19:
                itoMsgInFlag = 1;
            break; 
          case 21:
                strcpy(cmd_buf,subval_addr);
                //putchar2 (subCmdValIndex);
                get_time (cmd_buf);
                sprintf(dbgSendbuf,"%s",datetime);
                my_puts_string (dbgSndPort);
            break;
          case 22:
                sprintf(dbgSendbuf,"rOK\r\n",datetime);
                bRxOk = 1;
                my_puts_string (dbgSndPort);
            break;
				  case SAVE_HSC:
				  		gdataSaveFlag = 1;
				  	break;
				  case LOAD_HSC:
				  		gdataLoadFlag = 1;
				  	break;
				  case SEV_HSC:
                strncpy(cmd_buf,subval_addr,3 );

                if((*subval_addr > '0') && (*subval_addr < '9')){
                  tmp_iii = (atoi(subval_addr));
                  if(tmp_iii > 20000) tmp_iii = 20000;
				  
				  				ee.PortNumber += tmp_iii;
				  				ee.TcpPort += tmp_iii;
				  				ee.SendDelay += tmp_iii;
				  				ee.InverterCount += (char)tmp_iii;
				  				ee.P_BPS_485 += (char)tmp_iii;
				  				ee.P_MODE_232 += (char)tmp_iii;
									}else{
										 if(*subval_addr == '0')
					                      eeSave_eeVal_once();
									}
		  		 printf("%d,%d,%d,%d,%d,[%d.%d.%d.%d],%d,%d,%d\r\n"		
			    	,ee.PortNumber 
			    	,ee.TcpPort
			    	,ee.SendDelay
			    	,ee.SendTimer 
			    	,ee.InverterCount
			    	,ee.IpAddress[0],ee.IpAddress[1],ee.IpAddress[2],ee.IpAddress[3]
			    	,ee.ModelInverter
			    	,ee.P_MODE_232
			    	,ee.P_BPS_485 
			    );
		 		 	break;
	     	  case 26:
                strncpy(cmd_buf,subval_addr,3 );
                
                if((*subval_addr >= '0') && (*subval_addr < '9')){
                  tmp_c  = (char)(atoi(subval_addr));
								  if((tmp_c >= 0) && (tmp_c < 99))
								  ee.ModelInverter = tmp_c ;
								  gValIniFalg = 1;
                }
                sprintf(dbgSendbuf,"ivModeNum=%d",ee.ModelInverter);
                my_puts_string (dbgSndPort);
            break;
				  case 27:
				  	gFlcdIni = 1;
				  	break;
				  case 28:
					case SOFT_RESET:	
					  printf("now sys reboot....%d",ee.ModelInverter);
					  //my_puts_string (dbgSndPort);
				      watchdog_enable(100, 1);
					  while(1);
				  	break;

					case 29:
							//show_fi();
						h_Flash_cmd();
						break;
					case SET_COMMMNUM:
									strncpy(cmd_buf,subval_addr,3 );
					
									tmp_iii = (atoi(cmd_buf));
									if((tmp_iii > 99) || (tmp_iii < 0)) return 0;
					
									
									if(tmp_iii != 0)	devInfo.devNum_485comm = tmp_iii;
									
									printf("devNum=%02d,%X",devInfo.devNum_485comm , nml35State); 
						break;
					case TOSS_232:
							
							if(passThroughFlag) {
								passThroughFlag = 0;
								printf("toss_mode OFF!");
							}else{ 
								passThroughFlag = 1;
								printf("toss_mode ON!");
							}
						break;
					case LORA_RST_CMD:
								sbi(gResetSw, LORA_RSW); 
								printf("nowlora_reset..."); 
						break;
			    case (MAX_NUM_FROMPCCMD - 1):
						  i = 1;
						  while(1){
						  sprintf(dbgSendbuf,"\r\n%s",frompccmd_str_m2m[i]);
						  my_puts_string (dbgSndPort);
						  i++;
						  if(i >= (MAX_NUM_FROMPCCMD-1))break;
					      }
		        break;
         default:
                sprintf(dbgSendbuf,"num:[%0d,d_code:0x%02X\r\n]",i,subCmdValIndex);
                my_puts_string (dbgSndPort);
            break;
        }

      return 0;
} 

 
 
 uc08 Cmd_judge_usb(char * dest){
	 char tcmd_code = 0;
	 char tmp_c ;
	 char cmd_buf[50] = {0};
	 int subCmdValIndex = 0 , tmp_iii , j;
	 ui16 tmp_i  ;
	 char gsktota ;
	 char * addr = dest;
	 char * subval_addr = dest;
	 char i=0; 
	 static char * dbgSendbuf = txdatadbg;
	 static char dbgSndPort = ToDbg;
	 int i2c_errcode ;
	 sni buff = {0} ;
	 
	 // match 1cmd
			 i	= (MAX_NUM_FROMUSB - 1);
			 while(i)
			 {
				 //strcpyf(cmd_buf,frompccmd_str_m2m[i]);
				 //subCmdValIndex = strcspn(frompccmd_str_m2m[i],srt_4comp_prompc);
				 subCmdValIndex =  strlen(frompccmd_str_usb[i]);
				 addr = dest;
				 while(*addr){
					if(*addr ==  *frompccmd_str_usb[i]) break;
					addr++;
				 } 
				 if(strncmp(addr,frompccmd_str_usb[i],subCmdValIndex) == 0) break;
				 DEC (i);
			 }
			 subval_addr = addr;
			 while(subCmdValIndex--) subval_addr++;
			 while(*subval_addr){
				 if(*subval_addr != ' ')break;
				 subval_addr++;
			 } 

 
			 //if((i != 11) && (dbgLevel == 0)) dbgSndPort = 0xff;
 
			 switch(i){
					 case NO_HSC_USB:
								 sprintf(dbgSendbuf,"No_cmd,%d",i);
								 my_puts_string (dbgSndPort);
						 break;
					 case END_CHAR_HSC_USB:	// 0x0d0x0a -> not action 
					 case OK_HSC_USB:
						 break;					 
					 case DBG_HSC_USB:
						 strncpy(cmd_buf,subval_addr,3 );
						 
						 if((*subval_addr >= '0') && (*subval_addr < '9')){
							 dbgLevel = (char)(atoi(subval_addr));
							 if(dbgLevel > 9) dbgLevel = 9;
						 }
						 sprintf(dbgSendbuf,"dbgLv=%d",dbgLevel);
						 my_puts_string (dbgSndPort);
						 break;
					 case SAVE_HSC_USB:
						 gdataSaveFlag = 1;
						 break;
					 case LOAD_HSC_USB:
						 gdataLoadFlag = 1;
						 break;
					 case SEV_HSC_USB:
							 strncpy(cmd_buf,subval_addr,30 );
							 i = 0;

					 			 if(cmd_buf[0] == '1'){			
								 sbi (iotState, DEVICE_READY_STIOT);
								 i = 4;
								 while(i--) subval_addr++;
								 strcpy(ipAddress,cmd_buf+4);
								 
								 subval_addr = strtok (ipAddress ,"/\0"); 

								 sprintf(dbgSendbuf," iP=%s",ipAddress);
								 my_puts_string (dbgSndPort);
							 }
							 else{
								 sprintf(dbgSendbuf,"s=%s",cmd_buf);
								 my_puts_string (dbgSndPort);
							 } 
						 break;
					 case RESET_HSC_USB:

									if(strncmp(subval_addr,"lcd",3) == 0){
										gFlcdIni = 1;
									}else if(strncmp(subval_addr,"lora",3) == 0){
									  sbi(gResetSw, LORA_RSW);
									}else if(strncmp(subval_addr,"iot",3) == 0){
										
									}else if(strncmp(subval_addr,"sys",3) == 0){
										printf("now sys reboot....\r\n");
										watchdog_enable(100, 1);
										while(1);
									}else{
										printf("option?:lcd,lora,iot,sys ..\r\n");									 
									 //my_puts_string (dbgSndPort);
									}
						 break; 	
					 case SET_COMMMNUM_HSC_USB:
									 strncpy(cmd_buf,subval_addr,3 );
					 
									 tmp_iii = (atoi(cmd_buf));
									 if((tmp_iii > 99) || (tmp_iii < 0)) return 0;
					 
									 if(tmp_iii == 1 ) sbi(nml35State, 3);
									 else cbi(nml35State, 3);
									 
									 if(tmp_iii != 0)  devInfo.devNum_485comm = tmp_iii;
									 
									 printf("devNum=%02d,%X",devInfo.devNum_485comm , nml35State); 
						 break;
					 case TOSS_232_HSC_USB:
							 
							 if(passThroughFlag) {
								 passThroughFlag = 0;
								 printf("toss_mode OFF!");
							 }else{ 
								 passThroughFlag = 1;
								 printf("toss_mode ON!");
							 }
						 break;
					 case (MAX_NUM_FROMUSB - 1):
							 i = 1;
							 while(1){
							 sprintf(dbgSendbuf,"\r\n%s",frompccmd_str_usb[i]);
							 my_puts_string (dbgSndPort);
							 i++;
							 if(i >= (MAX_NUM_FROMUSB -1))break;
							 }
							 printf("\r\n");
						 break;
					default:
								 sprintf(dbgSendbuf,"num:[%0d,d_code:0x%02X\r\n]",i,subCmdValIndex);
								 my_puts_string (dbgSndPort);
						 break;
				 }
 
			 return 0;
 } 


 
 
 //------  inv Info ----------




 unsigned int adcVal[6] = {0};
 signed char adcValue = 0x12,oldAdcValue;
 unsigned char adcValue2, oldAdcValue2;
 ui16 key_val = 0x1f;


 char test_mk_ccs(char inv_number)
 {
    char ccs;
    
    ccs = 0;
     ccs ^= 'T';
     ccs ^= (char)(ee.PortNumber/0x100);
     ccs ^= (char)(ee.PortNumber%0x100);
     ccs ^= (inv_number+0x30);
 
     inv_number--;
 
     ccs ^= (char)adcValue;
     ccs ^= (char)adcValue2;
     ccs ^= (char)adcValue; 
     ccs ^= (char)rssiLevel;
     ccs ^= (char)key_val;
     
     ccs ^= (char)(inverter[inv_number].inverter_status[0]/0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[0]%0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[1]/0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[1]%0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[2]/0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[2]%0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[3]/0x100);
     ccs ^= (char)(inverter[inv_number].inverter_status[3]%0x100);
         
         
     ccs ^= (char)(inverter[inv_number].solar_cell_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].solar_cell_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].solar_cell_current/0x100);
     ccs ^= (char)(inverter[inv_number].solar_cell_current%0x100);
 
     ccs ^= (char)(inverter[inv_number].inv_u_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_u_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_voltage%0x100);
   
     ccs ^= (char)(inverter[inv_number].inv_u_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_u_current%0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_current%0x100);
         
     ccs ^= (char)(inverter[inv_number].inv_w_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_current%0x100);
     ccs ^= (char)(inverter[inv_number].inv_frequency/0x100);
     ccs ^= (char)(inverter[inv_number].inv_frequency%0x100); 
     
   ccs ^= (char)(inverter[inv_number].inv_u_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_u_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_voltage/0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_voltage%0x100);
     ccs ^= (char)(inverter[inv_number].inv_u_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_u_current%0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_v_current%0x100);
         
     ccs ^= (char)(inverter[inv_number].inv_w_current/0x100);
     ccs ^= (char)(inverter[inv_number].inv_w_current%0x100);
     ccs ^= (char)(inverter[inv_number].inv_frequency/0x100);
     ccs ^= (char)(inverter[inv_number].inv_frequency%0x100);
     
     ccs ^= (char)(inverter[inv_number].power_solar/0x100);
     ccs ^= (char)(inverter[inv_number].power_solar%0x100);
     ccs ^= (char)((inverter[inv_number].power_inv_total>>24)&0xff);
     ccs ^= (char)((inverter[inv_number].power_inv_total>>16)&0xff);
     ccs ^= (char)((inverter[inv_number].power_inv_total>>8)&0xff);
     ccs ^= (char)(inverter[inv_number].power_inv_total&0xff);
     ccs ^= (char)(inverter[inv_number].power_inv_now/0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_now%0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_now/0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_now%0x100);
 
     ccs ^= (char)(inverter[inv_number].power_inv_day_total/0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_day_total%0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_pf/0x100);
     ccs ^= (char)(inverter[inv_number].power_inv_pf%0x100);
 
   return ccs;
 }

 uc08 ui_2_uc(uc08 num ,ui16 val ){
   uni temp;
   temp.di[0] = val;
   return temp.dc[num]; 
   }

 uc08 ul_2_uc(uc08 num ,ul32 val){
   uni temp;
   temp.dl = val;
   return temp.dc[num]; 
 }

void make_iot_paket_4_iot(char inv_number){
  char buf[100] = {0};

  char ccs = 0;

//  memset(txdataIot,0,sizeof(txdataIot));
  
  

  sprintf(buf,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
             ,0x55
             ,'T'
             ,ui_2_uc (1,ee.PortNumber)
             ,ui_2_uc (0,ee.PortNumber)
             ,(inv_number + 0x30)
             ,(uc08) adcValue
             ,(uc08) adcValue2
             ,(uc08) adcValue
             ,ui_2_uc(0, rssiLevel)
             ,ui_2_uc(0, key_val)
             );
  //strcat(txdataIot,buf);
  sprintf(txdataIot , "AT+WSOWR=0,136,FFFF%s",buf);
  memset(buf,0,sizeof(buf));

  ccs = test_mk_ccs (inv_number);
  
  inv_number--;
  
  sprintf(buf,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
             ,ui_2_uc(1,inverter[inv_number].inverter_status[0])
             ,ui_2_uc(0,inverter[inv_number].inverter_status[0])
             ,ui_2_uc(1,inverter[inv_number].inverter_status[1])
             ,ui_2_uc(0,inverter[inv_number].inverter_status[1])
             ,ui_2_uc(1,inverter[inv_number].inverter_status[2])
             ,ui_2_uc(0,inverter[inv_number].inverter_status[2])
             ,ui_2_uc(1,inverter[inv_number].inverter_status[3])
             ,ui_2_uc(0,inverter[inv_number].inverter_status[3])
             ,ui_2_uc(1,inverter[inv_number].solar_cell_voltage)
          	 ,ui_2_uc(0,inverter[inv_number].solar_cell_voltage)
          	 ,ui_2_uc(1,inverter[inv_number].solar_cell_current)
          	 ,ui_2_uc(0,inverter[inv_number].solar_cell_current)
              );
  strcat(txdataIot,buf);
  
  memset(buf,0,sizeof(buf));

  sprintf(buf,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
              ,ui_2_uc(1,inverter[inv_number].inv_u_voltage)
          		,ui_2_uc(0,inverter[inv_number].inv_u_voltage)
          		,ui_2_uc(1,inverter[inv_number].inv_v_voltage)
          		,ui_2_uc(0,inverter[inv_number].inv_v_voltage)
          		,ui_2_uc(1,inverter[inv_number].inv_w_voltage)
          		,ui_2_uc(0,inverter[inv_number].inv_w_voltage)
          		,ui_2_uc(1,inverter[inv_number].inv_u_current)
          		,ui_2_uc(0,inverter[inv_number].inv_u_current)
          		,ui_2_uc(1,inverter[inv_number].inv_v_current)
          		,ui_2_uc(0,inverter[inv_number].inv_v_current)
          		,ui_2_uc(1,inverter[inv_number].inv_w_current)
          		,ui_2_uc(0,inverter[inv_number].inv_w_current)
          		,ui_2_uc(1,inverter[inv_number].inv_frequency)
          		,ui_2_uc(0,inverter[inv_number].inv_frequency)
          		);
    strcat(txdataIot,buf);
    memset(buf,0,sizeof(buf));

  sprintf(buf,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
           ,ui_2_uc(1,inverter[inv_number].inv_u_voltage)
           ,ui_2_uc(0,inverter[inv_number].inv_u_voltage)
           ,ui_2_uc(1,inverter[inv_number].inv_v_voltage)
           ,ui_2_uc(0,inverter[inv_number].inv_v_voltage)
           ,ui_2_uc(1,inverter[inv_number].inv_w_voltage)
           ,ui_2_uc(0,inverter[inv_number].inv_w_voltage)
           ,ui_2_uc(1,inverter[inv_number].inv_u_current)
           ,ui_2_uc(0,inverter[inv_number].inv_u_current)
           ,ui_2_uc(1,inverter[inv_number].inv_v_current)
           ,ui_2_uc(0,inverter[inv_number].inv_v_current)
           ,ui_2_uc(1,inverter[inv_number].inv_w_current)
           ,ui_2_uc(0,inverter[inv_number].inv_w_current)
           ,ui_2_uc(1,inverter[inv_number].inv_frequency)
           ,ui_2_uc(0,inverter[inv_number].inv_frequency)
           );  
    
    strcat(txdataIot,buf);
    memset(buf,0,sizeof(buf));       


  sprintf(buf,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
        		,ui_2_uc(1,inverter[inv_number].power_solar)
        		,ui_2_uc(0,inverter[inv_number].power_solar)
        		,ul_2_uc(3,inverter[inv_number].power_inv_total)
        		,ul_2_uc(2,inverter[inv_number].power_inv_total)
        		,ul_2_uc(1,inverter[inv_number].power_inv_total)
        		,ul_2_uc(0,inverter[inv_number].power_inv_total)
        		,ui_2_uc(1,inverter[inv_number].power_inv_now)
        		,ui_2_uc(0,inverter[inv_number].power_inv_now)
        		,ui_2_uc(1,inverter[inv_number].power_inv_now)
        		,ui_2_uc(0,inverter[inv_number].power_inv_now)
// ??     ,ul_2_uc(3,inverter[inv_number].power_inv_day_total),
// ??     ,ul_2_uc(2,inverter[inv_number].power_inv_day_total),
        		,ul_2_uc(1,inverter[inv_number].power_inv_day_total)
        		,ul_2_uc(0,inverter[inv_number].power_inv_day_total)
        		,ui_2_uc(1,inverter[inv_number].power_inv_pf)
        		,ui_2_uc(0,inverter[inv_number].power_inv_pf)
        		);
  
    strcat(txdataIot,buf);
    memset(buf,0,sizeof(buf));  
    
    //ccs = mk_ccs(&txdataIot[0],0);
    
    
    sprintf(buf,"%01XAA\r\n",ccs);

    strcat(txdataIot,buf);
    memset(buf,0,sizeof(buf));
    
  }

void make_iot_paket_4_iot_mdm (char inv_number){
     int i = 0;

     make_iot_paket_4_iot (inv_number);

     while((txdataIot[i + 17]) != 0){
       txdataIot[i] = txdataIot[i + 15];
       i++;
       if(i >= (1024 - 2) )break;
     }
     txdataIot[i] = 0;
}


void get_time(char* str_clk)
{
    
    int nowHour;
    int nowHour2;
    int nowMinute;
    int nowMinute2;
    int nowSecond;
    int nowYear;
    int nowMonth;
    int nowDay;
    int t_zone;
    char * ptr = str_clk;

    ptr = strtok(str_clk,"/,:+");
    nowYear = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+");
    nowMonth = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+");
    nowDay = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+");
    nowHour = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+");
    nowMinute = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+");
    nowSecond = (ui16)atoi(ptr);
    ptr = strtok(0x0,"/,:+\"");
    t_zone = (ui16)atoi(ptr);
    if(t_zone != 0){
      nowHour2 = t_zone / 4;
      nowMinute2 = (t_zone % 4) * 15;
      nowHour += nowHour2;
      nowMinute += nowMinute2;
    }
    sprintf(datetime,"%02d%02d%02d%02d%02d%02d",nowYear,nowMonth,nowDay,nowHour,nowMinute,nowSecond); 
      
}



void  putchar_test(char c, char ini){
    static int cnt = 0 ;
    static char * addr = &txdataIot[1] ;

    if(ini == 0) {
      addr = &txdataIot[0];
      *addr++ = c;
    }
    else {
      *addr++ = c;
      *addr = 0;
    }
    if(cnt >= 1023) {
      cnt = 0;
      addr = &txdataIot[1];
    }  
}



void sendWSOWR_T(char inv_number) {
//WRITE
  char txbuffer2[60] = {0};
  char ic=0;
    char ccs;
//    tx_rd_index2 = tx_wr_index2 = 0;      
//    bchecksum_flag2 = 0;
  ccs = 0;
    ccs ^= 'T';
    ccs ^= (char)(ee.PortNumber/0x100);
    ccs ^= (char)(ee.PortNumber%0x100);
    ccs ^= (inv_number+0x30);

    inv_number--;

    ccs ^= (char)adcValue;
    ccs ^= (char)adcValue2;
    ccs ^= (char)adcValue; 
    ccs ^= (char)rssiLevel;
    ccs ^= (char)key_val;
  ccs ^= (char)(inverter[inv_number].inverter_status[0]/0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[0]%0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[1]/0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[1]%0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[2]/0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[2]%0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[3]/0x100);
  ccs ^= (char)(inverter[inv_number].inverter_status[3]%0x100);
        
        
  ccs ^= (char)(inverter[inv_number].solar_cell_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].solar_cell_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].solar_cell_current/0x100);
  ccs ^= (char)(inverter[inv_number].solar_cell_current%0x100);

  ccs ^= (char)(inverter[inv_number].inv_u_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_current%0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_current%0x100);
        
  ccs ^= (char)(inverter[inv_number].inv_w_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_current%0x100);
  ccs ^= (char)(inverter[inv_number].inv_frequency/0x100);
  ccs ^= (char)(inverter[inv_number].inv_frequency%0x100); 
    
    ccs ^= (char)(inverter[inv_number].inv_u_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_voltage/0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_voltage%0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_u_current%0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_v_current%0x100);
        
  ccs ^= (char)(inverter[inv_number].inv_w_current/0x100);
  ccs ^= (char)(inverter[inv_number].inv_w_current%0x100);
  ccs ^= (char)(inverter[inv_number].inv_frequency/0x100);
  ccs ^= (char)(inverter[inv_number].inv_frequency%0x100);
    
  ccs ^= (char)(inverter[inv_number].power_solar/0x100);
  ccs ^= (char)(inverter[inv_number].power_solar%0x100);
  ccs ^= (char)((inverter[inv_number].power_inv_total>>24)&0xff);
  ccs ^= (char)((inverter[inv_number].power_inv_total>>16)&0xff);
  ccs ^= (char)((inverter[inv_number].power_inv_total>>8)&0xff);
  ccs ^= (char)(inverter[inv_number].power_inv_total&0xff);
  ccs ^= (char)(inverter[inv_number].power_inv_now/0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_now%0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_now/0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_now%0x100);

  ccs ^= (char)(inverter[inv_number].power_inv_day_total/0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_day_total%0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_pf/0x100);
  ccs ^= (char)(inverter[inv_number].power_inv_pf%0x100);

//printf(txbuffer1,"T$$TCPWRITE=!");
    putchar_test('T',1);  
    putchar_test('+',1);  
    putchar_test('W',1);  
    putchar_test('S',1);  
    putchar_test('O',1);  
    putchar_test('W',1);  
    putchar_test('R',1);  
    putchar_test('=',1);  
    putchar_test('0',1);  
    putchar_test(',',1); 
    putchar_test('1',1); 
    putchar_test('3',1);
    putchar_test('6',1);
    putchar_test(',',1);  

    putchar_test('F',1);  
    putchar_test('F',1);  
    putchar_test('F',1);  
    putchar_test('F',1);  
    
    /////////////////////////////////////////////////////////////
  sprintf(txbuffer2,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
        0x55, 'T', (unsigned char)(ee.PortNumber/0x100),(unsigned char)(ee.PortNumber%0x100),(inv_number+0x31),
            

            (unsigned char)adcValue,
            (unsigned char)adcValue2,
            (unsigned char)adcValue,
            (unsigned char)rssiLevel,
            (unsigned char)key_val);  

            
  for(ic=0;ic<20;ic++) {
      putchar_test(txbuffer2[ic] , 1);               
    }                              

  sprintf(txbuffer2,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    
        (unsigned char)(inverter[inv_number].inverter_status[0]/0x100),
    (unsigned char)(inverter[inv_number].inverter_status[0]%0x100),
    (unsigned char)(inverter[inv_number].inverter_status[1]/0x100),
    (unsigned char)(inverter[inv_number].inverter_status[1]%0x100),
    (unsigned char)(inverter[inv_number].inverter_status[2]/0x100),
    (unsigned char)(inverter[inv_number].inverter_status[2]%0x100),
    (unsigned char)(inverter[inv_number].inverter_status[3]/0x100),
    (unsigned char)(inverter[inv_number].inverter_status[3]%0x100),

      
    (unsigned char)(inverter[inv_number].solar_cell_voltage/0x100),
    (unsigned char)(inverter[inv_number].solar_cell_voltage%0x100),
    (unsigned char)(inverter[inv_number].solar_cell_current/0x100),
    (unsigned char)(inverter[inv_number].solar_cell_current%0x100));
  for(ic=0;ic<24;ic++) {
      putchar_test(txbuffer2[ic] , 1);
    }                              

  sprintf(txbuffer2,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned char)(inverter[inv_number].inv_u_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_u_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_v_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_v_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_w_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_w_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_u_current/0x100),
    (unsigned char)(inverter[inv_number].inv_u_current%0x100),
    (unsigned char)(inverter[inv_number].inv_v_current/0x100),
    (unsigned char)(inverter[inv_number].inv_v_current%0x100),

    (unsigned char)(inverter[inv_number].inv_w_current/0x100),
    (unsigned char)(inverter[inv_number].inv_w_current%0x100),
    (unsigned char)(inverter[inv_number].inv_frequency/0x100),
    (unsigned char)(inverter[inv_number].inv_frequency%0x100));
  for(ic=0;ic<28;ic++) {
      putchar_test(txbuffer2[ic] , 1);
    }                              
                          
  sprintf(txbuffer2,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned char)(inverter[inv_number].inv_u_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_u_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_v_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_v_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_w_voltage/0x100),
    (unsigned char)(inverter[inv_number].inv_w_voltage%0x100),
    (unsigned char)(inverter[inv_number].inv_u_current/0x100),
    (unsigned char)(inverter[inv_number].inv_u_current%0x100),
    (unsigned char)(inverter[inv_number].inv_v_current/0x100),
    (unsigned char)(inverter[inv_number].inv_v_current%0x100),

    (unsigned char)(inverter[inv_number].inv_w_current/0x100),
    (unsigned char)(inverter[inv_number].inv_w_current%0x100),
    (unsigned char)(inverter[inv_number].inv_frequency/0x100),
    (unsigned char)(inverter[inv_number].inv_frequency%0x100));  
    
  for(ic=0;ic<28;ic++) {
      putchar_test(txbuffer2[ic] , 1);
    }                              


  sprintf(txbuffer2,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
    (unsigned char)(inverter[inv_number].power_solar/0x100),
    (unsigned char)(inverter[inv_number].power_solar%0x100),
    (unsigned char)((inverter[inv_number].power_inv_total>>24)&0xff),
    (unsigned char)((inverter[inv_number].power_inv_total>>16)&0xff),
    (unsigned char)((inverter[inv_number].power_inv_total>>8)&0xff),
    (unsigned char)(inverter[inv_number].power_inv_total&0xff),
    (unsigned char)(inverter[inv_number].power_inv_now/0x100),
    (unsigned char)(inverter[inv_number].power_inv_now%0x100),
    (unsigned char)(inverter[inv_number].power_inv_now/0x100),
    (unsigned char)(inverter[inv_number].power_inv_now%0x100),

    (unsigned char)(inverter[inv_number].power_inv_day_total/0x100),
    (unsigned char)(inverter[inv_number].power_inv_day_total%0x100),
    (unsigned char)(inverter[inv_number].power_inv_pf/0x100),
    (unsigned char)(inverter[inv_number].power_inv_pf%0x100));
  for(ic=0;ic<28;ic++) {
      putchar_test(txbuffer2[ic] , 1);
    }                              


//    bchecksum_flag2 = 0;
  sprintf(txbuffer2,"%02X%02X",ccs, 0xAA);
  for(ic=0;ic<4;ic++) {
      putchar_test(txbuffer2[ic] , 1);
    }                              
  putchar_test(0x0d , 1);
  putchar_test(0x0a , 1);
                     
//    rx_seq2 = 0;  
//    timeout2 = 15000;
    //UDR2 = 'A';
    txdataIot[0] = 'A';
    
}

int msgNum4mdm =0;
ui16 gTcpPort = 7780;
ui16 recv_length_232 = 68;
uc08 fSoketOpend=0;

ui16 msg_send_2_iot_M2M(void){
    static ui16 wait_time= 0;
    static uc08 sSqcIot_m2m = 0;
    static char * addr_p;
    static char inv_num = 1;
	ui16 sendlength = 0;

    
    if(iotSendSw & bv(CLOCK_ICF)){ 
         sprintf(txdataIot,"AT+CCLK?");
         my_puts_string (ToIot);
	     cbi (iotSendSw, CLOCK_ICF);
         return 0; // wait time; 
       }
    if(iotSendSw & bv(RECEIVEM_MSG_ICF)){
         sprintf(txdataIot,"AT+CMGR=%d\r\n",msgNum4mdm);
         my_puts_string (ToIot) ;
         cbi (iotSendSw, RECEIVEM_MSG_ICF);
         return 0;
   }
       if(iotSendSw & bv(TCPSENDDATA_ICF)){ 
           switch(sSqcIot_m2m) {
           case 0:
                 wait_time = 1;
                 sprintf(txdataIot,"AT+QIOPEN=1,0,\"TCP\",\"hstec.kr\",%d\r\n",gTcpPort);
                 my_puts_string (ToIot) ;
		         sSqcIot_m2m = 1;
            break;
		   case 1:  // soket open check
		         //if(fSoketOpend)
		         sSqcIot_m2m = 2;
				 //else sSqcIot_m2m = 3;
		   	break;
           case 2:
                 if(SendTestPkt) {
				 	sprintf(txdataIot,"AT+QISEND=0,68\r\n");
					SendTestPkt = 0;
				    bRxOk = 1;
                 	sSqcIot_m2m = 21;
                 	}
                 else{
				 	sprintf(txdataIot,"AT+QISEND=0,%d\r\n",recv_length_232); // wait cmd
				 	sSqcIot_m2m = 20;
                 	}
                 my_puts_string (ToIot);
             break;
               case 20:
               case 21: // test pak  
                     sSqcIot_m2m = 3;
                     make_iot_paket_4_iot_mdm (1); 
                     my_puts_string (ToIot);
                 break;
               case 22:
                     sendWSOWR_T(1);
                     my_puts_string (ToIot);
                     sSqcIot_m2m = 3;
                 break;
           case 3:
                 sprintf(txdataIot,"AT+QICLOSE=0\r\n");  // wait cmd
                 my_puts_string (ToIot);
		   	     fSoketOpend = 0;
                 sSqcIot_m2m = 4;
                 if(inv_num > 20) inv_num = 1; 
             break;
		   case 4:
		   	     //sprintf(txdataIot,"AT+QIDEACT=1\r\n");  // wait cmd
                 //my_puts_string (ToIot);
                 cbi (iotSendSw, TCPSENDDATA_ICF);
                 wait_time = 0; // cmd end 
                 if(inv_num > 20) inv_num = 1; 
           default:
                 //  sprintf(txdataIot,"AT+QIRD=0\r\n",recv_length_232);
                 sSqcIot_m2m = 0;
             break;
           }
          return wait_time; //cmd 
       }
       if(iotSendSw & bv(NEWMSGCHECK_ICF)){
         switch(sSqcIot_m2m){
           case 0:
                 sprintf(txdataIot,"AT*SKT*NEWMSG=4098\r\n");
                 my_puts_string (ToIot);
                 sSqcIot_m2m = 1;
                 wait_time = 1; 
           break;
           case 1:
                sprintf(txdataIot,"AT*SKT*MTACK=4098\r\n");
                 my_puts_string (ToIot);
                 sSqcIot_m2m = 0;
                 wait_time = 0;
                 cbi (iotSendSw, NEWMSGCHECK_ICF);
           default:
                 sSqcIot_m2m = 0;
                 wait_time = 0;
           break;
         }
         return wait_time ;   
       }



             
}



void drv_sendTcpControlM2M(void){
  char tmpBuf={0};
  static int drvTimerTcpCtrl = 0;
  static ui16 dsDelay = 0;
  char * addr_p;
  ui16 sendlength;
  static char sSqcIot_m2m = 0;
  static int bootCnt = 0;
  static ui16 giotSetOnCnt;
  
  if((gSysCnt - drvTimerTcpCtrl) < 1000 ) return;  // 1s tic 
  drvTimerTcpCtrl = gSysCnt;
  DEC (dsDelay);

  if(bRxOk == 1){
    bRxOk = 0;
    dsDelay = 0;
    }
   if(dsDelay) return;

  switch(sSqcIot_m2m){
     case 0 : // ini
              gp_ini_h(IOTNROLA_POWER, GPIO_OUT);  
              gpset_high(IOTNROLA_POWER);   // lelay off 
              cbi (iotState, APP_READY);
              giotSetOnCnt = 60;
              dsDelay = 1;
              bootCnt = 0;
              sSqcIot_m2m = 1;
			  fSoketOpend = 0;
        break;
      case 1 : // boot 
              gpset_low(IOTNROLA_POWER); //lelay on 
              dsDelay = 1; 
              if(iotState & bv(APP_READY)) {
              sSqcIot_m2m = 2;
               } else{
                bootCnt++;
                if(bootCnt > 20)sSqcIot_m2m = 0 ;
              }  
		
        break;
      case 2 : // GSN  
             sprintf(txdataIot,"ATE0\r\n");
             //sprintf(txdataIot,"AT$$STAT?\r\n");
             my_puts_string (ToIot) ;
             dsDelay = 3;
              sSqcIot_m2m = 3;
        break;
      case 3 :  // STATE 
             sprintf(txdataIot,"AT+QCDS\r\n");
             my_puts_string (ToIot);
             cbi (iotState, DNSQUERY_STIOT);
             dsDelay = 3;
             sSqcIot_m2m = 4;
        break;
      case 4 :  // clk check 
             sprintf(txdataIot,"AT+CCLK?\r\n");
             my_puts_string (ToIot);
             cbi (iotState, TIMECHECK_STIOT);
             dsDelay = 3;
             sSqcIot_m2m = 5;
        break;
      case 5:
             sprintf(txdataIot,"AT+QICFG=\"dataformat\",1,1\r\n");
             my_puts_string (ToIot);
             dsDelay = 3;
             sSqcIot_m2m = 6;
        break;
      case 6 : // cnmi 
             //sprintf(txdataIot,"AT*SKT*NEWMSG=4098\r\n");  // msg set 
             sprintf(txdataIot,"AT+CNMI=1,2,0,0,0\r\n"); 
             my_puts_string (ToIot) ;
             dsDelay = 3;
             sSqcIot_m2m = 7;
        break;
      case 7:  // cmgf 

             sprintf(txdataIot,"AT+CMGF=1\r\n");   // msg mode set 
             my_puts_string (ToIot) ;
             dsDelay = 3;    
             sSqcIot_m2m = 8;
        break;
      case 8:  //  qiopen  
             dsDelay = 10;
             if(gImd_reaction) {
                gImd_reaction = 0;
                dsDelay = 1;
                }
             if(msg_send_2_iot_M2M()) break;
             if(gDbgFuseCnt < 5) gDbgFuseCnt = 5;
             sSqcIot_m2m = 9;
        break;
      case 9:
             if(iotSendSw)
             sSqcIot_m2m = 8;
        break;
    default:
            sSqcIot_m2m = 0;
      break;
  }

}






ui16 msg_send_2_iot_LTE(void){
    static ui16 wait_time= 0;
    static uc08 sub_sqc = 0;
    static char * addr_p;
    static ui16 sendlength;
    static char inv_num = 1;

    if(iotSendSw & bv(CLOCK_ICF)){ 
      sprintf(txdataIot,"AT+CCLK?");
      my_puts_string (ToIot);
	  cbi (iotSendSw, CLOCK_ICF);
      return 0; // wait time; 
    }
    if(iotSendSw & bv(RECEIVEM_MSG_ICF)){ 
	    switch(sub_sqc){
		case 0:
   		      sprintf(txdataIot,"AT+SKT*MTCNT\r\n");
		      my_puts_string (ToIot);
		      sub_sqc = 1;
			  wait_time = 1; 
			break;
		case 1:
  			sprintf(txdataIot,"AT*SKT*READMT\r\n");
  			my_puts_string (ToIot);
  			cbi (iotSendSw, RECEIVEM_MSG_ICF);
		default:
		      wait_time = 0;
			  sub_sqc = 0;
			break;
	    	}
      return wait_time;
    }
	
    if(iotSendSw & bv(TCPSENDDATA_ICF)){ 
        switch(sub_sqc) {
        case 0:
              sprintf(txdataIot,"AT+WSOCR=0,hstec.kr,%d,1,1\r\n",gTcpPort);
              sub_sqc = 1;
              my_puts_string (ToIot);
              wait_time = 1;
          break;    
        case 1:
              sprintf(txdataIot,"AT+WSOCO=0\r\n");  // wait cmd
              if(SendTestPkt)
              sub_sqc = 21;
              else sub_sqc = 22;
              my_puts_string (ToIot);
          break;
        case 2:
			  // toss 	
//              sprintf(txdataIot,"AT+WSOWR=0,%d,",recv_length_232);
//              my_puts_string (ToIot);
             
//              sendlength =  recv_length_232;
//              addr_p = rxdata_frm_ras;
//              while(sendlength){
//                 DEC(sendlength);
//                 putchar1 (*addr_p++); 
//              }
              sub_sqc = 3;
          break;
        	case 21: // test pak  
                  SendTestPkt = 0;
                  sub_sqc = 3;
                  make_iot_paket_4_iot (1);
                  my_puts_string (ToIot);
              break;
            case 22:
                  sendWSOWR_T(1);
                  my_puts_string (ToIot);
                  sub_sqc = 3;
              break;
        case 3:
              sprintf(txdataIot,"AT+WSOCL=0\r\n");  // wait cmd
              my_puts_string (ToIot);
              cbi (iotSendSw, TCPSENDDATA_ICF);
              wait_time = 0;
              sub_sqc = 0;
              if(inv_num > 20) inv_num = 1; 
          break;    
        default:
              sub_sqc = 0;
          break;
        }
       return wait_time; //cmd 
    }
    if(iotSendSw & bv(NEWMSGCHECK_ICF)){
      switch(sub_sqc){
        case 0:
              sprintf(txdataIot,"AT*SKT*NEWMSG=4098\r\n");
              my_puts_string (ToIot);
              sub_sqc++;
              wait_time = 1; 
        break;
        case 1:
             sprintf(txdataIot,"AT*SKT*MTACK=4098\r\n");
              my_puts_string (ToIot);
              sub_sqc = 100;
              cbi (iotSendSw, NEWMSGCHECK_ICF);
			  wait_time = 0; 
        default:
              sub_sqc = 0;
        break;
      }
      return wait_time ;   
    }

}


void drv_sendTcpControlLTE(void){
  char tmpBuf={0};
  static int drvTimerTcpCtrl = 0;
  static ui16 dsDelay = 0;
  char * addr_p;
  ui16 sendlength;
  static char sSqcILte_uri = 0;
  static int bootCnt = 0;
  static ui16 giotSetOnCnt;
  
  if((gSysCnt - drvTimerTcpCtrl) < 1000 ) return;  // 1s tic 
  drvTimerTcpCtrl = gSysCnt;
  DEC (dsDelay);

  if(bRxOk == 1){
    bRxOk = 0;
    dsDelay = 0;
    }
   if(dsDelay) return;

  switch(sSqcILte_uri){
     case 0 : // ini
							gp_ini_h(IOTNROLA_POWER, GPIO_OUT);
              gpio_hs(22, 1);   // lelay off 
              cbi (iotState, APP_READY);
              giotSetOnCnt = 60;
              dsDelay = 1;
              bootCnt = 0;
              sSqcILte_uri = 1;
			  recv_length_232 = 136;
			  fSoketOpend = 0;
        break;
      case 1 : // boot 
              gpio_hs(IOTNROLA_POWER, 0); //lelay on 
              dsDelay = 1; 
              if(iotState & bv(APP_READY)) {
              sSqcILte_uri = 2;
               } else{
                bootCnt++;
                if(bootCnt > 20)sSqcILte_uri = 0 ;
              } 
        break;
      case 2 : // GSN  
             sprintf(txdataIot,"ATE0\r\n");
             //sprintf(txdataIot,"AT$$STAT?\r\n");
             my_puts_string (ToIot) ;
             dsDelay = 3;
              sSqcILte_uri = 3;
        break;
      case 3 :  // STATE 
             sprintf(txdataIot,"AT+CSQ\r\n");
             my_puts_string (ToIot);
             cbi (iotState, DNSQUERY_STIOT);
             dsDelay = 3;
             sSqcILte_uri = 4;
        break;
      case 4 :  // clk check 
             sprintf(txdataIot,"AT$$STAT?\r\n");
             my_puts_string (ToIot);
             cbi (iotState, DEVICE_READY_STIOT);
             dsDelay = 3;
             sSqcILte_uri = 5;
        break;
      case 5:
             sprintf(txdataIot,"AT+CCLK?\r\n");
			 cbi (iotState, TIMECHECK_STIOT);
             my_puts_string (ToIot);
             dsDelay = 3;
             sSqcILte_uri = 6;
        break;
      case 6 : // cnmi 
             //sprintf(txdataIot,"AT*SKT*NEWMSG=4098\r\n");  // msg set 
			  dsDelay = 10;
             if(gImd_reaction) {
                gImd_reaction = 0;
                dsDelay = 1;
                }
			  if(msg_send_2_iot_LTE()) break;
            if(gDbgFuseCnt < 5) gDbgFuseCnt = 5;
 	          sSqcILte_uri = 7;
        break;
      case 7:  // cmgf 
             if(iotSendSw)
             sSqcILte_uri = 6;
        break;
    default:
            sSqcILte_uri = 0;
      break;
  }

}




void eeSave_eeVal_once(void){
    ee.PortNumber = 9999;
	ee.TcpPort     = 5000;
	ee.SendDelay	= 60000;
	ee.SendTimer    = 1000;
	ee.InverterCount = 4 ;
	ee.IpAddress[0];ee.IpAddress[1];ee.IpAddress[2];ee.IpAddress[3];
	ee.ModelInverter = 1;
	ee.P_MODE_232 = 0;
	ee.P_BPS_485  = 0; 
	}

void show_eeval(void){
 printf("%d,%d,%d,%d,%d,[%d.%d.%d.%d],%d,%d,%d\r\n" 	
		,ee.PortNumber 
		,ee.TcpPort
		,ee.SendDelay
		,ee.SendTimer 
		,ee.InverterCount
		,ee.IpAddress[0],ee.IpAddress[1],ee.IpAddress[2],ee.IpAddress[3]
		,ee.ModelInverter
		,ee.P_MODE_232
		,ee.P_BPS_485 
	);
}

void drv_eep_at24c128(void){
	static int dSqc_eep;
	static int delay_da = 0 ;
	static ui16 numberOfsaveVal =0;
	static ui16 maxNumOfeeval;
	static int errcode;
	if((gSysCnt - delay_da) < 10 ) return;
	delay_da  = gSysCnt; 
	
	switch(dSqc_eep){
		case 0: // initial
			//if(loadOnceFlag == 0)
			//eeSave_eeVal_once();
			numberOfsaveVal = 0;
			//maxNumOfeeval =    eep_addr(&(uEepv.su.dummy_endof_eepval));
			maxNumOfeeval =   4;
			dSqc_eep = 1;
			break;
		case 1: // wait 
			dSqc_eep = 5;
			break; 
		case 11: // stb. 
			if(numberOfsaveVal++ < maxNumOfeeval) dSqc_eep = 1;
			else {
				dSqc_eep = 12;
				gdataLoadFlag = 0;
				}
			break;
		case 12:
			dSqc_eep = 3;
			break;
		case 13:
			errcode = load_eep_page();
			printf("EEPec:%d,%x\r\n",errcode,errcode);		
			gdataLoadFlag = 0;
			dSqc_eep = 12;
			break;	
		case 2:	
			dSqc_eep =23;
			break;
		case 21: // save 
			errcode = save_eep(&(uEepv.addi[numberOfsaveVal]));
			printf("%d,[%x],%d,[%x]\r\n",numberOfsaveVal,errcode,uEepv.addi[numberOfsaveVal],uEepv.addi[numberOfsaveVal]);
			dSqc_eep = 22;
			break;
		case 22: // stb
			if(numberOfsaveVal++ < maxNumOfeeval) dSqc_eep = 21;
				else{
					dSqc_eep = 3;
					gdataSaveFlag = 0;
					}
			break;
		case 23:
			errcode = save_eep_page();
			printf("ec:%d,%x\r\n",errcode,errcode);		
			dSqc_eep = 3;
			gdataSaveFlag = 0;
			break;
		case 3: // show 
			show_eeval();
			dSqc_eep++;
			break;
		case 4: // copy show  
			dSqc_eep++;
			numberOfsaveVal = 0;
			break;
		case 5:
			if(gdataSaveFlag == 1) dSqc_eep = 2;
			if(gdataLoadFlag == 1) dSqc_eep = 13;	
			break;
		default:
			dSqc_eep = 0;
			break;
	}
}

void show_fi (void){
	
	extern const uint32_t __flash_binary_start;
	extern const uint32_t __flash_binary_end;

	printf("flash_start :0x%X\r\n",&__flash_binary_start);
	printf("flash_end :0x%X\r\n",&__flash_binary_end);
	printf("SIZE :%d KB \r\n",((uint32_t) &__flash_binary_end - (uint32_t)&__flash_binary_start) /1024);
	
}



void drv_key_check(void){
	static int delay_keyCheck = 0 ;
	static int dSqc_keyCheck = 99  ;
	static int dOld_keyStat = 0;
	static int dNew_keyStat = 0;
	static int dLongkeyCnt = 0;

	
	if((gSysCnt - delay_keyCheck) < 10 ) return;
	delay_keyCheck  = gSysCnt; 

	switch(dSqc_keyCheck){
		case 0:
			if(gpio_get(ADC0))
				sbi(dNew_keyStat, 1);
			else cbi(dNew_keyStat, 0); 
			if(gpio_get(ADC1))
				sbi(dNew_keyStat, 1);
			else cbi(dNew_keyStat, 0);
			dSqc_keyCheck++;
		break;
		case 1:
			dSqc_keyCheck = 2;
			gkey = NO_KEY;
			if(dNew_keyStat  &  bv(1)) dSqc_keyCheck = 12;
			if(dNew_keyStat  &  bv(0)) dSqc_keyCheck = 11;
		break;
		case 11:
			if(gpio_get(ADC0)){ 
				dLongkeyCnt++;
				break;
			}
			if(dLongkeyCnt > 100) gkey = KEY0_LONG;
			else gkey = KEY0;
			dSqc_keyCheck = 2;
		break;
		case 12:
			if(gpio_get(ADC1)){ 
				dLongkeyCnt++;
				break;
			}
			if(dLongkeyCnt > 100) gkey = KEY1_LONG;
			else gkey = KEY1;
			dSqc_keyCheck = 2;
		break;	
		case 2:
			if(gpio_get(ADC0)) break;
			if(gpio_get(ADC1)) break;
			if( gkey == NO_KEY ){
				dOld_keyStat =  dNew_keyStat;
				break;
			} 
		break;
		default:
			gpio_init(ADC0);
			gpio_set_dir(ADC0, GPIO_IN);
			gpio_pull_down(ADC0);
			gpio_init(ADC1);
			gpio_set_dir(ADC1, GPIO_IN);
			gpio_pull_down(ADC1);
			gkey = NO_KEY;
		break;
	}
}


