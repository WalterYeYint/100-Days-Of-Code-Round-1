#include <stdio.h>
main()
{
char c;
	printf("P for Pyrthagoras,L for linear algebra,T for trigonometery\n");
	printf("Enter your choice");
	scanf("%c",&c);
	if ( c == 'P')
	printf("Square of hypo side= square of ajacent side+ square of opposite side");
	else if( c == 'L')
printf("3x + y = 8\n x + y =9");
else if(c=='T')
printf("sin A = opposite side / ajacent side");
	
}