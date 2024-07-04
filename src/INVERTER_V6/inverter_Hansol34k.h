
void sendInverterRead_HansolModbus(void) {
    unsigned int retVal;
    char sendBuff[10];
	//int count = 1; inverter_address

    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;                                            
        case 1:     //Inv-1: RTU Master request frame  
        	//01 03 02 BB 00 1D F4 5E => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0;    

			inverter_address = 1;
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
//          Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = 0x00; //Modbus Address High
            sendBuff[3] = 0x00; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1B; //Data Count Low (27)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);
	
//    		sprintf(str,"CRC:%04X ",retVal);
//          put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX%02d",1);
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
        case 10:
        case 11:
        case 12:
        case 13:
        case 14: 
        	inverter_seq++;
            break;
        case 15:           
		
			inverter_address++;
			
        	if (eeInverterCount >= inverter_address) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 16:     //Inv-2: RTU Master request frame  
        	//02 03 02 BB 00 1D F4 6D => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0;       
            
			sendBuff[0] = inverter_address;	//Slave Number
			sendBuff[1] = 0x04;	//Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = 0x00; //Modbus Address High
            sendBuff[3] = 0x00; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1B; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low          
		    putchar0(retVal % 0x100);
    		putchar0(retVal / 0x100);
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif  
            sprintf(str,"TX%02d",inverter_address);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
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
        case 30:
            inverter_seq = 15;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_HansolModbus(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if (rxdata < 30){
				rcnt = 0;                
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            } 
			break;        
        case 1: //Device (Slave) 
            if (rxdata == 0x04) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
//            if (rxdata == 0x3a) {   
            if (rxdata == 0x36) {   
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

            if (dcnt == 56) {

				calCrc = calcCRC(rxbuff,58+3);   
                rxCrc = rxbuff[62];
                rxCrc <<= 8;
                rxCrc += rxbuff[61]; 

                    invNo = rxbuff[0] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[7],rxbuff[8])/10; //+ Bytes_to_Uint(rxbuff[9],rxbuff[10]);
					inverter[invNo].solar_cell_current  = (Bytes_to_Uint(rxbuff[11],rxbuff[12]) + Bytes_to_Uint(rxbuff[13],rxbuff[14]))/10;            
                	inverter[invNo].power_solar         = (Bytes_to_Uint(rxbuff[15],rxbuff[16]) + Bytes_to_Uint(rxbuff[17],rxbuff[18]))/100;
					
                	inverter[invNo].inv_u_voltage      = Bytes_to_Uint(rxbuff[33],rxbuff[34])/10;					
                	inverter[invNo].inv_v_voltage      = Bytes_to_Uint(rxbuff[37],rxbuff[38])/10; 
                	inverter[invNo].inv_w_voltage	   = Bytes_to_Uint(rxbuff[41],rxbuff[42])/10;
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[31],rxbuff[32])/10;
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[35],rxbuff[36])/10;
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[39],rxbuff[40])/10;
					
                	inverter[invNo].power_inv_now       = Bytes_to_Uint(rxbuff[27],rxbuff[28])/100;  
                    inverter[invNo].power_inv_pf        = 950;
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[43],rxbuff[44]);

					
					
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[29],rxbuff[30]);
					inverter[invNo].power_inv_day_total /= 100; 
                    
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                    inverter[invNo].power_inv_total    <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[21],rxbuff[22]); 
                    inverter[invNo].power_inv_total /= 10; 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[45],rxbuff[46]);            
                    inverter[invNo].inverter_status[1] = 0;              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[49],rxbuff[50]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[51],rxbuff[52]);             
                


	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX%02d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
                
    
                rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
