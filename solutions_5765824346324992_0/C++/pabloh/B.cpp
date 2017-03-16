#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

inline long long cc(const vector<int> & M, long long t)
{
	const size_t B = M.size();
	long long res = 0;
	FOR(i,B) res += t/M[i];
	return res;
}

int solve_case(const vector<int> & M,  int N)
{
	const size_t B = M.size();

	int m0 = *min_element(M.begin(), M.end());

	long long a = 0, b = m0; b *= N;
	long long t = (a+b)/2; 
	long long c0 = cc(M,t);
	long long c1 = cc(M,t+m0);
	while (!(c0 < N-1 && c1 >= N-1)) {
		if (c1 < N-1) a = t;
		else { assert(c0 >= N-1); b = t; }
		t = (a+b)/2; 
		c0 = cc(M,t);
		c1 = cc(M,t+m0);
	}
	assert(c0 < N-1 && c1 >= N-1);

	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
	FOR(i,B) q.push( make_pair((t) % M[i],i) );

	int res = -1;
	while (c0 < N)
	{
		pair<int,int> s = q.top(); q.pop();
		++c0;
		s.first += M[s.second];
		res = s.second+1;
		q.push(s);
	}
	//FOR(i,B) { 
	//	if ((t) % M[i] == 0) {
	//		++c0;
	//		if (c0 == N){
	//			res = i+1; 
	//			break; 
	//		}
	//	}
	//}
	return res;
}

int dcm(int a, int b)
{
	if (a < b) swap(a,b);
	while (b != 0) {
		int c = a%b; a = b; b = c;
	}
	return a;
}

int mcm(const vector<int> & M)
{
	int res = M[0];
	for (size_t i = 1;  i < M.size(); ++i) {
		int d = dcm(res,M[i]);
		res = res*M[i]/d;
	}
	return res;
}

int solve_case_slow(const vector<int> & M,  int N)
{
	const size_t B = M.size();

	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
	FOR(i,B) q.push( make_pair(0,i) );
	int MM = 1;
	//FOR(i,B) MM *= M[i];
	MM = mcm(M);
	int QQ = 0;
	FOR(i,B) QQ += MM / M[i];
	N = (N-1) % QQ + 1;

	for (int c = 1; c < N; ++c) {
		pair<int,int> t = q.top(); q.pop();
		t.first += M[t.second];
		q.push(t);
	}

	int res = q.top().second + 1;
	return res;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		cout << "Case #" << t << endl;
		int B, N;
		in >> B >> N; cout << B << ' ' << N << '\n';
		vector<int> M(B);
		FOR(i,B) { in >> M[i]; } show(M);

		int result = N <= B ? B : solve_case_slow(M, N);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//for (int a = 1; a < 19; ++a){

	//	for (int b = 1; b < 19; ++b)
	//		cout << dcm(a,b) << '\t';
	//	cout << endl;
	//}
	//return 0;
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt1.in");
	ofstream out("B-small-attempt1-out.txt");

	//ifstream in("B-large.in");
	//ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
