
void sendInverterRead_HexPower3K(void) {
    char sendBuff[16];      
    char strBuff[10];
    unsigned int cSum;
     

    switch(inverter_seq) {
        case 0:
			if (sendInverterCount[invNo-1] < 100) {
            	sendInverterCount[invNo-1]++;
            }     
            invNo++;
            if (invNo > eeInverterCount) {
                invNo = 1;
            }              

            sprintf(str,"TX%02d",invNo);
            put_str(4,16,str,1);    
            rx_led_delay = 5000;             
            inverter_seq++;
            break;     

        case 1:     //Fault Infomation
			sendBuff[0] = 0x05;	//STX(ENQ)
            if (invNo > 15) {
				sendBuff[1] = 0x31;
            	sendBuff[2] = 0x30 + invNo - 16;
        	} else {
				sendBuff[1] = 0x30;
            	sendBuff[2] = 0x30 + invNo;
            }
            sendBuff[3] = 0x52; //CMD
            sendBuff[4] = 0x30; //Addr-3
            sendBuff[5] = 0x30; //Addr-2
            sendBuff[6] = 0x30; //Addr-1
            sendBuff[7] = 0x34; //Addr-0
            sendBuff[8] = 0x30; //Cnt-1
            sendBuff[9] = 0x34; //Cnt-0
            cSum = sendBuff[1] + sendBuff[2] + sendBuff[3] + sendBuff[4] + sendBuff[5] + sendBuff[6] + sendBuff[7] + sendBuff[8] + sendBuff[9];     
			sprintf(strBuff,"%04x",cSum);
            sendBuff[10] = strBuff[0];	//CK_SUM-3
            sendBuff[11] = strBuff[1];	//CK_SUM-2
            sendBuff[12] = strBuff[2];	//CK_SUM-1
            sendBuff[13] = strBuff[3];	//CK_SUM-0
            sendBuff[14] = 0x04; //EOT
                        
            //putchar0(sendBuff[0]);
            putchar0(sendBuff[1]);
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(sendBuff[5]);
            putchar0(sendBuff[6]);
            putchar0(sendBuff[7]);
            putchar0(sendBuff[8]);
            putchar0(sendBuff[9]);
            putchar0(sendBuff[10]);
            putchar0(sendBuff[11]);
            putchar0(sendBuff[12]);
            putchar0(sendBuff[13]);
            putchar0(sendBuff[14]);
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif  
            inverter_seq++;
            break;         
        case 2:     //Solar Cell Voltage / current
			sendBuff[0] = 0x05;	//STX(ENQ)
            if (invNo > 15) {
				sendBuff[1] = 0x31;
            	sendBuff[2] = 0x30 + invNo - 16;
        	} else {
				sendBuff[1] = 0x30;
            	sendBuff[2] = 0x30 + invNo;
            }
            sendBuff[3] = 0x52; //CMD

            sendBuff[4] = 0x30; //Addr-3
            sendBuff[5] = 0x30; //Addr-2
            sendBuff[6] = 0x32; //Addr-1
            sendBuff[7] = 0x30; //Addr-0
            sendBuff[8] = 0x30; //Cnt-1
            sendBuff[9] = 0x32; //Cnt-0
            cSum = sendBuff[1] + sendBuff[2] + sendBuff[3] + sendBuff[4] + sendBuff[5] + sendBuff[6] + sendBuff[7] + sendBuff[8] + sendBuff[9];     
			sprintf(strBuff,"%04x",cSum);
            sendBuff[10] = strBuff[0];	//CK_SUM-3
            sendBuff[11] = strBuff[1];	//CK_SUM-2
            sendBuff[12] = strBuff[2];	//CK_SUM-1
            sendBuff[13] = strBuff[3];	//CK_SUM-0
            sendBuff[14] = 0x04; //EOT
                        
            //putchar0(sendBuff[0]);
            putchar0(sendBuff[1]);
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(sendBuff[5]);
            putchar0(sendBuff[6]);
            putchar0(sendBuff[7]);
            putchar0(sendBuff[8]);
            putchar0(sendBuff[9]);
            putchar0(sendBuff[10]);
            putchar0(sendBuff[11]);
            putchar0(sendBuff[12]);
            putchar0(sendBuff[13]);
            putchar0(sendBuff[14]);
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif  
            inverter_seq++;
            break;         
        case 3:     //Inv-1:Utility Line voltage / current /frequency
			sendBuff[0] = 0x05;	//STX(ENQ)
            if (invNo > 15) {
				sendBuff[1] = 0x31;
            	sendBuff[2] = 0x30 + invNo - 16;
        	} else {
				sendBuff[1] = 0x30;
            	sendBuff[2] = 0x30 + invNo;
            }
            sendBuff[3] = 0x52; //CMD

            sendBuff[4] = 0x30; //Addr-3
            sendBuff[5] = 0x30; //Addr-2
            sendBuff[6] = 0x35; //Addr-1
            sendBuff[7] = 0x30; //Addr-0
            sendBuff[8] = 0x30; //Cnt-1
            sendBuff[9] = 0x37; //Cnt-0
            cSum = sendBuff[1] + sendBuff[2] + sendBuff[3] + sendBuff[4] + sendBuff[5] + sendBuff[6] + sendBuff[7] + sendBuff[8] + sendBuff[9];     
			sprintf(strBuff,"%04x",cSum);
            sendBuff[10] = strBuff[0];	//CK_SUM-3
            sendBuff[11] = strBuff[1];	//CK_SUM-2
            sendBuff[12] = strBuff[2];	//CK_SUM-1
            sendBuff[13] = strBuff[3];	//CK_SUM-0
            sendBuff[14] = 0x04; //EOT
                        
            //putchar0(sendBuff[0]);
            putchar0(sendBuff[1]);
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(sendBuff[5]);
            putchar0(sendBuff[6]);
            putchar0(sendBuff[7]);
            putchar0(sendBuff[8]);
            putchar0(sendBuff[9]);
            putchar0(sendBuff[10]);
            putchar0(sendBuff[11]);
            putchar0(sendBuff[12]);
            putchar0(sendBuff[13]);
            putchar0(sendBuff[14]);
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif  
            inverter_seq++;
            break;         
        case 4:     //Inv-1:Solar and INV power
			sendBuff[0] = 0x05;	//STX(ENQ)
            if (invNo > 15) {
				sendBuff[1] = 0x31;
            	sendBuff[2] = 0x30 + invNo - 16;
        	} else {
				sendBuff[1] = 0x30;
            	sendBuff[2] = 0x30 + invNo;
            }
            sendBuff[3] = 0x52; //CMD

            sendBuff[4] = 0x30; //Addr-3
            sendBuff[5] = 0x30; //Addr-2
            sendBuff[6] = 0x36; //Addr-1
            sendBuff[7] = 0x30; //Addr-0
            sendBuff[8] = 0x30; //Cnt-1
            sendBuff[9] = 0x38; //Cnt-0
            cSum = sendBuff[1] + sendBuff[2] + sendBuff[3] + sendBuff[4] + sendBuff[5] + sendBuff[6] + sendBuff[7] + sendBuff[8] + sendBuff[9];     
			sprintf(strBuff,"%04x",cSum);
            sendBuff[10] = strBuff[0];	//CK_SUM-3
            sendBuff[11] = strBuff[1];	//CK_SUM-2
            sendBuff[12] = strBuff[2];	//CK_SUM-1
            sendBuff[13] = strBuff[3];	//CK_SUM-0
            sendBuff[14] = 0x04; //EOT
                        
            //putchar0(sendBuff[0]);
            putchar0(sendBuff[1]);
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(sendBuff[5]);
            putchar0(sendBuff[6]);
            putchar0(sendBuff[7]);
            putchar0(sendBuff[8]);
            putchar0(sendBuff[9]);
            putchar0(sendBuff[10]);
            putchar0(sendBuff[11]);
            putchar0(sendBuff[12]);
            putchar0(sendBuff[13]);
            putchar0(sendBuff[14]);
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif  
            inverter_seq++;
            break;         

		case 5:              
		case 6:              
		case 7:              
		case 8:              
            inverter_seq++;
            break;         
		case 9:              
            inverter_seq = 0;
            break;         

        default:  
            inverter_seq = 0;
            break;
    }
}





void rx0Control_HexPower3K(void) {   
	char rxdata;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == ENQ) {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                timeout0 = 250;
            	rx_seq0++;
            } else if (rxdata == 0x02) {  
//				rcnt = 0;
//				rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
				rx_seq0 = 100;
			}   
			break;        
        case 1:                      
        	//rcnt = 0;
			rxbuff[rcnt++] = rxdata;
        	if ((rxdata == 0x30) || (rxdata == 0x31))  {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;
        case 2:
        	//rcnt = 1;
			rxbuff[rcnt++] = rxdata;
            rx_seq0++;
            break;      
        case 3:
        	//rcnt = 2;
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x52) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 4:
        	//rcnt = 3;	//Address-3
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x30) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;       
        case 5:
        	//rcnt = 4;	//Address-2
			rxbuff[rcnt++] = rxdata;
            rx_seq0++;       
            break;         
        case 6:
        	//rcnt = 5;	//Address-1
			rxbuff[rcnt++] = rxdata;
            rx_seq0++;       
            break;                 
        case 7:
        	//rcnt = 6;	//Address-0
			rxbuff[rcnt++] = rxdata;   
            inverter_address = HexStr_to_Uint(rxbuff[3], rxbuff[4], rxbuff[5], rxbuff[6]);            
                                   
            switch(inverter_address) {
				//Fault Information  
                case 0x0004: 
		            rx_seq0 = 10;       
                	break;   
                //Solar Cell voltage/current
                case 0x0020:
		            rx_seq0 = 20;       
                	break;  
                //Utility Line voltage / current / frequency
                case 0x0050:
		            rx_seq0 = 50;       
                	break; 
                //Solar and INV power / pf
                case 0x0060:
		            rx_seq0 = 60;       
                	break;  
            	default:        
		            rx_seq0 = 0;;       
                	break;;
            }
            break;             
		//HexPowerInverter : Fault Information            
        case 10:  
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=22;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                if (chksum0 == rchksum0) {
                	imInvNo = HexStr_to_Uint(0x30,0x30,rxbuff[0],rxbuff[1]);
                
					inverter[imInvNo-1].inverter_status[0] = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
					inverter[imInvNo-1].inverter_status[1] = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);            
					inverter[imInvNo-1].inverter_status[2] = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);            
					inverter[imInvNo-1].inverter_status[3] = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);            
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;
		//HexPowerInverter : Solar Cell voltage/current (8byte)            
        case 20:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=14;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);
                if (chksum0 == rchksum0) {
                	imInvNo = HexStr_to_Uint(0x30,0x30,rxbuff[0],rxbuff[1]);

                	inverter[imInvNo-1].solar_cell_voltage = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
					inverter[imInvNo-1].solar_cell_current = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);            
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;
		//HexPowerInverter : Utility Line voltage / current / frequency (28byte)            
        case 50:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=34;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38]);
                if (chksum0 == rchksum0) {
                	imInvNo = HexStr_to_Uint(0x30,0x30,rxbuff[0],rxbuff[1]);

                	inverter[imInvNo-1].inv_u_voltage = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]); 
                	inverter[imInvNo-1].inv_v_voltage = 0; 
                	inverter[imInvNo-1].inv_w_voltage = 0;
                	inverter[imInvNo-1].inv_u_current  = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
                	inverter[imInvNo-1].inv_v_current  = 0;
                	inverter[imInvNo-1].inv_w_current  = 0;
                    inverter[imInvNo-1].inv_frequency  = HexStr_to_Uint(rxbuff[31],rxbuff[32],rxbuff[33],rxbuff[34]); 
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;		
		//HexPowerInverter : Solar and INV power / pf (32byte)            
        case 60:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=38;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[39],rxbuff[40],rxbuff[41],rxbuff[42]);
                if (chksum0 == rchksum0) {
                	imInvNo = HexStr_to_Uint(0x30,0x30,rxbuff[0],rxbuff[1]);

                	inverter[imInvNo-1].power_solar         = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]); 
                	inverter[imInvNo-1].power_inv_total     = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);
                    inverter[imInvNo-1].power_inv_total   <<= 16; 
                	inverter[imInvNo-1].power_inv_total    += HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);
                	inverter[imInvNo-1].power_inv_now       = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
                	//inverter[rxbuff[1]-0x31].power_inv_max       = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                	inverter[imInvNo-1].power_inv_day_total = HexStr_to_Uint(rxbuff[27],rxbuff[28],rxbuff[29],rxbuff[30]);
                    inverter[imInvNo-1].power_inv_pf        = HexStr_to_Uint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38]);

	                sendInverterCount[0] = 0;
					buzzer_flag |= BUZZER_TIC;

	                sprintf(str,"RX%02d",imInvNo);
    	            put_str(4,16,str,1);   
                    //put_str(4,16,C_RXOK,1);   
					rx_led_delay = 2500;
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;
            
		//System Setting /////////////////////////////////////            
		case 100:               
            rcnt = 0;
            if (rxdata == 0xa5) {			//RD_DATA
                rx_seq0 = 120;
            } else if (rxdata == 0xaa) {	//WR_DATA
				rcnt = 0;
                rx_seq0 = 110;      
            } else {
                rx_seq0 = 0;
            }
			break;
		case 110:  	//WR_DATA
			rxbuff[rcnt++] = rxdata;
			if (rcnt == 5) {
				rx_seq0++;
			}			
			break;  
			     
		case 111:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 112:  
			if (rxdata == 0x0d) {   
				eePortNumber = rxbuff[0] * 0x100 + rxbuff[1];
				eeSendDelay = rxbuff[2] * 0x100 + rxbuff[3];  
                eeSendDelay *= 1000; 
                eeInverterCount = rxbuff[4];
			    sprintf(str,"%04d", eePortNumber);
				put_str(1,6,str,2);    
    sprintf(str,"%01X", eeInverterCount);
    put_str(7,18,str,1);    
            	//send_system_parameter();   
				buzzer_flag |= BUZZER_TIC;
			}
			rx_seq0 = 0;         
			break;
			
			
		case 120:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 121:  
			if (rxdata == 0x0d) {
            	send_system_parameter();   
				buzzer_flag |= BUZZER_TIC;
			}
			rx_seq0 = 0;         
			break;
		default:
			rx_seq0 = 0;
			break;
	}
}
