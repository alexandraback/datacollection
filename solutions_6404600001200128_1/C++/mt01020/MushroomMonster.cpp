#include<cstdio>
using namespace std;

int main(){
    int T, N;
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d ", &N);
	int *mi = new int[N];
	for(int i=0; i<N; ++i)	scanf(" %d ", &mi[i]);
	int res1 = 0;
	for(int i=1; i<N; ++i){
	    if(mi[i] < mi[i-1])	res1 += (mi[i-1]-mi[i]);
	}
	int res2 = 0;
	int maxeat = 0;
	for(int i=1; i<N; ++i){
	    if(mi[i-1]-mi[i] > maxeat)	maxeat = mi[i-1]-mi[i];
	}
	for(int i=0; i<N-1; ++i){
	    res2 += (mi[i] > maxeat ? maxeat : mi[i]);
	}
	printf("Case #%d: %d %d\n", t, res1, res2);
    }
    return 0;
}
