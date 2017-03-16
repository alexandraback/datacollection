#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
   int n,x,cnt[26],mx,k,T;
   cin>>T;
   for (int test=1;test<=T;test++)
   {
       cin>>n;
       memset(cnt,0,sizeof(cnt));
       for (int i=0;i<n;i++)
       {
           cin>>x;
           cnt[i]+=x;
       }
       cout<<"Case #"<<test<<":";
       for (;;)
       {
           mx = 0;
           for (int i=0;i<26;i++) mx = max(mx,cnt[i]);
           if (!mx) break;
           k = 0;
           for (int i=0;i<26;i++)
           {
               if (cnt[i]==mx) k++;
           }
           if (k&1)
           {
              for (int i=0;i<26;i++)
              {
                  if (cnt[i]==mx)
                  {
                    cout<<" "<<(char)(65+i);
                    cnt[i]--;
                    break;
                  }
              }
           }
           else
           {
               for (int i=0;i<26;i++)
               {
                   if (cnt[i]==mx)
                   {
                        for (int j=i+1;j<26;j++)
                        {
                            if (cnt[j]==mx)
                            {
                                cout<<" "<<(char)(65+i)<<(char)(65+j);
                                cnt[j]--;
                                break;
                            }

                        }
                        cnt[i]--;
                        break;
                   }
               }
           }
       }
       cout<<endl;
   }

    return 0;
}
