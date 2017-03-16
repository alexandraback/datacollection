#include<bits/stdc++.h>

using namespace std;

int pre()
{
	int R,C;
	cin>>R>>C;
	int N;
	cin>>N;
	bool A[R][C];
	int mn = 1000;
	memset(A,false,sizeof A);
	for(int i=0;i<(1<<(R*C));i++)
	{
		int cnt = 0;
		for(int j=0;j<(R*C);j++)
		{
			if((1<<j)&i)
			{
				cnt++;
				int x = j%R;
				int y = (j/R)%C;
				A[x][y] = true;
			}
		}
		if(cnt==N)
		{
			int tmp = 0;
			for(int j=0;j<R;j++)
			for(int k=0;k<C;k++)
			{
				if(k<C-1)
				{
					if(A[j][k+1] == true and A[j][k])
					{
						tmp++;
					}
				}
				if(j<R-1)
				{
					if(A[j+1][k] == true and A[j][k]){
					
						tmp++;
					}
				}
			}
			mn = min(tmp,mn);
		}
		
		memset(A,false,sizeof A);
	}
	return mn;
}

int main()
{
	int T;
	cin>>T;
	
	for(int idx=1;idx<=T;idx++)
	{
		cout<<"Case #"<<idx<<": "<<pre()<<'\n';
	}
}
