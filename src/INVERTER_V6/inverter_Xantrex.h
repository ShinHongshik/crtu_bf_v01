void sendInverterRead_Xantrex(void) {
	return;
}

void rx0Control_Xantrex(void) {   
	char rxdata;
    unsigned long lim[2];

	rxdata = getchar0();  
	
	switch(rx_seq0) {
		case 0:        
        	if (rxdata == STX) { 
            	chksum0 = 0;
				rcnt = 0;           
                memset(rxbuff,0,sizeof(rxbuff));
                timeout0 = 250;
            	rx_seq0++;
            } else if (rxdata == 0x02) {  
//				rcnt = 0;
//				rxbuff[rcnt++] = rxdata;
                timeout0 = 250;
				rx_seq0 = 100;
			}   
			break;        
        case 1:                      
        	//rcnt = 0;     
			rxbuff[rcnt++] = rxdata;
            chksum0 ^= rxdata;
        	if (rcnt == 41) {
            	rx_seq0++;
            }               
            break;
        case 2:   
        	rchksum0 = rxdata; 
            rx_seq0++;
            break;
        case 3:             
        	if ((rxdata == ETX) && (rchksum0 == chksum0)) {
            	inverter_address = rxbuff[0];
                inverter[inverter_address].inverter_status[0] = ((unsigned int)rxbuff[1] * 0x100) + rxbuff[2];
                inverter[inverter_address].inverter_status[1] = ((unsigned int)rxbuff[3] * 0x100) + rxbuff[4];
                inverter[inverter_address].inverter_status[2] = ((unsigned int)rxbuff[5] * 0x100) + rxbuff[6];
                inverter[inverter_address].inverter_status[3] = ((unsigned int)rxbuff[7] * 0x100) + rxbuff[8];
                
                inverter[inverter_address].solar_cell_voltage = ((unsigned int)rxbuff[9] * 0x100) + rxbuff[10]; 
                inverter[inverter_address].solar_cell_current = ((unsigned int)rxbuff[11] * 0x100) + rxbuff[12];  
                                                                             //
                inverter[inverter_address].inv_u_voltage = ((unsigned int)rxbuff[13] * 0x100) + rxbuff[14];  
                inverter[inverter_address].inv_v_voltage = ((unsigned int)rxbuff[15] * 0x100) + rxbuff[16];  
                inverter[inverter_address].inv_w_voltage = ((unsigned int)rxbuff[17] * 0x100) + rxbuff[18];  
                inverter[inverter_address].inv_u_current = ((unsigned int)rxbuff[19] * 0x100) + rxbuff[20];  
                inverter[inverter_address].inv_v_current = ((unsigned int)rxbuff[21] * 0x100) + rxbuff[22];  
                inverter[inverter_address].inv_w_current = ((unsigned int)rxbuff[23] * 0x100) + rxbuff[24];  

                inverter[inverter_address].inv_frequency = ((unsigned int)rxbuff[25] * 0x100) + rxbuff[26];  

                inverter[inverter_address].power_solar         = ((unsigned int)rxbuff[27] * 0x100) + rxbuff[28];     
                lim[0]                                         = ((unsigned int)rxbuff[29] * 0x100) + rxbuff[30];
                lim[0] <<= 16; 
                lim[1]                                         = ((unsigned int)rxbuff[31] * 0x100) + rxbuff[32];

                inverter[inverter_address].power_inv_total     = lim[0] + lim[1];

                inverter[inverter_address].power_inv_now       = ((unsigned int)rxbuff[33] * 0x100) + rxbuff[34];
                //inverter[inverter_address].power_inv_max       = ((unsigned int)rxbuff[35] * 0x100) + rxbuff[36];
                inverter[inverter_address].power_inv_day_total = ((unsigned int)rxbuff[37] * 0x100) + rxbuff[38];
                inverter[inverter_address].power_inv_pf        = ((unsigned int)rxbuff[39] * 0x100) + rxbuff[40];

                buzzer_flag |= BUZZER_TIC;   
//                put_str(4,16,C_RXOK,1);   
				sprintf(str,"RX:%d",inverter_address+1);
				put_str(4,16,str,1);   
                rx_led_delay = 2500;
            }
            rx_seq0 = 0;       
			break;

		//System Setting /////////////////////////////////////            
		case 100:               
            rcnt = 0;
            if (rxdata == 0xa5) {			//RD_DATA
                rx_seq0 = 120;
            } else if (rxdata == 0xaa) {	//WR_DATA
				rcnt = 0;
                rx_seq0 = 110;      
            } else {
                rx_seq0 = 0;
            }
			break;
		case 110:  	//WR_DATA
			rxbuff[rcnt++] = rxdata;
			if (rcnt == 5) {
				rx_seq0++;
			}			
			break;  
			     
		case 111:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 112:  
			if (rxdata == 0x0d) {   
				eePortNumber = rxbuff[0] * 0x100 + rxbuff[1];
				eeSendDelay = rxbuff[2] * 0x100 + rxbuff[3];  
                eeInverterCount = rxbuff[4];
			    sprintf(str,"%04d", eePortNumber);
				put_str(1,6,str,2);    
            	send_system_parameter();   
				buzzer_flag |= BUZZER_TIC;
			}
			rx_seq0 = 0;         
			break;
			
			
		case 120:  
			if (rxdata == 0x03) {
				rx_seq0++;
			} else {
				rx_seq0 = 0;
			}  
			break;
		case 121:  
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
