#include <bits/stdc++.h>
using namespace std;

int B, N;
int M[1005];

int MCD(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int mcm(int a, int b)
{
    int temp = MCD(a, b);

    return temp ? (a / temp * b) : 0;
}

int solve() {
	cin >> B >> N;
	for (int i = 0; i < B; i++) cin >> M[i];
	
	
	int step = M[0];
	int chunk = M[0];
	for (int i = 1; i < B; i++)
		chunk = mcm(chunk, M[i]), step = MCD(step, M[i]);
	
	int n_chunk = 0;
	for (int i = 0; i < B; i++)
		n_chunk += chunk / M[i];
	
	N = (n_chunk+N-1)%n_chunk;
	
	//printf("n_chunk = %d, step = %d, chunk = %d, N = %d\n\n", n_chunk, step, chunk, N);
	
	int t = 0;
	int pos = 0;
	while (true) {
		for (int i = 0; i < B; i++) {
			if (t % M[i] == 0) {
				//cout << "Tipo " << pos << " da " << i+1 << endl;
				if (pos == N)
					return i+1;
				pos++;
			}
		}
		t += step;
	}		
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cerr << "Caso " << t << "/" << T << endl;
		cout << "Case #" << t << ": " << solve() << endl;
	}
}
