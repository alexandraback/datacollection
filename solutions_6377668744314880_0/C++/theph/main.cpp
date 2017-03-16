#include <fstream>
#include <iostream>
#include <vector>

struct tree
{
	long long X;
	long long Y;
	int cut;
};

inline long long cross(const tree& a, const tree& b, const tree& c )
{
	//(b-a)X(c-a) 
	return ((b.X - a.X)*(c.Y - a.Y)) - ((b.Y - a.Y)*(c.X - a.X));
}

void solve_case()
{
	int N;
	std::cin >> N;
	
	std::vector<tree> forest(N);
	for( int i = 0; i < N; ++i )
	{
		std::cin >> forest[i].X;
		std::cin >> forest[i].Y;
		forest[i].cut = 30000;
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = i + 1; j < N; ++j)
		{
			int left = 0;
			for( int k = 0; k < N; ++k)
			{
				if( cross(forest[i], forest[j], forest[k]) > 0 )
				{
					++left;
				}
				if( (left > forest[i].cut) && (left > forest[j].cut) )
					break;
			}
			if( forest[i].cut > left )
				forest[i].cut = left;
			if( forest[j].cut > left )
				forest[j].cut = left;

			int right = 0;
			for( int k = 0; k < N; ++k)
			{
				if( cross(forest[i], forest[j], forest[k]) < 0)
				{
					++right;
				}
				if( (right > forest[i].cut) && (right > forest[j].cut) )
					break;
			}
			if( forest[i].cut > right )
				forest[i].cut = right;
			if( forest[j].cut > right )
				forest[j].cut = right;
		}
	}



	for( int i = 0; i < N; ++i )
	{
		if( forest[i].cut < 30000)
			std::cout << std::endl << forest[i].cut;
		else
			std::cout << std::endl << 0;
	}
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("C-small-attempt1.in", "r", stdin);		//input file
	freopen ("C-small-attempt1.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}