#include <iostream>
#include <vector>

using namespace std;

void doCase()
{
	int N;
	
	cin >> N;
	
	vector<int> amm(N,0);
	
	for (int i=0; i<N; i++)
	{
		cin >> amm[i];
	}
	
	int y=0;
	int maxGap = 0;
	
	for (int i=0; i<N-1; i++)
	{
		if (amm[i+1] < amm[i])
		{
			y += amm[i]-amm[i+1];
			maxGap = max(maxGap, amm[i]-amm[i+1]);
		}
	}
	
	int z = 0;
	
	for (int i=0; i<N-1; i++)
	{
		z += min(amm[i], maxGap);
	}
	
	cout << y << " " << z << endl;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cout << "Case #" << i+1 << ": ";
		doCase();
	}
	
	return 0;
}
