#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, sum = 0;
	printf("argc = %d\n", argc);
	printf("what's in argv[]\n");
	if(argc > 1){
		for (i = 0; i < argc; i++)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
			sum += atoi(argv[i]);
		}
		printf("Total = %d\n", sum);
	}
	return 0;
}