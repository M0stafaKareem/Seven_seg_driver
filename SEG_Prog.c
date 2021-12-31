#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "SEG_Config.h"
#include "SEG_Interface.h"
#include "../../MCAL/DIO/Dio_Interface.h"

const u8 seg_array[]=NUMBERS;

void Seg_vidUpCount(u16 Copy_u8Delay_ms){

	for(int count=0;count<10;count++)
	{
		DIO_u8SetPortValue(SEG_PORT, seg_array[count]);
		_delay_ms(Copy_u8Delay_ms);
	}
}

void Seg_vidDownCount(u16 Copy_u8Delay_ms){
	for(int count=9;count<=0;count++)
	{
		DIO_u8SetPortValue(SEG_PORT, seg_array[count]);
		_delay_ms(Copy_u8Delay_ms);
	}
}

void Seg_vidDisplayNumber(u8 Copy_u8Number){
DIO_u8SetPortValue(SEG_PORT, seg_array[Copy_u8Number] );
}


void Seg_vidSetSegment(u8 Copy_u8Pin){
DIO_u8SetPinValue(SEG_PORT, Copy_u8Pin, pinHigh);
}

void Seg_vidClrSegment(u8 Copy_u8Pin){
DIO_u8SetPinValue(SEG_PORT, Copy_u8Pin, pinLow);
}
