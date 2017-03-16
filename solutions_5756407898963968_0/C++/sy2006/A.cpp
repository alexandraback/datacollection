#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10+ch-'0';
}
int msk[5];
void run(int C) {
	printf("Case #%d: ", C);
	int a1, a2, x;
	R(a1);
	for (int i=1; i<=4; ++i) {
		msk[i] = 0;
		for (int j=1; j<=4; ++j) {
			R(x);
			msk[i] |= 1 << x;
		}
	}
	a1 = msk[a1];
	R(a2);
	for (int i=1; i<=4; ++i) {
		msk[i] = 0;
		for (int j=1; j<=4; ++j) {
			R(x);
			msk[i] |= 1 << x;
		}
	}
	a2 = msk[a2];
	a1 &= a2;
	if (!a1)
		puts("Volunteer cheated!");
	else {
		int r = __builtin_ctz(a1);
		if (a1 == (1 << r))
			printf("%d\n", r); else
			puts("Bad magician!");
	}
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) run(i);
	return 0;
}
