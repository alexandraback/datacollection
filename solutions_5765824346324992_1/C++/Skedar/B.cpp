#include <iostream>
#define LL long long

using namespace std;
LL B, N;
LL TAB[2005];
LL iluzaczetych(LL TIME)
{
	LL odp = 0;
	for(int i=0; i<B; i++)
		odp = odp + (TIME/TAB[i])+1;
	return odp;
}
LL ktywolny(LL TIME, LL K)
{
	LL a = 0;
	for(LL i=0; i<B; i++)
	{
		if (TIME%TAB[i] == 0)
			a++;
		if (a==K)
			return (i+1);
	}
	return -1;
}

LL binsearch()
{
	if (N <= B)
		return 0;
	LL zle = 0, dobrze = (long long)1000000000*(long long)1000, s;
	while(zle < dobrze - (long long)1)
	{
		s = (zle + dobrze)/(long long)2;
		if (iluzaczetych(s) >= N)
			dobrze = s;
		else
			zle = s;
	}
	return dobrze;
}

int main()
{
	int TEST;
	cin>>TEST;
	for(int test=1; test<=TEST; test++)
	{
		cin >> B >> N;
		for(int i=0; i < B; i++)
			cin >> TAB[i];
			//cout << "BLA" << endl; //////////////////
		LL K = binsearch();
		//cerr << "K" << K << endl;
		LL odp = N - iluzaczetych(K-1);
		odp = ktywolny(K, odp);
		cout << "CASE #" << test << ": " << odp << endl;
	}
	
}
