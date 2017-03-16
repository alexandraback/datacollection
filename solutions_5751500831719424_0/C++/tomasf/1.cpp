#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>
#include <climits>
#include <sstream>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod 10
#define B 33
#define MAX 100011
#define eps 1e-7
#define ull unsigned long long

double pi = acos(-1);

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

char aux[101];
int countm[101][101];
int numberOp[101];

int minOp(int totalString, int charN) {
	int min = 1000000;
	for (int i = 0; i < totalString; ++i)
	{
		int total = 0;
		for (int j = 0; j < totalString; ++j)
		{
			if(j!=i) {
				total += abs(countm[i][charN] - countm[j][charN]);
			}
		}
		if(total < min)
			min = total;
	}
	return min;
}

int main() {
	int t;
	vii charcount;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		char curchar;
		charcount.clear();
		cin>>n;

		scanf("%s", aux);
		curchar = aux[0];	
		int count = 1;

		int j=1;
		int totalc = 0;
		while(j < strlen(aux)) {
			if(aux[j] != curchar) {
				charcount.pb(mp(curchar, count));
				countm[0][totalc] = count;
				count = 0;
				totalc++;
			}
			curchar = aux[j];
			count++;
			j++;
		}
		charcount.pb(mp(curchar, count));
		countm[0][totalc] = count;
		totalc++;

		bool ok = true;
		for (int j = 1; j < n; ++j)
	    {
			scanf("%s", aux);
			curchar = aux[0];	
			int count = 1;

			int k=1;
			int totalc = 0;
			while(k < strlen(aux)) {
				if(aux[k] != curchar) {
					if((charcount[totalc]).F != curchar) {
						ok = false;
						break;
					}
					else {
						countm[j][totalc] = count;
//						charcount.pb(mp(curchar, count));
						count = 0;
						totalc++;
					}
				}
				curchar = aux[k];
				count++;
				k++;
			}
			if((charcount[totalc]).F != curchar) {
						ok = false;	
			}
			else {
				countm[j][totalc] = count;
//						charcount.pb(mp(curchar, count));
				count = 0;
				totalc++;
				if(totalc != charcount.size())
					ok = false;
			}
		}

		if(!ok){
			cout<<"Case #"<<i+1<<": "<<"Fegla Won"<<endl;
		}
		else {
			int total = 0;
			for (int j = 0; j < charcount.size(); ++j)
			{
				total += minOp(n, j);
			}
			cout<<"Case #"<<i+1<<": "<<total<<endl;
		}

	}
	return 0;
}