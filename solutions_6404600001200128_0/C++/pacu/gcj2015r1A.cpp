#include <iostream>
#include <fstream>
using namespace std;

int test1(int n,int *a)
{
	int tot = 0;
	for(int i=0;i<(n-1);i++)
		if(a[i] > a[i+1])
			tot += (a[i]-a[i+1]);
	return tot;
}

int test2(int n,int *a)
{
	int high = 0;
	for(int i=0;i<(n-1);i++)
		high = max(high,a[i]-a[i+1]);
	int tot = 0;
	for(int i=0;i<(n-1);i++)
		tot += min(a[i],high);
	return tot;
}

int A[1000];

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	int T,N;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> N;
		for(int j=0;j<N;j++)
			cin >> A[j];
		cout << "Case #" << i+1 << ": " << test1(N,A) << " " << test2(N,A) << endl;
	}
	return 0;
}