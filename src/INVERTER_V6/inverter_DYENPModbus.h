void sendInverterRead_DYENPModbus(void) {  
    unsigned int retVal;
    char sendBuff[10];   

    eeDYENPaddress[0] = 75;
    eeDYENPaddress[1] = 54;
    eeDYENPaddress[2] = 74;
    eeDYENPaddress[3] = 73;
    eeDYENPaddress[4] = 41;
    eeDYENPaddress[5] = 68;
	
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
            
			sendBuff[0] = eeDYENPaddress[inverter_address-1];	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x75; //Modbus Address High
            sendBuff[3] = 0x61; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1B; //Data Count Low (26)
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
            
			sendBuff[0] = eeDYENPaddress[inverter_address-1];	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x75; //Modbus Address High
            sendBuff[3] = 0x61; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x1B; //Data Count Low (26)
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



void rx0Control_DYENPModbus(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
    unsigned long int imlong;

	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if (rxdata < 100) {
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
            if (rxdata == 0x36) {   
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
            if (dcnt == 56) {
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
                    invNo = inverter_address - 1;  //rxbuff[0] - 1;
                    
                	inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[31],rxbuff[32]);    /*clr*/
                    
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[29],rxbuff[30]);       //다른 인버터 소스예제 참조 (합산))  /*clr*/
                    inverter[invNo].solar_cell_current  += Bytes_to_Uint(rxbuff[33],rxbuff[34]);       /*clr*/
                    inverter[invNo].solar_cell_current  += Bytes_to_Uint(rxbuff[37],rxbuff[38]);       /*clr*/
                    inverter[invNo].solar_cell_current  += Bytes_to_Uint(rxbuff[41],rxbuff[42]);       /*clr*/
                    inverter[invNo].solar_cell_current  += Bytes_to_Uint(rxbuff[45],rxbuff[46]);       /*clr*/
                    inverter[invNo].solar_cell_current  += Bytes_to_Uint(rxbuff[49],rxbuff[50]);       /*clr*/
                       
                	imlong         = (Bytes_to_Uint(rxbuff[29],rxbuff[30]) * Bytes_to_Uint(rxbuff[31],rxbuff[32])); 
                	imlong         += (Bytes_to_Uint(rxbuff[33],rxbuff[34]) * Bytes_to_Uint(rxbuff[35],rxbuff[36]));
                    imlong         += (Bytes_to_Uint(rxbuff[37],rxbuff[38]) * Bytes_to_Uint(rxbuff[39],rxbuff[40]));
                    imlong         += (Bytes_to_Uint(rxbuff[41],rxbuff[42]) * Bytes_to_Uint(rxbuff[43],rxbuff[44]));
                    imlong         += (Bytes_to_Uint(rxbuff[45],rxbuff[46]) * Bytes_to_Uint(rxbuff[47],rxbuff[48]));
                    imlong         += (Bytes_to_Uint(rxbuff[49],rxbuff[50]) * Bytes_to_Uint(rxbuff[51],rxbuff[52])); /*clr*/   
                    
                    inverter[invNo].power_solar = imlong/1000;
                                                        
                	inverter[invNo].inv_u_voltage     = Bytes_to_Uint(rxbuff[9],rxbuff[10]);        /*clr*/
                	inverter[invNo].inv_v_voltage     = Bytes_to_Uint(rxbuff[11],rxbuff[12]);       /*clr*/
                	inverter[invNo].inv_w_voltage     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);       /*clr*/
                    
                    inverter[invNo].inv_u_current      = Bytes_to_Uint(rxbuff[3],rxbuff[4]);        /*clr*/
                	inverter[invNo].inv_v_current      = Bytes_to_Uint(rxbuff[5],rxbuff[6]);        /*clr*/
                	inverter[invNo].inv_w_current      = Bytes_to_Uint(rxbuff[7],rxbuff[8]);        /*clr*/

                    
                    imlong       = (Bytes_to_Uint(rxbuff[3],rxbuff[4]) * Bytes_to_Uint(rxbuff[9],rxbuff[10]))*0.58; 
                    imlong       += (Bytes_to_Uint(rxbuff[5],rxbuff[6]) * Bytes_to_Uint(rxbuff[11],rxbuff[12]))*0.58;
                    imlong       += (Bytes_to_Uint(rxbuff[7],rxbuff[8]) * Bytes_to_Uint(rxbuff[13],rxbuff[14]))*0.58;
                                                      
                    inverter[invNo].power_inv_pf        = 950;   //역률
                    //inverter[invNo].power_inv_pf = (inverter[invNo].power_inv_now * 100) / inverter[invNo].power_solar;
                    
                    
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[55],rxbuff[56]);    /*clr*/

                	
                    inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[15],rxbuff[16]);      //금일발전량 /*clr*/ 
                    inverter[invNo].power_inv_day_total <<= 16;
                    inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[17],rxbuff[18]);      /*clr*/
                    
                    inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[25],rxbuff[26]);      //총누적  /*clr*/
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[27],rxbuff[28]);      /*clr*/
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[19],rxbuff[20]);    //상태  /*clr*/       
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[21],rxbuff[22]);            /*clr*/        
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[23],rxbuff[24]);            /*clr*/        
                    inverter[invNo].inverter_status[3] = 0;//            /*clr*/                                                     
                                                                          
                    inverter[invNo].power_inv_now = imlong/ 100;   //전류에 의한
                    //inverter[invNo].power_inv_now /= 1000;  //단위(K)에 의한 
                    
                	//inverter[invNo].power_solar  /= 100;            /*clr*/
                    //inverter[invNo].power_solar  /= 1000; 
					inverter[invNo].solar_cell_current  /= 10;      /*clr*/ 
                                
                    inverter[invNo].inv_u_current      /= 10;       /*clr*/ 
                	inverter[invNo].inv_v_current      /= 10;        /*clr*/ 
                	inverter[invNo].inv_w_current      /= 10;        /*clr*/ 
                                                                    
                	inverter[invNo].power_inv_day_total /= 100;      /*clr*/
                    
                    
                    inverter[invNo].power_inv_now = inverter[invNo].power_solar;//180730 계산값이 많이 달라서 수정
                    inverter[invNo].power_inv_now *= 98;
                    inverter[invNo].power_inv_now /= 100;
                    
                    if(inverter[invNo].inv_u_current==0) 
                        inverter[invNo].power_inv_now = 0;
                    
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
