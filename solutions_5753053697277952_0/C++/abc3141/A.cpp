#include<bits/stdc++.h>
using namespace std;
int T;
int N;
int P[30];
string S="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d",&P[i]);
		}
		int L1=-1,L2=-1;
		int L1i=-1,L2i=-1;
		for(int i=0;i<N;i++){
			if(L1<P[i]){
				L2=L1;L2i=L1i;
				L1=P[i];L1i=i;
			}
			else if(L2<P[i]){
				L2=P[i];L2i=i;
			}
		}
		printf("Case #%d:",cas+1);
		while(L1!=L2){
			cout << " " << S[L1i] ;
			L1--;
		}
		for(int i=0;i<N;i++){
			if(L1i==i)continue;
			if(L2i==i)continue;
			for(int j=0;j<P[i];j++){
				cout << " " << S[i];
			}
		}
		for(int i=0;i<L1;i++){
			cout << " " << S[L1i] << S[L2i];
		}
		cout << "\n";
	}
	return 0;
}
