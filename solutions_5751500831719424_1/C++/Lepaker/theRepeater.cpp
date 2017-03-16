#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <vi> vvi;
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int tc,N,count = 0;
	cin >> tc;
	while (tc--) {
		int numMove = 0;
		cin >> N;
		vs str = vs(N), shortStr = vs(N,"");
		vvi segment = vvi(N,vi());
		bool fw = true;
		for (int i=0;i<N;i++) {
			cin >> str[i];
			shortStr[i] += str[i][0];
			segment[i].push_back(0);
			for (int j=1; j<(int)str[i].length(); j++) {
				if (str[i][j] != str[i][j-1]) {
					shortStr[i] += str[i][j];
					segment[i].push_back(j);
				}
			}
			segment[i].push_back(str[i].size());
		}
		for (int i=1; i<N; i++)
			if (shortStr[i] != shortStr[i-1]) fw = false;
		if (!fw) cout << "Case #" << ++count << ": Fegla Won" << endl;
		else {
			/*for (int i=0;i<N;i++) {
				cout << str[i] << " " << shortStr[i] << " ";
				for (int j=0; j<(int)segment[i].size(); j++) cout <<segment[i][j] << " ";
				cout << endl;
			}*/
			for (int i=1; i<(int)segment[0].size(); i++) {
				int temp = 100000;
				for (int norm = 1; norm <= 100; norm++) {
					int nt = 0;
					for (int j=0; j<N; j++) {
						nt += abs((segment[j][i] - segment[j][i-1]) - norm);
					}
					temp = min(temp,nt);
				}
				numMove += temp;
				//cout << "DEBUG: " << numMove << endl;
			}
			cout << "Case #" << ++count << ": " << numMove << endl; 
		}
	}
}
