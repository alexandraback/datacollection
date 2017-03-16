#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;
const ll MAXV = 100000000000000ll + 1ll;

ll solve(int tc){
	ll B, N;
	cin >>B>> N;
	vector<ll> barbers(B, 0ll);
	for (auto& i : barbers)
		cin >> i;
	//binary search variables
	ll mint = 0, maxt = MAXV, midt;
	while (maxt - mint > 2){
		midt = (maxt + mint) / 2;
		// if all customer can cut his/her hair, midt has to be increased.
		ll haircuted = 0;
		for (ll& i : barbers)
			haircuted += (midt / i) + 1;

		if (haircuted >= N-1)
			maxt = midt;
		else
			mint = midt;
	}
	//maxt is available N-1
	ll firstAvailable = maxt;
	for (ll k = maxt - 1; k >= max(mint-4,0ll); --k){
		ll haircuting = 0;
		for (ll& i : barbers)
			haircuting += (k / i) + 1;

		if (haircuting >= N-1) // k is available
			firstAvailable = k;
		else
			break;
	}

	//firstAvailable : N-1번째 손님이 머리를 자르러 들어간 시간이 된다. 그 이전 시간에는 불가능했으므로 여기서부터 N번째(나)가 들어갈 가능성이 생긴다
	//#1 혹시 이 시간에 나도 같이 들어갈 수 있다면?
	ll haircut = 0;
	for (auto& i : barbers){
		haircut += (firstAvailable / i) + 1;
	}
	if (haircut >= N){
		//나도 들어갈 수 있으므로 firstAv-1 때의 상황을 보고
		ll notYet = firstAvailable - 1, startingPoint = 0;
		vector<ll> doneAt(B, 0ll); // notYet시간 까지 들어간 사람들이 각각 머리깎기가 끝나는 시간
		
		for (int i = 0; i < B;++i){
			startingPoint += notYet / barbers[i] + 1;
			doneAt[i] = notYet / barbers[i] * (barbers[i]+1);
		}
		if (startingPoint >= N - 1){
			cerr << "**??????? error!!!!" << endl;
			exit(0);
		}
		//N-x번째 것부터 집어넣어본다
		// minidx : start with [startingPoint+1]...
		int minidx;
		for (ll i = startingPoint + 1; i <= N; ++i){
			minidx = 0;
			for (int j = 0; j < B; ++j){
				if (doneAt[j] < doneAt[minidx]) minidx = j;
			}
			doneAt[minidx] += barbers[minidx];
		}
		//minidx : N
		return minidx+1;
	}
	//#2 시간이 지나야 한다면?
	// = 곧바로 시뮬레이션하면 된다
	vector<ll> doneAt(B, 0ll); // firstAvailable시간까지 들어간 사람들이 각각 머리깎기가 끝나는 시간
	int minidx = 0;
	for (int i = 0; i < B; ++i){
		doneAt[i] = firstAvailable / barbers[i] * (barbers[i] + 1);
		if (doneAt[i] < doneAt[minidx])
			minidx = i;
	}
	return minidx+1;
}

int main(){
	cin.sync_with_stdio(false);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		ll idx = solve(tc);
		cout << "Case #" << tc << ": " << idx << '\n';
	}
	return 0;
}