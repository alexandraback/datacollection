#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <discreture/discreture.hpp>

using namespace std;
// using namespace dscr;

template <class T> 
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
	for (const auto& x : rhs)
		os << x << " ";
	return os;
}


int NumNonZero(const vector<int>& A)
{
	int b = 0;
	for (auto a : A)
	{
		if (a != 0)
			++b;
	}
	return b;
}

void Solve(vector<int> A)
{
// 	cout << "A = " << A << endl;
	int n = A.size();
	vector<int> W(n,0);
	for (int i = 0; i < n; ++i)
	{
		W[i] = i;
	}
	sort(W.begin(), W.end(), [&A](int a, int b) -> bool
	{
		return A[a] > A[b];
	});
// 	cout << endl << "A = " << A << endl;
// 	cout << "W = " << W << endl;
	
	if (A[W[0]] == 0)
		return;
	
	if (A.size() == 2 || A[W[2]] == 0)
	{
		for (int i = 0; i < A[W[0]]; ++i)
		{
			cout << char(W[0]+65) << char(W[1]+65) << " ";
		}
		return;
	}
	
	if (A[W[0]] > A[W[1]])
	{
		cout << char(W[0]+65) << char(W[0]+65) << " ";
		--A[W[0]];
		--A[W[0]];
		Solve(A);
		return;
	}
	
	if (A[W[0]] == 1)
	{
// 		cout << "A = " << A << endl;
		cout << char(W[0]+65) << " ";
		--A[W[0]];
		Solve(A);
		return;
	}
	
	if (A[W[0]] == A[W[1]])
	{
		cout << char(W[0]+65) << char(W[1]+65) << " ";
		--A[W[0]];
		--A[W[1]];
		Solve(A);
		return;
	}
	
	
}

int main() 
{
	int T;
	cin >>T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		vector<int> A(N,0);
		for (int j = 0; j < N; ++j)
			cin >> A[j];
		cout << "Case #" << i+1 << ": ";
// 		cout << endl << "A = " << A << endl << "S = " << endl;
		Solve(A);
		cout << endl;
	}
	
	return 0;
}
