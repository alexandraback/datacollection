//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL
long long a[1010],n;

long long check(long long mid){
    long long countt=0,i;
    for(i=0;i<n;i++)countt+=(mid+a[i]-1)/a[i];
    return countt;
}

int main()
{
    freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int test_cases,Testno;
    long long i,low,high,don,nump,mid,ct;
    vector<pair<long long, long long> > v;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        cin>>n>>ct;
        for(i=0;i<n;i++)cin>>a[i];
        v.clear();
        //cout<<'*';
        low=0;high=1ll<<55;
        while(low+1<high){
            mid=(low+high)/2;
            if(check(mid)>=(ct))high=mid;
            else low=mid;
        }
        //cout<<'*';
        nump=check(low);
        for(i=0;i<n;i++){
            don=low/a[i];
            v.push_back(mp(low-don*a[i],i));
        }
        sort(all(v));
        //cout<<nump<<' '<<low<<' '<<high<<' '<<check(high);
        cout<<v[ct-nump-1].S+1;
//___________________________________________
        Done: printf("\n");
    }

return 0;
}
