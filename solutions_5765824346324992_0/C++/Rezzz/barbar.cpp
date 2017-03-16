#include <iostream> 
#include <sstream>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>

using namespace std;

class Barbar
{
public:
	Barbar();
	int N;
	long long nextTime;
	long waitTime;
};

Barbar::Barbar()
{
	N = 0;
	waitTime = 0;
	nextTime = 0;
}

Barbar barbars[1000];

bool compare(int i, int j)
{
	Barbar lhs = barbars[i];
	Barbar rhs = barbars[j];
	if (lhs.nextTime != rhs.nextTime) return (lhs.nextTime < rhs.nextTime);
	else return (lhs.N < rhs.N);
}

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
	return (a * b / gcd(a,b));
}


class mycomparison
{
public:
  bool operator() (int& i, int& j) const
  {
  	Barbar* lhs = &barbars[i];
  	Barbar* rhs = &barbars[j];
  	if (lhs->nextTime != rhs->nextTime) return (lhs->nextTime > rhs->nextTime);
    else 
    	{
    		//cout << lhs.N << " " << rhs.N << endl;
    		//cout << lhs->nextTime << " " << rhs->nextTime << endl;
    		return (lhs->N > rhs->N);
    	}
  }
};


int main()
{
	int T;
	string line;
	getline(std::cin, line);
	std::istringstream stream1(line);
	stream1 >> T;

	for(int i = 1; i <= T; i++)
	{
		int B;
		int N;
		long M[1000];
		std::priority_queue<int,std::vector<int>, mycomparison> MainHeap;


		getline(std::cin, line);
		std::istringstream stream2(line);
		stream2 >> B >> N;

		getline(std::cin, line);
		std::istringstream stream(line);
		long long lcm1 = 1;

		for(int j = 0; j< B; j++)
		{
			stream >> M[j];
			barbars[j].waitTime = M[j];
			barbars[j].N = j;
			barbars[j].nextTime = 0;
			//cout << M[j] << " ";
			MainHeap.push(j);
			lcm1 = lcm(lcm1, (long long)M[j]);
		}
		long long nnumbers = 0;
		for(int j = 0; j< B; j++)
		{
			nnumbers += (lcm1 / M[j]);
		}
		//cout << nnumbers << endl;
		long long remain = N % nnumbers;
		if (remain == 0)
			remain = nnumbers;
		//cout << remain << endl;
		for(long j = 1; j < remain; j++)
		{
			int r = MainHeap.top();
			Barbar* b = &barbars[r];
			//cout << b->nextTime << " ";
			MainHeap.pop();
			b->nextTime = b->nextTime +  b->waitTime;
			//cout << b->nextTime << endl;
			MainHeap.push(r);
			//cout << barbars[r].nextTime << endl;
		}
		int r = MainHeap.top();
		Barbar b= barbars[r];
		cout << "Case #" << i << ": " << b.N  + 1 << endl;
	}

}