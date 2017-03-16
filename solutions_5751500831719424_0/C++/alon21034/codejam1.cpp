#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector> 

using namespace std;

int* getNum(string str1) {
	char* chs1 = new char[100];
	int* t1 = new int[100];

	int top = 0;
	chs1[0] = str1[0];
	t1[0] = 1;

	for (int i = 1 ; i < str1.length()+1; ++i) {
		if(str1[i] == chs1[top]) {
			t1[top]++;
		} else {
			top++;
			chs1[top] = str1[i];
			t1[top] = 1;
		}
	}

	return t1;
}

char* getChar(string str1, int& num) {
	char* chs1 = new char[100];
	int* t1 = new int[100];

	int top = 0;
	chs1[0] = str1[0];
	t1[0] = 1;

	for (int i = 1 ; i < str1.length()+1; ++i) {
		if(str1[i] == chs1[top]) {
			t1[top]++;
		} else {
			top++;
			chs1[top] = str1[i];
			t1[top] = 1;
		}
	}

	num = top;
	return chs1;
}

bool check(char* ch1, char* ch2, int l1, int l2) {
	if (l1 != l2) {
		// cout << "l1 != l2" << endl;
		return false;
	}

	for (int i = 0 ; i < l1 ; ++i) {
		if (ch1[i] != ch2[i]) {
			// cout << ch1[i] << "!=" << ch2[i] << endl;
			return false;
		}
			
	}
	return true;
}

int getAns(int** t, int N, int l) {
	int ret = 0;
	for (int j = 0 ; j < l ; ++j) {
		vector<int> vec(N);
		for (int i = 0 ; i < N ; i++) {
			vec[i] = (t[i][j]);
		}

		sort(vec.begin(), vec.begin()+N);

		// for (int i = 0 ; i < N ; i++) {
		// 	cout << vec[i] << " ";
		// }
		// cout << endl;

		int mid = vec[N/2];
		for (int i = 0 ; i < N ; i++) {
			ret+=(vec[i]>mid)?vec[i]-mid:mid-vec[i];
		}
	}
	// cout << ret << endl;
	return ret;
}

int main() {

	int T;

	cin >> T;

	int index = 1;
	while (T--) {
		int N;
		cin >> N;

		string* strs = new string[N];

		char** c = new char*[N];
		int** t = new int*[N]; 

		int ans = 0;
		int* num = new int[N];
		for (int i = 0 ; i < N ; ++i) {
			cin >> strs[i];

			c[i] = getChar(strs[i], num[i]);
			t[i] = getNum(strs[i]);

			// for (int j = 0 ; j < num[i] ; j++) {
			// 	cout <<c[i][j] << "  " << t[i][j] << "  ";
			// }
			// cout << num[i] << endl;
		}

		bool flag = true;
		for (int i = 0 ; i < N ; i++) {
			if (!check(c[i], c[0], num[i], num[0])){
				ans = -1;
				flag = false;
				break;
			}
		}

		if (flag) {
			ans += getAns(t,N,num[0]);	
		}

		cout << "Case #" << index++ << ": ";
		if (ans == -1 ) {
			cout << "Fegla Won" << endl;
		} else {
			cout << ans << endl;
		}
	}

}