#include "main.h"

int strlen_no_wilds(char *str);
void iterate_wild(char **wildstr);
char *postfix_match(char *str, char *postfix);
int wildcmp(char *s1, char *s2);

/**
 * strlen_no_wilds - Return length of a string, ignoring wildcard.
 * @str: the string to be measures.
 *
 * Return: the len.
 */
int strlen_no_wilds(char *str)
{
	int len = 0;
	int index = 0;

	if (*(str + index))
	{
		if (*str != '*')
			len++;
		index++;
		len += strlen_no_wilds(str + index);
	}
	return (len);
}
/**
 * iterate_wild - iterates through a string located at a wildcard unit
 * it point to a non wildcard.
 * @wildstr: thr string to be iterated through.
 */
void iterate_wild(char **wildstr)
{
	if (**wildstr == '*')
	{
		(*wildstr)++;
		iterate_wild(wildstr);
	}
}
/**
 * postfix_match - Checks if a string str matches the postfix of
 *                 another string potentially containing wildcards.
 * @str: The string to be matched.
 * @postfix: The postfix.
 *
 * Return: If str and postfix are identical - a pointer to the null byte
 *                                            located at the end of postfix.
 *         Otherwise - a pointer to the first unmatched character in postfix.
 */
char *postfix_match(char *str, char *postfix)
{
	int str_len = strlen_no_wild(str) - 1;
	int postfix_len = strlen_no_wilds(postfix) - 1;

	if (*postfix == '*')
		iterate_wild(&postfix);
	if (*(str + str_len - postfix_len) == *postfix && *postfix != '\0')
	{
		postfix++;
		return (postfix_match(str, postfix));
	}
	return (postfix);
}
/**
 * wildcmp - Write a function that compares two strings and returns 1
 * if the strings can be considered identical, otherwise return 0.
 *
 * @s1: first string 
 * @s2: second string
 * Return: if string is consider identical 1.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		iterate_wild(&s2);
		s2 = postfix_match(s1, s2);
	}
	if (*s1 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	else
		return (wildcmp(++s1, ++s2));
}
