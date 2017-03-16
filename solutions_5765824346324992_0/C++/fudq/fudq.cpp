/*
 * fudq.cpp
 *
 *  Created on: 2015-04-18
 *      Author: bjfudq
 */
#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf2s(a,b) scanf("%s%s",(a),(b))
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a))
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define pfk printf(" ")
#define LL long long

const int N=3010;
const int M=19999997ll;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int dir8[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
const double eps=1e-8;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/

int b,n,f[10],t[10],a[10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
    freopen ("testout.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	sf2(b,n);
    	for(int i=1;i<=b;i++){
    		sf(f[i]);
    		t[i] = f[i];
    	}
    	if(b>=n){
    		pf(n);
    		continue;
    	}
    	int Lcm=1;
    	for(int i=1;i<=b;i++)
    		Lcm=lcm(Lcm,f[i]);
    	int res=0;
    	for(int i=1;i<=b;i++){
    		res += (Lcm/f[i]);
    	}
    	n %= res;
    	if(n == 0)
    		n = res;
		if (b >= n) {
			pf(n);
			continue;
		}
		n -= b;
    	int flag;
    	while(n){
    		int mmin = INF;
    		for(int i=1;i<=b;i++){
    			mmin = Min(mmin,f[i]);
    		}
    		for(int i=1;i<=b;i++){
    			f[i] -= mmin;
    			if(f[i] == 0){
    				n--;
    				if(n == 0){
    					flag = i;
    					break;
    				}
    				f[i] = t[i];
    			}
    		}
    		if(n == 0)
    			break;
    	}
    	pf(flag);
    }
    return 0;
}
