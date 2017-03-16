#include <iostream>

using namespace std;

int barbers[1000];
int barber_order[100000000];

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int b,n;
		cin >> b >> n;
		for (int i = 0; i < b; i++)
			cin >> barbers[i];
		
		int gcd_bar = barbers[0];
		for (int i = 1; i < b; i++)
			gcd_bar = gcd(gcd_bar, barbers[i]);
		int time_loop = 1;
		for (int i = 0; i < b; i++)
			time_loop *= barbers[i]/gcd_bar;
		int order_end = 0;
		for (int i = 0; i < time_loop; i++)
			for (int j = 0; j < b; j++)
				if (i * gcd_bar % barbers[j] == 0)
					barber_order[order_end++] = j;
		
		cout << "Case #" << t1 << ": " << barber_order[(n-1)%(order_end)]+1 << endl;
		
		for (int i = 0; i < b; i++)
			barber_order[i] = 0;
	}
}
