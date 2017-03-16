#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

void solve (int k)
{
	int i,j,ans1,ans2;
	cin >> ans1;
	int arr1[4][4], arr2[4][4];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			cin>>arr1[i][j];
	cin >> ans2;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			cin>>arr2[i][j];
	int kol[17];
	for (i = 0; i <= 16; i++) kol[i] = 0;
	for (j = 0;  j < 4; j++) kol[arr1[ans1 - 1][j]]++;
	for (j = 0;  j < 4; j++) kol[arr2[ans2 - 1][j]]++;
	vector <int> res;
	for (i = 1; i <= 16; i++)
		if (kol[i] == 2)
			res.push_back(i);
	cout << "Case #" << k << ": ";
	//for (i=1; i<=16; i++) cout<<kol[i]<<" ";
	if (res.size() == 1) cout<<res[0];
	else if (res.size() > 1) cout << "Bad magician!";
	else cout << "Volunteer cheated!";
	cout<<endl;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin >> t;
	for (i = 1; i <= t; i++) solve(i);
	return 0;
}