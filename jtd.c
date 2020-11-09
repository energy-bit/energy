	#include<reg51.h>
typedef unsigned char uint8;
typedef unsigned int uint16;
void delay(uint16 x)
{
uint16 i,j;
for(i=x;i>0;i--)
for(j=114;j>0;j--);
}
#define RED_EW_ON()  P0 &=~0x01
#define YELLOW_EW_ON()  P0 &=~0x02
#define GREEN_EW_ON()  P0 &=~0x04

#define RED_EW_OFF()  P0 |=0x01
#define YELLOW_EW_OFF()  P0 |=0x02
#define GREEN_EW_OFF()  P0 |=0x04

#define RED_SN_ON()  P0 &=~0x08
#define YELLOW_SN_ON()  P0 &=~0x10
#define GREEN_SN_ON()  P0 &=~0x20

#define RED_SN_OFF()  P0 |=0x08
#define YELLOW_SN_OFF()  P0 |=0x10
#define GREEN_SN_OFF()  P0 |=0x20

#define YELLOW_EW_BLINK()  P0 ^=0x02
#define YELLOW_SN_BLINK()  P0 ^=0x10

uint8 Flash_Count=0;Operation_Type=1;
void Traffic_Light()
{
switch (Operation_Type)
{
case 1:
RED_EW_OFF();YELLOW_EW_OFF();GREEN_EW_ON();
RED_SN_ON();YELLOW_SN_OFF();GREEN_SN_OFF();
delay(2000);
Operation_Type=2;
break;
case 2:
delay(120);
YELLOW_EW_BLINK();
GREEN_EW_OFF();
if( ++Flash_Count !=10) return;
Flash_Count=0;
Operation_Type=3;
break;
case 3:
RED_EW_ON();YELLOW_EW_OFF();GREEN_EW_OFF();
RED_SN_OFF();YELLOW_SN_OFF();GREEN_SN_ON();
delay(2000);
Operation_Type=4;
break;
case 4:
delay(120);
YELLOW_SN_BLINK();
GREEN_SN_OFF();
if( ++Flash_Count !=10) return;
Flash_Count=0;
Operation_Type=1;
}
}
int main()
{
while(1)Traffic_Light();
}
