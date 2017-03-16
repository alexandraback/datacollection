#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
ld start_time,end_time;

string BADMAG = "Bad magician!";
string CHEATED = "Volunteer cheated!";

string solve() {
	int f,tmp;
	vector <int> nums1, nums2;
	for (int z = 0; z < 2; ++z) {
		cin >> f;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> tmp;
				if (i+1==f && z) {
					nums2.push_back(tmp);
				} else if (i+1==f) {
					nums1.push_back(tmp);
				}
			}
		}
	}
	vector<int> result_set;
	result_set.resize(16);
	sort(all(nums1));sort(all(nums2));
	vector<int>::iterator it = set_intersection(all(nums1),all(nums2),result_set.begin());
	result_set.resize(it-result_set.begin());
	if (result_set.size() == 1)
	{
		stringstream ss; ss<<*(result_set.begin());
		return ss.str();
	}
	if (result_set.size() == 0) {
		return CHEATED;
	}
	if (result_set.size() >= 2) {
		return BADMAG;
	}
	return "ELSE";
}



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test ,solve().c_str()); 
	}


	//end program
	//end_time=get_time()-start_time;
	return 0;
}




