#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
long long gcd(long long a, long long b){
	if (b == 0){
		return a;
	}
	return gcd(b, a%b);
}

long long lcm(long long a, long long b){
	return a*b / gcd(a, b);
}
long long LCM(vector<unsigned int >& list_task){

	vector<unsigned int>::iterator it = list_task.begin();
	long long m = *it;
	for (; it != list_task.end(); it++){
		m = lcm(m, *it);
	}

	return m;
}
int main()
{
	int t, smax = 0;
	ifstream infile("small.in");
	ofstream outfile("small.txt");
	infile >> t;
	//cin >> t;
	for (int index = 0; index < t; index++)
	{
		int b, n;
		infile >> b >> n;
		vector<unsigned int> bar(b, 0);

		for (int i = 0; i < b; i++)
		{
			infile >> bar[i];
		}
		int step = LCM(bar);
		int result = -1;
		int sernum = 0;
		int a = 0;
		for (int i = 0; i < b; i++)
		{
			a+=step / bar[i];
		}
		int k = n%a;
		if (k == 0)k = a;
		vector<int> sertime(b, 0);
		while (1)
		{
			for (int j = 0; j < b; j++)
			{
				if (sertime[j]>0)
				{
					if (sertime[j] < bar[j]){ sertime[j]+=1; }
					else sertime[j] = 0;
				}

				if (sertime[j] == 0)
				{
					sernum++;
					sertime[j]++;
					if (sernum == k){
						result = j; break;
					}
					
				}
				
			}
			if (result != -1)break;
		}
		outfile << "Case #" << index + 1 << ": " << result + 1 << endl;
		//outfile << "Case #" << index + 1 << ": " << others << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}