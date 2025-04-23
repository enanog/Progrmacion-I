#include <stdio.h>

int pierna_poker(const int cartas[]);

int main(void)
{
	int cartas[] = {101,202,301,402,501};
	printf("%s", (pierna_poker(cartas))? "Hubo pierna.\n": "No hubo pierna.\n");
	
	return 0;
}

int pierna_poker(const int cartas[])
{
	int num_cart[13];
	int pierna = 0;
	int i;
	
	for(i = 0; i < 5; i++)
		num_cart[cartas[i]%100-1]++;
		
	for(i = 0; i < 13 && !pierna; i++)
		pierna = (num_cart[i] >= 3);
		
	return pierna;
}
