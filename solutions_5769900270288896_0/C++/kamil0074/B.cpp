#include<iostream>
#include<queue>
#include<map>
#include<climits>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

bool A[20][20];

int main()
{

	int z;
	cin>>z;
	for(int v=0;v<z;v++)
	{
		int R,C,k;
		cin>>R>>C;
		cin>>k;
		int wynik=INT_MAX;
		for(int mask=0;mask<(1<<(R*C));mask++)
		{
			int ludki=0;
			for(int i=0;i<30;i++)
			{
				if(mask&(1<<i))
				ludki++;
			}
			if(ludki!=k)
			continue;
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
					if(mask&(1<<(i*C+j)))
						A[i][j]=true;
			int licz=0;
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
				{
					if(A[i][j]&&A[i+1][j])
					{
						licz++;
					}
					if(A[i][j]&&A[i][j+1])
					{
						licz++;
					}
				}
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
				{
					A[i][j]=false;
				}
			wynik=min(wynik,licz);
		}
		cout<<"Case #"<<v+1<<": "<<wynik<<endl;
	}

}

