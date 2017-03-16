#include <bits/stdc++.h>
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define FOR(x,m,n) for(int x=(int)m;x<(int)(n);x++)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
map<LL, LL> memo;

void dostuff() {
	LL B, N, cur = 0, t = 0;
	cin >> B >> N;
	vector<LL> M(B);
	memo.clear(), --N;
	REP(i, B) cin >> M[i];
	priority_queue<PLI> Q;
	set<int> barbers;
	REP(i, B) barbers.insert(i);
	if (N == 0) {
		printf("1\n");
		return;
	}
	while (cur < N || barbers.size() == 0) {
		//there is free barber
		if (barbers.size() && cur < N) {
			int b = *barbers.begin();
			barbers.erase(b);
			Q.push(PLI(t - M[b], b));
			fprintf(stderr, "%lli -> %i until %lli\n", cur, b, M[b] - t);
			memo[cur] = b;
			++cur;
			continue;
		}

		//empty barber
		PLI aux = Q.top();
		int b = aux.second;
		t = aux.first;
		fprintf(stderr, "Barber finished @%lli: %i", -t, b + 1);
		Q.pop();
		barbers.insert(b);
		while (Q.size() > 0 && Q.top().first == t) {
			barbers.insert(Q.top().second);
			fprintf(stderr, " %i", Q.top().second + 1);
			Q.pop();
		}
		fprintf(stderr, "\n");

		if (Q.size() == 0) {
			cout << memo[N % cur] + 1 << endl;
			fprintf(stderr, "Rotation @ %lli!\n", cur);
			return;
		}
	}
	cout << *barbers.begin() + 1 << endl;
	fprintf(stderr, "Finished\n");
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}