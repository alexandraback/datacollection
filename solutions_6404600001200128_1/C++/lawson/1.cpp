#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>

#define MAXN (10001)
using namespace std;

int t, n;
int m[MAXN];

int main () {
	ifstream in;
    in.open("in.txt");
    ofstream out;
    out.open("out.txt");
    in >> t;
    for (int j = 0 ; j < t ; ++j) {
    	in >> n;
    	int tmp;
		for (int i = 0 ; i < n ; ++i) {
    		in >> tmp;
    		m[i] = tmp;
		}
		int result1 = 0;
		int maxInteval = 0;
		for (int i = 1 ; i < n ; ++i) {
			tmp = m[i-1] - m[i];
			if (tmp > 0) {
				result1 += tmp;
				if (tmp > maxInteval) {
					maxInteval = tmp;
				}
			}
		}
		out << "Case #" << j+1 << ": " << result1 << " ";
		int result2 = 0;
		for (int i = n -1 ; i > 0 ; --i) {
			if (m[i-1] < maxInteval) {
				result2 += m[i-1];
			} else {
				result2 += maxInteval;
			}
		}
		out << result2 << endl;
	}
    
    in.close();
    out.close();
}
