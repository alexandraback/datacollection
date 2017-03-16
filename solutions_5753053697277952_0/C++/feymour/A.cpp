#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=0;t<T;++t) {
		int N;
		cin >> N;
		priority_queue<pair<int,char> > parties;
		int sum = 0;
		for (int n=0;n<N;++n) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			parties.push(make_pair(tmp,(char)('A'+n)));
		}
		string result;
		bool firsttime = true;
		while (!parties.empty()) {
			if (result.length()>0) {
				result += " ";
			}
			pair<int,char> first = parties.top();
			parties.pop();
			result += first.second;
			first.first--;
			if (firsttime && sum%2 == 1) {
				firsttime = false;
				if (first.first>0) {
					parties.push(first);
				}
				continue;
			}
			if (!parties.empty() && parties.top().first >= first.first) {
				pair<int,char> second = parties.top();
				parties.pop();
				result += second.second;
				second.first--;
				if (second.first>0) {
					parties.push(second);
				}
			} else if (first.first>0) {
				result += first.second;
				first.first--;
			}
			if (first.first>0) {
				parties.push(first);
			}
		}
		
		cout << "Case #" << t+1 << ": ";
		cout << result;
		cout << endl;
	}
	return 0;
}
