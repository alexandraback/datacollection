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
#include <complex>
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


struct point
{
    double x,y;
};
point convex[50];

double cross(const point &p1, const point &p2, const point &q1, const point &q2)
{
    return (q2.y - q1.y)*(p2.x - p1.x) - (q2.x - q1.x)*(p2.y - p1.y);
}

bool judge(vector<point> p)
{
    point origin;
    origin.x = origin.y = 0;

    for(int i = 0; i< p.size(); i++)
    {
        vector<int> t;
        for(int j = 0; j<p.size(); j++)
        {
            if(j !=i)
            {
                if(cross(origin, p[i], origin, p[j]) < 0) t.push_back(-1);
                else if(cross(origin, p[i], origin, p[j])> 0) t.push_back(+1);
            }
        }
        sort(t.begin(), t.end());
        if(t[0] != t[t.size()-1]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
//    freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    for(int cas = 1; cas<= T; cas++)
    {
        int N;
        cin>>N;
        for(int i = 0; i<N; i++)
        {
//            double a, b;cin>>a>>b;
            point p;
            cin>>p.x>>p.y;
            convex[i] = p;
        }
        vector<int > ret;
        for(int t = 0; t< N; t++)
        {
            point origin = convex[t];
            int ans = N-1;
            for(int i = 0; i< N; i++)
            {
                int pos = 0;
                int neg = 0;
                int zero = 0;
                if(i ==t ) continue;
                for(int j = 0; j<N; j++)
                {
                    if(j !=i && j!=t)
                    {
                        double x = cross(origin, convex[i], origin, convex[j]);
                        if( x < 0.0) neg++;
                        else if(x> 0.0) pos++;
                        else zero++;
                    }
                }
//                cout<<pos<<" "<<neg<<" "<<zero<<endl;
                ans = min(ans, min(pos, neg));

//        sort(t.begin(), t.end());
//        if(t[0] != t[t.size()-1]) return false;
            }
            ret.push_back(ans);
        }
        cout<<"Case #"<<cas<<":"<<endl;
        for(int i=0; i<N; i++) cout<<ret[i]<<endl;
//        for(int cs = 1; cs <= (1<<15)
//        for(int i = 0; i<N;i++) cout<<arg(point[i])<<endl;
    }

    return 0;
}
