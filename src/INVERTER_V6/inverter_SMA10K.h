
void sendInverterRead_SMA10K(void) {  
    unsigned char crcXor;
    char sendBuff[10];   
    
    switch(inverter_seq) {

//Inv-1: RTU Master request frame  
		case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:
			rx_seq0 = 0; 
			
			imInvNo = 1;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-1");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
		
//Inv-2: RTU Master request frame  
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
			rx_seq0 = 0; 
            			
			imInvNo = 2;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 7:
        case 8:
        case 9:
        	inverter_seq++;
            break;

//Inv-3: RTU Master request frame  			
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
			rx_seq0 = 0; 
            			
			imInvNo = 3;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-3");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 12:
        case 13:
        case 14:

//Inv-4: RTU Master request frame  
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
			rx_seq0 = 0; 
     
			imInvNo = 4;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-4");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 17:
        case 18:
        case 19:
        	inverter_seq++;
            break;
			
//Inv-5: RTU Master request frame  			
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
			rx_seq0 = 0; 
            
			imInvNo = 5;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-5");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 22:
        case 23:
        case 24:

//Inv-6: RTU Master request frame  		
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
			rx_seq0 = 0; 
            		
			imInvNo = 6;
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-6");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 27:
        case 28:
        case 29:
        	inverter_seq++;
            break;
			
//Inv-7: RTU Master request frame  			
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
			rx_seq0 = 0; 
            		
			imInvNo = 7;	
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-7");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 32:
        case 33:
        case 34:

//Inv-8: RTU Master request frame 		
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
			rx_seq0 = 0; 
            	
			imInvNo = 8;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-8");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 37:
        case 38:
        case 39:
        	inverter_seq++;
            break;

//Inv-9: RTU Master request frame  			
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
			rx_seq0 = 0; 
            	
			imInvNo = 9;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX-9");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 42:
        case 43:
        case 44:

//Inv-10: RTU Master request frame  		
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
			rx_seq0 = 0; 
            	
			imInvNo = 10;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX10");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 47:
        case 48:
        case 49:
        	inverter_seq++;
            break;
			
//Inv-11: RTU Master request frame			
		case 50:
        	if (eeInverterCount > 10) { 
                if (sendInverterCount[10] < 100) {
                    sendInverterCount[01]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                   
        case 51:       
			rx_seq0 = 0; 
            	
			imInvNo = 11;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX11");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 52:
        case 53:
        case 54:

//Inv-12: RTU Master request frame  		
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
        case 56:     
			rx_seq0 = 0; 
            
			imInvNo = 12;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX12");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 57:
        case 58:
        case 59:
        	inverter_seq++;
            break;
			
//Inv-13: RTU Master request frame  
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
        case 61:     
			rx_seq0 = 0; 
            
			imInvNo = 13;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX13");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 62:
        case 63:
        case 64:

//Inv-14: RTU Master request frame 		
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
        case 66:      
			rx_seq0 = 0; 
            
			imInvNo = 14;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX14");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 67:
        case 68:
        case 69:
        	inverter_seq++;
            break;
			
//Inv-15: RTU Master request frame  			
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
        case 71:     
			rx_seq0 = 0; 
            
			imInvNo = 15;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX15");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 72:
        case 73:
        case 74:

//Inv-16: RTU Master request frame		
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
        case 76:       
			rx_seq0 = 0; 
            
			imInvNo = 16;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX16");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 77:
        case 78:
        case 79:
        	inverter_seq++;
            break;
			
//Inv-17: RTU Master request frame  			
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
        case 81:     
			rx_seq0 = 0; 
            
			imInvNo = 17;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX17");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 82:
        case 83:
        case 84:

//Inv-18: RTU Master request frame  		
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
        case 86:     
			rx_seq0 = 0; 
            
			imInvNo = 18;			
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX18");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;           
		case 87:
        case 88:
        case 89:
        	inverter_seq++;
            break;
			
//Inv-19: RTU Master request frame  			
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
        case 91:     
			rx_seq0 = 0; 
            	
			imInvNo = 19;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX19");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
            inverter_seq++;             
            break;         
        case 92:
        case 93:
        case 94:

//Inv-20: RTU Master request frame  
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
        case 96:     
			rx_seq0 = 0; 
            	
			imInvNo = 20;		
			sendBuff[0] = 0x02;	//STX 1
			sendBuff[1] = 0x55;	//STX 2
            sendBuff[2] = imInvNo; //INV-NO
            sendBuff[3] = 0xAA; //ETX 1 
            sendBuff[4] = 0x03; //ETX 2

			crcXor = sendBuff[0];
			crcXor ^= sendBuff[1];
			crcXor ^= sendBuff[2];
			crcXor ^= sendBuff[3];
			crcXor ^= sendBuff[4];
			
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]);
            putchar0(sendBuff[3]);
            putchar0(sendBuff[4]);
            putchar0(crcXor);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif        
            sprintf(str,"TX20");     
            put_str(4,16,str,1);   
            rx_led_delay = 1500;
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


void rx0Control_SMA10K(void) {   
	char rxdata;   
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if (rxdata == 0x02) {
				chksum0 = rxdata;
                timeout0 = 250;
            	rx_seq0++;
			}
			break;
		case 1:
			chksum0 ^= rxdata;
			if (rxdata == 0x55)
			{
            	rx_seq0++;
			} else {
            	rx_seq0 = 0;
			}
			break;
		case 2:
			chksum0 ^= rxdata;
			imInvNo = rxdata;		
			rcnt = 0;           
			memset(rxbuff,0,sizeof(rxbuff));
			rxbuff[rcnt++] = rxdata;
			rx_seq0++;
			break;
		case 3:
			chksum0 ^= rxdata;
			rxbuff[rcnt++] = rxdata;
			if (rcnt == 20) {
				rx_seq0++;
			}
			break;
		case 4:
			chksum0 ^= rxdata;
			if (rxdata == 0xAA) {
				rx_seq0++;
			} else {
            	rx_seq0 = 0;
			}
			break;
		case 5:
			chksum0 ^= rxdata;
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
            	rx_seq0 = 0;
			}
			break;
		case 6:      
//				sprintf(str,"CRC:%02X,%02X  ",chksum0,rxdata);
//				put_str(0,0,str,1);   
			if (chksum0 == rxdata) {
				invNo = imInvNo - 1;
				inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[1],rxbuff[2]);
				inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[3],rxbuff[4]);            
				inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[5],rxbuff[6]); 
				inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[7],rxbuff[8]); 
				inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[7],rxbuff[8]); 
				inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
				inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
				inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
				inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
				inverter[invNo].power_inv_now      = Bytes_to_Uint(rxbuff[11],rxbuff[12]);  
				inverter[invNo].inverter_status[0] = rxbuff[13];
				inverter[invNo].inv_frequency       = 600;
				//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
				inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[14],rxbuff[15]);
				inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[16],rxbuff[17]);
				inverter[invNo].power_inv_total   <<= 16; 
				inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[18],rxbuff[19]); 
				
		
				// inverter[invNo].solar_cell_voltage  /= 10;
				// inverter[invNo].solar_cell_current  /= 10;            
				// inverter[invNo].inv_u_voltage     /= 10; 
				// inverter[invNo].inv_v_voltage     /= 10; 
				// inverter[invNo].inv_w_voltage     /= 10;
				// inverter[invNo].inv_u_current      /= 10;
				// inverter[invNo].inv_v_current      /= 10;
				// inverter[invNo].inv_w_current      /= 10;
				// inverter[invNo].power_inv_day_total /= 10;

				sendInverterCount[invNo] = 0;
				buzzer_flag |= BUZZER_TIC;
				sprintf(str,"RX%02d",invNo+1);
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
