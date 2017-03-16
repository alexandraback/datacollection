#include<cstdio>
using namespace std;

int main(){
    int T, R, C, N;
    int room[16];
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d %d %d ", &R, &C, &N);
	for(int i=0; i<R; ++i){
	    for(int j=0; j<C; ++j){
		room[i*C+j] = (i==0 ? 0 : 1)+(i==R-1 ? 0 : 1)+(j==0 ? 0 : 1)+(j==C-1 ? 0 : 1);
	    }
	}
	int max = ((R-1)*C+(C-1)*R);
	int emp = R*C - N;
	while(emp > 0){
	    int rr = -1;
	    int rc = -1;
	    int mn = -1;
	    for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
		    if(room[i*C+j] > mn){
			mn = room[i*C+j];
			rr = i;
			rc = j;
		    }
		}
	    }
	    max -= room[rr*C+rc];
	    room[rr*C+rc] = -(R*C+1);
	    if(rr > 0)	room[(rr-1)*C+rc] -= 1;
	    if(room[(rr-1)*C+rc] < 0)	room[(rr-1)*C+rc] = 0;
	    if(rr < R-1)    room[(rr+1)*C+rc] -= 1;
	    if(room[(rr+1)*C+rc] < 0)	room[(rr+1)*C+rc] = 0;
	    if(rc > 0)	room[rr*C+(rc-1)] -= 1;
	    if(room[rr*C+(rc-1)] < 0)	room[rr*C+(rc-1)] = 0;
	    if(rc < C-1)    room[rr*C+(rc+1)] -= 1;
	    if(room[rr*C+(rc+1)] < 0)	room[rr*C+(rc+1)] = 0;
	    --emp;
	}
	printf("Case #%d: %d\n", t, max);
    }
    return 0;
}
