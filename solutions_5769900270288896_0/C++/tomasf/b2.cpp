#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int b[16];
int mn;
int r,c,n;

int test(){
	int total = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(b[i*c + j]){
				if(j - 1 >= 0){
					total += b[i*c + j - 1];
				}
				if(j + 1 < c){
					total += b[i*c + j + 1];
				}
				if(i - 1 >= 0){
					total += b[(i-1)*c + j];
				}
				if(i + 1 < r){
					total += b[(i+1)*c + j];
				}
			}
		}
	}
	return total/2;
}

void bf(int left, int cur){
	if(cur >= r*c and left){
		return;
	}if(left == 0){
		mn = min(test(), mn);
		return;
	}else{
		b[cur] = 1;
		bf(left-1, cur+1);
		b[cur] = 0;
		bf(left, cur+1);
	}
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> r >> c >> n;
		mn = 100000;
		memset(b, 0, sizeof b);
		bf(n, 0);
		cout << "Case #"<< t << ": " << mn << endl;


	}
    return 0;
}