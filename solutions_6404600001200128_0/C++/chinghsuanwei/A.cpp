#include <iostream>
#include <algorithm>  
using namespace std;

int main()
{
	FILE *input;
	FILE *output;
	freopen_s(&input, "A-small-attempt0.in", "r", stdin);
	freopen_s(&output, "A-small-attempt0.out", "w", stdout);

	int T;
	cin >> T;

	int plates[10000];

	for (int i = 1; i <= T; i++){
		int N;
		cin >> N;
		for (int j = 0; j < N; j++){
			cin >> plates[j];
		}

		

		int y = 0;
		for (int j = 0; j < N-1; j++){
			int p = plates[j] - plates[j+1];
			if (p > 0) y += p;			
		}

		int max = 0;
	
		for (int j = 0; j < N - 1; j++){
			int p = plates[j] - plates[j + 1];
			if (p > max) max = p;
		}
		
		int z = 0;

		for (int j = 0; j < N - 1; j++){
			z += min(max, plates[j]);
		}

		cout << "Case #" << i << ": " << y << " " << z << endl;
	}

	//system("pause");
}