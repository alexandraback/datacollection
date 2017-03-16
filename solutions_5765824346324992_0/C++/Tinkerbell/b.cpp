/// ///////////////////// ///
///                       ///
///      Tamanna_24       ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>

typedef long long ll;
typedef unsigned long long ull;

#define pi 2.0*acos(0.0)

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T>T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T>T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}
template<class T> T toRad(T deg) { return (deg*pi)/(180.0) ;}
template<class T> T toDeg(T rad) { return (rad*180.0)/(pi) ;}

#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PN() puts("")
#define PCASE() printf("Case %d: ",kk++)
#define eps 1e-9
#define inf 200000000000000000ll
#define mod 1000000007
#define MX  1000000
using namespace std;

ll t,kk=1,b,n,m[1005],i,j,hi,lo,mid,x,y;
vector<pair<ll,ll> >v;

ll check(ll a){
    ll s=0;
    for(ll p=1;p<=b;p++){
        if(a%m[p]) s+=(a/m[p] +1);
        else s+=(a/m[p]);
    }
    return s;
}

int main()
{
    freopen("b.txt","r",stdin);
    freopen("b1.txt","w",stdout);
    cin>>t;
    while(t--){
        cin>>b>>n;
        for(i=1;i<=b;i++)cin>>m[i];

        hi=2000000000000000ll;lo=0;
        ll rr=inf;
        while(hi>=lo){
            mid=(hi+lo)/2;
            j=check(mid);
            //cout<<mid<<" "<<check(mid)<<endl;
            if(j==n-1) break;
            else if(j<n-1) lo=mid+1;
            else {hi=mid-1;rr=min(rr,mid);}
        }
        if(check(mid)<n-1) mid=rr;
        if(check(mid)==n-1){
            x=-1;y=-1;
            for(i=1;i<=b;i++){
                if(mid%m[i]==0) j=mid;
                else j=mid-(mid%m[i])+m[i];
                if(x==-1){x=j;y=i;}
                else if(j<x) {x=j;y=i;}
            }
        }
        else if(check(mid)>=n){
            x=-1;y=-1;
            v.clear();
            for(i=1;i<=b;i++){
                if(mid%m[i]!=0){
                    j=(m[i])*(mid/m[i]);
                    v.pb(make_pair(j,i));
                }
                else{
                    j=(m[i]*(mid/m[i]-1));
                    v.pb(make_pair(j,i));
                }
            }
            sort(v.begin(),v.end());
            i=check(mid);
            j=v.size()-1;
            while(i>=n){
                y=v[j].second;
                j--;
                i--;
            }
        }
        cout<<"Case #"<<kk++<<": "<<y<<endl;
    }

	return 0;
}











