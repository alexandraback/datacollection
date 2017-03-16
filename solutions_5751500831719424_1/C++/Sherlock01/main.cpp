#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

const int INF=0x3f3f3f3f;

const int N=200;
const int prime=1000000007;
vector<string>a;
int c[N];
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1; ca<=T; ++ca)
    {
        printf("Case #%d: ",ca);
        int n;
        cin>>n;
        a.clear();
        for(int i=0;i<n;++i)
        {
            string stmp;
            cin>>stmp;
            a.push_back(stmp);
        }

        int ans=0;
        memset(c,0,sizeof(c));
        while(true)
        {
            bool end=false;
            for(int i=0;i<n;++i)
            if(c[i]==a[i].size())
            end=true;
            if(end==true)
            {
                for(int i=0;i<n;++i)
                {
                    for(int j=c[i];j<a[i].size();++j)
                    if(j>0&&a[i][j]==a[i][j-1])
                    {

                    }else
                    {
                        ans=INF;
                        break;
                    }
                }
                if(ans==INF)
                break;
                int S=INF;
                for(int l=0;l<=100;++l)
                {
                    int sum=0;
                    for(int i=0;i<n;++i)
                    {
                        int kk=a[i].size();
                        sum+=abs(kk-c[i]-l);
                    }
                    S=min(S,sum);
                }
                //cout<<ans<<" "<<S<<endl;
                ans+=S;
                break;
            }
            set<char>st;
            int sum=0;
            for(int i=0;i<n;++i)
            {
                if(c[i]>0&&a[i][c[i]]==a[i][c[i]-1])
                ++sum;
                else
                st.insert(a[i][c[i]]);
            }
            if(st.size()>1)
            {
                ans=INF;
                break;
            }
            if(sum==0||sum==n)
            {
                for(int i=0;i<n;++i) ++c[i];

            }else if(sum<=n-sum)
            {
                ans+=sum;
                for(int i=0;i<n;++i)
                {
                    if(c[i]>0&&a[i][c[i]]==a[i][c[i]-1])
                    ++c[i];
                }
            }else
            {
                ans+=(n-sum);
                for(int i=0;i<n;++i)
                {
                    if(c[i]>0&&a[i][c[i]]==a[i][c[i]-1])
                    ++c[i];
                }
            }
        }
        if(ans==INF)
        printf("Fegla Won\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
