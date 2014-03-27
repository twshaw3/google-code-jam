#include <stdio.h>
#include <string.h>

void solve(char* message, char* translation);
void getCode(char letter, char* code);

void main(void)
{
	int i, T;
	char T_char[1];
	gets(T_char);
	T = atoi(T_char);
	for(i = 0; i < T; i++)
	{
		char message[1001];
		char translation[5000];
		gets(message);
		solve(message, translation);
		printf("Case #%d: %s\n", (i+1), translation);
	}
}

void solve(char* message, char* translation)
{
	int i, j, l;
	int len;
	len = strlen(message);
	l = 0;
	for(i = 0; i < len; i++)
	{
		char trans[5];
		getCode(message[i], trans);
		if((l != 0) && (trans[0] == translation[l - 1])) translation[l++] = ' ';
		for(j = 0; j < strlen(trans); j++)
		{
			translation[l + j] = trans[j];
		}
		l += j;
	}
	translation[l] = '\0';
}

void getCode(char letter, char* code)
{
	int offset; 
	int k;
	if(letter == ' ')
	{
		letter = 0;
		offset = 1;
	}
	else if(letter < (int)'s')
	{
		letter = (int)letter - 97; //map 'a' to 0
		offset = (letter % 3) + 1;
		letter = (letter + 6)/3;
	}
	else if(letter < (int)'w')
	{
		if(letter == (int)'s')
		{
			letter = 7;
			offset = 4;
		}
		else
		{
			offset = (letter - (int)'t') + 1;
			letter = 8;
		}
	}
	else
	{
		offset = (letter - (int)'w') + 1;
		letter = 9;
	}
	for(k = 0; k < offset; k++)
	{
		code[k] = (char)(letter + 48);
	}
	code[offset] = '\0';
}
