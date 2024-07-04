
void sendInverterRead_Windrex3K(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('1');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX-1");
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
        case 6:     //Inv-2: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('2');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX-2");
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
        case 11:     //Inv-3: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('3');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-3");
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
        case 16:     //Inv-4: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('4');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-4");
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
        case 21:     //Inv-5: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('5');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-5");
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
        case 26:     //Inv-6: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('6');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-6");
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
        case 31:     //Inv-7: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('7');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-7");
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
        case 36:     //Inv-8: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('8');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-8");
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
        case 41:     //Inv-9: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('0');
            putchar0('9');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX-9");
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
        case 46:     //Inv-10: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('0');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX10");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;           
            
        case 50:
        	if (eeInverterCount > 10) { 
                if (sendInverterCount[10] < 100) {
                    sendInverterCount[10]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 51:     //Inv-11: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('1');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX11");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 52:
        case 53:
        case 54:
            inverter_seq++;
            break;               


        case 55:
        	if (eeInverterCount > 11) { 
                if (sendInverterCount[11] < 100) {
                    sendInverterCount[11]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 56:     //Inv-12: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('2');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX12");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 57:
        case 58:
        case 59:
            inverter_seq++;
            break;           
            
        case 60:
        	if (eeInverterCount > 12) { 
                if (sendInverterCount[12] < 100) {
                    sendInverterCount[12]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 61:     //Inv-13: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('3');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX13");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 62:
        case 63:
        case 64:
            inverter_seq++;
            break;               


        case 65:
        	if (eeInverterCount > 13) { 
                if (sendInverterCount[13] < 100) {
                    sendInverterCount[13]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 66:     //Inv-14: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('4');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX14");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 67:
        case 68:
        case 69:
            inverter_seq++;
            break;   
			
        case 70:
        	if (eeInverterCount > 14) { 
                if (sendInverterCount[14] < 100) {
                    sendInverterCount[14]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 71:     //Inv-15: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('5');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX15");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 72:
        case 73:
        case 74:
            inverter_seq++;
            break;               


        case 75:
        	if (eeInverterCount > 15) { 
                if (sendInverterCount[15] < 100) {
                    sendInverterCount[15]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 76:     //Inv-16: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('6');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX16");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 77:
        case 78:
        case 79:
            inverter_seq++;
            break;   
        case 80:
        	if (eeInverterCount > 16) { 
                if (sendInverterCount[16] < 100) {
                    sendInverterCount[16]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 81:     //Inv-17: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('7');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX17");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 82:
        case 83:
        case 84:
            inverter_seq++;
            break;               


        case 85:
        	if (eeInverterCount > 17) { 
                if (sendInverterCount[17] < 100) {
                    sendInverterCount[17]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 86:     //Inv-18: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('8');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX18");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 87:
        case 88:
        case 89:
            inverter_seq++;
            break; 
			
        case 90:
        	if (eeInverterCount > 18) { 
                if (sendInverterCount[18] < 100) {
                    sendInverterCount[18]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 91:     //Inv-19: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('1');
            putchar0('9');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';        

            sprintf(str,"TX19");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 92:
        case 93:
        case 94:
            inverter_seq++;
            break;               


        case 95:
        	if (eeInverterCount > 19) { 
                if (sendInverterCount[19] < 100) {
                    sendInverterCount[19]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;     
        case 96:     //Inv-20: //#WR 000 0 X
            //putchar0('#');	//Frame Header
            putchar0('W');
            putchar0('R');
            putchar0('0');
            putchar0('2');
            putchar0('0');
            putchar0('R');
            putchar0('X');
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            UDR0 = '#';       

            sprintf(str,"TX20");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 97:
        case 98:
        case 99:
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



void rx0Control_Windrex3K(void) {   
	char rxdata;
	rxdata = getchar0();

	switch(rx_seq0) {         
    	case 0:
        	if (rxdata == '#') {  
                memset(rxbuff,0,sizeof(rxbuff));
				rcnt = 1;           
            	rxbuff[rcnt++] = rxdata;

                timeout0 = 2500;
            	rx_seq0++;
            } else if (rxdata ==0x02) {
                timeout0 = 250;
            	rx_seq0 = 200;
            }
            break;
		case 1:        
        	if (rxdata == 'W') {
            	rxbuff[rcnt++] = rxdata;
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}
			break;
		case 2:
			if (rxdata == 'R') {
            	rxbuff[rcnt++] = rxdata;
                rx_seq0++;
			} else {
				rx_seq0 = 0;
			}
			break;
		case 3:
			rxbuff[rcnt++] = rxdata;
			if ((rxdata == 'X') && (rcnt==57)) {
                rx_seq0++;
			}
			break;
		case 4:        
        	if (rxdata == 0x0A) {	//LF 0x0A
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}
			break;

			//==========================================================
//0000000001111111111222222222233333333334444444444555555555
//1234567890123456789012345678901234567890123456789012345678
//----------------------------------------------------------
//#WR???T00000-A000B000C000D000E000F000G000H000I000J00000X0A0D
		case 5:        
        	if (rxdata == 0x0D) {	//CR 0x0D
				memset(str,0,sizeof(str));
				str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
				invNo = atoi(str) - 1;            

				memset(str,0,sizeof(str));
				str[0]=rxbuff[15];str[1]=rxbuff[16];str[2]=rxbuff[17];
				inverter[invNo].inverter_status[0] = atoi(str);            

				memset(str,0,sizeof(str));
				str[0]=rxbuff[19];str[1]=rxbuff[20];str[2]=rxbuff[21];
				inverter[invNo].inverter_status[1] = atoi(str);
				inverter[invNo].inverter_status[2] = 0;
				inverter[invNo].inverter_status[3] = 0;
				
				memset(str,0,sizeof(str));
				str[0]=rxbuff[23];str[1]=rxbuff[24];str[2]=rxbuff[25];
				inverter[invNo].solar_cell_voltage = atoi(str);            
				
				memset(str,0,sizeof(str));
				str[0]=rxbuff[27];str[1]=rxbuff[28];str[2]=rxbuff[29];
				inverter[invNo].solar_cell_current = atoi(str);
				inverter[invNo].solar_cell_current /= 10;

				inverter[invNo].power_solar = inverter[invNo].solar_cell_voltage * inverter[invNo].solar_cell_current;
				inverter[invNo].power_solar /= 10;	//3Kw 인버터 출력은 *10으로 표현함. 사용자는 /10으로 봐야함.
				
				memset(str,0,sizeof(str));
				str[0]=rxbuff[31];str[1]=rxbuff[32];str[2]=rxbuff[33];
				inverter[invNo].inv_u_voltage = atoi(str);       
				inverter[invNo].inv_v_voltage = inverter[0].inv_u_voltage; 
				inverter[invNo].inv_w_voltage = inverter[0].inv_u_voltage;
				
				memset(str,0,sizeof(str));
				str[0]=rxbuff[35];str[1]=rxbuff[36];str[2]=rxbuff[37];
				inverter[invNo].inv_u_current = atoi(str);
				inverter[invNo].inv_u_current /= 10;
				inverter[invNo].inv_v_current = inverter[0].inv_u_current;
				inverter[invNo].inv_w_current = inverter[0].inv_u_current;

				memset(str,0,sizeof(str));
				str[0]=rxbuff[39];str[1]=rxbuff[40];str[2]=rxbuff[41];
				inverter[invNo].inv_frequency = atoi(str);

				inverter[invNo].power_inv_now = atoi(str);     

				inverter[invNo].power_inv_now = inverter[invNo].inv_u_voltage * inverter[invNo].inv_u_current;
				inverter[invNo].power_inv_now /= 10;	//3Kw 인버터 출력은 *10으로 표현함. 사용자는 /10으로 봐야함.

				memset(str,0,sizeof(str));
				str[0]=rxbuff[47];str[1]=rxbuff[48];str[2]=rxbuff[49];
				inverter[invNo].power_inv_day_total = atoi(str);            
				inverter[invNo].power_inv_day_total /= 10;
				
				memset(str,0,sizeof(str));  
				str[0]=rxbuff[51];str[1]=rxbuff[52];str[2]=rxbuff[53];str[3]=rxbuff[54];str[4]=rxbuff[55];
				inverter[invNo].power_inv_total = atoi(str);
				

				inverter[invNo].power_inv_pf = 960;
									
				sendInverterCount[invNo] = 0;
				buzzer_flag |= BUZZER_TIC; 
										   
				sprintf(str,"RX%02d",invNo+1);
				//sprintf(str,"RX71");
				put_str(4,16,str,1);   
				rx_led_delay = 2500;

				rx_seq0 = 0;
			}
            break;  

		//System Setting /////////////////////////////////////            
		case 200:               
            rcnt = 0;
            if (rxdata == 0xa5) {			//RD_DATA
                rx_seq0 = 220;
            } else if (rxdata == 0xaa) {	//WR_DATA
				rcnt = 0;
                rx_seq0 = 210;      
            } else {
                rx_seq0 = 0;
            }
			break;
		case 210:  	//WR_DATA
			rxbuff[rcnt++] = rxdata;
			if (rcnt == 5) {
				rx_seq0++;
			}			
			break;  
			     
		case 211:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 212:  
			if (rxdata == 0x0d) {   
				eePortNumber = rxbuff[0] * 0x100 + rxbuff[1];
				eeSendDelay = rxbuff[2] * 0x100 + rxbuff[3]; 
                eeSendDelay *= 1000; 
                eeInverterCount = rxbuff[4];
			    sprintf(str,"%04d", eePortNumber);
				put_str(1,6,str,2);    
            	//send_system_parameter();   
				buzzer_flag |= BUZZER_TIC;
			}
			rx_seq0 = 0;         
			break;
			
			
		case 220:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 221:  
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



