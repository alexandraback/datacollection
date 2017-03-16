#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
#define LL long long
#define maxn 1005
int n,b;
LL m[maxn];

LL cal(LL times,int pos)
{
	LL res = 0;
	for(int i=1;i<=pos;++i)
	{
		res += times/m[i]+1;
	}
	for(int i=pos+1;i<=b;++i)
	{
		res += (times-1)/m[i]+1;
	}
	return res;
}

bool chk(int id) 
{
	LL l = 0, r = n;
	while(l < r - 1) 
	{
		LL mid = (l + r) >> 1;
		LL t = mid * m[id];
		LL tans = cal(t,id);
		if(tans == n) return true;
		if(tans < n) l = mid;
		else r = mid;
	}
	return false;
}

int main()
{
	int T,cas=1;
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin >> T;
	while(T--)
	{
		fin>>b>>n;
		for(int i=1;i<=b;++i)
		{
			fin>>m[i];
		}

		int res = 0;
		if(n <= b)
			res = n;
		else
		{
			for(int i=1;i<=b;++i)
			{
				if(chk(i))
				{
					res = i;
					break;
				}
			}
		}
		fout<<"Case #"<<cas++<<": "<<res<<endl;
	}
	fout.close();
	fin.close();
	return 0;
}