#include <stdio.h>
#include <stdint.h>

#define IS_A_SIGN(c) ( (c) == '-' || (c) == '+' )
#define IS_A_DIGIT(c) ( (c) >= '0' && (c) <= '9' )
#define IS_A_NUMBER(c) ( IS_A_SIGN(c) || IS_A_DIGIT(c) || (c) == '.' )

unsigned int parse_to_double(double* number, char* string, unsigned int string_length);
unsigned int search_valid_imput(char** string, unsigned int* string_length);
double integer_power_of_x(double x, int n);
void clear_stdi();

int main ()
{
	double number;
	unsigned int readed = 0;
	char buffer[] = "   -10.1023 43+1-10-02-1+10==11vbbbxcvjsd748534h1hg21g212j3h       .333567 d.d .";
	unsigned long buffer_size = sizeof(buffer)/sizeof(char);
	for (readed = 0; (buffer_size - readed) != 1;)
	{
		readed += parse_to_double(&number, buffer + readed, buffer_size - readed);
		printf("\nnumber = %lf", number);
	}
	printf("\n");
	return 0;
}

unsigned int parse_to_double(double* number, char* string, unsigned int string_length)
{
	unsigned int readed_elements;
	unsigned int i;
	int exponent;

	if (number == NULL || string == NULL || string_length == 0)
		return 0;

	*number = 0.0;
	readed_elements = search_valid_imput(&string, &string_length);
	if (readed_elements == 0)
		return string_length;

	for (i = IS_A_SIGN(string[0]); string[i] != '\0' && i < string_length && string[i] != '.'; i++)
	{
		*number *= 10.0;
		*number += (double)(string[i] - '0');
	}

	for (i++, exponent = -1; string[i] != '\0' && i < string_length; i++)
	{
		*number += integer_power_of_x(10, exponent--) * (double)(string[i] - '0');
	}

	*number *= (string[0] == '-') ? -1.0 : 1.0;

	return readed_elements;
}

unsigned int search_valid_imput(char** string, unsigned int* string_length)
{
	unsigned int readed_elements;
	unsigned int i;
	unsigned int amount_of_points;

	if (string == NULL || *string == NULL || string_length == NULL || *string_length == 0)
		return 0;

	for (i = 0; (*string)[i] != '\0' && i < *string_length && !IS_A_NUMBER((*string)[i]); i++);

	if (i == *string_length || (*string)[i] == '\0')	// Esto significa que el string no tenia numeros
		return 0;

	readed_elements = i;
	*string += i;	// Movemos el puntero del comienzo del string al inicio del numero.
	*string_length -= i;	// Ajustamos la longitud del string para no escribir fuera del mismo.

	for (i = IS_A_SIGN((*string)[0]), amount_of_points = 0; (*string)[i] != '\0' && i < *string_length && ((*string)[i] == '.' || IS_A_DIGIT((*string)[i])) && amount_of_points < 2; i++)
	{
		amount_of_points += (*string)[i] == '.';
	}

	readed_elements += i;
	*string_length = i;

	return readed_elements;
}

double integer_power_of_x(double x, int n)
{
	if ( n < 0)
		return 1. / integer_power_of_x(x, -n);
	if ( n == 0)
		return 1;
	return x * integer_power_of_x(x,--n);
}

void clear_stdi()
{
	while (getchar() != '\n');
}