#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDrawdown(vector<int> seq)
{
    int maxDiff = 0;
    for (int i = 0; i < seq.size()-1; i++)
    {
	if (seq[i] - seq[i+1] > maxDiff)
	{
	    maxDiff = seq[i] - seq[i+1];
	}
    }
    return maxDiff;
}

int main()
{
    int numCases;
    cin >> numCases;
    for (int c = 1; c <= numCases; c++)
    {
	int n;
	cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; i++)
	{
	    cin >> seq[i];
	}
	int method1 = 0;
	for (int i = 0; i < n-1; i++)
	{
	    if (seq[i+1] < seq[i])
	    {
		method1 += seq[i] - seq[i+1];
	    }
	}
	int method2 = 0;
	int rate = maxDrawdown(seq);
	for (int i = 0; i < n-1; i++)
	{
	    method2 += min(rate, seq[i]);
	}
	cout << "Case #" << c << ": " << method1 << " " << method2 << endl;
    }
}
