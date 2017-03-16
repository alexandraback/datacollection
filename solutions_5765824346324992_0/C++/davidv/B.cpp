#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

long long calcHelped(long long T, vector<int> &barbers)
{
	long long res = 0;
	for (int i=0; i<barbers.size(); i++)
		res += (T+barbers[i])/barbers[i];
	return res;
}

void doCase()
{
	long long N;
	int B;
	
	cin >> B >> N;
	
	vector<int> barbers(B, 0);
	
	for (int i=0; i<B; i++)
		cin >> barbers[i];
	
	int minBarb = barbers[0];
	for (int i=0; i<B; i++)
		minBarb = min(minBarb, barbers[i]);
	
	long long high = N*minBarb;
	long long low = -1;
	
	while (high-low > 1)
	{
		long long mid = (high+low)/2;
		long long NT = calcHelped(mid, barbers);
		
		if (NT < N)
			low = mid;
		else
			high = mid;
	}
	
	long long overShoot = calcHelped(high, barbers) - N;
	long long nth = calcHelped(high, barbers)-calcHelped(high-1, barbers) - overShoot;
	
	for (int i=0; i<B; i++)
	{
		if (high%barbers[i] == 0)
		{
			nth--;
			if (nth == 0)
			{
				cout << i+1 << endl;
				return;
			}
		}
	}
	
	assert(0);
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
