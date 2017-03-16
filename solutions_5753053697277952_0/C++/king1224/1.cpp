#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
	char p;
	int num;
	bool operator < (const Node &a) const{
		return num < a.num;
	}
}party[30];

int main(){
	int T;
	int N;
	scanf("%d",&T);
	Node now1,now2;
	for(int i=1;i<=T;++i){
		priority_queue<Node> q;
		scanf("%d",&N);
		for(int j=0;j<N;++j){
			party[j].p='A'+j;
			scanf("%d",&party[j].num);
			q.push(party[j]);
		}

		printf("Case #%d:",i);

		while(q.size()){
			if(q.size()%2){ //奇數
				now1=q.top();
				q.pop();
				printf(" %c",now1.p);
				--now1.num;
				if(now1.num>0){
					q.push(now1);
				}
			}
			else{
				now1=q.top();
				q.pop();
				now2=q.top();
				if(now1.num==now2.num){ //前兩大相等
					q.pop();
					printf(" %c%c",now1.p,now2.p);
					--now1.num;
					--now2.num;
					if(now1.num>0){
						q.push(now1);
						q.push(now2);
					}
				}
				else{
					printf(" %c",now1.p);
					--now1.num;
					if(now1.num>0){
						q.push(now1);
					}
				}
			}
		}
		printf("\n");
	}
}
