#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_B 1000

int barber[MAX_B];
long long int B, N;

long long int served(long long int time)
{
	long long int nClients(0);
	for (int i=0; i<B; ++i)
		nClients += (time / barber[i]) + 1;
	return nClients;
}

int barberID()
{
	long long int l(0), r(1ll<<50), x;
	
	while (l < r)
	{
		x = (l+r) / 2;
		//cout<<l<<" "<<r<<" "<<x<<" : "<<served(x)<<endl;
		served(x) < N ? l = x + 1 : r = x;
	}
	//cout<<N<<" "<<served(x)<<" - "<<served(x+1)<<endl;
	//cout<<x<<endl;
	while (served(x-1) >= N) --x;
	//cout<<x<<endl;
	while (served(x) < N) ++x;
	//cout<<x<<endl;
	N -= served(x-1);
	//cout<<x<<" "<<N<<endl;
	
	for (int i=0; i<B; ++i)
	{
		if (x % barber[i] == 0)
		{
			if (N == 1)
				return i+1;
			else
				--N;
		}		
	}
			
	return -1;
}

void readCase()
{
	cin>>B>>N;
	for (int i=0; i<B; ++i)
		cin>>barber[i];
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		cout<<"Case #"<<i+1<<": "<<barberID()<<endl;
	}
	return 0;
}