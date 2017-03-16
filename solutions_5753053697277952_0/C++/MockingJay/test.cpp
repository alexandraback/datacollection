    #include <bits/stdc++.h>
    using namespace std;
    #define int long long 
     
    #undef int
    int main(){
    	#define int long long 
    	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    	freopen("A-small-attempt5.in", "r", stdin);
    	freopen("output.out", "w", stdout);
    	int i,j,k,n,m,c;
    	cin >> c;
    	for (i = 1; i <= c; i++){
    		cin >> n;
    		vector<pair<int, char>> S;
    		int total = 0;
    		for (j = 0; j < n; j++){
    			cin >> k;
    			total += k;
    			S.emplace_back(make_pair(-k, 'A' + j));
    		}
    		sort(S.begin(), S.end());
    		bool fP = true;
    		cout << "Case #" << i << ": ";
    		while (S[0].first < 0){
    			if (!fP) cout << " ";
    			if (S[0].first % 2 == -1){
    				cout << S[0].second;
    				if (S[1].first == S[0].first){
    					if (S.size() > 2){
    						if (S[2].first == 0){
    							cout << S[1].second;
    							S[1].first++;
    						}
    					}else{
    						cout << S[1].second;
    						S[1].first++;
    					}
    				}
    				else if (S[0].first < -1){
    					S[0].first++;
    					cout << S[0].second;
    				}		
    			}else{
    				cout << S[0].second;
    				if (S[1].first < 0 && S[1].first == S[0].first){
    					cout << S[1].second;
    					S[1].first++;
    				} 
    			}
    			S[0].first++;
    			fP = false;
    			sort(S.begin(), S.end());
    		}
    		//print ans here
    		cout << "\n";
    	}
    	return 0;
    }