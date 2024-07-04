#ifndef _HS_TYPE_
#define _HS_TYPE_
//-----------------------type def

typedef unsigned int ui16;
typedef signed int si16;
typedef unsigned long int ul32;
//typedef unsigned long int DWORD;
typedef signed long int sl32;
//typedef signed long int LONG;
typedef unsigned char uc08;
typedef signed char sc08;
//typedef signed char BYTE;
//typedef unsigned int WORD;


// Alphanumeric LCD Module functions
#define BITON(x,y) (x|=(1<<y))
#define BITOFF(x,y) (x&=~(1<<y))

#define sbi(x,y) (x|=(1<<y))
#define cbi(x,y) (x&=~(1<<y))
#define bv(bit)	 (1 << (bit))
#define ABS(x)		((x>0)?(x):(-x))
#define DEC(a) if((a)>0) a--
#define ON 1
#define OFF 0
#define INIT 0xff
//#define STOP 3
//#define __DEBUG_MODE_	 0
//#define LCD_P_GO(a,b) (lcd_gotoxy(a,b))
//#define LCD_CLR() (lcd_clear())





#endif
