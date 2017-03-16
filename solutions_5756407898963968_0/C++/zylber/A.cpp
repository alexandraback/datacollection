#include <iostream>
#include <cstdio>
using namespace std;

int cand[20];

void tablero(int r)
{
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
		{
			int a;
			cin >> a;
			if(i!=r) cand[a]=0;
		}
}

int main()
{
	freopen("A2.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++)
	{
		for(int i=1; i<=16; i++) cand[i]=1;
		
		int r1;
		cin >> r1;
		tablero(r1);
		cin >> r1;
		tablero(r1);
		
		int cant=0, last=0;
		for(int i=1; i<=16; i++) if(cand[i]==1)
		{
			cant++;
			last=i;
		}
		
		cout << "Case #" << tc << ": ";
		if(cant==0) cout << "Volunteer cheated!";
		if(cant==1) cout << last;
		if(cant>1) cout << "Bad magician!";
		cout << endl;
	}
}
