#include <fstream>
#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <algorithm>

struct C
{
	char c;
	int  len;
	C(char c_, int len_) : c(c_), len(len_) {}
};

int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);

	int T;
	fin >> T;
	for (int t=1; t<=T; t++) {
		int N;
		fin >> N;
		std::vector<std::vector<C>> sss;
		for (int n=0; n<N; n++) {
			std::vector<C> ss;
			std::string s;
			fin >> s;
			for (int i=0; i<s.size();) {
				C c(s[i], 1);
				for (; ++i<s.size();) {
					if (s[i] != c.c) break;
					c.len++;
				}
				ss.push_back(c);
			}
			sss.push_back(ss);
		}
		bool possible=true;
		for (int i=1; i<sss.size(); i++) {
			if (sss[i].size() != sss[0].size()) {
				possible=false;
				break;
			}
			for (int j=0; j<sss[0].size(); j++) {
				if (sss[i][j].c != sss[0][j].c) {
					possible=false;
					break;
				}
			}
			if (!possible) break;
		}

		if (possible) {
			int result=0;
			for (int i=0; i<sss[0].size(); i++) {
				std::vector<int> st;
				for (int j=0; j<sss.size(); j++) {
					st.push_back(sss[j][i].len);
				}
				std::sort(st.begin(), st.end());
				int median=st[st.size() / 2];
				for (int j=0; j<sss.size(); j++) {
					result += std::abs(sss[j][i].len - median);
				}
			}
			printf("Case #%d: %d\n", t, result);
		} else {
			printf("Case #%d: Fegla Won\n", t);
		}
	}

	return 0;
}
