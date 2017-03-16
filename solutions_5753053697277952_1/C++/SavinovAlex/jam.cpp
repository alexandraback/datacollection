#define  _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

typedef long long ll;
typedef unsigned int ui;
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >

#define veceach(v) for(uint i = 0;i < (v).size();i++)
#define veceach2(v,i) for(uint i = 0;i < (v).size();i++)
using namespace std;

void main () {
	int T, n;

	FILE *f_in, *f_out;
	f_in = fopen("data.txt","r");	
	f_out = fopen("output.txt","w");	
	fscanf(f_in,"%d",&T);

	
	for (int t = 0; t < T; ++t) {
		fscanf(f_in, "%d", &n);

		vi ch(n), ch1(n, 0);
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int d;
			fscanf(f_in, "%d", &d);
			sum += d;
			ch[i] = d;
		}

		vector<string> res;
		int lastEven = 0;
		int curSum = 0;

		while (curSum < sum) {
			int lowest = -1, lowest2 = -1;
			for (int i = 0; i < n; i++) {
				if (ch1[i] < ch[i] && (lowest == -1 || ch1[lowest] > ch1[i]))
					lowest = i;
			}
			curSum++;
			ch1[lowest]++;

			if (curSum < sum) {
				for (int i = 0; i < n; i++) {
					if (ch1[i] < ch[i] && (lowest2 == -1 || ch1[lowest2] > ch1[i]))
						lowest2 = i;
				}
				curSum++;
				if (lowest2 != -1)
					ch1[lowest2]++;
			}

			string s;
			s = 'A' + lowest;
			if (lowest2 != -1)
				s += 'A' + lowest2;

			res.push_back(s);
		}
	

		fprintf(f_out, "Case #%d: ", t+1);

		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			fprintf(f_out, "%s ", res[i].c_str());
		}
		fprintf(f_out, "\n");

	}
	
}