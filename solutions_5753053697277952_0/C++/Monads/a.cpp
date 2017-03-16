#include<bits/stdc++.h>
#define rep(i,s,t) for (ll i=(s); i<=(t); ++i)
#define dep(i,t,s) for (ll i=(t); i>=(s); --i)
#define i first
#define j second
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define sz(x) ll((x).size())
#define p(i) (1LL<<((i)-1))
#define w(x,i) ((x)&p(i))
#define inf ll(~0u>>1)

using namespace std ;

typedef long long ll;

ll n,sum;
multimap<ll,char> mpp ;

template<class T>
inline void get(T &n) {
	char c = getchar();
	while (c!='-' && (c<'0' || c>'9')) c = getchar();
	n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
	while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
	n *= s;
}

int main() {
	ll Test,i,j,k,t,tt;
    get(Test);
    rep(Ti,1,Test) {
        printf("Case #%lld:",Ti);
        mpp.clear();
        get(n);
        sum = 0 ;
        rep(i,0,n-1) {
            get(tt);
            sum += tt ;
            mpp.insert( {-tt , i+'A'} ) ;
        }

        while ( mpp.size() >= 4 || (mpp.size() == 3 && -mpp.begin() -> i >= 2) ) {
            char w1 , w2 ;
            ll a1 , a2 ;

            a1 = -mpp.begin() -> i;
            w1 = mpp.begin() -> j ;
            mpp.erase(mpp.begin()) ;

            --a1;
            if (a1 != 0) mpp.insert( {-a1,w1} ) ;

            a2 = -mpp.begin() -> i ;
            w2 = mpp.begin() -> j ;
            mpp.erase(mpp.begin()) ;

            --a2;
            if ( a2 != 0 ) mpp.insert( {-a2,w2} ) ;

            printf(" %c%c",w1,w2);
            sum -= 2 ;
        }
        //for (auto x:mpp) cout << x.first << " " << x.j << endl;

        while ( mpp.size() == 2 ) {
            char w1 , w2 ;
            ll a1 , a2 ;

            a1 = -mpp.begin() -> i ;
            w1 = mpp.begin() -> j ;
            mpp.erase(mpp.begin()) ;

            --a1;
            if ( a1 != 0 ) mpp.insert( {-a1,w1} ) ;
            //for (auto x:mpp) cout << x.first << " " << x.j << endl;

            a2 = -mpp.begin() -> i ;
            w2 = mpp.begin() -> j ;
            mpp.erase(mpp.begin()) ;

            --a2;
            if ( a2 != 0 ) mpp.insert( {-a2,w2} ) ;

            printf(" %c%c",w1,w2);
            sum -= 2 ;
        }
        if ( mpp.size() == 3 ) {
            vector<char> c;
            rep(i,1,3) {
                c.push_back(mpp.begin() -> j);
                mpp.erase(mpp.begin());
            }
            printf(" %c %c%c",c[0],c[1],c[2]);
        }
        puts("");
    }
}
