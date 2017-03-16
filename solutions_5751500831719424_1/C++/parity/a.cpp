#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<tr1/unordered_map>
#include<set>
#include<tr1/unordered_set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T, N;

int num[100][100];

string s;

int nnode;

string normalize(string x, int idx){

	int len = x.size();

	string ret = "";
	int ndiff = -1;

	for(int pos = 0; pos < len; pos++){

		if(!pos || x[pos] - x[pos - 1]){

			num[idx][++ndiff] = 1;
			ret.push_back(x[pos]);
		}
		else num[idx][ndiff]++;
	}

	nnode = ndiff + 1;

	return ret;
}

int main()
{
	cin >> T;

	for(int caseidx = 1; caseidx <= T; caseidx++){

		cin >> N;

		long long ret = 0;

		string pre;
		bool bad = false;
		for(int i = 0; i < N; i++){
			string t;
			cin >> t;
			string s = normalize(t, i);

			if(!i)	pre = s;
			if(i && pre != s)bad = true;
		}

		if(bad)	goto done;


		for(int i = 0; i < nnode; i++){

			vector<int> v;
			for(int j = 0; j < N; j++)
				v.push_back(num[j][i]);

			sort(v.begin(), v.end());

			int val = v[N >> 1];

			for(int j = 0; j < N; j++)
				ret += ABS(val - num[j][i]);
		}

		printf("Case #%d: %lld\n", caseidx, ret);
		continue;
done:

		printf("Case #%d: Fegla Won\n", caseidx);
	}
	return 0;
}

// vi: ts=2 sw=2
