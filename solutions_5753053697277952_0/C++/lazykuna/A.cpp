#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

ifstream f;

struct Senator {
	char type;
	int cnt;
};

bool sfunc(const Senator& a, const Senator& b) { return b.cnt<a.cnt; }

void process() {
	int cnt, t=0;
	Senator s[30];
	for (int i=0; i<=26; i++) {
		s[i].type = 'A'+i;
		s[i].cnt = 0;
	}
	f >> cnt;
	for (int i=0; i<cnt; i++) {
		f >> s[i].cnt;
		t += s[i].cnt;
	}
	sort(s, s+26, sfunc);
	for (;t;) {
		if (t == 3 || t == 1) {
			s[0].cnt--; t++;
			cout << s[0].type << ' ';
		}
		else if (s[0].cnt-s[1].cnt >= 2) {
			s[0].cnt-=2;
			cout << s[0].type << s[0].type << ' ';
		}
		else {
			s[0].cnt--;
			s[1].cnt--;
			cout << s[0].type << s[1].type << ' ';
		}
		sort(s, s+26, sfunc);
		t-=2;
	}
}

int main(int argc, char **argv) {
	f.open(argc>=2 ? argv[1] : "input.txt");
	int n;	f >> n;
	for (int i=0; i<n; i++) {
		cout << "Case #" << i+1 << ": ";
		process();
		cout << endl;
	}
	return 0;
}
