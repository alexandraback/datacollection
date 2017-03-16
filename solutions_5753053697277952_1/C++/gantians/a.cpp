#include <bits/stdc++.h>

using namespace std;

int n;
struct node{
	int x,y;
	node(int x,int y):x(x+'A'),y(y){}
	node(){}
	bool operator<(node b)const{
		return y>b.y;
	}
};
vector<node> v;

int main(){
	int T;
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		v.clear();
		int tot=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			tot+=x;
			v.push_back(node(i,x));
		}
		
		printf("Case #%d:", ti);
		while (tot>0){
			sort(v.begin(),v.end());
			printf(" %c",v[0].x);
			v[0].y--;tot--;
			if (v[1].y*2>tot){
				printf("%c",v[1].x);
				v[1].y--;tot--;
			}
		}
		printf("\n");
	}
	return 0;
}