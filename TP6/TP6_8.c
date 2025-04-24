#include <stdio.h>

char* strSplit(char* str, char separador);

int main(void)
{
	char str[] = "Hola,,paisano";
	char* nstr;
	
	nstr = strSplit(str, ',');
	
	printf("%c\n", nstr[0]);
	
	return 0;
}

char* strSplit(char* str, char separador)
{
	unsigned int i;
	
	for(i = 0; str[i] != '\0' && str[i] != separador; i++);
	
	if(str[i] == separador)
		return &str[i+1];
	else
		return &str[i];
}
