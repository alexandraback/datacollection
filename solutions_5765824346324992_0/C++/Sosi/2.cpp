#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
using namespace std;

template<class T> T gcd(T a,T b)
{
    if(a<0) return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template <class T> T lcm(T a,T b)
{
    return a*(b/gcd(a,b));
}
template<class T> inline vector<pair<T,int> > factorize(T n)
{
    vector<pair<T,int> > R;
    for (T i=2; n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for (; n%i==0; C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) i=n;
    }
    if (n>1) R.push_back(make_pair(n,1));
    return R;
}
template<class T> inline bool isPrimeNumber(T n)
{
    if(n<=1)return false;
    for (T i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}
template<class T> inline T eularFunction(T n)
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for (int i=0; i<R.size(); i++)r=r/R[i].first*(R[i].first-1);
    return r;
}
template<class T> string toString(T n)
{
    ostringstream ost;
    ost<<n;
    ost.flush();
    return ost.str();
}
int toInt(string s)
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int i,j,k;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int dirx[]= {1, 1, 0,-1,-1,-1,0,1};
int diry[]= {0,-1,-1,-1, 0, 1,1,1}; //clockwise

vector<long long> X;
// t 时刻已经剪完的人数
long long judge(long long t)
{
    long long ret = 0LL;
    for(int i = 0; i< X.size(); i++)
    {
        ret += t/X[i];
    }
    return ret;
}
long long being(long long t)
{
    long long ret = 0LL;
    for(int i = 0; i< X.size(); i++)
    {
        if(t%X[i] == 0) ret++;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
//    freopen("1.txt","r",stdin);
    int T; cin>>T;
    for(int cas = 1; cas<= T; cas++)
    {
        int B; long long N;
        cin>>B>>N;
        X.resize(B);
        for(int i = 0; i< B; i++) cin>>X[i];

        long long lowt = 0LL;
        long long hight = N*X[0];
        long long ret = 0LL;
        while(lowt < hight)
        {
//            cout<<lowt <<" --> "<<hight<<endl;
            long long mid = (lowt + hight)/2;
//            cout<<" mid "<<mid<<endl;
            if(judge(mid) + B < N )
            {
                lowt = mid+1;
            }else if(judge(mid) + B - being(mid)>=N )
            {
                hight = mid;
            }else{
                ret = mid;
                break;
//                bool flag = 0;
//                for(int i = 0; i< B; i++)
//                {
//                    if(mid% X[i] ==0)
//                    {
//                        flag = 1;
//                    }
//                }
//                if(flag)
//                {
//                    ret = mid;
//                    break;
//                }else hight = mid;
            }
        }
//        cout<<"ret "<<ret<<endl;
//        int ans= -1;
        vector<int> ans;
        for(int i = 0; i< B; i++)
        {
            if(ret%X[i] == 0LL)
            {
                ans.push_back(i+1);
//                break;
            }
        }

        cout<<"Case #"<<cas<<": "<<ans[N - judge(ret) - (B - being(ret)) -1]<<endl;
    }

    return 0;
}
