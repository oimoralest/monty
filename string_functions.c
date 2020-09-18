#include "monty.h"
/**
 * _strtok - function separate the string in tokens
 * @arg: string
 * @dlm: delimiter
 * Return: a pointer to the next token
 */
char *_strtok(char *arg, char *dlm)
{
	static char *token;
	int c = 0, found = 0, i = 0;
	char *str = NULL;

	if (!dlm || (arg == NULL && token == NULL))
		return (0);
	if (arg != NULL)
		str = arg;
	if (arg == NULL)
		str = token;
	while (str[i] == dlm[0])
		i++;
	for (c = i; str[c] != '\0'; c++)
		if (str[c] == dlm[0])
		{
			found = 1;
			break;
		}
	for ( ; str[c] != '\0'; c++)
		if (str[c] != dlm[0])
			break;
		else if (str[c + 1] == '\0')
		{
			str[c] = '\0';
			found = 0;
			break;
		}
		else
			str[c] = '\0';
	if (!found)
	{
		token = NULL;
		return (str + i);
	}
	if (*(str + c) != '\0')
		token = str + c;
	else
		token = '\0';
	return (str + i);
}