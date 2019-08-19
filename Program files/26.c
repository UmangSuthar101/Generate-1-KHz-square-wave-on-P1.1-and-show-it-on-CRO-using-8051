#include <reg51.h>		/* Include x51 header file */
sbit test = P1^1;		/* set test pin0 of port1 */ 

void timer_delay()		/* Timer0 delay function */
{
	TH0 = 0xFE;		/* Load higher 8-bit in TH0 */
	TL0 = 0x41;		/* Load lower 8-bit in TL0 */
	TR0 = 1;		/* Start timer0 */
	while(TF0 == 0);	/* Wait until timer0 flag set */
	TR0 = 0;		/* Stop timer0 */
	TF0 = 0;		/* Clear timer0 flag */
}
void main()
{
	TMOD = 0x01;		/* Timer0 mode1 (16-bit timer mode) */
	while(1)
	{
		test = ~test;	/* Toggle test pin */
		timer_delay();	/* Call timer0 delay */
	}
}