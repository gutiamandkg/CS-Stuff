// DP_RodCutting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BottomUpCutRod(vector<int> &p, int n)
{
	int* r = new int[n];
	r[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		int q = -INT_MAX;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}

	cout << "given n = " << n << ", we get: " << r[n] << endl;

	int ret = r[n];
	delete[] r;

	return ret;
}

int main()
{
	vector<int> p = { 1,5,8,9,10,17,17,20,24,30 };

	BottomUpCutRod(p, 1);
	BottomUpCutRod(p, 4);
	BottomUpCutRod(p, 10);

    return 0;
}

