#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
int result[2];//0 = min 1 = max
double angle[3];
point points[3];
typedef struct point
{
	int x;
	int y;
}point;
double calc_ang(int x_1, int y_1, int x_2, int y_2)
{
	return (double(y_1) - double(y_2)) / (double(x_1) - double(x_2));
}
int calc_rect(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3)
{
	result[0] = -1;
	result[1] = 0;
	angle[0] = calc_ang(x_1, y_1, x_2, y_2);
	angle[1] = calc_ang(x_2, y_2, x_3, y_3);
	angle[2] = calc_ang(x_1, y_1, x_3, y_3);
	//result[0] 수식을 적용해서 좌표를 계산한 뒤 거리를 계산해서 저장



	return result[1] - result[0];
	
	if (result[1] == 0 && result[0] == -1)
	{
		return -1;
	}
	
}
int main(void)
{
	int x_1, y_1, x_2, y_2, x_3, y_3;

	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;





}