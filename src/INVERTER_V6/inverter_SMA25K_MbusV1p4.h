unsigned char dCrcSum, dCalSum;
unsigned char bLen;

//H : 0000 0000 0006 0304 7743 000A  -└┘    6 772 30531 
//H : 0000 0000 0006 0304 7831 0046
//H : 0000 0000 0006 0304 78ED 000A
//H : 0000 0000 0006 0304 9C5D 000A 
//H : 0000 0000 0006 0304 762B 000A 
#define SQRT3 1.73205080756887729352

//char sendcmd[5][12] = {
//						 {0,0,0,0,0,0x06,0x03,0x04,0x77,0x43,0x00,0x0a},
//						 {0,0,0,0,0,0x06,0x03,0x04,0x78,0x31,0x00,0x46},
//						 {0,0,0,0,0,0x06,0x03,0x04,0x78,0xed,0x00,0x0a},
//						 {0,0,0,0,0,0x06,0x03,0x04,0x9C,0x5d,0x00,0x0a},
//						 {0,0,0,0,0,0x06,0x03,0x04,0x76,0x2B,0x00,0x0a}
//					   };

//	flash char sendcmd1[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x77,0x43,0x00,0x0a};
//	flash char sendcmd2[12] =	{0,0,0,0,0,0x06,0x03,0x04,0x78,0x31,0x00,0x46};
//	flash char sendcmd3[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x78,0xed,0x00,0x0a};
//	flash char sendcmd4[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x9C,0x5d,0x00,0x0a};
//	flash char sendcmd5[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x76,0x2B,0x00,0x0a};

const char sendcmd1[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x77,0x43,0x00,0x0a};
const char sendcmd2[12] =	{0,0,0,0,0,0x06,0x03,0x04,0x78,0x31,0x00,0x46};
const char sendcmd3[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x78,0xed,0x00,0x0a};
const char sendcmd4[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x9C,0x5d,0x00,0x0a};
const char sendcmd5[12] =  {0,0,0,0,0,0x06,0x03,0x04,0x76,0x2B,0x00,0x0a};

//  00000 23 03 04 20 



char msgType;
extern char commCompliteCnt;


void sendInverterRead_SMA_25kMod(void) {
	int i;
	static uc08 cmdCycleCompFlag =0;
	static uc08 siSqc = 0; 
    switch(siSqc) {
        case 0:
			cmdCycleCompFlag = 0;
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
//				commCompliteCnt = 0;

			siSqc++;
            break;     
        case 1:     //Inv-1: ^P001MOD
	        msgType = 0;
			for(i=1;i<12;i++)
			{
				putchar3 (sendcmd1[i]);
			}	
			write_dudr (W107_PORT, sendcmd1[0]);
            siSqc++;
            break;         
        case 2:     //Inv-1: ^P001ST2 
	        msgType = 1;
			for(i=1;i<12;i++)
			{
				putchar3 (sendcmd2[i]);
			}	
			write_dudr (W107_PORT, sendcmd2[0]);
            siSqc++;
            break;         
        case 3:     //Inv-1: ^P001ST3  
			msgType = 2;
			for(i=1;i<12;i++)
			{
				putchar3 (sendcmd3[i]);
			}	
			write_dudr (W107_PORT, sendcmd3[0]);
            siSqc++;
            break;         
        case 4:     //Inv-1: ^P001ST4  
			msgType = 3;		
			for(i=1;i<12;i++)
			{
				putchar3 (sendcmd4[i]);
			}	
			write_dudr (W107_PORT, sendcmd4[0]);
            siSqc++;
            break;         
        case 5:     //Inv-1: ^P001ST6    
			msgType = 4;		
			for(i=1;i<12;i++)
			{
				putchar3 (sendcmd5[i]);
			}	
			write_dudr (W107_PORT, sendcmd5[0]);
            siSqc++;
            break;
		case 6:
			siSqc++;
			cmdCycleCompFlag = 1;
			if(invCycleComp < 100)		
			invCycleComp++;
			invSwitchFlag = 1;
			break;
		case 7:
			siSqc = 0;
			msgType = 0;
			break;
        ///////////////////////////////              
        case 150:
            siSqc = 0;
            break;
        default:  
            siSqc = 0;
            break;
    }
}

//H : 0000 0000 0006 0304 7743 000A  -└┘    6 772 30531 
//H : 0000 0000 0006 0304 7831 0046
//H : 0000 0000 0006 0304 78ED 000A
//H : 0000 0000 0006 0304 9C5D 000A 
//H : 0000 0000 0006 0304 762B 000A 
typedef union
{
	char arr[4];
	unsigned short us_data[2];
	short ss_data[2];
	long l_data;
}a_t;


long ld4_copy( char* currData )
{
	a_t ret_data ;
	char * ptr = currData;
	ret_data.arr[0] = *ptr++;
	ret_data.arr[1] = *ptr++;
	return ret_data.l_data;
		
}

int id2_copy( char* currData )
{
	a_t ret_data ;
	char * ptr = currData;
	ret_data.arr[0] = *ptr++;
	ret_data.arr[1] = *ptr;
	return ret_data.ss_data[0];
		
}

void ini_iverterbuff_val(char invNum);


char commCompliteCnt = 0;
uc08 rx3_recevcmd_len = 0;
char rx3_recevcmd_idx = 0;
//char rx3_rece_sqc = 0;
uc08 reactionLeng[5]= {24,80,20,12,12};
extern char db_reaction_buf[] ;
extern char wiz_cmd_buf[];

extern uc08 wiz_cmd_len;



char  cmdPasingFromW107(void)
	{
		char data , dtBuf  ;
		static char  dataCorectCnt = 5;
		char cmdbuf[64] = {0} ;
		static int rs_dltimer ; 


		if(wiz_cmd_len < reactionLeng[msgType]) return 0x8 ; // CMD_CONT;

		memset(rxbuff,0,sizeof(rxbuff));
		strncpy(rxbuff,wiz_cmd_buf,wiz_cmd_len);

		// if data not CORRECT  return CMD_ERROR
			
		switch(msgType)
		{
		case 0:   // msg case 1 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				inverter[20].power_inv_total = ld4_copy (&rxbuff[9]);
				inverter[20].power_inv_day_total = ld4_copy (&rxbuff[21]);
				dataCorectCnt = 4;
			}
			break;
		case 1:   // msg case 2 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				ABbuferinverter[0].solar_cell_current = ld4_copy (&rxbuff[9]);

				ABbuferinverter[0].solar_cell_voltage = ld4_copy (&rxbuff[13]);
		
				ABbuferinverter[0].power_solar = ld4_copy (&rxbuff[17]);

				inverter[20].power_inv_now = ld4_copy (&rxbuff[21]);
				
				inverter[20].inv_u_voltage = (ui16)((id2_copy (&rxbuff[39])) == 0xffff ? 0 : (id2_copy(&rxbuff[39]) * (float)SQRT3));
				inverter[20].inv_v_voltage = (ui16)((id2_copy (&rxbuff[43])) == 0xffff ? 0 : (id2_copy(&rxbuff[43]) * (float)SQRT3)); 
				inverter[20].inv_w_voltage =  (ui16)((id2_copy (&rxbuff[47])) == 0xffff ? 0 : (id2_copy(&rxbuff[47]) * (float)SQRT3));

				inverter[20].inv_u_current = (ui16)((ld4_copy (&rxbuff[61])) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]));
	//			inverter[21].inv_v_current =  ld4_copy (&rxbuff[61]) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]);
				inverter[20].inv_v_current = inverter[imInvNo].inv_u_current ;
	//			inverter[21].inv_w_current =  ld4_copy (&rxbuff[61]) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]);
				inverter[20].inv_w_current = inverter[imInvNo].inv_u_current ;

				if(inverter[20].power_inv_now == 2123)	inverter[imInvNo].power_inv_now = 0;
				inverter[20].inv_frequency = ld4_copy (&rxbuff[77]) >= 0xffff ? 0 :  ld4_copy (&rxbuff[77]); 
			}
			break;
		case 2:    // msg case 3 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				ABbuferinverter[1].solar_cell_current = ld4_copy (&rxbuff[9]);
				ABbuferinverter[1].solar_cell_voltage = ld4_copy (&rxbuff[13]);
				ABbuferinverter[1].power_solar = ld4_copy (&rxbuff[17]);

				inverter[20].solar_cell_current = 
					ABbuferinverter[0].solar_cell_current + ABbuferinverter[1].solar_cell_current;
				inverter[20].solar_cell_voltage = 
					(ABbuferinverter[0].solar_cell_voltage + ABbuferinverter[1].solar_cell_voltage) / 2;
				inverter[20].power_solar = 
					ABbuferinverter[0].power_solar + ABbuferinverter[1].power_solar;

				inverter[20].power_inv_total = id2_copy (&rxbuff[39]) ;
			}
			break;
		case 3:    // msg case 4
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				inverter[20].inverter_status[0] = id2_copy (&rxbuff[9]);
				inverter[20].inverter_status[1] = id2_copy (&rxbuff[11]);
			}
			break;
		case 4:    // msg case 5
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				inverter[20].inverter_status[2] = id2_copy (&rxbuff[9]);
				inverter[20].inverter_status[3] = id2_copy (&rxbuff[11]);
			}
			dataCorectCnt--;
			break; 
		}

		commCompliteCnt = 1;
		if(dataCorectCnt == 0 ) 
		{
			inverter[imInvNo] = inverter[20];	
			dataCorectCnt = 5;
			//ini_iverterbuff_val(20);
			sprintf(cmdbuf,"3<etc....comp.");
			//my_put_string (1, cmdbuf);
		}

		return 0;
		
	}

void  rX3Control_SMA25K_mod_old(void)
	{
#if 0	
		char data , dtBuf  ;
		static char  dataCorectCnt;
		char cmdbuf[0xff] = {0} ;
		static int rs_dltimer ; 
		
		switch(rx_seq3)
		{
		case 0:
			 rx3_recevcmd_len = 0;
			 rx3_recevcmd_idx = 0;
			 rx_seq3++;
			 rcnt = 0;
			 dataCorectCnt = 5;
			 memset(rxbuff,0,sizeof(rxbuff));
			 timeout3 = 250;
			 rs_dltimer = hs_state_delay_set();
			break;
		case 1:
			if(rx_wr_index3 != rx_rd_index3) { rx_seq3++; break;}
			if( hs_state_delay_rmnd (rs_dltimer, 250) ) break;
			rx_seq3 = 0;
			commCompliteCnt = 2;  // timeout 
			break;
		case 2:
			rx_seq3++;
			break;
		case 3:	
			if(rx_wr_index3 != rx_rd_index3)
			{
				rs_dltimer = hs_state_delay_set();	
				//flagCommSendBusy = USARTREACTIONDELAY;
				data = getchar3 ();

				if(rx3_recevcmd_len >= 0xff)	
					rx3_recevcmd_len = 0xff;
				rxbuff[rx3_recevcmd_len++] = data;
				rx3_recevcmd_len++;
				if(rx3_recevcmd_len >= reactionLeng[msgType])
				{
					if(swUsart4dbgshow & bv(USARTDBGSWHOW_IN3))
					{
						 sprintf(cmdbuf,"3<");
						 my_put_string (DBG_PORT, cmdbuf);
						 strncpy(cmdbuf,rxbuff,rx3_recevcmd_len);
						 my_Nput_string (DBG_PORT, cmdbuf, rx3_recevcmd_len);
					}
					rx_seq3++;
					break;
				}
			}
			break;
		case 4:    // check correct 
			if(wizInfo.rmWiz_state[imInvNo] & bv(DEVON))
			rx_seq3 += (msgType + 1) ;
			else rx_seq3 =  20;	
			break;
		case 5:   // msg case 1 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				inverter[20].power_inv_total = ld4_copy (&rxbuff[9]);
				inverter[20].power_inv_day_total = ld4_copy (&rxbuff[21]);
				dataCorectCnt--;
			}
			rx_seq3 = 0;
			break;
		case 6:   // msg case 2 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				ABbuferinverter[0].solar_cell_current = ld4_copy (&rxbuff[9]);

				ABbuferinverter[0].solar_cell_voltage = ld4_copy (&rxbuff[13]);
		
				ABbuferinverter[0].power_solar = ld4_copy (&rxbuff[17]);

				inverter[20].power_inv_now = ld4_copy (&rxbuff[21]);
				
				inverter[20].inv_u_voltage = (ui16)((id2_copy (&rxbuff[39])) == 0xffff ? 0 : (id2_copy(&rxbuff[39]) * (float)SQRT3));
				inverter[20].inv_v_voltage = (ui16)((id2_copy (&rxbuff[43])) == 0xffff ? 0 : (id2_copy(&rxbuff[43]) * (float)SQRT3)); 
				inverter[20].inv_w_voltage =  (ui16)((id2_copy (&rxbuff[47])) == 0xffff ? 0 : (id2_copy(&rxbuff[47]) * (float)SQRT3));

				inverter[20].inv_u_current = (ui16)((ld4_copy (&rxbuff[61])) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]));
	//			inverter[21].inv_v_current =  ld4_copy (&rxbuff[61]) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]);
				inverter[20].inv_v_current = inverter[imInvNo].inv_u_current ;
	//			inverter[21].inv_w_current =  ld4_copy (&rxbuff[61]) >=  0xffff ? 0 : ld4_copy (&rxbuff[61]);
				inverter[20].inv_w_current = inverter[imInvNo].inv_u_current ;

				if(inverter[20].power_inv_now == 2123)	inverter[imInvNo].power_inv_now = 0;
				inverter[20].inv_frequency = ld4_copy (&rxbuff[77]) >= 0xffff ? 0 :  ld4_copy (&rxbuff[77]); 
			}
			rx_seq3 = 0;
			break;
		case 7:    // msg case 3 
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				ABbuferinverter[1].solar_cell_current = ld4_copy (&rxbuff[9]);
				ABbuferinverter[1].solar_cell_voltage = ld4_copy (&rxbuff[13]);
				ABbuferinverter[1].power_solar = ld4_copy (&rxbuff[17]);

				inverter[20].solar_cell_current = 
					ABbuferinverter[0].solar_cell_current + ABbuferinverter[1].solar_cell_current;
				inverter[20].solar_cell_voltage = 
					(ABbuferinverter[0].solar_cell_voltage + ABbuferinverter[1].solar_cell_voltage) / 2;
				inverter[20].power_solar = 
					ABbuferinverter[0].power_solar + ABbuferinverter[1].power_solar;

				inverter[20].power_inv_total = id2_copy (&rxbuff[39]) ;
			}
			rx_seq3 = 0;
			break;
		case 8:    // msg case 4
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				inverter[20].inverter_status[0] = id2_copy (&rxbuff[9]);
				inverter[20].inverter_status[1] = id2_copy (&rxbuff[11]);
			}
			rx_seq3 = 0;
			break;
		case 9:    // msg case 5
			if(wizInfo.rmWiz_state[imInvNo] & bv (NOWTOKEN) ) 
			{
				dataCorectCnt--;
				inverter[20].inverter_status[2] = id2_copy (&rxbuff[9]);
				inverter[20].inverter_status[3] = id2_copy (&rxbuff[11]);
			}
			if(dataCorectCnt != 0)
			rx_seq3 = 11;
			else rx_seq3 = 10;
			break; 
		case 10:    // save 
			inverter[imInvNo] = inverter[20];
			rx_seq3++;	
			break;
		case 11:
			ini_iverterbuff_val(20);    // buf 
			dataCorectCnt = 5;
			if(dbgLevel > 0)
			{
				if(swUsart4dbgshow & bv(USARTDBGSWHOW_IN3))
				{
					sprintf(db_reaction_buf,"3<etc....comp.");
					my_put_string (1, db_reaction_buf);
				}
			}
			commCompliteCnt = 1;
			rx_seq3 = 0;
			break;
		case 20:   // data => nul 
			rx_seq3 = 0;
			break;
		default:
			rx_seq3 = 0;
			break;
		}
#else
#endif		
	}
//--------------------------------------

void ini_iverterbuff_val(char invNum)
{
	inverter[invNum].inverter_status[0] = 0xff;				 
	inverter[invNum].inverter_status[1] = 0xff;				 
	inverter[invNum].inverter_status[2] = 0xff;				 
	inverter[invNum].inverter_status[3] = 0xff;							
	
	inverter[invNum].solar_cell_voltage = 0;				  
	inverter[invNum].solar_cell_current = 0;				  
	inverter[invNum].inv_u_voltage = 0;				 
	inverter[invNum].inv_v_voltage = 0;				 
	inverter[invNum].inv_w_voltage = 0;				 
	inverter[invNum].inv_u_current = 0;				 
	inverter[invNum].inv_v_current = 0;				 
	inverter[invNum].inv_w_current = 0;				 
	inverter[invNum].power_solar = 0;				   
	inverter[invNum].power_inv_now = 0;
}

