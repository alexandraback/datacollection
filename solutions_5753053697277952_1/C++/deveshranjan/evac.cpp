#include <iostream>
using namespace std;
main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,cnt[30],total=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>cnt[j];
            total+=cnt[j];
        }
        cout<<"Case #"<<i<<": ";
        if(n==2&&cnt[0]==cnt[1])
        {
            while(cnt[0]>0) { cout<<"AB"<<" "; cnt[0]--; }
            cout<<"\n";
            continue;
        }
        while(total>2)
        {
         int maxm=0;
         for(int j=0;j<n;j++)
         {
          if(cnt[maxm]<=cnt[j]) maxm=j;
         }
         cout<<(char)(maxm+65)<<" ";
         cnt[maxm]--;
         total--;
        }
        for(int j=0;j<n;j++)
         {
          if(cnt[j]>0) cout<<(char)(j+65);
         }
        cout<<endl;
    }
    return 0;
}
