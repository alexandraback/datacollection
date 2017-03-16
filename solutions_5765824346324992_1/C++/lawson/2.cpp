#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#define MAXB 1e14

using namespace std;

int t, b, n;
long long cutTime[1001]; 

long long find(long long start, long long end, long long n) {
	long long before = (start + end) / 2;
	long long after = before + 1;
	long long beforeNum = 0;
	long long afterNum = 0;
	
	for (int i = 0 ; i < b ; ++i) {
		beforeNum += before / cutTime[i] + 1;
		afterNum += after / cutTime[i] + 1;
	}
	
	if (before == 0 && beforeNum >= n) {
		return 0;
	}
	
	if (beforeNum < n && afterNum >= n) {
		return after;
	} else if (beforeNum >= n) {
		return find(start, before , n);
	} else {
		return find(after, end, n);
	}
}

int main () {
	ifstream in;
    in.open("in.txt");
    ofstream out;
    out.open("out.txt");
    in >> t;
    for (int i = 0 ; i < t ; ++i) {
    	in >> b >> n;
    	long long tmp;
		for (int j = 0 ; j < b ; ++j) {
    		in >> tmp;
    		cutTime[j] = tmp;
		}
    	long long time = find(0, MAXB, n);
    	long long beforeNum = 0;
		long long afterNum = 0;
		for (int j = 0 ; j < b ; ++j) {
			beforeNum += time / cutTime[j] + 1;
			afterNum += time / cutTime[j] + 1;
		}
		long long num = afterNum - n + 1;
		int result = 0;
		for (int j = b - 1 ; j >= 0 ; --j) {
			if (time % cutTime[j] == 0) {
				num --;
				if (num == 0) {
					result = j;
					break;
				}
			}
		}
		
		out << "Case #" << i + 1 << ": " << result + 1 << endl;
	}
    in.close();
    out.close();
}
