#include <bits/stdc++.h>
#define pp pair<int,int>
#define mp make_pair
#define INF 100000000

using namespace std;

int lcm(int a, int b) {
	int c=a*b;
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}

	return c/a;
}

int main() {
	int T, final;
	cin >> T;
	final = T;
	while(T>0) {
		T--;
		int B, N;
		cin >> B >> N;
		std::vector<int> cutTime;
		int roundTime = 0;
		for (int i = 0; i < B; ++i)
		{
			int temp;
			cin >> temp;
			cutTime.push_back(temp);
			if(i!=0) {
				roundTime = lcm(roundTime, temp);
			}
			if(i==0) {
				roundTime = temp;
			}
		}
		// cout << "roundTime " << roundTime << endl;
		std::map<int, int> alloc;
		int t = 0;
		int nCurr = 1;
		set<pp> timeLine;
		int ans = -1;
		for (int i = 0; i < B; ++i)
		{
			pp temp = mp(cutTime[i],i+1);
			alloc[nCurr] = i+1;
			nCurr++;
			timeLine.insert(temp);
		}

		// for(auto it = timeLine.begin(); it!=timeLine.end(); it++) {
		// 	cout << it->first << " " << it->second << endl;
		// }
		
		while(!timeLine.empty()) {
			auto start = timeLine.begin();
			t = (*start).first;
			// cout << "time " << t << endl;
			if(t >= roundTime) break;
			while(start != timeLine.end() && (*start).first == t) {
				// cout << "time " << t << " pair: " << start->second << " N-curr: " << nCurr << endl;
				int barber = start->second;
				if(nCurr == N) {
					ans = barber;
					//break;
				}
				alloc[nCurr] = barber;
				pp temp = mp(t+cutTime[barber-1], barber);
				timeLine.insert(temp);
				nCurr++;
				start++;
			}
			// if(ans != -1) break;
			timeLine.erase(timeLine.begin(), start);
		}

		int size = 0;
		for(auto it = alloc.begin(); it!=alloc.end(); it++) {
			// cout << it->first << " " << it->second << endl;
			size++;
		}

		cout << "Case #" << final-T << ": " << alloc[(N%size==0) ? size : N%size] << endl;

	}

}