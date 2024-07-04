
void sendInverterRead_EkosMbus(void) {
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;         
        case 1:     //Inv-1: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x01;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX01");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
            inverter_seq++;             
            break;
            
        case 5:    
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 6:     //Inv-2: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x02;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX02");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;                    
            
//-----------------------------------------------------
        case 10:    
        	if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 11:     //Inv-3: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x03;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX03");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 12:
        case 13:
        case 14:
            inverter_seq++;             
            break;
            
        case 15:    
        	if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 16:     //Inv-4: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x04;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX04");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 17:
        case 18:
        case 19:
        	inverter_seq++;
            break; 
            //-------------------
//-----------------------------------------------------
        case 20:    
        	if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 21:     //Inv-5: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x05;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX05");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 22:
        case 23:
        case 24:
            inverter_seq++;             
            break;
            
        case 25:    
        	if (eeInverterCount > 5) { 
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 26:     //Inv-6: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x06;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX06");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 27:
        case 28:
        case 29:
        	inverter_seq++;
            break; 
            //-------------------
//-----------------------------------------------------
        case 30:    
        	if (eeInverterCount > 6) { 
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;             
        case 31:     //Inv-7: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x07;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX07");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 32:
        case 33:
        case 34:
            inverter_seq++;             
            break;
            
        case 35:    
        	if (eeInverterCount > 7) { 
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;        
        case 36:     //Inv-8: RTU Master request frame (from WILLINGS_MBUS)  
            sendBuff[0] = 0x08;
            sendBuff[1] = 0x04;
            sendBuff[2] = 0x00;
            sendBuff[3] = 0x22;
            sendBuff[4] = 0x00;
            sendBuff[5] = 0x46;		//cnt:64 
            retVal = calcCRC(sendBuff,6);     
                                          
            TXEN = 1;
            TXEN = 1;
            putchar0(sendBuff[1]); //Function Code
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low  
            putchar0(retVal % 0x100); //CRC_L
            putchar0(retVal / 0x100); //CRC_H
                            
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif	//485 Address     

            sprintf(str,"TX08");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
                        
            inverter_seq++;             
            break;         
        case 37:
        case 38:
        case 39:
        	inverter_seq++;
            break; 
            //-------------------
		case 40:
        	inverter_seq = 0;
            break;            
            
            
            
                  
        default:  
            inverter_seq = 0;
            break;
    }
}


void rx0Control_EkosMbus(void) {
    //char imc;        
	char rxdata = getchar0();; 
    unsigned int calCrc,rxCrc;                 
    unsigned long int lim1, lim2;

//buzzer_flag |= BUZZER_TIC; 
//sprintf(str,"SEQ:%02d, %02X ", rx_seq0, rxdata );
//put_str(0,0,str,1);
             	
	switch(rx_seq0) {
		case 0:
			if ((rxdata > 0x10) || (rxdata < 0x19)) {   
                rcnt = 0;
                rxbuff[rcnt++] = rxdata;   
                timeout0 = 250;
				rx_seq0++;
			}   
			break;   
		case 1:     
        	rxbuff[rcnt++] = rxdata;   
			if (rxdata == 0x04) {   
            	rx_seq0++;   
            } else {      
            	rx_seq0=0;  
            }  
            break;
        case 2:      
        	rxbuff[rcnt++] = rxdata;
        	//if (rxdata == (0x2E * 2)) {	//92 (5CH)  
        	if (rxdata == (0x46 * 2)) {	//92 (5CH)  
            	rx_seq0++;
            } else {      
            	rx_seq0 = 0;
            }  
            break;
    	case 3:   
            rxbuff[rcnt++] = rxdata;  
                
            if (rcnt == (0x46 * 2 + 5)) {   
            	calCrc = calcCRC(rxbuff, 0x46 * 2 + 3);
                rxCrc = rxbuff[0x46 * 2 + 4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x46 * 2 + 3];  
                
                          
                       
//				sprintf(str,"CR:%02X%02X,%02X%02X ",calCrc%0x100,calCrc/0x100,rxCrc%0x100,rxCrc/0x100  );
//                put_str(0,0,str,1);         
//                buzzer_flag |= BUZZER_TIC;
                
                if (rxCrc != calCrc) {
                	return;
                }

                invNo = rxbuff[0] - 0x01;            
                inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[131],rxbuff[132]);
                inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[137],rxbuff[138]);
                inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[139],rxbuff[140]);
                inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[141],rxbuff[142]);
                
                
                //DC-V
                fdata.chars[3] = rxbuff[3];
                fdata.chars[2] = rxbuff[4];
                fdata.chars[1] = rxbuff[5];
                fdata.chars[0] = rxbuff[6];
                inverter[invNo].solar_cell_voltage	= (unsigned int)(fdata.value);                                                           
                //DC-A
                fdata.chars[3] = rxbuff[11];
                fdata.chars[2] = rxbuff[12];
                fdata.chars[1] = rxbuff[13];
                fdata.chars[0] = rxbuff[14];
                inverter[invNo].solar_cell_current	= (unsigned int)(fdata.value*10) / 10;
                //DC-KW
                fdata.chars[3] = rxbuff[15];
                fdata.chars[2] = rxbuff[16];
                fdata.chars[1] = rxbuff[17];
                fdata.chars[0] = rxbuff[18];                                     
                inverter[invNo].power_solar			= (unsigned int)(fdata.value/100);// / 10;   
                                                                                                      
                //선간전압 RS상
                fdata.chars[3] = rxbuff[51];
                fdata.chars[2] = rxbuff[52];
                fdata.chars[1] = rxbuff[53];
                fdata.chars[0] = rxbuff[54];
                inverter[invNo].inv_u_voltage		= (unsigned int)(fdata.value*1.73);// / 10;  
                //선간전압 ST상
                fdata.chars[3] = rxbuff[55];
                fdata.chars[2] = rxbuff[56];
                fdata.chars[1] = rxbuff[57];
                fdata.chars[0] = rxbuff[58];
                inverter[invNo].inv_v_voltage     	= (unsigned int)(fdata.value*1.73);// / 10;  
                //선간전압 TR상
                fdata.chars[3] = rxbuff[59];
                fdata.chars[2] = rxbuff[60];
                fdata.chars[1] = rxbuff[61];
                fdata.chars[0] = rxbuff[62];
                inverter[invNo].inv_w_voltage     	= (unsigned int)(fdata.value*1.73);// / 10;
                                                                                                                                             
                //전류 R상
                fdata.chars[3] = rxbuff[63];
                fdata.chars[2] = rxbuff[64];
                fdata.chars[1] = rxbuff[65];
                fdata.chars[0] = rxbuff[66];
                inverter[invNo].inv_u_current      = (unsigned int)(fdata.value*10) / 10;
                //전류 S상
                fdata.chars[3] = rxbuff[67];
                fdata.chars[2] = rxbuff[68];
                fdata.chars[1] = rxbuff[69];
                fdata.chars[0] = rxbuff[70];
                inverter[invNo].inv_v_current      = (unsigned int)(fdata.value*10) / 10; 
                //전류 T상
                fdata.chars[3] = rxbuff[71];
                fdata.chars[2] = rxbuff[72];
                fdata.chars[1] = rxbuff[73];
                fdata.chars[0] = rxbuff[74];
                inverter[invNo].inv_w_current      = (unsigned int)(fdata.value*10) / 10;  
                //주파수
                fdata.chars[3] = rxbuff[39];
                fdata.chars[2] = rxbuff[40];
                fdata.chars[1] = rxbuff[41];
                fdata.chars[0] = rxbuff[42];
                inverter[invNo].inv_frequency		= (unsigned int)(fdata.value*10); 
                //총 역률
                fdata.chars[3] = rxbuff[35];
                fdata.chars[2] = rxbuff[36];
                fdata.chars[1] = rxbuff[37];
                fdata.chars[0] = rxbuff[38];                                     
                //gipam.powerFactor = (signed int)(abs)(fdata.value*10);       
                inverter[invNo].power_inv_pf		= (signed int)(abs)(fdata.value*10);

                //AC-KW (현재 출력)
                fdata.chars[3] = rxbuff[27];
                fdata.chars[2] = rxbuff[28];
                fdata.chars[1] = rxbuff[29];
                fdata.chars[0] = rxbuff[20];
                inverter[invNo].power_inv_now 		= (unsigned int)(fdata.value/100);// / 10;          

                //DAY-TOTAL
                fdata.chars[3] = rxbuff[43];
                fdata.chars[2] = rxbuff[44];
                fdata.chars[1] = rxbuff[45];
                fdata.chars[0] = rxbuff[46];
                inverter[invNo].power_inv_day_total =  (unsigned int)(fdata.value/1000);// / 10;
                      
                                 
                lim1 = Bytes_to_Uint(rxbuff[123],rxbuff[124]);
                lim1 <<= 16; 
                lim1  += Bytes_to_Uint(rxbuff[125],rxbuff[126]);
                lim1 *= 1000; 

                lim2 = Bytes_to_Uint(rxbuff[127],rxbuff[128]);
                lim2 <<= 16; 
                lim2  += Bytes_to_Uint(rxbuff[129],rxbuff[130]);
                lim2 /= 1000; 
                         
                inverter[invNo].power_inv_total     = lim1 + lim2;
                                            
                sendInverterCount[invNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
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