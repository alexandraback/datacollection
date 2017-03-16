/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int R,C,N;
bool a[16][16];
int ans;
int fn()
{
	int i,j,k=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(!a[i][j])continue;
			if((j+1<C)&&(a[i][j+1]))k++;
			if((i+1<R)&&(a[i+1][j]))k++;
		}
	}
	return k;
}
void fun(int r,int c,int re)
{
	int i,j,k;
	if(c==C)
	{
		fun(r+1,0,re);
		return;
	}
	if(re==0)
	{
		k=fn();
		if(k<ans)ans=k;
		return;
	}
	a[r][c]=true;
	fun(r,c+1,re-1);
	a[r][c]=false;
	if((R-r-1)*C+C-c==re)return;
	fun(r,c+1,re);
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>R>>C>>N;
		for(i=0;i<R;i++)
		for(j=0;j<C;j++)a[i][j]=false;
		ans=1000*R*C;
		fun(0,0,N);
		cout<<ans<<endl;
	}
	return 0;
}
