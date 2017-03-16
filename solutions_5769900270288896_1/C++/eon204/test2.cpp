#include <bits/stdc++.h>

using namespace std;

int solve(int r, int c, int n) {
	int ans = 0;
	if (r == 1 || c == 1) {
		int notone;
		if (r == 1) {
			notone = c;
		}
		else {
			notone = r;
		}
		n -= (notone+1)/2;
		if (n <= 0) return 0;
		
		if (notone % 2 == 0) {
			n--;
			ans += 1;
			if (n == 0) return ans;
		}
		
		int canuse = (notone - 1) / 2;
		while (canuse > 0 && n > 0) {
			n--;
			canuse--;
			ans += 2;
		}
		return ans;
	}
	else if (r % 2 == 0 && c % 2 == 0) {
		n -= (r*c) / 2;
		if (n <= 0) return 0;	// no conflict
		
		if (n == 1) return 2;
		if (n == 2) return 4;	// +2
		
		ans += 4;
		n -= 2;
		
		int canuse = r-2+c-2;
		while (n > 0 && canuse > 0) {
			ans += 3;
			n--;
			canuse--;
		}
		if (n == 0) return ans;
		
		canuse = (r*c)/2 - 2 - (r-2+c-2);
		while (n > 0 && canuse > 0) {
			ans += 4;
			n--;
			canuse--;
		}
		return ans;
	}
	else if (r%2 == 1 && c%2 == 1) {
		int canuse = ((r*c)/2);
		while (canuse > 0 && n > 0) {
			canuse--;
			n--;
		}
		if (n == 0) return 0;
		int nc = n;
		
		// method 1: place with more zeroes
		int ans1 = 0;
		n--;
		canuse = (r-1) + (c-1);
		while (n > 0 && canuse > 0) {
			ans1 += 3;
			canuse--;
			n--;
		}
		canuse = (r*c) - ((r*c)/2) - 1 - ((r-1) + (c-1));
		while (n > 0 && canuse > 0) {
			ans1 += 4;
			canuse--;
			n--;
		}
		
		// method 2: place with 1 less zero
		int ans2 = 0;
		canuse = 4;
		while (nc > 0 && canuse > 0) {
			nc--;
			canuse--;
			ans2+=2;
		}
		
		canuse = 2*(r/2+1) + 2*(c/2+1) - 8;
		while (nc > 0 && canuse > 0) {
			nc--;
			canuse--;
			ans2+=3;
		}
		
		canuse = (r*c) - ((r*c)/2) - 4 - (2*(r/2+1) + 2*(c/2+1) - 8);
		while (nc > 0 && canuse > 0) {
			nc--;
			canuse--;
			ans2+=4;
		}
		
		return min(ans1, ans2);
	}
	else if ((r%2 == 1 && c%2 == 0) || (r%2 == 0 && c%2 == 1)) {
		int odd, even;
		if (r%2 == 1) {
			odd = r;
			even = c;
		}
		else {
			odd = c;
			even = r;
		}
		
		n -= (odd*even)/2;
		if (n <= 0) return 0;
		
		if (n == 1) return 2;
		if (n == 2) return 4;	// +2
		
		ans += 4;
		n -= 2;
		
		int canuse = (odd/2) + ((odd+1)/2-2) + 2*(even/2-1);
		while (n > 0 && canuse > 0) {
			ans += 3;
			n--;
			canuse--;
		}
		if (n == 0) return ans;
		
		canuse = (odd*even) - (odd*even/2) - 2 - ((odd/2) + ((odd+1)/2-2) + 2*(even/2-1));
		while (n > 0 && canuse > 0) {
			ans += 4;
			n--;
			canuse--;
		}
		return ans;
	}
	
	
	return ans;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, tc, r, c, n;
	scanf("%d", &tc);
	for (int xx = 1; xx <= tc; xx++) {
		scanf("%d%d%d", &r, &c, &n);
		cout << "Case #" << xx << ": " << solve(r, c, n) << "\n";
	}
	
	
	
	return 0;
}
