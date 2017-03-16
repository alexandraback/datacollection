//Google Codejam
//2015 Round 1A
//Alan Richards - alarobric

//Problem B
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

#define FOR(i, n) for(ull i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

template <class T>
string ContainerPrint(T a)
{
	stringstream ss;
	FOREACH(a, iter)
		ss << *iter << " ";
	return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAXB 1000

int B, N;
std::array<ull, MAXB> M;
std::array<ull, MAXB> nextSlot{};

ull GuessServed(ull testtime)
{
	ull served = 0;
	FOR(i,B)
	{
		served += testtime / M[i] + 1;
		nextSlot[i] = testtime + M[i] - testtime % M[i];
		//Debug("Barber " << i << " can serve " << testtime / M[i] + 1 << " with next at " << nextSlot[i]);
	}
	return served;
}

bool BinarySearch(ull & testtime, ull & served)
{
	Debug("guess " << testtime << " looking for: " << N);
	ull imax = testtime*10;
	ull imin = 0;
	while (imax >= imin)
  {
    // calculate the midpoint for roughly equal partition
    ull imid = (imax+imin)/2;
		ull guess = GuessServed(imid);
		Debug("guess was " << imid << " for " << guess << " " << N << " " << N-10*B);
    if (guess < N && guess > max(0, N - 10*B))
    {
    	testtime = imid;
    	served = guess;
      return true;
    }
    // determine which subarray to search
    else if (guess < N)
      // change min index to search upper subarray
      imin = imid + 1;
    else         
      // change max index to search lower subarray
      imax = imid - 1;
  }
  return false;
}

int Solve(int i_case)
{
	std::cin >> B >> N;	//barbers, place in line
	ull averageBarber = 0;
	FOR(i, B) 
	{
		cin >> M[i];
		nextSlot[i] = 0;
		averageBarber += M[i];
	}
	averageBarber = averageBarber / B;
	Debug("B " << B << " N " << N << " averageBarber: " << averageBarber);

	ull currtime = max(0,N-B-1)*averageBarber/B;
	ull served = 0;
	Debug("curr" << currtime);
	if (currtime > 0)
	{
		if (!BinarySearch(currtime, served))
		{
			Debug("FAILURE");
			return -11111111;
		}
		currtime++;
	}
	Debug(" served:" << served);

	if(served >= N)
	{
		Debug("FAILURE");
		return -11111111;
	}
	while(served < N)
	{
		//find next empty slot, jump to them, serve someone
		ull minSlot = ULLONG_MAX;
		int minBarber = 0;
		FOR(i,B)
		{
			if (nextSlot[i] < minSlot)
			{
				minSlot = nextSlot[i];
				minBarber = i;
				if (minSlot == currtime)
					break;
			}
		}
		currtime = nextSlot[minBarber];
		nextSlot[minBarber] += M[minBarber];
		served++;
		if (served == N)
		{
			return minBarber+1;	//1-index
		}
	}
	
	return -1;
}

int main()
{
	std::cerr << "GCJ 2015 Round 1A-B" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}