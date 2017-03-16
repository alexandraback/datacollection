//solution by Wsl_F
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define author Wsl_F
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <x86intrin.h>

using namespace std;

typedef long long LL;
typedef double dbl;
typedef vector<int> vi;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)

int numb(string s1, string s2)
{

}


string shrt(string s)
{
    string ans= "";
    ans= s[0];
    for (int i=1; i<s.length(); i++)
        if (s[i]!=s[i-1]) ans+= s[i];
    return ans;
}

int main()
{

 ios_base::sync_with_stdio(0);
 cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 srand(__rdtsc());

 int T;
 cin>>T;

 for (int TT=1; TT<=T; TT++)
 {
     cout<<"Case #"<<TT<<": ";

     int n;
     cin>>n;
     string str[110];

     for (int i=0; i<n; i++)
        cin>> str[i];

     string s= shrt(str[0]);

     bool flag= true;
     for (int i=1; i<n; i++)
       if (shrt(str[i])!=s) { flag= false; break; }

     if (!flag) {cout<<"Fegla Won"<<endl; continue;}

     int ans=0;
     for (int i=0; i<n; i++)
        str[i]+= "#####";
     vi v;
     int ind[110];
     for (int i=0; i<n; i++)
        ind[i]= 0;
     while (str[0][ind[0]]!='#')
     {
         v.clear();
         for (int i=0; i<n; i++)
         {
           int j= ind[i];
           int k= 0;
           while (str[i][j]==str[i][j+1]) { j++; k++; }
           v.pb(k);
           ind[i]= j+1;
         }

         sort(v.begin(),v.end());

         int sum1= 0;
         int sum2= 0;
         int sum3= 0;
         int x1= v[n/2], x2= v[n/2-1];
         v.pb(x2);
         int  x3= v[n/2+1];

         for (int i=0; i<n; i++)
         {
            sum1+= abs(v[i]-x1);
            sum2+= abs(v[i]-x2);
            sum3+= abs(v[i]-x3);
         }

         ans+= min(sum1,min(sum2,sum3));
     }
     cout<<ans<<endl;
 }


 return 0;
}


