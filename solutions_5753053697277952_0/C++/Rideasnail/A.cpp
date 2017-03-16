#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sci(x) scanf("%d",&x)
#define scs(x) scanf("%s",&x)

int main(void){
    freopen("D:/Code/A-small-attempt0.in","r",stdin);
    freopen("D:/Code/out.txt","w",stdout);

    int tc;
    sci(tc);

    int partyarr[30];

    FOR(i,tc)
    {
        reset(partyarr,0);
        int party;
        int sum = 0;

        sci(party);
        FOR(ii,party){
            sci(partyarr[ii]);
            sum+= partyarr[ii];
        }
        cout << "Case #" << i+1 << ":";

        while(sum > 0)
        {
            int maxRep = -1;
            int maxRepInd1 = -1;
            int maxRepInd2 = -1;
            bool justOne = true;;


            FOR(ii,party){
                if(partyarr[ii]>maxRep){
                    maxRep = partyarr[ii];
                    maxRepInd2 = -1;
                    maxRepInd1 = ii;
                    justOne = true;
                } else if(partyarr[ii]==maxRep){
                    if(maxRepInd2 >=0){
                        justOne = true;
                    } else {
                        justOne = false;
                    }
                    maxRepInd2 = ii;
                }
            }

            //cout << maxRep << endl;
            //cout << maxRepInd1 << endl;
            //cout << maxRepInd2 << endl;

            if(justOne){
                char ans1 = 'A' + maxRepInd1;
                cout << " " << ans1;
                partyarr[maxRepInd1]--;
                sum--;
            } else {
                cout << " ";
                char ans1 = 'A' + maxRepInd1;
                char ans2 = 'A' + maxRepInd2;
                cout << ans1;
                cout << ans2;
                partyarr[maxRepInd1]--;
                sum--;
                partyarr[maxRepInd2]--;
                sum--;
            }
        }

        cout << endl;

    }


    return 0;
}
