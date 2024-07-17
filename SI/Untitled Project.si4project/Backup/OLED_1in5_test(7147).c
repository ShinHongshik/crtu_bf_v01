/*****************************************************************************
* | File      	:   OLED_1in5_rgb_test.c
* | Author      :   Waveshare team
* | Function    :   1.5inch OLED Module test demo
* | Info        :
*----------------
* |	This version:   V2.0
* | Date        :   2020-08-17
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "hs_global.h"
#include "test.h"
#include "OLED_1in5.h"

//OLED Define
#define OLED_SEL         6
#define OLED_CS         13
#define OLED_RST        15	
#define OLED_DC         14	

//#define OLED_CS_0      gpwr(OLED_CS,0)
//#define OLED_CS_1      gpwr(OLED_CS,1)


//#define OLED_DC_0       gpwr(OLED_DC,0)
//#define OLED_DC_1       gpwr(OLED_DC,1)


extern void gpio_hs (const uint gpNum, char onoff );
extern void OLED_1in5_Display(UBYTE *Image);
void drv_lcd_1in5_oled(void);
void flcd_refrash(void);





void DEV_SPI_WriteByte(uint8_t Value)
{
	// printf("write data is %d\r\n", Value);
	uint8_t buf[2];
	buf[0] = Value;
	cs_select(DOT_DEFAULT_SPI_CSN_PIN);
	spi_write_blocking(spi1, buf, 1);
	cs_deselect(DOT_DEFAULT_SPI_CSN_PIN);
}

static void OLED_WriteReg(uint8_t Reg)
{
    gpio_put(OLED_DC,0);
	DEV_SPI_WriteByte(Reg);
}

static void OLED_WriteData(uint8_t data)
{
    gpio_put(OLED_DC,1);
	DEV_SPI_WriteByte(data);
    
}

void DEV_Delay_ms(uint32_t xms)
{
    uint32_t i;
    for(i=0; i < xms; i++){
        usleep(1000);
    }
}

static void OLED_Reset(int i)
{

	switch(i){
		case 0:
	    	gpio_put(OLED_RST,1);
		break;
		case 1:
	 	   gpio_put(OLED_RST,0);
		break;
		case 2:
	       gpio_put(OLED_RST,1);
		break;
		case 3:
		default:
		break;	
	}
}

uint8_t OLED_InitReg(void)
{
	uint8_t arr[34] = {
			0xae,
			0x15,
			0x00,
			0x7f,
			0x75,
			0x00,
			0x7f,
			0x81,
			0x40,
			0xa0,
			0x51,
			0xa1,
			0x00,
			0xa2,
			0x00,
			0xa4,
			0xa8,
			0x7f,
			0xb1,
			0xf1,
			0xb3,
			0x70,
			0xab,
			0x01,
			0xb6,
			0x0f,
			0xbe,
			0x0f,
			0xbc,
			0x08,
			0xd5,
			0x62,
			0xfd,
			0x12
	};
	static uint8_t num = 0; 
	uint8_t val = 0;

	val =  arr[num];
 	OLED_WriteReg(val);
	if(num >= 33){
		num = 0;
		return 1;
	}	
	else num++;
	
	return 0;
//	    OLED_WriteReg(0xae);//--turn off oled panel
//	
//	    OLED_WriteReg(0x15);    //   set column address
//	    OLED_WriteReg(0x00);    //  start column   0
//	    OLED_WriteReg(0x7f);    //  end column   127
//	
//	    OLED_WriteReg(0x75);    //   set row address
//	    OLED_WriteReg(0x00);    //  start row   0
//	    OLED_WriteReg(0x7f);    //  end row   127
//	
//	    OLED_WriteReg(0x81);  // set contrast control
//	    OLED_WriteReg(0x40);
//	
//	    OLED_WriteReg(0xa0);    // gment remap
//	    OLED_WriteReg(0x51);   //51
//	
//	    OLED_WriteReg(0xa1);  // start line
//	    OLED_WriteReg(0x00);
//	
//	    OLED_WriteReg(0xa2);  // display offset
//	    OLED_WriteReg(0x00);
//	
//	    OLED_WriteReg(0xa4);    // rmal display
//	    OLED_WriteReg(0xa8);    // set multiplex ratio
//	    OLED_WriteReg(0x7f);
//	
//	    OLED_WriteReg(0xb1);  // set phase leghth
//	    OLED_WriteReg(0xf1);
//	
//	    OLED_WriteReg(0xb3);  // set dclk
//	    OLED_WriteReg(0x00);  //80Hz:0xc1 90Hz:0xe1   100Hz:0x00   110Hz:0x30 120Hz:0x50   130Hz:0x70     01
//	
//	    OLED_WriteReg(0xab);  //
//	    OLED_WriteReg(0x01);  //
//	
//	    OLED_WriteReg(0xb6);  // set phase leghth
//	    OLED_WriteReg(0x0f);
//	
//	    OLED_WriteReg(0xbe);
//	    OLED_WriteReg(0x0f);
//	
//	    OLED_WriteReg(0xbc);
//	    OLED_WriteReg(0x08);
//	
//	    OLED_WriteReg(0xd5);
//	    OLED_WriteReg(0x62);
//	
//	    OLED_WriteReg(0xfd);
//	    OLED_WriteReg(0x12); 

	
}

static void OLED_SetWindow(UBYTE Xstart, UBYTE Ystart, UBYTE Xend, UBYTE Yend)
{
    if((Xstart > OLED_1in5_WIDTH) || (Ystart > OLED_1in5_HEIGHT) ||
       (Xend > OLED_1in5_WIDTH) || (Yend > OLED_1in5_HEIGHT))
        return;

    OLED_WriteReg(0x15);
    OLED_WriteReg(Xstart/2);
    OLED_WriteReg(Xend/2 - 1);

    OLED_WriteReg(0x75);
    OLED_WriteReg(Ystart);
    OLED_WriteReg(Yend - 1);
}


void OLED_1in5_Display_test(UBYTE *Image)
{
    UWORD i, j, temp;
    OLED_SetWindow(0, 0, 128, 128);
    for(i=0; i<OLED_1in5_HEIGHT; i++)
        for(j=0; j<OLED_1in5_WIDTH/2; j++)
        {
            temp = Image[j + i*64];
            OLED_WriteData(temp);
        }
}



static void DEV_GPIO_Init_h(void)
{
	gpio_init(OLED_RST);
	gpio_set_dir(OLED_RST, GPIO_OUT);
	
	gpio_init(OLED_DC);
	gpio_set_dir(OLED_DC, GPIO_OUT);

}
void Paint_plug_l(void){
	Paint_DrawLine(5, 4, 8, 4, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(5, 5, 10, 5, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(3, 6, 12, 6, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(3, 7, 12, 7, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(3, 8, 13, 8, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine(3, 9, 13, 9, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 10, 14,10, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	//
	
	//
	
	Paint_DrawLine( 5, 11, 15,11, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 12, 15,12, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 13, 15,13, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 14, 14,14, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 3, 15, 13,15, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 3, 16, 13,16, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 3, 17, 12,17, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 3, 18, 12,18, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 19, 10,19, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	Paint_DrawLine( 5, 20, 8, 20, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

	//Paint_DrawLine(50, 10, 80, 10, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	//Paint_DrawLine(0, 0, 128, 128, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
	
}



extern void drv_lcd_1in5_oled(void){
	static int sDlSqc = 0;
	static int cnt =0;
	static UBYTE *BlackImage;
	static UWORD Imagesize = ((OLED_1in5_WIDTH%2==0)? (OLED_1in5_WIDTH/2): (OLED_1in5_WIDTH/2+1)) * OLED_1in5_HEIGHT;
	
	switch(sDlSqc){
		case 0:  // wait Sys stable
			if((gSysCnt - cnt) < 1500) break;
			printf("1.5inch RGB OLED test demo\n");
			
			DEV_GPIO_Init_h();
//			dev_select_cs1(SELDEV_LCD);
			
			//DEV_HARDWARE_SPI_b1egin("/dev/spidev0.0");
			OLED_Reset(1);
			cnt = gSysCnt;
			sDlSqc++;
			break;
		case 1:
			if((gSysCnt - cnt) < 200) break;
			cnt = gSysCnt;
			OLED_Reset(0);
			sDlSqc++;
			break;
		case 2:
			if((gSysCnt - cnt) < 2) break;
			cnt = gSysCnt;
			if(OLED_InitReg() == 1)
				sDlSqc++;
			break;
		case 3:    // turn on 
			if((gSysCnt - cnt) < 200) break;
			cnt = gSysCnt;
			OLED_WriteReg(0xAF);
			printf("lcd_w");
			sDlSqc++;
			break;
		case 4:
			if((gSysCnt - cnt) < 200) break;
			cnt = gSysCnt;
			BlackImage = (UBYTE *)malloc(Imagesize);
			printf("Failed to apply for black memory...\r\n");
			sDlSqc++;
			break;
		case 5:
			if((gSysCnt - cnt) < 100) break;
			Paint_NewImage(BlackImage, OLED_1in5_WIDTH, OLED_1in5_HEIGHT, 0, BLACK);	
			Paint_SetScale(16);
			Paint_SelectImage(BlackImage);
			cnt = gSysCnt;
			sDlSqc++;
			break;
		case 6:
			if((gSysCnt - cnt) < 500) break;
			Paint_Clear(BLACK);
			sDlSqc++;
			break;
		case 7:
			// 2.Drawing on the image		
			printf("Drawing:page 1\r\n");
			Paint_DrawPoint(20, 10, WHITE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
			Paint_DrawPoint(30, 10, WHITE, DOT_PIXEL_2X2, DOT_STYLE_DFT);
			Paint_DrawPoint(40, 10, WHITE, DOT_PIXEL_3X3, DOT_STYLE_DFT);
			Paint_DrawLine(10, 10, 10, 20, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
			Paint_DrawLine(20, 20, 20, 30, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
			Paint_DrawLine(30, 30, 30, 40, WHITE, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
			Paint_DrawLine(40, 40, 40, 50, WHITE, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
			Paint_DrawCircle(60, 30, 15, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawCircle(100, 40, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);			
			Paint_DrawRectangle(50, 30, 60, 40, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
			Paint_DrawRectangle(90, 30, 110, 50, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);		
			// 3.Show image on page1
			//OLED_1in5_Display_test(BlackImage);

			//------------
			// Drawing on the image
			printf("Drawing:page 2\r\n");
			cnt = gSysCnt;
			sDlSqc++;
			break;
		case 8:
			if((gSysCnt - cnt) < 2000) break;
			//Paint_Clear(BLACK);
			for(UBYTE i=0; i<16; i++){
				Paint_DrawRectangle(0, 8*i, 127, 8*(i+1), WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
				Paint_DrawRectangle(0, 4*i, 127, 4*(i+1), BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);		
				//Paint_DrawLine(0, 8*i, 127, 8*(i+1), WHITE, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
			}

			//---------------
			//OLED_1in5_Display_test(BlackImage);
			cnt = gSysCnt;
			sDlSqc++;
			break;
		case 9:
			if((gSysCnt - cnt) < 2000) break;
			Paint_Clear(BLACK);
			
			Paint_DrawString_EN(10, 80, "i_love_U", &Font12, 0x1, 0xb);
			Paint_DrawString_EN(10, 92, "soul_energy", &Font16, 0x2, 0xc);
			Paint_DrawNum(10, 100, 123.456789, &Font8, 4, 0x3, 0xd);
			Paint_DrawNum(10, 116, 987654, &Font12, 5, 0x4, 0xe);
	
			// Show image on page2
			OLED_1in5_Display_test(BlackImage);
			cnt = gSysCnt;
			sDlSqc++;
			break;
		case 10:
			if((gSysCnt - cnt) < 2000) break;
			cnt = gSysCnt;
			if(gfLcdRefash == 1) sDlSqc = 11;
			if(gflcdsleep_n == 0){ 
				sDlSqc = 12;
				OLED_WriteReg(0xAE);
			}
			if(isb(gResetSw,LCD_RSW))sDlSqc = 14; 
			break;
		case 11:
			gfLcdRefash = 0;
			flcd_refrash();
			sDlSqc = 10; 
			break;
		case 12:
			if((gSysCnt - cnt) < 500) break;
			sDlSqc = 13; 
			break;
		case 13:
			if(gflcdsleep_n == 0) break;
				//OLED_Reset(0); //--turn off oled panel
				OLED_WriteReg(0xAF);
				sDlSqc = 10;
			break;
		case 14:
		default:	
			if((gSysCnt - cnt) < 2000) break;
			cnt = gSysCnt;
			if(isb(gResetSw,LCD_RSW)){ 
				sDlSqc = 0;
				cbi(gResetSw, LCD_RSW);
				cnt = gSysCnt;
				}
		break;
	}
}


void flcd_refrash(void){
		Paint_DrawRectangle(80, 12, 90, 13, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
		Paint_DrawRectangle(60, 12, 70, 13, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
		Paint_DrawRectangle(110, 5, 120, 10, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
		Paint_DrawRectangle(110, 12, 120, 13, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
		Paint_DrawRectangle(110, 15, 120, 20, WHITE, DOT_PIXEL_1X1, DRAW_FILL_FULL);
		Paint_DrawRectangle(1, 1, 128, 128, WHITE, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
		Paint_plug_l();
		Paint_DrawString_EN(10, 80, "i_love_U", &Font12, 0x1, 0xb);
		Paint_DrawString_EN(10, 92, "soul_energy", &Font16, 0x2, 0xc);
		//OLED_1in5_Display_test(BlackImage);
}

