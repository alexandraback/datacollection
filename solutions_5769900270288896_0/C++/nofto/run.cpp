#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

vector <vector <int> > generateSubsets(int N){
	vector <vector <int> > ret;
	ret.push_back(vector <int>(0));
	for(int i=0;i<N;i++){
		int act=ret.size();
		for(int j=0;j<act;j++){
			vector <int> subset=ret[j];
			subset.push_back(i);
			ret.push_back(subset);
		}
	}
	return ret;
}

int main()
{
	vector <vector <vector <int> > > subset(17);
	for(int i=0;i<17;i++){
		subset[i]=generateSubsets(i);//cerr << subset[i].size() << endl;
	}
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int R,C,N;
		scanf("%d %d %d\n",&R,&C,&N);
		int best=100000;
		for(int i=0;i<subset[R*C].size();i++) if(subset[R*C][i].size()==N){
			vector <int> tab(R*C,0);
			for(int j=0;j<N;j++) tab[subset[R*C][i][j]]=1;
			int unhep=0;
			for(int r=0;r<R;r++) for(int c=0;c<C-1;c++){
				if(tab[r*C+c]==1 && tab[r*C+c+1]==1) unhep++;
			}		
			for(int r=0;r<R-1;r++) for(int c=0;c<C;c++){
				if(tab[r*C+c]==1 && tab[(r+1)*C+c]==1) unhep++;
			}
			best=min(best,unhep);
		}
		printf("Case #%d: %d\n",t,best);
	}
  return 0;
}
