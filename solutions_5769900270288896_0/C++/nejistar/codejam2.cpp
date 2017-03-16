# include <bits/stdc++.h>
using namespace std;

int mini, r, c, m;
int mark[17];
void recurse(int a, int x){
	if( a ==  (r*c)){
		if( x != m )
			return;
		int count = 0;
		for(int i = 0; i < r; i++){
			for( int j = 0; j < (c - 1); j++){
				if(mark[i*c + j] && mark[i*c + (j + 1)])
					count++;
			}
		}
		for(int i = 0; i < c; i++){
			for( int j = 0; j < (r - 1); j++){
				if(mark[j*c + i] && mark[(j + 1)*c + i])
					count++;
			}
		}
		if( count < mini )
			mini = count;
		return;
	}
	recurse( a + 1, x);
	mark[a] = 1;
	recurse( a + 1, x + 1);
	mark[a] = 0;
	return;
}

void init(){
	for( int i = 0; i < 17; i++ ){
			mark[i] = 0;
	}
}
int main(){
	freopen("read.txt", "r", stdin);
	freopen("write.txt", "w", stdout);
	int t;
	scanf("%d\n",&t);
	for( int kr = 1; kr <= t; kr++ ){
		init();
		printf("Case #%d: ",kr);
		scanf("%d%d%d",&r,&c,&m);
		mini = 99999;
		recurse( 0, 0);
		printf("%d\n", mini);
	}
	return 0;	
}