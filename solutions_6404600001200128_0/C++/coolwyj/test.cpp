#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
#define LL long long
#define maxn 10005
template <class T>
T SQR(T x) {return x*x;}

int food[maxn];

int main()
{
	int T,cas=1;
	int n;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin >> T;
	//scanf("%d",&T);
	while(T--)
	{
		fin>>n;
		//scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			fin>>food[i];
			//scanf("%d",&food[i]);
		}
		int sum1 = 0;
		int sum2 = 0;
		for(int i=2;i<=n;++i)
		{
			if(food[i] < food[i-1])
				sum1 += -food[i] + food[i-1];
		}
		int tmp = 0;
		for(int i=1;i<n;++i)
		{
			tmp = max(tmp,food[i] - food[i+1]);
		}
		for(int i=1;i<n;++i)
		{
			if(tmp > food[i])
				sum2 += food[i];
			else
				sum2 += tmp;
		}
		fout<<"Case #"<<cas++<<": "<<sum1<<" "<<sum2<<endl;
		//printf("Case #%d: %d %d\n",cas++,sum1,sum2);
	}
	fout.close();
	fin.close();
	return 0;
}