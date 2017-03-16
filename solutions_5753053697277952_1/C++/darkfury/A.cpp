#include <bits/stdc++.h>


using namespace std;
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define pii pair<int,int>
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define ld long double
#define tr(n) cin>>n
#define tr2(n,m) cin>>n>>m
#define tr3(a,b,c) cin>>a>>b>>c
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vii vector<pii>
#define vii vector<pii>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define Si set<int>
#define SLL set<LL>
#define SpLL set<pLL>
#define Sii set<pii>
#define fill(a,v) memset(a,v,sizeof(a))
#define oo 1000000007
#define MOD 1000000007

#define i64 long long

const i64 MODD=1000000007LL;

i64 poww(i64 x,i64 y,i64 MODD)
{
    if(x==0LL && y==0LL)
    {
        return 1LL;
    }
    i64 ret=1;

    while(y)
    {
        if(y&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        x*=x;
        x%=MODD;
        y>>=1;
    }


    return ret;
}


int t;

//cout << "Case #"

LL n;

LL arr[40];

int main()
{
    cin >>t;
    rep(tt,1,t){
    cin >> n;

    LL tot = 0;
    SpLL S;
    rep( i , 1, n)
    {
        cin >> arr[i];
        tot+=arr[i];
        S.insert(pLL(-arr[i],i));
    }


    cout << "Case #"<<tt<<": ";
    while(1)
    {
        pLL v = *(S.begin());
        if(v.ff == 0)break;
        S.erase(S.begin());
        cout<<(char)('A'-1+v.ss);
        v.ff++;
        tot--;
        pLL v2 = *(S.begin());
        if(-v.ff>tot/2)
        {
            v.ff++;
            tot--;
        }
        else if(-v2.ff>tot/2)
        {
            S.erase(S.begin());
            cout<<(char)('A'-1+v2.ss);
            
            v2.ff++;
            tot--;
            S.insert(v2);
            S.insert(v);
        }
        else
        {
            S.insert(v);
        }
        cout << " ";
    }

    cout <<"\n";
}






    return 0;
}