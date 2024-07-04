
void sendInverterRead_Kaco(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: //23 30 31 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       

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
        case 6:     //Inv-2: //23 30 32 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 11:     //Inv-3: //23 30 33 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 16:     //Inv-4: //23 30 34 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 21:     //Inv-5: //23 30 35 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 26:     //Inv-6: //23 30 36 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x36); //6
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 31:     //Inv-7: //23 30 37 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x37); //7
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 36:     //Inv-8: //23 30 38 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x38); //8
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 41:     //Inv-9: //23 30 39 30 0d
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x39); //9
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

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
        case 46:     //Inv-10: //23 31 30 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX-A");
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
        case 51:     //Inv-11: //23 31 31 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX-B");
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
        case 56:     //Inv-12: //23 31 32 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x32); //2
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX-C");
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
        case 61:     //Inv-13: //23 31 33 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x33); //3
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX-D");
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
        case 66:     //Inv-14: //23 31 34 30 0d
            //putchar0(0x23); //
            putchar0(0x31); //1
            putchar0(0x34); //4
            putchar0(0x30); //0
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  

            sprintf(str,"TX-E");
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
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_Kaco(void) {   
	char rxdata;
	rxdata = getchar0();

	switch(rx_seq0) {         
    	case 0:
        	if (rxdata == 0x0a) {  
                timeout0 = 250;
            	rx_seq0++;
            } else if (rxdata ==0x02) {
                timeout0 = 250;
            	rx_seq0 = 200;
            }
            break;
		case 1:        
        	if (rxdata == 0x2a) {
				rcnt = 0;           
                 memset(rxbuff,0,sizeof(rxbuff));

            	rxbuff[rcnt++] = rxdata;
                rx_seq0++;
			}   
			break;        

//=========================================================================
//000000000011111111112222222222333333333344444444445555555555666666666677777777
//012345678901234567890123456789012345678901234567890123456789012345678901234567
//--------------------------------------------------------------------------------
//*000 005 482.8 132.30 063900 393.2 091.60 062100 37 0341458  100k   000007831
//*010  35 492.9 80.60 039700 381.3 61.80 039200 34 262100 r 100k   5751
//*010  35 514.0 69.70 035800 382.6 55.80 035500 32 285500 v 100k   5775

//*010 005 535.7 012.90 006900 383.2 014.00 004800 17 0040453 0kTR 000034087

		case 2:
        	rxbuff[rcnt++] = rxdata;
            if (rcnt == 71) {
            	if (rxdata == 0x0d) {  //LS PV Inverter 
                	invNo = rxbuff[2] - 0x31;
                    


                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];str[1]=rxbuff[16];str[2]=rxbuff[17];str[2]=rxbuff[18];
                    inverter[invNo].solar_cell_current = atoi(str);
                    inverter[invNo].solar_cell_current /=  10;            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[21];str[1]=rxbuff[22];str[2]=rxbuff[23];str[3]=rxbuff[24];
                    inverter[invNo].power_solar        = atoi(str);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[28];str[1]=rxbuff[29];str[2]=rxbuff[30];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    inverter[invNo].inv_v_voltage = inverter[0].inv_u_voltage; 
                    inverter[invNo].inv_w_voltage = inverter[0].inv_u_voltage;
                    
                    inverter[invNo].inv_frequency = 600;

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[34];str[1]=rxbuff[35];str[2]=rxbuff[36];str[3]=rxbuff[37];
                    inverter[invNo].inv_u_current = atoi(str);
                    inverter[invNo].inv_v_current = inverter[0].inv_u_current;
                    inverter[invNo].inv_w_current = inverter[0].inv_u_current;
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[40];str[1]=rxbuff[41];str[2]=rxbuff[42];str[3]=rxbuff[43];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[50];str[1]=rxbuff[51];str[2]=rxbuff[52];//str[3]=rxbuff[55];
                    inverter[invNo].power_inv_day_total = atoi(str);            
                    
                    memset(str,0,sizeof(str));  
//                    str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
//                    if (atol(str) > 0) {
//                        inverter[invNo].power_inv_total = atol(str);
//                    }          
					inverter[invNo].power_inv_total = 0;  
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[5];str[1]=rxbuff[6];str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[0].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;

					inverter[invNo].power_inv_pf = 960;
                                        
                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC; 
		                                       
                    sprintf(str,"RX-%01d",invNo+1);
                    //sprintf(str,"RX71");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                
                } else {
                	rx_seq0++;
                }
            }                     
            break;  

        case 3: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 78) {
            	if (rxdata == 0x0d) {
                	                                           


                	//2014/1/12 KACO XP500-HL-TL ¼öÁ¤µÊ....
                    if ((rxbuff[2] > 0x30) && (rxbuff[2] < 0x35)) { 
                    	invNo = rxbuff[2] - 0x31; 
                    } else if ((rxbuff[3] > 0x30) && (rxbuff[3] < 0x35)) { 
                    	invNo = rxbuff[3] - 0x31;
                    }
                    /////////////////////////////////////
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];
                    inverter[invNo].solar_cell_voltage = atoi(str);            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];str[1]=rxbuff[16];str[2]=rxbuff[17];str[3]=rxbuff[19];
                    inverter[invNo].solar_cell_current = atoi(str);
                    inverter[invNo].solar_cell_current /= 10;            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[22];str[1]=rxbuff[23];str[2]=rxbuff[24];str[3]=rxbuff[25];
                    inverter[invNo].power_solar        = atoi(str);

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[29];str[1]=rxbuff[30];str[2]=rxbuff[31];
                    inverter[invNo].inv_u_voltage = atoi(str);       
                    inverter[invNo].inv_v_voltage = inverter[0].inv_u_voltage; 
                    inverter[invNo].inv_w_voltage = inverter[0].inv_u_voltage;
                    
                    inverter[invNo].inv_frequency = 600;

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[35];str[1]=rxbuff[36];str[2]=rxbuff[37];
                    inverter[invNo].inv_u_current = atoi(str);
                    inverter[invNo].inv_v_current = inverter[0].inv_u_current;
                    inverter[invNo].inv_w_current = inverter[0].inv_u_current;

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[42];str[1]=rxbuff[43];str[2]=rxbuff[44];str[3]=rxbuff[45];
                    inverter[invNo].power_inv_now = atoi(str);     
    //                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[52];str[1]=rxbuff[53];str[2]=rxbuff[54];//str[3]=rxbuff[55];
                    inverter[invNo].power_inv_day_total = atoi(str);            

//	            sprintf(str, "RxCount:%02X,%02X,%02X,%02X ",rxbuff[51],rxbuff[52],rxbuff[53],rxbuff[54]);
//    	        put_str(0,0,str,1);   
                    
                    memset(str,0,sizeof(str));  
                    str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
                    if (atol(str) > 0) {
                        inverter[invNo].power_inv_total = atol(str);
                    }            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[5];str[1]=rxbuff[6];str[2]=rxbuff[7];
                    if (atoi(str) < 255) { 
                        inverter[invNo].inverter_status[0] = atoi(str);            
                    } else {
                        inverter[invNo].inverter_status[0] = 255;            
                    }
                    inverter[invNo].inverter_status[1] = inverter[0].inverter_status[0];
                    inverter[invNo].inverter_status[2] = 0;
                    inverter[invNo].inverter_status[3] = 0;

					inverter[invNo].power_inv_pf = 960;
                                     
                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC; 
		                                       
                    sprintf(str,"RX-%01d",invNo+1);   
                    //sprintf(str,"RX78");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;

                    rx_seq0 = 0;
                
                } else {
                	rx_seq0++;
                }
            }                     
            break;  

//=========================================================================
//0000000000111111111122222222223333333333444444444455555555556666666666777777777
//0123456789012345678901234567890123456789012345678901234567890123456789012345678
//--------------------------------------------------------------------------------
//*000 005 482.8 132.30 063900 393.2 091.60 062100 37 0341458  100k   000007831
//*000 005 482.8 132.20 063800 393.2 091.70 062000 37 0341458  100k   000007831
//*000 005 482.8 132.30 063900 393.2 091.60 062000 37 0341544  100k   000007831
//*000 005 486.3 131.30 063900 393.1 091.60 062100 37 0341544  100k   000007831
//         PV-V  PV-C    63.9w u-V   U-A    U-W    tmp d-tot           tot-     
//*020 000 006.4 000.00 000000 282.5 005.40 000000 16 0283300 200kTL 000353575 0D
//*010 000 004.4 000.00 000000 284.1 004.30 000000 15 

                     
        case 4: //LS 100K
            rxbuff[rcnt++] = rxdata;
            if (rxdata == 0x0d) { 

            
                       
//sprintf(str,"RX_seq:%02d ST1 ",rx_seq0); buzzer_flag |= BUZZER_TIC; tx_led_delay = 1000; put_str(0,0,str,1);
//sprintf(str,"RX_seq:%02d ST1 ",rx_seq0);
  //              put_str(0,0,str,1);   

//	            sprintf(str, "RCnt:%02d  ",rcnt);
//    	        put_str(0,0,str,1);   



				if (rcnt == 79) {          
					invNo = rxbuff[2] - 0x31;
                } else {
					invNo = rxbuff[3] - 0x31;
                }

                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];
                inverter[invNo].solar_cell_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[15];str[1]=rxbuff[16];str[2]=rxbuff[17];str[3]=rxbuff[19];
                inverter[invNo].solar_cell_current = atoi(str);
                inverter[invNo].solar_cell_current /= 10;            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[22];str[1]=rxbuff[23];str[2]=rxbuff[24];str[3]=rxbuff[25];
                inverter[invNo].power_solar        = atoi(str);

                memset(str,0,sizeof(str));
                str[0]=rxbuff[29];str[1]=rxbuff[30];str[2]=rxbuff[31];
                inverter[invNo].inv_u_voltage = atoi(str);       
                inverter[invNo].inv_v_voltage = inverter[0].inv_u_voltage; 
                inverter[invNo].inv_w_voltage = inverter[0].inv_u_voltage;
                
                inverter[invNo].inv_frequency = 600;

                memset(str,0,sizeof(str));
                str[0]=rxbuff[35];str[1]=rxbuff[36];str[2]=rxbuff[37];
                inverter[invNo].inv_u_current = atoi(str);
                inverter[invNo].inv_v_current = inverter[0].inv_u_current;
                inverter[invNo].inv_w_current = inverter[0].inv_u_current;

                memset(str,0,sizeof(str));
                str[0]=rxbuff[42];str[1]=rxbuff[43];str[2]=rxbuff[44];str[3]=rxbuff[45];
                inverter[invNo].power_inv_now = atoi(str);     
//                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       

                memset(str,0,sizeof(str));
                str[0]=rxbuff[52];str[1]=rxbuff[53];str[2]=rxbuff[54];str[3]=rxbuff[55];
                inverter[invNo].power_inv_day_total = atoi(str);            
                
                memset(str,0,sizeof(str));  
//                rxbuff[71] = 0x30;
//                rxbuff[72] = 0x30;
//                rxbuff[73] = 0x30;
//                rxbuff[74] = 0x30;
//                rxbuff[75] = 0x38;
//                rxbuff[76] = 0x39;
//                rxbuff[77] = 0x38;
				if (rcnt == 79) {           
//						old
//                    str[0]=rxbuff[69];str[1]=rxbuff[70];str[2]=rxbuff[71];str[3]=rxbuff[72];str[4]=rxbuff[73];str[5]=rxbuff[74];str[6]=rxbuff[75];
// LS 100K
                    str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];str[7]=rxbuff[77];
                    if (atol(str) > 0) {
                        inverter[invNo].power_inv_total = atol(str);
                    }            
				} else {
                    str[0]=rxbuff[71];str[1]=rxbuff[72];str[2]=rxbuff[73];str[3]=rxbuff[74];str[4]=rxbuff[75];str[5]=rxbuff[76];str[6]=rxbuff[77];
                    if (atol(str) > 0) {
                        inverter[invNo].power_inv_total = atol(str);
                    }   
                }         

	            //sprintf(str, "ino:%d,%05d,%05d", invNo+1, inverter[invNo].power_inv_day_total, inverter[invNo].power_inv_total);
    	        //put_str(0,0,str,1);   

                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[5];str[1]=rxbuff[6];str[2]=rxbuff[7];
                if (atoi(str) < 255) { 
	                inverter[invNo].inverter_status[0] = atoi(str);            
                } else {
	                inverter[invNo].inverter_status[0] = 255;            
                }
                inverter[invNo].inverter_status[1] = inverter[0].inverter_status[0];
                inverter[invNo].inverter_status[2] = 0;
                inverter[invNo].inverter_status[3] = 0;

                inverter[invNo].power_inv_pf = 960;
                
                sendInverterCount[invNo] = 0;                                  
                buzzer_flag |= BUZZER_TIC;   
                
                sprintf(str,"RX-%01d",invNo+1); 
                //   sprintf(str,"RX79");
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



