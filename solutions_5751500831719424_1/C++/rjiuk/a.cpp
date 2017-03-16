#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int t,n;
string Tab[111];

int Rozne[111];
char Jaka[111][111];
int Ile[111][111];

void szukaj(int casee)
{
	FOR(z,0,n)
	{
		string slowo = Tab[z];

		char pop = slowo[0];
		Jaka[z][0]=pop;
		Ile[z][0]=1;
		Rozne[z]=0;

		FOR(i,1,slowo.size())
		{
			if(slowo[i]==pop)
				Ile[z][Rozne[z]]++;
			else
			{
				pop = slowo[i];
				Rozne[z]++;
				Jaka[z][Rozne[z]]=pop;
				Ile[z][Rozne[z]]=1;
			}
		}
	}
	//sprawdzamy czy się w ogole da :
	bool ok = 1;
	
	//czy maja tyle samo roznych
	FOR(i,0,n)
		FOR(j,0,n)
			if(Rozne[i]!=Rozne[j])
				ok=0;
	if(ok==0)
	{
		cout<<"Case #"<<casee<<": Fegla Won\n";
		return;
	}

	//sprawdzamy czy jjesli sa takie same tolitery sie zgadzaja
	FOR(i,0,n)
		FOR(j,i+1,n)
			FOR(k,0,Rozne[i]+1)
				if(Jaka[i][k]!=Jaka[j][k])
					ok=0;
	if(ok==0)
	{
		cout<<"Case #"<<casee<<": Fegla Won\n";
		return;
	}

	//jest ok teraz szukamy ilosc ruchow
	LL all = 0;
	FOR(i,0,Rozne[0]+1)
	{
		//dla kazdej litery szukamy optymalnej liczby
		LL mini = 1000000000;	
		FOR(j,1,101)
		{
			LL akt = 0;
			FOR(k,0,n)
				akt = akt + abs(Ile[k][i]-j);
			mini=min(mini,akt);
		}
		all+=mini;
	}
	cout<<"Case #"<<casee<<": "<<all<<"\n";
}

void dane()
{
	cin>>t;
	FOR(przypadek,0,t)
	{
		cin>>n;
		FOR(i,0,n)
			cin>>Tab[i];
		szukaj(przypadek+1);
	}

}

int main()
{
	dane();
	return 0;
}
