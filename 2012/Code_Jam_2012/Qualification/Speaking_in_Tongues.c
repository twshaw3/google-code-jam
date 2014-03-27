#include <stdio.h>
#include <string.h>

// a -> y
// o -> e
// z -> q

int charToInt(char x);
void updateDictionary(char* in, char* out);
void initializeDictionary(void);
void visualizeDictionary(void);
void translate(char* in, char* out);

char dictionary[26];

void main(void)
{
	char G[100];
	char S[100];
	int i, T;
	char* in1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	char* in2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	char* in3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char* out1 = "our language is impossible to understand";
	char* out2 = "there are twenty six factorial possibilities";
	char* out3 = "so it is okay if you want to just give up";
	initializeDictionary();
	dictionary[charToInt('y')] = 'a';
	dictionary[charToInt('e')] = 'o';
	dictionary[charToInt('q')] = 'z';
	dictionary[charToInt('z')] = 'q';
	updateDictionary(in1, out1);
	updateDictionary(in2, out2);
	updateDictionary(in3, out3);
	scanf("%d\n", &T);
	for(i = 0; i < T; i++)
	{
		gets(G);
		translate(G, S);
		printf("Case #%d: %s\n", (i+1), S);
	}
}

void translate(char* in, char* out)
{
	int k;
	for(k = 0; k < strlen(in); k++)
	{
		out[k] = dictionary[charToInt(in[k])];
	}
	out[k] = '\0';
}

int charToInt(char x)
{
	return ((int)x - 97);
}

void updateDictionary(char* in, char* out)
{
	int j;
	for(j = 0; j < strlen(in); j++)
	{
		dictionary[charToInt(in[j])] = out[j];
	}
}

void initializeDictionary(void)
{
	int k;
	for(k = 0; k < 26; k++) dictionary[k] = '_';
}

void visualizeDictionary(void)
{
	int k;
	for(k = 0; k < 26; k++) printf("%c",dictionary[k]);
	printf("\n");
}
