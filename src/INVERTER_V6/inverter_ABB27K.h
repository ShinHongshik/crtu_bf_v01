void sendInverterRead_Abb27K(void) {

//sprintf(str,"S:%0d ",inverter_seq);
//put_str(0,0,str,1); 

    switch(inverter_seq) {
        case 0:
            inverter_seq++;  
			//INV-01
            if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
	            sprintf(str,"TX-%d",1);
    	        put_str(4,16,str,1);   
        	    rx_led_delay = 2500;
            }
            break;                      
        case 1:                                                      
        	//Request measurement - Grid Voltage (V)
			//02 3b 01 00 00 00 00 00 ff 2c -> 00 06 43 68 03 df f0 38  
            
            imInvNo = 0x02;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00);
                         
            putchar0(0xff); 
            putchar0(0x2c);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;    
            break;            

        case 2:                                                      
        	//Request measurement - Grid Current (A)
			//02 3b 02 00 00 00 00 00 82 20 -> 00 06 40 e7 47 30 e9 65  
            
            imInvNo = 0x02;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00);
             
            putchar0(0x82); 
            putchar0(0x20); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 3:                                                      
        	//Request measurement - Grid power(W)
			//02 3b 03 00 00 00 00 00 a9 24 -> 00 06 45 9e 16 e1 53 1a  
            
            imInvNo = 0x02;                   
			inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00);
             
            putchar0(0xa9); 
            putchar0(0x24); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 4:                                                      
        	//Request measurement - //PV Voltage (Float 1:1)   
            //02 3b 17 00 00 00 00 00 b5 76 -> 00 06 44 01 8a 11 24 82
            
            imInvNo = 0x02;                   
			inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xb5); 
            putchar0(0x76); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 5:                                                      
        	//Request measurement - //PV-1 Current (Float 1:1)     
            //02 3b 19 00 00 00 00 00 17 4f -> 00 06 40 d6 cd 39 e6 55
            
            imInvNo = 0x02;                    
			inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x17); 
            putchar0(0x4f); 
            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 6:                                                      
        	//Request measurement - //PV-2 Current (Float 1:1) 
            //02 3b 1b 00 00 00 00 00 41 47 -> 00 06 40 d4 7a 90 f3 af
            
            imInvNo = 0x02;                   
			inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x41); 
            putchar0(0x47);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 7:                                                      
        	//Request measurement - //PV-1 POwer (Float * 10) 
            //02 3b 08 00 00 00 00 00 8c 09 -> 00 06 45 57 fd 67 d8 60
            
            imInvNo = 0x02;                   
			inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x8c); 
            putchar0(0x09);

			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 8:                                                      
        	//Request measurement - //PV-2 POwer (Float * 10) 
            //02 3b 09 00 00 00 00 00 a7 0d -> 00 06 45 59 64 ea 6b e1
            
            imInvNo = 0x02;                   
			inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xa7); 
            putchar0(0x0d); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 9:  //Inv-01: RTU Master request frame                                                 
        	//Cumulated energy readings (daily energy)
			//02 4e 00 00 00 00 00 00 3b c9 -> 00 06 00 00 28 3d 82 cb  //Cumulated energy readings (daily energy)
            
            imInvNo = 0x02;                   
			inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x3b); 
            putchar0(0xc9);
 

			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 10:  //Inv-01: RTU Master request frame                                                 
        	//Cumulated energy readings (total energy (total lifetime))
			//02 4e 05 00 00 00 00 00 bc dd -> 00 06 00 00 d5 ad 7b 93  //Cumulated energy readings (total energy (total lifetime)
            
            imInvNo = 0x02;              
			inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xbc); 
            putchar0(0xdd);
 

			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 11:                                                      
        	//Request the state of the system module  
            //02 32 00 00 00 00 00 00 ed 69 -> 00 06 02 02 02 00 69 73
            
            imInvNo = 0x02;                   
			inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xed); 
            putchar0(0x69); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 12:
        	inverter_seq++;
            break;
        case 13:
            inverter_seq = 15;
            break;             

            
		//Inv-02: RTU Master request frame ////////////////////////////////////////                                                			
        case 15:           
        	if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                    sprintf(str,"TX-%d",2);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;                   
        case 16:                                                      
        	//Request measurement - Grid Voltage (V)
			//03 3b 01 00 00 00 00 00 40 ad -> 00 06 43 67 02 82 8f e2  
            
            imInvNo = 0x03;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x40); 
            putchar0(0xad); 

            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 17:                                                      
        	//Request measurement - Grid Current (A)
			//03 3b 02 00 00 00 00 00 3d a1 -> 00 06 41 70 e1 79 c4 58  
            
            imInvNo = 0x03;                   
			inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x3d); 
            putchar0(0xa1);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 18:                                                      
        	//Request measurement - Grid power(W)
			//03 3b 03 00 00 00 00 00 16 a5 -> 00 06 46 23 ff 9a 76 b9 
            
            imInvNo = 0x03;              
			inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x16); 
            putchar0(0xa5);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 19:                                                      
        	//Request measurement - //PV Voltage (Float 1:1)   
            //03 3b 17 00 00 00 00 00 0a f7 -> 00 06 44 01 a1 95 93 87
            
            imInvNo = 0x03;                   
			inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x0a); 
            putchar0(0xf7);

			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 20:                                                      
        	//Request measurement - //PV-1 Current (Float 1:1)     
            //03 3b 19 00 00 00 00 00 a8 ce -> 00 06 41 27 55 f6 d3 76
            
            imInvNo = 0x03;          
        
			inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xa8); 
            putchar0(0xce); 

			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 21:                                                      
        	//Request measurement - //PV-2 Current (Float 1:1) 
            //03 3b 1b 00 00 00 00 00 fe c6 -> 00 06 41 27 99 48 2c 49
            
            imInvNo = 0x03;                   
			inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0xfe); 
            putchar0(0xc6);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 22:                                                      
        	//Request measurement - //PV-1 POwer (Float * 10) 
            //03 3b 08 00 00 00 00 00 33 88 -> 00 06 45 a8 9f f3 63 22
            
            imInvNo = 0x03;                    
			inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x33); 
            putchar0(0x88);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 23:                                                      
        	//Request measurement - //PV-2 POwer (Float * 10) 
            //03 3b 09 00 00 00 00 00 18 8c -> 00 06 45 a9 8e d8 27 6b
            
            imInvNo = 0x03;                   
			inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x18); 
            putchar0(0x8c);


			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 24:  //Inv-2: RTU Master request frame                                                 
        	//Cumulated energy readings (daily energy)
			//03 4e 00 00 00 00 00 00 84 48 -> 00 06 00 01 60 b4 31 00
            
            imInvNo = 0x03;                  
			inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            
            putchar0(0x84); 
            putchar0(0x48); 
            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
			
        case 25:  //Inv-03: RTU Master request frame                                                 
        	//Cumulated energy readings (total energy (total lifetime))
			//03 4e 05 00 00 00 00 00 03 5c -> 00 06 00 02 65 a4 6c 81
            
            imInvNo = 0x03;                   
			inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00);
             
            putchar0(0x03); 
            putchar0(0x5c); 
            
			rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 26:                                                      
        	//Request the state of the system module  
            //03 32 00 00 00 00 00 00 52 e8 -> 00 06 02 02 02 00 69 73
            
            imInvNo = 0x03;               
			inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00);
             
            putchar0(0x52); 
            putchar0(0xe8);


            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 27:
            inverter_seq++;
            break;
        case 28: 
            inverter_seq = 30;
            break;
            

        //Inv-03: RTU Master request frame ////////////////////////////////////////        
        case 30:           
            if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                    sprintf(str,"TX-%d",3);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 31:                                                      
            //Request measurement - Grid Voltage (V)
            //04 3b 01 00 00 00 00 00 4e 31 -> 00 06 43 66 42 d7 1d fb  
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4e); 
            putchar0(0x31); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 32:                                                      
            //Request measurement - Grid Current (A)
            //04 3b 02 00 00 00 00 00 33 3d -> 00 06 41 6d 28 b2 43 47 
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x33); 
            putchar0(0x3d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 33:                                                      
            //Request measurement - Grid power(W)
            //04 3b 03 00 00 00 00 00 18 39 -> 00 06 46 21 f5 87 da 3a
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x18); 
            putchar0(0x39); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 34:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //04 3b 17 00 00 00 00 00 04 6b -> 00 06 44 01 18 c5 60 38
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x04); 
            putchar0(0x6b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 35:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //04 3b 19 00 00 00 00 00 a6 52 -> 00 06 41 24 5b 00 1e 91
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa6); 
            putchar0(0x52); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 36:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //04 3b 1b 00 00 00 00 00 f0 5a -> 00 06 41 25 c7 a7 8a aa 
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf0); 
            putchar0(0x5a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 37:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //04 3b 08 00 00 00 00 00 3d 14 -> 00 06 45 a5 27 7d c4 44
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x3d); 
            putchar0(0x14); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 38:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //04 3b 09 00 00 00 00 00 16 10 -> 00 06 45 a7 89 1f 87 84
            imInvNo = 0x04;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x16); 
            putchar0(0x10); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 39:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //04 4e 00 00 00 00 00 00 8a d4 -> 00 06 00 01 60 7f ee 78 
            imInvNo = 0x04;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8a); 
            putchar0(0xd4); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 40:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //04 4e 05 00 00 00 00 00 0d c0 -> 00 06 00 02 65 6f b3 f9
            imInvNo = 0x04;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x0d); 
            putchar0(0xc0); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 41:                                                      
            //Request the state of the system module  
            //04 32 00 00 00 00 00 00 5c 74 -> 00 06 02 02 02 00 69 73
            imInvNo = 0x04;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5c); 
            putchar0(0x74); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 42:
            inverter_seq++;
            break;
        case 43: 
            inverter_seq = 45;
            break;
            
            
        //Inv-04: RTU Master request frame ////////////////////////////////////////        
        //TX-4, Inverter NO : 5
        case 45:           
            if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                    sprintf(str,"TX-%d",4);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 46:                                                      
            //Request measurement - Grid Voltage (V)
            //05 3b 01 00 00 00 00 00 f1 b0 -> 00 06 43 66 f1 df 53 67  
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf1); 
            putchar0(0xb0); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 47:                                                      
            //Request measurement - Grid Current (A)
            //05 3b 02 00 00 00 00 00 8c bc -> 00 06 41 6a 5c 05 d6 9d 
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8c); 
            putchar0(0xbc); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 48:                                                      
            //Request measurement - Grid power(W)
            //05 3b 03 00 00 00 00 00 a7 b8 -> 00 06 46 20 84 39 ef d5
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa7); 
            putchar0(0xb8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 49:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //05 3b 17 00 00 00 00 00 bb ea -> 00 06 44 01 81 84 a8 a5 
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xbb); 
            putchar0(0xea); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 50:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //05 3b 19 00 00 00 00 00 19 d3 -> 00 06 41 21 b9 cd 63 6f 
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x19); 
            putchar0(0xd3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 51:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //05 3b 1b 00 00 00 00 00 4f db -> 00 06 41 20 8a dc 7d a8 
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4f); 
            putchar0(0xdb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 52:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //05 3b 08 00 00 00 00 00 82 95 -> 00 06 45 a4 91 8d 29 87
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x82); 
            putchar0(0x95); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 53:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //05 3b 09 00 00 00 00 00 a9 91 -> 00 06 45 a4 6d 93 7e ab
            imInvNo = 0x05;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa9); 
            putchar0(0x91); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 54:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //05 4e 00 00 00 00 00 00 35 55 -> 00 06 00 01 63 32 67 cb 
            imInvNo = 0x05;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x35); 
            putchar0(0x55); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 55:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //05 4e 05 00 00 00 00 00 b2 41 -> 00 06 00 01 f2 8e 05 b4 
            imInvNo = 0x05;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xb2); 
            putchar0(0x41); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 56:                                                      
            //Request the state of the system module  
            //05 32 00 00 00 00 00 00 e3 f5 -> 00 06 02 02 02 00 69 73
            imInvNo = 0x05;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe3); 
            putchar0(0xf5); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 57:
            inverter_seq++;
            break;
        case 58: 
            inverter_seq = 60;
            break;
            
                      
        //Inv-05: RTU Master request frame ////////////////////////////////////////        
        //TX-5, Inverter NO : 6
        case 60:           
            if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                    sprintf(str,"TX-%d",5);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 61:                                                      
            //Request measurement - Grid Voltage (V)
            //06 3b 01 00 00 00 00 00 21 3a -> 00 06 43 5e cd d8 82 4c   
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x21); 
            putchar0(0x3a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 62:                                                      
            //Request measurement - Grid Current (A)
            //06 3b 02 00 00 00 00 00 5c 36 -> 00 06 41 29 bc db ae a2 
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5c); 
            putchar0(0x36); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 63:                                                      
            //Request measurement - Grid power(W)
            //06 3b 03 00 00 00 00 00 77 32 -> 00 06 45 d9 fc 86 70 93 
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x77); 
            putchar0(0x32); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 64:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //06 3b 17 00 00 00 00 00 6b 60 -> 00 06 44 09 ec 50 ee 26 
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x6b); 
            putchar0(0x60); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 65:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //06 3b 19 00 00 00 00 00 c9 59 -> 00 06 40 d1 b7 b4 ba 8b 
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc9); 
            putchar0(0x59); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 66:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //06 3b 1b 00 00 00 00 00 9f 51 -> 00 06 40 cf 38 29 5c 5e 
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9f); 
            putchar0(0x51); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 67:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //06 3b 08 00 00 00 00 00 52 1f -> 00 06 45 62 ef dc b2 72
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x52); 
            putchar0(0x1f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 68:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //06 3b 09 00 00 00 00 00 79 1b -> 00 06 45 5f f3 20 b1 0a
            imInvNo = 0x06;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x79); 
            putchar0(0x1b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 69:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //06 4e 00 00 00 00 00 00 e5 df -> 00 06 00 00 2f 1c 01 b6 
            imInvNo = 0x06;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe5); 
            putchar0(0xdf); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 70:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //06 4e 05 00 00 00 00 00 62 cb 00 06 00 00 2f 1c 01 b6 
            imInvNo = 0x06;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x62); 
            putchar0(0xcb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 71:                                                      
            //Request the state of the system module  
            //06 32 00 00 00 00 00 00 33 7f -> 00 06 02 02 02 00 69 73
            imInvNo = 0x06;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x33); 
            putchar0(0x7f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 72:
            inverter_seq++;
            break;
        case 73: 
            inverter_seq = 75;
            break;


        //Inv-06: RTU Master request frame ////////////////////////////////////////                 
        //TX-6, Inverter NO : 7
        case 75:           
            if (eeInverterCount > 5) { 
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                    sprintf(str,"TX-%d",6);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 76:                                                      
            //Request measurement - Grid Voltage (V)
            //07 3b 01 00 00 00 00 00 9e bb -> 00 06 43 5d 02 cc 21 bc  
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9e); 
            putchar0(0xbb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 77:                                                      
            //Request measurement - Grid Current (A)
            //07 3b 02 00 00 00 00 00 e3 b7 -> 00 06 40 f2 6c ab 00 34
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe3); 
            putchar0(0xb7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 78:                                                      
            //Request measurement - Grid power(W)
            //07 3b 03 00 00 00 00 00 c8 b3 -> 00 06 45 9c b9 93 49 d3
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc8); 
            putchar0(0xb3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 79:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //07 3b 17 00 00 00 00 00 d4 e1 -> 00 06 43 f4 50 b0 44 76 
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd4); 
            putchar0(0xe1); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 80:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //07 3b 19 00 00 00 00 00 76 d8 -> 00 06 40 87 57 5c 5f 5c 
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x76); 
            putchar0(0xd8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 81:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //07 3b 1b 00 00 00 00 00 20 d0 -> 00 06 40 c5 01 e7 ee 63 
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x20); 
            putchar0(0xd0); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 82:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //07 3b 08 00 00 00 00 00 ed 9e -> 00 06 45 00 ba 1d 8d b8
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xed); 
            putchar0(0x9e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 83:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //07 3b 09 00 00 00 00 00 c6 9a -> 00 06 45 42 e6 81 f1 2f
            imInvNo = 0x07;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc6); 
            putchar0(0x9a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 84:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //07 4e 00 00 00 00 00 00 5a 5e -> 00 06 00 00 21 48 b0 38 
            imInvNo = 0x07;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5a); 
            putchar0(0x5e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 85:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //07 4e 05 00 00 00 00 00 dd 4a -> 00 06 00 00 21 48 b0 38 
            imInvNo = 0x07;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xdd); 
            putchar0(0x4a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 86:                                                      
            //Request the state of the system module  
            //07 32 00 00 00 00 00 00 8c fe -> 00 06 02 02 02 00 69 73
            imInvNo = 0x07;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8c); 
            putchar0(0xfe); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 87:
            inverter_seq++;
            break;
        case 88: 
            inverter_seq = 90;
            break;

        
        //Inv-07: RTU Master request frame ////////////////////////////////////////     
        //TX-7, Inverter NO : 8
        case 90:           
            if (eeInverterCount > 6) { 
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                    sprintf(str,"TX-%d",7);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 91:                                                      
            //Request measurement - Grid Voltage (V)
            //08 3b 01 00 00 00 00 00 2c 0a -> 00 06 43 5e ab 54 63 33  
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x2c); 
            putchar0(0x0a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 92:                                                      
            //Request measurement - Grid Current (A)
            //08 3b 02 00 00 00 00 00 51 06 -> 00 06 41 1e 5e 30 f1 2b 
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x51); 
            putchar0(0x06); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 93:                                                      
            //Request measurement - Grid power(W)
            //08 3b 03 00 00 00 00 00 7a 02 -> 00 06 45 ca f8 d5 ff fe
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x7a); 
            putchar0(0x02); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 94:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //08 3b 17 00 00 00 00 00 66 50 -> 00 06 44 09 a5 c5 b4 74 
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x66); 
            putchar0(0x50); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 95:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //08 3b 19 00 00 00 00 00 c4 69 -> 00 06 40 c3 b1 4d 09 85 
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc4); 
            putchar0(0x69); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 96:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //08 3b 1b 00 00 00 00 00 92 61 -> 00 06 40 c0 ee 71 bd c1 
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x92); 
            putchar0(0x61); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 97:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //08 3b 08 00 00 00 00 00 5f 2f -> 00 06 45 52 64 ea cd c8
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5f); 
            putchar0(0x2f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 98:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //08 3b 09 00 00 00 00 00 74 2b -> 00 06 45 4f 84 12 79 20
            imInvNo = 0x08;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x74); 
            putchar0(0x2b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 99:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //08 4e 00 00 00 00 00 00 e8 ef -> 00 06 00 00 30 55 9d 7f 
            imInvNo = 0x08;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe8); 
            putchar0(0xef); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 100:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //08 4e 05 00 00 00 00 00 6f fb -> 00 06 00 00 30 55 9d 7f 
            imInvNo = 0x08;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x6f); 
            putchar0(0xfb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 101:                                                      
            //Request the state of the system module  
            //08 32 00 00 00 00 00 00 3e 4f -> 00 06 02 02 02 00 69 73
            imInvNo = 0x08;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x3e); 
            putchar0(0x4f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 102:
            inverter_seq++;
            break;
        case 103: 
            inverter_seq = 105;
            break;

        //Inv-08: RTU Master request frame ////////////////////////////////////////     
        //TX-8, Inverter NO : 9
        case 105:           
            if (eeInverterCount > 7) { 
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                    sprintf(str,"TX-%d",8);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 106:                                                      
            //Request measurement - Grid Voltage (V)
            //09 3b 01 00 00 00 00 00 93 8b -> 00 06 43 5c ab c4 52 12  
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x93); 
            putchar0(0x8b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 107:                                                      
            //Request measurement - Grid Current (A)
            //09 3b 02 00 00 00 00 00 ee 87 -> 00 06 40 e1 3e 63 f2 f4 
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xee); 
            putchar0(0x87); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 108:                                                      
            //Request measurement - Grid power(W)
            //09 3b 03 00 00 00 00 00 c5 83 -> 00 06 45 90 7e 41 d7 04
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc5); 
            putchar0(0x83); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 109:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //09 3b 17 00 00 00 00 00 d9 d1 -> 00 06 43 f2 c7 5a 9c bc 
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd9); 
            putchar0(0xd1); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 110:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //09 3b 19 00 00 00 00 00 7b e8 -> 00 06 40 7d ad 5d e0 33 
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x7b); 
            putchar0(0xe8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 111:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //09 3b 1b 00 00 00 00 00 2d e0 -> 00 06 40 b2 6c 9f d1 45 
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x2d); 
            putchar0(0xe0); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 112:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //09 3b 08 00 00 00 00 00 e0 ae -> 00 06 44 ef 33 6e 98 fd
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe0); 
            putchar0(0xae); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 113:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //09 3b 09 00 00 00 00 00 cb aa -> 00 06 45 32 52 d9 ea 2c
            imInvNo = 0x09;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xcb); 
            putchar0(0xaa); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 114:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //09 4e 00 00 00 00 00 00 57 6e -> 00 06 00 00 22 0b 47 62 
            imInvNo = 0x09;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x57); 
            putchar0(0x6e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 115:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //09 4e 05 00 00 00 00 00 d0 7a -> 00 06 00 00 22 0b 47 62
            imInvNo = 0x09;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd0); 
            putchar0(0x7a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 116:                                                      
            //Request the state of the system module  
            //09 32 00 00 00 00 00 00 81 ce -> 00 06 02 02 02 00 69 73
            imInvNo = 0x09;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x81); 
            putchar0(0xce); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 117:
            inverter_seq++;
            break;
        case 118: 
            inverter_seq = 120;
            break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //Inv-09: RTU Master request frame ////////////////////////////////////////     
        //TX-9, Inverter NO : a
        case 120:           
            if (eeInverterCount > 8) { 
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                    sprintf(str,"TX-%d",9);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 121:                                                      
            //Request measurement - Grid Voltage (V)
            //0a 3b 01 00 00 00 00 00 43 01 -> 00 06 43 65 3b 51 9b d2  //1    
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x43); 
            putchar0(0x01); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 122:                                                      
            //Request measurement - Grid Current (A)
            //0a 3b 02 00 00 00 00 00 3e 0d -> 00 06 40 a5 fa 09 73 f0  //2     
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x3e); 
            putchar0(0x0d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 123:                                                      
            //Request measurement - Grid power(W)
            //0a 3b 03 00 00 00 00 00 15 09 -> 00 06 45 5e 5f e4 1a d6  //3    
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x15); 
            putchar0(0x09); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 124:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0a 3b 17 00 00 00 00 00 09 5b -> 00 06 44 05 f7 0c 9d 6a  //4
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x09); 
            putchar0(0x5b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 125:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0a 3b 19 00 00 00 00 00 ab 62 -> 00 06 40 83 92 71 cb 71  //5 
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xab); 
            putchar0(0x62); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 126:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0a 3b 1b 00 00 00 00 00 fd 6a -> 00 06 40 30 5d 48 cd f1  //6    
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfd); 
            putchar0(0x6a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 127:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0a 3b 08 00 00 00 00 00 30 24 -> 00 06 45 08 76 d2 be 23  //7
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x30); 
            putchar0(0x24); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 128:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0a 3b 09 00 00 00 00 00 1b 20 -> 00 06 44 b7 e9 f8 4d eb  //8    
            imInvNo = 0x0a;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x1b); 
            putchar0(0x20); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 129:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0a 4e 00 00 00 00 00 00 87 e4 -> 00 06 00 02 0e 55 97 e6  //9
            imInvNo = 0x0a;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x87); 
            putchar0(0xe4); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 130:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0a 4e 05 00 00 00 00 00 00 f0 -> 00 06 00 06 05 91 76 e1  //a
            imInvNo = 0x0a;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf0); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 131:                                                      
            //Request the state of the system module  
            //0a 32 00 00 00 00 00 00 51 44 -> 00 06 02 02 02 00 69 73  //b
            imInvNo = 0x0a;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x51); 
            putchar0(0x44); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 132:
            inverter_seq++;
            break;
        case 133: 
            inverter_seq = 135;
            break;
            

        //Inv-10: RTU Master request frame ////////////////////////////////////////     
        //TX-10, Inverter NO : 0b
        case 135:           
            if (eeInverterCount > 9) { 
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                    sprintf(str,"TX%02d",10);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 136:                                                      
            //Request measurement - Grid Voltage (V)
            //0b 3b 01 00 00 00 00 00 fc 80 -> 00 06 43 66 bf e9 90 ef //1 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfc); 
            putchar0(0x80); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 137:                                                      
            //Request measurement - Grid Current (A)
            //0b 3b 02 00 00 00 00 00 81 8c -> 00 06 40 a3 2f de 1b a5 //2  
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x81); 
            putchar0(0x8c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 138:                                                      
            //Request measurement - Grid power(W)
            //0b 3b 03 00 00 00 00 00 aa 88 -> 00 06 45 5e 8c d7 51 a0 //3  
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xaa); 
            putchar0(0x88); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 139:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0b 3b 17 00 00 00 00 00 b6 da -> 00 06 44 06 75 2c 87 1b //4 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xb6); 
            putchar0(0xda); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 140:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0b 3b 19 00 00 00 00 00 14 e3 -> 00 06 40 86 11 fb 80 c5 //5 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x14); 
            putchar0(0xe3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 141:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0b 3b 1b 00 00 00 00 00 42 eb -> 00 06 40 32 4a f6 19 c0 //6 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x42); 
            putchar0(0xeb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 142:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0b 3b 08 00 00 00 00 00 8f a5 -> 00 06 45 0a bc 0f b4 ac //7 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8f); 
            putchar0(0xa5); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 143:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0b 3b 09 00 00 00 00 00 a4 a1 -> 00 06 44 b7 b6 33 ad c3 //8 
            imInvNo = 0x0b;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa4); 
            putchar0(0xa1); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 144:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0b 4e 00 00 00 00 00 00 38 65 -> 00 06 00 02 11 d4 4f 65 //9 
            imInvNo = 0x0b;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x38); 
            putchar0(0x65); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 145:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0b 4e 05 00 00 00 00 00 bf 71 -> 00 06 00 06 0e 06 e8 e5 //a
            imInvNo = 0x0b;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xbf); 
            putchar0(0x71); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 146:                                                      
            //Request the state of the system module  
            //0b 32 00 00 00 00 00 00 ee c5 -> 00 06 02 02 02 00 69 73 //b 
            imInvNo = 0x0b;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xee); 
            putchar0(0xc5); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 147:
            inverter_seq++;
            break;
        case 148: 
            inverter_seq = 150;
            break;
            

        //Inv-11: RTU Master request frame ////////////////////////////////////////     
        //TX-11, Inverter NO : 0c
        case 150:           
            if (eeInverterCount > 10) { 
                if (sendInverterCount[10] < 100) {
                    sendInverterCount[10]++;
                    sprintf(str,"TX%02d",11);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 151:                                                      
            //Request measurement - Grid Voltage (V)
            //0c 3b 01 00 00 00 00 00 f2 1c -> 00 06 43 66 e1 38 73 61 //1  
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf2); 
            putchar0(0x1c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 152:                                                      
            //Request measurement - Grid Current (A)
            //0c 3b 02 00 00 00 00 00 8f 10 -> 00 06 41 5a 1f c9 16 7b //2 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8f); 
            putchar0(0x10); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 153:                                                      
            //Request measurement - Grid power(W)
            //0c 3b 03 00 00 00 00 00 a4 14 -> 00 06 46 13 f1 4e 61 35 //3 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa4); 
            putchar0(0x14); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 154:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0c 3b 17 00 00 00 00 00 b8 46 -> 00 06 44 0a fb cd 7f 5e //4 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xb8); 
            putchar0(0x46); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 155:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0c 3b 19 00 00 00 00 00 1a 7f -> 00 06 41 29 49 40 44 8a //5 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x1a); 
            putchar0(0x7f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 156:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0c 3b 1b 00 00 00 00 00 4c 77 -> 00 06 40 e1 5d 3e af 32 //6 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4c); 
            putchar0(0x77); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 157:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0c 3b 08 00 00 00 00 00 81 39 -> 00 06 45 b6 dd 72 ba 57 //7 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x81); 
            putchar0(0x39); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 158:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0c 3b 09 00 00 00 00 00 aa 3d -> 00 06 45 73 42 38 56 13 //8 
            imInvNo = 0x0c;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xaa); 
            putchar0(0x3d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 159:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0c 4e 00 00 00 00 00 00 36 f9 -> 00 06 00 02 0f 51 6b b9 //9 
            imInvNo = 0x0c;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x36); 
            putchar0(0xf9); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 160:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0c 4e 05 00 00 00 00 00 b1 ed -> 00 06 00 05 f0 49 67 56 //a
            imInvNo = 0x0c;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xb1); 
            putchar0(0xed); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 161:                                                      
            //Request the state of the system module  
            //0c 32 00 00 00 00 00 00 e0 59 -> 00 06 02 02 02 00 69 73 //b 
            imInvNo = 0x0c;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe0); 
            putchar0(0x59); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 162:
            inverter_seq++;
            break;
        case 163: 
            inverter_seq = 165;
            break;
            

        //Inv-12: RTU Master request frame ////////////////////////////////////////     
        //TX-12, Inverter NO : 0d
        case 165:           
            if (eeInverterCount > 11) { 
                if (sendInverterCount[11] < 100) {
                    sendInverterCount[11]++;
                    sprintf(str,"TX%02d", 12);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 166:                                                      
            //Request measurement - Grid Voltage (V)
            //0d 3b 01 00 00 00 00 00 4d 9d -> 00 06 43 67 72 ba 80 af //1 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4d); 
            putchar0(0x9d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 167:                                                      
            //Request measurement - Grid Current (A)
            //0d 3b 02 00 00 00 00 00 30 91 -> 00 06 41 5a a6 57 97 eb //2 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x30); 
            putchar0(0x91); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 168:                                                      
            //Request measurement - Grid power(W)
            //0d 3b 03 00 00 00 00 00 1b 95 -> 00 06 46 14 7a a7 cf ab //3 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x1b); 
            putchar0(0x95); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 169:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0d 3b 17 00 00 00 00 00 07 c7 -> 00 06 44 0b a4 ae 01 05 //4 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x07); 
            putchar0(0xc7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 170:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0d 3b 19 00 00 00 00 00 a5 fe -> 00 06 41 28 1f ec d9 38 //5 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa5); 
            putchar0(0xfe); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 171:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0d 3b 1b 00 00 00 00 00 f3 f6 -> 00 06 40 e1 03 7b e1 6e //6 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf3); 
            putchar0(0xf6); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 172:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0d 3b 08 00 00 00 00 00 3e b8 -> 00 06 45 b7 1e 91 31 38 //7 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x3e); 
            putchar0(0xb8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 173:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0d 3b 09 00 00 00 00 00 15 bc -> 00 06 45 74 d0 a7 c0 d9 //8 
            imInvNo = 0x0d;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x15); 
            putchar0(0xbc); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 174:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0d 4e 00 00 00 00 00 00 89 78 -> 00 06 00 02 15 4c ee 1a //9 
            imInvNo = 0x0d;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x89); 
            putchar0(0x78); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 175:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0d 4e 05 00 00 00 00 00 0e 6c -> 00 06 00 06 0a 94 13 35 //a 
            imInvNo = 0x0d;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x0e); 
            putchar0(0x6c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 176:                                                      
            //Request the state of the system module  
            //0d 32 00 00 00 00 00 00 5f d8 -> 00 06 02 02 02 00 69 73 //b 
            imInvNo = 0x0d;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5f); 
            putchar0(0xd8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 177:
            inverter_seq++;
            break;
        case 178: 
            inverter_seq = 180;
            break;
            

        //Inv-13: RTU Master request frame ////////////////////////////////////////     
        //TX-13, Inverter NO : 0e
        case 180:           
            if (eeInverterCount > 12) { 
                if (sendInverterCount[12] < 100) {
                    sendInverterCount[12]++;
                    sprintf(str,"TX%02d",13);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 181:                                                      
            //Request measurement - Grid Voltage (V)
            //0e 3b 01 00 00 00 00 00 9d 17 -> 00 06 43 66 89 c0 21 b1 //1 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9d); 
            putchar0(0x17); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 182:                                                      
            //Request measurement - Grid Current (A)
            //0e 3b 02 00 00 00 00 00 e0 1b -> 00 06 41 59 77 23 b3 77 //2 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe0); 
            putchar0(0x1b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 183:                                                      
            //Request measurement - Grid power(W)
            //0e 3b 03 00 00 00 00 00 cb 1f -> 00 06 46 13 3d f4 ba 4c //3
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xcb); 
            putchar0(0x1f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 184:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0e 3b 17 00 00 00 00 00 d7 4d -> 00 06 44 0b 64 8c bb cd //4 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd7); 
            putchar0(0x4d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 185:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0e 3b 19 00 00 00 00 00 75 74 -> 00 06 41 27 72 03 ca b8 //5 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x75); 
            putchar0(0x74); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 186:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0e 3b 1b 00 00 00 00 00 23 7c -> 00 06 40 e3 dc c8 ba 80 //6 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x23); 
            putchar0(0x7c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 187:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0e 3b 08 00 00 00 00 00 ee 32 -> 00 06 45 b5 04 9f 16 0c //7 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xee); 
            putchar0(0x32); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 188:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0e 3b 09 00 00 00 00 00 c5 36 -> 00 06 45 75 cf 94 5d 96 //8 
            imInvNo = 0x0e;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc5); 
            putchar0(0x36); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 189:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0e 4e 00 00 00 00 00 00 59 f2 -> 00 06 00 02 11 b9 ac dd //9 
            imInvNo = 0x0e;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x59); 
            putchar0(0xf2); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 190:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0e 4e 05 00 00 00 00 00 de e6 -> 00 06 00 06 03 e1 21 c6 //a 
            imInvNo = 0x0e;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xde); 
            putchar0(0xe6); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 191:                                                      
            //Request the state of the system module  
            //0e 32 00 00 00 00 00 00 8f 52 -> 00 06 02 02 02 00 69 73 //b 
            imInvNo = 0x0e;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x8f); 
            putchar0(0x52); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 192:
            inverter_seq++;
            break;
        case 193: 
            inverter_seq = 195;
            break;
            

        //Inv-14: RTU Master request frame ////////////////////////////////////////     
        //TX-14, Inverter NO : 0f
        case 195:           
            if (eeInverterCount > 13) { 
                if (sendInverterCount[13] < 100) {
                    sendInverterCount[13]++;
                    sprintf(str,"TX%02d",14);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 196:                                                      
            //Request measurement - Grid Voltage (V)
            //0f 3b 01 00 00 00 00 00 22 96 -> 00 06 43 66 68 64 4e a2 //1  
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x22); 
            putchar0(0x96); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 197:                                                      
            //Request measurement - Grid Current (A)
            //0f 3b 02 00 00 00 00 00 5f 9a -> 00 06 41 56 ad 28 ec 21 //2 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x5f); 
            putchar0(0x9a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 198:                                                      
            //Request measurement - Grid power(W)
            //0f 3b 03 00 00 00 00 00 74 9e -> 00 06 46 12 dd 61 db 3c //3 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x74); 
            putchar0(0x9e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 199:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //0f 3b 17 00 00 00 00 00 68 cc -> 00 06 44 0a e0 03 34 00 //4
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x68); 
            putchar0(0xcc); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 200:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //0f 3b 19 00 00 00 00 00 ca f5 -> 00 06 41 28 58 05 78 49 //5 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xca); 
            putchar0(0xf5); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 201:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //0f 3b 1b 00 00 00 00 00 9c fd -> 00 06 40 e0 66 67 3d f5 //6 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9c); 
            putchar0(0xfd); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 202:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //0f 3b 08 00 00 00 00 00 51 b3 -> 00 06 45 b4 b1 27 df 2b //7 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x51); 
            putchar0(0xb3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 203:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //0f 3b 09 00 00 00 00 00 7a b7 -> 00 06 45 72 6a 65 19 2d //8 
            imInvNo = 0x0f;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x7a); 
            putchar0(0xb7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 204:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //0f 4e 00 00 00 00 00 00 e6 73 -> 00 06 00 02 15 6f 77 09 //9 
            imInvNo = 0x0f;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe6); 
            putchar0(0x73); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 205:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //0f 4e 05 00 00 00 00 00 61 67 -> 00 06 00 06 0c ab b7 a8 //a 
            imInvNo = 0x0f;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x61); 
            putchar0(0x67); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 206:                                                      
            //Request the state of the system module  
            //0f 32 00 00 00 00 00 00 30 d3 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x0f;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x30); 
            putchar0(0xd3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 207:
            inverter_seq++;
            break;
        case 208: 
            inverter_seq = 210;
            break;
            

        //Inv-15: RTU Master request frame ////////////////////////////////////////     
        //TX-15, Inverter NO : 0x10
        case 210:           
            if (eeInverterCount > 14) { 
                if (sendInverterCount[14] < 100) {
                    sendInverterCount[14]++;
                    sprintf(str,"TX%02d",15);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 211:                                                      
            //Request measurement - Grid Voltage (V)
            //10 3b 01 00 00 00 00 00 e8 7c -> 00 06 43 67 9c 3b 88 49 //1 
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe8); 
            putchar0(0x7c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 212:                                                      
            //Request measurement - Grid Current (A)
            //10 3b 02 00 00 00 00 00 95 70 -> 00 06 41 59 fe 19 be b2 //2
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x95); 
            putchar0(0x70); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 213:                                                      
            //Request measurement - Grid power(W)
            //10 3b 03 00 00 00 00 00 be 74 -> 00 06 46 13 a3 64 7e 5b //3 
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xbe); 
            putchar0(0x74); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 214:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //10 3b 17 00 00 00 00 00 a2 26 -> 00 06 44 0b 75 a6 aa cf //4
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xa2); 
            putchar0(0x26); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 215:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //10 3b 19 00 00 00 00 00 00 1f -> 00 06 41 25 ee ec 76 a2 //5
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x1f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 216:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //10 3b 1b 00 00 00 00 00 56 17 -> 00 06 40 dc 7f d2 9f 76 //6 
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x56); 
            putchar0(0x17); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 217:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //10 3b 08 00 00 00 00 00 9b 59 -> 00 06 45 b6 9a a7 f4 dd //7 
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9b); 
            putchar0(0x59); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 218:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //10 3b 09 00 00 00 00 00 b0 5d -> 00 06 45 71 b9 26 b1 c7 //8 
            imInvNo = 0x10;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xb0); 
            putchar0(0x5d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 219:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //10 4e 00 00 00 00 00 00 2c 99 -> 00 06 00 02 18 f0 71 d5 //9
            imInvNo = 0x10;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x2c); 
            putchar0(0x99); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 220:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //10 4e 05 00 00 00 00 00 ab 8d -> 00 06 00 06 15 40 e3 b3 //a
            imInvNo = 0x10;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xab); 
            putchar0(0x8d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 221:                                                      
            //Request the state of the system module  
            //10 32 00 00 00 00 00 00 fa 39 -> 00 06 02 02 02 00 69 73 //b 
            imInvNo = 0x10;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfa); 
            putchar0(0x39); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 222:
            inverter_seq++;
            break;
        case 223: 
            inverter_seq = 225;
            break;
            

        //Inv-16: RTU Master request frame ////////////////////////////////////////     
        //TX-16, Inverter NO : 0x11
        case 225:           
            if (eeInverterCount > 15) { 
                if (sendInverterCount[15] < 100) {
                    sendInverterCount[15]++;
                    sprintf(str,"TX%02d",16);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 226:                                                      
            //Request measurement - Grid Voltage (V)
            //11 3b 01 00 00 00 00 00 57 fd -> 00 06 43 66 ab 16 19 12 //1
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x57); 
            putchar0(0xfd); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 227:                                                      
            //Request measurement - Grid Current (A)
            //11 3b 02 00 00 00 00 00 2a f1 -> 00 06 41 53 2c 1e f0 d9 //2
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x2a); 
            putchar0(0xf1); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 228:                                                      
            //Request measurement - Grid power(W)
            //11 3b 03 00 00 00 00 00 01 f5 -> 00 06 46 0f 9d bd b6 1c //3
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x01); 
            putchar0(0xf5); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 229:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //11 3b 17 00 00 00 00 00 1d a7 -> 00 06 44 0a b0 fb 04 a8 //4
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x1d); 
            putchar0(0xa7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 230:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //11 3b 19 00 00 00 00 00 bf 9e -> 00 06 41 24 e1 a4 2e b5 //5
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xbf); 
            putchar0(0x9e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 231:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //11 3b 1b 00 00 00 00 00 e9 96 -> 00 06 40 dd d0 6c 81 5c //6
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xe9); 
            putchar0(0x96); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 232:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //11 3b 08 00 00 00 00 00 24 d8 -> 00 06 45 b1 8c 56 b6 76 //7
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x24); 
            putchar0(0xd8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 233:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //11 3b 09 00 00 00 00 00 0f dc -> 00 06 45 6e 62 be b1 ab //8
            imInvNo = 0x11;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x0f); 
            putchar0(0xdc); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 234:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //11 4e 00 00 00 00 00 00 93 18 -> 00 06 00 02 11 6c 8c 5c //9
            imInvNo = 0x11;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x93); 
            putchar0(0x18); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 235:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //11 4e 05 00 00 00 00 00 14 0c -> 00 06 00 05 f2 64 30 9f //a    
            imInvNo = 0x11;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x14); 
            putchar0(0x0c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 236:                                                      
            //Request the state of the system module  
            //11 32 00 00 00 00 00 00 45 b8 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x11;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x45); 
            putchar0(0xb8); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 237:
            inverter_seq++;
            break;
        case 238: 
            inverter_seq = 240;
            break;
            

        //Inv-17: RTU Master request frame ////////////////////////////////////////     
        //TX-17, Inverter NO : 0x12
        case 240:           
            if (eeInverterCount > 16) { 
                if (sendInverterCount[16] < 100) {
                    sendInverterCount[16]++;
                    sprintf(str,"TX%02d",17);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 241:                                                      
            //Request measurement - Grid Voltage (V)
            //12 3b 01 00 00 00 00 00 87 77 -> 00 06 43 67 9c 3b 88 49 //1
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x87); 
            putchar0(0x77); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 242:                                                      
            //Request measurement - Grid Current (A)
            //12 3b 02 00 00 00 00 00 fa 7b -> 00 06 41 51 65 f8 0e 7f //2    
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfa); 
            putchar0(0x7b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 243:                                                      
            //Request measurement - Grid power(W)
            //12 3b 03 00 00 00 00 00 d1 7f -> 00 06 46 0f 27 27 7b e0 //3
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd1); 
            putchar0(0x7f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 244:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //12 3b 17 00 00 00 00 00 cd 2d -> 00 06 44 0b 82 7a 4b e2 //4
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xcd); 
            putchar0(0x2d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 245:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //12 3b 19 00 00 00 00 00 6f 14 -> 00 06 41 23 15 9f 13 ad //5
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x6f); 
            putchar0(0x14); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 246:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //12 3b 1b 00 00 00 00 00 39 1c -> 00 06 40 dc 04 67 d5 80 //6
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x39); 
            putchar0(0x1c); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 247:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //12 3b 08 00 00 00 00 00 f4 52 -> 00 06 45 af b2 4d d8 61 //7
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf4); 
            putchar0(0x52); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 248:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //12 3b 09 00 00 00 00 00 df 56 -> 00 06 45 6c d7 3b 7a 89 //8
            imInvNo = 0x12;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xdf); 
            putchar0(0x56); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 249:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //12 4e 00 00 00 00 00 00 43 92 -> 00 06 00 02 17 67 8f b6 //9
            imInvNo = 0x12;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x43); 
            putchar0(0x92); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 250:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //12 4e 05 00 00 00 00 00 c4 86 -> 00 06 00 06 0c af 93 ee //a
            imInvNo = 0x12;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc4); 
            putchar0(0x86); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 251:                                                      
            //Request the state of the system module  
            //12 32 00 00 00 00 00 00 95 32 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x12;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x95); 
            putchar0(0x32); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 252:
            inverter_seq++;
            break;
        case 253: 
            inverter_seq = 255;
            break;
            
        case 255:
           
            if (eeInverterCount > 17) { 
                if (sendInverterCount[17] < 100) {
                    sendInverterCount[17]++;
                    sprintf(str,"TX%02d",18);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 256:                                                      
            //Request measurement - Grid Voltage (V)
            //12 3b 01 00 00 00 00 00 87 77 -> 00 06 43 67 9c 3b 88 49 //1
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x38); 
            putchar0(0xF6); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 257:                                                      
            //Request measurement - Grid Current (A)
            //12 3b 02 00 00 00 00 00 fa 7b -> 00 06 41 51 65 f8 0e 7f //2    
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x45); 
            putchar0(0xFA); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 258:                                                      
            //Request measurement - Grid power(W)
            //12 3b 03 00 00 00 00 00 d1 7f -> 00 06 46 0f 27 27 7b e0 //3
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x6e); 
            putchar0(0xfe); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 259:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //12 3b 17 00 00 00 00 00 cd 2d -> 00 06 44 0b 82 7a 4b e2 //4
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x72); 
            putchar0(0xac); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 260:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //12 3b 19 00 00 00 00 00 6f 14 -> 00 06 41 23 15 9f 13 ad //5
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd0); 
            putchar0(0x95); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 261:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //12 3b 1b 00 00 00 00 00 39 1c -> 00 06 40 dc 04 67 d5 80 //6
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x86); 
            putchar0(0x9d); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 262:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //12 3b 08 00 00 00 00 00 f4 52 -> 00 06 45 af b2 4d d8 61 //7
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4b); 
            putchar0(0xd3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 263:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //12 3b 09 00 00 00 00 00 df 56 -> 00 06 45 6c d7 3b 7a 89 //8
            imInvNo = 0x13;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x60); 
            putchar0(0xd7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 264:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //12 4e 00 00 00 00 00 00 43 92 -> 00 06 00 02 17 67 8f b6 //9
            imInvNo = 0x13;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfc); 
            putchar0(0x13); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
                     
        case 265:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //12 4e 05 00 00 00 00 00 c4 86 -> 00 06 00 06 0c af 93 ee //a
            imInvNo = 0x13;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x7b); 
            putchar0(0x07); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 266:                                                      
            //Request the state of the system module  
            //12 32 00 00 00 00 00 00 95 32 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x13;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x2a); 
            putchar0(0xb3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 267:
            inverter_seq++;
            break;
        case 268: 
            inverter_seq = 270;
            break;
            
        case 270:           
            if (eeInverterCount > 18) { 
                if (sendInverterCount[18] < 100) {
                    sendInverterCount[18]++;
                    sprintf(str,"TX%02d",19);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 271:                                                      
            //Request measurement - Grid Voltage (V)
            //12 3b 01 00 00 00 00 00 87 77 -> 00 06 43 67 9c 3b 88 49 //1
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x36); 
            putchar0(0x6a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 272:                                                      
            //Request measurement - Grid Current (A)
            //12 3b 02 00 00 00 00 00 fa 7b -> 00 06 41 51 65 f8 0e 7f //2    
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4b); 
            putchar0(0x66); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 273:                                                      
            //Request measurement - Grid power(W)
            //12 3b 03 00 00 00 00 00 d1 7f -> 00 06 46 0f 27 27 7b e0 //3
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x60); 
            putchar0(0x62); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 274:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //12 3b 17 00 00 00 00 00 cd 2d -> 00 06 44 0b 82 7a 4b e2 //4
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x7c); 
            putchar0(0x30); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 275:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //12 3b 19 00 00 00 00 00 6f 14 -> 00 06 41 23 15 9f 13 ad //5
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xde); 
            putchar0(0x09); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 276:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //12 3b 1b 00 00 00 00 00 39 1c -> 00 06 40 dc 04 67 d5 80 //6
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x88); 
            putchar0(0x01); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 277:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //12 3b 08 00 00 00 00 00 f4 52 -> 00 06 45 af b2 4d d8 61 //7
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x45); 
            putchar0(0x4f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 278:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //12 3b 09 00 00 00 00 00 df 56 -> 00 06 45 6c d7 3b 7a 89 //8
            imInvNo = 0x14;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x6e); 
            putchar0(0x4b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 279:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //12 4e 00 00 00 00 00 00 43 92 -> 00 06 00 02 17 67 8f b6 //9
            imInvNo = 0x14;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf2); 
            putchar0(0x8f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 280:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //12 4e 05 00 00 00 00 00 c4 86 -> 00 06 00 06 0c af 93 ee //a
            imInvNo = 0x14;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x75); 
            putchar0(0x9b); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 281:                                                      
            //Request the state of the system module  
            //12 32 00 00 00 00 00 00 95 32 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x14;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x24); 
            putchar0(0x2f); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 282:
            inverter_seq++;
            break;
        case 283: 
            inverter_seq = 285;
            break;
            
        case 285:           
            if (eeInverterCount > 19) { 
                if (sendInverterCount[19] < 100) {
                    sendInverterCount[19]++;
                    sprintf(str,"TX%02d",20);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;                   
        case 286:                                                      
            //Request measurement - Grid Voltage (V)
            //12 3b 01 00 00 00 00 00 87 77 -> 00 06 43 67 9c 3b 88 49 //1
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x01;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x89); 
            putchar0(0xeb); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 287:                                                      
            //Request measurement - Grid Current (A)
            //12 3b 02 00 00 00 00 00 fa 7b -> 00 06 41 51 65 f8 0e 7f //2    
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x02;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xf4); 
            putchar0(0xe7); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         

        case 288:                                                      
            //Request measurement - Grid power(W)
            //12 3b 03 00 00 00 00 00 d1 7f -> 00 06 46 0f 27 27 7b e0 //3
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x03;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xdf); 
            putchar0(0xe3); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
            
        case 289:                                                      
            //Request measurement - //PV Voltage (Float 1:1)   
            //12 3b 17 00 00 00 00 00 cd 2d -> 00 06 44 0b 82 7a 4b e2 //4
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x17;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xc3); 
            putchar0(0xb1); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;        

        case 290:                                                      
            //Request measurement - //PV-1 Current (Float 1:1)     
            //12 3b 19 00 00 00 00 00 6f 14 -> 00 06 41 23 15 9f 13 ad //5
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x19;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x61); 
            putchar0(0x88); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                              
        case 291:                                                      
            //Request measurement - //PV-2 Current (Float 1:1) 
            //12 3b 1b 00 00 00 00 00 39 1c -> 00 06 40 dc 04 67 d5 80 //6
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x1b;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x37); 
            putchar0(0x80); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                        
        case 292:                                                      
            //Request measurement - //PV-1 POwer (Float * 10) 
            //12 3b 08 00 00 00 00 00 f4 52 -> 00 06 45 af b2 4d d8 61 //7
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x08;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xfa); 
            putchar0(0xce); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
                           
        case 293:                                                      
            //Request measurement - //PV-2 POwer (Float * 10) 
            //12 3b 09 00 00 00 00 00 df 56 -> 00 06 45 6c d7 3b 7a 89 //8
            imInvNo = 0x15;          
            inv_command = 0x3b;
            inv_command2 = 0x09;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xd1); 
            putchar0(0xca); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;               
            
        case 294:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (daily energy)
            //12 4e 00 00 00 00 00 00 43 92 -> 00 06 00 02 17 67 8f b6 //9
            imInvNo = 0x15;          
            inv_command = 0x4e;
            inv_command2 = 0x00;
            
            putchar0(0x4e); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x4d); 
            putchar0(0x0e); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;         
        case 295:  //Inv-2: RTU Master request frame                                                 
            //Cumulated energy readings (total energy (total lifetime))
            //12 4e 05 00 00 00 00 00 c4 86 -> 00 06 00 06 0c af 93 ee //a
            imInvNo = 0x15;          
            inv_command = 0x4e;
            inv_command2 = 0x05;
            
            putchar0(0x4e); 
            putchar0(0x05); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0xca); 
            putchar0(0x1a); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break;
            
        case 296:                                                      
            //Request the state of the system module  
            //12 32 00 00 00 00 00 00 95 32 -> 00 06 02 02 02 00 69 73 //b
            imInvNo = 0x15;          
            inv_command = 0x32;
            inv_command2 = 0x00;
            
            putchar0(inv_command); 
            putchar0(inv_command2); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x00); 
            putchar0(0x9b); 
            putchar0(0xae); 

            rx_seq0 = 0;                           
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, imInvNo);  
#else  
			UDR0 = imInvNo ;  
#endif        
            inverter_seq++;             
            break; 
                                              
        case 297:
            inverter_seq++;
            break;
            
        case 298:  
            inverter_seq = 0;
            break;
            
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_Abb27K(void) {   
    char rxdata;   
    unsigned int rCrc;//, cCrc;
    unsigned int check_value;
    rxdata = getchar0();
    
    
    switch(rx_seq0) {
        case 0: //STX (Trans.State)        
            if (rxdata == 0x00) {
                timeout0 = 250;
                rx_seq0++;
            } 
            break;        
        case 1: //Global State 
//            if (rxdata == 0x06) {
//                rcnt = 0;           
//                memset(rxbuff,0,sizeof(rxbuff));
//                rx_seq0++;
//            } else {
//                rx_seq0 = 0;
//            }        
            rcnt = 0;           
            memset(rxbuff,0,sizeof(rxbuff)); 
            rxbuff[rcnt++] = rxdata;
            rx_seq0++;                   
            break;
        case 2: //rx Count
            rxbuff[rcnt++] = rxdata;
            
            if (rcnt == 7) {
                rCrc = rxbuff[5] * 0x100;
                rCrc += rxbuff[4];
                //cCrc = calcCRC(rxbuff,4);         
                
                invNo = imInvNo - 2;
                    
                switch(inv_command) {     
                    case 0x32: 
                        inverter[invNo].inverter_status[0] = rxbuff[0];            
                        inverter[invNo].inverter_status[1] = rxbuff[1];              
                        inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[2],rxbuff[3]);             
                        inverter[invNo].inverter_status[3] = rxbuff[4];   
//                            sprintf(str,"STS:%02X,%02X,%02X,%02X,%02X ",rxbuff[0],rxbuff[1],rxbuff[2],rxbuff[3],rxbuff[4]);   
//                            buzzer_flag |= BUZZER_TIC;
//                            put_str(0,0,str,1);   
                        break;     
                        
                    case 0x4e:
                        if (inv_command2 == 0x00) {
                            uLong.cc[3] = rxbuff[1];                    
                            uLong.cc[2] = rxbuff[2];                    
                            uLong.cc[1] = rxbuff[3];                    
                            uLong.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)(uLong.ff/1000);
                            
                            if( check_value < 9999 )
                            {
                                inverter[invNo].power_inv_day_total = check_value;
                            }
                             
                        } else if (inv_command2 == 0x05) {        
                            uLong.cc[3] = rxbuff[1];                    
                            uLong.cc[2] = rxbuff[2];                    
                            uLong.cc[1] = rxbuff[3];                    
                            uLong.cc[0] = rxbuff[4];                        
                            
                            //if(inverter[invNo].power_inv_total < uLong.ff/1000)
                            inverter[invNo].power_inv_total = uLong.ff/1000; 
                           

                            sendInverterCount[invNo] = 0;
                            buzzer_flag |= BUZZER_TIC;
                            sprintf(str,"RX%02d", imInvNo-1);
                            put_str(4,16,str,1);   
                            rx_led_delay = 2500;

                        }                      
                        break;

                    case 0x3b:
                        if (inv_command2 == 0x01) {
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff;
                            
                            if( check_value < 9999 )
                            {                   
                                inverter[invNo].inv_u_voltage = check_value; 
                                inverter[invNo].inv_v_voltage = inverter[invNo].inv_u_voltage;
                                inverter[invNo].inv_w_voltage = inverter[invNo].inv_u_voltage;
                            }
                            
                        } else if (inv_command2 == 0x02) {
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff;
                            
                            if( check_value < 9999 )
                            {                    
                                inverter[invNo].inv_u_current = check_value; 
                                inverter[invNo].inv_v_current = inverter[invNo].inv_u_current; 
                                inverter[invNo].inv_w_current = inverter[invNo].inv_u_current;
                             }
                             
                        } else if (inv_command2 == 0x03) {
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff / 100;
                            
                            if( check_value < 9999  )
                            {
                                if (inverter[invNo].inv_u_current == 0 && inverter[invNo].solar_cell_current == 0)
                                    inverter[invNo].power_inv_now = 0;
                                else
                                    inverter[invNo].power_inv_now = check_value;    
                            }                   
                            
                            if(inverter[invNo].inverter_status[0] != 6)
                                inverter[invNo].power_inv_now = 0;
                                
                            
                            inverter[invNo].inv_frequency = 600; 
                        } else if (inv_command2 == 0x17) {   
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff;
                            
                            if( check_value < 9999 )
                            {
                                inverter[invNo].solar_cell_voltage = check_value; 
                            }
                            
                        } else if (inv_command2 == 0x19) {   
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff;
                            
                            if( check_value < 9999 )
                            {                    
                                inverter[invNo].solar_cell_current = check_value;
                            }
                             
                        } else if (inv_command2 == 0x1b) {   
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff;
                            
                            if( check_value < 9999 )
                            {
                                inverter[invNo].solar_cell_current += check_value;
                            }
                             
                        } else if (inv_command2 == 0x08) {   
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4];
                            
                            check_value = (unsigned int)uFloat.ff / 100;
                            
                            if( check_value < 9999 )
                            {                    
                                inverter[invNo].power_solar = check_value;
                            }
                            
                        } else if (inv_command2 == 0x09) {   
                            uFloat.cc[3] = rxbuff[1];                    
                            uFloat.cc[2] = rxbuff[2];                    
                            uFloat.cc[1] = rxbuff[3];                    
                            uFloat.cc[0] = rxbuff[4]; 
                            
                            check_value = (unsigned int)uFloat.ff / 100;
                            
                            if( check_value < 9999 )
                            {
                                inverter[invNo].power_solar += check_value;
                            }
                        }
                        break;
                }


                rx_seq0 = 0;
            }                     
            break;   


        default:
            rx_seq0 = 0;
            break;
    }
}
