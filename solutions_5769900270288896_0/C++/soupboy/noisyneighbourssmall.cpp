#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <string.h>
 
#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)  v.begin(),v.end()
#define np next_permutation
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VF vector<float>
#define SI set<int>
#define SC set<char>
#define SS set<string>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MIC map<int,char>
#define MCI map<char,int>
#define LL long long
using namespace std;
	
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
 
int main()
{
	int test;
	cin>>test;
	repx(tc,1,test+1)
	{
		int r,c,n;
		cin>>r>>c>>n;
		int total = (1<<(r*c));
		int ret = INT_MAX;
		rep(i,total)
		{
			if(__builtin_popcount(i) != n)
				continue;
			
			bool occ[17][17]={0};
			VI ocl;
			int unhappy =0;
			rep(j,r*c)
			{
				if(i&(1<<j))
				{
					ocl.pb(j);

					int nr = j/c;
					int nc = j % c;
					occ[nr][nc]=true;

					
				}
			}
			rep(i,ocl.size())
			{
				int num = ocl[i];
				int nr = num/c;
				int nc = num % c;
				
				rep(k,4)
				{
					int tr = nr + dr[k];
					int tc = nc + dc[k];



					if(tr < r && tr>=0 && tc<c && tc>=0 && occ[tr][tc])
						{
							unhappy++;
						}
				}
				occ[nr][nc]=false;
			}
			ret = min(ret,unhappy);
		}
		cout<<"Case #"<<tc<<": "<<ret<<"\n";
	}
	 return 0;
}