#include <cstdio>
#include <iostream>

using namespace std;

int nTest,B,N,timeNeeded[100010];

long long simulation[100010];

long long formula(long long seconds) {
	long long sum = 0LL;
	for (int i=0;i<B;i++) {
		sum += (seconds/timeNeeded[i]);
		if (seconds%timeNeeded[i] != 0LL) sum+=1LL;
	}
	return sum;
}


long long binarySearch(long long left,long long right) {
	long long center = (left + right) /2LL;
	if (left + 1LL == right) return left;
	long long current = formula(center);
	if (current > N) {
		return binarySearch(left,center);
	}
	else if (current == N) {
		if (formula(center-1LL)==N) {
			return binarySearch(left,center);
		} else {
			return center;
		}
	}
	else {
		return binarySearch(center,right);
	}
}


int main() {
	scanf("%d",&nTest);
	for (int tc=1;tc<=nTest;tc++) {
		scanf("%d %d",&B,&N);
		for (int i=0;i<B;i++) {
			scanf("%d",&(timeNeeded[i]));
		}
		long long minTime = binarySearch(0LL,100000000000000LL);
		long long current = formula(minTime);
		long long answer = 0;
		if (current == N) {
			minTime -= 1;
		}
		current = formula(minTime);
		for (int i=0;i<B;i++) {
			long long nPeople = (minTime/timeNeeded[i]);
			if (minTime%(long long)timeNeeded[i]!=0LL) nPeople+=1LL;
			simulation[i] = nPeople * timeNeeded[i];
		}
		for (int i=0;i<B;i++) {
			if (simulation[i]==minTime) current += 1LL;
			if (current == N) {
				answer = i+1;
				break;
			}
		}
		cout<<"Case #"<<tc<<": "<<answer<<endl;
	}
	return 0;
}