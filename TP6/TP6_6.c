#include <stdio.h>

#define TOUPPER(c) (((c) >= 'a' && (c) <= 'z')? (c) - 'a' + 'A' : (c))
#define TOLOWER(c) (((c) >= 'A' && (c) <= 'Z')? (c) - 'A' + 'a' : (c))
#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define ISLOWER(c) ((c) >= 'a' && (c) <= 'z')

void CamelCase(char* str);

int main()
{
	char str[] = "Will I paSS the EXAM? I hOPe so. i'VE stuDIEd a lot... NOT!\n";
	
	CamelCase(str);
	
	unsigned int i;
	
	for(i = 0; str[i] != '\0'; i++)
		printf("%c", str[i]);
		
	return 0;
}

void CamelCase(char* str)
{
	unsigned int i;
	unsigned int first_letter = 1;
	
	for(i = 0; str[i] != '\0'; i++)
	{
		if(ISUPPER(TOUPPER(str[i])))
		{
			if(first_letter)
			{
				str[i] = TOUPPER(str[i]);
				first_letter = 0;
			}
			else
				str[i] = TOLOWER(str[i]);
		}
		else
			first_letter = 1;
	}
}

