#include <iostream>
#include <cmath>
using namespace std;

long long x[3000];
long long y[3000];
int N;
int ans[3000];

void test()
{
	int cbel,cab;
	if(N==1)
	{
		ans[0] = 0;
		return;
	}
	for(int i=0;i<N;i++)
	{
		ans[i] = N;
		for(int j=0;j<N;j++)
		{
			if(j==i) continue;
			cbel = cab = 0;
			for(int k=0;k<N;k++)
			{
				if(((y[k]-y[i])*(x[j]-x[i]))<((x[k]-x[i])*(y[j]-y[i])))
					cbel++;
				else if(((y[k]-y[i])*(x[j]-x[i]))>((x[k]-x[i])*(y[j]-y[i])))
					cab++;
			}
			ans[i] = min(ans[i],min(cbel,cab));
		}
	}
}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> N;
		for(int j=0;j<N;j++)
			cin >> x[j] >> y[j];
		test();
		cout << "Case #" << i+1 << ":\n";
		for(int j=0;j<N;j++)
			cout << ans[j] << "\n";
	}
}