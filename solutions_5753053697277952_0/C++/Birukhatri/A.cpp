#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define LL long long int
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;

///         0123456789
#define MX  400007
#define MOD 1000000007
#define INF 2000000000
#define EPS 1e-9

int a[MX];

bool Ck(int n) {
    int tot=0;
    int mx=0;
    for(int i=0;i<n;i++) tot+=a[i],mx=max(mx,a[i]);

    if(mx>(tot/2)) return 1;
    return 0;

}

int Boro(int n) {
    int boro=0;
    int id=-1;
    for(int i=0;i<n;i++) {
        if(boro<a[i]) {
            boro=a[i];
            id=i;
        }
    }



    return id;
}

int main()
{

    freopen("A.in","r",stdin),freopen("A1.out","w",stdout);

    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++) {
        int n;
        cin>>n;
        vector<string> ans;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        while(true) {
            string s;
            int tp=Boro(n);
            if(tp==-1) break;
            s+=(char)(tp+'A');
            a[tp]--;
            int tp1=Boro(n);
            if(tp1==-1) {
                ans.PB(s);
                break;
            }
            a[tp1]--;
             if(Ck(n)) {
                a[tp1]++;
                ans.PB(s);
                continue;
            }
            s+=(char)(tp1+'A');
            ans.PB(s);
        }

        cout<< "Case #"<<cs<< ":";

        for(int i=0;i<ans.size();i++) {
            cout<< " "<<ans[i];

        }
        cout<<endl;
    }

    return 0;
}
///============= Thank You ===================///
