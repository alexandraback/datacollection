#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

int main()
{
        freopen ("A-small-attempt1.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
               int arr[17]={0};
               int row;
               cin>>row;
               for(int i=0;i<4;i++)
               {
                        for(int j=0;j<4;j++)
                        {
                                int temp;
                                cin>>temp;
                                if(i==row-1)
                                {
                                        arr[temp]++;
                                }
                        }
               }
               
               cin>>row;
               for(int i=0;i<4;i++)
               {
                        for(int j=0;j<4;j++)
                        {
                                int temp;
                                cin>>temp;
                                if(i==row-1)
                                {
                                        arr[temp]++;
                                }
                        }
               }
               
               int flag=0;
               int ans=-1;
               for(int i=1;i<=16;i++)
               {
                        if(arr[i]==2&&flag==0)
                        {
                                ans=i;
                                flag=1;
                        }
                        else if(arr[i]==2&&flag==1)
                        {
                                flag=2;
                        }
               }
               if(flag==0)
               {
                        cout<<"Case #"<<test<<": Volunteer cheated!\n";
               } 
               else if(flag==1)
               {
                        cout<<"Case #"<<test<<": "<<ans<<"\n";
               }
               else if(flag==2)
               {
                        cout<<"Case #"<<test<<": Bad magician!\n";

               }
        }
        return 0;
}
