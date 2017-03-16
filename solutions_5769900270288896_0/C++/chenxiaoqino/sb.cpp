#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int R,C;
const int N=18;
bool occ[N][N];

void init()
{
	memset(occ,0,sizeof(occ));
	//for(int i=0;i<N;i++)for(int j=0;j<N;j++)occ[i][j]=false;
	//for(int i=0;i<R;i++)for(int j=0;j<C;j++)occ[i][j]=true;
}
int calc_unhappiness()
{
	int u=0;
	
	for(int i=0;i<R;i++)
	for(int j=0;j<C-1;j++)
		if(occ[i][j] && occ[i][j+1])u++;
		
	
	for(int i=0;i<R-1;i++)
	for(int j=0;j<C;j++)
		if(occ[i][j] && occ[i+1][j])u++;
	
	return u;
}

int xs[18],ys[18],id[18];
int minu;
void search(int pos,int remain)
{
	if(remain==0)
	{
		int hap=calc_unhappiness();
		minu=min(minu,hap);
		return;
	}
	if(pos+remain>R*C || pos>=R*C)return;
	int x=xs[pos],y=ys[pos];
	occ[x][y]=1;
	search(pos+1,remain-1);
	occ[x][y]=0;
	search(pos+1,remain);
 }
int calc()
{
	int n;
	cin>>R>>C>>n;
	if(n==0)return 0;
	
	int p=0;
	for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)
	{
		xs[p]=i;ys[p]=j;
		id[p]=p;
		p++;
	}			
	 minu=R*C*2;
	/*do
	{
		init();
		for(int i=0;i<n;i++)
			occ[xs[id[i]]][ys[id[i]]]=1;
		minu=min(minu,calc_unhappiness());
	}
	while(next_permutation(id,id+R*C));*/
	search(0,n);
	return minu;
}

int main()
{
	
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}