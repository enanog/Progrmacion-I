#include <stdio.h>

#define SPANISH 0
#define ENGLISH 1

#define IDIOMA SPANISH
	
int main(void)
{
	#ifndef IDIOMA
		#warning - No esta definido el idioma | The language is not define.
	#elif IDIOMA == 0
		printf("Hola mundo!\n");
	#elif IDIOMA == 1
		printf("Hello world!\n");
	#else
		#warning - El programa no contiene ese idioma | The program does not contains that language.
	#endif
	return 0;
}
