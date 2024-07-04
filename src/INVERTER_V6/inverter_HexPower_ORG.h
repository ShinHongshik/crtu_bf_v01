
#define ENQ				0x06
#define EOT				0x04

unsigned int HexStr_to_Uint(char c3, char c2, char c1, char c0) {
	unsigned int uint1;
    if ((c3 > 0x30) && (c3 < 0x3A)) {
        uint1 = (unsigned int)(c3-0x30) << 12;             
    } else if ((c3 > 0x40) && (c3 < 0x47)) {
        uint1 = (unsigned int)(c3-0x37) << 12;             
    } else if ((c3 > 0x60) && (c3 < 0x67)) {
        uint1 = (unsigned int)(c3-0x57) << 12;             
    } else {
        uint1 = 0;
    }

    if ((c2 > 0x30) && (c2 < 0x3A)) {
        uint1 += (unsigned int)(c2-0x30) << 8;             
    } else if ((c2 > 0x40) && (c2 < 0x47)) {
        uint1 += (unsigned int)(c2-0x37) << 8;             
    } else if ((c2 > 0x60) && (c2 < 0x67)) {
        uint1 += (unsigned int)(c2-0x57) << 8;             
    }

    if ((c1 > 0x30) && (c1 < 0x3A)) {
        uint1 += (unsigned int)(c1-0x30) << 4;             
    } else if ((c1 > 0x40) && (c1 < 0x47)) {
        uint1 += (unsigned int)(c1-0x37) << 4;             
    } else if ((c1 > 0x60) && (c1 < 0x67)) {
        uint1 += (unsigned int)(c1-0x57) << 4;             
    }

    if ((c0 > 0x30) && (c0 < 0x3A)) {
        uint1 += (unsigned int)(c0-0x30);             
    } else if ((c0 > 0x40) && (c0 < 0x47)) {
        uint1 += (unsigned int)(c0-0x37);             
    } else if ((c0 > 0x60) && (c0 < 0x67)) {
        uint1 += (unsigned int)(c0-0x57);             
    }        
    
    return uint1;
}  


//unsigned char HexStr_to_Byte(unsigned char c1, unsigned char c0) {
//	unsigned char b8;
//    if ((c1 > 0x2f) && (c1 < 0x3A)) {
//        b8 = (c1-0x30) << 4;             
//    } else if ((c1 > 0x60) && (c1 < 0x67)) {
//        b8 = (c1-0x57) << 4;             
//    } else {
//    	b8 = 0;
//    }
//
//    if ((c0 > 0x2f) && (c0 < 0x3A)) {
//        b8 += (c0-0x30);             
//    } else if ((c0 > 0x60) && (c0 < 0x67)) {
//        b8 += (c0-0x57);             
//    }        
//    
//    return b8;
//}  



void sendInverterRead_HexPower(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }                            
            put_str(4,16,"TX-1",1);   
            rx_led_delay = 2500;
            break;     
        case 1:     //Inv-1:Fault Infomation
            //putchar0(0x05);   //0
            putchar0(0x30);		//1
            putchar0(0x31);		//2
            putchar0(0x52);		//3
            putchar0(0x30);		//4
            putchar0(0x30);		//5
            putchar0(0x30);		//6
            putchar0(0x34);		//10
            putchar0(0x30);		//11
            putchar0(0x34);		//12
            putchar0(0x30);		//13
            putchar0(0x31);		//14
            putchar0(0x64);		//15
            putchar0(0x62);		//16
            putchar0(0x04);		//17
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 2:     //Inv-1:Solar Cell Voltage / current
            //putchar0(0x05);	//0
            putchar0(0x30);		//1
            putchar0(0x31);		//2
            putchar0(0x52);		//3
            putchar0(0x30);		//4
            putchar0(0x30);		//5
            putchar0(0x32);		//6
            putchar0(0x30);		//20
            putchar0(0x30);		//21
            putchar0(0x32);		//22
            putchar0(0x30);		//23
            putchar0(0x31);		//24
            putchar0(0x64);		//25
            putchar0(0x37);		//26
            putchar0(0x04);		//27
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 3:     //Inv-1:Inverter voltage / current / frequency
            //putchar0(0x05);	//0
            putchar0(0x30);		//1
            putchar0(0x31);		//2
            putchar0(0x52);		//3
            putchar0(0x30);		//4
            putchar0(0x30);		//5
            putchar0(0x33);		//6
            putchar0(0x30);		//30
            putchar0(0x30);		//31
            putchar0(0x37);		//32
            putchar0(0x30);		//33
            putchar0(0x31);		//34
            putchar0(0x64);		//35
            putchar0(0x64);		//36
            putchar0(0x04);		//37
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 4:     //Inv-1:Utility Line voltage / current /frequency
            //putchar0(0x05);	//0
            putchar0(0x30);		//1
            putchar0(0x31);		//2
            putchar0(0x52);		//3
            putchar0(0x30);		//4
            putchar0(0x30);		//5
            putchar0(0x35);		//6
            putchar0(0x30);		//50
            putchar0(0x30);		//51
            putchar0(0x37);		//52
            putchar0(0x30);		//53
            putchar0(0x31);		//54
            putchar0(0x64);		//55
            putchar0(0x66);		//56
            putchar0(0x04);		//57
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 5:     //Inv-1:Solar and INV power
            //putchar0(0x05);	//0
            putchar0(0x30);		//1
            putchar0(0x31);		//2
            putchar0(0x52);		//3
            putchar0(0x30);		//4
            putchar0(0x30);		//5
            putchar0(0x36);		//6
            putchar0(0x30);		//60
            putchar0(0x30);		//61
            putchar0(0x38);		//62
            putchar0(0x30);		//63
            putchar0(0x31);		//64
            putchar0(0x65);		//65
            putchar0(0x31);		//66
            putchar0(0x04);		//67
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
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
                put_str(4,16,"TX-1",1);   
                rx_led_delay = 2500;
            	inverter_seq++;
            } else {
            	inverter_seq = 0;
            }
            break;     

        case 11:     //Inv-2:Fault Infomation
            //putchar0(0x05);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x52);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x34);
            putchar0(0x30);
            putchar0(0x34);
            putchar0(0x30);
            putchar0(0x31);
            putchar0(0x64);
            putchar0(0x63);
            putchar0(0x04);
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 12:     //Inv-2:Solar Cell Voltage / current
            //putchar0(0x05);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x52);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x30);
            putchar0(0x31);
            putchar0(0x64);
            putchar0(0x38);
            putchar0(0x04);
            TXEN=1;TXEN=1;        
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 13:     //Inv-2:Inverter voltage / current / frequency
            //putchar0(0x05);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x52);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x33);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x37);
            putchar0(0x30);
            putchar0(0x31);
            putchar0(0x64);
            putchar0(0x65);
            putchar0(0x04);
            TXEN=1;TXEN=1;         
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 14:     //Inv-2:Utility Line voltage / current /frequency
            //putchar0(0x05);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x52);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x35);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x37);
            putchar0(0x30);
            putchar0(0x31);
            putchar0(0x64);
            putchar0(0x67);
            putchar0(0x04);
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 15:     //Inv-2:Solar and INV power
            //putchar0(0x05);
            putchar0(0x30);
            putchar0(0x32);
            putchar0(0x52);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x36);
            putchar0(0x30);
            putchar0(0x30);
            putchar0(0x38);
            putchar0(0x30);
            putchar0(0x31);
            putchar0(0x65);
            putchar0(0x32);
            putchar0(0x04);
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 16:
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
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}





void rx0Control_HexPower(void) {   
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
        	if (rxdata == 0x30) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;
        case 2:
        	//rcnt = 1;
			rxbuff[rcnt++] = rxdata;
        	if ((rxdata == 0x31) || (rxdata == 0x32) || (rxdata == 0x33)){
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
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
                //Inverter voltage /current / frequency
                case 0x0030:
		            rx_seq0 = 30;       
                	break;  
                //Utility Line voltage / current / frequency
                case 0x0050:
		            rx_seq0 = 50;       
                	break; 
                //Solar and INV power / pf
                case 0x0060:
		            rx_seq0 = 60;       
                	break;  
                //Solar Panel - Environment Measurement
				case 0x0070:
		            rx_seq0 = 70;       
                	break;  
                // System Information - Phase, Capacity, Serial Number
                case 0x01e0:
		            rx_seq0 = 80;       
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
					inverter[rxbuff[1]-0x31].inverter_status[0] = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
					inverter[rxbuff[1]-0x31].inverter_status[1] = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);            
					inverter[rxbuff[1]-0x31].inverter_status[2] = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);            
					inverter[rxbuff[1]-0x31].inverter_status[3] = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);            
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
                	inverter[rxbuff[1]-0x31].solar_cell_voltage = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
					inverter[rxbuff[1]-0x31].solar_cell_current = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);            
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;
		//HexPowerInverter : Inverter voltage /current / frequency (28byte)            
        case 30:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=34;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38]);
                if (chksum0 == rchksum0) {
                	inverter[rxbuff[1]-0x31].inv_u_voltage = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]); 
                	inverter[rxbuff[1]-0x31].inv_v_voltage = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]); 
                	inverter[rxbuff[1]-0x31].inv_w_voltage = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);
                	inverter[rxbuff[1]-0x31].inv_u_current = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
                	inverter[rxbuff[1]-0x31].inv_v_current = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                	inverter[rxbuff[1]-0x31].inv_w_current = HexStr_to_Uint(rxbuff[27],rxbuff[28],rxbuff[29],rxbuff[30]);
                    inverter[rxbuff[1]-0x31].inv_frequency = HexStr_to_Uint(rxbuff[31],rxbuff[32],rxbuff[33],rxbuff[34]);
//					sprintf(str,"%d",inverter[rxbuff[1]-0x31].inv_u_current);
//                    put_str(0,0,str,2);                    
                    
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
//                	inverter[rxbuff[1]-0x31].util_rs_voltage = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]); 
//                	inverter[rxbuff[1]-0x31].util_st_voltage = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]); 
//                	inverter[rxbuff[1]-0x31].util_tr_voltage = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);
//                	inverter[rxbuff[1]-0x31].util_r_current  = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
//                	inverter[rxbuff[1]-0x31].util_s_current  = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
//                	inverter[rxbuff[1]-0x31].util_t_current  = HexStr_to_Uint(rxbuff[27],rxbuff[28],rxbuff[29],rxbuff[30]);
//                    inverter[rxbuff[1]-0x31].util_frequency  = HexStr_to_Uint(rxbuff[31],rxbuff[32],rxbuff[33],rxbuff[34]); 
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
                	inverter[rxbuff[1]-0x31].power_solar         = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]); 
                	inverter[rxbuff[1]-0x31].power_inv_total     = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);
                    inverter[rxbuff[1]-0x31].power_inv_total   <<= 16; 
                	inverter[rxbuff[1]-0x31].power_inv_total    += HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);
                	inverter[rxbuff[1]-0x31].power_inv_now       = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
                	//inverter[rxbuff[1]-0x31].power_inv_max       = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                	inverter[rxbuff[1]-0x31].power_inv_day_total = HexStr_to_Uint(rxbuff[27],rxbuff[28],rxbuff[29],rxbuff[30]);
                    inverter[rxbuff[1]-0x31].power_inv_pf        = HexStr_to_Uint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38]);

	                sendInverterCount[0] = 0;
					buzzer_flag |= BUZZER_TIC;

	                sprintf(str,"RX-%01d",rxbuff[1]-0x30);
    	            put_str(4,16,str,1);   
                    //put_str(4,16,C_RXOK,1);   
					rx_led_delay = 2500;
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;
		//HexPowerInverter : Solar Panel - Environment Measurement, (16byte)           
        case 70:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=22;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                if (chksum0 == rchksum0) {
//                	inverter[rxbuff[1]-0x31].t_radiation        = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
//                	inverter[rxbuff[1]-0x31].h_radiation        = HexStr_to_Uint(rxbuff[11],rxbuff[12],rxbuff[13],rxbuff[14]);            
//                	inverter[rxbuff[1]-0x31].out_temperature    = HexStr_to_Uint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18]);            
//                	inverter[rxbuff[1]-0x31].module_temperature = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);            
                }
                rx_seq0 = 0;       
            } else {
				rxbuff[rcnt++] = rxdata;
            }
        	break;            
		//HexPowerInverter : System Information - Phase, Capacity, Serial Number (12byte)            
        case 80:
            if (rxdata == EOT) {            
            	chksum0 = 0;
            	for(im=0;im<=18;im++) {
                	chksum0 += rxbuff[im];
                }                          
                rchksum0 = HexStr_to_Uint(rxbuff[19],rxbuff[20],rxbuff[21],rxbuff[22]);
                if (chksum0 == rchksum0) {
//                	inverter[rxbuff[1]-0x31].inv_phase = HexStr_to_Uint(rxbuff[7], rxbuff[8], rxbuff[9], rxbuff[10]);            
//					inverter[rxbuff[1]-0x31].inv_year  = HexStr_to_Byte(rxbuff[11],rxbuff[12]);
//					inverter[rxbuff[1]-0x31].inv_month = HexStr_to_Byte(rxbuff[13],rxbuff[14]);            
//                	inverter[rxbuff[1]-0x31].inv_serial = HexStr_to_Uint(rxbuff[15], rxbuff[16], rxbuff[17], rxbuff[18]);
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
