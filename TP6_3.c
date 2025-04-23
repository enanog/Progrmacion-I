#include <stdio.h>

#define MODULO(c) (((c) < 0)? -(c): (c))

void print_rombo(int n);

int main(void)
{
	print_rombo(8);
	return 0;
}

void print_rombo(int n)
{
	int i, j;
	int cant_max = n*2-1;
	if(1 <= n && n <= 25)
	{
		for(i = 1; i <= cant_max; i++)
		{
			for(j = MODULO(n-i); 0 < j; j--)
				printf(" ");
				
			for(j = cant_max - MODULO(2*(n-i)); 0 < j; j--)
				printf("*");
				
			printf("\n");
		}
	}
}


