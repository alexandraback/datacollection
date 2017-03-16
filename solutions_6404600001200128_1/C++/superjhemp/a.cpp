#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_N 1000

int m[MAX_N];
int N, method1, method2;

void count()
{
	int maxLeap(0);
	method1 = 0;
	method2 = 0;
	
	for (int i=1; i<N; ++i)
		maxLeap = max(maxLeap, m[i-1] - m[i]);
	for (int i=1; i<N; ++i)
	{
		if (m[i] < m[i-1])
			method1 += m[i-1] - m[i];
		method2 += (m[i-1] < maxLeap) ? m[i-1] : maxLeap;
	}
}

void readCase()
{
	cin>>N;
	for (int i=0; i<N; ++i)
		cin>>m[i];
}

int main()
{
	int T;
	cin>>T;
	for (int i=0; i < T; ++i)
	{
		readCase();
		cout<<"Case #"<<i+1<<": ";
		count();
		cout<<method1<<" "<<method2<<endl;
	}
	return 0;
}