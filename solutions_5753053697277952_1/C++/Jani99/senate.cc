#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

unsigned getMax(const std::vector<int>& sv) {
	unsigned max = 0;
	for (unsigned i=1;i<sv.size();++i) {
		if (sv[max] < sv[i]) {
			max = i;
		}
	}
	return max;
}

int main(int argc, char **argv) {

	unsigned T;
	std::cin >> T;

	for (unsigned i=0; i<T; ++i) {
		unsigned S;
		std::cin >> S;

		unsigned N = 0;
		std::vector<int> sv;

		for (unsigned j=0;j<S;++j) {
			unsigned n;
			std::cin >> n;
			N+=n;
			sv.push_back(n);
		}

		printf("Case #%d: ",i+1);

		while (N>0) {
			unsigned ix1 = getMax(sv);
			--N;
			--sv[ix1];
			printf("%c",'A'+ix1);

			if (N == 0) {
				break;
			}

			unsigned ix2 = getMax(sv);
			--N;
			--sv[ix2];

			if (getMax(sv)*2 > N) {
				++N;
				++sv[ix2];
				printf(" ");
				continue;
			}
			printf("%c ",'A'+ix2);
		}

		printf("\n");
	}

	return 0;
}








