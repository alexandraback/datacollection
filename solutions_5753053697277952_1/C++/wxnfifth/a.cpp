#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace::std;

struct S{
	int num;
	int pos;
	bool operator<(const S& o) const{
		return num > o.num;
	}
};

int main() 
{
	FILE* file_in = fopen("A-large.in","r");
	FILE* file_out = fopen("A-large.out","w");
	int n_case;
	fscanf(file_in,"%d",&n_case);
	for (int i_case = 0; i_case < n_case; ++i_case) {
		printf("i%d\n", i_case);
		int n;
		fscanf(file_in, "%d", &n);
		vector<S> s(n);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			fscanf(file_in, "%d", &s[i].num);
			s[i].pos = i;
			cnt += s[i].num;
		}
		fprintf(file_out, "Case #%d:", i_case + 1);
		while (cnt > 0) {
			sort(s.begin(), s.end());
			if (cnt % 2 == 1) {
				fprintf(file_out, " %c", s[0].pos + 'A');
				s[0].num--;
				cnt--;
			} else {
				fprintf(file_out, " %c%c", s[0].pos + 'A', s[1].pos + 'A');
				s[0].num--;
				s[1].num--;
				cnt -= 2;
			}
			if (cnt == 0) {
				break;
			}
		}
		fprintf(file_out, "\n");




		

	
	}


	
	fclose(file_out);
	fclose(file_in);

	system("pause");
	return 0;
}