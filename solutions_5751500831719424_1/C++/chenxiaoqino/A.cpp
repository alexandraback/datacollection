#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


long long parseln(char s[50],int l)
{
	int i;
	long long ret=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='1')
			ret=ret+(1<<i);
	}
	return ret;
}

int debug=0;

int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	int i,j,n;
	cin>>n;
	char s[105];
	char sc[105];
	int repcnt[105][105];
	memset(repcnt,0,sizeof(repcnt));
	
	cin>>s;
	i=j=0;
	sc[j]=s[i];
	j++;i++;
	while(s[i]>0)
	{
		if(s[i] != s[i-1] )
		{
			sc[j]=s[i];
			j++;
		}
		i++;
	}
	int dlen=j;sc[j]=0;
	
		if(debug) cout<<"distinct sc:"<<sc<<endl;
	
	bool flag=false;
	
	i=0;
	int pt=0;
	j=0;
	while(s[j]>0)
	{
		if(sc[pt]==s[j])
		{
			repcnt[i][pt]++;
		}
		else if(sc[pt+1]==s[j])
		{
			pt++;
			repcnt[i][pt]++;
		}
		else
		{flag=true;break;}
		
		j++;
	}
	
	for(i=1;i<n;i++)
	{
		cin>>s;
		pt=0;
		j=0;
	if(s[0]!=sc[0]){flag=true;}
	else
	while(s[j]>0)
	{
		if(sc[pt]==s[j])
		{
			repcnt[i][pt]++;
		}
		else if(sc[pt+1]==s[j])
		{
			pt++;
			repcnt[i][pt]++;
		}
		else
		{flag=true;break;}
		
		j++;
	}
		
	}

	long ans=0;
	int cal[n];
	for(pt=0;pt<dlen;pt++)
	{
		for(i=0;i<n;i++)
			cal[i]=repcnt[i][pt];
		sort(cal,cal+n);
		if(cal[0]==0)flag=true;
		
		if(debug)
		{
		cout<<"cal i";
		for(i=0;i<n;i++) cout<<cal[i]<<"-";
		cout<<endl;
		}
		
		int mid=cal[n/2];
		for(i=0;i<n;i++)
			ans+=abs(cal[i]-mid);
	}
	
	cout<<"Case #"<<(ti+1)<<": ";
	if(flag)cout<<"Fegla Won";
	else cout<<ans;
	
	cout<<endl;
}
return 0;
}