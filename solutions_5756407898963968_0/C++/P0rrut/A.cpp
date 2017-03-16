#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
const int N = 4;

int t,t2,T;
int tab[N][N];
int tab2[N][N];
int c;
int tn;
int getN(){

	int cnt =0 ;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tab[t][i]==tab2[t2][j]) cnt++,tn=tab[t][i];
		}
	}
	if(cnt>1) return -1;
	return cnt;
}



int main(){

	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		cout << "Case #" << (i+1) <<  ": ";
		scanf("%d",&t);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&tab[i][j]);
			}
		}
		scanf("%d",&t2);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf("%d",&tab2[i][j]);

		t--,t2--;
		if(getN()==-1) cout << "Bad magician!";
		else if(getN()==1) cout << tn;
		else cout << "Volunteer cheated!";
		


		cout << endl;
	}


	return 0;
}
