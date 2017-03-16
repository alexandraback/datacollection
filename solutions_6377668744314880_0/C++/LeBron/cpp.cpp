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

struct pt
{
 long x;
 long y;
};

long tests;
long n,a,b;
vector<pt> v;
map<pair<long, long> ,long> mapp;
pt orig;
vector<pt> tv;
long ans;
long r;
long cnt;
long answ[1<<20];
long ts;

pt gp(pt p)
{
 p.x-=orig.x;
 p.y-=orig.y;
 return p;
}

vector<pair<double, double> > ev;

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
    v.clear();
    for (int i=0;i<n;i++)
    {
     cin>>a>>b;
     pt temp;
     mapp[make_pair(a,b)]=i;
     temp.x=a;
     temp.y=b;
     v.push_back(temp);
    }   
    
    for (int centr=0;centr<n;centr++)
    {
        orig=v[centr];
        tv.clear();
        for (int i=0;i<n;i++)
         if (i!=centr)
          tv.push_back(gp(v[i]));
//        sort(tv.begin(),tv.end());
        ev.clear();
        for (int i=0;i<tv.size();i++)
        {
            ev.push_back(make_pair(atan2(tv[i].y,tv[i].x),1));
          //  ev.push_back(make_pair(atan2(tv[i].y,tv[i].x)+M_PI,-1));
        }
        for (int i=0;i<tv.size();i++) 
        {   
            ev.push_back(make_pair(ev[i].first+2*M_PI,1));
            //ev.push_back(make_pair(ev[i*2+1].first+2*M_PI,-1));
        }
        sort(ev.begin(),ev.end());
/*        cout<<"^^^^"<<orig.x<<" "<<orig.y<<endl;
        for (int i=0;i<ev.size();i++)
         cout<<"^"<<ev[i].first<<" "<<ev[i].second<<endl;
  */       
        ans=1e9;
        r=0;
        long cnt=0;
        for (int i=0;i<tv.size();i++)
        {
//         if (ev[i]>2*M_PI)break;
         while (ev[r].first<ev[i].first+M_PI-1e-9)
         {
          cnt+=ev[r].second;
          r++;
         }
         cnt-=ev[i].second;
         ans=min(ans,cnt);
//         cout<<"^^"<<i<<" "<<r<<" "<<cnt<<endl;
        }
        if (ans>1e6)ans=0;
        answ[mapp[make_pair(v[centr].x,v[centr].y)]]=ans;
    }
    ++ts;
    cout<<"Case #"<<ts<<":"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<answ[i]<<endl;
    }
}

cin.get();cin.get();
return 0;}
