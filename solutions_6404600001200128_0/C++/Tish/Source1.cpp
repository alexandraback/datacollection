#include <iostream>
using namespace std;


int calc(long long x, int a[],int b,int n)
{
	int i;
	long long res1=0;
	long long res2=0;
	long long minind=-1;
	for (i=0;i<b;++i)
	{
		res1+=(x+a[i]-1)/a[i];
		if (((x/a[i])*a[i])==x)
		{
			if (minind==-1)
				minind=i;
			res2+=1;
		}
	}
	if ((res1+res2)<n)
		return -1;
	if (res1>=n)
		return -2;
	int count=0;
	for (i=0;i<b;++i)
	{
		if (((x/a[i])*a[i])==x)
		{
			count++;
		}
		if (count==(n-res1))
			return i+1;
	}
	return 0;
}


void q2(int num)
{
	int n,b;
	cin >> b >> n ;
	int a[1000];
	int i;
	for (i=0;i<b;++i)
		cin>>a[i];
	long long x=1;
	int res=calc(x,a,b,n);
	while(res==-1)
	{
		x*=2;
		res=calc(x,a,b,n);
	}
	long long down=x/2;
	long long up=x;
	while (res<0)
	{
		x=(down+up)/2;
		res=calc(x,a,b,n);
		if (res==-1)
			down=x+1;
		if(res==-2)
			up=x-1;


	}
	cout <<"Case #"<<num <<": " << res << endl;
	return;

	
}



void q1(int num)
{
	int n;
	int i;
	cin >> n;
	int a[1000];
	for (i=0; i<n;++i)
		cin >>a[i];
	int res1=0;
	int maxgap=0;
	for (i=1;i<n;++i)
	{
		if (a[i]<a[i-1])
		{
			if ((a[i-1]-a[i])>maxgap)
				maxgap=a[i-1]-a[i];
			res1+=(a[i-1]-a[i]);
		}

	}
	int res2=0;
	for (i=0;i<(n-1);++i)
	{
		if (a[i]>=maxgap)
			res2+=maxgap;
		else
			res2+=a[i];
	}

		cout <<"Case #"<<num <<": " << res1 << " " << res2 << endl;
		return;
	
}
int main()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
		q1(i+1);
}