#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

struct AR{
	char c;	
	int n;
	bool operator<(const struct AR &t)const{
		return n<t.n;
	}
};

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		priority_queue<struct AR> q;
		scanf("%d",&N);
		int sum=0;
		for(int i=0; i<N; ++i){ 
			struct AR tmp;
			tmp.c='A'+i;
			scanf("%d",&tmp.n);
			sum+=tmp.n;
			q.push(tmp);
		}
		printf("Case #%d:",Case);
		while(!q.empty()){
			struct AR tmp = q.top();
			q.pop();
			--tmp.n;
			--sum;
			printf(" %c",tmp.c);
			if(tmp.n) q.push(tmp);
			/* finish first fetch */
			if(100*q.top().n/sum>50){
				struct AR tmp2 = q.top();
				q.pop();
				--tmp2.n;
				--sum;
				printf("%c",tmp2.c);
				if(tmp2.n) q.push(tmp2);
			}
		}
		puts("");
	}
	return 0;
}
