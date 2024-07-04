void sendInverterRead_ABB50K(void) {  
    unsigned int retVal;
    char sendBuff[10];   
    
    switch(inverter_seq) {
        case 0:
            inverter_seq++;
			invNo++;
			if (invNo > eeInverterCount) {
				invNo = 1;
			}
			if (sendInverterCount[invNo-1] < 100) {
            	sendInverterCount[invNo-1]++;
            }
            break;     
        case 1:     //Inv-1: RTU Master request frame  
			rx_seq0 = 0; 

			sendBuff[0] = invNo;	//Slave Number
			sendBuff[1] = 0x03;	//Function Code
            sendBuff[2] = 0x00; //Modbus Address High
            sendBuff[3] = 0x00; //Modbus Address Low
            sendBuff[4] = 0x00; //Data Count High
            sendBuff[5] = 0x3A; //Data Count Low (58)
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
            sprintf(str,"TX%02d", invNo);     
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
			inverter_seq = 0;
			break;

        case 100:
            inverter_seq = 0;
            break;
        default:  
            inverter_seq = 0;
            break;
    }
}



void rx0Control_ABB50K(void) {   
	char rxdata;   
    char rxInverterNumber;  
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
            if (rxdata == 0x74) {   
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
            if (dcnt == (0x74+2)) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,0x74+3);   
                rxCrc = rxbuff[0x74+4];
                rxCrc <<= 8;
                rxCrc += rxbuff[0x74+3];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    rxInverterNumber = rxbuff[0] - 1;
                    
                    inverter[rxInverterNumber].inverter_status[0] = Bytes_to_Uint(rxbuff[39],rxbuff[40]);	//Main status word             
                    inverter[rxInverterNumber].inverter_status[1] = Bytes_to_Uint(rxbuff[3],rxbuff[4]);	//Inverter operation            
                    inverter[rxInverterNumber].inverter_status[2] = Bytes_to_Uint(rxbuff[25],rxbuff[26]);	//Tripping fault              
                    inverter[rxInverterNumber].inverter_status[3] = Bytes_to_Uint(rxbuff[37],rxbuff[38]);	//Lastest warning	             

                	inverter[rxInverterNumber].solar_cell_voltage  = Bytes_to_Uint(rxbuff[9],rxbuff[10]); 
					inverter[rxInverterNumber].solar_cell_current  = Bytes_to_Uint(rxbuff[23],rxbuff[24]);            
                	inverter[rxInverterNumber].power_solar         = Bytes_to_Uint(rxbuff[15],rxbuff[16]); 
                	inverter[rxInverterNumber].inv_u_voltage     	= Bytes_to_Uint(rxbuff[105],rxbuff[106]); 
                	inverter[rxInverterNumber].inv_v_voltage    	= Bytes_to_Uint(rxbuff[107],rxbuff[108]); 
                	inverter[rxInverterNumber].inv_w_voltage     	= Bytes_to_Uint(rxbuff[109],rxbuff[110]);
                    inverter[rxInverterNumber].inv_u_current      	= Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                	inverter[rxInverterNumber].inv_v_current      	= Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                	inverter[rxInverterNumber].inv_w_current      	= Bytes_to_Uint(rxbuff[11],rxbuff[12]);
                	inverter[rxInverterNumber].power_inv_now       = Bytes_to_Uint(rxbuff[17],rxbuff[18]);  
                    inverter[rxInverterNumber].power_inv_pf        = 999;
                    inverter[rxInverterNumber].inv_frequency       = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[rxInverterNumber].power_inv_day_total = inverter[rxInverterNumber].power_inv_now;
//                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[31],rxbuff[32]);
//                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[rxInverterNumber].power_inv_total    = Bytes_to_Uint(rxbuff[95],rxbuff[96]); 

                
                    if (rxInverterNumber) inverter[rxInverterNumber].solar_cell_voltage = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].solar_cell_current = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].power_solar = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].inv_u_current = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].inv_v_current = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].inv_w_current = 0; 
                    if (rxInverterNumber) inverter[rxInverterNumber].power_inv_now = 0; 

                	inverter[rxInverterNumber].solar_cell_voltage  /= 10;
					inverter[rxInverterNumber].solar_cell_current  /= 10;            
                    inverter[rxInverterNumber].inv_u_current      /= 10;
                	inverter[rxInverterNumber].inv_v_current      /= 10;
                	inverter[rxInverterNumber].inv_w_current      /= 10;

	                sendInverterCount[rxInverterNumber] = 0;
					buzzer_flag |= BUZZER_TIC;
	                sprintf(str,"RX%02d",rxInverterNumber+1);
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
