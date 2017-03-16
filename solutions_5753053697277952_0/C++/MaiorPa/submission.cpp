#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#define ll long long
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

bool sf(pair<char, int>a, pair<char, int>b){
	return a.second > b.second;
}

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		ll t, n, k, f, m1, m2, sum;
		ofstream ttt;
		ttt.open("output.out");
		in >> t;
		for (int ii = 1; ii <= t; ii++)
		{
			ttt << "Case #" << ii << ":";
			in >> n;
			sum = 0;
			vector< pair<char,int> > p(30);
			for (int i = 0; i < n; i++)
			{
				in >> p[i].second;
				p[i].first = 'A' + i;
				sum += p[i].second;
			}
			while (1>0){
				sort(p.begin(), p.end(), sf);
				if (p[0].second == 0)break;
				if ((p[1].second != p[0].second)
					|| ((p[1].second == p[0].second) && (p[1].second == p[2].second))){
					ttt << " " << p[0].first;
					p[0].second--;
				}
				else
				{
					ttt << " " << p[0].first << p[1].first;
					p[0].second--;
					p[1].second--;
				}
			}
			ttt << endl;
		}

    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}

#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;
    solve(in, out);
    return 0;
}
