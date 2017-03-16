#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stack>

using namespace std;

int counter = 0;


int game(vector<string> &list, int num) {
	
	if (list.size() < 1) return -1;
	
	//int result;
	
	string ch;
	// vector<vector<int> > rep(num, vector<int>);
	vector<vector<int> > rep(num);
	// int n = 0;
	//char pre = '';
	
	char pre = list[0][0];
	ch.push_back(pre);	
	int n = 1;
	
	for (int j=1; j<list[0].size(); ++j) {
		if (pre != list[0][j]) {
			rep[0].push_back(n);
			n = 1;
			ch.push_back(list[0][j]); // next
		} else {
			n += 1;
		}
		pre = list[0][j];
	}
	rep[0].push_back(n);
	
	// for (int i=0; i<ch.size(); i++)
	// 	cout << ch[i] << endl;

	int mn = ch.size();	
	for (int i=1; i<num; ++i) {
		
		// n = 0;
		// l = 0;
		// for (int j=0; j<list[i].size(); ++j) {
		// 	
		// 	if ( l < mn && list[j] == cha[l]) n += 1;
		// 	else if ( l<mn-1 && list[j] == cha[l+1] && n != 0) {
		// 		rep[i].push_back(n);
		// 		n = 0;
		// 		l += 1;
		// 	} else if ( l==mn-1 && n != 0) {
		// 		rep[i].push_back(n);
		// 		n = 0;
		// 		l += 1;
		// 	}
		// 	 else return -1;
		// }
		string temp;
		pre = list[i][0];
		n = 1;
		
		temp.push_back(pre);	
		for (int j=1; j<list[i].size(); ++j) {
			if (pre != list[i][j]) {
				rep[i].push_back(n);
				n = 1;
				temp.push_back(list[i][j]); // next
			} else {
				n += 1;
			}
			pre = list[i][j];
		}
		rep[i].push_back(n);
		
		if (ch != temp) return -1;
	}
	
	
	int result = 0;
	for (int i=0; i<mn; ++i) {
		
		vector<int> se(num);
		for (int j=0; j<num; j++)
			se[j] = rep[j][i];
		
		sort(se.begin(), se.end());
		
		for (int j=0; j<num; j++)
			result += abs(se[num/2] - se[j]);
	}
	
	
	return result;
}

void process() {
	int ns;
	cin >> ns;
	
	vector<string> list(ns);
	
	for (int i=0; i<ns; ++i)
		cin >> list[i];	
	
	int result = game(list, ns);
	
	if (result == -1) cout << "Case #" << ++counter << ": " << "Fegla Won" << endl;
	else cout << "Case #" << ++counter << ": " << result << endl;
	
	//"Fegla Won"
	
	return;
}


int main() {
	int t;
	scanf("%d", &t); // read the number of cases
	
	while (t--) process();

	return 0;
}