#include <iostream>
#include <vector>
using namespace std;
/*
  1) ixw+j ixw+j-1 (i+1)xw+j 
  2) ixw+j ixw+j+1 (i-1)xw+j
  3) ixw+j ixw+j+1 (i+1)xw+j
  4) ixw+j ixw+j-1 (i-1)xw+j
  */
int calc(vector<int>&temp,int h, int w,int count)
{
	int result;
	result = 0;
	if (count == 0)
		return 1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (temp.at(i*w + j) == 0&& temp.at(i*w+j-1) == 0 && temp.at((i+1)*w+j) == 0)
			{
				count -= 3;
				temp.at(i*w + j) = 1;
				temp.at(i*w + j - 1) = 1; 
				temp.at((i + 1)*w + j) = 1;
				result += calc(temp, h, w, count);
				temp.at(i*w + j) = 0;
				temp.at(i*w + j - 1) = 0;
				temp.at((i + 1)*w + j) = 0;
				count += 3;
			}
			else if (temp.at(i*w + j) == 0 && temp.at(i*w + j + 1) == 0 && temp.at((i - 1)*w + j) == 0)
			{
				count -= 3;
				temp.at(i*w + j) = 1;
				temp.at(i*w + j + 1) = 1;
				temp.at((i - 1)*w + j) = 1;
				result += calc(temp, h, w, count);
				temp.at(i*w + j) = 0;
				temp.at(i*w + j + 1) = 0;
				temp.at((i - 1)*w + j) = 0;
				count += 3;
			}
			else if (temp.at(i*w + j) == 0 && temp.at(i*w + j + 1) == 0 && temp.at((i + 1)*w + j) == 0)
			{
				count -= 3;
				temp.at(i*w + j) = 1;
				temp.at(i*w + j +1) = 1;
				temp.at((i + 1)*w + j) = 1;
				result += calc(temp, h, w, count);
				temp.at(i*w + j) = 0;
				temp.at(i*w + j + 1) = 0;
				temp.at((i + 1)*w + j) = 0;
				count += 3;
			}
			else if (temp.at(i*w + j) == 0 && temp.at(i*w + j - 1) == 0 && temp.at((i - 1)*w + j) == 0)
			{
				count -= 3;
				temp.at(i*w + j) = 1;
				temp.at(i*w + j - 1) = 1;
				temp.at((i - 1)*w + j) = 1;
				result += calc(temp, h, w, count);
				temp.at(i*w + j) = 0;
				temp.at(i*w + j - 1) = 0;
				temp.at((i - 1)*w + j) = 0;
				count += 3;
			}
		}
	}
	return result;
}
int main(void)
{
	int c;
	int h, w;
	int temp;
	int count;
	cin >> c;
	vector <int> result;
	vector<int>stor;
	result.reserve(c);
	for (int i = 0; i < c; i++)
	{
		cin >> h >> w;
		count = 0;
		stor.reserve(h*w);
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				cin >> temp;
				if (temp == 0) count++;
				stor.push_back(temp);
				
				//# = 1
				//* = 0
			}
		
		}
		if (count % 3 != 0)
		{
			result.push_back(0);
		}
		else
		{
			result.push_back(calc(stor,h,w,count));
		
		}
		stor.clear();
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i);
	}
}