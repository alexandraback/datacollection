#include <bits/stdc++.h>

using namespace std;

int arr[26];
int N;

bool found;

typedef pair<int, int> pi;

vector<pi> dump;

int curN;

bool no_conflict(){
	// printf("Checking: [%d]", curN);
	// for(int i = 0; i<N; i++) printf(" %d", arr[i]);
	// 	printf("\n");
	for(int i = 0; i<N;i++){
		if(arr[i] <= (curN/2)){

		} else {
			return false;
		}
	}
	// printf("Good\n");
	return true;

}

void f(){
	if(found) return;

	if(curN == 0){

		for(auto p : dump){
			printf(" %c", p.first + 'A');
			if(p.second != -1){
				printf("%c", p.second+'A');
			}
		}

		printf("\n");
		found = true;
		return;
	}

	// Try 1
	for(int i = 0; i<N; i++){
		// printf("trying 1 with %d\n", i);
		if(arr[i] && arr[i]-1 <= (curN-1)/2) {
		// printf("Trying one with party %c\n", i+'A');


			arr[i] -=1;
			curN--;
			dump.push_back(pi(i, -1));
			if(no_conflict())
			f();
			dump.pop_back();
			curN++;
			arr[i]+=1;
		}
		if(found) return;
	}

	// Try 2
	for(int i = 0; i<N; i++){
		if(!arr[i]) continue;
			arr[i]--;
		for(int j=  0; j<N; j++){
			if(!arr[j]) continue;

			arr[j]--;
			curN-=2;

			if(arr[i] <= (curN)/2 && arr[j] <= (curN)/2){
				// printf("Trying two with party %c %c\n", i+'A', j+'A');
				dump.push_back(pi(i,j));
				if(no_conflict())
				f();
				dump.pop_back();
			}

			arr[j]++;
			curN+=2;

		}
		arr[i]++;
		if(found) return;
	}

}

int main(){
	int cases;
	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){
		printf("Case #%d:", e+1);
		scanf("%d", &N);

		curN = 0;
		for(int i = 0; i<N; i++){
			scanf("%d", &arr[i]);
			curN += arr[i];
		}

		found = false;
		f();
	}


	return 0;
}