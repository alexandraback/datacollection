#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;



struct BarberPQ
{
	// the id of the baber
	int id;
	// the minute left for the barber to finish his operation
	int m;
	BarberPQ() {}
	BarberPQ(int id, int m) : id(id), m(m) {}
};

struct compare
{
	bool operator() (const BarberPQ& l, const BarberPQ& r)
	{			
		if (l.m == r.m)
		{
			return l.id > r.id;
		}
		return l.m > r.m;
	}
};


int gcd(int m, int n)
{
    if(n == 0) return m;
    return gcd(n, m % n);
}

int lcm(int m, int n)
{
	return m * n / gcd(m, n);
}

int solve(const vector<BarberPQ>& barber, int N)
{
	// code here
	priority_queue<BarberPQ, vector<BarberPQ>, compare> pq;
	// first we are going to push 
	const int B = barber.size();
	for (int i = 0; i < B; ++i)
	{
		pq.push(BarberPQ(barber[i].id, 0));
	}
	
	int lcmN = barber[0].m;
	for (int i = 1; i < B; ++i)
	{
		lcmN = lcm(lcmN, barber[i].m);
	}

	int modfactor = 0;
	for (int i = 0; i < B; ++i)
	{
		modfactor += lcmN / barber[i].m;
	}

	int count = N % modfactor;
	if (count == 0)
		count = modfactor;
	int id = -1;
	


	while (count > 0)
	{
		// get the smallest element
		
		id = pq.top().id;
		int t = pq.top().m;
		// cout << id << ":" << t << " ";
		pq.pop();
		// remove this element and creae a new set
		priority_queue<BarberPQ, vector<BarberPQ>, compare> tmp;
		// update tmp
		tmp.push(BarberPQ(id, barber[id - 1].m));
		while (!pq.empty())
		{
			tmp.push(BarberPQ(pq.top().id, pq.top().m - t));
			pq.pop();
		}
		// update pq
		pq = tmp;
		count--;
	}	
	// cout << endl;
	return id;
}


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "no input file\n";
		return 0;
	}

	string fname(argv[1]);
	ifstream ifile(fname);
	ofstream ofile(fname + ".out");

	int T;
	ifile >> T;
	for (int i = 0; i < T; ++i)
	{
		// get the specific format 
		// cout << i << endl;
		int B, N;
		ifile >> B >> N;
		vector<BarberPQ> barber(B);
		for (int j = 0; j < B; ++j)
		{
			ifile >> barber[j].m;
			barber[j].id = j + 1;
		}
		int result = solve(barber, N);
		ofile << "Case #" << i + 1 << ": " << result << "\n";
 	}
	return 0;
}