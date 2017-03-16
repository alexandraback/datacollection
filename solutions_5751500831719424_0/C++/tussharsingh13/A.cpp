#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define pb push_back

int main()
{
freopen ("input.in","r",stdin);
freopen ("output.txt","w",stdout);
int t;
cin>>t;
int test;
FOR(test,1,t+1)
{
int n,check=0,m,l,k,c,tempu,tempo;
cin>>n;
string vect,rec="tusshar",tem;
vector<string> a;
vector<vector<int> > tot;
for(int i=0;i<n;i++)
{
cin>>vect;
a.pb(vect);
tem=vect;
m=tem.size();
vect.erase(unique(vect.begin(),vect.end()),vect.end());
l=vect.size();
k=0;c=0;
if(rec=="tusshar")
{
rec=vect;
tot=vector<vector<int> > (l,vector<int>() );
}
else if(vect!=rec)
{
cout<<"Case #"<<t+1<<": Fegla Won\n";
check = 1;
break;
}
for(int j=0;j<l;j++)
{
while(k<m&&tem[k]==vect[j])
{
k++;c++;
}
if(c>0)
tot[j].pb(c);
c=0;
}
}
if(check)
continue;
long long ans=0;
for(int i=0;i<tot.size();i++)
{
sort(tot[i].begin(),tot[i].end());
if(tot[i].size()>0 && tot[i].size()%2==0)
{
tempu=0,tempo=0;
int cent = tot[i][tot[i].size()/2-1];
for(int j=0;j<tot[i].size();j++)
tempu+=abs(tot[i][j]-cent);
cent = tot[i][tot[i].size()/2];
for(int j=0;j<tot[i].size();j++)
tempo+=abs(tot[i][j]-cent);
ans+=min(tempu,tempo);
}
else if(tot[i].size()>0)
{
int cent = tot[i][tot[i].size()/2];
for(int j=0;j<tot[i].size();j++)
ans+=abs(tot[i][j]-cent);
} 
}
cout<<"Case #"<<test<<": ";
cout<<ans<<endl;

}

return 0;
}
