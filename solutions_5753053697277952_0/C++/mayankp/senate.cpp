#include <bits/stdc++.h> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, char> pic;
template<class T> inline T maxm(T& a, T b){return a = a < b ? b : a;}
template<class T> inline T minm(T& a, T b){return a = a > b ? b : a;}

int P[26];
int tot[26];
int main(){

    int T;
    cin >> T;
    for(int i_ = 0; i_ < T; i_++){
	deque<pic> V;
	int N;
	cin >> N;

	int s = 0;
	int cnt = 0;
	for(int i = 0; i < N; i++){ 
	    cin >> P[i];
	    V.push_back(mp(P[i], 'A' + i));
	    s += P[i];
	}

	deque<pair<char, char> > ans;

	sort(V.begin(), V.end());
	while(!V.empty()){

	    while(V[0].X){
		if(V.size() > 1){
		    ans.push_front(mp(V[0].Y, V[1].Y));
		    V[1].X--;
		}else ans.push_front(mp(V[0].Y, 0));
		V[0].X--;
	    }
	    V.pop_front();

	}

	cout << "Case #" << i_ + 1 << ": ";
	for(int i = 0; i < ans.size(); ++i){
	    cout << ans[i].X; 
	    if(ans[i].Y) cout << ans[i].Y;
	    cout << ' ';
	}
	cout << '\n';

    }
    return 0;

}
