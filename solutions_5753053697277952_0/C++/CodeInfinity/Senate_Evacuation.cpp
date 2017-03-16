#include <iostream>
#include <queue>

int main()
{
  int T, N;
  std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
    {
      std::priority_queue<std::pair<int, char> > pq;
      int temp;
      std::cin >> N;

      for ( int i = 0; i < N; ++i )
	{
	  std::cin >> temp;
	  pq.push(std::pair<int, char>(temp, alpha[i]));
	}

      std::cout << "Case #" << t << ":";
      while ( !pq.empty() )
	{
	  std::pair<int, char> p1 = pq.top();
	  pq.pop();
	  std::pair<int, char> p2 = pq.top();
	  pq.pop();

	  if ( p1.first > p2.first )
	    {
	      std::cout << ' ' << p1.second << p1.second;
	      p1.first -= 2;
	      if ( p1.first != 0 )
		pq.push(p1);
	      pq.push(p2);
	    }
	  else
	    {
	      if ( !pq.empty() && pq.top().first == p1.first )
		{
		  std::cout << ' ' << p1.second;
		  p1.first -= 1;
		  if ( p1.first != 0 )
		    pq.push(p1);
		  pq.push(p2);
		}
	      else
		{
		  std::cout << ' ' << p1.second << p2.second;
		  p1.first -= 1;
		  p2.first -= 1;
		  if ( p1.first != 0 )
		    pq.push(p1);
		  if ( p2.first != 0 )
		    pq.push(p2);
		}
	    }
	}
      std::cout << std::endl;
    }

  
  return 0;
}
