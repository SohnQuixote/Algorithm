#include <stdio.h>
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	if ((int)a % (int)b == 0)
	{
		printf("%d", (int)a / (int)b);
	}
	else
	{
		printf("%lf", (double)a / (double)b);
	}
	return 0;
}