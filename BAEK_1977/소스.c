#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int min, sum, max;
	for (int i = 1; i*i<n; i++)
	{
		min = i;
	}
	min += 1;
	sum = min * min;
	if (min*min>m)
	{
		printf("-1\n");
		return;
	}
	for (int j = min + 1; j*j <= m; j++)
	{
		sum += j * j;
		max = j;
	}
	min *= min;
	printf("%d\n%d\n", sum, min);
}