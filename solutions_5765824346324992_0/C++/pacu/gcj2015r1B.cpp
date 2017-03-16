#include <iostream>
using namespace std;

long long tot[1000];
int test(int n,int b,long long *a)
{
	for(int i=0;i<b;i++)
		tot[i] = 0;
	int low = 0;
	int per = 1000000001;
	int same;
	for(int i=1;i<n;i++)
	{
		tot[low]++;
		low = 0;
		for(int j=0;j<b;j++)
			if((tot[j]*a[j])<(tot[low]*a[low]))
				low = j;
		for(same=0;same<b;same++)
			if((tot[same]*a[same])!=(tot[0]*a[0]))
				break;
		if(same==b)
		{
			per = i;
			break;
		}
	}
	n--;
	n %= per;
	n++;

	for(int i=0;i<b;i++)
		tot[i] = 0;
	low = 0;
	for(int i=1;i<n;i++)
	{
		tot[low]++;
		low = 0;
		for(int j=0;j<b;j++)
			if((tot[j]*a[j])<(tot[low]*a[low]))
				low = j;
	}
	return low;
}
long long A[1000];
int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	int T,N,B;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> B >> N;
		for(int i=0;i<B;i++)
			cin >> A[i];
		cout << "Case #" << i+1 << ": " << test(N,B,A)+1 << "\n";
	}
}