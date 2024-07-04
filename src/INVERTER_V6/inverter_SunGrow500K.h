
void rx0Control_SunGrow500K(void) {   
	char rxdata;   
    unsigned int calCrc,rxCrc;
	rxdata = getchar0();
	
	switch(rx_seq0) {
		case 0: //STX        
        	if ( (rxdata > 0x00) && (rxdata < 0x23)) {
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
            if (rxdata == 0xaa) {   
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
            if (dcnt == 172) {
            //if (1) {	//CRC-16 Check
            //if (rxCount1 == (rx1RetCount[rxbuff1[0]]*2+5)) {   
            	calCrc = calcCRC(rxbuff,170+3);   
                rxCrc = rxbuff[174];
                rxCrc <<= 8;
                rxCrc += rxbuff[173];  
//sprintf(str,"%04X %04X ", calCrc, rxCrc);
//put_str(0,0,str,1);

                if (rxCrc == calCrc) {
                    //invNo = 0;
                    invNo = rxbuff[0] - 1;
            
                	//inverter[invNo].solar_cell_voltage  = Bytes_to_Uint(rxbuff[25],rxbuff[26]);
					rxCrc = Bytes_to_Uint(rxbuff[25],rxbuff[26]);         
					calCrc = Bytes_to_Uint(rxbuff[29],rxbuff[30]);
                    if (rxCrc > calCrc) {   
						inverter[invNo].solar_cell_voltage = rxCrc;                    
                    } else {
						inverter[invNo].solar_cell_voltage = calCrc;                    
                    }         
					inverter[invNo].solar_cell_current  = Bytes_to_Uint(rxbuff[27],rxbuff[28]) + 
                    									Bytes_to_Uint(rxbuff[31],rxbuff[32]) +
                                                        Bytes_to_Uint(rxbuff[35],rxbuff[36]);            
                	inverter[invNo].power_solar         = Bytes_to_Uint(rxbuff[37],rxbuff[38]);  
                    
                	inverter[invNo].inv_u_voltage		= Bytes_to_Uint(rxbuff[41],rxbuff[42]); 
                	if (modelInverter == MODEL_INVERTER_SUNGROW3K) { 
	                	inverter[invNo].inv_v_voltage	= inverter[invNo].inv_u_voltage;
    	            	inverter[invNo].inv_w_voltage	= inverter[invNo].inv_u_voltage;
                    } else { 
	                	inverter[invNo].inv_v_voltage	= Bytes_to_Uint(rxbuff[43],rxbuff[44]); 
    	            	inverter[invNo].inv_w_voltage	= Bytes_to_Uint(rxbuff[45],rxbuff[46]); 
                    }
                    inverter[invNo].inv_u_current		= Bytes_to_Uint(rxbuff[47],rxbuff[48]); 
                	if (modelInverter == MODEL_INVERTER_SUNGROW3K) { 
                        inverter[invNo].inv_v_current	= inverter[invNo].inv_u_current;
                        inverter[invNo].inv_w_current	= inverter[invNo].inv_u_current;
                    } else {
                        inverter[invNo].inv_v_current	= Bytes_to_Uint(rxbuff[49],rxbuff[50]); 
                        inverter[invNo].inv_w_current	= Bytes_to_Uint(rxbuff[51],rxbuff[52]); 
                    }
                	inverter[invNo].power_inv_now		= Bytes_to_Uint(rxbuff[65],rxbuff[66]);  
                    inverter[invNo].power_inv_pf        = Bytes_to_Uint(rxbuff[73],rxbuff[74]);
                    inverter[invNo].inv_frequency       = Bytes_to_Uint(rxbuff[75],rxbuff[76]);
                	//inverter[invNo].power_inv_max       = Bytes_to_Uint(rxbuff[27],rxbuff[28]);
                	inverter[invNo].power_inv_day_total = Bytes_to_Uint(rxbuff[9],rxbuff[10]);
                	inverter[invNo].power_inv_total     = Bytes_to_Uint(rxbuff[13],rxbuff[14]);
                    inverter[invNo].power_inv_total   <<= 16; 
                	inverter[invNo].power_inv_total    += Bytes_to_Uint(rxbuff[11],rxbuff[12]); 
                    
                    inverter[invNo].inverter_status[0] = Bytes_to_Uint(rxbuff[79],rxbuff[80]);            
                    inverter[invNo].inverter_status[1] = Bytes_to_Uint(rxbuff[93],rxbuff[94]);              
                    inverter[invNo].inverter_status[2] = Bytes_to_Uint(rxbuff[103],rxbuff[104]);             
                    inverter[invNo].inverter_status[3] = Bytes_to_Uint(rxbuff[105],rxbuff[106]);             
                
                	inverter[invNo].solar_cell_voltage  /= 10;
					inverter[invNo].solar_cell_current  /= 10;            
                	inverter[invNo].inv_u_voltage     /= 10; 
                	inverter[invNo].inv_v_voltage     /= 10; 
                	inverter[invNo].inv_w_voltage     /= 10;
                    inverter[invNo].inv_u_current      /= 10;
                	inverter[invNo].inv_v_current      /= 10;
                	inverter[invNo].inv_w_current      /= 10;
                	inverter[invNo].power_inv_day_total /= 10;
                	
                	if (modelInverter == MODEL_INVERTER_SUNGROW30K) {
                    	inverter[invNo].power_solar         /= 100;
                		inverter[invNo].power_inv_now		/= 100;
                	}else {
                    	inverter[invNo].power_solar         /= 10;
                		inverter[invNo].power_inv_now		/= 10;
                    }  

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
