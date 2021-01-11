#include "holberton.h"

/**
 * str_len - Get the length of a string.
 * @str: Pointer to string.
 *
 * Return: Length of string.
 */
int str_len(char *str)
{
	int i;

	/* take str length */
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _isdigit - checks if characters is digit
 * @str: character to be checked
 *
 * Return: 1 on Success, 0 on Fail
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

/**
 * add_str - Add the string representations of two numbers.
 * @result: Rolling result of ongoing multiplications.
 * @buffer: New product to be added to rolling result.
 * @i: Position in rolling result to begin adding new product.
 *
 * Return: String representation of sum.
 */
char *add_str(char *result, char *buffer, int i)
{
	int result_len = str_len(result);
	int k, j, sum = 0, carry = 0;

	char *new_result;

	/* allocate mem for sum str & null-byte */
	new_result = malloc(sizeof(char) * (result_len + 1));
	if (new_result == NULL)
		return (NULL);

    /* initialize result */
	for (k = 0; k < result_len; k++)
		new_result[k] = '0';

	/* adjust for place count */
	for (j = 0; j < i; j++)
		new_result[j] = result[j];

	for (k = 0; buffer[k] != '\0'; k++)
	{
		/* add digits */
		sum = (result[k + j] - '0') + (buffer[k] - '0');
		/* write sum to new result */
		new_result[k + j] = ((sum % 10) + carry) + '0';
		/* calculate new carry */
		carry = sum / 10;

		if (buffer[k + 1] == '\0')
		{
			if (carry != 0)
			{
				new_result[k + j + 1] = ((result[k + 1] - '0') + carry) + '0';
			}
		}
	}
	/* return sum */
	return (new_result);
}

/**
 * mul_str - Multiplies two string of any length.
 * @num1: First string to multiply.
 * @num2: Second string to multiply.
 *
 * Return: String representation of multiplication product.
 */
char *mul_str(char *num1, char *num2)
{
	int prod, carry = 0;
	int i, j, k, place_cnt = 0;
	int num1_len = str_len(num1);
	int num2_len = str_len(num2);
	char *result, *buffer;

	result = malloc(sizeof(char) * (num1_len + num2_len + 1));
	if (result == NULL)
		return (NULL);

	for (k = 0; k < num1_len + num2_len; k++) /* initialize result */

		result[k] = '0';

	buffer = malloc(sizeof(char) * (num1_len + num2_len + 1));
	if (buffer == NULL)
		return (NULL);
	for (i = num1_len - 1; i >= 0; i--, place_cnt++) /* loop through num1 */
	{
		carry = k = 0;
		for (j = num2_len - 1; j >= 0; j--, k++) /* loop through num2 */
		{
			prod = (num1[i] - '0') * (num2[j] - '0'); /* multiply converted chars */
			buffer[k] = ((prod % 10) + carry) + '0'; /* grab remainder for digit */
			carry = prod / 10; /* calculate carry */

			if (j == 0) /* check for/add final carry */
			{
				if (carry != 0)
				{
					buffer[k + 1] = carry + '0';
					buffer[k + 2] = '\0';
				}
				else
					buffer[k + 1] = '\0';
			}
		}
		result = add_str(result, buffer, place_cnt); /* add buffer to result */
	}
	return (result); /* return product of multiplication */
}

/**
 * main - multiply two pos numbers
 * @argc: argument count
 * @argv: argument(s)
 *
 * Return: 0 on success; exits with code 98 on failure.
 */
int main(int argc, char **argv)
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	char *product;
	int i;

	/* check arg count */
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	/* check for non-digit */
	if (!(_isdigit(num1) && _isdigit(num2)))
	{
		printf("Error\n");
		exit(98);
	}

	product = mul_str(num1, num2); /* multiply number */

    /* Remove trailing zeros */
	for (i = str_len(product) - 1; i >= 0; i--)
	{
		if (product[i] != '0' || i == 0)
		{
			product[i + 1] = '\0';
			break;
		}
	}

	/* print product string */
	for (i = str_len(product); i >= 0; i--)
	{
		_putchar(product[i]);
	}
	_putchar('\n');

	return (0);
}
