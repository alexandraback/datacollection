#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> ii;


void testcase(int T){
	int n;
	scanf("%d", &n);
	int cnts[27];
	REP(i, n)scanf("%d", &cnts[i]);

	int difs = 0;
	int sum = 0;
	REP(i, n){
		if(cnts[i] > 0)difs++;
		sum+=cnts[i];
	}

	printf("Case #%d: ", T);

	if(difs == 2){
		vector<int> d;
		REP(i, n)if(cnts[i] > 0)d.push_back(i);
		for(;sum > 0; sum-=2){
			printf("%c%c ", d[0]+'A', d[1]+'A');
		}
		printf("\n");
		return;
	}

	priority_queue<ii> q;
	REP(i, n)q.push(ii(cnts[i], i));

	while(sum > 4){
		auto t = q.top();
		q.pop();
		t.first--;
		sum--;
		printf("%c ", 'A'+t.second);
		q.push(t);
	}

	vector<int> twos, ones;
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		if(t.first == 2)twos.push_back(t.second);
		if(t.first == 1)ones.push_back(t.second);
	}

	if(twos.size() > 1){
		printf("%c%c %c%c\n", 'A'+twos[0], 'A'+twos[1], 'A'+twos[0], 'A'+twos[1]);
	} else if(twos.size() == 1){ // sum == 4
		printf("%c%c %c%c\n", 'A'+twos[0], 'A'+twos[0], 'A'+ones[0], 'A'+ones[1]);
	} else{ // twos.size() == 0
		if(sum == 4){
			printf("%c%c %c%c\n", 'A'+ones[0], 'A'+ones[1], 'A'+ones[2], 'A'+ones[3]);
		} else if(sum == 3){
			printf("%c %c%c\n", 'A'+ones[0], 'A'+ones[1], 'A'+ones[2]);
		} else if(sum == 0){
			assert(false);
			printf("\n");
		} else{ // sum == 2
			printf("%c%c\n", 'A'+ones[0], 'A'+ones[1]);
		}
	}

}

int main(){
	int T;
	cin >> T;
	REP(i, T)testcase(i+1);


	return 0;
}
