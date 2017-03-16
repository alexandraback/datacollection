#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(arr,i) for(vector<pii>::itr i=(arr.begin());i!=(arr.end());++i)
#define pb push_back
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pr pair
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf

#define lowbit(i) (i&(-i))

typedef long long int LL;
typedef pr<int,int> pii;

const int oo=(~0u)>>1;
const LL lloo=(~0ull)>>1;
const int INF = 0x3f3f3f3f;
const double dboo=1e+20;
const double eps=1e-8;
const double pi=3.1414926;

const int maxn = 200;
int N;
char stdstr[maxn];


vector<vector<pii> > data;
char temp[maxn];

void parser()
{
    vector<pii> now;
    int len = strlen(temp + 1);
    int i = 1;
    int cnt = 1;
    while(i <= len - 1)
    {
        if(temp[i+1] != temp[i])
        {
            now.pb(pii(temp[i],cnt));
            cnt = 0;
        }
        cnt ++;
        i ++;
    }
    now.pb(pii(temp[len],cnt));

    data.pb(now);               // 每次生成对串
}
bool same(int a,int b)
{
    if(data[a].size() != data[b].size())
        return 0;
    int len = data[a].size();
    
    vector<pii> &veca = data[a];
    vector<pii> &vecb = data[b];

    ft(i,0,len-1)
        if(veca[i].x != vecb[i].x)
            return false;
    return true;
}
bool right()
{
    ft(i,0,N-2)
    {
        if(!same(i,i+1))
            return 0;
    }
    return 1;
}
int count(int pos)
{
    vector<int> tempnum;
    for (int i = 0; i < N; ++i)
    {
        tempnum.pb(data[i][pos].y);
    }
    srt(tempnum);
    int cho = tempnum[N/2];
    int sum= 0;
    for (int i = 0; i < N; ++i)
    {
        sum += abs(tempnum[i] - cho);
    }
    return sum;
}
int ansit()
{
    int sum = 0 ;
    int len = sz(data[0]);
    for (int i = 0; i < len; ++i)
    {
        sum += count(i);
    }
    return sum;
}
int T;
void clear()
{
    data.clear();

}
int main(int argc, char *argv[])
{
    sf("%d",&T);
    ft(tt,1,T)
    {
        sf("%d",&N);
        ft(i,1,N)
        {
            sf("%s",&temp[1]);
            parser();
        }
        // for (int i = 0; i < N; ++i)
        // {
        //     int len = sz(data[i]);
        //     for (int j = 0 ; j < len; ++j)
        //     {
        //         pf("(%,%d) ",data[i][j].x,data[i][j].y);
        //         puts("");
        //     }
        // }
        if(!right())
        {
            pf("Case #%d: %s\n",tt,"Fegla Won");
        }
        else
        {
            pf("Case #%d: %d\n",tt,ansit());
        }
        clear();
    }

    return 0;
}