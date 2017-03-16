#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define FOR(a,b,c) for(long long a=(b);a!=(c);a++)
#define REP(a,n) for(long long a=0;a!=(n);a++)
#define FORE(a,b,c) for(long long a=(b);a<=(c);a++)

using namespace std;

long long t, b, n, tmp, res; long long arr[1001];
long long time;

long long counter(long long time) {
	long long count = b;
	if(time < 0) return 0; if(time == 0) return b;
	REP(i,b) 
		count += time / (long long)(arr[i]);
	if(count < 0) throw"error";
	return count;
}

bool check(long long time) {
	return counter(time) >= (long long)(n);
}

long long binary(long long l, long long r) {
	if(l==r) {
		if(check(l)) return l; 
		else return -1;
	}
	if(l+1==r) {
		if(check(l)) return l;
		if(check(r)) return r;
		return -1;
	}
	long long m = (l+r) >> 1;
	bool tmp = check(m);
	if(!tmp) return binary(m+1, r);
	return binary(l,m);
}
/*
struct Barber {
	int id, time;
	Barber(int _id, int _time):
		id(_id), time(_time) {}
	bool operator < (const Barber & other) {
		return !(time < other.time || (time == other.time && id < other.id));
	}
};

int main() {
	cin >> t;
	vector<Barber> v;
	REP(a,t) {
		cin >> b >> n;
		v.clear();
		REP(i,b) { cin >> arr[i]; v.emplace_back(i, 0); }
		make_heap(v.begin(), v.end());
		int id;
		while(n!=1) {
			n--;
			id = v.front().id;
			for(vector<Barber>::iterator p = v.begin(); p!=v.end(); p++) {
				p->time = p->time - v.front().time;
			}
			pop_heap(v.begin(), v.end());
			v.pop_back();
			v.emplace_back(id, arr[id]);
			push_heap(v.begin(), v.end());
		}
		cout << "Case #" << a+1 << ": " << id+1 << endl;
	}
	return 0;
}
*/

int main() {
	cin >> t;
	REP(a,t) {
		cin >> b >> n;
		REP(i,b) { cin >> arr[i]; }

		//b=3; arr[0]=5; arr[1]=2;arr[2]=1;
		//for(n=1;n<=20;n++) {

		time = binary(0, 0x3FFFFFFFFFFFFF);
		long long count = (long long)(n) - counter(time-1);
		long long i;
		for(i=0; i<b; i++) {
			if(time % (long long)(arr[i]) == 0) {
				if(count==1) break; else count --; 
			}
		}
		if(i==b) throw "error";
		cout << "Case #" << a+1 << ": " << (i+1) << endl;

		//}
	}
	return 0;
}