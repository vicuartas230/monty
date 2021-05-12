#include "monty.h"

/**
 * char_to_array - This function converts a string to an array of pointers.
 * @str: The string to convert.
 * Return: The array of pointers.
 */

char **str_to_array(char *str, unsigned int lines)
{
    char **arr = NULL, *token = NULL;
    unsigned int i = 0;

    arr = malloc((lines + 1) * sizeof(char *));
    if (!arr)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    while (i < lines)
    {
        if (!i)
            token = strtok(str, "\n");
        else
            token = strtok(NULL, "\n");
        arr[i] = _strdup(token);
        i++;
    }
    arr[i] = NULL;
    return (arr);
}

/**
 * _strdup - This function returns a pointer to a new string which is
 * a duplicate of the string s.
 * @s: The string to duplicate.
 * Return: a pointer to the duplicated string.
 */
char *_strdup(const char *s)
{
	int i = 0;
	char *cpy = NULL;

	if (!s || !*s)
		return (NULL);
	cpy = malloc(sizeof(char) * (_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/**
 * count_lines - Function that counts the words writed in terminal
 * @buff: to temporarily store the words
 * @delim: words delimiter
 * Return: the number of words
 */
int count_lines(char *buff, char *delim)
{
	int step = 0, i = 0;
	unsigned int words = 0;

	while (buff[i])
	{
		if (buff[i] == delim[0])
			step = 0;
		else if (step == 0)
		{
			step = 1;
			words++;
		}
		i++;
	}
	return (words);
}

/**
 * _strlen - Function that returns the length of a string
 * @s: string of characters
 * Return: number of characters
 */

int _strlen(const char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strncmp - This function compares n positions of strings s1 and s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 * Return: 0, if s1 and s2 are equal or The diference between s1 and s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a = 0, e = 0;

	for (; a < n; a++)
	{
		if (s1[a] != s2[a])
		{
			e = (s1[a] - s2[a]);
			break;
		}
		else
		{
			e = 0;
		}
	}
	return (e);
}
