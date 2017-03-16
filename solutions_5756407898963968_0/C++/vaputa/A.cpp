#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int T, n;

int main(){
	cin >> T;
	for (int testcase = 1; testcase <=T; ++testcase){
		int x, count = 0, number = -1;
		set<int> v;
		cin >> n;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j){
				cin >> x;
				if (i + 1 == n)
					v.insert(x);
			}
		cin >> n;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j){
				cin >> x;
				if (i + 1 == n)
					if (v.count(x)){
						++count;
						number = x;
					}
			}
		cout << "Case #" << testcase << ": ";
		if (count == 0)
			cout << "Volunteer cheated!" << endl;
		else 
			if (count == 1)
				cout << number <<endl;
			else
				cout << "Bad magician!" << endl;
	}
	return 0;
}