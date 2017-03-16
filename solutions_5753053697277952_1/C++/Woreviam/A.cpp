
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int main(){

	int tc = 0,caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n, p;
		scanf("%d", &n);
		
		priority_queue<pair<int, char> >Q;
		int quedan = 0;
		for(int i = 0; i < n; i++){
			
			scanf("%d", &p);
			Q.push(make_pair(p, char(i + 'A')));
			quedan += p;
		}
		
		vector<string>ans;
		pair<int, char>best1, best2;
		
		string aux;
	
		
		while(!Q.empty()){
		
			aux = "";
		
			if(quedan == 3){
				
				best1 = Q.top();
				Q.pop();
				
				aux += best1.second;
				quedan--;
			}
			else{
				
				best1 = Q.top();
				Q.pop();
				
				
				best2 = Q.top(), Q.pop();
				
				if(best1.first == best2.first){
						
					aux += best1.second;
					aux += best2.second;
						
					best1.first--;
					best2.first--;
						
					if(best1.first > 0)Q.push(best1), Q.push(best2);
					quedan -= 2;
				}
				else{
					
					aux += best1.second;
					best1.first--;
					
					Q.push(best2);
					if(best1.first > 0)Q.push(best1);
					quedan--;
				}	
			}
			
			ans.pb(aux);

		}
		
		printf("Case #%d:", caso++);
		for(int i = 0; i < ans.size(); i++)printf(" %s", ans[i].c_str());
		puts("");
		
		
	}


}

