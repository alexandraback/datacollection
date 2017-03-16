
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

	pin.open("B-small-attempt0.in");//m.txt
	oput.open("out_2_small");
	string p;
	getline(pin, p);
	int cNum = atoi(p.c_str());

	for (int i = 0; i < cNum; i++)
	{
		getline(pin, p);
		int pos1 = p.find(" ");
		int B = atoi(p.substr(0, pos1).c_str());
		ll N = atoll(p.substr(pos1 + 1).c_str());

		vector<ll> agv;
		getline(pin, p);
		for (int j = 0; j < B - 1; j++)
		{
			int posg = p.find(" ");
			agv.push_back(atoll(p.substr(0, posg).c_str()));
			p = p.substr(posg + 1);
		}
		agv.push_back(atoll(p.c_str()));

		ll minval = *min_element(agv.begin(), agv.end());
		ll start = 0;
		ll endp = N;
		while (abs(endp - start) > 1)
		{
			ll mid = (start + endp) / 2;
			ll cnum = 0;
			for (int z = 0; z < B; z++)
			{
				ll tmp = (mid*minval) / agv[z];
				if (tmp*agv[z] != mid*minval) tmp++;
				cnum += tmp;
			}
			if (cnum < N) start = mid;
			else endp = mid;
		}

		ll cnum = 0;
		for (int z = 0; z < B; z++)
		{
			ll tmp = (start*minval) / agv[z];
			if (tmp*agv[z] != start*minval) tmp++;
			cnum += tmp;
		}

		vector<ll> plo;
		for (int j = 0; j < B; j++)
		{
			ll gtm = (start*minval) / agv[j]; 
			if (gtm*agv[j] != start*minval) gtm++;
			plo.push_back(gtm*agv[j]);
		}

		int minpos = 0;
		for (ll z = 0; z < N - cnum; z++)
		{
			ll minval = 100000000000000000;
			for (int j = 0; j < B; j++)
			{
				if (plo[j] < minval){
					minval = plo[j];
					minpos = j;
				}
			}
			plo[minpos] += agv[minpos];
		}

		oput << "Case #" << i + 1 << ": "<<minpos+1 << endl;
	}
	pin.close();
	oput.close();

	cout << "Program Done!" << endl;
	getchar();
	//return 0;
}
