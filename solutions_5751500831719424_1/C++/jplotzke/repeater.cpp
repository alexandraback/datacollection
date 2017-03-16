#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 100, L = 100;
struct Char {
	char c; int cnt;
	Char(char C=' ', int CNT=0){ c = C; cnt = CNT; }
};
struct String {
	Char ch[L]; int len;
};
String str[N];

int min_change(const int & cnt, const int & loc){
	int num1 = L, num2 = 0, moves = N*L, tmp;
	for (int x = 0; x < cnt; ++x){
		if (str[x].ch[loc].cnt < num1) num1 = str[x].ch[loc].cnt;
		if (str[x].ch[loc].cnt > num2) num2 = str[x].ch[loc].cnt;
	}
	for (int n = num1; n <= num2; ++n){
		tmp = 0;
		for (int x = 0; x < cnt; ++x){
			if (str[x].ch[loc].cnt < n) tmp += (n - str[x].ch[loc].cnt);
			else tmp += (str[x].ch[loc].cnt - n);
		}
		if (tmp < moves) moves = tmp;
	}
	return moves;
}

int deter_moves(const int & cnt){
	int len = str[0].len, moves = 0;
	for (int x = 1; x < cnt; ++x)
		if (str[x].len != len) return -1;
	for (int y = 0; y < len; ++y)
		for (int x = 1; x < cnt; ++x)
			if (str[x].ch[y].c != str[0].ch[y].c) return -1;
	for (int y = 0; y < len; ++y)
		moves += min_change(cnt, y);
	return moves;
}

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "A-large.in", "r", stdin);
	freopen_s(&fout, "repeater.out", "w", stdout);
	int run, cnt, prev, moves; string tmp;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> cnt;
		for (int x = 0; x < cnt; ++x){
			cin >> tmp; str[x].len = 0;
			prev = 0;
			for (int y = 1; y < tmp.length(); ++y){
				if (tmp[y] != tmp[prev]){
					str[x].ch[str[x].len++] = Char(tmp[prev], y-prev);
					prev = y;
				}
			}
			str[x].ch[str[x].len++] = Char(tmp[prev], tmp.length()-prev);
		}
		cout << "Case #" << a << ": ";
		if ((moves = deter_moves(cnt)) == -1) cout << "Fegla Won" << endl;
		else cout << moves << endl;
	}
	return 0;
}
