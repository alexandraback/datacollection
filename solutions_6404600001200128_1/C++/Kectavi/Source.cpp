
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

typedef long long ll;

void main()
{

ifstream pin;
ofstream oput;

pin.open("A-large.in");//m.txt
oput.open("out_1_l");
string p;
getline(pin, p);
int cNum = atoi(p.c_str());

for (int i = 0; i < cNum; i++)
{
	getline(pin, p);
	int N = atoi(p.c_str());

	vector<ll> avy;
	getline(pin, p);
	for (int j = 0; j < N-1; j++)
	{
		int pos1 = p.find(" ");
		avy.push_back(atoll(p.substr(0, pos1).c_str()));
		p = p.substr(pos1 + 1);
	}
	avy.push_back(atoll(p.c_str()));

	ll fnum = 0;
	for (int j = 0; j < N-1; j++)
	{
		if (avy[j] > avy[j+1]) fnum += (avy[j] - avy[j+1]);
	}

	ll maxval = 0;
	for (int j = 0; j < N - 1; j++)
	{
		if (avy[j] > avy[j + 1] && maxval < (avy[j] - avy[j + 1]))
			maxval = avy[j] - avy[j + 1];
	}
	ll snum = 0;
	for (int j = 0; j < N-1; j++)
	{
		if (avy[j] <= maxval) snum += avy[j];
		else snum += maxval;
	}

	oput << "Case #" << i + 1 << ": "<<fnum <<" "<<snum << endl;
}
pin.close();
oput.close();


	cout << "Program Done!" << endl;
	getchar();
	//return 0;
}
