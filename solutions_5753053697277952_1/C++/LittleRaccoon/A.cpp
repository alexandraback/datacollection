#include <queue>
#include <iostream>

using namespace std;

struct Party
{
	int n;
	char rep;
};

bool operator < (const Party &A, const Party &B)
{
	return A.n < B.n;
}

int N, NS;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		priority_queue<Party> pq;

		cin >> N;
		for (int i = NS = 0; i < N; i++) {
			Party p;
			cin >> p.n;
			p.rep = i + 'A';
			NS += p.n;
			pq.push(p);
		}

		bool printed = false;
		cout << "Case #" << t << ": ";
		while (!pq.empty()) {
			Party p = pq.top(); pq.pop();

			if (printed) cout << " ";
			printed = true;

			cout << p.rep;
			p.n -= 1; NS -= 1;
			if (p.n) pq.push(p);
			
			if ((p.n && pq.size() == 2 || p.n == 0 && pq.size() == 1) && NS - p.n > NS / 2) {
				p = pq.top(); pq.pop();
				cout << p.rep;
				p.n -= 1; NS -= 1;
				if (p.n) pq.push(p);
			}
		}
		cout << endl;
	}

	return 0;
}

