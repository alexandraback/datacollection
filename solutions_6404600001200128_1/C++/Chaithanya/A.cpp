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

int main()
{
    freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int test_cases,Testno;

    long long n,rate,i,sum1,sum2,a[1010],flag;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        cin>>n;
        sum1=sum2=0;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=1;i<n;i++){
            if(a[i-1]>a[i])sum1+=a[i-1]-a[i];
        }
        cout<<sum1<<' ';
        for(rate=0;rate<10010;rate++){
            flag=1;
            for(i=1;i<n;i++)if(a[i-1]-rate>a[i])flag=0;
            if(flag){
                for(i=1;i<n;i++)sum2+=min(rate,a[i-1]);
                cout<<sum2;
                break;
            }

        }

//___________________________________________
        Done: printf("\n");
    }

return 0;
}
