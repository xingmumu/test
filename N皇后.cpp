#include "pch.h"
/*
用n元组x[1:n]表示n后问题的解。x[i]表示皇后i放置在棋盘的第i行的第x[i]列
*/

#include<iostream>
#include <math.h>

using namespace std;

static int n, x[1000];
static long sum;
//first change 
/*
判断第k个后能不能放在x[k]处
两个皇后不能放在统一斜线上：
若2个皇后放置的位置分别是（i,j）和（k,l）,
且 i-j = k -l 或 i+j = k+l，则说明这2个皇后处于同一斜线上。
*/

void OutPut()
{
	for (int i = 1; i <= n; ++i)
		cout << x[i] << " ";//输出对应行的列数，数组的顺序表示行数，如第一个数字7表示在第一行第7列
	cout << endl;//在一行的一种情况输出完毕之后换一行
}

int Place(int k)//放置并判断判断是否在同一斜线上
{
	int i;
	for (i = 1; i < k; i++)
	{
		if (x[k] == x[i] || abs(i - k) == abs(x[i] - x[k]))
			return 0;
	}
	return 1;
}

void BackTrack1(int t)
{
	int i;
	if (t > n)
	{
		sum++;
		OutPut();
		return;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			x[t] = i;
			if (Place(t))
			{
				BackTrack1(t + 1);
			}
		}
	}
}

void BackTrack()
{
	int k = 1;
	x[1] = 0;
	while (k >= 1)
	{
		x[k]++;
		while (x[k] <= n && !Place(k))
		{
			x[k]++;
		}
		if (x[k] <= n)
		{
			if (k == n)
			{
				sum++;
				OutPut();
			}

			else
			{
				x[++k] = 0;
			}
		}
		else
		{
			k--;
		}
	}
}

int main()
{
	while (1)
	{
		cin >> n;
		sum = 0;
		for (int i = 0; i <= n; ++i)
		{
			x[i] = 0;
		}
		BackTrack();
		//BackTrack1(1);
		cout << "方案种数：" << sum << endl;;
	}
	return 0;
}
