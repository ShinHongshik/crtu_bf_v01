//unsigned int accCurrent[20];

void sendInverterRead_Canadian50K(void) {  
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
      
         inverter_address = 1;
      
         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         sendBuff[2] = 0x03; //Modbus Address High
         sendBuff[3] = 0x00; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x21; //Data Count Low (58)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;
         
        case 2:
      
      
         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         sendBuff[2] = 0x03; //Modbus Address High
         sendBuff[3] = 0x59; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x02; //Data Count Low (58)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;
         
        case 3:

            inverter_seq++;             
            break;
      
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
           inverter_seq++;
            break;

        case 10:   
        
           inverter_address++;
           if (eeInverterCount+1 > inverter_address) { 
                if (sendInverterCount[inverter_address-1] < 100) {
                    sendInverterCount[inverter_address-1]++;
                }            
               inverter_seq++;
           } else {
            inverter_seq = 0;               
            }
            break;
         
        case 11:     //Inv-2: RTU Master request frame  

		rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         sendBuff[2] = 0x03; //Modbus Address High
         sendBuff[3] = 0x00; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x21; //Data Count Low (58)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break; 
         
        case 12:

         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x03;   //Function Code
         sendBuff[2] = 0x03; //Modbus Address High
         sendBuff[3] = 0x59; //Modbus Address Low
         sendBuff[4] = 0x00; //Data Count High
         sendBuff[5] = 0x02; //Data Count Low (58)
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
			write_udr0 (inverter_address);  
#else  
			UDR0 = inverter_address ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;

        case 13:

            inverter_seq++;             
            break;
      
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            inverter_seq=10;
            break;     

        default:  
            inverter_seq = 0;
            break;
    }
}





void rx0Control_Canadian50K(void) {   
   char rxdata;   
    unsigned int calCrc,rxCrc,temp_data;
    unsigned long int imlong;
   rxdata = getchar0();
   
   switch(rx_seq0) {
      
      case 0: //STX        
           if ( (rxdata > 0x00) && (rxdata < 0x17)) {
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
         if (rxdata == 0x42) {   
               dcnt = 0;
               rxbuff[rcnt++] = rxdata;
               rx_seq0++;
         
         } 
         else if(rxdata == 0x04){
               dcnt = 0;
               rxbuff[rcnt++] = rxdata;
               rx_seq0=13;
               sprintf(str," x%02d",invNo+1);
               put_str(4,16,str,1);
         }
         else {
                rx_seq0 = 0;
         }                     
         break; 
         
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x42+2)) {
  
               calCrc = calcCRC(rxbuff,0x42+3);   
                rxCrc = rxbuff[0x42+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x42+3];  


                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;

					inverter[invNo].solar_cell_voltage = Bytes_to_Uint(rxbuff[3],rxbuff[4])/10;
					accmCurrent[invNo] = Bytes_to_Uint(rxbuff[7],rxbuff[8]) + Bytes_to_Uint(rxbuff[9],rxbuff[10]);
					
					inverter[invNo].inv_u_voltage = Bytes_to_Uint(rxbuff[11],rxbuff[12])/10;
					inverter[invNo].inv_v_voltage = Bytes_to_Uint(rxbuff[13],rxbuff[14])/10; 
					inverter[invNo].inv_w_voltage = Bytes_to_Uint(rxbuff[15],rxbuff[16])/10;					
			   

					inverter[invNo].inv_u_current = Bytes_to_Uint(rxbuff[17],rxbuff[18])/10;
                    inverter[invNo].inv_v_current = Bytes_to_Uint(rxbuff[19],rxbuff[20])/10;
                    inverter[invNo].inv_w_current = Bytes_to_Uint(rxbuff[21],rxbuff[22])/10;
               
					inverter[invNo].inv_frequency = Bytes_to_Uint(rxbuff[23],rxbuff[24])/100;
			   
					inverter[invNo].power_inv_now = Bytes_to_Uint(rxbuff[29],rxbuff[30])/100;
			   
			   
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[31],rxbuff[32]);   //Work Mode             
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[35],rxbuff[36]);   //Error Message H            
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[37],rxbuff[38]);   //Error Message L              
                    inverter[invNo].inverter_status[3] = 0;//Bytes_to_Uint(rxbuff[9],rxbuff[10]);   //DC/AC Converter State                
                
					inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[39],rxbuff[40]);
					inverter[invNo].power_inv_total   <<= 16; 
					inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[41],rxbuff[42]);
                    
                    inverter[invNo].power_inv_total /= 10;           
                    
                    inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[67],rxbuff[68])/10;	
                    
					inverter[invNo].power_inv_pf        = 950;

                    sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
                    sprintf(str,"RX%02d",invNo+1);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                }
               rx_seq0 = 0;
            }
            break;
        
        case 13:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x04+2)) {
  
                calCrc = calcCRC(rxbuff,0x04+3);   
                rxCrc = rxbuff[0x04+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x04+3];  
                
                if (rxCrc == calCrc) {
                    
                    accmCurrent[invNo] += (Bytes_to_Uint(rxbuff[3],rxbuff[4]) + Bytes_to_Uint(rxbuff[5],rxbuff[6]));
                    
                    inverter[invNo].solar_cell_current = accmCurrent[invNo]/10;
					
					imlong = inverter[invNo].solar_cell_voltage * inverter[invNo].solar_cell_current;
					imlong /= 100;
					
                    inverter[invNo].power_solar = imlong;
                    
                    sendInverterCount[invNo] = 0;
					buzzer_flag |= BUZZER_TIC;
                    sprintf(str,"Rx%02d",invNo+1);
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