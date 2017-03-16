//C++ Template

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef map<int,int>::iterator ITmii;

#define EPS 1e-9
#define FOR1(x,y,z) for( int x = y; x < z ; ++x)
#define FOR(x,y) FOR1(x,0,y)
#define FOR2(x,y) for(int x = y; x >= 0; --x)
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define SORT(X) sort(ALL(X))
#define SIZE(X) ((int)(X).size())

//------------------------------------------------------------------
struct party{
	char name;
	int num;
};

struct compare{
	bool operator()(party a, party b){
		return a.num < b.num;

	}
};

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-Large.txt","w",stdout);
	int T; cin >> T;
	FOR(I,T){
		int N;
		cin >> N;
		priority_queue<party,vector<party>,compare> pq;
		FOR(i,N) {
			party a;
			a.name = 'A'+i;
			cin >> a.num;
			pq.push(a);
		}
		cout << "Case #" << I+1 << ":";
		while(not pq.empty()){
			party a = pq.top(); pq.pop();
			if(pq.size() == 1 and pq.top().num+1 == a.num or pq.empty())  cout << a.name;
			else cout << ' ' << a.name;
			--a.num;
			if (a.num > 0) pq.push(a);
			
		} 
		cout << '\n';
	}
}
