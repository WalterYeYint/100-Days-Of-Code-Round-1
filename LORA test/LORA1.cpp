#include <stdio.h>
main()
{
	int i,j=15;
	printf("Guess number");
	scanf("%d",&i);
	if (i < 1 || i > 100)
	printf("OUT OF BOUNDS");
else if (i <= 20&&i >= 10&&i!=15)
	printf("WARM!");
	else if ( i >= 5&& i <= 25&&i!=15 )
	printf("COLD!");
	else if (i < 5&&i<=35 && i!=0 && i != 15)
	printf( "WARMER!");
	else if (i >35 && i<=100)
	printf("COLDER!");
	else if ( i == j)
	printf("You 've guessed correctly\nHow many guesses it took?");
	
	
	
	
}