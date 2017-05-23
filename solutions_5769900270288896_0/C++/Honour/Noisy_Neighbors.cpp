//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

vector<long long>vec;
long long ar[1000][1000];

long long get(long long curr)
{
    long long ans=0;
    while(curr)
    {
        if(curr%2) ans++;
        curr/=2;
    }
    return ans;
}

int main()
{
    long long i,j,k,l,cas=0,C,N,R,temp,index,T,M,ans,jj,kk;

    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    cin>>T;
    while(T--)
    {
        cas++;

        cin>>R>>C>>N;

        memset(ar,0,sizeof(ar));

        M=1<<(R*C);
        M--;

        ans=1000000;

        for(i=0;i<=M;i++)
        {
            if(get(i)==N)
            {
                vec.clear();
                j=i;
                k=0;
                while(j)
                {
                    vec.push_back(j%2);
                    j/=2;
                    k++;
                }

                for(j=1;j<=R*C-k;j++) vec.push_back(0);

                index=0;

                for(j=1;j<=R;j++)
                {
                    for(k=1;k<=C;k++)
                    {
                        ar[j][k]=vec[index];
                        index++;
                    }
                }

                temp=0;
                for(j=1;j<=R;j++)
                {
                    for(k=1;k<=C;k++)
                    {
                        for(jj=1;jj<=R;jj++)
                        {
                            for(kk=1;kk<=C;kk++)
                            {
                                if(abs(j-jj)+abs(k-kk)==1)
                                {
                                    if(ar[j][k]==1 && ar[jj][kk]==1) temp++;
                                }
                            }
                        }
                    }
                }
                temp/=2;
                ans=min(ans,temp);
                //cout<<i<<" "<<ans<<endl;
            }
        }

        printf("Case #%lld: %lld\n",cas,ans);

    }



}
