#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc!=3) 
    {
	cout << "Missing arguments." << endl;
	return -1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int T;
    fin >> T;

    for (int t = 0; t < T; ++t)
    {
		int N;
		fin >> N;
		vector<int> m(N);
		for (int i = 0; i < N; ++i)
		{
			int temp;
			fin >> temp;
			m.push_back(temp);
		}
		
		int one = 0;
		int rate = 0;
		for (int i = 1; i < m.size(); ++i)
		{
			int diff = m[i-1] - m[i];
			if (diff > 0)
			{
				one += diff;
			}
			rate = max(rate,diff);
		}
		int two = 0;
		
		for (int i = 0; i < m.size()-1; ++i)
		{
			if (m[i] >= rate)
			{
				two += rate;
			}
			else
			{
				two += m[i];
			}
		}
		fout << "Case #" << t+1 << ": " << one << " " << two;
		fout << endl;
    }
    return 0;
}
