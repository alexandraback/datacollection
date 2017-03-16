#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int T;
int n, total;
int cnt[30];

char extract_max()
{
	int mi = 0;
	for (int i=0; i<n; i++)
		if (cnt[i] > cnt[mi])
			mi = i;
			
	cnt[mi]--;
	total--;
	
	return 'A' + mi;
}

bool try_extract_max()
{
	int mi = 0;
	for (int i=0; i<n; i++)
		if (cnt[i] > cnt[mi])
			mi = i;
			
	cnt[mi]--;
	total--;
	
	int mi2 = 0;
	for (int i=0; i<n; i++)
		if (cnt[i] > cnt[mi2])
			mi2 = i;
			
	bool result = cnt[mi2] <= total/2;
	
	cnt[mi]++;
	total++;
	
	return result;
}

int main() 
{
	cin >> T;
	
	for (int tc=1; tc<=T; tc++) {
		cin >> n;
		total = 0;
		for (int i=0; i<n; i++) {
			cin >> cnt[i];
			total += cnt[i];
		}
			
		cout << "Case #" << tc << ":";
		while (total > 0) {
			char f = extract_max();
			char s = '!';
			if (try_extract_max())
				s = extract_max();
				
			if (s == '!')
				cout << ' ' << f;
			else
				cout << ' ' << f << s;
		}
		
		cout << endl;
	}
	
	return 0;
}
