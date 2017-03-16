#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

long long m[2000];
long long b;

long long  calc(long long time){
	long long all = 0;
	for(int i = 0; i < b; i++){
		all += time / m[i] + 1;
	}
	return all;
}

int main()
{
	string letters;
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int result;
		long long n;
		cin >> b >> n;
		long long  maxTime = 0;
		for(int i= 0; i < b; i++){
			cin >> m[i];
			if (m[i] > maxTime)
				maxTime = m[i];
		}
		long long high = maxTime * n;
		long long low = 0;
		long long mid;
		while(true){
			mid = (high + low) / 2;
			long long cutted = calc(mid);
			long long cutted1 = calc(mid - 1);
			if (cutted < n )
				low = mid + 1;
			else if(cutted1 >= n)
				high = mid - 1;
			else
				break;
		}
		long long temp = calc(mid - 1);
		long long number = n - temp;
		for(int i = 0; i < b; i++){
			if (mid % m[i] == 0){
				result = i + 1;
				number--;
			}
			if (number == 0)
				break;
		}
		cout << "Case #" << tt << ": " << result << endl;
	}
	return 0;
}