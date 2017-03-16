#include <iostream>
#include <string>
using namespace std;

void run() {
	int row;
	cin >> row;

	bool q[16];
	for(int i=0; i<16; i++) q[i]=false;
	for(int i=0, tmp; i<16; i++) {
		cin >> tmp;
		if(i/4 == row-1) q[tmp-1]=true;
	}
	cin >> row;
	for(int i=0, tmp; i<16; i++) {
		cin >> tmp;
		if(i/4 != row-1) q[tmp-1]=false;
	}
	
	int result=-1;
	for(int i=0; i<16; i++)
		if(q[i])
			if(result == -1) result=i+1;
			else {
				cout << "Bad magician!";
				return;
			}
	if(result == -1) {
		cout << "Volunteer cheated!";
		return;
	}
	cout << result;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << "Case #" << (i+1) << ": ";
		run();
		cout << endl;
	}
}