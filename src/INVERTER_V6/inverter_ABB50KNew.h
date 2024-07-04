

void sendInverterRead_ABB50K(void) {  
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
		 //inverter_address = 2;
      
         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x19; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x05; //Data Count Low (58)
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
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x2D; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x04; //Data Count Low (58)
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
      
         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x18; //Data Count Low (58)
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
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x19; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x05; //Data Count Low (58)
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
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x2D; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x04; //Data Count Low (58)
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
            sprintf(str,"TX%02d",inverter_address
            );     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;
      
        case 13:
      
         rx_seq0 = 0; 

         sendBuff[0] = inverter_address;   //Slave Number
         sendBuff[1] = 0x04;   //Function Code
            sendBuff[2] = 0x04; //Modbus Address High
            sendBuff[3] = 0x41; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x18; //Data Count Low (58)
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





void rx0Control_ABB50K(void) {   
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
            if (rxdata == 0x04) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Data Count
            if (rxdata == 0x0A) {   
               dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
         }else if (rxdata == 0x08) {   
               dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0=4;
         }else if (rxdata == 0x30) {   
               dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0=5;
            } else {
                rx_seq0 = 0;
            }                     
            break; 
         
        case 3:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x0A+2)) {
  
               calCrc = calcCRC(rxbuff,0x0A+3);   
                rxCrc = rxbuff[0x0A+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x0A+3];  


                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
               
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);   //Global State             
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[5],rxbuff[6]);   //Alarm State            
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[7],rxbuff[8]);   //DC/DC Converter State              
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[9],rxbuff[10]);   //DC/AC Converter State                
                
               
                    
                    
                    

                   sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                   sprintf(str,"RX%02d",invNo+1);
                   put_str(4,16,str,1);   
                   rx_led_delay = 2500;
                }
               rx_seq0 = 0;
            }
            break;

      case 4:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x08+2)) {
  
               calCrc = calcCRC(rxbuff,0x08+3);   
                rxCrc = rxbuff[0x08+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x08+3];  


                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
               
               //inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[5],rxbuff[6]); // daily energy rxbuff[3],rxbuff[4],
               
               imlong = Bytes_to_Uint(rxbuff[3],rxbuff[4]);
               imlong <<= 16;
               imlong += Bytes_to_Uint(rxbuff[5],rxbuff[6]);
               
               inverter[invNo].power_inv_day_total = imlong/1000;
               
               inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[7],rxbuff[8]);
               inverter[invNo].power_inv_total   <<= 16; 
               inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[9],rxbuff[10]);
               
               inverter[invNo].power_inv_total /= 1000;
               
               sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                   sprintf(str,"RX%02d",invNo+1);
                   put_str(4,16,str,1);   
                   rx_led_delay = 2500;
                }
               rx_seq0 = 0;
            }
            break;
         
      case 5:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == (0x30+2)) {
  
               calCrc = calcCRC(rxbuff,0x30+3);   
                rxCrc = rxbuff[0x30+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x30+3];  


                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
               
               temp_data = Hex_to_Uint(rxbuff[5],rxbuff[6],rxbuff[3],rxbuff[4],false);
               
               if (temp_data < 9999)
                  inverter[invNo].inv_u_voltage   = temp_data;
                  
               inverter[invNo].inv_v_voltage       = inverter[invNo].inv_u_voltage; 
               inverter[invNo].inv_w_voltage       = inverter[invNo].inv_u_voltage;
               
               temp_data = Hex_to_Uint(rxbuff[9],rxbuff[10],rxbuff[7],rxbuff[8],false);
               
               if (temp_data < 9999)
                  inverter[invNo].inv_u_current   = temp_data;
                   inverter[invNo].inv_v_current         = inverter[invNo].inv_u_current;
                   inverter[invNo].inv_w_current         = inverter[invNo].inv_u_current;
               
               temp_data = Hex_to_Uint(rxbuff[13],rxbuff[14],rxbuff[11],rxbuff[12],false)/100;
               
               if (temp_data < 9999)
                  inverter[invNo].power_inv_now   = temp_data;
               
               
               
               inverter[invNo].power_inv_pf        = Hex_to_Uint(rxbuff[33],rxbuff[34],rxbuff[31],rxbuff[32],false);
               inverter[invNo].inv_frequency       = Hex_to_Uint(rxbuff[37],rxbuff[38],rxbuff[35],rxbuff[36],false);
               
               temp_data = Hex_to_Uint(rxbuff[41],rxbuff[42],rxbuff[39],rxbuff[40],false)/100;
               
               if (inverter[invNo].power_solar < 9999)
                  inverter[invNo].power_solar     = temp_data;
               
               temp_data = Hex_to_Uint(rxbuff[45],rxbuff[46],rxbuff[43],rxbuff[44],false);
               
               if (inverter[invNo].solar_cell_voltage < 9999)
                  inverter[invNo].solar_cell_voltage  = temp_data;
               
               temp_data = Hex_to_Uint(rxbuff[49],rxbuff[50],rxbuff[47],rxbuff[48],false);
               
               if (inverter[invNo].solar_cell_current < 9999)
                  inverter[invNo].solar_cell_current  = temp_data;            
                    
                
               if(inverter[invNo].power_inv_now > 600)
               {     
                    inverter[invNo].power_inv_now=0;
                     
               }
               if(inverter[invNo].power_solar > 600)
               {     
                    inverter[invNo].power_solar=0;
                     
               }

               //inverter[invNo].solar_cell_voltage  /= 10;
               //inverter[invNo].solar_cell_current  /= 10;            
               //inverter[invNo].inv_u_current      /= 10;
 
                    
               
               sendInverterCount[invNo] = 0;
               buzzer_flag |= BUZZER_TIC;
                   sprintf(str,"RX%02d",invNo+1);
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