#include <array>
#include <iostream>
#include <algorithm>


typedef std::array<int, 4> Guess;


Guess read_guess()
{
  int row;
  std::cin >> row;
  for ( int i = 1; i < row; ++i )
    for ( int j = 1; j <= 4; ++j )
    {
      int dummy;
      std::cin >> dummy;
    }
  Guess r;
  for ( int i = 0; i != 4; ++i )
    std::cin >> r[i];
  for ( int i = row + 1; i <= 4; ++i )
    for ( int j = 1; j <= 4; ++j )
    {
      int dummy;
      std::cin >> dummy;
    }
  return r;
}


void run_case(int case_no)
{
  Guess g1 = read_guess();
  std::sort(g1.begin(), g1.end());
  Guess g2 = read_guess();
  std::sort(g2.begin(), g2.end());
  Guess cand;
  auto e = std::set_intersection(g1.begin(), g1.end(), g2.begin(), g2.end(), cand.begin());
  std::cout << "Case #" << case_no << ": ";
  if ( e == cand.begin() )
    std::cout << "Volunteer cheated!\n";
  else if ( e != cand.begin() + 1 )
    std::cout << "Bad magician!\n";
  else
    std::cout << cand[0] << '\n';
}


int main()
{
  int T;
  std::cin >> T;
  for ( int i = 1; i <= T; ++i )
    run_case(i);
  return 0;
}
