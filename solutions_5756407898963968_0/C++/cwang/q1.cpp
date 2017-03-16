#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <assert.h>
#include <time.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <bitset>
#include <exception>
#include <memory>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>

#include <cctype>
#include <cstddef>
#include <cstring>
#include <ctime>

#define NOMINMAX
#include <windows.h>

#define	SAFE_DELETE(ptr) if(ptr){delete ptr; ptr=NULL;}
#define	SAFE_DELETE_ARRAY(ptr) if(ptr){delete [] ptr; ptr=NULL;}

using namespace std;

string run(int ans1, int M1[4][4], int ans2, int M2[4][4] )
{
	vector<int> vrow1(M1[ans1-1], M1[ans1-1]+4);
	vector<int> vrow2(M2[ans2-1], M2[ans2-1]+4);

	set<int> s1(vrow1.begin(), vrow1.end());
	vector<int> rst;
	for (int i=0; i<vrow2.size(); i++)
	{
		if (s1.find(vrow2[i]) != s1.end())
			rst.push_back(vrow2[i]);
	}

	if (rst.size() == 1)
	{
		char str[300];
		sprintf(str, "%d", rst[0]);
		return str;
	}
	else if (rst.size() > 1)
		return "Bad magician!";
	else
		return "Volunteer cheated!";
}

int main()
{
	freopen("datain.txt", "r", stdin);
	freopen("dataout.txt", "w", stdout);

	int T; cin >> T;

	for (int i=0; i<T; i++)
	{
		int ans1, ans2;
		int M1[4][4], M2[4][4];

		cin >> ans1;
		for (int r=0; r<4; r++)
		{
			for(int c=0; c<4; c++)
			{
				cin >> M1[r][c];
			}
		}

		cin >> ans2;
		for (int r=0; r<4; r++)
		{
			for(int c=0; c<4; c++)
			{
				cin >> M2[r][c];
			}
		}

		stringstream ss;
		ss << "Case #" << (i+1) << ": ";
		string rst = run(ans1, M1, ans2, M2);
		ss << rst << endl;
		cout << ss.str();
	}

	fclose(stdout);
	fclose(stdin);
	return 1;
}