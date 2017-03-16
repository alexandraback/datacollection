#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<string>
#define P(x,y) make_pair(x,y)
using namespace std;
int ntests, Tn, ar[560];
int main() {
	
	freopen("A.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	string str;
	cin >> ntests;
	while (ntests--) {
		int n, m;
		cin >> n;
		vector < pair < int, int > > v;
		for (int j = 0;j < n;j++) cin >> ar[j];
		for (int j = 0;j < n;j++)
			v.push_back(P(ar[j], j));
		vector < string > I_hate_google;
		sort(v.begin(), v.end());
		int sz = n;
		while (v[sz - 1].first != v[sz - 2].first) {
			string mega_string;
			mega_string.push_back(char('A' + v[sz - 1].second));
			v[sz - 1].first--;
			I_hate_google.push_back(mega_string);
		}
		for (int j = 0;j < sz - 2;j++) {
			while (v[j].first > 0) {
				string mega_string;
				mega_string.push_back(char('A' + v[j].second));
				v[j].first--;
				I_hate_google.push_back(mega_string);
			}
		}
		while (v[sz - 1].first > 0) {
			string mega_string;
			mega_string.push_back(char('A' + v[sz - 1].second));
			mega_string.push_back(char('A' + v[sz - 2].second));
			v[sz - 1].first--; v[sz - 2].first--;
			I_hate_google.push_back(mega_string);

		}
		int ss = I_hate_google.size();
		printf("Case #%d: ", ++Tn);
		for (int j = 0;j < ss - 1;j++) {
			cout << I_hate_google[j] << ' ';
		}
		cout << I_hate_google.back() << ' ';
		cout << endl;
	}
}