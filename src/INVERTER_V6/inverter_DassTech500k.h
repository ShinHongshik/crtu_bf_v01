
void sendInverterRead_DassTech(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;

                sprintf(str,"TX-%d",1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;                
            }
            break;     
        case 1:     //Inv-1: ^P000MOD
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 2:     //Inv-1: ^P000ST1   
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 3:     //Inv-1: ^P000ST2 
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 4:     //Inv-1: ^P000ST3  
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 5:     //Inv-1: ^P000ST4  
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 6:     //Inv-1: ^P000ST6    
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 7:
        case 8:
        case 9:
            inverter_seq++;
            break; 
            
            
        //// Inv-2 ////////////////////////////////////////////////////       
        case 10:  
        	if (eeInverterCount > 1) {  
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;

                    sprintf(str,"TX-%d",2);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;                

                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 11:     //Inv-2: ^P001MOD   
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 12:     //Inv-2: ^P001ST1     
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 13:     //Inv-2: ^P001ST2      
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 14:     //Inv-2: ^P001ST3    
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 15:     //Inv-2: ^P001ST4    
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 16:     //Inv-2: ^P001ST6      
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 17:
        case 18:
        case 19:
            inverter_seq++;
            break;                    
            
            
        //// Inv-3 ////////////////////////////////////////////////////       
        case 20:  
        	if (eeInverterCount > 2) {  
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;

                    sprintf(str,"TX-%d",3);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;                

                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 21:     //Inv-3: ^P002MOD   
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 22:     //Inv-3: ^P002ST1     
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 23:     //Inv-3: ^P002ST2      
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 24:     //Inv-3: ^P002ST3    
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 25:     //Inv-3: ^P002ST4    
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 26:     //Inv-3: ^P002ST6      
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 27:
        case 28:
        case 29:
            inverter_seq++;
            break;                    
            

        //// Inv-4 ////////////////////////////////////////////////////       
        case 30:  
        	if (eeInverterCount > 3) {  
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;

                    sprintf(str,"TX-%d",4);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;                

                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 31:     //Inv-4: ^P003MOD   
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 32:     //Inv-4: ^P003ST1     
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 33:     //Inv-4: ^P003ST2      
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 34:     //Inv-4: ^P003ST3    
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 35:     //Inv-4: ^P003ST4    
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 36:     //Inv-4: ^P003ST6      
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;                    
            

        //// Inv-5 ////////////////////////////////////////////////////       
        case 40:  
        	if (eeInverterCount > 4) {  
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;

                    sprintf(str,"TX-%d",5);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;                

                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 41:     //Inv-5: ^P004MOD   
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 42:     //Inv-5: ^P004ST1     
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 43:     //Inv-5: ^P004ST2      
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 44:     //Inv-5: ^P004ST3    
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 45:     //Inv-5: ^P004ST4    
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 46:     //Inv-5: ^P004ST6      
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;                    
            
                                    

        //// Inv-6 ////////////////////////////////////////////////////       
        case 50:  
        	if (eeInverterCount > 5) {  
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;

                    sprintf(str,"TX-%d",6);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;                

                }
            timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 51:     //Inv-6: ^P005MOD   
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x4D); //M
            putchar0(0x4F); //O
            putchar0(0x44); //D
            TXEN=1;TXEN=1;  
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 52:     //Inv-6: ^P005ST1     
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x31); //1
            TXEN=1;TXEN=1;    
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 53:     //Inv-6: ^P005ST2      
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x32); //2
            TXEN=1;TXEN=1;      
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 54:     //Inv-6: ^P005ST3    
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x33); //3
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 55:     //Inv-6: ^P005ST4    
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x34); //4
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 56:     //Inv-6: ^P005ST6      
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //6
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 57:
        case 58:
        case 59:
            inverter_seq++;
            break;                    
            
        case 60:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_DassTech1(void) {   
	char rxdata;
	rxdata = getchar0();

	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == '^') {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                timeout0 = 250;
            	rx_seq0++;
            } else if (rxdata == 0x02) {  
                timeout0 = 250;
				rx_seq0 = 200;
			}   
			break;        
        case 1: 
            if (rxdata == 'D') {
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2:
            switch(rxdata) {
                case '0':                              
                    rx_seq0++;
                    break;
                case '1':                              
                    rx_seq0 = 10;
                    break;
                case '2':                              
                    rx_seq0 = 20;
                    break;
                case '3':                              
                    rx_seq0 = 30;
                    break;
                case '4':                              
                    rx_seq0 = 40;
                    break;
                case '6':                              
                    rx_seq0 = 60;
                    break;
                default:
                    rx_seq0 = 0;
                    break;
            }
            break;
        case 3:
        	if (rxdata == '1') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 4:
        	if (rxdata == '4') {
            	rx_seq0++;
            } else if  (rxdata == '7') {
            	rx_seq0 = 105;
            	rx_seq0 = 0;
            }               
            break;      
        case 5:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 14) {
                //Inverter Mode (Phase, power capacity,rated in voltaeg)
                //inverter[0].inv_phase = rxbuff[4]-0x30;            
                rcnt = 0;   
                rx_seq0 = 0;
            }           
        case 105:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 17) {
                //Inverter Mode (Phase, power capacity,rated in voltaeg)
                //inverter[0].inv_phase = rxbuff[4]-0x30;            
                rcnt = 0;   
                rx_seq0 = 0;
            }           
            break;
            break;   
            

        //ST-1      
        case 10:
        	if (rxdata == '1') {
            	rx_seq0++;
        	} else if (rxdata == '2') {
            	rx_seq0 = 111;
            } else {
            	rx_seq0 = 0;                                     
            }               
            break;      
        case 11:
        	if (rxdata == '7') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 12:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 17) {
//sprintf(str,"RX_seq:%02d ST1 ",rx_seq0); buzzer_flag |= BUZZER_TIC; tx_led_delay = 1000; put_str(0,0,str,1);
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
                inverter[imInvNo].solar_cell_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[8];str[1]=rxbuff[9];str[2]=rxbuff[10];str[3]=rxbuff[11];
                inverter[imInvNo].solar_cell_current = atoi(str);
				//inverter[imInvNo].solar_cell_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[13];str[1]=rxbuff[14];str[2]=rxbuff[15];str[3]=rxbuff[16];
                inverter[imInvNo].power_solar        = atoi(str);
                inverter[imInvNo].power_solar        *= 10;		//500~1000K
                rx_seq0 = 0;
            }           
            break; 

        case 111:
        	if (rxdata == '0') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 112:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 20) {                        
//                                                   04 05 06    08 09 10 11    13 14 15 16              
//5e 50 30 30 30 53 54 31 5e 44 31 32 30 30 30 30 2c 34 39 32 2c 30 30 35 36 2c 30 30 32 38 2c 33 39             
//sprintf(str,"RX_seq:%02d ST1 ",rx_seq0); buzzer_flag |= BUZZER_TIC; tx_led_delay = 1000; put_str(0,0,str,1);
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
                inverter[imInvNo].solar_cell_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[8];str[1]=rxbuff[9];str[2]=rxbuff[10];str[3]=rxbuff[11];
                inverter[imInvNo].solar_cell_current = atoi(str);
//                inverter[imInvNo].solar_cell_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[13];str[1]=rxbuff[14];str[2]=rxbuff[15];str[3]=rxbuff[16];
                inverter[imInvNo].power_solar        = atoi(str);
                inverter[imInvNo].power_solar        *= 10;		//500~1000K
                //inverter[0].power_solar *= 10;
                rx_seq0 = 0;
            }           
            break;                       

        //ST-2      
        case 20:
        	if (rxdata == '1') {
            	rx_seq0++;
        	} else if (rxdata == '2') {
            	rx_seq0 = 121;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 21:
        	if (rxdata == '9') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 22:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 19) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
                inverter[imInvNo].inv_u_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[8];str[1]=rxbuff[9];str[2]=rxbuff[10];
                inverter[imInvNo].inv_v_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[12];str[1]=rxbuff[13];str[2]=rxbuff[14];
                inverter[imInvNo].inv_w_voltage = atoi(str);

                memset(str,0,sizeof(str));
                str[0]=rxbuff[16];str[1]=rxbuff[17];str[2]=rxbuff[18];
                inverter[imInvNo].inv_frequency = atoi(str);

                rx_seq0 = 0;
            }           
            break;    
                              
        case 121:
        	if (rxdata == '2') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 122:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 22) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
                inverter[imInvNo].inv_u_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[8];str[1]=rxbuff[9];str[2]=rxbuff[10];
                inverter[imInvNo].inv_v_voltage = atoi(str);            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[12];str[1]=rxbuff[13];str[2]=rxbuff[14];
                inverter[imInvNo].inv_w_voltage = atoi(str);

                memset(str,0,sizeof(str));
                str[0]=rxbuff[16];str[1]=rxbuff[17];str[2]=rxbuff[18];
                inverter[imInvNo].inv_frequency = atoi(str);

                rx_seq0 = 0;
            }           
            break;      

        //ST-3      
        case 30:
        	if (rxdata == '1') {
            	rx_seq0++;
        	} else if (rxdata == '2') {
            	rx_seq0 = 131; 
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 31:
        	if (rxdata == '8') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 32:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 18) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                inverter[imInvNo].inv_u_current = atoi(str);
//                inverter[imInvNo].inv_u_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                inverter[imInvNo].inv_v_current = atoi(str);
//                inverter[imInvNo].inv_v_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                inverter[imInvNo].inv_w_current = atoi(str);
//                inverter[imInvNo].inv_w_current /= 10;	//30K~250K
                
                rx_seq0 = 0;
            }           
            break;   
                        
        case 131:
        	if (rxdata == '1') {
            	rx_seq0++;
            } else if (rxdata == '6') {
            	rx_seq0 = 133;
         	} else {
            	rx_seq0 = 0;
            }               
            break;      
        case 132:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 21) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                inverter[imInvNo].inv_u_current = atoi(str);
                //inverter[imInvNo].inv_u_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                inverter[imInvNo].inv_v_current = atoi(str);
                //inverter[imInvNo].inv_v_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                inverter[imInvNo].inv_w_current = atoi(str);
                //inverter[imInvNo].inv_w_current /= 10;	//30K~250K
                
                rx_seq0 = 0;
            }           
            break;      
        case 133:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 26) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                inverter[imInvNo].inv_u_current = atoi(str);
                //inverter[imInvNo].inv_u_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                inverter[imInvNo].inv_v_current = atoi(str);
                //inverter[imInvNo].inv_v_current /= 10;	//30K~250K            
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                inverter[imInvNo].inv_w_current = atoi(str);
                //inverter[imInvNo].inv_w_current /= 10;	//30K~250K
                
                rx_seq0 = 0;
            }           
            break;      

        //ST-4      
        case 40:
        	if (rxdata == '1') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 41:
        	if (rxdata == '6') {
            	rx_seq0++;
        	} else if (rxdata == '9') {
            	rx_seq0 = 142;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 42:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 16) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                inverter[imInvNo].power_inv_day_total = atoi(str);            
                inverter[imInvNo].power_inv_day_total *= 10;                               
                inverter[imInvNo].power_inv_now = atoi(str) * 10;       
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];str[4]=rxbuff[13];str[5]=rxbuff[14];str[6]=rxbuff[15]; 
                if (atol(str) > 0) {
	                inverter[imInvNo].power_inv_total = atol(str);            
    			}
                sendInverterCount[imInvNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                put_str(4,16,C_RXOK,1);   
                rx_led_delay = 2500;
                           

                rx_seq0 = 0;
            }           
            break; 
                 
        case 142:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 19) {
                memset(str,0,sizeof(str));
                str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                inverter[imInvNo].power_inv_day_total = atoi(str);            
                inverter[imInvNo].power_inv_day_total *= 10;                               
                inverter[imInvNo].power_inv_now = atoi(str) * 10;       
//                inverter[0].power_inv_now = inverter[0].power_inv_day_total;       
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];str[4]=rxbuff[13];str[5]=rxbuff[14];str[6]=rxbuff[15];
                if (atol(str) > 0) {
                    inverter[imInvNo].power_inv_total = atol(str);
                }            
                sendInverterCount[imInvNo] = 0;
                buzzer_flag |= BUZZER_TIC;
                put_str(4,16,C_RXOK,1);   
                rx_led_delay = 2500;


                rx_seq0 = 0;
            }           
            break;          

        //ST-6      
        case 60:
        	if (rxdata == '0') {
            	rx_seq0++;
        	} else if (rxdata == '1') {
            	rx_seq0 = 161;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 61:
        	if (rxdata == '9') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 62:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 9) {                   
                inverter[imInvNo].inverter_status[0] = rxbuff[4] - 0x30;
                inverter[imInvNo].inverter_status[1] = rxbuff[6] - 0x30;
                inverter[imInvNo].inverter_status[2] = rxbuff[8] - 0x30;
                inverter[imInvNo].inverter_status[3] = 0;

					buzzer_flag |= BUZZER_TIC;        
                    sprintf(str,"RX-%d",imInvNo+1);
                    put_str(4,16,str,1);   
					rx_led_delay = 2500;

                rx_seq0 = 0;
            }           
            break; 
                       
        case 161:
        	if (rxdata == '2') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 162:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 12) {                   
                inverter[imInvNo].inverter_status[0] = rxbuff[4] - 0x30;
                inverter[imInvNo].inverter_status[1] = rxbuff[6] - 0x30;
                inverter[imInvNo].inverter_status[2] = rxbuff[8] - 0x30;
                inverter[imInvNo].inverter_status[3] = 0;

					buzzer_flag |= BUZZER_TIC;
                    sprintf(str,"RX-%d",imInvNo+1);
                    put_str(4,16,str,1);   
					rx_led_delay = 2500;

//	                sprintf(str,"%5dmWh ",inverter[0].power_inv_total/1000);
//				    put_str(5,8,str,1);


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
    sprintf(str,"%01X", eeInverterCount);
    put_str(7,18,str,1);
                
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

