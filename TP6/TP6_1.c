#include <stdio.h>

#define TOUPPER(c) (((c) >= 'a' && (c) <= 'z')? (c) - 'a' + 'A' : (c))

int ordenalfa(char* str1, char* str2);

int main()
{
	int orden = ordenalfa("lala", "Ho");
	
	if(orden)
		printf("Esta antes el string %d\n", (orden == -1)? 1 : 2);
		
	else
		printf("Los stings son iguales\n");
	
	return 0;
}

int ordenalfa(char* str1, char* str2)
{
	unsigned int i, fin_lectura = 0;
	for(i = 0; str1[i] != '\0' && str2[i] != '\0' && (!fin_lectura); i++)
	{
		if(TOUPPER(str1[i]) < TOUPPER(str2[i]))
			fin_lectura = -1;
		
		else if(TOUPPER(str1[i]) > TOUPPER(str2[i]))
			fin_lectura = 1;
	}
	
	if(str1[i] != str2[i] && (!fin_lectura))
		fin_lectura = (str1[1] == '\0')? -1 : 1;
	
	return fin_lectura;
}


