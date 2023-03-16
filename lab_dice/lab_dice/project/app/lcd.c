/* ------------------------------------------------------------------
 * --  _____       ______  _____                                    -
 * -- |_   _|     |  ____|/ ____|                                   -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems    -
 * --   | | | '_ \|  __|  \___ \   Zurich University of             -
 * --  _| |_| | | | |____ ____) |  Applied Sciences                 -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland     -
 * ------------------------------------------------------------------
 * --
 * -- Description:  Implementation of module lcd
 * --               Performs all the interactions with the lcd
 * --
 * -- $Id: lcd.c 5144 2020-09-01 06:17:21Z ruan $
 * ------------------------------------------------------------------
 */

/* standard includes */
#include <stdio.h>

/* user includes */
#include "lcd.h"
#include "reg_ctboard.h"

/* macros */
#define LCD_ADDR_LINE1      0u
#define LCD_ADDR_LINE2      20u

#define NR_OF_CHAR_PER_LINE 20u

#define LCD_CLEAR           "                    "

/// STUDENTS: To be programmed
void lcd_write_value(uint8_t i, uint8_t number_of_throws)
 {
    char str[3];
    sprintf(str,"%d",number_of_throws);
    CT_LCD->ASCII[i*3-3] = str[0];
    CT_LCD->ASCII[i*3-2] = str[1];
	 
	 
 }
 void lcd_write_total(uint8_t stat)
 {
	 int i;
	 const int length = 16;
   char str[length+1];
   CT_LCD->BG.GREEN = 65535;
   sprintf(str,"Total throws %d",stat);
	for(i = 0; i < length; i++){
       CT_LCD->ASCII[LCD_ADDR_LINE2 + i] = str[i];
   }
 }
void hal_ct_lcd_clear()
 {
	 CT_LCD -> ASCII[LCD_ADDR_LINE1] = LCD_CLEAR[0u];
	 CT_LCD -> ASCII[LCD_ADDR_LINE2] = LCD_CLEAR[0u];
	 
 }


/// END: To be programmed
