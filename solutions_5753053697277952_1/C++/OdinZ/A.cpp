#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,c;
	scanf("%d", &t);
	for(int cs = 1; cs <= t; ++cs){
		scanf("%d", &n);
		priority_queue<pair<int,int> >  q;
		int s_p = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &c);	
			q.push(make_pair(c, i));
			s_p += c;
		}
		printf("Case #%d: ", cs);
		while(!q.empty()){
			int num = (s_p == 3 || s_p == 1) ? 1 : 2;
			for(int i = 0; i < num; ++i){
				pair<int,int> p1 = q.top();
				q.pop();
				printf("%c", 'A' + p1.second);
				if(p1.first > 1)
					q.push(make_pair(p1.first - 1, p1.second));
				s_p--;
			}
			printf(" ");			
		}
		puts("");
	}
}