#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip> 

using namespace std;

int main()
{
	freopen ("A-large.in","r", stdin);
	//freopen("test","r",stdin);
	freopen ("out.txt","w",stdout);
	int k;
	cin >> k;
	for(int s = 0; s < k; s++)
	{
		cout << "Case #" << s + 1 << ": ";
		int N;
		cin >> N;
		cin.ignore(1,'\n');
		vector<vector<pair<char,int>>> cads;
		for(int i = 0; i < N; i++)
		{
			vector<pair<char,int>> cad;
			string cadd;
			getline(cin, cadd);
			char ant = ' ';
			char c;
			for(int j = 0; j < cadd.size(); j++)
			{
				c = cadd[j];
				if(c == ant)
					cad[cad.size()-1].second++;
				else
					cad.push_back(make_pair(c,1));
				ant = c;
			}
			cads.push_back(cad);
		}
		
		/*for(int i = 0; i < N; i++)
		{
			cout << i << ": ";
			for(int j = 0; j < cads[i].size(); j++)
				cout << cads[i][j].first << cads[i][j].second << " ";
			cout << endl;
		}*/
		
		// chequear tamanos
		bool valeTam = true;
		int tamanos = cads[0].size();
		for(int i = 0; i < cads.size(); i++)
			if(tamanos != cads[i].size())
			{
				valeTam = false;
				break;
			}
		if(!valeTam)
		{
			cout << "Fegla Won" << endl;
			continue;
		}
		// chequear letras
		bool valeLetra = true;
		for(int i = 0; i < cads[0].size(); i++) // Por cada letra
		{
			char c = cads[0][i].first;
			for(int p = 0; p < cads.size(); p++) // Por cada palabra
			{
				if(c != cads[p][i].first)
				{
					valeLetra = false;
					break;
				}
			}
			if(!valeLetra)
				break;
		}
		if(!valeLetra)
		{
			cout << "Fegla Won" << endl;
			continue;
		}
		
		//
		int res = 0;
		for(int i = 0; i < cads[0].size(); i++) // Por cada letra
		{
			int val = 1000000;
			for(int j = 1; j <= 100; j++) // Por cada posible
			{
				int acc = 0;
				for(int p = 0; p < cads.size(); p++)
				{
					int ind = cads[p][i].second - j;
					if(ind < 0)
						ind *= -1;
					acc += ind;
				}
				val = min(val,acc);
			}
			res += val;
		}
		
		cout << res << endl;
	}
}
