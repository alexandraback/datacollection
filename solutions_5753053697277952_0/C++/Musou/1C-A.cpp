#include <iostream>
#include <vector>
using namespace std;

int largest(int p[]);

int main() {
	int T,N;
	cin >> T;
	for(int i=0;i<T;++i) {
		cin >> N;
		int parties[26]={0};
		int P,sum=0;
		int rmv;
		cout << "Case #" << i+1 << ": ";
		for(int j=0;j<N;++j) {
			cin >> P;
			parties[j]=P;
			sum+=P;
		}
		while(sum>0) {
			if(sum==1) {
				rmv=largest(parties);
				parties[rmv]--;
				sum--;
				cout << char(rmv+65);
			} else {
				rmv=largest(parties);
				parties[rmv]--;
				cout << char(rmv+65);
				rmv=largest(parties);
				parties[rmv]--;
				cout << char(rmv+65) << ' ';
				sum-=2;
			}
		}
	cout << endl;
	}
	return 0;
}

int largest(int p[]) {
	int mv=0;
	int max=0;
	for(int i=0;i<26;++i) {
		if(p[i]>mv) {
			mv=p[i];
			max=i;
		}
	}
	return max;
}