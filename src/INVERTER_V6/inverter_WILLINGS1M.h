void sendInverterRead_Willings1M(void) {
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
        case 1:     
			//Inv-1:STATUS, PV, INV,GRID  (00, 3 byte)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 30 30 30 33 04 43 34
			//putchar0(0x05);   //0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x30);		//d
            putchar0(0x30);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x34);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;            
			imInvNo = 0x00;          
			inv_command = 0x00;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 2:
			//Inv-1:PV Volt,Curr,Kw (32, 3 byte)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 33 32 30 33 04 43 39
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x33);		//d
            putchar0(0x32);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x39);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x32;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 3:     
			//Inv-1:UT-1 (Vol)
            //05 30 31 72 53 42 30 37 25 4D 57 30 30 36 34 30 33 04 43 45
			//putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x36);		//d
            putchar0(0x34);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x45);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x64;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 4:     
			//Inv-1:UT-2 (Curr)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 36 37 30 33 04 44 31
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x36);		//d
            putchar0(0x37);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x44);		//BCC1
            putchar0(0x31);		//BCC2
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x67;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 5:     
			//Inv-1:UT-3 (Hz,Pf,Kw)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 37 30 30 33 04 43 42
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x30);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x42);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x70;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
        case 6:
			//Inv-1:DayTotal(kWh)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 37 37 30 32 04 44 31
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x37);		//r
            putchar0(0x30);		//偎
            putchar0(0x32);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x44);		//BCC1
            putchar0(0x31);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x77;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
        case 7:
			//Inv-1:Total (kWh)
			//05 30 31 72 53 42 30 37 25 4D 57 30 30 37 33 30 32 04 43 44
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x31);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x33);		//r
            putchar0(0x30);		//偎
            putchar0(0x32);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x44);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x00;          
			inv_command = 0x73;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
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
        case 11:     
			//Inv-1:STATUS, PV, INV,GRID  (00, 3 byte)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 30 30 30 33 04 43 35
			//putchar0(0x05);   //0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x30);		//d
            putchar0(0x30);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x35);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;            
			imInvNo = 0x01;          
			inv_command = 0x00;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 12:
			//Inv-1:PV Volt,Curr,Kw (32, 3 byte)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 33 32 30 33 04 43 41
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x33);		//d
            putchar0(0x32);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x41);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x32;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 13:     
			//Inv-1:UT-1 (Vol)
            //05 30 32 72 53 42 30 37 25 4D 57 30 30 36 34 30 33 04 43 46
			//putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x36);		//d
            putchar0(0x34);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x46);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x64;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 14:     
			//Inv-1:UT-2 (Curr)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 36 37 30 33 04 44 32
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x36);		//d
            putchar0(0x37);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x44);		//BCC1
            putchar0(0x32);		//BCC2
            TXEN=1;TXEN=1;       
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x67;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;         
        case 15:     
			//Inv-1:UT-3 (Hz,Pf,Kw)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 37 30 30 33 04 43 43
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x30);		//r
            putchar0(0x30);		//偎
            putchar0(0x33);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x43);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x70;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
        case 16:
			//Inv-1:DayTotal(kWh)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 37 37 30 32 04 44 32
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x37);		//r
            putchar0(0x30);		//偎
            putchar0(0x32);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x44);		//BCC1
            putchar0(0x32);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x77;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
        case 17:
			//Inv-1:Total (kWh)
			//05 30 32 72 53 42 30 37 25 4D 57 30 30 37 33 30 32 04 43 45
            //putchar0(0x05);	//0
            putchar0(0x30);		//I
            putchar0(0x32);		//D
            putchar0(0x72);		//r
            putchar0(0x53);		//S
            putchar0(0x42);		//B
            putchar0(0x30);		//0
            putchar0(0x37);		//7
            putchar0(0x25);		//%
            putchar0(0x4D);		//M
            putchar0(0x57);		//W
            putchar0(0x30);		//a
            putchar0(0x30);		//d
            putchar0(0x37);		//d
            putchar0(0x33);		//r
            putchar0(0x30);		//偎
            putchar0(0x32);		//熱
            putchar0(0x04);		//ETX
            putchar0(0x43);		//BCC1
            putchar0(0x45);		//BCC2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
			imInvNo = 0x01;          
			inv_command = 0x73;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            inverter_seq++;
            break;    
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





void rx0Control_Willings1M(void) {   
	char rxdata;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == 0x06) {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
				rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            }   
			break;        
        case 1:                      
        	//rcnt = 0; //ID
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x30) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;
        case 2:
        	//rcnt = 1; //ID
			rxbuff[rcnt++] = rxdata;
        	if ((rxdata == 0x31) || (rxdata == 0x32) || (rxdata == 0x33)){
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 3:
        	//rcnt = 2; //'r'
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x72) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 4:
        	//rcnt = 3;	//'S'
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x53) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;       
        case 5:
        	//rcnt = 4;	//'B'
			rxbuff[rcnt++] = rxdata;
        	if (rxdata == 0x42) {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;         
        case 6:
        	//rcnt = 5 ~~
			rxbuff[rcnt++] = rxdata;
			if (rxdata == 0x03)
			{
//sprintf(str,"rcnt:%02d  ",rcnt);
//put_str(0,0,str,1);
	            rx_seq0++;       
			}
            break;                 
        case 7:    
			rxbuff[rcnt++] = rxdata;
			rx_seq0++;       
			break;
        case 8:
			rxbuff[rcnt] = rxdata;
			//imInvNo = 0x00;          
			//inv_command = 0x73;
            chksum0 = 0;
            for(im=0;im<=(rcnt-2);im++) {
            	chksum0 += rxbuff[im];
            }       
            chksum0 &= 0x00ff;                   
            rchksum0 = HexStr_to_Uint(0,0,rxbuff[rcnt-1],rxbuff[rcnt]);
//sprintf(str,"%02X %02X ", chksum0, rchksum0);
//put_str(0,0,str,1);

            if (chksum0 == rchksum0) {

                switch(inv_command) {
                    case 0x00:	//STATUS
                        inverter[imInvNo].inverter_status[0] = HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]);            
                        inverter[imInvNo].inverter_status[1] = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);            
                        inverter[imInvNo].inverter_status[2] = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);            
                        inverter[imInvNo].inverter_status[3] = 0;               
                        break;
                    case 0x32:	//PV Volt,Curr,Kw (32, 3 byte) 			
                        inverter[imInvNo].solar_cell_voltage = HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]);         
                        inverter[imInvNo].solar_cell_current = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
						inverter[imInvNo].solar_cell_current /= 10;                                    
                        inverter[imInvNo].power_solar        = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);
                        break;
                    case 0x64:	//UT-1 Voltage (64, 3 byte)
                        inverter[imInvNo].inv_u_voltage = HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]); 
                        inverter[imInvNo].inv_v_voltage = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
                        inverter[imInvNo].inv_w_voltage = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);
                        break;
                    case 0x67:	//UT-1 Current (67, 3 byte)
                        inverter[imInvNo].inv_u_current = HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]); 
                        inverter[imInvNo].inv_v_current = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
                        inverter[imInvNo].inv_w_current = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);
                        inverter[imInvNo].inv_u_current /= 10; 
                        inverter[imInvNo].inv_v_current /= 10;
                        inverter[imInvNo].inv_w_current /= 10;
                        break;
                    case 0x70:	//UT-3 (Hz,Pf,Kw)			
                        inverter[imInvNo].inv_frequency = HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]); 
                        inverter[imInvNo].power_inv_pf = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
                        inverter[imInvNo].power_inv_now = HexStr_to_Uint(rxbuff[18],rxbuff[19],rxbuff[20],rxbuff[21]);
                        break;
                    case 0x77:	//DayTotal(kWh)   
                        lim[0]   = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
                        lim[0] <<= 16; 
                        lim[0]  += HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]);
                        inverter[imInvNo].power_inv_day_total = lim[0] / 100;                     
                        break;
                    case 0x73:	//Total (kWh)
                        inverter[imInvNo].power_inv_total     = HexStr_to_Uint(rxbuff[14],rxbuff[15],rxbuff[16],rxbuff[17]);
                        inverter[imInvNo].power_inv_total   <<= 16; 
                        inverter[imInvNo].power_inv_total    += HexStr_to_Uint(rxbuff[10],rxbuff[11],rxbuff[12],rxbuff[13]);
                        inverter[imInvNo].power_inv_total    /= 100;                     

                        sendInverterCount[0] = 0;
                        buzzer_flag |= BUZZER_TIC;
                                     
                        sprintf(str,"RX%02",imInvNo+1);
                        put_str(4,16,str,1);   
                        //put_str(4,16,C_RXOK,1);   
                        rx_led_delay = 2500;

                        break;
                }
            }
			rx_seq0 = 0;       
			break;

		default:
			rx_seq0 = 0;
			break;
	}
}
