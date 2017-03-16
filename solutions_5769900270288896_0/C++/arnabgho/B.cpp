#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int A[20][20];

void init(){
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j <20 ; ++j)
		{
			A[i][j]=0;
		}
	}
}
bool getBit(int n,int i){
	return (n>>i & 1)!=0;
}
int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int R,C,N,mn;
		mn=1e9;
		cin>>R>>C>>N;
		for (int mask = 0; mask < 1LL<<R*C ; ++mask)
		{
			init();
			int numBits=0;
			for (int r = 0; r < R ; ++r)
			{
				for (int c = 0; c <C ; ++c)
				{
					if(getBit(mask,r*C+c)){
						A[r][c]=1;
						numBits++;
					}
				}
			}
			if(numBits!=N)
				continue;
			int val=0;
			for (int i = 0; i < R; ++i)
			{
				for (int j = 0; j <C ; ++j)
				{
					if(A[i][j]==1){
						if(A[i+1][j]==1) val++;
						if(A[i][j+1]==1) val++;
					}
				}
			}
			mn=min(mn,val);
		}
		cout<<"Case #"<<cas<<": "<<mn<<endl;
	}
	return 0;
}