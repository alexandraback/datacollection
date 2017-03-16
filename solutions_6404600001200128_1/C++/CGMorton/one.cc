#include <fstream>
#include <vector>

using namespace std;

long solve1( vector<long> &intervals )
{ 
   if (intervals.size() == 0)
      return 0;

   long total = 0;
   long last = intervals[0];

   for (long i = 1; i < intervals.size(); ++i) {
      long next = intervals[i];
      if (next < last)
         total += (last - next);
      last = next;
   }

   return total;
}

long solve2( vector<long> &intervals )
{
   if (intervals.size() == 0)
      return 0;
   long min_interval_eat = 0;

   long last = intervals[0];

   for (long i = 1; i < intervals.size(); ++i) {
      long next = intervals[i];
      if (next < last) {
         if ((last - next) > min_interval_eat)
            min_interval_eat = last - next;
      }
      last = next;
   }

   // Now we have the minimum, we add them up

   long total = 0;

   for (long j = 0; j + 1 < intervals.size(); ++j) {
      long plate = intervals[j];
      if (plate > min_interval_eat)
         total += min_interval_eat;
      else
         total += plate;
   }

   return total;
}

int main()
{
   std::ifstream in ("one.in", std::ifstream::in);
   std::ofstream out ("one.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {

      long num_ints;
      in >> num_ints;

      vector<long> intervals;
      intervals.resize( num_ints );
      for( long j = 0; j < num_ints; ++j ) {
         long interval;
         in >> interval;
         intervals.at(j) = interval;
      }

      long r1 = solve1( intervals );
      long r2 = solve2( intervals );

      out << "Case #" << i << ": " << r1 << " " << r2 << endl;
   }
   return 0;
}
