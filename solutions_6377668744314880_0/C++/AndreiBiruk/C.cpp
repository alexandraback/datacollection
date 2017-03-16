#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

long long x[3000], y[3000];
long n;
long T;
long long ans;
long long a, b, c;
long long c1, c2;

int main() {
	std::ifstream in(".in");
	std::ofstream out(".out");

	in >> T;

	for (int t = 1; t <= T; ++t) {
		in >> n;
		for (int i = 0; i < n; ++i){
			in >> x[i] >> y[i];
		}
		out << "Case #" << t << ':' << '\n';
		for (int i = 0; i < n; ++i) {
			ans = 1000000000;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				a = y[i] - y[j];
				b = x[j] - x[i];
				c = -a * x[i] - b * y[i];
				c1 = 0;
				c2 = 0;
				for (int k = 0; k < n; ++k){
					if (k == i || k == j) continue;
					if (a * x[k] + b * y[k] + c > 0) c1++;
					if (a * x[k] + b * y[k] + c < 0) c2++;
 				}
				ans = std::min(ans, std::min(c1, c2));
			}
			if (n <= 3) out << 0 << '\n'; else out << ans << '\n';
		}
	}

	in.close();
	out.close();
	return 0;
}