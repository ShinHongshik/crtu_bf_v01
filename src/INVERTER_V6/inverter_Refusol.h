
void sendInverterRead_Refusol() {
    switch(inverter_seq) {
        case 0:
			if (sendInverterCount[invNo-1] < 100) {
            	sendInverterCount[invNo-1]++;
            }     
            invNo++;
            if (invNo > eeInverterCount) {
                invNo = 1;
            }              

            sprintf(str,"TX%02d",invNo);
            put_str(4,16,str,1);    
            rx_led_delay = 5000;             
            inverter_seq++;
            break;     
        case 1:     //01: (452h) 1106.0 AC(W) - 0x?452h
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x52); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 2:     //02: (0461h) 1121.0 UAC-1 (Volt)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x61); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 3:     //03: (461h) 1121.1 UAC-2 (Volt)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x61); 	//05
            putchar0(0x00); 	//06
            putchar0(0x01); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 4:     //04: (461h) 1121.02 UAC-3 (Volt)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x61); 	//05
            putchar0(0x00); 	//06
            putchar0(0x02); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         

		////////////////////////////////////////////
        case 5:     //05: (0x0475h)1141 IAC-1 (Ampear)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x64); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 6:     //06: 1141 IAC-2 (Ampear)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x64); 	//05
            putchar0(0x00); 	//06
            putchar0(0x01); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 7:     //07: 1141 IAC-2 (Ampear)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x64); 	//05
            putchar0(0x00); 	//06
            putchar0(0x02); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 8:     //08: (462h) 1122.0 FAC (Freq)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x62); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 9:     //09: (453h) 1107.0 PDC(W)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x53); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 10:     //10: (450h) 1104.0 UDC(V)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x50); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 11:     //11: (451h) 1105.0 IDC(A)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x51); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 12:     //12: (47Eh) 1150.0 DailyYield(0.1 kWh)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x7e); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 13:     //13: (1F5h) 501.0 Status
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x61); 	//04
            putchar0(0xf5); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 14:     //14: (47Fh) 1151.0 TotalYield (0.1 kWh)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x7f); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         
        case 15:     //15: (480h) 1152.0 OperatingHours (0.01h)
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x64); 	//04
            putchar0(0x80); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         

        case 16:     //16: (1F4h) 500.0 Error Code -   //2016/04/05 Insert
            //putchar0(0x02); //^     
            calBCC = 0x02;		//01
            putchar0(0x16); 	//02
            putchar0(invNo);	//03
            putchar0(0x61); 	//04
            putchar0(0xF4); 	//05
            putchar0(0x00); 	//06
            putchar0(0x00); 	//07
            putchar0(0x00); 	//08
            putchar0(0x00); 	//09
            putchar0(0x00); 	//10
            putchar0(0x00); 	//11
            putchar0(0x00); 	//12
            putchar0(0x00); 	//13
            putchar0(0x00); 	//14
            putchar0(0x00); 	//15
            putchar0(0x00); 	//16
            putchar0(0x00); 	//17
            putchar0(0x00); 	//18
            putchar0(0x00); 	//19
            putchar0(0x00); 	//20
            putchar0(0x00); 	//21
            putchar0(0x00); 	//22
            putchar0(0x00); 	//23
            putchar0(calBCC);
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            inverter_seq++;
            break;         

        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;     
            inverter_seq = 0;
            break;
        case 20:
        default:  
            inverter_seq = 0;
            break;
    }
}


//memset(rxbuff,0,sizeof(rxbuff));
//rx_seq0++;
//} else if (rxdata == 0x02) {  
//rx_seq0 = 200;

void rx0Control_Refusol(void) {   
	char rxdata;    
    char rxInverterNumber;  
    unsigned int rxCommand;
	rxdata = getchar0();      
	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == 0x02) {
				chksum0 = rxdata;       
                timeout0 = 500;    
                rx_seq0++;              
			}   
			break;        
        case 1:
        	chksum0 ^= rxdata; 
            if (rxdata == 0x16) {
				memset(rxbuff,0,sizeof(rxbuff));
                rcnt = 0;
                rx_seq0++;
            } else if (rxdata == 0xaa) {  
            	pc_delay = 20000;
            	rcnt = 0;
				rx_seq0 = 110;
            } else if (rxdata == 0xa5) {
            	pc_delay = 20000;
            	rcnt = 0;
				rx_seq0 = 120;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2:      
        	chksum0 ^= rxdata;
            rxbuff[rcnt++] = rxdata;
            if (rcnt == 21) {
                rx_seq0++;
            }
        	break;
        case 3:
        	if ((rxdata == chksum0) && ((rxbuff[1] & 0xf0) == 0x50)) {
	            rx_seq0 = 0;

            	rxInverterNumber = rxbuff[0]-1;
            	rxCommand = rxbuff[1];
                rxCommand <<= 8;
                rxCommand += rxbuff[2];
                rxCommand &= 0x0fff;  
				
                switch(rxCommand) {
                	case 0x0452:	//01: 1106.0 ACÀü·Â(W)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].power_inv_now = (unsigned int)uFloat.ff / 100;  
                    	break;
                	//case 0x0463:	//02: 1123.0 UAC (Volt)
                    case 0x0461:     //02: (0461)1121.0 UAC-1 (Volt)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];
                    	if (rxbuff[3] == 0) {                    
                    		inverter[rxInverterNumber].inv_u_voltage = (unsigned int)(uFloat.ff/1.4142*1.7325);
                        } else if (rxbuff[3] == 1) {  
                    		inverter[rxInverterNumber].inv_v_voltage = (unsigned int)(uFloat.ff/1.4142*1.7325); 
                        } else if (rxbuff[3] == 2) {  
	                    	inverter[rxInverterNumber].inv_w_voltage = (unsigned int)(uFloat.ff/1.4142*1.7325);
                        } 
                    	break;
                	//case 0x0464:	//03: 1124.0 IAC (Ampear)
			        case 0x0464:     //05: (0x0475)1141 IAC-1 (Ampear)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
//                    	if (rxbuff[3] == 0) {                    
//	                    	inverter[rxInverterNumber].inv_u_current = (unsigned int)(uFloat.ff * 10); 
//                        } else if (rxbuff[3] == 1) {  
//	                    	inverter[rxInverterNumber].inv_v_current = (unsigned int)(uFloat.ff * 10);
//                        } else if (rxbuff[3] == 2) {  
//	                    	inverter[rxInverterNumber].inv_w_current = (unsigned int)(uFloat.ff * 10);
//                        }
                    	if (rxbuff[3] == 0) {                    
	                    	inverter[rxInverterNumber].inv_u_current = (unsigned int)(uFloat.ff);// * 10); 
                        } else if (rxbuff[3] == 1) {  
	                    	inverter[rxInverterNumber].inv_v_current = (unsigned int)(uFloat.ff);// * 10);
                        } else if (rxbuff[3] == 2) {  
	                    	inverter[rxInverterNumber].inv_w_current = (unsigned int)(uFloat.ff);// * 10);
                        }
                    	break;
                	case 0x0462:	//04: 1122.0 FAC (Freq)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].inv_frequency = (unsigned int)(uFloat.ff * 10); 
                    	break;
                	case 0x0453:	//05: 1107.0 PDC(W)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].power_solar = (unsigned int)uFloat.ff / 100; 
                    	break;
                	case 0x0450:	//06: 1104.0 UDC(V)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].solar_cell_voltage = (unsigned int)uFloat.ff; 
                    	break;
                	case 0x0451:	//07: 1105.0 IDC(A)
                    	uFloat.cc[3] = rxbuff[5];                    
                    	uFloat.cc[2] = rxbuff[6];                    
                    	uFloat.cc[1] = rxbuff[7];                    
                    	uFloat.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].solar_cell_current = (unsigned int)(uFloat.ff);// * 10); 
                    	break;
                	case 0x047e:	//08: 1150.0 DailyYield(0.1 kWh)
                    	uLong.cc[3] = rxbuff[5];                    
                    	uLong.cc[2] = rxbuff[6];                    
                    	uLong.cc[1] = rxbuff[7];                    
                    	uLong.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].power_inv_day_total = (unsigned int)uLong.ff / 10;
            
//sprintf(str," dTOT:%04d ", inverter[rxInverterNumber].power_inv_day_total);
//put_str(0,10,str,1);   
                    	break;
                	case 0x01f4:	//09: 500.0 Error Code
                    	uLong.cc[3] = rxbuff[5];                    
                    	uLong.cc[2] = rxbuff[6];                    
                    	uLong.cc[1] = rxbuff[7];                    
                    	uLong.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]); 
                    	inverter[rxInverterNumber].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]); 
                    	inverter[rxInverterNumber].inverter_status[3] = Bytes_to_Uint(rxbuff[9],rxbuff[10]); 
                    	break;
                	case 0x01f5:	//09: 501.0 Status
                    	uLong.cc[3] = rxbuff[5];                    
                    	uLong.cc[2] = rxbuff[6];                    
                    	uLong.cc[1] = rxbuff[7];                    
                    	uLong.cc[0] = rxbuff[8];                    
                    	inverter[rxInverterNumber].inverter_status[0] = (unsigned int)uLong.ff; 
                    	break;
                	case 0x047f:	//10: 1151.0 TotalYield (0.1 kWh)
                    	uLong.cc[3] = rxbuff[5];                    
                    	uLong.cc[2] = rxbuff[6];                    
                    	uLong.cc[1] = rxbuff[7];                    
                    	uLong.cc[0] = rxbuff[8];                        

                    	inverter[rxInverterNumber].power_inv_total = (unsigned long int)uLong.ff/10; 
//                        switch(modelInverter) {  
//                            case MODEL_INVERTER_LS20K:	//0x00
//		                    	inverter[rxInverterNumber].power_inv_total = (unsigned long int)uLong.ff/10; 
//                                break;    
//                            case MODEL_INVERTER_REFUSOL:	//0x00
//		                    	inverter[rxInverterNumber].power_inv_total = (unsigned long int)uLong.ff; 
//                                break;    
//                        }                            
                        inverter[rxInverterNumber].power_inv_pf = 950;
                		buzzer_flag |= BUZZER_TIC;
						sprintf(str,"RX%02d",rxInverterNumber+1);
						put_str(4,16,str,1);   
//                		put_str(4,16,C_RXOK,1);   
                		rx_led_delay = 5000;
                    	break;
                }

                sendInverterCount[rxInverterNumber] = 0;
            }   
            rx_seq0 = 0;
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
