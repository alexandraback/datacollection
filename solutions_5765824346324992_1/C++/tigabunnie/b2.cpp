#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	int B, N;
	int M[1000], M_min, n;
	unsigned int whoFinished, timeNow;
	multiset<uint64_t> ms;
	multiset<uint64_t>::iterator it;
	uint64_t ts;
	double peoplePerMin;
	long long minutes, alreadyServiced, availableIn;
	
	
	for (int t=1; t<=T; t++) {
		printf("Case #%d: ", t);
		cin >> B >> N;
		for (int i=0; i<B; i++) cin >> M[i];
		
		
		if (N <= B) {
			whoFinished = N-1;
		}
		else {
			M_min = M[0];
			for (int i=1; i<B; i++) if (M[i] < M_min) M_min = M[i];
			alreadyServiced = 0;
			
			peoplePerMin = 0;
			for (int i=0; i<B; i++) peoplePerMin += 1.0 / M[i];
			minutes = N / peoplePerMin;
			alreadyServiced = 0;
			for (int i=0; i<B; i++) alreadyServiced += (minutes+M[i]-1) / M[i];
			
		//	printf("minutes %lld, alreadyServiced %lld, N-B %d\n", minutes, alreadyServiced, N-B);
			while (alreadyServiced >= N-B) {
				minutes -= M_min;
				if (minutes < 0) {
					minutes = 0;
					alreadyServiced = 0;
					break;
				}
				alreadyServiced = 0;
				for (int i=0; i<B; i++) alreadyServiced += (minutes+M[i]-1) / M[i];
		//	printf("minutes %lld, alreadyServiced %lld, N-B %d\n", minutes, alreadyServiced, N-B);
			}
			
			
		//	printf("minutes %lld, alreadyServiced %lld, N-B %d\n", minutes, alreadyServiced, N-B);
			
			ms.clear();
			for (int i=0; i<B; i++) {
				availableIn = minutes % M[i];
				if (availableIn) availableIn = M[i] - availableIn;
				ts = availableIn;
				ts <<= 32;	//finish time on upper 32 bits
				ts |= i;	//barber number of lower 32
				ms.insert(ts);
			//	printf("push %lld %lld\n", ts >> 32, ts & 0xffffffff);
			}
			for (n=alreadyServiced; n<N-1; n++) {
				it = ms.begin();
				ts = *it;
				ms.erase(it);
				whoFinished = ts & 0xffffffff;
				timeNow = ts >> 32;
			//	printf("pop %d %d\n", timeNow, whoFinished);
				
				ts = M[whoFinished] + timeNow;
				ts <<= 32;
				ts |= whoFinished;
				ms.insert(ts);
			//	printf("push %lld %lld\n", ts >> 32, ts & 0xffffffff);
			}
			it = ms.begin();
			ts = *it;
			whoFinished = ts & 0xffffffff;
		}
		printf("%d", whoFinished+1);
		printf("\n");
	}
	return 0;
}