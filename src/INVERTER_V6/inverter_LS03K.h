void sendInverterRead_Lsis03k(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: RTU Master request frame  
        	//01 03 01 40 00 12 C5 EF => 01 03 24 e0 a6 29 91 00 00 00 00 06 4f 03 cf 0f 1e 09 39 02 a3 01 cb 00 61 02 58 06 2b 06 25 2b a7 0a 26 00 0a 82 9b 40 48 
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0; 
            
//            putchar0(0x03); //Function Code
//            putchar0(0x01); //Modbus Address High
//            putchar0(0x40); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x11); //Data Count Low
//            putchar0(0xC5); //CRC_L
//            putchar0(0xEF); //CRC_H  
            
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x01; //Modbus Address High
            sendBuff[3] = 0x40; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x12; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);

//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-1");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;

        case 10:           
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 11:     //Inv-2: RTU Master request frame  
        	//02 03 01 40 00 12 C5 DC => 
            //putchar0(0x02); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x03); //Function Code
//            putchar0(0x01); //Modbus Address High
//            putchar0(0x40); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x12); //Data Count Low
//            putchar0(0xc5); //CRC_L
//            putchar0(0xDC); //CRC_H 
            
            
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x01; //Modbus Address High
            sendBuff[3] = 0x40; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x12; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;     

        case 20:           
        	if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 21:     //Inv-3: RTU Master request frame  
        	//03 03 01 40 00 12 C4 0D => 
            //putchar0(0x03); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x03); //Function Code
//            putchar0(0x01); //Modbus Address High
//            putchar0(0x40); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x12); //Data Count Low
//            putchar0(0xc4); //CRC_L
//            putchar0(0x0d); //CRC_H 
            
            
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x01; //Modbus Address High
            sendBuff[3] = 0x40; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x12; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            sprintf(str,"TX-3");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     

        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_Lsis03k(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata > 0x00) && (rxdata < 0x04)) {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            }
			break;        
        case 1: //Device (Slave) 
            if (rxdata == 0x03) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            if (rxdata == 0x24) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 38) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,36+3);   
                rxCrc = rxbuff[40];
                rxCrc <<= 8;
                rxCrc += rxbuff[39];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[11],rxbuff[12]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[13],rxbuff[14]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[29],rxbuff[30]); 
                	inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[17],rxbuff[18]); 
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[17],rxbuff[18]); 
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[17],rxbuff[18]);
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                	inverter[invNo].power_inv_now         = Bytes_to_Uint(rxbuff[29],rxbuff[30]);  
                    inverter[invNo].power_inv_pf        = 955;
                    inverter[invNo].inv_frequency       = 600;
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[31],rxbuff[32]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[35],rxbuff[36]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[37],rxbuff[38]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[9],rxbuff[10]);             
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 100;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 100;
                	inverter[invNo].inv_v_current      /= 100;
                	inverter[invNo].inv_w_current      /= 100;   
                    inverter[invNo].power_solar        /= 10;
                	inverter[invNo].power_inv_now      /= 10;  
                	inverter[invNo].power_inv_day_total /= 1000;
					inverter[invNo].power_inv_total /= 1000;

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX-%01d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;


//	                sprintf(str,"PS%01d:%05d ",invNo+1,inverter[invNo].power_solar);
//    	            put_str(1,0,str,1);   
                }
            	rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
