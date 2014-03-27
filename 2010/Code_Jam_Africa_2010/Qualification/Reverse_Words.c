#include <stdio.h>
#include <string.h>

void solve(char* words, char* rev_words);

void main(void)
{
	int i, T;
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		char words[1001];
		char rev_words[1001];
		gets(words);
		solve(words, rev_words);
		printf("Case #%d: %s\n", (i+1), rev_words);
	}
}

void solve(char* words, char* rev_words)
{
	int k, l, j;
	int len;
	len = strlen(words);
	k = 0;
	l = 0;
	rev_words[len] = '\0';
	while(1)
	{
		while(words[l] != ' ') 
		{
			l++;
			if(l >= len) break;
		}
		j = 0;
		while(k < l)
		{
			rev_words[len - l + j] = words[k];
			j++;
			k++;
		}
		if(len - l + j < len) rev_words[len - l + j] = ' ';
		if(l >= (len - 1)) return;
		l++;
		k = l;
	}
}
