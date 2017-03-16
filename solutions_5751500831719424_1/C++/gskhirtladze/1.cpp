//gskhirtladze

#include <iostream>
#include <stdio.h>

#define LL long long
#define INF 10000000000LL
#define N 1000010

using namespace std;

string s[3000];
int a[3000],b[3000];
int res,i,t1,t,n;

main()
 {
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  cin>>t;
  for (t1=1;t1<=t;t1++)
   {
     cin>>n;
     for (i=1;i<=n;i++)
      cin>>s[i],a[i]=0;
     bool ans=true;
     res=0;
     while (true)
      {
       int z=0;
       for (i=1;i<=n;i++)
        if (a[i] >= s[i].size()) { z++; ans=false; }
       if (z == n) { ans=true; break; }
       if (!ans) break;
       char c=s[1][a[1]];
       for (i=1;i<=n;i++)
        if (s[i][a[i]] != c) ans=false;
       if (!ans) break;
       for (i=1;i<=n;i++) b[i]=0;
       for (i=1;i<=n;i++)
        { a[i]++; b[i]++; while (a[i] < s[i].size() && s[i][a[i]] == s[i][a[i]-1]) { a[i]++; b[i]++; } }
       sort(b+1,b+n+1);
       int mid=0;
       if (n % 2 == 0)
         mid=(b[n/2]+b[n/2+1])/2; else mid=b[(n+1)/2];
       for (i=1;i<=n;i++)
        res+=abs(b[i]-mid);
     }
     cout<<"Case #"<<t1<<": ";
   if (!ans) cout<<"Fegla Won"<<endl; else
             cout<<res<<endl;
   }
  
 }
