#include <iostream>

using namespace std;

int tab[200000];

int main()
{
	int TEST;
	cin>>TEST;
	for(int test = 1; test <= TEST; test++)
	{
		int n, J=0, D=0, maks = 0;
		cin>>n;
		cin>>tab[0];
		for(int i=1; i<n; i++)
		{
			cin >> tab[i];
			maks = max(maks, tab[i-1] - tab[i]);
			if (tab[i] < tab[i-1])
				J = J + tab[i-1] - tab[i];
		}
		for(int i=1; i<n; i++)
		{
			D += min(maks, tab[i-1]);
		}
		cout << "Case #"<<test<<": " << J << " " << D << endl;
	}
}
