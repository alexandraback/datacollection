/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define move adsfasdfasd

#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long tests,n,ar[1<<20],ts,mx,s,s1;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n;
 for (int i=0;i<n;i++)
  cin>>ar[i];
 ++ts;
 mx=0;
 for (int i=1;i<n;i++)
  mx=max(ar[i-1]-ar[i],mx);
 s=0;
 s1=0;
 for (int i=1;i<n;i++)
 {
     if (ar[i]<ar[i-1])s+=ar[i-1]-ar[i];
     if (ar[i-1]<mx)
      s1+=ar[i-1];
      else s1+=mx;
 }
 cout<<"Case #"<<ts<<": "<<s<<" "<<s1<<endl;
 
}
cin.get();cin.get();
return 0;}
