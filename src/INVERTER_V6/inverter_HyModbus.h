void sendInverterRead_HyModbus(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			if (sendInverterCount[0] < 100) {
            	sendInverterCount[0]++;
            }
            break;     
        case 1:     //Inv-1: RTU Master request frame  
        	//01 03 02 BB 00 1D F4 5E => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0; 
            
//            putchar0(0x03); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x5E); //CRC_H  
            
			sendBuff[0] = 0x01;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);

//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
            
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-1");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
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
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 11:     //Inv-2: RTU Master request frame  
        	//02 03 02 BB 00 1D F4 6D => 01 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x01); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x03); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x02;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x02);  
#else  
			UDR0 = 0x02 ;  
#endif  
            sprintf(str,"TX-2");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
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
        	if (eeInverterCount > 2) { 
                if (sendInverterCount[2] < 100) {
                    sendInverterCount[2]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 21:     //Inv-3: RTU Master request frame  
        	//03 03 02 BB 00 1D F4 6D => 03 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x03); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x03); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x03;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x03);  
#else  
			UDR0 = 0x03 ;  
#endif  
            sprintf(str,"TX-3");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
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
        	if (eeInverterCount > 3) { 
                if (sendInverterCount[3] < 100) {
                    sendInverterCount[3]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 31:     //Inv-4: RTU Master request frame  
        	//04 03 02 BB 00 1D F4 6D => 04 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x04); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x04); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x04;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x04);  
#else  
			UDR0 = 0x04 ;  
#endif  
            sprintf(str,"TX-4");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
            inverter_seq++;
            break;
                 
        case 40:           
        	if (eeInverterCount > 4) { 
                if (sendInverterCount[4] < 100) {
                    sendInverterCount[4]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 41:     //Inv-5: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x05); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x05;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x05);  
#else  
			UDR0 = 0x05 ;  
#endif  
            sprintf(str,"TX-5");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            inverter_seq++;
            break;     

        case 50:           
        	if (eeInverterCount > 5) { 
                if (sendInverterCount[5] < 100) {
                    sendInverterCount[5]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 51:     //Inv-6: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x06); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x06;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x06);  
#else  
			UDR0 = 0x06 ;  
#endif  
            sprintf(str,"TX-6");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
            inverter_seq++;
            break;     

        case 60:           
        	if (eeInverterCount > 6) { 
                if (sendInverterCount[6] < 100) {
                    sendInverterCount[6]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 61:     //Inv-7: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x07); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x07;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x07);  
#else  
			UDR0 = 0x07 ;  
#endif  
            sprintf(str,"TX-7");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
            inverter_seq++;
            break;     

        case 70:           
        	if (eeInverterCount > 7) { 
                if (sendInverterCount[7] < 100) {
                    sendInverterCount[7]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 71:     //Inv-8: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x08); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x08;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x08);  
#else  
			UDR0 = 0x08 ;  
#endif  
            sprintf(str,"TX-8");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            inverter_seq++;
            break;     

        case 80:           
        	if (eeInverterCount > 8) { 
                if (sendInverterCount[8] < 100) {
                    sendInverterCount[8]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 81:     //Inv-9: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x09); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x09;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x09);  
#else  
			UDR0 = 0x09 ;  
#endif  
            sprintf(str,"TX-9");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            inverter_seq++;
            break;     

        case 90:           
        	if (eeInverterCount > 9) { 
                if (sendInverterCount[9] < 100) {
                    sendInverterCount[9]++;
                }            
            	inverter_seq++;
        	} else {
				inverter_seq = 0;            	
            }
            break;         
        case 91:     //Inv-A: RTU Master request frame  
        	//05 03 02 BB 00 1D F4 6D => 05 03 10 0f 83 0f 92 0f 86 01 72 01 67 01 6a 00 00 02 58 eb a1
            //putchar0(0x05); //Slave Address     
			rx_seq0 = 0;
//            putchar0(0x0A); //Function Code
//            putchar0(0x02); //Modbus Address High
//            putchar0(0xBB); //Modbus Address Low
//            putchar0(0x00); //Data Count High
//            putchar0(0x1D); //Data Count Low
//            putchar0(0xF4); //CRC_L
//            putchar0(0x6D); //CRC_H 
            
            
			sendBuff[0] = 0x0A;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x02; //Modbus Address High
            sendBuff[3] = 0xBB; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1D; //Data Count Low (29)
    		retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
		    putchar0(retVal % 0x100);   //2a.73
    		putchar0(retVal / 0x100);         
            
//            sprintf(str,"%02X %02X ", retVal % 0x100, retVal / 0x100);
//            put_str(0,0,str,1);
                        
            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x0A);  
#else  
			UDR0 = 0x0A ;  
#endif  
            sprintf(str,"TX-A");     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
            break;         
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
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



void rx0Control_HyModbus(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata > 0x00) && (rxdata < 0x0b)) {
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
            	rx_seq0++;
            }
			break;        
        case 1: //Device (Slave) 
            if (rxdata == 0x03) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            if (rxdata == 0x3a) {   
            	dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 60) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,58+3);   
                rxCrc = rxbuff[62];
                rxCrc <<= 8;
                rxCrc += rxbuff[61];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[5],rxbuff[6]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[7],rxbuff[8]); 
                	inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[9],rxbuff[10]); 
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[11],rxbuff[12]); 
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[15],rxbuff[16]);
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[17],rxbuff[18]);
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20]);
                	inverter[invNo].power_inv_now         = Bytes_to_Uint(rxbuff[21],rxbuff[22]);  
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[23],rxbuff[24]);
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[29],rxbuff[30]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[31],rxbuff[32]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[33],rxbuff[34]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[47],rxbuff[48]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[51],rxbuff[52]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[53],rxbuff[54]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[55],rxbuff[56]);             
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 10;
                	inverter[invNo].inv_v_current      /= 10;
                	inverter[invNo].inv_w_current      /= 10;
                	inverter[invNo].power_inv_day_total /= 10;

	                sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX-%01d",invNo+1);
    	            put_str(4,16,str,1);   
        	        rx_led_delay = 2500;
                }
            	rx_seq0 = 0;
            }
            break;

		default:
			rx_seq0 = 0;
			break;
	}
}
