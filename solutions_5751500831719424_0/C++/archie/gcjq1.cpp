#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("op1.txt","w",stdout);
    int t;
    cin>>t;
    int q=0;
    while(t--)
    {
        q++;
        ll int n,i,j,cnt=0,flag=0,k;
        cin>>n;
        string s[n],s1[n];
        char zx;
        for(i=0;i<n;i++)
            cin>>s[i];
        vector<ll int> v[n],v1;
        for(i=0;i<n;i++)
        {
            //cout<<"hi\n";
            for(j=0;j<s[i].length();j++)
            {
                zx=s[i][j];
                cnt=0;
                //cout<<"hi1\n";
                while(s[i][j]==zx&&j<s[i].length())
                {
                    cnt++;
                    j++;
                }
                j--;
                s1[i]+=zx;
                v[i].pb(cnt);
            }
        }
        ll int len=s1[0].length();
        for(i=0;i<n;i++)
        {
            if(s1[i].length()!=len)
                flag=1;
        }
        if(flag==1)
        {
            printf("Case #%d: Fegla Won\n",q);
            continue;
        }
        for(i=0;i<len;i++)
        {
            zx=s1[0][i];
            for(j=0;j<n;j++)
            {
                if(s1[j][i]!=zx){
                    flag=1;
                    goto ab;
                }
            }
        }
        ab:
        if(flag==1)
        {
            printf("Case #%d: Fegla Won\n",q);
            continue;
        }
        long long int pen=0,p1,min1=INT_MAX,pen1=0;
        for(i=0;i<len;i++)
        {
            min1=INT_MAX;
            for(j=0;j<n;j++)
            {
                v1.pb(v[j][i]);
            }
            for(k=0;k<101;k++)
            {
                pen=0;

                for(j=0;j<v1.size();j++)
                    pen+=abs(v1[j]-k);
                if(pen<min1)
                    min1=pen;
            }
            pen1+=min1;
            v1.clear();
        }
        printf("Case #%d: %lld\n",q,pen1);
    }
return 0;
}
