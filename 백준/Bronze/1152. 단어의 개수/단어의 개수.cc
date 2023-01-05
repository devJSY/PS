#include <iostream>

int main()
{
	int i, cnt = 0;
	char a[1000500];

	std::cin.getline(a, 1000500, '\n');

	for (i = 0; a[i] != '\0'; ++i)
	{
		if (a[i] != ' ')
		{
			if (a[i + 1] == ' ' || a[i + 1] == '\0')
			{
				++cnt;
			}			
		}
	}

	printf("%d", cnt);

	return 0;
}

