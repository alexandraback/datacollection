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
     string s1,s2;
     cin>>s1>>s2;

     string s= shrt(s1);

     if (shrt(s2)!=s) { cout<<"Fegla Won"<<endl; continue; }

     int k1,k2;
     k1= 0; k2= 0;
     int ans=0;
         int i1= 0;
         int i2= 0;
     s1+= "######"; s2+= "######";
     while (s1[i1]!='#')
     {
         k1= 0; k2= 0;
         while (s1[i1]==s1[i1+1]) { i1++; k1++; }
         while (s2[i2]==s2[i2+1]) { i2++; k2++; }
         ans+= abs(k1-k2);
         i1++; i2++;
     }
     cout<<ans<<endl;
 }


 return 0;
}


