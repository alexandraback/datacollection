// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
#include<queue>
#include<utility>
#include<array>

#include <limits>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

ll diff(ll a, ll b)
{
	return a > b ? a - b : b - a;
}
/*
#define COMB_NUM 3001L
ld comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
	comb[0][0] = 1;
	ll i, j;
	for (i = 1; i < COMB_NUM; i++)
	{
		comb[i][0] = comb[i][i] = 1;
		for (j = 1; j < i; j++)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
	}
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s, ll &a, ll &b)
{
	string replacedString = s;
	replace_if(replacedString.begin(),
		replacedString.end(),
		bind2nd(equal_to<char>(), '.'),
		' ');

	istringstream buffer(replacedString);
	buffer >> a;
	if (buffer.good())
	{
		buffer >> b;
	}
	else
	{
		b = 0;
	}
}


template<class T>
vector<T> split(const std::string &s) {

	string replacedString = s;
	replace_if(replacedString.begin(),
		replacedString.end(),
		bind2nd(equal_to<char>(), '.'),
		' ');

	vector<T> ret;
	istringstream buffer(replacedString);
	copy(istream_iterator<T>(buffer),
		istream_iterator<T>(), back_inserter(ret));
	return ret;
}// vector<ll> k = split<ll>(s);

int main()
{
	fstream in, out;
	//in.open("test.in.txt", ios::in);	out.open("test.out.txt", ios::out);
	//in.open("A-small-attempt2.in",ios::in); out.open("A-small-2.out",ios::out);
	in.open("A-large.in",ios::in); out.open("A-large-0.out",ios::out);
	istream& input = in;
	ostream& output = out;


	ll case_id, total_case;

	input >> total_case;
	ll I, H, K, ans;

	for (case_id = 1; case_id <= total_case; case_id++)
	{
		ll N;
		ll P[26];
		ll sum = 0;
		ll ind;
		ll temp = -1;
		ll ma;
		input >> N;
		for (I = 0; I < N; I++) {
			input >> P[I];
			sum += P[I];
		}
		//output << fixed;
		//output.precision(10);
		output << "Case #" << case_id << ": ";
		while (sum != 0) {
			ma = P[0];
			ind = 0;
			temp = -1;
			for (I = 1; I < N; I++) {
				if (P[I] > ma) {
					ma = P[I];
					ind = I;
					temp = -1;
				}
				else if (P[I] == ma) {
					temp = I;
				}
			}
			if (temp != -1 && sum != 3) {
				output << string(1, ind + 'A') << string(1, temp+'A')<<" ";
				sum -= 2;
				P[ind]--; P[temp]--;
			}
			else {
				output << string(1, ind + 'A') << " ";
				sum -= 1;
				P[ind]--;;
			}
		}
		//output << ans;
		output << endl;
	}
	return EXIT_SUCCESS;
}











