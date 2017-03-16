#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int p[26];

int getLargest(int n) {
	int max = 0;
	for(int i = 1; i < n; i++) {
		if(p[max] < p[i])
			max = i;
	}
	return max;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int t;
	cin >> t;
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		for(int i = 0; i < 26; i++)
			p[i] = 0;
		int n;
		cin >> n;
		
		int peopleRemaining = 0;
		for(int i = 0; i < n; i++) {
			int numPeople;
			cin >> numPeople;
			p[i] = numPeople;
			peopleRemaining += numPeople;
		}
		cout << "Case #" << caseNum << ":";
		
		while(peopleRemaining > 0) {
			int next = getLargest(n);
			char party = 'A' + next;
			cout << " " << party;
			p[next]--;
			peopleRemaining--;
			
			if(peopleRemaining > 0) {
				next = getLargest(n);
				if(p[next] > (peopleRemaining / 2)) {
					party = 'A' + next;
					cout << party;
					p[next]--;
					peopleRemaining--;
				}
			}
		}
		cout << endl;
	}
	return 0;
}