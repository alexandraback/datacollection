#include <fstream>
#include <string>
#include <algorithm>

long t;
long n;
long m[10000];
long first;
long second;
long prev;
long d;
long mx;

int main() {
	std::ifstream in(".in");
	std::ofstream out(".out");

	in >> t;
	for (int i = 0; i < t; ++i){
		in >> n;
		first = 0;
		second = 0;
		
		mx = 0;

		for (int j = 0; j < n; ++j){
			in >> m[j];
			if (j > 0){
				mx = std::max(mx, m[j - 1] - m[j]);
			}
		}

		for (int j = 1; j < n; ++j) {
			if (m[j - 1] - m[j] > 0){
				first += m[j - 1] - m[j];
			}
		}

		for (int j = 0; j < n - 1; ++j){
			second += std::min(m[j], mx);
		}

		out << "Case #" << i + 1 << ": " << first << ' ' << second << '\n';
	}
	in.close();
	out.close();
}