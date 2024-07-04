unsigned long int Bytes_to_Ulint(unsigned char c3, unsigned char c2, unsigned char c1, unsigned char c0) {
   unsigned long int ulint1;
    ulint1 = c3;
    ulint1 <<= 8;
    ulint1 += c2;
	ulint1 <<= 8;
	ulint1 += c1;
    ulint1 <<= 8;
    ulint1 += c0;
	
    return ulint1;
}

   unsigned char command1=0;
   unsigned char command2=0;


void sendInverterRead_AbbModbus1M(void) {
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
    
         rx_seq0 = 0;                           
           
         command1 = 0x9D; 
         command2 = 0x09;
         
         sendBuff[0] = 0x01;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         // Parameter Groups 01..09 (104;0068H)
          sendBuff[2] = command1; //Modbus Address High
          sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
          sendBuff[4] = 0x00; //Data Count High
          sendBuff[5] = 0x18; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            
            break; 
         
        case 2:
    
         rx_seq0 = 0;                           
           
         command1 = 0x43; 
         //command2 = 0x95;
         command2 = 0x94;
         
         sendBuff[0] = 0x01;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = command1; //Modbus Address High
            sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x05; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);
   
//          sprintf(str,"CRC:%04X ",retVal);
//            put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
         
         break;
      
        case 3:
   
         rx_seq0 = 0;                           
           
         command1 = 0x00; 
         command2 = 0x35;
         
         sendBuff[0] = 0x01;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = command1; //Modbus Address High
            sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x04; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);
   
//          sprintf(str,"CRC:%04X ",retVal);
//            put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
         
         break;
      
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14: 
           inverter_seq++;
            break;
        case 15:           
           if (eeInverterCount > 1) { 
                if (sendInverterCount[1] < 100) {
                    sendInverterCount[1]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;         
        case 16:     //Inv-1: RTU Master request frame  
    
         rx_seq0 = 0;                           
           
         command1 = 0x9D; 
         command2 = 0x09;
         
         sendBuff[0] = 0x02;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         // Parameter Groups 01..09 (104;0068H)
          sendBuff[2] = command1; //Modbus Address High
          sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
          sendBuff[4] = 0x00; //Data Count High
          sendBuff[5] = 0x18; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            
            break; 
         
        case 17:
    
         rx_seq0 = 0;                           
           
         command1 = 0x43; 
         command2 = 0x95;
         
         sendBuff[0] = 0x02;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = command1; //Modbus Address High
            sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x05; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);
   
//          sprintf(str,"CRC:%04X ",retVal);
//            put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
         
         break;
      
        case 18:
   
         rx_seq0 = 0;                           
           
         command1 = 0x00; 
         command2 = 0x35;
         
         sendBuff[0] = 0x02;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
            // Parameter Groups 01..09 (104;0068H)
            sendBuff[2] = command1; //Modbus Address High
            sendBuff[3] = command2; //Modbus Address Low 101.01(40202)
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x03; //Data Count Low (24)
          retVal = calcCRC(sendBuff,6);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High
            putchar0(sendBuff[3]); //Modbus Address Low
            putchar0(sendBuff[4]); //Data Count High
            putchar0(sendBuff[5]); //Data Count Low           
          putchar0(retVal % 0x100);   //2a.73
          putchar0(retVal / 0x100);
   
//          sprintf(str,"CRC:%04X ",retVal);
//            put_str(0,0,str,2);

            TXEN=1;TXEN=1; 
            
#if (UDR_CLONE_MODE == 1)
			write_dudr ( 0, 0x01);  
#else  
			UDR0 = 0x01 ;  
#endif        
            sprintf(str,"TX-%d",1);
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;
         
         break;
                  
        case 19:
        case 20:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_AbbModbus1M(void) {   
   char rxdata;   
   unsigned long int imlog = 0;
   rxdata = getchar0();
   
   switch(rx_seq0) {
      case 0: //STX        
           if ( (rxdata == 0x01) || (rxdata == 0x02) || (rxdata == 0x03) ){
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
            if ((rxdata == 0x30 && command1 ==0x9d ) || (rxdata == 0x0a && command1==0x43) || (rxdata == 0x08 && command1 == 0x00)) {   
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
//            if (dcnt == 58) {
            if (dcnt == 48 && command1 ==0x9d) {
               buzzer_flag |= BUZZER_TIC;
               put_strf(4,16,C_RXOK,1);   
               rx_led_delay = 2500;

                   //if (1) {   //CRC-16 Check
                    //invNo = 0;
                invNo = rxbuff[0] - 1;

				inverter[invNo].solar_cell_voltage = (unsigned int)(Bytes_to_Ulint(rxbuff[3],rxbuff[4],rxbuff[5],rxbuff[6])/100);
				inverter[invNo].solar_cell_current = (unsigned int)(Bytes_to_Ulint(rxbuff[7],rxbuff[8],rxbuff[9],rxbuff[10])/100);
				
				inverter[invNo].inv_u_current      = (unsigned int)(Bytes_to_Ulint(rxbuff[15],rxbuff[16],rxbuff[17],rxbuff[18])/100);
				inverter[invNo].inv_v_current	   = inverter[invNo].inv_u_current;
				inverter[invNo].inv_w_current	   = inverter[invNo].inv_u_current;
				
				inverter[invNo].inv_frequency      = Bytes_to_Uint(rxbuff[33],rxbuff[34]);
				inverter[invNo].inv_u_voltage      = (unsigned int)(Bytes_to_Ulint(rxbuff[35],rxbuff[36],rxbuff[37],rxbuff[38])/100);
				inverter[invNo].inv_v_voltage	   = inverter[invNo].inv_u_voltage;
				inverter[invNo].inv_w_voltage	   = inverter[invNo].inv_u_voltage;
				
				inverter[invNo].power_inv_now      = (unsigned int)(Bytes_to_Ulint(rxbuff[47],rxbuff[48],rxbuff[49],rxbuff[50])/10);
                inverter[invNo].power_inv_pf        = 950;
                
				inverter[invNo].power_solar        = inverter[invNo].power_inv_now;
	                  
                
           
                   //inverter[invNo].power_solar         *= 10; 
                  

                   sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;

                rx_seq0 = 0;
            }
			
			if (dcnt == 10 && command1 ==0x43) {
               buzzer_flag |= BUZZER_TIC;
               put_strf(4,16,C_RXOK,1);   
               rx_led_delay = 2500;

               invNo = rxbuff[0] - 1;
			   
			   
			   inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);            
               inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);              
               inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);             
               inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[11],rxbuff[12]);             

               sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;

               
			   
			   rx_seq0 = 0;
			}
			
			if (dcnt == 8 && command1 ==0x00) {
               buzzer_flag |= BUZZER_TIC;
               put_strf(4,16,C_RXOK,1);   
               rx_led_delay = 2500;

               invNo = rxbuff[0] - 1;
	
				inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
				
                inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
				inverter[invNo].power_inv_total    *= 1000;
				inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[7],rxbuff[8]);
				inverter[invNo].power_inv_total    *= 1000;
				inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[5],rxbuff[6])/10;


                  sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                sprintf(str,"RX-%01d",invNo+1);
                put_str(4,16,str,1);   
                rx_led_delay = 2500;

				
				rx_seq0 = 0;
			}		  
			
            break;
         
         
            

      default:
         rx_seq0 = 0;
         break;
   }
}