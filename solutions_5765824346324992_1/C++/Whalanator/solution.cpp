#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
long double speed;
long long T,B,N,c1,lb,c2;
typedef vector<int> vi;
vi mks;
priority_queue<pii> ftimes;
pii t;

int main() {
	cin >> T;
	int cas=1;
	mks.assign(1000,0);
	for (;cas<=T;cas++) {
		cin >> B >> N;
		speed=0;
		for (c1=0;c1<B;c1++) {
			cin >> mks[c1];
			speed+=1.0/mks[c1];
		}
		lb=((N-1)-100000)/(long double)speed;

		//cout << "speed: " << speed << endl;
		//cout << "lb: " << lb << endl;

		if (lb<0) lb=0;
		while(ftimes.size()) ftimes.pop();
		c2=0;
		if (N<=B) {cout << "Case #" << cas << ": " << N << endl; continue;}
		for (c1=0;c1<B;c1++) {
			c2+=lb/mks[c1]+1;
			ftimes.push(make_pair(lb-(lb/mks[c1])*mks[c1]-mks[c1],-c1));
		}
		//cout << N-c2 << endl;
		for (;c2<N-1;c2++) {
			t=ftimes.top();
			ftimes.pop();
			t.first-=mks[-t.second];
			ftimes.push(t);
		}
		cout << "Case #" << cas << ": " << (1-ftimes.top().second) << endl;
	}
	return 0;
}
