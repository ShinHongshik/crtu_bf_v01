/*
02 2e 01 00 00 00 01 06 11 09 59 00 00 22 bd 00 0e c6 7f 01 21 00 59 00 00 00 00 00 e3 00 69 00 00 00 00 00 00 00 00 00 00 00 00 04 73 03 
02 2e 02 00 00 00 01 06 11 09 62 00 00 22 be 00 0e c6 80 01 1d 00 58 00 00 00 00 00 e3 00 69 00 00 00 00 00 00 00 00 00 00 00 00 04 79 03 
02 2e 03 00 00 00 01 06 11 09 60 00 00 22 bf 00 0e c6 81 01 19 00 50 00 00 00 00 00 e4 00 69 00 00 00 00 00 00 00 00 00 00 00 00 04 6e 03 
02 2e 04 00 00 00 01 06 11 09 44 00 00 22 bf 00 0e c6 81 01 16 00 50 00 00 00 00 00 e3 00 68 00 00 00 00 00 00 00 00 00 00 00 00 04 4d 03 
02 2e 05 00 00 00 01 06 11 09 44 00 00 22 bf 00 0e c6 81 01 16 00 50 00 00 00 00 00 e3 00 68 00 00 00 00 00 00 00 00 00 00 00 00 04 4d 03 
02 2e 01 00 00 00 02 06 11 09 58 00 00 22 92 00 0e b0 8f 01 23 00 51 00 00 00 00 00 e3 00 69 00 00 00 00 00 00 00 00 00 00 00 00 04 3c 03 
02 2e 02 00 00 00 02 06 11 09 5c 00 00 22 93 00 0e b0 90 01 1f 00 52 00 00 00 00 00 e3 00 69 00 00 00 00 00 00 00 00 00 00 00 00 04 3f 03 
*/

void sendInverterRead_Hansol3k(void) {  
//    unsigned int retVal;
//    char sendBuff[10];   

//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     
        	//Inv-1: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x01;

            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX%02d",imInvNo);     
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
        case 6:
        	//Inv-2: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x02;  
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 7:
        case 8:
        case 9: 
            inverter_seq++;             
            break;         

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
        case 11:
        	//Inv-3: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x03;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
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
        case 16:
        	//Inv-4: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x04;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;     

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
        case 21: 
        	//Inv-5: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x05;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
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
        case 26:  
        	//Inv-6: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x06;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;     

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
        case 31:  
        	//Inv-7: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x07;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
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
        case 36: 
        	//Inv-8: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x08;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;
                 
        case 40:           
        	if (eeInverterCount > 8) { 
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 41:
        	//Inv-9: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x09;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 42:
        case 43:
        case 44:   
            inverter_seq++;             
            break;  
                   
        case 45:           
        	if (eeInverterCount > 9) { 
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 46:  
        	//Inv-10: RTU Master request frame  
			rx_seq0 = 0;                               
                                           
            imInvNo = 0x0a;
            
            putchar0(0x0c);		//Length (STX~ETX) 
            putchar0(0x00);		//Frame Number
            putchar0(0x00);		//Option
            putchar0(0x00);		//Option
            putchar0(imInvNo);		//목적지 ID
            putchar0(0x00); 	//자신 ID           
		    putchar0(0x05);		//ENQ
		    putchar0(0x11);		//단상:0x11,삼상:0x33
    		putchar0(0x00);		//CheckSum
            calBCC = imInvNo + 0x05 + 0x11;
    		putchar0(calBCC);	//CheckSum
    		putchar0(0x03);     //ETX
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif       
            sprintf(str,"TX%02d",imInvNo);    
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;     



        case 100:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_Hansol3k(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
    char ic;
    
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
        case 1: //Length 
            if (rxdata == 0x2E) {	//Length=46
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2:
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 45) {
            	rx_seq0++;
            }
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (rxdata == 0x03) {	//ETX 
                rxCrc = rxbuff[43];
                rxCrc <<= 8;
                rxCrc += rxbuff[44];  

            	calCrc = 0;
                for(ic=5;ic<43;ic++) {
                	calCrc += rxbuff[ic];
                }   
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[6] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[21],rxbuff[22]); 
                	inverter[invNo].power_solar         = inverter[invNo].solar_cell_voltage * inverter[invNo].solar_cell_current; 
                	inverter[invNo].inv_u_voltage     	= Bytes_to_Uint(rxbuff[27],rxbuff[28]); 
                	inverter[invNo].inv_v_voltage     	= inverter[invNo].inv_v_voltage; 
                	inverter[invNo].inv_w_voltage    	= inverter[invNo].inv_v_voltage;
                    inverter[invNo].inv_u_current      	= Bytes_to_Uint(rxbuff[29],rxbuff[30]);
                	inverter[invNo].inv_v_current      	= inverter[invNo].inv_u_current;
                	inverter[invNo].inv_w_current      	= inverter[invNo].inv_u_current;
                	inverter[invNo].power_inv_now       = inverter[invNo].inv_u_voltage * inverter[invNo].inv_u_current;
                    inverter[invNo].power_solar			= inverter[invNo].power_inv_now; 
                    inverter[invNo].power_inv_pf        = 997;
                    inverter[invNo].inv_frequency       = 600;
                	//inverter[invNo].power_inv_max     = 0;
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[15],rxbuff[16]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[17],rxbuff[18]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[39],rxbuff[40]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[41],rxbuff[42]);              
                    inverter[invNo].inverter_status[2] = 0;             
                    inverter[invNo].inverter_status[3] = 0;             
                
					inverter[invNo].solar_cell_current  /= 10;  
                    inverter[invNo].inv_u_current      /= 10;
                	inverter[invNo].inv_v_current      /= 10;
                	inverter[invNo].inv_w_current      /= 10;   
                	inverter[invNo].power_solar 		/= 100;        
                	inverter[invNo].power_inv_now       /= 100;  
                    
                	inverter[invNo].power_inv_day_total /= 1000;
                	inverter[invNo].power_inv_total     /= 1000;                    
                    
	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX0%d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
                }
            	rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
