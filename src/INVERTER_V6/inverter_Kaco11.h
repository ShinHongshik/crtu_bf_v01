//KACO 33000XI-M (33K 구형 인버터), 내부에 11K 3대가 들어가 있어서
//1,2,3번 개별로 데이터를 읽어와야 함.
//DCV, ACV(UV)는 내부 1번 인버터의 값으로 표현하고,
//DCA, ACA, DCKW, ACKW, e-DAY는 내부 3개의 합산한 값으로 표현한다.


void sendInverterRead_KACO11(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }                                                                                                     
            break;     
        case 1:     //Inv-1: //23 30 31 31 0d	1번인버터 내부1번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x31); //1
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;     
            break;
        case 2:     //Inv-1: //23 30 31 32 0d	1번인버터 내부2번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x32); //2
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif       
            inverter_seq++;      
            break;
        case 3:     //Inv-1: //23 30 31 33 0d	1번인버터 내부3번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x33); //3
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
        case 6:     //Inv-2: //23 30 32 31 0d	2번인버터 내부1번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x31); //1
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  
            inverter_seq++;    
            break;
        case 7:     //Inv-2: //23 30 32 33 0d	2번인버터 내부2번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x32); //2
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif  
            inverter_seq++;     
            break;
        case 8:     //Inv-2: //23 30 32 34 0d	2번인버터 내부3번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x33); //3
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
        case 11:     //Inv-3: //23 30 33 31 0d		3번인버터 내부1번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x31); //1
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;     
            break;
        case 12:     //Inv-3: //23 30 33 32 0d		3번인버터 내부2번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x32); //2
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;     
            break;
        case 13:     //Inv-3: //23 30 33 33 0d		3번인버터 내부3번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x33); //3
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
        case 16:     //Inv-4: //23 30 34 31 0d		4번인버터 내부1번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x31); //1
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;   
            break;
        case 17:     //Inv-4: //23 30 34 32 0d		4번인버터 내부2번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x32); //2
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;      
            break;
        case 18:     //Inv-4: //23 30 34 33 0d		4번인버터 내부3번
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x33); //3
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
        case 21:     //Inv-5: //23 30 35 31 0d		5번인버터 내부1
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x31); //1
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;    
            break;
        case 22:     //Inv-5: //23 30 35 32 0d		5번인버터 내부1
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x32); //2
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;    
            break;
        case 23:     //Inv-5: //23 30 35 33 0d		5번인버터 내부3
            //putchar0(0x23); //
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x33); //3
            putchar0(0x0d); //cr
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x23);  
#else  
			UDR0 = 0x23 ;  
#endif   
            inverter_seq++;

            sprintf(str,"TX-5");
            put_str(4,16,str,1);   
            rx_led_delay = 2500;  

            inverter_seq++;
            break;         
        case 24:
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



void rx0Control_KACO11(void) {   
	char rxdata;
	rxdata = getchar0();

	switch(rx_seq0) {         
    	case 0:
        	//0a 2a 30 31 6e 20 32
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
               
		//KACO 11K x 3 = 33000xi_M
        case 2: 
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 72) {
            	if (rxdata == 0x0d) {
                	if (rxbuff[1] == 0x30) {       
                		invNo = rxbuff[2] - 0x31;
                        inv_command = rxbuff[3] - 0x30;
                    } else {
                    	return;
                    }
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[7];//str[1]=rxbuff[15]; //str[2]=rxbuff[7];

                    if (atoi(str) < 255) { 
						imInverterData[inv_command].inv_status = atoi(str);
                    } else {
						imInverterData[inv_command].inv_status = 255;
                    }    
                        
                    if (inv_command == 1) {
                        memset(str,0,sizeof(str));
                        str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];
                        inverter[invNo].solar_cell_voltage = atoi(str);
                    }            
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[15];str[1]=rxbuff[16];//str[2]=rxbuff[25];//str[3]=rxbuff[19];
                    imInverterData[inv_command].solar_cell_current = atoi(str);   
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[22];str[1]=rxbuff[23];str[2]=rxbuff[24];   
                    imInverterData[inv_command].power_solar = atoi(str);   
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[28];str[1]=rxbuff[29];str[2]=rxbuff[30];
                    if (inv_command == 1) {
                    	inverter[invNo].inv_u_voltage = atoi(str);       
                    } else if (inv_command == 2) {
                    	inverter[invNo].inv_v_voltage = atoi(str);       
                    } else if (inv_command == 3) {
                    	inverter[invNo].inv_w_voltage = atoi(str);       
                    } 
                    inverter[invNo].inv_frequency = 600;

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[34];str[1]=rxbuff[35];  
                    
                    if (inv_command == 1) {
                    	inverter[invNo].inv_u_current = atoi(str);       
                    } else if (inv_command == 2) {
                    	inverter[invNo].inv_v_current = atoi(str);       
                    } else if (inv_command == 3) {
                    	inverter[invNo].inv_w_current = atoi(str);       
                    } 
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[41];str[1]=rxbuff[42];str[2]=rxbuff[43];   
                    imInverterData[inv_command].power_inv_now = atoi(str);   

                    
//    sprintf(str,"%3d  ",imInverterData[inv_command].power_inv_now);
//    put_str(inv_command-1,0,str,1);
//sprintf(str,"%3d  ",inverter[0].power_inv_now);
//put_str(1,0,str,1);          

                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[50];str[1]=rxbuff[51];str[2]=rxbuff[52];  
                    imInverterData[inv_command].power_inv_day_total = atoi(str);  
                    
                                
                    //inverter[invNo].power_inv_day_total /= 10;            
                    
                    //memset(str,0,sizeof(str));  
                    //str[0]=rxbuff[70];str[1]=rxbuff[71];str[2]=rxbuff[72];str[3]=rxbuff[73];str[4]=rxbuff[74];str[5]=rxbuff[75];str[6]=rxbuff[76];
                                      
                                                  
                    
                    if (inv_command == 3) {        
    
                    	inverter[invNo].inverter_status[0] = imInverterData[1].inv_status;
                    	inverter[invNo].inverter_status[1] = imInverterData[2].inv_status;
                    	inverter[invNo].inverter_status[2] = imInverterData[3].inv_status;
                    	inverter[invNo].inverter_status[3] = 0;

                    	inverter[invNo].solar_cell_current = imInverterData[1].solar_cell_current + imInverterData[2].solar_cell_current + imInverterData[3].solar_cell_current; 
                    	inverter[invNo].power_inv_now = imInverterData[1].power_inv_now + imInverterData[2].power_inv_now + imInverterData[3].power_inv_now;  
                    	inverter[invNo].power_solar = imInverterData[1].power_solar + imInverterData[2].power_solar + imInverterData[3].power_solar;
                        inverter[invNo].power_inv_day_total = imInverterData[1].power_inv_day_total + imInverterData[2].power_inv_day_total + imInverterData[3].power_inv_day_total; 
                    	if (atol(str) > 0) {
                            inverter[invNo].power_inv_total = 0; //atol(str);
                        }     
                        inverter[invNo].power_inv_total = 0; //atol(str);       
                        inverter[invNo].power_inv_pf = 97;   
                        sendInverterCount[invNo] = 0;
                        buzzer_flag |= BUZZER_TIC;
                        //put_str(4,16,C_RXOK,1);        
                    sprintf(str,"RX-%01X",invNo+1);
                    put_str(4,16,str,1);   
                        rx_led_delay = 2500;
                    }  

                    rx_seq0 = 0;

                } else {
                	rx_seq0++;
                }
            }
            break;
            
		case 3:
        	rx_seq0++;
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



