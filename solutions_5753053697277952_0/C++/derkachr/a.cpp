#include<bits/stdc++.h>
 using namespace std;

 int a[100],t,tt,n,mx,i,s;

  int main()
  {

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      //freopen("input.txt","r",stdin);
      //freopen("output.txt","w",stdout);

    cin>>t;
     for(tt=1;tt<=t;++tt)
     {
        cin>>n;
        s = 0;
         for(i=0;i<n;++i)
         cin>>a[i],s+=a[i];

         cout<<"Case #"<<tt<<":";

         while(s)
         {
         mx = 0;
            for(i=0;i<n;++i)
            if(a[i] > a[mx]) mx = i;
            cout<<' ';

            cout<<char('A' + mx);

            --s;
            --a[mx];
            if(!s) break;

             for(i=0;i<n;++i)
              if(a[i] > s / 2) {
              cout<<char('A' + i);
              --a[i];
              --s;
              break;
              }

         }

         cout<<endl;

     }

    return 0;
  }
