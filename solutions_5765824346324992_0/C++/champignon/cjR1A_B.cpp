#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
//#include <string>
//#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <functional> 
using namespace std;

class mycomparison
{
public:
  bool operator() (const pair<int, int> & lhs, const pair<int, int> &rhs) const
  {
  	bool res;
  	if(lhs.second == rhs.second) res = (lhs.first > rhs.first);
  	else res = (lhs.second > rhs.second);
    return res;
  }
};

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}      

int lcm(int a, int b)
{
	return abs(a*b)/gcd(a,b);
}

int whichBarber(vector<int> M, int N)
{
	int B = M.size();
	int k, n = 1, id, wt;
	priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison > buffer;
	
	int LCM = M[0];
	//cout << B << endl;
	for(k = 0; k < B; k++)
	{
		buffer.push(pair<int, int>(k, 0));
		LCM = lcm(LCM, M[k]);
	}
	int base = 0;
	for(k = 0; k < B; k++)
		base += LCM/M[k];
	
	//cout << LCM << " " << base << endl;
	while(n < (N-1)%base+1)
	{
		id = buffer.top().first;
		wt = buffer.top().second;
		//cout << id << " " << wt << endl;
		buffer.pop();
		buffer.push(pair<int, int>(id, wt+M[id]));
		n++;
	}
	id = buffer.top().first+1;	
		
	return id;
}

int main()
{
	fstream  infile, outfile;
	infile.open("B-small-attempt1.in", ios::in);
	
	infile.seekg(0, ios::end);  
	if (infile.tellg() == 0) return 0;
	infile.seekg(0, ios::beg);
	
	outfile.open("output.txt", ios::out | ios::trunc);
	int i, j, nCase, temp, N, B;
	vector<int> M;
	infile >> nCase;
	//cout << nCase << endl;
	for(i = 0; i < nCase; i++)
	{
		M.clear();
		infile >> B;
		infile >> N;
		for(j = 0; j < B; j++)
		{
			infile >> temp;
			M.push_back(temp);
		}
		outfile << "Case #" << i+1 << ": " << whichBarber(M, N) << endl;
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}
