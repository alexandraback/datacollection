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

long long tests,b,t[1<<20],l,r,mid,lst,lid;
long long n;
long long ts;
vector<long> v;

long long get(long long T)
{
 long long res=0;
 for (int i=1;i<=b;i++)
 {
  res+=T/t[i]+1;
  if (res>1e16)return res;
 }
 return res;
}

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
 cin>>b>>n;
 for (int i=1;i<=b;i++)
  cin>>t[i];
 
 l=0;
 r=1e15;
 while (l<r)
 {
  long long mid=l+r;
  mid/=2;
  if (get(mid)>=n)r=mid;
  else l=mid+1;
 // cout<<l<<"   "<<r<<" "<<get(l)<<endl;
 }
 lst=-1;
 lid=0;
 for (int i=1;i<=b;i++)
 {
     long long temp=l%t[i];
     temp=l-temp;
     if (temp>lst) 
      lst=temp;
 }
 
 v.clear();
 
 long long ttl=0;
 for (int i=1;i<=b;i++)
 {
  ttl+=lst/t[i];
  if (lst%t[i])ttl++;
  else v.push_back(i);
 }
 
// cout<<b<<"  "<<lst<<" "<<l<<endl;
 n--;
 n-=ttl;
// cout<<"^"<<n<<" "<<v.size()<<" "<<v[0]<<endl;
 ++ts;
 cout<<"Case #"<<ts<<": "<<v[n]<<endl;
}

cin.get();cin.get();
return 0;}
