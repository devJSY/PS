#include <stdio.h>
#include <string.h> 

int stack[10001] = {};
int Index = 0;

void push(int X)
{
	stack[Index++] = X;
}

void pop()
{
	--Index;

	if (Index < 0)
	{
		Index = 0;
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", stack[Index]);
		stack[Index] = -1;
	}
}

void size()
{
	int i = 0;

	while (1)
	{
		if (stack[i] != -1)
		{
			++i;
		}
		else
		{
			break;
		}
	}

	printf("%d\n", i);
}

void empty()
{
	int count = Index;
	bool Trig = false;

	while (count >= 0)
	{
		if (stack[count] != -1)
		{
			Trig = true;
			break;
		}
		--count;
	}

	if (Trig)
	{
		printf("%d\n", 0);
	}
	else
	{
		printf("%d\n", 1);
	}
}

void top()
{
	if (Index == 0)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", stack[Index - 1]);
	}
}

int main()
{
	int init = 10001 - 1;

	while (init >= 0)
	{
		stack[init] = -1;
		--init;
	}

	int input, n;
	int i;
	int num;
	char wtd[100];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		num = 0;
		scanf("%s", wtd);
		if (strcmp(wtd, "push") == 0) {
			scanf("%d", &input);
			push(input);
		}
		else if (strcmp(wtd, "pop") == 0)
		{
			pop();
		}
		else if (strcmp(wtd, "size") == 0)
		{
			size();
		}
		else if (strcmp(wtd, "top") == 0)
		{
			top();
		}
		else if (strcmp(wtd, "empty") == 0)
		{
			empty();
		}
	}

	return 0;
}