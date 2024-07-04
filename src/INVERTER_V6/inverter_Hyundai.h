void sendInverterRead_Hyundai(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }    
            sprintf(str,"TX-1");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;            
            break;     
        case 1:     //Inv-1: RTU Master request frame  
        	//                        00 01 02 03 04 05 06 07 08 09
            //putchar0(0x02); //STX   02 aa 00 00 01 00 00 03 03 ad  
			rx_seq0 = 0;
            putchar0(0xAA); //MASTER
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x01); //ID
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x03); //ETX
            putchar0(0x03); //BCS1
            putchar0(0xAD); //BCS2
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
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

            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
    	        rx_led_delay = 2500;                
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 11:     //Inv-2: RTU Master request frame 
        	//                            00 01 02 03 04 05 06 07 08 09
            //putchar0(0x02); //STX       02 aa 00 00 02 00 00 03 04 ad
            rx_seq0 = 0;
            putchar0(0xAA); //MASTER
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x02); //ID
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x03); //ETX
            putchar0(0x04); //BCS1
            putchar0(0xAD); //BCS2
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif              
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
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }         

            sprintf(str,"TX-3");     
            put_str(4,16,str,1);   
    	        rx_led_delay = 2500;                
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 21:     //Inv-3: RTU Master request frame 
        	//                            00 01 02 03 04 05 06 07 08 09
            //putchar0(0x02); //STX       02 aa 00 00 02 00 00 03 04 ad
            rx_seq0 = 0;
            putchar0(0xAA); //MASTER
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x03); //ID
            putchar0(0x00); //Spare
            putchar0(0x00); //Spare
            putchar0(0x03); //ETX
            putchar0(0x05); //BCS1
            putchar0(0xAD); //BCS2
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif              
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
        case 30:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}




void rx0Control_Hyundai(void) {   
	char rxdata;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if (rxdata == 0x02) {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;   
                timeout0 = 250;
            	rx_seq0++;
            }  
			break;        
        case 1: //Device (Slave) 
            if (rxdata == 0x55) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else if (rxdata == 0xaa) {
            	rcnt = 0;
				rx_seq0 = 110;
            } else if (rxdata == 0xa5) {
            	rcnt = 0;
				rx_seq0 = 120;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //model (0x01,0x03,0x04,0x05 ; 3, 12.5,50, 100)
            if ( (rxdata == 0x03) ||(rxdata == 0x04) ||(rxdata == 0x05) ||(rxdata == 0x08) ||
            	(rxdata == 0x09) ||(rxdata == 0x0a) ||(rxdata == 0x0b) ||(rxdata == 0x0c) ) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 54) {
					buzzer_flag |= BUZZER_TIC;
                    put_strf(4,16,C_RXOK,1);   
					rx_led_delay = 2500;

                if (rxbuff[51]==0x03) {
                    invNo = rxbuff[3] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[4],rxbuff[5]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[6],rxbuff[7]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[8],rxbuff[9]); 
                	inverter[invNo].inv_u_voltage     	= Bytes_to_Uint(rxbuff[10],rxbuff[11]); 
                	inverter[invNo].inv_v_voltage     	= Bytes_to_Uint(rxbuff[12],rxbuff[13]); 
                	inverter[invNo].inv_w_voltage    	= Bytes_to_Uint(rxbuff[14],rxbuff[15]);
                    inverter[invNo].inv_u_current      	= Bytes_to_Uint(rxbuff[16],rxbuff[17]);
                	inverter[invNo].inv_v_current      	= Bytes_to_Uint(rxbuff[18],rxbuff[19]);
                	inverter[invNo].inv_w_current      	= Bytes_to_Uint(rxbuff[20],rxbuff[21]);
               	    inverter[invNo].power_inv_now 		= Bytes_to_Uint(rxbuff[22],rxbuff[23]);
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[24],rxbuff[25]);
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[26],rxbuff[27]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[28],rxbuff[29]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[30],rxbuff[31]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[32],rxbuff[33]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[34],rxbuff[35]);
                    inverter[invNo].inverter_status[0] 	= Bytes_to_Uint(rxbuff[45],rxbuff[46]);            
                    inverter[invNo].inverter_status[1] 	= rxbuff[47];            
                    inverter[invNo].inverter_status[2] 	= rxbuff[48];            
                    inverter[invNo].inverter_status[3] 	= rxbuff[49];            
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].inv_u_voltage     	/= 10; 
                	inverter[invNo].inv_v_voltage     	/= 10; 
                	inverter[invNo].inv_w_voltage     	/= 10;
                    inverter[invNo].inv_u_current      	/= 10;
                	inverter[invNo].inv_v_current      	/= 10;
                	inverter[invNo].inv_w_current      	/= 10;
                	inverter[invNo].power_inv_day_total /= 10;

					sendInverterCount[invNo] = 0;
                    
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX-%01d",invNo+1);
    	            put_str(4,16,str,1);   
					rx_led_delay = 2500;
                
                }    
                rx_seq0 = 0;
            }
            break;

		//System Setting /////////////////////////////////////            

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
