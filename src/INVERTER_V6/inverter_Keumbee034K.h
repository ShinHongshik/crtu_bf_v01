
void sendInverterRead_Keumbee34K(void) {  

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
            
            sendBuff[0] = 0x7e;    //SOP
            sendBuff[1] = inverter_address;    //Number
            sendBuff[2] = 0x07; //Command
            retVal = calcCRC(sendBuff,3);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High         
            putchar0(retVal % 0x100);   //2a.73
            putchar0(retVal / 0x100);

            
            TXEN=1;TXEN=1; //RS485 Tx Enable Pin is ON, two delay
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;         
        case 2:
        case 3:
        case 4:
            inverter_seq++;
            break;  
            
        case 5:         
            inverter_address++;
            if (eeInverterCount >= inverter_address) { 
                if (sendInverterCount[inverter_address-1] < 100) {
                    sendInverterCount[inverter_address-1]++;
                }            
                inverter_seq++;
            } else {
                inverter_seq = 0;                
            }
            break;    
        case 6:     //Inv-??: RTU Master request frame  

            //putchar0(0x01); //Slave Address
            rx_seq0 = 0; 
            
            
            sendBuff[0] = 0x7e;    //SOP
            sendBuff[1] = inverter_address;    //Number
            sendBuff[2] = 0x07; //Command
            retVal = calcCRC(sendBuff,3);         
                        
            putchar0(sendBuff[1]); 
            putchar0(sendBuff[2]); //Modbus Address High         
            putchar0(retVal % 0x100);   //2a.73
            putchar0(retVal / 0x100);
         
            TXEN=1;TXEN=1; //RS485 Tx Enable Pin is ON, two delay
            
#if (UDR_CLONE_MODE == 1)
			write_udr0 (sendBuff[0]);  
#else  
			UDR0 = sendBuff[0] ;  
#endif        
            sprintf(str,"TX%02d",inverter_address);     
            put_str(4,16,str,1);   
            rx_led_delay = 2500;
            inverter_seq++;             
            break;     
        case 7:
        case 8:  
            inverter_seq++;
            break;  
        case 9: 
            inverter_seq = 5;
            break;



        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_Keumbee34K(void) {   
    char rxdata;   
    unsigned int calCrc,rxCrc;
    unsigned long int imlong;

    rxdata = getchar0();
    
    switch(rx_seq0) {
        case 0: //SOP        
            if (rxdata == 0x7e) {
                rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
                rx_seq0++;
            }
            break;        
        case 1: //Number 
            if (rxdata < 100) {
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
                invNo = rxdata-1;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 2: //Command
            if (rxdata == 0x08) {   
                dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break; 
        case 3: //Command
            if (rxdata == 0x00) {   
                dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;
        case 4: //Command
            if (rxdata == 0x26) {   
                dcnt = 0;
                rxbuff[rcnt++] = rxdata;
                rx_seq0++;
            } else {
                rx_seq0 = 0;
            }                     
            break;   
        case 5:
            rxbuff[rcnt++] = rxdata;
            dcnt++;
            if (dcnt == 0x26) { //26   
                calCrc = calcCRC(rxbuff,0x26+3);   
                rxCrc = rxbuff[0x26+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x26+3];  


                //if (rxCrc == calCrc) {
                    //invNo = 0;
                    //invNo = inverter_address - 1;  //rxbuff[0] - 1;
                    
                    inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[5],rxbuff[6]);    /*clr*/
                    
                    inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[7],rxbuff[8]);    /*clr*/  
                    
                    inverter[invNo].power_solar = Bytes_to_Uint(rxbuff[11],rxbuff[12])/100;    /*clr*/
                                                        
                    inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);        /*clr*/
                    inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[15],rxbuff[16]);       /*clr*/
                    inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[17],rxbuff[18]);       /*clr*/
                    
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[19],rxbuff[20]);        /*clr*/
                    inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[21],rxbuff[22]);        /*clr*/
                    inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[23],rxbuff[24]);        /*clr*/

                    
                    inverter[invNo].power_inv_now       = Bytes_to_Uint(rxbuff[27],rxbuff[28])/100;        /*clr*/
                                                      
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[29],rxbuff[30]);   //

                                   
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[31],rxbuff[32])/10;   //

                    
                    inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[37],rxbuff[38]);       /*clr*/
                    inverter[invNo].power_inv_total   <<= 16; 
                    inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[39],rxbuff[40]);      /*clr*/
                    inverter[invNo].power_inv_total    /= 1000;
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[41],rxbuff[42]);      /*clr*/       
                    inverter[invNo].inverter_status[1] = 0;            /*clr*/        
                    inverter[invNo].inverter_status[2] = 0;            /*clr*/        
                    inverter[invNo].inverter_status[3] = 0;            /*clr*/                                                     
                                                                          
                    
                    
                    sendInverterCount[invNo] = 0;
                    buzzer_flag |= BUZZER_TIC;
                    sprintf(str,"RX%02d",invNo+1);
                    put_str(4,16,str,1);   
                    rx_led_delay = 2500;
                //}
                rx_seq0 = 0;
            }
            break;

        default:
            rx_seq0 = 0;
            break;
    }
}
