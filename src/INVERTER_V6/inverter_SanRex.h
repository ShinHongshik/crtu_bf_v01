
//unsigned int HexStr_to_Uint(unsigned char c3, unsigned char c2, unsigned char c1, unsigned char c0) {
//	unsigned int uint1;
//    if ((c3 > 0x2f) && (c3 < 0x3A)) {
//        uint1 = (unsigned int)(c3-0x30) << 12;             
//    } else if ((c3 > 0x60) && (c3 < 0x67)) {
//        uint1 = (unsigned int)(c3-0x57) << 12;             
//    } else {
//        uint1 = 0;
//    }
//
//    if ((c2 > 0x2f) && (c2 < 0x3A)) {
//        uint1 += (unsigned int)(c2-0x30) << 8;             
//    } else if ((c2 > 0x60) && (c2 < 0x67)) {
//        uint1 += (unsigned int)(c2-0x57) << 8;             
//    }
//
//    if ((c1 > 0x2f) && (c1 < 0x3A)) {
//        uint1 += (unsigned int)(c1-0x30) << 4;             
//    } else if ((c1 > 0x60) && (c1 < 0x67)) {
//        uint1 += (unsigned int)(c1-0x57) << 4;             
//    }
//
//    if ((c0 > 0x2f) && (c0 < 0x3A)) {
//        uint1 += (unsigned int)(c0-0x30);             
//    } else if ((c0 > 0x60) && (c0 < 0x67)) {
//        uint1 += (unsigned int)(c0-0x57);             
//    }        
//    
//    return uint1;
//}  
//
//
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



void sendInverterRead_SanRex(void) {
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
        case 1:     //Inv-1:Call  4d 4e 20 30 31 0d 
            //putchar0(0x4d);   //M
            putchar0(0x4e);		//N
            putchar0(0x20);		//SP
            putchar0(0x30);		//0
            putchar0(0x31);		//1
            putchar0(0x0d);		//CR
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x4d);  
#else  
			UDR0 = 0x4d ;  
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

        case 11:     //Inv-2:Call
            //putchar0(0x4d);   //M
            putchar0(0x4e);		//N
            putchar0(0x20);		//SP
            putchar0(0x30);		//0
            putchar0(0x32);		//2
            putchar0(0x0d);		//CR
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x4d);  
#else  
			UDR0 = 0x4d ;  
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
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}





void rx0Control_SanRex(void) {   
	char rxdata;           
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == 'M') {
				chksum0 = rxdata;
                rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
				rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            }   
			break;        
        case 1:                      
            chksum0 ^= rxdata;
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 'N') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;
        case 2:
            chksum0 ^= rxdata;
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x20) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;
        case 3:
            chksum0 ^= rxdata;
			rxbuff[rcnt++] = rxdata;
        	if (rcnt == 88) {
            	rx_seq0++;
            }               
            break;      
        case 4:
			rxbuff[rcnt++] = rxdata;
            rx_seq0++;
            break;       
        case 5:
			rxbuff[rcnt++] = rxdata;
            rx_seq0++;
            break;       
//00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//4d 4e 20 30 32 44 41 2c 30 31 46 46 2c 30 34 36 30 2c 30 30 36 37 2c 35 31 36 31 2c 30 37 39 44 2c 46 45 30 43 2c 30 30 30 30 2c 30 30 30 30 2c 30 32 35 38 20 30 30 30 31 2c 31 30 31 41 2c 30 32 44 39 2c 30 31 46 46 2c 31 32 46 37 2c 30 34 36 32 2c 30 30 30 32 2c 37 45 0d 
//M  N  SP IAC--------    PAC--------    IDC--------    INVERTER_TOTAL------------    Day-Total--    Temp-------    Ratation---    -----------    Frequency--    Inv-NO-----    VAC--------     IAC-------    PAC--------    VDC--------    IDC--------    STAT-------    BCC   CRs
            
        case 6:
            if (rxdata == 0x0d) {            
                rchksum0 = HexStr_to_Uint(0,0,rxbuff[88],rxbuff[89]);
                if (1) { //(chksum0 == rchksum0) {
                    invNo = rxbuff[56] - 0x31;
                
                	inverter[invNo].solar_cell_voltage = HexStr_to_Uint(rxbuff[73], rxbuff[74], rxbuff[75], rxbuff[76]) / 10;            
					inverter[invNo].solar_cell_current = HexStr_to_Uint(rxbuff[78], rxbuff[79], rxbuff[80], rxbuff[81]) / 10;            
                	inverter[invNo].power_solar        = (inverter[invNo].solar_cell_voltage /10) * (inverter[invNo].solar_cell_current / 10);

                	inverter[invNo].inv_u_voltage = HexStr_to_Uint(rxbuff[58],rxbuff[59],rxbuff[60],rxbuff[61]) / 10; 
                	inverter[invNo].inv_v_voltage = inverter[invNo].inv_u_voltage; 
                	inverter[invNo].inv_w_voltage = inverter[invNo].inv_u_voltage;
                	inverter[invNo].inv_u_current = HexStr_to_Uint(rxbuff[3],rxbuff[4],rxbuff[5],rxbuff[6]) / 10;
                	inverter[invNo].inv_v_current = inverter[invNo].inv_u_current;
                	inverter[invNo].inv_w_current = inverter[invNo].inv_u_current;
                    inverter[invNo].inv_frequency = HexStr_to_Uint(rxbuff[48],rxbuff[49],rxbuff[50],rxbuff[51]);


					inverter[invNo].inverter_status[0] = HexStr_to_Uint(rxbuff[83], rxbuff[84], rxbuff[85], rxbuff[86]);            
					inverter[invNo].inverter_status[1] = 0;            
					inverter[invNo].inverter_status[2] = 0;           
					inverter[invNo].inverter_status[3] = 0;            

                	inverter[invNo].power_inv_total     = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
					inverter[invNo].power_inv_total /= 10;                    
                	inverter[invNo].power_inv_now       = HexStr_to_Uint(rxbuff[8],rxbuff[9],rxbuff[10],rxbuff[11]);
                	//inverter[rxbuff[1]-0x31].power_inv_max       = HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]);
                	inverter[invNo].power_inv_day_total = HexStr_to_Uint(rxbuff[28],rxbuff[29],rxbuff[30],rxbuff[31]) / 10;
                    inverter[invNo].power_inv_pf        = 920;

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;                    
                    
                    
//	                sprintf(str,"ITOT:%c%c%c%c, %04X  ",rxbuff[58],rxbuff[59],rxbuff[60],rxbuff[61],HexStr_to_Uint(rxbuff[23],rxbuff[24],rxbuff[25],rxbuff[26]));
//    	            put_str(0,0,str,1);   

	                sprintf(str,"RX-%01d",invNo+1);
    	            put_str(4,16,str,1);   
                    //put_str(4,16,C_RXOK,1);   
					rx_led_delay = 2500;     
                    
                    
//    LCD_initialize();		
//    for(im=0;im<10;im++) {
//    	sprintf(str,"%02X", rxbuff[im+0]);
//        put_str(0,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+10]);
//        put_str(1,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+20]);
//        put_str(2,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+30]);
//        put_str(3,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+40]);
//        put_str(4,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+50]);
//        put_str(5,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+60]);
//        put_str(6,im*2,str,1);
//    	sprintf(str,"%02X", rxbuff[im+70]);
//        put_str(7,im*2,str,1);
//    }
//	while(1) {
//    	#asm("wdr")
//    }


                }
            }
            rx_seq0 = 0;       
        	break;



		default:
			rx_seq0 = 0;
			break;
	}
}
