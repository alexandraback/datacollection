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
int N,a[26][2];
int Qsort(int left,int right)
{
	int i,j;

	int tmp,mid;

	i=left;
	j=right;
	mid=a[(left+right)/2][1];
	do
	{
		while(a[i][1]<mid)
		i++;
		while(mid<a[j][1])
		j--;
		if(i<=j)
		{
			tmp=a[i][0];
			a[i][0]=a[j][0];
			a[j][0]=tmp;
			tmp=a[i][1];
			a[i][1]=a[j][1];
			a[j][1]=tmp;
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j)
	Qsort(left,j);
	if(i<right)
	Qsort(i,right);
}
char fn(int k)
{
	return 'A'+k;
}
int main()
{
	int t,i,j,k,cs,css;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>N;
		for(i=0;i<N;i++)
		{
			cin>>a[i][1];
			a[i][0]=i;
		}
		cout<<"Case #"<<cs<<": ";
		Qsort(0,N-1);
		for(i=N-1;i>=0;i--)
		{
			while(a[N-1][1]!=a[i][1])
			{
				for(j=N-1;j>i;j--)
				{
					cout<<fn(a[j][0])<<" ";
					a[j][1]--;
				}
			}
		}
		if(N==2)
		{
			for(i=0;i<a[0][1];i++)cout<<"AB ";
		}
		else
		{
			for(i=0;i<a[0][1]-1;i++)
			{
				for(j=0;j<N;j++)cout<<fn(j)<<" ";
			}
			if(N%2==1)
			{
				cout<<"A ";
				for(j=1;j<N;j+=2)cout<<fn(j)<<fn(j+1)<<" ";
			}
			else
			{
				for(j=0;j<N;j+=2)cout<<fn(j)<<fn(j+1)<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
