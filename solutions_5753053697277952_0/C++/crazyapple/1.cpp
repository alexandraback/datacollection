#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
	int T, n;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n;
		string res = "";
		int count = 0;
		unordered_map<int, int>dic;
		for(int i = 0; i < n; i++) {
			cin >> dic[i];
			count += dic[i];
		}
		while(count > 0) {
			int flag = -1, index1 = -1, index2 = -1, m1 = 0, m2 = 0;
			for(int i = 0; i < n; i++) {
				if(index1 != -1 && dic[i] > m1) {
					index1 = i;
					m1 = dic[i];
				} else if(index1 != -1 && dic[i] == m1) {
					index2 = i;
					m2 = dic[i];
				} else if(index1 == -1 && dic[i] > 0) {
					index1 = i;
					m1 = dic[i];
				}
			}
			char c1 = 'A' + index1;
			res = res + " " + c1;
			dic[index1]--;
			count--;
			if(m1 == m2) {
				if(dic[index2] > count / 2) {
					char c2 = ('A' + index2);
					res = res +  c2;
					dic[index2]--;
					count--;
				}
			}			
		}
		cout << "Case #" << t << ":" << res << endl;
	}
	return 0;
}