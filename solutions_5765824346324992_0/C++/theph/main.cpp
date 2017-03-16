#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 


struct barber
{
	long long work_cost;
	long long wait_time;
	int number;
};

inline bool wait_tima_compare(barber a, barber b)
{
	return a.work_cost < b.work_cost;
}

inline bool number_compare(barber a, barber b)
{
	return a.number < b.number;
}

void solve_case()
{
	long long B, N;
	std::cin >> B;
	std::cin >> N;
	
	std::vector<barber> barbers(B);
	int answer = 1;
	for(int i = 0; i < B; ++i)
	{
		std::cin >> barbers[i].work_cost;
		barbers[i].wait_time = 0;
		barbers[i].number = i + 1;
	}
	
	std::sort (barbers.begin(), barbers.end(), wait_tima_compare);
	if(N > B)
	{
		N -= B;
		for(int i = 0; i < B; ++i)
		{
			barbers[i].wait_time += barbers[i].work_cost;
		}
	}
	
	if(N > B)
	{
		long long N1 = N - B;
		N -= N1;

		barbers[0].wait_time = N1 * barbers[0].work_cost;

		for(int i = 0; i < B; ++i)
		{
			for(int j = i - 1; j > 0; --j)
			{
				if(barbers[i].wait_time < barbers[j].wait_time)
				{
					int tempN = (barbers[j].wait_time - barbers[i].wait_time) / 2 / barbers[j].work_cost + 1;
					barbers[j].wait_time -= barbers[j].work_cost * tempN;
					barbers[i].wait_time += barbers[i].work_cost * tempN;
				}
			}
		}
	}
	
	std::sort (barbers.begin(), barbers.end(), number_compare);
	while(N > 0)
	{
		long long least_wait_time = 1000000;
		for(int j = 0; j < B; ++j)
		{
			if( least_wait_time > barbers[j].wait_time )
				least_wait_time = barbers[j].wait_time;
		}
		for(int j = 0; j < B; ++j)
		{
			barbers[j].wait_time -= least_wait_time;
		}
		for(int j = 0; j < B; ++j)
		{
			if(barbers[j].wait_time == 0)
			{
				barbers[j].wait_time += barbers[j].work_cost;
				answer = j + 1;
				--N;
				break;
			}
		}
		
	}
	
	std::cout << answer;
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("B-small-attempt0.in", "r", stdin);		//input file
	freopen ("B-small-attempt0.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}