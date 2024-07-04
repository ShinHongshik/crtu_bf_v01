//동이에코스 100K 인버터는 다스테크 프로토콜과 비슷, 단 ST6-> ST5로 콜됨....
//서버에서 인버터 메이커를 DASSTECH로 설정해야 함...

void sendInverterRead_DongeiEcos(void) {
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	//sendInverterCount[0]++;      

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
        case 6:     //Inv-1: ^P000ST5
			imInvNo = 0;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
        case 16:     //Inv-2: ^P001ST5      
			imInvNo = 1;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
        case 26:     //Inv-3: ^P002ST5      
			imInvNo = 2;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
        case 36:     //Inv-4: ^P003ST5      
			imInvNo = 3;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
        case 46:     //Inv-5: ^P004ST5      
			imInvNo = 4;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
        case 56:     //Inv-6: ^P005ST5     
			imInvNo = 5;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x35); //5
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
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
                              
        //// Inv-7 ////////////////////////////////////////////////////       
        case 60:  
        	if (eeInverterCount > 6) {  
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;  
                    sprintf(str,"TX-%d",7);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 61:     //Inv-7: ^P006MOD   
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
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
        case 62:     //Inv-7: ^P006ST1     
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
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
        case 63:     //Inv-7: ^P006ST2      
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
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
        case 64:     //Inv-7: ^P006ST3    
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
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
        case 65:     //Inv-7: ^P006ST4    
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
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
        case 66:     //Inv-7: ^P006ST5      
			imInvNo = 6;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x36); //6
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 67:
        case 68:
        case 69:
            inverter_seq++;
            break;                                     
                                                   
                              
        //// Inv-8 ////////////////////////////////////////////////////       
        case 70:  
        	if (eeInverterCount > 7) {  
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;  
                    sprintf(str,"TX-%d",8);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 71:     //Inv-8: ^P007MOD   
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
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
        case 72:     //Inv-8: ^P007ST1     
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
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
        case 73:     //Inv-8: ^P007ST2      
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
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
        case 74:     //Inv-8: ^P007ST3    
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
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
        case 75:     //Inv-8: ^P007ST4    
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
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
        case 76:     //Inv-8: ^P007ST5      
			imInvNo = 7;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x37); //7
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 77:
        case 78:
        case 79:
            inverter_seq++;
            break;                                     
                    

		/////////////////////////////////////////////////////////////
        
        
                                      
        //// Inv-9 ////////////////////////////////////////////////////       
        case 80:  
        	if (eeInverterCount > 8) {  
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;  
                    sprintf(str,"TX-%d",9);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 81:     //Inv-9: ^P008MOD   
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
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
        case 82:     //Inv-9: ^P008ST1     
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
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
        case 83:     //Inv-9: ^P008ST2      
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
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
        case 84:     //Inv-9: ^P008ST3    
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
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
        case 85:     //Inv-9: ^P008ST4    
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
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
        case 86:     //Inv-9: ^P008ST5      
			imInvNo = 8;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x38); //8
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 87:
        case 88:
        case 89:
            inverter_seq++;
            break;                                     
                                      
                     
                              
        //// Inv-A ////////////////////////////////////////////////////       
        case 90:  
        	if (eeInverterCount > 9) {  
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;  
                    sprintf(str,"TX-A");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 91:     //Inv-A: ^P009MOD   
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
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
        case 92:     //Inv-A: ^P009ST1     
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
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
        case 93:     //Inv-A: ^P00AST2      
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
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
        case 94:     //Inv-A: ^P009ST3    
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
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
        case 95:     //Inv-A: ^P009ST4    
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
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
        case 96:     //Inv-A: ^P009ST6      
			imInvNo = 9;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x30); //0
            putchar0(0x39); //9
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 97:
        case 98:
        case 99:
            inverter_seq++;
            break;                                     
                          
                              
        //// Inv-B ////////////////////////////////////////////////////       
        case 100:  
        	if (eeInverterCount > 10) {  
                if (sendInverterCount[10] < 100) {
                    sendInverterCount[10]++;  
                    sprintf(str,"TX-B");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 101:     //Inv-B: ^P010MOD   
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 102:     //Inv-B: ^P010ST1     
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 103:     //Inv-B: ^P010ST2      
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 104:     //Inv-B: ^P010ST3    
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 105:     //Inv-B: ^P010ST4    
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 106:     //Inv-B: ^P010ST5      
			imInvNo = 10;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x30); //0
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x36); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 107:
        case 108:
        case 109:
            inverter_seq++;
            break;                                     
                          
                              
        //// Inv-C ////////////////////////////////////////////////////       
        case 110:  
        	if (eeInverterCount > 11) {  
                if (sendInverterCount[11] < 100) {
                    sendInverterCount[11]++;  
                    sprintf(str,"TX-C");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 111:     //Inv-C: ^P011MOD   
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 112:     //Inv-C: ^P011ST1     
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 113:     //Inv-C: ^P011ST2      
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 114:     //Inv-C: ^P011ST3    
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 115:     //Inv-C: ^P011ST4    
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 116:     //Inv-C: ^P011ST5      
			imInvNo = 11;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x31); //1
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 117:
        case 118:
        case 119:
            inverter_seq++;
            break;                                     
                          
                              
        //// Inv-D ////////////////////////////////////////////////////       
        case 120:  
        	if (eeInverterCount > 12) {  
                if (sendInverterCount[12] < 100) {
                    sendInverterCount[12]++;  
                    sprintf(str,"TX-D");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 121:     //Inv-D: ^P012MOD   
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 122:     //Inv-D: ^P012ST1     
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 123:     //Inv-D: ^P012ST2      
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 124:     //Inv-D: ^P012ST3    
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 125:     //Inv-D: ^P012ST4    
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 126:     //Inv-D: ^P012ST5      
			imInvNo = 12;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x32); //2
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 127:
        case 128:
        case 129:
            inverter_seq++;
            break;                                     
                          
                              
        //// Inv-E ////////////////////////////////////////////////////       
        case 130:  
        	if (eeInverterCount > 13) {  
                if (sendInverterCount[13] < 100) {
                    sendInverterCount[13]++;  
                    sprintf(str,"TX-E");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 131:     //Inv-E: ^P013MOD   
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 132:     //Inv-E: ^P013ST1     
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 133:     //Inv-E: ^P013ST2      
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 134:     //Inv-E: ^P013ST3    
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 135:     //Inv-E: ^P013ST4    
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 136:     //Inv-E: ^P013ST5      
			imInvNo = 13;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x33); //3
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 137:
        case 138:
        case 139:
            inverter_seq++;
            break;                                     
                          
                              
        //// Inv-F ////////////////////////////////////////////////////       
        case 140:  
        	if (eeInverterCount > 14) {  
                if (sendInverterCount[14] < 100) {
                    sendInverterCount[14]++;  
                    sprintf(str,"TX-F");
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;     
                }
            	timeout0 = 250;
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;          
        case 141:     //Inv-F: ^P014MOD   
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 142:     //Inv-F: ^P014ST1     
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 143:     //Inv-F: ^P014ST2      
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 144:     //Inv-F: ^P014ST3    
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 145:     //Inv-F: ^P014ST4    
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
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
        case 146:     //Inv-F: ^P007ST5      
			imInvNo = 14;
            //putchar0(0x5E); //^     
            putchar0(0x50); //P
            putchar0(0x30); //0
            putchar0(0x31); //1
            putchar0(0x34); //4
            putchar0(0x53); //S
            putchar0(0x54); //T
            putchar0(0x35); //5
            TXEN=1;TXEN=1;     
            rx_seq0 = 0;
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x5E);  
#else  
			UDR0 = 0x5E ;  
#endif  
            inverter_seq++;
            break;         
        case 147:
        case 148:
        case 149:
            inverter_seq++;
            break;                                     
                          
                              
            
        ///////////////////////////////              
        case 150:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}

void rx0Control_DongeiEcos(void) {   
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
        	dCalSum = (rxdata - 0x30);
            
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
                case '5':                              
                    rx_seq0 = 50;
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
            	dCalSum += 2;    
				bLen = 20;
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
					//PVES-100TLS (100KW)
                inverter[imInvNo].solar_cell_current /= 10;
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[13];str[1]=rxbuff[14];str[2]=rxbuff[15];str[3]=rxbuff[16];
                inverter[imInvNo].power_solar        = atoi(str); 
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
//sprintf(str,"RX_seq:%02d ST1 ",rx_seq0); buzzer_flag |= BUZZER_TIC; tx_led_delay = 1000; put_str(0,0,str,1);

				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30);
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[5] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
				dCalSum += (rxbuff[8] - 0x30);
				dCalSum += (rxbuff[9] - 0x30);
				dCalSum += (rxbuff[10] - 0x30);
				dCalSum += (rxbuff[11] - 0x30);
				dCalSum += (rxbuff[13] - 0x30);
				dCalSum += (rxbuff[14] - 0x30);
				dCalSum += (rxbuff[15] - 0x30);
				dCalSum += (rxbuff[16] - 0x30); 
                
                dCrcSum = (rxbuff[18] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[19] - 0x30);     
                
                if (dCalSum == dCrcSum) {
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];
                    inverter[imInvNo].solar_cell_voltage = atoi(str);            
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[8];str[1]=rxbuff[9];str[2]=rxbuff[10];str[3]=rxbuff[11];
                    inverter[imInvNo].solar_cell_current = atoi(str); 
					//PVES-100TLS (100KW)
                    inverter[imInvNo].solar_cell_current /= 10;
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[13];str[1]=rxbuff[14];str[2]=rxbuff[15];str[3]=rxbuff[16];
                    inverter[imInvNo].power_solar        = atoi(str);  
                    sprintf(str,"COK1");
                    put_str(4,16,str,1);                        
                } else {   
                    sprintf(str,"Crc1");
                    put_str(4,16,str,1);   
                }
                rx_seq0 = 0;
            }           
            break;                       

        //ST-2      
        case 20:
        	if (rxdata == '1') {
            	rx_seq0++;
        	} else if (rxdata == '2') {   
            	dCalSum += 2;    
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
            	dCalSum += 2;    
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 122:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 22) {  
				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30); 
                
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[5] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
                
				dCalSum += (rxbuff[8] - 0x30);
				dCalSum += (rxbuff[9] - 0x30);
				dCalSum += (rxbuff[10] - 0x30); 
                
				dCalSum += (rxbuff[12] - 0x30);
				dCalSum += (rxbuff[13] - 0x30);
				dCalSum += (rxbuff[14] - 0x30);
                
				dCalSum += (rxbuff[16] - 0x30);
				dCalSum += (rxbuff[17] - 0x30); 
				dCalSum += (rxbuff[18] - 0x30); 
                
                dCrcSum = (rxbuff[20] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[21] - 0x30);     
                
                if (dCalSum == dCrcSum) {
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
                    sprintf(str,"COK2");
                    put_str(4,16,str,1);   
            	} else {   
                    sprintf(str,"Crc2");
                    put_str(4,16,str,1);   
                }

                rx_seq0 = 0;
            }           
            break;      

        //ST-3      
        case 30:
        	if (rxdata == '1') {
            	rx_seq0++;
        	} else if (rxdata == '2') {   
            	dCalSum += 2;    
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
                //PVES-100TLS (100KW)
                inverter[imInvNo].inv_u_current /= 10;
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                inverter[imInvNo].inv_v_current = atoi(str);     
                //PVES-100TLS (100KW)
               	inverter[imInvNo].inv_v_current /= 10;   
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                inverter[imInvNo].inv_w_current = atoi(str);  
                //PVES-100TLS (100KW)
               	inverter[imInvNo].inv_w_current /= 10;
                
                rx_seq0 = 0;
            }           
            break;   
                        
        case 131:
        	if (rxdata == '1') {   
            	dCalSum += 1;    
            	rx_seq0++;
            } else if (rxdata == '6') { 
            	dCalSum += 6;    
            	rx_seq0 = 133;
         	} else {
            	rx_seq0 = 0;
            }               
            break;      
        case 132:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 21) {       
				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30);
                
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[5] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
				dCalSum += (rxbuff[7] - 0x30); 
                
				dCalSum += (rxbuff[9] - 0x30);
				dCalSum += (rxbuff[10] - 0x30);
				dCalSum += (rxbuff[11] - 0x30);
				dCalSum += (rxbuff[12] - 0x30);
                
				dCalSum += (rxbuff[14] - 0x30);
				dCalSum += (rxbuff[15] - 0x30);
				dCalSum += (rxbuff[16] - 0x30); 
				dCalSum += (rxbuff[17] - 0x30); 
                
                dCrcSum = (rxbuff[19] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[20] - 0x30);     
                
                if (dCalSum == dCrcSum) {
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                    inverter[imInvNo].inv_u_current = atoi(str);
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_u_current /= 10;   
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                    inverter[imInvNo].inv_v_current = atoi(str); 
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_v_current /= 10;    
                        
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                    inverter[imInvNo].inv_w_current = atoi(str); 
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_w_current /= 10;  

                    sprintf(str,"CK31");
                    put_str(4,16,str,1);                                                  
                } else {  
                    sprintf(str,"Cr31");
                    put_str(4,16,str,1);  
                }
                
                rx_seq0 = 0;
            }           
            break;      
        case 133:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 26) { 
				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30);
                 
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[5] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
				dCalSum += (rxbuff[7] - 0x30); 
                
				dCalSum += (rxbuff[9] - 0x30);
				dCalSum += (rxbuff[10] - 0x30);
				dCalSum += (rxbuff[11] - 0x30);
				dCalSum += (rxbuff[12] - 0x30);
                
				dCalSum += (rxbuff[14] - 0x30);
				dCalSum += (rxbuff[15] - 0x30);
				dCalSum += (rxbuff[16] - 0x30); 
				dCalSum += (rxbuff[17] - 0x30);  
                
				dCalSum += (rxbuff[19] - 0x30);
				dCalSum += (rxbuff[20] - 0x30);
				dCalSum += (rxbuff[21] - 0x30); 
				dCalSum += (rxbuff[22] - 0x30); 
                
                dCrcSum = (rxbuff[24] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[25] - 0x30);     
                
                if (dCalSum == dCrcSum) {
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                    inverter[imInvNo].inv_u_current = atoi(str);  
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_u_current /= 10;     
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];
                    inverter[imInvNo].inv_v_current = atoi(str);  
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_v_current /= 10;   
                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[14];str[1]=rxbuff[15];str[2]=rxbuff[16];str[3]=rxbuff[17];
                    inverter[imInvNo].inv_w_current = atoi(str); 
	                //PVES-100TLS (100KW)
                    inverter[imInvNo].inv_w_current /= 10;

                    sprintf(str,"CK32");
                    put_str(4,16,str,1);                       
                } else {  
                    sprintf(str,"Cr32");
                    put_str(4,16,str,1);       
                }
                
                rx_seq0 = 0;
            }           
            break;      

        //ST-4      
        case 40:
        	if (rxdata == '1') {  
            	dCalSum += 1;    
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 41:
        	if (rxdata == '6') {
            	rx_seq0++;
        	} else if (rxdata == '9') {  
            	dCalSum += 9;    
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
                if (modelInverter == MODEL_INVERTER_DASSTECH500K) {
            		inverter[imInvNo].power_inv_day_total *= 10;
                }                               
                inverter[imInvNo].power_inv_now = inverter[imInvNo].power_inv_day_total;       
                
                memset(str,0,sizeof(str));
                str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];str[4]=rxbuff[13];str[5]=rxbuff[14];str[6]=rxbuff[15]; 
                if (atol(str) > 0) {
	                inverter[imInvNo].power_inv_total = atol(str);            
    			}
                sendInverterCount[imInvNo] = 0;
                buzzer_flag |= BUZZER_TIC;         
                
                sprintf(str,"RX-%X",imInvNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;
                //put_str(4,16,C_RXOK,1);   
                //rx_led_delay = 2500;

                rx_seq0 = 0;
            }           
            break; 
                 
        case 142:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 19) {  
				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30);
                   
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[5] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
				dCalSum += (rxbuff[7] - 0x30); 
                
				dCalSum += (rxbuff[9] - 0x30);
				dCalSum += (rxbuff[10] - 0x30);
				dCalSum += (rxbuff[11] - 0x30);
				dCalSum += (rxbuff[12] - 0x30);
				dCalSum += (rxbuff[13] - 0x30);
				dCalSum += (rxbuff[14] - 0x30);
				dCalSum += (rxbuff[15] - 0x30);
                
                dCrcSum = (rxbuff[17] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[18] - 0x30);     
                
                if (dCalSum == dCrcSum) {
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[4];str[1]=rxbuff[5];str[2]=rxbuff[6];str[3]=rxbuff[7];
                    inverter[imInvNo].power_inv_day_total = atoi(str);             
                    if (modelInverter == MODEL_INVERTER_DASSTECH500K) {         
                        inverter[imInvNo].power_inv_day_total *= 10;
                    }                               
                    inverter[imInvNo].power_inv_now = inverter[imInvNo].power_inv_day_total;       

                    
                    memset(str,0,sizeof(str));
                    str[0]=rxbuff[9];str[1]=rxbuff[10];str[2]=rxbuff[11];str[3]=rxbuff[12];str[4]=rxbuff[13];str[5]=rxbuff[14];str[6]=rxbuff[15];
                    if (atol(str) > 0) {
                        inverter[imInvNo].power_inv_total = atol(str);
                    }            
                    sendInverterCount[imInvNo] = 0;
                    buzzer_flag |= BUZZER_TIC;   
                                                      

inverter[imInvNo].inverter_status[2] = 0;
inverter[imInvNo].inverter_status[3] = 0;
                                               
                    sprintf(str,"COK4");
                    put_str(4,16,str,1);
                    
                    sprintf(str,"RX-%X",imInvNo+1);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                    //put_str(4,16,C_RXOK,1);   
                    //rx_led_delay = 2500; 
                } else {   
                    sprintf(str,"Crc4");
                    put_str(4,16,str,1); 
                }

                rx_seq0 = 0;
            }           
            break;          

        //ST-5      
        case 50:
        	if (rxdata == '0') {
            	rx_seq0++;
        	} else if (rxdata == '1') { 
            	dCalSum += 1;    
            	rx_seq0 = 151;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 51:
        	if (rxdata == '9') {
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 52:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 9) {          
                inverter[imInvNo].inverter_status[0] = rxbuff[4] - 0x30;
                inverter[imInvNo].inverter_status[1] = rxbuff[6] - 0x30;
                inverter[imInvNo].inverter_status[2] = rxbuff[8] - 0x30;
                inverter[imInvNo].inverter_status[3] = 0;

				//buzzer_flag |= BUZZER_TIC;
	                //sprintf(str,"RX-%01d",imInvNo+1);
    	            //put_str(4,16,str,1);   
        	        //rx_led_delay = 2500;
                    //put_str(4,16,C_RXOK,1);   
					//rx_led_delay = 2500;

                rx_seq0 = 0;
            }           
            break; 
                       
        case 151:
        	if (rxdata == '2') {  
            	dCalSum += 2;    
            	rx_seq0++;
            } else {
            	rx_seq0 = 0;
            }               
            break;      
        case 152:
            rxbuff[rcnt] = rxdata;
            rcnt++;
            if (rcnt == 13) {  
				dCalSum += (rxbuff[0] - 0x30);
				dCalSum += (rxbuff[1] - 0x30);
				dCalSum += (rxbuff[2] - 0x30);
                
				dCalSum += (rxbuff[4] - 0x30);
				dCalSum += (rxbuff[6] - 0x30);
				dCalSum += (rxbuff[8] - 0x30); 
				dCalSum += (rxbuff[9] - 0x30); 
                
                dCrcSum = (rxbuff[11] - 0x30);
                dCrcSum *= 10;
                dCrcSum += (rxbuff[12] - 0x30);     
                                           
//sprintf(str,"%02d,%02d,,%c,%c ",dCalSum, dCrcSum, rxbuff[11], rxbuff[12]);
//put_str(0,0,str,1);   
                if (dCalSum == dCrcSum) {                         
                    inverter[imInvNo].inverter_status[0] = rxbuff[4] - 0x30;
                    inverter[imInvNo].inverter_status[1] = rxbuff[6] - 0x30;
                    inverter[imInvNo].inverter_status[2] = rxbuff[8] - 0x30;
                    inverter[imInvNo].inverter_status[3] = rxbuff[9] - 0x30;

                       // buzzer_flag |= BUZZER_TIC;
                        //put_str(4,16,C_RXOK,1);   
                        //rx_led_delay = 2500;

    //	                sprintf(str,"%5dmWh ",inverter[0].power_inv_total/1000);
    //				    put_str(5,8,str,1);     
                    sprintf(str,"COK6");
                    put_str(4,16,str,1);   
				} else { 
                    sprintf(str,"Crc6");
                    put_str(4,16,str,1); 
                }

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
    sprintf(str,"%2d", eeInverterCount);
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

