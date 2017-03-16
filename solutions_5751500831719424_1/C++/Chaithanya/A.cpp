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
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test_cases,Testno;
    int flag,sum,step,n,i,k,totch,ch,cnt,avg;
    int ind[1000],tot[1000];
    char s[500][500],a[1000],val;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________
        flag=0;sum=0;step=0;
        cin>>n;
        for(i=0;i<n;i++)scanf("%s",s[i]);
        val=s[0][0];
        k=0;
        for(i=0;s[0][i];)
        {
            while(s[0][i] && s[0][i]==val)i++;
            a[k++]=val;
            val=s[0][i];
        }
        totch=k;//cout<<totch<<' ';
        init(ind,0);
        for(ch=0;ch<totch;ch++)
        {
            //cout<<a[ch];
            sum=0;
            for(i=0;i<n;i++)
            {
                cnt=0;
                while(s[i][ind[i]] && s[i][ind[i]]==a[ch]){ind[i]++;cnt++;}
                tot[i]=cnt;
            }
            for(i=0;i<n;i++)
            {
                if(!tot[i]){printf("Fegla Won");goto Done;}
                sum+=tot[i];
                //cout<<tot[i]<<' ';
            }

            avg=(2*sum+1)/(2*n);
            //cout<<avg<<' ';cout<<'\n';
            for(i=0;i<n;i++)step+=abs(avg-tot[i]);
        }
        for(i=0;i<n;i++)if(s[i][ind[i]]!=0){printf("Fegla Won");goto Done;}
        cout<<step;
//___________________________________________
        Done: printf("\n");
    }

return 0;
}
