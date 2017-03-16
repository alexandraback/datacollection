#include <bits/stdc++.h>
using namespace std;

#define f(i,a)  for(int i=0;(i)<(a);++i)
#define fab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define fba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define fit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef char u8;
typedef vector <int> vi;
typedef pair <int, int> pii;

ll pw(ll b,int p, int m){
    ll a=1;
    while(p){
        if(p&1)
            a=(a*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return a;
}

ll gcd(ll a, ll b){
    if(a<b)
        swap(a,b);
    if(!b)
        return a;
    return gcd(b,a%b);
}
bool comp (pair<int,char> i,pair<int,char> j) { return (i.first>j.first); }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T,n,j,x,diff;
    vector<pair<int, char> > A;
    vector<char> B;
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        A.clear();B.clear();
        cin>>n;
        f(i,n){
            cin>>x;
            A.push_back(make_pair(x,'A'+i));
        }
        sort(A.begin(),A.end(), comp);
        diff=A[0].first-A[1].first;
        fab(i,2,n){
            while(A[i].first--)
                B.push_back(A[i].second);
        }
        j=0;
        f(i,diff){
            cout<<A[0].second<<B[j++]<<" ";
        }
        while(j<B.size()){
            cout<<B[j++];
            if(j<B.size())
                cout<<B[j++];
            cout<<" ";
        }
        f(i,A[1].first)
            cout<<A[0].second<<A[1].second<<" ";
        cout<<"\n";
    }
    return 0;
}

