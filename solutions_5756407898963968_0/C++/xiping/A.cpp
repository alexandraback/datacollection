#include <iostream>

using namespace std;

void solve_case();

int main()
{
   int N = 0;
   cin >> N;
   for (int i = 0; i < N; ++ i)
   {
      cout << "Case #" << i + 1 << ": ";
      solve_case();
      cout << '\n';
   }

   return 0;
}

void solve_case()
{
   int markers[17] = {};

   for(int k = 0; k < 2; ++ k)
   {
      int row = 0;
      cin >> row;
      for(int i = 1; i <= 4; ++ i)
      {
         for(int j = 1; j <= 4; ++ j)
         {
            int n = 0;
            cin >> n;
            if (i == row)
            {
               ++markers[n];
            }
         }
      }
   }

   int c = 0;
   for(int i = 1; i < 17; ++ i)
   {
      if (markers[i] == 2)
      {
         if (c == 0)
            c = i;
         else
         {
            cout << "Bad magician!";
            return;
         }

      }
   }

   if (c)
      cout << c;
   else
      cout << "Volunteer cheated!";

}
