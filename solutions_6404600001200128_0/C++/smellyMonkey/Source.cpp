#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <cstdlib>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("data.in");
	outFile.open("data.out");

	
	int T;
	inFile >> T;

	for (int ca = 1; ca <= T; ++ca)
	{
		int n;
		inFile >> n;

		vector<int> m(n);

		for (int i = 0; i < n; ++i)
			inFile >> m[i];

		int y = 0;

		for (int i = 1; i < n; ++i)
		{
			if (m[i] >= m[i - 1])
				continue;

			y += m[i-1]-m[i];
		}

		int speed = 0;
		for (int i = 1; i < n; ++i)
		{
			int eated = m[i-1] - m[i];

			if (eated <= 0)
				continue;

			speed = max(speed, eated);

		}

		int x = 0;
		for (int i = 0; i < n-1; ++i)
		{
			if (m[i] - speed <= 0)
				x += m[i];
			else
				x += speed;
		}
	

		
		outFile << "Case #" << ca << ": " << y <<" "<<x<< endl;
		//cout << ans << endl;
	}


	inFile.close();
	outFile.close();

	return 0;
}
