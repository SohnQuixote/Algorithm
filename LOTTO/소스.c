#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>
#define BALL_NUMBER 45
#define LOTTO_NUMBER 6
int ball[BALL_NUMBER];
void stabilize_ball(int index, int ball_number)
{
	if (index == ball_number - 1)
	{
		return;
	}
	else
	{
		for (int i = index; i < ball_number - 1; i++)
		{
			ball[i] = ball[i + 1];
		}
	}
}
void lotto(void)
{
	int ball_number = BALL_NUMBER;
	int temp;
	for (int i = 0; i < LOTTO_NUMBER; i++)
	{
		temp = rand() % ball_number;
		//printf("%d ", ball_number);
		//printf("%d ", temp);
		printf(" %d¹øÂ° : %d \n",i+1,ball[temp] );
		stabilize_ball(temp,ball_number);
		ball_number--;
	}
}

int main(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < BALL_NUMBER; i++)
	{
		ball[i] = i + 1;
	}
	lotto();
}