void sendInverterRead_DIK(void) {  

    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: DIK 30K  
			//02 aa 00 01 01 00 00 03 03 ae
			rx_seq0 = 0; 
                        
            putchar0(0xaa);	//Master 
            putchar0(0x00); //Spare
            putchar0(0x01); //Model, 0x01:30kW, 0x04:3kW
            putchar0(0x01); //ID, inverterNo
            putchar0(0x00); //Spare          
            putchar0(0x00); //Spare          
		    putchar0(0x03); //ETX
    		putchar0(0x03);	//BCS1
            putchar0(0xAE);	//BCS2
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif	//STX        
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
			//02 aa 00 01 02 00 00 03 04 ae
			rx_seq0 = 0; 
                        
            putchar0(0xaa);	//Master 
            putchar0(0x00); //Spare
            putchar0(0x01); //Model, 0x01:30kW, 0x04:3kW
            putchar0(0x02); //ID, inverterNo
            putchar0(0x00); //Spare          
            putchar0(0x00); //Spare          
		    putchar0(0x03); //ETX
    		putchar0(0x04);	//BCS1
            putchar0(0xAE);	//BCS2
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif	//STX        
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
			//02 aa 00 01 03 00 00 03 05 ae
			rx_seq0 = 0; 
                        
            putchar0(0xaa);	//Master 
            putchar0(0x00); //Spare
            putchar0(0x01); //Model, 0x01:30kW, 0x04:3kW
            putchar0(0x03); //ID, inverterNo
            putchar0(0x00); //Spare          
            putchar0(0x00); //Spare          
		    putchar0(0x03); //ETX
    		putchar0(0x05);	//BCS1
            putchar0(0xAE);	//BCS2
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif	//STX        
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

        case 30:           
        	if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 31:     //Inv-4: RTU Master request frame  
			//02 aa 00 01 04 00 00 03 06 ae
			rx_seq0 = 0; 
                        
            putchar0(0xaa);	//Master 
            putchar0(0x00); //Spare
            putchar0(0x01); //Model, 0x01:30kW, 0x04:3kW
            putchar0(0x04); //ID, inverterNo
            putchar0(0x00); //Spare          
            putchar0(0x00); //Spare          
		    putchar0(0x03); //ETX
    		putchar0(0x06);	//BCS1
            putchar0(0xAE);	//BCS2
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif	//STX        
            sprintf(str,"TX-4");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;
                 
        case 40:           
        	if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 41:     //Inv-5: RTU Master request frame 
			//02 aa 00 01 05 00 00 03 07 ae
			rx_seq0 = 0; 
                        
            putchar0(0xaa);	//Master 
            putchar0(0x00); //Spare
            putchar0(0x01); //Model, 0x01:30kW, 0x04:3kW
            putchar0(0x05); //ID, inverterNo
            putchar0(0x00); //Spare          
            putchar0(0x00); //Spare          
		    putchar0(0x03); //ETX
    		putchar0(0x07);	//BCS1
            putchar0(0xAE);	//BCS2
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif	//STX        
            sprintf(str,"TX-5");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;     

        case 50:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_DIK(void) {   
	char rxdata;   
    unsigned int calCrc,icnt;
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
            rxbuff[rcnt++] = rxdata;
            if (rxdata == 0x55) {
                rx_seq0++; 
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 51) {   
                rx_seq0++;   
            }                     
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            if (rxdata == 0x03) {	//ETX ?
				rx_seq0++;     
            } else {
				rx_seq0 = 0;
            }
            break;
        case 4:  
        	calCrc = 0;
        	for(icnt=0; icnt<51; icnt+=2) {
            	calCrc += rxbuff[icnt];  
            }                           
            calCrc &= 0x00ff;
                    
//sprintf(str,"rxSeq:%02d %02X,%02X ",rx_seq0, rxdata, calCrc);   
//put_str(0,0,str,1);   
            if (rxdata == calCrc) {
				rx_seq0++;   
            } else {
				rx_seq0 = 0;
            }
            break;
        case 5:  
        	calCrc = 0;
        	for(icnt=0; icnt<51; icnt+=2) {
            	calCrc += rxbuff[icnt+1];
            }                        
            calCrc &= 0x00ff;

            if (rxdata == calCrc) {
                //invNo = 0;
                invNo = rxbuff[3] - 1;
                    
                inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[4],rxbuff[5]) / 10;
                inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[6],rxbuff[7]) / 10;            
                inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[8],rxbuff[9]); 
                inverter[invNo].inv_u_voltage     	= Bytes_to_Uint(rxbuff[10],rxbuff[11]) / 10; 
                inverter[invNo].inv_v_voltage     	= Bytes_to_Uint(rxbuff[12],rxbuff[13]) / 10; 
                inverter[invNo].inv_w_voltage     	= Bytes_to_Uint(rxbuff[14],rxbuff[15]) / 10;
                inverter[invNo].inv_u_current      	= Bytes_to_Uint(rxbuff[16],rxbuff[17]) / 10;
                inverter[invNo].inv_v_current     	= Bytes_to_Uint(rxbuff[18],rxbuff[19]) / 10;
                inverter[invNo].inv_w_current      	= Bytes_to_Uint(rxbuff[20],rxbuff[21]) / 10;
                inverter[invNo].power_inv_now        = Bytes_to_Uint(rxbuff[22],rxbuff[23]);  
                inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[24],rxbuff[25]);
                inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[26],rxbuff[27]);
                //inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[30],rxbuff[31]);
                inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[32],rxbuff[33]);
                inverter[invNo].power_inv_total   <<= 16; 
                inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[34],rxbuff[35]); 
                    
                inverter[invNo].inverter_status[0] = rxbuff[45];            
                inverter[invNo].inverter_status[1] = rxbuff[46];               
                inverter[invNo].inverter_status[2] = rxbuff[47];              
                inverter[invNo].inverter_status[3] = rxbuff[48];              
                
//                inverter[invNo].solar_cell_voltage  /= 10;
//                inverter[invNo].solar_cell_current  /= 10;            
//                inverter[invNo].inv_u_voltage     /= 10; 
//                inverter[invNo].inv_v_voltage     /= 10; 
//                inverter[invNo].inv_w_voltage     /= 10;
//                inverter[invNo].inv_u_current      /= 10;
//                inverter[invNo].inv_v_current      /= 10;
//                inverter[invNo].inv_w_current      /= 10;
                inverter[invNo].power_inv_day_total /= 10;

                sendInverterCount[invNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;

            }
            rx_seq0 = 0;
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
