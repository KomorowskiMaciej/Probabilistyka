#include <stdio.h>
#include <stdlib.h>


#define size 5


struct StrukturaPermutacji
{
	struct StrukturaPermutacji * parent;
	struct StrukturaPermutacji ** children;
	int count;
	int value;
};

struct StrukturaPermutacji * StworzPermutacje(int set[], int setCount, int value, struct  StrukturaPermutacji * parent)
{
	struct StrukturaPermutacji * node = malloc(sizeof(struct StrukturaPermutacji));
	node->value = value;
	node->count = setCount;
	node->parent = parent;
	if (setCount == 0)
	{
		node->children = NULL;
		return node;
	}
	node->children = calloc(setCount,sizeof(struct StrukturaPermutacji*));

	for (int i = 0; i < setCount; i++)
	{
		int * newSet = calloc(setCount-1, sizeof(int));
		for (int j = 0; j < i; j++)
		{
			newSet[j] = set[j];
		}
		for (int j = i+1; j < setCount; j++)
		{
			newSet[j - 1] = set[j];
		}
		node->children[i] = StworzPermutacje(newSet, setCount-1,set[i], node);
		free(newSet);
	}
	return node;
}

void Wydrukuj_permutacje(struct StrukturaPermutacji * node)
{
	if (node->children == NULL)
	{
		while (node->parent != NULL)
		{
			printf_s("%d ", node->value);
			node = node->parent;
		}
		printf_s("\n");
		return;
	}
	for (int i = 0; i < node->count; i++)
	{
		if (node->children[i] != NULL)
		{
			Wydrukuj_permutacje(node->children[i]);
		}
	}
}

unsigned long long silnia(int a) {
	if ((a == 0) || (a == 1)) return 1;
	int s = 1;
	for (int i = 1; i <= a; i++) s *= i;
	return s;
}

int DwumianNewtona(int m, int n)
{
	if (n == 0)
		return 1;
	else if (m == 0)
		return 0;
	else
		return DwumianNewtona(--m, --n) + DwumianNewtona(m, n + 1);
}

void Wydrukuj_kombinacje(int const set[], int start, int setCount, const int comLength, int result[], int count)
{
	if (count == comLength)
	{
		for (int i = 0; i < comLength; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < setCount; i++)
	{
		result[count] = set[i];
		Wydrukuj_kombinacje(set, i+1, setCount, comLength, result, count+1);
	}
}

int main()
{


	printf("%d", DwumianNewtona(20,3));

	return 0;

	
	int tab[size];
	for (int i = 0; i < size; i++) tab[i] = i;

	int result[3];
	
	struct StrukturaPermutacji * root = StworzPermutacje(tab, size, 0, NULL);
	Wydrukuj_permutacje(root);
	//Wydrukuj_kombinacje(tab, 0, size, 3, result,0);
	return 0;
}
