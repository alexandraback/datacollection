#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	ifstream in("A-large.in");
	ofstream out("A.out");
	int T;
	in >> T;
	for (int z = 1 ; z <= T ; z++)
	{
		int n;
		in >> n;
		int a[n];
		for (int i = 0 ; i < n ; i++)
		{
			in >> a[i];
		}
		int count1 = 0;
		int rate = 0;
		for (int i = 1 ; i < n ; i++)
		{
			if (a[i] < a[i - 1])
			{
				count1 += a[i - 1] - a[i];
				rate = max(rate, a[i - 1] - a[i]);
			}
		}
		int count2 = 0;
		for (int i = 0 ; i < n - 1 ; i++)
		{
			count2 += min(rate, a[i]);
		}
		out << "Case #" << z << ": " << count1 << ' ' << count2 << endl;
	}
	in.close();
	out.close();
	return 0;
}
