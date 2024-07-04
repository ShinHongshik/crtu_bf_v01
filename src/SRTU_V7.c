
//#include "..\inverter_V5\inverter_DassTechAll.h"	//addr:0   

#include "hs_global.h"

#define BUZZER_GOOD		0xA03C
#define BUZZER_ERROR	0xff0f   
#define BUZZER_PIN		0x000a
#define BUZZER_TIC		0x01

#define TX_BUFFER_SIZE0 384
#define TX_BUFFER_SIZE1 384
#define TX_BUFFER_SIZE2 384
#define TX_BUFFER_SIZE3 384

#define STX				0x55
#define ETX				0xAA
#define EHD				0x0d
#define CMD_READ_DATA	0x52 //'R'
#define CMD_REQ			0x52
#define CMD_WRITE_DATA	0x57 //'W'   
#define CMD_READ_OFFSET	0x54 //'T'
#define CMD_ACK			0xf0   

#define CHAR_A			0x41 //'A'
#define CHAR_B			0x42 //'B'
#define CHAR_C			0x43 //'C'
#define CHAR_D			0x44 //'D'
#define CHAR_E			0x45 //'E'
#define CHAR_F			0x46 //'F'
#define CHAR_R			0x52 //'R'
#define CHAR_STX		0x02
#define CHAR_ETX		0x03
                                        

#define ENQ				0x06
#define EOT				0x04      

//#define TXEN if(sendReactionTriger != 1)sendReactionTriger = 1

extern char getchar0_h(void);
void drv_recev_inv_tV7(void); 

void putchar0(char c);
void putchar1(char c);
void putchar2(char c);
void putchar3(char c);

void put_str(char y_pos, char x_pos,const char *string, char atr);
unsigned int calcCRC(unsigned char bArray[], unsigned int bCnt);
void drv_send_inv (void);
//---------------------------------------------------------------
extern char txdataInv[1024];
extern char txdataIot[1024];
extern char txdatadbg[1024];
extern uc08 sendReactionTriger;


extern char rx_seq0 ;
extern char rx_seq1 ;
extern char rx_seq2 ;
extern char rx_seq3 ;

extern char rx_buffer3[1024];
extern unsigned int rx_wr_index3 ,rx_rd_index3 ,rx_counter3 ;
extern unsigned int rx_wr_index0, rx_rd_index0, rx_counter0;
extern unsigned int rx_wr_index1, rx_rd_index1, rx_counter1;
extern unsigned int rx_wr_index2, rx_rd_index2, rx_counter2;

//------------------------------------------------------------------
extern char TXEN ;

/* union declaration */
/* union declaration */
union _uFloat {
    float ff;
    unsigned char cc[4];
} uFloat;

union _uLong {
    unsigned long int ff;
    unsigned char cc[4];
} uLong;

union _sLong {
    signed long int ff;
    unsigned char cc[4];
} slong1,slong2,slong3;

union Uni_Data{
		float value;
		unsigned char chars[4];
}fdata;


	extern char dummy[0x10];
	extern unsigned int eePortNumber;
	extern unsigned int eeSendDelay;
	extern unsigned char eeInverterCount; 
	extern char eeIpAddress[4];
	extern unsigned int eeTcpPort;
	extern unsigned int eeSendTimer;
	extern unsigned char eeModelInverter ;

	sInv_val inverter[21]= {0};


//JMH 2018/07/25 
 unsigned char eeDYENPaddress[20];

//JMH 2019/07/19 
 unsigned int variable=1;
//variable=1;
enum{
	 MODEL_INVERTER_DASSTECH3K		//	0
	,MODEL_INVERTER_DASSTECH100K	//	1
	,MODEL_INVERTER_DASSTECH500K	//	2
	,MODEL_INVERTER_DASSTECH3KN 	//	3
	,MODEL_INVERTER_DASSTECH100KN	//	4
	,MODEL_INVERTER_DASSTECH500KN	//	5
	,MODEL_INVERTER_HEXPOWER20K 	//	6
	,MODEL_INVERTER_HEXPOWER3K		//	7
	,MODEL_INVERTER_HEXPOWER		//	8
	,MODEL_INVERTER_HEXPOWER_NEW		//	9
	,MODEL_INVERTER_HYUNDAI 	//	10
	,MODEL_INVERTER_HYMODBUS		//	11
	,MODEL_INVERTER_HYMODBUS50K 		//	12
	,MODEL_INVERTER_HYMODBUS1M			//	13
	,MODEL_INVERTER_KACO20		//	14
	,MODEL_INVERTER_KACO11		//	15
	,MODEL_INVERTER_KACO39		//	16
	,MODEL_INVERTER_KACO		//	17
	,MODEL_INVERTER_LSIS20K 	//	18
	,MODEL_INVERTER_LSIS03K 	//	19
	,MODEL_INVERTER_LSIS50K 	//	20
	,MODEL_INVERTER_LSIS100K		//	21
	,MODEL_INVERTER_LSIS500K		//	22
	,MODEL_INVERTER_ABB33K		//	23
	,MODEL_INVERTER_ABB27K		//	24
	,MODEL_INVERTER_ABB50K				//	25
	,MODEL_INVERTER_ABB_MODBUS		//	26
	,MODEL_INVERTER_ABB_MODBUS1M		//	27
	,MODEL_INVERTER_HYOS36K 	//	28
	,MODEL_INVERTER_HYOS50K 			//	29
	,MODEL_INVERTER_HYOS		//	30
	,MODEL_INVERTER_REFUSOL 	//	31
	,MODEL_INVERTER_SUNGROW3K		//	32
	,MODEL_INVERTER_SUNGROW30K		//	33
	,MODEL_INVERTER_SUNGROW500K 	//	34
	,MODEL_INVERTER_SUNGROW1250K		//	35
	,MODEL_INVERTER_WILLINGSMBUS_A		//	36
	,MODEL_INVERTER_WILLINGS1M		//	37
	,MODEL_INVERTER_WILLINGSMBUS_B		//	38
	,MODEL_INVERTER_WILLINGSMBUS_B5 	//	39
	,MODEL_INVERTER_EKOS		//	40
	,MODEL_INVERTER_XANTREX 	//	41
	,MODEL_INVERTER_DIK 		//	42
	,MODEL_INVERTER_DIKMODBUS		//	43
	,MODEL_IMVERTER_GIFAM115FI		//	44
	,MODEL_INVERTER_SANREX		//	45
	,MODEL_INVERTER_DYENP		//	46
	,MODEL_INVERTER_WINDREX 	//	47
	,MODEL_INVERTER_SMA10K		//	48
	,MODEL_INVERTER_DELTA		//	49
	,MODEL_INVERTER_SOLECTRIA		//	50
	,MODEL_INVERTER_HANSOL3K		//	51
	,MODEL_INVERTER_HANSOL34K			//	52
	,MODEL_INVERTER_DONGEIECOS100K		//	53
	,MODEL_INVERTER_DYENPMBUS		//	54
	,MODEL_INVERTER_KSTAR60K		//	55
	,MODEL_INVERTER_DYENPMBUS50K		//	56
	,MODEL_INVERTER_DYENPMBUS500K		//	57
	,MODEL_INVERTER_SSENG50K			//	58
	,MODEL_INVERTER_SINENG36K			//	59
	,MODEL_INVERTER_SINENG50K			//	60
	,MODEL_INVERTER_CANADIAN50K 		//	61
	,MODEL_INVERTER_KEUMBEE34K			//	62
	,MODEL_INVERTER_SMA2LAN_25K 		//	63
};
// Declare your global variables here   



	unsigned int buzzer_flag;
//	char buzzer_count;
	char cursor_pos;
	unsigned int cur_count;
	char dflag,dcount;
	char vflag;
//	//char rst_flag1, rst_flag2;
//	unsigned char im_output0,im_output1;
//	char led_count;
//	
//	unsigned char icc;
//	        
	unsigned int old_key_val;             
//	extern unsigned int key_val,key_old,key_sw, new_key,key_cnt;
//	unsigned int key_loop;
	unsigned int pc_delay;
//	unsigned int adc_delay;
	char ethernet_fail_count;
	unsigned int ethernet_fail_reset_count;
//	  
//	//// CDMA ////////////////////////////////////////////   
//	char sendSeq,sendTcpCount;
	extern char bRxOk;
//	unsigned int sendDelay;
//	char bSockSendOk;
//	extern char bCSQ, csqCount,bCsqDump;
//	extern unsigned int rssiLevel;
//	unsigned int startTimer;
//	unsigned int sendTimer;
//	char cdmaSendError;
//	char cdmaSendErrorCount;  
//	#define CDMA_SEND_ERROR_COUNT 	5                                  
//	char czCsq[5];
//	int RTU_RESET_COUNT=0;         
//	
//	//// ADC /////////////////////////////////////////////
//	#define ADC_BUFFER_SIZE	0x0f
//	char adcBuffer0[ADC_BUFFER_SIZE+1];
//	
//	signed char adcIndex;                   
//	unsigned int adcSum;
//	extern signed char adcValue,oldAdcValue;
//	extern unsigned char adcValue2, oldAdcValue2;
//	//char adcSeq;
//	
	int im;
	int cim;
	unsigned int rchksum0, chksum0;
	unsigned int rchksum1, chksum1;
//	unsigned int rchksum2, chksum2;
//	//char chksum_high,chksum_low; 
//	//float fim;
	unsigned int inverter_address;
	unsigned int inverter_seq;    
//	unsigned char machine_seq;
	unsigned int inv_read_timer;
	unsigned char invNo,imInvNo;
	unsigned char inv_command, inv_command2;
	unsigned int invCommand;
	unsigned long int lim[4]; 
//	
//	unsigned int msecCount;
//	char bTcpReadFlag;
//	char bTcpReadOK;
//	
	char modelInverter;
//	
	#define RTU_MODE_LAN	0x00
	#define RTU_MODE_RF400	0x01
	#define RTU_MODE_WCDMA	0x02
	#define RTU_MODE_LTE	0x03
	#define RTU_MODE_SETUP	0x0E
	#define RTU_MODE_M2M	0x04
	
//	
	char rtuMode;
//	
	unsigned int timeout0, timeout1, timeout2, timeout3;
//	
	char str[50];
//	char bMsec;          
//	char Send_packet_seq;
//	int sysCnt , dcur_ms;
//	
	unsigned int dsec; 
	unsigned int tx_led_delay; 
	unsigned int rx_led_delay; 
//	char checksum, checksum1, checksum2, checksum3;
	char bchecksum_flag, bchecksum_flag2, bchecksum_flag3;
//	
//	int arrCnt=129;


char gValIniFalg = 0;


//char inverter_seq;


unsigned char sendInverterCount[21], oldSendInverterCount[21]; 

struct {
	unsigned int machineNo; //회사 제품 코드
    unsigned int inverterNo; // 인버터 넘버
    
    unsigned char rtu_temp[4];
    unsigned int rtu_status;

	unsigned int inverter_status[4]; // 상태표시 (회사마다 다름)
    
    unsigned int solar_cell_voltage;
    unsigned int solar_cell_current;    
    
    unsigned int inv_u_voltage;
    unsigned int inv_v_voltage;
    unsigned int inv_w_voltage;//3상 전압
    unsigned int inv_u_current;
    unsigned int inv_v_current;
    unsigned int inv_w_current;//3상 전류
    unsigned int inv_frequency;//주파수

	unsigned int power_solar;//입력 전력
    unsigned long int power_inv_total;//누적 전력
    unsigned int power_inv_now;//전력
    //unsigned int power_inv_max;
    unsigned int power_inv_day_total;//하루 누적 전력(특정회사)   
    unsigned int power_inv_pf;

} remote_inverter[2]; 

//struct {
//	unsigned int inv_status;
//    
//    unsigned int solar_cell_current;
//    unsigned int power_solar;
//    
//    unsigned int inv_current;
//    unsigned int power_inv_now;
//    
//    unsigned int power_inv_day_total;
//
//} imInverterData[10];

/////////SERVER //////////////////////
#define MAX_INVERTER_COUNT 21
 unsigned char inverter_count[MAX_INVERTER_COUNT];
 unsigned int  client_mcno[MAX_INVERTER_COUNT];
 unsigned char rtu_count;
//eeprom unsigned int eeSendDelay;
unsigned int serverReturnValue[MAX_INVERTER_COUNT];
#define SEND_DELAY_SERVER	5000
////////////////////////////////////////




//---------------4SMA ---------------------
struct {
    
    unsigned int solar_cell_voltage;      // dcVolt      A + B  / 2 
    unsigned int solar_cell_current;      // dcCurrent  A + B  
    unsigned int power_solar;          //  dcPower   =  dcPowerA + B 
//    unsigned int power_inv_max;      
    
} ABbuferinverter[2];

struct {
    unsigned int power_solar;
    unsigned int power_inv_now;
    unsigned int power_day_total; 
    unsigned long int power_inv_total;
} generation[2];



unsigned char sw_val;



////////// Connection Box ////////////////////
//eeprom unsigned char eeCidCount;
//struct {
//	unsigned int volt[30];
//    unsigned int crnt[30];
//    unsigned int temp[2];
//} connBoxData[10]; 
char connBoxChannelMax;

//void variables_initial(void) {
//
//}




//=================================






char tx_buffer0[TX_BUFFER_SIZE0]={0};
unsigned int tx_rd_index0 = 0, tx_wr_index0 = 0;
char tx_buffer1[TX_BUFFER_SIZE1]={0};
unsigned int tx_rd_index1 = 0, tx_wr_index1 = 0;
char tx_buffer2[TX_BUFFER_SIZE2]={0};
unsigned int tx_rd_index2 = 0, tx_wr_index2 = 0;
char tx_buffer3[TX_BUFFER_SIZE3]={0};
unsigned int tx_rd_index3 = 0, tx_wr_index3 = 0;

char calBCC , calBCC1, calBCC2, calBCC3;  

//---------------------------------------------
 char dummy[0x10];
 unsigned int eePortNumber = 8906;
 unsigned int eeSendDelay;
 unsigned char eeInverterCount = 1;  
 char eeIpAddress[4];
 unsigned int eeTcpPort;
 unsigned int eeSendTimer;
 unsigned char eeModelInverter=0;


char rx_seq0 = 0;
char rx_seq1 = 0;
char rx_seq2 = 0;
char rx_seq3 = 0;

char UDR0 = 0;
char UDR1 = 0;
char UDR2 = 0;
char UDR3 = 0;

uc08 invCycleComp = 0;

char rxbuff[0xff]; 
char rcnt;
char dcnt;

char TXEN  = 0;

extern char gLastChar_inv;

char getchar0(void){
    char data;
	data  = gLastChar_inv;
    return data;

}


//-----------------------
enum WizDriverState{
	DEVON,
	REACTION,
	NOWTOKEN
	}; 


typedef struct{
			char li_local_id[4];
			char sub_mask[4];
			char gate_way[4];
			char dns_server[4];
			char rh_com_high[3];
			uc08 rh_com_low[22];
			char rmWiz_state[22];
			int baud_rate;
			char mc_mac[6];
			}wiz_modual_info;

wiz_modual_info wizInfo = 
	{
			{192,168,  0,100},
			{255,255,255,  0},
			{192,168,  0,  1},
			{168,126, 63,  1},
			{192,168, 0},
			{104,106,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121},
			{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			1152,
			{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}
			
	};


uc08 invSwitchFlag;

extern see ee;
//-------------------------
void putchar0(char c)
{
	tx_buffer0[tx_wr_index0++]=c;   
	calBCC ^= c;
}

void putchar1(char c)
{
	tx_buffer1[tx_wr_index1++]=c;   
	calBCC1 ^= c;
}
void putchar2(char c)
{
	tx_buffer2[tx_wr_index2++]=c;   
	calBCC2 ^= c;
}
void putchar3(char c)
{
	tx_buffer3[tx_wr_index3++]=c;   
	calBCC3 ^= c;
}

unsigned int Bytes_to_Uint(unsigned char c1, unsigned char c0) {
	unsigned int uint1;
    uint1 = c1;
    uint1 <<= 8;
    uint1 += c0;
    return uint1;
}  

        


typedef struct{
	char x ;
	char y ;
	const char * dst ;
	char atr ;
}lcd_data;

lcd_data sLcd = {0};

void put_str(char y_pos, char x_pos,const char *string, char atr){
	 sLcd.x = y_pos;
	 sLcd.y = x_pos;
	 sLcd.dst = string;
	 sLcd.atr = atr;
}

const unsigned int crc16tab[] = {
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
    0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
    0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
    0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
    0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
    0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
    0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
    0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
    0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
    0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
    0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
    0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
    0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
    0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
    0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
    0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
    0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
    0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
    0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
    0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
    0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
    0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
    0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
    0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
    0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
    0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
    0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
    0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
    0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
    0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};

unsigned int calcCRC(unsigned char bArray[], unsigned int bCnt)
{
    unsigned int im;      
            
    unsigned int crc = 0xffff;

    for (im = 0; im < bCnt; im++)
    {
        crc = (unsigned int)(((crc >> 8) & 0xff) ^ crc16tab[(crc ^ bArray[im]) & 0xff]);
    }
    return crc;
}


void write_dudr(uc08 port,char first)  // dont fix 
{
	int dif_index ;
	
	switch(port)
	{
		case 0:
			UDR0= first;
			sprintf(txdataInv,"%c",first);
			strcat(txdataInv,tx_buffer0);
			sendReactionTriger = 1;
		break;	
		case 1:
			UDR1= first;
			sprintf(txdataIot,"%c",first);
			strcat(txdataIot,tx_buffer1);
			my_puts_string(ToIot);
		break;
		case 2:
			UDR2= first;
		break;
		case 3:
			UDR3 = first;
		break;
		default:
		break;	
	}
	
}

void write_udr0(char c)  // dont fix 
{
		write_dudr( 0 , c);
}
//----------------------------------------------------------------

#include "XLCD12864.h"
//-----------------------------------------------------------------

#define USE_DBG_MODEI 1
#define UDR_CLONE_MODE 1

#include ".\INVERTER_V6\inverter_DassTechNew.h"	//addr:0  


//#include ".\INVERTER_V6\inverter_HyosungMbus36k.h"//addr:C
#include ".\INVERTER_V6\inverter_SMA25K_MbusV1p4.h"//addr:C


#include ".\INVERTER_V6\inverter_HexPower.h"	//addr:1        
#include ".\INVERTER_V6\inverter_Xantrex.h" 	//addr:2   
#include ".\INVERTER_V6\inverter_Hyundai.h"	//addr:3        
#include ".\INVERTER_V6\inverter_HyModbus.h"	//addr:4        
#include ".\INVERTER_V6\inverter_Kaco.h"		//addr:5   
#include ".\INVERTER_V6\inverter_DIK.h"		//addr:6 
#include ".\INVERTER_V6\inverter_GIPAM115.h"   //addr:7  
#include ".\INVERTER_V6\inverter_Lsis.h"		//addr:8        
#include ".\INVERTER_V6\inverter_Lsis100kw.h"		//addr:8        
#include ".\INVERTER_V6\inverter_LST500L.h"		//addr:8        
#include ".\INVERTER_V6\inverter_Kaco39.h"		//addr:9 
#include ".\INVERTER_V6\inverter_ABB.h"		//addr:A
#include ".\INVERTER_V6\inverter_ABB27K.h"		//addr:B
#include ".\INVERTER_V6\inverter_LS03K.h"	//addr:C
#include ".\INVERTER_V6\inverter_HyosungMbus.h"//addr:C
#include ".\INVERTER_V6\inverter_Refusol.h"	//addr:E 

#include ".\INVERTER_V6\inverter_SanRex.h"	//addr:F   
#include ".\INVERTER_V6\inverter_DYENP.h"	//addr:F

//#include "..\inverter_V5\inverter_Kaco11.h"	//addr:F  �����ι��� 3���� �ι��� 1���� �ջ�..
#include ".\INVERTER_V6\inverter_Kaco11M.h"	//addr:F  �����ι��� 3���� �ι��� ���� 3���� ó��

#include ".\INVERTER_V6\inverter_EkosMbus.h"	//addr:F
#include ".\INVERTER_V6\inverter_Windrex3K.h"	//addr:F
#include ".\INVERTER_V6\inverter_SMA10K.h"	//addr:F
#include ".\INVERTER_V6\inverter_Delta.h"		//addr:F
//#include "..\inverter_V5\inverter_Solectria.h"	//addr:F
#include ".\INVERTER_V6\inverter_SunGrow3K.h"	//addr:F   


#include ".\INVERTER_V6\inverter_WILLINGS1M.h"  
//#include "..\inverter_V5\inverter_WILLINGS_MBUS_3EA.h"   
#include ".\INVERTER_V6\inverter_WILLINGS_MbusA.h"    
#include ".\INVERTER_V6\inverter_WILLINGS_MbusB.h"    
//#include "..\inverter_V5\inverter_WILLINGS_MbusB500.h"    
#include ".\INVERTER_V6\inverter_Hansol3k.h"   

#include ".\INVERTER_V6\inverter_HexPower3K.h"	//addr:1        
#include ".\INVERTER_V6\inverter_ABB33K.h"		//addr:B

#include ".\INVERTER_V6\inverter_Kaco20.h"		//addr:B
#include ".\INVERTER_V6\inverter_HexPower20K.h"		//addr:B
#include ".\INVERTER_V6\inverter_DONGEIECOS.h"		//addr:0x24

#include ".\INVERTER_V6\inverter_DikModbus.h"		//addr:0x25        

#include ".\INVERTER_V6\inverter_KSTAR50k.h"		//addr:B  
#include ".\INVERTER_V6\inverter_HyosungMbus36k.h"//addr:C


#include ".\INVERTER_V6\inverter_DYENPModbus.h" //addr:D

#include ".\INVERTER_V6\inverter_HyModbus1M.h" //�����ι��� 4���� ����ó�� 
#include ".\INVERTER_V6\inverter_DYENPModbus500K.h"//500K 
#include ".\INVERTER_V6\inverter_HexPower100K(New).h"  //new protocol
#include ".\INVERTER_V6\inverter_Hansol34k.h"    

#include ".\INVERTER_V6\inverter_HyModbus50k.h"

#include ".\INVERTER_V6\inverter_ABBModbus1M.h"		//addr:A

#include ".\INVERTER_V6\inverter_SunGrow1250K.h"		//addr:A

#include ".\INVERTER_V6\inverter_ABB50KNew.h"		

#include ".\INVERTER_V6\inverter_DYENPModbus50K.h" //addr:D

#include ".\INVERTER_V6\inverter_HyosungMbus50k.h" //addr:D
#include ".\INVERTER_V6\inverter_SINENG36k.h" //addr:D

#include ".\INVERTER_V6\inverter_Canadian50K.h"

#include ".\INVERTER_V6\inverter_Keumbee034K.h"




void variablesInitial(void) {
	int im;
	if( (eePortNumber < 7000) || (eePortNumber > 9500)) {
		eePortNumber = 9499;
	}
	if( (eeSendDelay < 1000) || (eeSendDelay > 65000)) {
		eeSendDelay = 60000;
	}      

    sprintf(str,"%04d", eePortNumber);
	put_str(1,6,str,2);        
    sprintf(str,"%2d", eeInverterCount);
    put_str(7,18,str,1);

    generation[0].power_solar = 9999;
    generation[0].power_inv_now = 9999;
    generation[0].power_day_total = 9999;
    generation[0].power_inv_total = 9999;  
    old_key_val = 0x99;
    
    bchecksum_flag = 0;   
    dsec = 0;        
	rx_wr_index0 = rx_rd_index0 = 0;
	tx_rd_index0 = tx_wr_index0 = 0;
	rx_wr_index1 = rx_rd_index1 = 0;
	tx_rd_index1 = tx_wr_index1 = 0;
	rx_wr_index2 = rx_rd_index2 = 0;
	tx_rd_index2 = tx_wr_index2 = 0;
	rx_wr_index3 = rx_rd_index3 = 0;
	tx_rd_index3 = tx_wr_index3 = 0;
    
	rx_seq0 = rx_seq1 = rx_seq2 = 0;  
	ethernet_fail_count = 0;       
	ethernet_fail_reset_count = 0;
    //Send_packet_seq = 0;  
        
    generation[0].power_solar = 9999;
    generation[1].power_solar = 0;
    generation[0].power_inv_now = 9999;
    generation[1].power_inv_now = 0;
    generation[0].power_day_total = 9999;
    generation[1].power_day_total = 0;
    generation[0].power_inv_total = 9999;
    generation[1].power_inv_total = 0;
    
    
    for(im=0; im<20;im++) {
    	sendInverterCount[im] = 0;
    }          
    //adcIndex = 0;
    inverter_seq = 1;  
	invNo = 1;                     
	rtuMode = ee.P_MODE_232 ;
    
    
 //   startTimer = 30;  
 //   sendTimer = eeSendTimer * 60; 

}

int send_inv_sqc(char ModelNumber){
	
			switch(ModelNumber) 	{  
				case MODEL_INVERTER_SMA2LAN_25K:
					sendInverterRead_SMA_25kMod(); 
				break;	
				case MODEL_INVERTER_DASSTECH3K: 		//0
				case MODEL_INVERTER_DASSTECH100K:		//1
				case MODEL_INVERTER_DASSTECH500K:		//2
					sendInverterRead_DassTech();																		   
					break;	  

				case MODEL_INVERTER_DASSTECH3KN:		//3
				case MODEL_INVERTER_DASSTECH100KN:		//4
				case MODEL_INVERTER_DASSTECH500KN:		//5
					sendInverterRead_DassTechNew(); 																		  
					break;	  
												
				case  MODEL_INVERTER_HEXPOWER3K:		//6
					sendInverterRead_HexPower3K();																			 
					break;						
				case  MODEL_INVERTER_HEXPOWER20K:		//7
					sendInverterRead_HexPower20K(); 																		  
					break;						
				case  MODEL_INVERTER_HEXPOWER:			//8
					sendInverterRead_HexPower();																		   
					break;
									
				case  MODEL_INVERTER_HYUNDAI:			//9
					sendInverterRead_Hyundai(); 																		  
					break;
				case  MODEL_INVERTER_HYMODBUS:			//10
					sendInverterRead_HyModbus();																		   
					break;	 
							 
				case MODEL_INVERTER_KACO11: 			//11
					sendInverterRead_KACO11();
					break;	  
				case MODEL_INVERTER_KACO20: 			//12	
					sendInverterRead_KACO20();
					break;				   
				case MODEL_INVERTER_KACO39: 			//13	
					sendInverterRead_Kaco39();
					break;	
				case MODEL_INVERTER_KACO:	
					sendInverterRead_Kaco();			//14
					break;												 
																		   
				case MODEL_INVERTER_LSIS03K:			//15
					sendInverterRead_Lsis03k(); 		
					break;		  
				case MODEL_INVERTER_LSIS20K:			//16
					sendInverterRead_Refusol(); 		
					break;
				case  MODEL_INVERTER_LSIS50K:			//17
					sendInverterRead_Lsis50K(); 																		  
					break;	 
				case  MODEL_INVERTER_LSIS100K:			//18
					sendInverterRead_Lsis100K();																		   
					break;	  
				case MODEL_INVERTER_LSIS500K:
					sendInverterRead_Ls500k();
					break;		
											   
				case MODEL_INVERTER_ABB27K: 			//19	
					sendInverterRead_Abb27K();
					break;						  
				case MODEL_INVERTER_ABB33K: 			//20	
					sendInverterRead_ABB33K();
					break;	
				case MODEL_INVERTER_ABB_MODBUS: 		//21	
					sendInverterRead_AbbModbus();
					break;				   
								
				case MODEL_INVERTER_HYOS36K:			//22
					sendInverterRead_HyosungMbus36k(); 
					break;	
				case MODEL_INVERTER_HYOS:				//23
					sendInverterRead_HyosungMbus(); 
					break;			
					
				case MODEL_INVERTER_REFUSOL:			//24
					sendInverterRead_Refusol();
					break;
						   
				case MODEL_INVERTER_SUNGROW3K:			//25
				case MODEL_INVERTER_SUNGROW30K: 		//26
				case MODEL_INVERTER_SUNGROW500K:		//27
					sendInverterRead_SunGrow3K();
					break;	  
											   
				case MODEL_INVERTER_WILLINGS1M: 		//28 
					sendInverterRead_Willings1M();
					break;	
				case MODEL_INVERTER_WILLINGSMBUS_A: 	//29
					sendInverterRead_WillingsMbusA();
					break;	
				case MODEL_INVERTER_WILLINGSMBUS_B: 	//29
				case MODEL_INVERTER_WILLINGSMBUS_B5 :	  //61 
					sendInverterRead_WillingsMbusB();
					break;	
					
				case MODEL_INVERTER_EKOS:				//30
					sendInverterRead_EkosMbus();
					break;
				case  MODEL_INVERTER_XANTREX:			//31
					//sendInverterRead_Xantrex();																			
					break;			 
						 
				case MODEL_INVERTER_DIK:				//32
					sendInverterRead_DIK();
					break;		
				case  MODEL_INVERTER_DIKMODBUS: 		//33
					sendInverterRead_DikModbus();																			
					break;	  
					
								   
				case MODEL_IMVERTER_GIFAM115FI: 		//34 
					sendInverterRead_GIPAM115();
					break;		 
				case MODEL_INVERTER_SANREX: 			//35
					sendInverterRead_SanRex();	
					break;	
				case MODEL_INVERTER_DYENP:				//36
					sendInverterRead_DYENP();
					break;
				case MODEL_INVERTER_WINDREX:			//37
					sendInverterRead_Windrex3K();
					break;
				case MODEL_INVERTER_SMA10K: 			//38
					sendInverterRead_SMA10K();
					break;
				case MODEL_INVERTER_DELTA:				//39
					sendInverterRead_Delta();
					break;
				case MODEL_INVERTER_SOLECTRIA:			//40
					//sendInverterRead_Solectria();
					break;
				case MODEL_INVERTER_HANSOL3K:			//41
					sendInverterRead_Hansol3k();
					break;		  
				case  MODEL_INVERTER_DONGEIECOS100K:	//42
					sendInverterRead_DongeiEcos();																			 
					break;				   
				case MODEL_INVERTER_KSTAR60K:			//45	
					sendInverterRead_KSTAR50K();
					break;		 
				 case MODEL_INVERTER_DYENPMBUS: 		//46	
					sendInverterRead_DYENPModbus();
					break;
				 case MODEL_INVERTER_HYMODBUS1M:		//47	
					sendInverterRead_HyModbus1M();
					break;
				 case MODEL_INVERTER_DYENPMBUS500K: 		//48	
					sendInverterRead_DYENPModbus500K();
					break;
					
				 case  MODEL_INVERTER_HEXPOWER_NEW: 		//49
					sendInverterRead_HexPowerNew(); 																		  
					break;
					
				 case MODEL_INVERTER_HANSOL34K: 			//50
					sendInverterRead_HansolModbus();
					break;
				 case  MODEL_INVERTER_HYMODBUS50K:			//51
					sendInverterRead_HyModbus50K(); 																		  
					break;
					
				 case MODEL_INVERTER_ABB_MODBUS1M:			//52
					sendInverterRead_AbbModbus1M(); 																		  
					break;
					
				 case MODEL_INVERTER_SUNGROW1250K:			//53
					sendInverterRead_SunGrow1250K();
					break;
					
				 case MODEL_INVERTER_ABB50K:				//54
					sendInverterRead_ABB50K();
					break;
				
				case MODEL_INVERTER_DYENPMBUS50K:		//55	
					sendInverterRead_DYENPModbus50K();
					break;				   
				
				case MODEL_INVERTER_SSENG50K:		  //56
					sendInverterRead_KSTAR50K();
					break;
					
				case MODEL_INVERTER_HYOS50K:			 //57
					sendInverterRead_HyosungMbus50k();
					break;
					
				case MODEL_INVERTER_SINENG36K:			   //58
				case MODEL_INVERTER_SINENG50K:			   //58
					sendInverterRead_SINENG36k();
					break;
					
				case MODEL_INVERTER_CANADIAN50K:		  //59
					sendInverterRead_Canadian50K();
					break;
					
				case MODEL_INVERTER_KEUMBEE34K: 		   //60
					sendInverterRead_Keumbee34K();
					break;
			}

}

void variablesInitial_v7(void) {
	int im;

	eePortNumber = ee.PortNumber;
	if( (eePortNumber < 7000) || (eePortNumber > 9500)) {
		eePortNumber = 9499;
	}

	eeSendDelay = ee.PortNumber;
	if( (eeSendDelay < 1000) || (eeSendDelay > 65000)) {
		eeSendDelay = 60000;
	}
	modelInverter = ee.ModelInverter;
	rtuMode = ee.P_MODE_232 ;
	

    sprintf(str,"%04d", eePortNumber);
	put_str(1,6,str,2);        
    sprintf(str,"%2d", eeInverterCount);
    put_str(7,18,str,1);

    generation[0].power_solar = 9999;
    generation[0].power_inv_now = 9999;
    generation[0].power_day_total = 9999;
    generation[0].power_inv_total = 9999;  
    old_key_val = 0x99;
    
    bchecksum_flag = 0;   
    dsec = 0;        
	rx_wr_index0 = rx_rd_index0 = 0;
	tx_rd_index0 = tx_wr_index0 = 0;
	rx_wr_index1 = rx_rd_index1 = 0;
	tx_rd_index1 = tx_wr_index1 = 0;
	rx_wr_index2 = rx_rd_index2 = 0;
	tx_rd_index2 = tx_wr_index2 = 0;
	rx_wr_index3 = rx_rd_index3 = 0;
	tx_rd_index3 = tx_wr_index3 = 0;
    
	rx_seq0 = rx_seq1 = rx_seq2 = 0;  
	ethernet_fail_count = 0;       
	ethernet_fail_reset_count = 0;
    //Send_packet_seq = 0;  
        
    generation[0].power_solar = 9999;
    generation[1].power_solar = 0;
    generation[0].power_inv_now = 9999;
    generation[1].power_inv_now = 0;
    generation[0].power_day_total = 9999;
    generation[1].power_day_total = 0;
    generation[0].power_inv_total = 9999;
    generation[1].power_inv_total = 0;
    
    
    for(im=0; im<20;im++) {
    	sendInverterCount[im] = 0;
    }          
    //adcIndex = 0;
    inverter_seq = 1;  
	invNo = 1;                     
	
    
 //   startTimer = 30;  
 //   sendTimer = eeSendTimer * 60; 

}

void drv_send_inv (void)	{
		static int dCnt = 0;
		static int dsSqc = 0;
		static int sInvNum  =0;

		if(sendReactionTriger) return;

		switch(dsSqc){
			case 0: // data ini
					variablesInitial_v7();
					gValIniFalg = 0;	
					for(cim=0; cim<20; cim++) {
						if ((sendInverterCount[cim] > 90) && (oldSendInverterCount[cim] != sendInverterCount[cim])) {
							inverter[cim].inverter_status[0] = 0xff;				 
							inverter[cim].inverter_status[1] = 0xff;				 
							inverter[cim].inverter_status[2] = 0xff;				 
							inverter[cim].inverter_status[3] = 0xff;							
	
							inverter[cim].solar_cell_voltage = 0;				  
							inverter[cim].solar_cell_current = 0;				  
							inverter[cim].inv_u_voltage = 0;				 
							inverter[cim].inv_v_voltage = 0;				 
							inverter[cim].inv_w_voltage = 0;				 
							inverter[cim].inv_u_current = 0;				 
							inverter[cim].inv_v_current = 0;				 
							inverter[cim].inv_w_current = 0;				 
							inverter[cim].power_solar = 0;				   
							inverter[cim].power_inv_now = 0;
						}
					}
					if(rtuMode == RTU_MODE_LAN) {	  
						sprintf(str,"%03d",dsec/1000);
						put_str(2,17,str,1);
					}		
				dsSqc++;	
				break;
			case 1:
				send_inv_sqc(modelInverter);
				if(sendReactionTriger == 1) dsSqc++;
				if(inverter_seq == 0) { 
					dsSqc = 3;
					break;
				}
				break;
			case 2:
				if(gSysCnt == dCnt ) break;
				dCnt = gSysCnt;
				DEC(timeout0);
				if( (timeout0 == 0 ) ||( bRxOk == 1 ) ) dsSqc = 1;
				break;
			case 3:  // wait
				if((gSysCnt - dCnt ) < 1000) break;
				dsSqc=4;
				break;
			case 4:
				inv_read_timer = 1000;
				dsSqc = 1;
				if(gValIniFalg) dsSqc = 0;
				break;
			default:
				dsSqc = 0;
				break;
		}	
		
	//	  
		
	//	if(invCycleComp == 1)inv_read_timer = 1000;	//Command Send Interval = 1 Sec 	
				
	  
				
						
	}


void drv_recev_inv_tV7(void){

            switch(modelInverter) {
                case MODEL_INVERTER_DASSTECH3K:		//0
        	    case MODEL_INVERTER_DASSTECH100K:		//1
      		    case MODEL_INVERTER_DASSTECH500K:		//2
                case MODEL_INVERTER_DASSTECH3KN:	//3
                case MODEL_INVERTER_DASSTECH100KN:	//4
                case MODEL_INVERTER_DASSTECH500KN:	//5
                    rx0Control_DassTechAll();
                    break;
                            
                case MODEL_INVERTER_HEXPOWER3K:		//6
                    rx0Control_HexPower3K();
                    break;   
                case MODEL_INVERTER_HEXPOWER20K:	//7
                    rx0Control_HexPower20K();
                    break;                       
                case MODEL_INVERTER_HEXPOWER:		//8
                    rx0Control_HexPower();
                    break;
                           
                case MODEL_INVERTER_HYUNDAI:		//9
                    rx0Control_Hyundai();
                    break;
                case MODEL_INVERTER_HYMODBUS:		//10
                    rx0Control_HyModbus();
                    break; 
                         
				case MODEL_INVERTER_KACO11:			//11
                	rx0Control_KACO11();
                    break;   
                case MODEL_INVERTER_KACO20: 		//12    
                    rx0Control_KACO20();
                    break;         
                case MODEL_INVERTER_KACO39: 		//13    
                    rx0Control_Kaco39();
                    break;     
                case MODEL_INVERTER_KACO:			//14
                    rx0Control_Kaco();
                    break;     
                            
                case MODEL_INVERTER_LSIS03K: 		//15
                    rx0Control_Lsis03k();
                    break;       
                case MODEL_INVERTER_LSIS20K:		//16
                    rx0Control_Refusol();
                    break;     
                case MODEL_INVERTER_LSIS50K:		//17
                    rx0Control_Lsis50K();
                    break;     
                case MODEL_INVERTER_LSIS100K:		//18
                    rx0Control_Lsis100K();
                    break;            
                case MODEL_INVERTER_LSIS500K:		//18
                    rx0Control_Ls500k();
                    break;            
                            
                case MODEL_INVERTER_ABB27K: 		//19    
                    rx0Control_Abb27K();
                    break;   
                case MODEL_INVERTER_ABB33K: 		//20    
                    rx0Control_ABB33K();
                    break;       
                case MODEL_INVERTER_ABB_MODBUS: 	//21    
                    rx0Control_AbbModbus();
                    break;          
                                       
                case MODEL_INVERTER_HYOS36K:		//22
                    rx0Control_HyosungMbus36k();
                    break;  
                case MODEL_INVERTER_HYOS:			//23
                    rx0Control_HyosungMbus();
                    break;     
                             
                case MODEL_INVERTER_REFUSOL:		//24
                    rx0Control_Refusol();
                    break;         
                               
				case MODEL_INVERTER_SUNGROW3K:		//25		
		        case MODEL_INVERTER_SUNGROW30K:		//26
		        case MODEL_INVERTER_SUNGROW500K:		//26
                	rx0Control_SunGrow3K();
                    break;       
                             
                case MODEL_INVERTER_WILLINGS1M:		//27
                    rx0Control_Willings1M();
                    break;  
                case MODEL_INVERTER_WILLINGSMBUS_A:	//28
                    rx0Control_WillingsMbusA();
                    break;  
                case MODEL_INVERTER_WILLINGSMBUS_B:	//29
                case MODEL_INVERTER_WILLINGSMBUS_B5 : //61
                    rx0Control_WillingsMbusB();
                    break;  
                            
				case MODEL_INVERTER_EKOS:			//30
                	rx0Control_EkosMbus();
                    break;               
                case MODEL_INVERTER_XANTREX:		//31
                    rx0Control_Xantrex();
                    break;
                          
                case MODEL_INVERTER_DIK:			//32
                    rx0Control_DIK();
                    break; 
                case MODEL_INVERTER_DIKMODBUS:		//33
                    rx0Control_DikModbus();
                    break;                   
                               
                case MODEL_IMVERTER_GIFAM115FI:		//34 
                    rx0Control_GIPAM115();
                    break;                            
                case MODEL_INVERTER_SANREX:			//35
                    rx0Control_SanRex();
                    break;
				case MODEL_INVERTER_DYENP:			//36
                	rx0Control_DYENP();
                    break;       
				case MODEL_INVERTER_WINDREX:		//37
                	rx0Control_Windrex3K();
                    break;       
				case MODEL_INVERTER_SMA10K:			//38
                	rx0Control_SMA10K();
                    break;       
				case MODEL_INVERTER_DELTA: 			//39
                	rx0Control_Delta();
                    break;       
				case MODEL_INVERTER_SOLECTRIA:		//40
                	//rx0Control_Solectria();
                    break;       
                case MODEL_INVERTER_HANSOL3K:		//41
                    rx0Control_Hansol3k();
                    break;                                 
                case MODEL_INVERTER_DONGEIECOS100K:	//42
                    rx0Control_DongeiEcos();
                    break;        
                case MODEL_INVERTER_KSTAR60K: 		//43    
                    rx0Control_KSTAR50K();
                    break;   
				case MODEL_INVERTER_DYENPMBUS: 		//46    
                    rx0Control_DYENPModbus();
                    break;
                case MODEL_INVERTER_HYMODBUS1M: 		//47    
                    rx0Control_HyModbus1M();
                    break;
                case MODEL_INVERTER_DYENPMBUS500K: 		//48    
                    rx0Control_DYENPModbus500K();
                    break; 
                case MODEL_INVERTER_HEXPOWER_NEW:		//49
                    rx0Control_HexPowerNew();
                    break;
                case MODEL_INVERTER_HANSOL34K: 			//50
                    rx0Control_HansolModbus();
                    break;
                case MODEL_INVERTER_HYMODBUS50K: 		//51    
                    rx0Control_HyModbus50K();
                    break;
                    
                    
                case MODEL_INVERTER_ABB_MODBUS1M: 		//52   
                    rx0Control_AbbModbus1M();
                    break;
                    
                case MODEL_INVERTER_SUNGROW1250K: 		//53   
                    rx0Control_SunGrow1250K();
                    break;
                    
                case MODEL_INVERTER_ABB50K:                //54
                    rx0Control_ABB50K();
                    break;    
                
                case MODEL_INVERTER_DYENPMBUS50K: 		//55    
                    rx0Control_DYENPModbus50K();
                    break; 
                
                case MODEL_INVERTER_SSENG50K:          //56
                    rx0Control_KSTAR50K();
                    break;
                    
                case MODEL_INVERTER_HYOS50K:             //57
                    rx0Control_HyosungMbus50k();
                    break;  
                
                case MODEL_INVERTER_SINENG36K:             //58
                case MODEL_INVERTER_SINENG50K:             //58
                    rx0Control_SINENG36k();
                    break;
                    
                case MODEL_INVERTER_CANADIAN50K:         //59
                    rx0Control_Canadian50K();
                    break; 
                    
                case MODEL_INVERTER_KEUMBEE34K:
                    rx0Control_Keumbee34K();
                    break;
                     
	            } 
}

void put_strf(char y_pos, char x_pos, const	char *string, char atr)
{
	char buff[40] = {0};
	sprintf(buff,"%s",string); 
	put_str( y_pos,  x_pos,  buff,  atr);
}

//	const char *cCur   = "^";	 
//	const char *cClr  = " ";		 

extern void put_sel_c(char y_pos);




void displayLCD(void) {     
    unsigned char ic=0;
        
    //Rolling cursor bar////////////////////////////// display change
    if (!cur_count) {
        cur_count = 100;
        cursor_pos++;   
        if (cursor_pos>8)cursor_pos=1;
        put_sel_c(cursor_pos);  
            
        if (dcount < 35) {
            dcount++;
        } else {
            dcount = 0;            
        }         
             
	    if ( (rtuMode == RTU_MODE_LAN) || (rtuMode == RTU_MODE_RF400) || (rtuMode == RTU_MODE_WCDMA) || (rtuMode == RTU_MODE_LTE)) {
            if ((vflag == 0) && !dcount) { 
                generation[0].power_solar = 9999; //inverter[0].power_solar + inverter[1].power_solar + inverter[2].power_solar;
                generation[1].power_solar = 0; //inverter[0].power_solar + inverter[1].power_solar + inverter[2].power_solar;
                
                for(im=0; im<eeInverterCount; im++) {
                    generation[1].power_solar += inverter[im].power_solar;
                }
                
                if (generation[0].power_solar != generation[1].power_solar) {
                    generation[0].power_solar = generation[1].power_solar;
                    sprintf(str,"%3d.%dKWh",generation[1].power_solar/10,generation[1].power_solar%10);
                    put_str(3,7,str,1);
                } 

                generation[0].power_inv_now = 9999;//inverter[0].power_inv_now + inverter[1].power_inv_now + inverter[2].power_inv_now;            
                generation[1].power_inv_now = 0;//inverter[0].power_inv_now + inverter[1].power_inv_now + inverter[2].power_inv_now;            
                
                for(im=0; im<eeInverterCount; im++) {
                    generation[1].power_inv_now += inverter[im].power_inv_now;
                }
                
                if (generation[0].power_inv_now != generation[1].power_inv_now) {
                    generation[0].power_inv_now = generation[1].power_inv_now;
                    sprintf(str,"%3d.%dKWh ",generation[1].power_inv_now/10,generation[1].power_inv_now%10);
                    put_str(4,7,str,1);
                }
                
                vflag = 1;                            
            
            } else if ((vflag == 1) && !dcount) { 
                sprintf(str," %3d VDC",inverter[0].solar_cell_voltage);
                put_str(3,7,str,1);
                sprintf(str," %3d VAC",inverter[0].inv_u_voltage);
                put_str(4,7,str,1);
                vflag = 2;
           
            } else if ((vflag == 2) && !dcount) { 
                sprintf(str," %3d ADC",inverter[0].solar_cell_current);
                put_str(3,7,str,1);
                sprintf(str," %3d AAC",inverter[0].inv_u_current);
                put_str(4,7,str,1);
                vflag = 0;
            }   
                
            if ((dflag > 0) && !dcount) {
                dflag = 0;

                put_strf(5,0, "DAY",1);	      
                generation[0].power_day_total = 9999;
                switch(modelInverter) {      
                    //dass ����ó�� 
                    case MODEL_INVERTER_DASSTECH3K:
                    case MODEL_INVERTER_DASSTECH100K:
                    case MODEL_INVERTER_DASSTECH500K:
                    case MODEL_INVERTER_DASSTECH3KN:
                    case MODEL_INVERTER_DASSTECH100KN:
                    case MODEL_INVERTER_DASSTECH500KN:
                        generation[1].power_day_total = 0;//inverter[0].power_inv_day_total + inverter[1].power_inv_day_total + inverter[2].power_inv_day_total;            
                        for(im=0; im<eeInverterCount; im++) {
                            generation[1].power_day_total += inverter[im].power_inv_now;
                        }
                        if (generation[0].power_day_total != generation[1].power_day_total) {
                            generation[0].power_day_total = generation[1].power_day_total;
                            sprintf(str,"%4d.%dKWh   ",generation[1].power_day_total/10,generation[1].power_day_total%10);
                            put_str(5,8,str,1);
                        }
                        break;
                            
                    default:
                        generation[1].power_day_total = 0;//inverter[0].power_inv_day_total + inverter[1].power_inv_day_total + inverter[2].power_inv_day_total;            
                        for(im=0; im<eeInverterCount; im++) {
                            generation[1].power_day_total += inverter[im].power_inv_day_total;
                        }
                        if (generation[0].power_day_total != generation[1].power_day_total) {
                            generation[0].power_day_total = generation[1].power_day_total;
                            sprintf(str,"%4dKWh     ",generation[1].power_day_total);
                            put_str(5,8,str,1);
                        }
                        break;
                }
            } else if (!dflag && !dcount){
                dflag = 1;
                put_str(5,0, "INV" ,1);	
                generation[0].power_inv_total = 1;
                generation[1].power_inv_total = 0;
                for(im=0; im<eeInverterCount; im++) {
                    generation[1].power_inv_total += inverter[im].power_inv_total;
                }
                if (generation[0].power_inv_total != generation[1].power_inv_total) {
                    generation[0].power_inv_total = generation[1].power_inv_total;
                    if (generation[1].power_inv_total > 999) {
                        sprintf(str,"%5d.%03dMWh",generation[1].power_inv_total/1000,generation[1].power_inv_total%1000);
                    } else {
                        sprintf(str,"    0.%03dMWh",generation[1].power_inv_total%1000);
                    }
                    put_str(5,8,str,1);
                }

                //send_fnd_display();
                
            }
        }
    }


	return;	


#if 0
		  	if (rx_wr_index1 != rx_rd_index1) { 
            rdata1 = getchar1();
            //SOKRST?E	///////////////		   	
            switch(rx_seq1) { 
                case 0:   
                    if (rdata1 == 0x02) {
                        timeout1 = 250;     
                        
                        rcnt1 = 0;           
                        memset(rxbuff1,0,sizeof(rxbuff1));
                        checksum1 = rdata1;
                        rxbuff1[rcnt1++] = rdata1;
                                        
                        rx_seq1 = 200;
                    }
                    break;
                        
                //System Setting /////////////////////////////////////            
                case 200:    
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;       
                        
                    if (rdata1 == 0xa5) {			//RD_DATA
                        rcnt1 = 0;
                        rx_seq1 = 220;
                    } else if (rdata1 == 0xa6) {	//RD_DATA2
                        rcnt1 = 0;
                        rx_seq1 = 240;      
                    } else if (rdata1 == 0xaa) {	//WR_DATA
                        rcnt1 = 0;
                        rx_seq1 = 210;      
                    } else if (rdata1 == 0xab) {	//WR_DATA2
                        rcnt1 = 0;
                        rx_seq1 = 230;    
                    } else if (rdata1 == CHAR_R) {	//SOLAR RADIATION MODULE
                        rx_seq1 = 102;    
                    } else if (rdata1 == CHAR_D) {	//DYENP INVERTER ID SET
                        rcnt1 = 0;
                        rx_seq1 = 90;    
                    } else if (rdata1 == CHAR_A) {	//DYENP INVERTER ID GET
                        rcnt1 = 0;
                        rx_seq1 = 80;    
                    } else if (rdata1 == CHAR_E) {	//DYENP INVERTER ID GET
                        rcnt1 = 0;
                        rx_seq1 = 70;    
                    } else if (rdata1 == CHAR_F) {	//DYENP INVERTER ID GET
                        rcnt1 = 0;
                        rx_seq1 = 60;    
                    } else {
                        rx_seq1 = 0;
                    }
                    break;
                
                case 60:
                    putchar1(variable);
                    rx_seq1++;                        
                    break;     
                
                        
                case 61: 
                    rx_seq1 = 0;                    
                    write_dudr ( 1, 'F');
                    break;
                 //�б� �κ��۾���   
                
                case 70:  	//WR_DYENP INVERVER NO (Serial Number)   
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;  

        sprintf(str,"rxSeq:90 %02d ", rcnt1);
        put_str(0,0,str,1);                
                    if (rcnt1 == 1) {
                        rx_seq1++;
                    }			
                    break;  
                case 71:
                    if (rdata1 == 0x03) {   

                        variable =  rxbuff1[0];

                                   //1234567890
                        sprintf(str,"WILLING OK");
                        put_str(0,0,str,2);        
                        sprintf(str,"          ");
                        put_str(1,0,str,2);    
                        sprintf(str," REBOOTING");
                        put_str(2,0,str,2);    
                        sprintf(str,"          ");
                        put_str(3,0,str,2);    
                        //send_system_parameter();   
                        buzzer_flag |= BUZZER_TIC;   
                        while(1);
                    }
                    rx_seq1 = 0;         
                    break;       
                  
                
                case 80:
                    //rx_seq1++; 
                    for(ic=0;ic<20;ic++) { 
                        putchar1(eeDYENPaddress[ic]);
                        //sprintf(str,"rxSeq:%02d %02d ",ic, rx_seq1);
                        //put_str(0,0,str,1);
                        if (ic == 19) {
                            rx_seq1++; 
                        }
                    }
                    
                    //sprintf(str,"rxSeq:%02d %02d ",ic, rx_seq1);
                    //put_str(0,0,str,1);

                        
                    break;     
                
                        
                case 81: 
                    rx_seq1 = 0;                    
                    write_dudr ( 1, 'A');
                    break;
                 //�б� �κ��۾���   
                    
                case 90:  	//WR_DYENP INVERVER NO (Serial Number)   
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;  

        sprintf(str,"rxSeq:90 %02d ", rcnt1);
        put_str(0,0,str,1);                
                    if (rcnt1 == 20) {
                        rx_seq1++;
                    }			
                    break;  
                case 91:
                    if (rdata1 == 0x03) {   
                        for(ic=0;ic<20;ic++) {
                            eeDYENPaddress[ic] =  rxbuff1[ic];
                        }
                                   //1234567890
                        sprintf(str," DYENP OK!");
                        put_str(0,0,str,2);        
                        sprintf(str,"          ");
                        put_str(1,0,str,2);    
                        sprintf(str," REBOOTING");
                        put_str(2,0,str,2);    
                        sprintf(str,"          ");
                        put_str(3,0,str,2);    
                        //send_system_parameter();   
                        buzzer_flag |= BUZZER_TIC;   
                        while(1);
                    }
                    rx_seq1 = 0;         
                    break;            
                                
                /////////////////////////////////////////    
                case 210:  	//WR_DATA
                    rxbuff1[rcnt1++] = rdata1;
                    if (rcnt1 == 5) {
                        rx_seq1++;
                    }			
                    break;  
        			     
                case 211:  
                    if (rdata1 == 0x03) {
                        rx_seq1++;
                    } else {
                        rx_seq1 = 0;
                    }  
                    break;
                case 212:  
                    if (rdata1 == 0x0d) {   
                        eePortNumber = rxbuff1[0] * 0x100 + rxbuff1[1];
                        eeSendDelay = rxbuff1[2] * 0x100 + rxbuff1[3]; 
                        eeSendDelay *= 1000; 
                        eeInverterCount = rxbuff1[4];
                        sprintf(str,"%04d", eePortNumber);
                        put_str(1,6,str,2);            
            sprintf(str,"%2d", eeInverterCount);
            put_str(7,18,str,1);
                        
                        //send_system_parameter();   
                        buzzer_flag |= BUZZER_TIC;
                    }
                    rx_seq1 = 0;         
                    break;
        			
                case 230:  	//WR_DATA
                    rxbuff1[rcnt1++] = rdata1;
                    if (rcnt1 == 6) {
                        rx_seq1++;
                    }			
                    break;  
        			     
                case 231:  
                    if (rdata1 == 0x03) {
                        rx_seq1++;
                    } else {
                        rx_seq1 = 0;
                    }  
                    break;
                case 232:  
                    if (rdata1 == 0x0d) {   
                        eePortNumber = rxbuff1[0] * 0x100 + rxbuff1[1];
                        eeSendDelay = rxbuff1[2] * 0x100 + rxbuff1[3]; 
                        eeSendDelay *= 1000; 
                        eeInverterCount = rxbuff1[4];
                        eeModelInverter = rxbuff1[5];
                        modelInverter = eeModelInverter;
                        sprintf(str,"%04d", eePortNumber);
                        put_str(1,6,str,2);            
            sprintf(str,"%2d", eeInverterCount);
            put_str(7,18,str,1);
     
                        InverterDisplay(modelInverter);  					                             
                        ClearDisplay();
                        //send_system_parameter();   
                        buzzer_flag |= BUZZER_TIC;
                    }
                    rx_seq1 = 0;         
                    break;
        			
                case 220:  
                    if (rdata1 == 0x03) {
                        rx_seq1++;
                    } else {
                        rx_seq1 = 0;
                    }  
                    break;
                case 221:  
                    if (rdata1 == 0x0d) {
                        send_system_parameter1();   
                        buzzer_flag |= BUZZER_TIC;
                    }
                    rx_seq1 = 0;         
                    break;
        			
                case 240:  
                    if (rdata1 == 0x03) {
                        rx_seq1++;
                    } else {
                        rx_seq1 = 0;
                    }  
                    break;
                case 241:  
                    if (rdata1 == 0x0d) {
                        send_system_parameter2();   
                        buzzer_flag |= BUZZER_TIC;
                    }
                    rx_seq1 = 0;         
                    break;   
                                            
                case 102:                 
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;
                    if (rdata1 == 0x41) {
                        rx_seq1++;            
                    } else {      
                        rx_seq1 = 0;  
                    }
                    break;   
                case 103:   
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;
                    if (rdata1 == 0x44) {
                        rx_seq1++;             
                    } else {      
                        rx_seq1 = 0;  
                    }
                    break;
                case 104:   
                case 105:   
                case 106:  
                    checksum1 ^= rdata1;
                    rxbuff1[rcnt1++] = rdata1;
                    rx_seq1++;
                    break;    
                case 107:  
                    rxbuff1[rcnt1++] = rdata1;
                    rx_seq1++;
                    break;     
                case 108:   
                    if ( (rdata1 == CHAR_ETX) && (checksum1 == rxbuff1[7]) ) {                                                                       
                        adcValue2 = ((unsigned int)rxbuff1[5] * 0x100 + rxbuff1[6]) / 10;
//                        sprintf(str,"T:%+03d,R:%04d,%04d", (signed char)rxbuff1[4] - 20, (unsigned int)rxbuff1[5] * 0x100 + rxbuff1[6], adcValue2); 
//                        put_str(0,0,str,1);       
                    }
                    rx_seq1 = 0;
                    break;
                 
            
                default:
                    rx_seq1 = 0;
                    break;
	            }
			}

#endif
}


//
//
//void rx1Control_radiation(void) {    
//    rdata1 = getchar1();          
//    
//    switch(rx_seq1) {
//    	case 0:   
//       		if (rdata1 == 0x02) {
//            	timeout1 = 2500;     
//				rcnt1 = 0;           
//                memset(rxbuff1,0,sizeof(rxbuff1));
//            	checksum1 = rdata1;
//                rxbuff1[rcnt1++] = rdata1;
//            	rx_seq1++;  
//            }
//        	break;        
//        case 1:                 
//            checksum1 ^= rdata1;
//            rxbuff1[rcnt1++] = rdata1;
//        	if (rdata1 == 0x52) {            
//            	rx_seq1++;  
//            } else {      
//            	rx_seq1 = 0;
//            }
//        	break;   
//        case 2:                 
//sprintf(str,"rx_seq1 : 2 "); 
//put_str(0,0,str,1);     
//            checksum1 ^= rdata1;
//            rxbuff1[rcnt1++] = rdata1;
//        	if (rdata1 == 0x41) {
//            	rx_seq1++;            
//            } else {      
//            	rx_seq1 = 0;  
//            }
//        	break;   
//        case 3:   
//            checksum1 ^= rdata1;
//            rxbuff1[rcnt1++] = rdata1;
//        	if (rdata1 == 0x44) {
//            	rx_seq1++;             
//            } else {      
//            	rx_seq1 = 0;  
//            }
//        	break;
//        case 4:   
//        case 5:   
//        case 6:  
//            checksum1 ^= rdata1;
//            rxbuff1[rcnt1++] = rdata1;
//            rx_seq1++;
//        	break;    
//        case 7:  
//            rxbuff1[rcnt1++] = rdata1;
//            rx_seq1++;
//        	break;     
//        case 8:   
//        	if ( (rdata1 == CHAR_ETX) && (checksum1 == rxbuff1[7]) ) {                                                                       
//                sprintf(str,"T:%+03d'C R:%04dW/m2  ", (signed char)rxbuff1[4] - 20, (unsigned int)rxbuff1[5] * 0x100 + rxbuff1[6]); 
//                put_str(0,0,str,1);                  
//			} else {   
//                sprintf(str,"Error Packet  ",client_mcno[machine_seq],inverter_seq); 
//                put_str(0,0,str,1);                  
//            }
//            rx_seq1 = 0;
//        	break;
//		default:       
//            rx_seq1 = 0;
//        	break;
//    }
//
//}
//
//
void msecControl(void) {
	static ui16 modelInverter = 0;
//    if (pc_delay++ > 100) {
//        pc_delay = 0;   
//    }

    if (dsec) dsec--; 
    if (cur_count) cur_count--;   
    //if (pc_delay) pc_delay--;

	
    ///////// Request Inverter Information to Inverter //////////
//    
	
    if (inv_read_timer) {
        inv_read_timer--;
    }else {  
		    if(invCycleComp == 1){
				invCycleComp = 0; 
	            for(cim=0; cim<20; cim++) {
	                if ((sendInverterCount[cim] > 90) && (oldSendInverterCount[cim] != sendInverterCount[cim])) {
	                    inverter[cim].inverter_status[0] = 0xff;                 
	                    inverter[cim].inverter_status[1] = 0xff;                 
	                    inverter[cim].inverter_status[2] = 0xff;                 
	                    inverter[cim].inverter_status[3] = 0xff;                            

	                    inverter[cim].solar_cell_voltage = 0;                 
	                    inverter[cim].solar_cell_current = 0;                 
	                    inverter[cim].inv_u_voltage = 0;                 
	                    inverter[cim].inv_v_voltage = 0;                 
	                    inverter[cim].inv_w_voltage = 0;                 
	                    inverter[cim].inv_u_current = 0;                 
	                    inverter[cim].inv_v_current = 0;                 
	                    inverter[cim].inv_w_current = 0;                 
	                    inverter[cim].power_solar = 0;                 
	                    inverter[cim].power_inv_now = 0;
	                }
                oldSendInverterCount[cim] = sendInverterCount[cim];
	            }     
		    }
            inv_read_timer = 1000;  //Command Send Interval = 1 Sec     
            
            if (rtuMode == RTU_MODE_LAN) {    
                sprintf(str,"%03d",dsec/1000);
                put_str(2,17,str,1);
            }         
            
            switch(modelInverter) {  
#if (USE_DBG_MODEI == 1)
				case MODEL_INVERTER_SMA2LAN_25K:
					if (invSwitchFlag == 0)
					sendInverterRead_SMA_25kMod();
				break;	
            	case MODEL_INVERTER_DASSTECH3K:		
	                sendInverterRead_DassTech();                                                                         
				break;	
                case MODEL_INVERTER_HYOS36K:			//22
	                 sendInverterRead_HyosungMbus36k(); 
				break; 
				{
#else 

            	case MODEL_INVERTER_DASSTECH3K:			//0
                case MODEL_INVERTER_DASSTECH100K:		//1
                case MODEL_INVERTER_DASSTECH500K:		//2
                    sendInverterRead_DassTech();                                                                           
                    break;    

            	case MODEL_INVERTER_DASSTECH3KN:		//3
                case MODEL_INVERTER_DASSTECH100KN:		//4
                case MODEL_INVERTER_DASSTECH500KN:		//5
                    sendInverterRead_DassTechNew();                                                                           
                    break;    
                                                
                case  MODEL_INVERTER_HEXPOWER3K:		//6
                    sendInverterRead_HexPower3K();                                                                           
                    break;                      
                case  MODEL_INVERTER_HEXPOWER20K:		//7
                    sendInverterRead_HexPower20K();                                                                           
                    break;                      
                case  MODEL_INVERTER_HEXPOWER:			//8
                    sendInverterRead_HexPower();                                                                           
                    break;
                                    
                case  MODEL_INVERTER_HYUNDAI:			//9
                    sendInverterRead_Hyundai();                                                                           
                    break;
                case  MODEL_INVERTER_HYMODBUS:			//10
                    sendInverterRead_HyModbus();                                                                           
                    break;   
                             
				case MODEL_INVERTER_KACO11:				//11
                	sendInverterRead_KACO11();
                    break;    
                case MODEL_INVERTER_KACO20: 			//12    
                    sendInverterRead_KACO20();
                    break;                 
                case MODEL_INVERTER_KACO39: 			//13    
                    sendInverterRead_Kaco39();
                    break;  
                case MODEL_INVERTER_KACO:   
                    sendInverterRead_Kaco();			//14
                    break;                                               
                                                                           
                case MODEL_INVERTER_LSIS03K:			//15
                    sendInverterRead_Lsis03k(); 		
                    break;        
                case MODEL_INVERTER_LSIS20K:			//16
                    sendInverterRead_Refusol(); 		
                    break;
                case  MODEL_INVERTER_LSIS50K:			//17
                    sendInverterRead_Lsis50K();                                                                           
                    break;   
                case  MODEL_INVERTER_LSIS100K:			//18
                    sendInverterRead_Lsis100K();                                                                           
                    break;    
                case MODEL_INVERTER_LSIS500K:
                	sendInverterRead_Ls500k();
                    break;      
                                               
                case MODEL_INVERTER_ABB27K: 			//19    
                    sendInverterRead_Abb27K();
                    break;                        
                case MODEL_INVERTER_ABB33K: 			//20    
                    sendInverterRead_ABB33K();
                    break;  
                case MODEL_INVERTER_ABB_MODBUS: 		//21    
                    sendInverterRead_AbbModbus();
                    break;                 
                                
                case MODEL_INVERTER_HYOS36K:			//22
                    sendInverterRead_HyosungMbus36k(); 
                    break;  
                case MODEL_INVERTER_HYOS:				//23
                    sendInverterRead_HyosungMbus(); 
                    break;          
                    
                case MODEL_INVERTER_REFUSOL:			//24
                    sendInverterRead_Refusol();
                    break;
                           
				case MODEL_INVERTER_SUNGROW3K: 			//25
				case MODEL_INVERTER_SUNGROW30K:			//26
				case MODEL_INVERTER_SUNGROW500K:		//27
                	sendInverterRead_SunGrow3K();
                    break;    
                                               
                case MODEL_INVERTER_WILLINGS1M:			//28 
                    sendInverterRead_Willings1M();
                    break;  
                case MODEL_INVERTER_WILLINGSMBUS_A:		//29
                    sendInverterRead_WillingsMbusA();
                    break;  
                case MODEL_INVERTER_WILLINGSMBUS_B:		//29
                case MODEL_INVERTER_WILLINGSMBUS_B5 :     //61 
                    sendInverterRead_WillingsMbusB();
                    break;  
                    
				case MODEL_INVERTER_EKOS:				//30
                	sendInverterRead_EkosMbus();
                    break;
                case  MODEL_INVERTER_XANTREX:			//31
                    //sendInverterRead_Xantrex();                                                                           
                    break;           
                         
                case MODEL_INVERTER_DIK:				//32
                    sendInverterRead_DIK();
                    break;      
                case  MODEL_INVERTER_DIKMODBUS:			//33
                    sendInverterRead_DikModbus();                                                                           
                    break;    
                    
                                   
                case MODEL_IMVERTER_GIFAM115FI:			//34 
                    sendInverterRead_GIPAM115();
                    break;       
                case MODEL_INVERTER_SANREX:				//35
                    sendInverterRead_SanRex();  
                    break;  
				case MODEL_INVERTER_DYENP:				//36
                	sendInverterRead_DYENP();
                    break;
				case MODEL_INVERTER_WINDREX:			//37
                	sendInverterRead_Windrex3K();
                    break;
				case MODEL_INVERTER_SMA10K:				//38
                	sendInverterRead_SMA10K();
                    break;
				case MODEL_INVERTER_DELTA:				//39
                	sendInverterRead_Delta();
                    break;
				case MODEL_INVERTER_SOLECTRIA: 			//40
                	//sendInverterRead_Solectria();
                    break;
                case MODEL_INVERTER_HANSOL3K: 			//41
                    sendInverterRead_Hansol3k();
                    break;        
                case  MODEL_INVERTER_DONGEIECOS100K:	//42
                    sendInverterRead_DongeiEcos();                                                                           
                    break;                 
                case MODEL_INVERTER_KSTAR60K: 			//45    
                    sendInverterRead_KSTAR50K();
                    break;       
				 case MODEL_INVERTER_DYENPMBUS: 		//46    
                    sendInverterRead_DYENPModbus();
                    break;
                 case MODEL_INVERTER_HYMODBUS1M: 		//47    
                    sendInverterRead_HyModbus1M();
                    break;
                 case MODEL_INVERTER_DYENPMBUS500K: 		//48    
                    sendInverterRead_DYENPModbus500K();
                    break;
                    
                 case  MODEL_INVERTER_HEXPOWER_NEW:			//49
                    sendInverterRead_HexPowerNew();                                                                           
                    break;
                    
                 case MODEL_INVERTER_HANSOL34K: 			//50
                    sendInverterRead_HansolModbus();
                    break;
                 case  MODEL_INVERTER_HYMODBUS50K:			//51
                    sendInverterRead_HyModbus50K();                                                                           
                    break;
                    
                 case MODEL_INVERTER_ABB_MODBUS1M:			//52
                    sendInverterRead_AbbModbus1M();                                                                           
                    break;
                    
                 case MODEL_INVERTER_SUNGROW1250K:          //53
                    sendInverterRead_SunGrow1250K();
                    break;
                    
                 case MODEL_INVERTER_ABB50K:                //54
                    sendInverterRead_ABB50K();
                    break;
                
                case MODEL_INVERTER_DYENPMBUS50K: 		//55    
                    sendInverterRead_DYENPModbus50K();
                    break;                 
                
                case MODEL_INVERTER_SSENG50K:         //56
                    sendInverterRead_KSTAR50K();
                    break;
                    
                case MODEL_INVERTER_HYOS50K:             //57
                    sendInverterRead_HyosungMbus50k();
                    break;
                    
                case MODEL_INVERTER_SINENG36K:             //58
                case MODEL_INVERTER_SINENG50K:             //58
                    sendInverterRead_SINENG36k();
                    break;
                    
                case MODEL_INVERTER_CANADIAN50K:          //59
                    sendInverterRead_Canadian50K();
                    break;
                    
                case MODEL_INVERTER_KEUMBEE34K:            //60
                    sendInverterRead_Keumbee34K();
                    break;
#endif				
				}

                       
                     
            }
        
    }
}

