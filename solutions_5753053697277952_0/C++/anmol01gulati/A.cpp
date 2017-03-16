#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int t;
	int maxNow = -1;
	map<int,vector<int> > M;
	int p[30];
	scanf("%d",&t);
	for(int z = 1;z<=t;z++){
		for(int i = 0;i<30;i++) p[i] = 0;
		M.clear();
		printf("Case #%d: ",z);
		scanf("%d",&n);
		int total = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&p[i]);
			total += p[i];
			maxNow = max(p[i],maxNow);
			M[p[i]] = vector<int>(0);
		}	
		for(int i = 0;i<n;i++){
			M[p[i]].push_back(i);
		}
		int id1,id2;
		while(total>0){
			vector<int> presAns;
			if(M[maxNow].size()&1){
				id1 = M[maxNow][0];
				presAns.push_back(id1);
				p[id1]--;
				M[maxNow].erase(M[maxNow].begin());
				M[p[id1]].push_back(id1);
				if(M[maxNow].size() == 0) maxNow = p[id1];
				total--;
			}else{
				id1 = M[maxNow][0];
				id2 = M[maxNow][1];
				p[id1]--;
				p[id2]--;
				M[maxNow].erase(M[maxNow].begin(),M[maxNow].begin()+2);
				M[p[id1]].push_back(id1);
				M[p[id2]].push_back(id2);
				if(M[maxNow].size() == 0) maxNow = p[id1];
				presAns.push_back(id1);
				presAns.push_back(id2);
				total-=2;
			}
			for(int i =0;i<presAns.size();i++){
				printf("%c",char('A' + presAns[i]));
			}
			printf(" ");
		}
		printf("\n");
	}
	return 0;
	
}