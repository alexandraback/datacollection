#include <iostream>

using namespace std;

const int N = 1005;
__int64 b[N];
__int64 res[N];
bool f[N];

__int64 getCustomerNum(int bNum, __int64 minute) {
	__int64 cusNum = 0;
	for (int i = 0; i < bNum; i++) {
		res[i] = (minute-1)/b[i]+1;
		cusNum += res[i];
		if (minute%b[i] == 0) {
			f[i] = true;
		}
		else {
			f[i] = false;
		}
	}
	return cusNum;
}

int bsearch(int bNum, __int64 lMin, __int64 rMin, int n) {
	__int64 mid = (lMin+rMin)/2;
	__int64 cusNum2 = getCustomerNum(bNum, mid+1);
	__int64 cusNum = getCustomerNum(bNum, mid);
	if (cusNum <= n-1 && n-1 < cusNum2) {
		int cnt = n-cusNum;
		for (int i = 0; i < bNum; i++) {
			if (f[i] == true) {
				cnt--;
				if (cnt == 0) return i;
			}
		}
	}
	else if (n-1 < cusNum) {
		return bsearch(bNum, lMin, mid-1, n);
	}
	else {
		return bsearch(bNum, mid+1, rMin, n);
	}
}

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas ++) {
		int bNum, n;
		__int64 maxMinute = 0;
		scanf("%d%d", &bNum, &n);
		for (int i = 0; i < bNum; i++) {
			scanf("%d", b+i);
			if (b[i] > maxMinute) maxMinute = b[i];
		}
		__int64 right = maxMinute*n+1;
		int ans = bsearch(bNum, 0, right, n);
		printf("Case #%d: %d\n", cas, ans+1);
	}
	return 0;
}