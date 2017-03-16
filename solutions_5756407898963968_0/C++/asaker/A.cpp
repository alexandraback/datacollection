#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
#define REP(i,N) for(int i=0;i<N;i++)
int pattern[3][6][6];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	cin>>T;
	REP(t,T)
	{
		int A[3];
		REP(k,2)
		{
		  cin>>A[k];
		  A[k]--;
		  REP(i,4)
		  {
		  	REP(j,4)
		  	{
		  		cin>>pattern[k][i][j];
		  	}
		  }
		}
		vector<int> common;
		REP(i,4)
		{
		    REP(j,4)
		    {
		    	//printf("---->%d %d \n",pattern[0][A[0]][i],pattern[1][A[1]][j]);
				if(pattern[0][A[0]][i]==pattern[1][A[1]][j])
		    	common.push_back(pattern[0][A[0]][i]);
		    }
		}
		/*REP(i,common.size())
		cout<<common[i]<<endl;*/
		printf("Case #%d: ",t+1);
		if(common.empty())
		cout<<"Volunteer cheated!\n";
		else
		if(common.size()>1)
		cout<<"Bad magician!\n";
		else
		cout<<common[0]<<endl;
	}
	return 0;
}
