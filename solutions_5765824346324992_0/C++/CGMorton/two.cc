#include <fstream>
#include <vector>
#include <boost/math/common_factor.hpp>

using namespace std;

long mylcm( vector<long> &vec )
{
   long result = 1;
   for (long i = 0; i < vec.size(); ++i) {
      result = boost::math::lcm(vec[i], result);
   }
   return result;
}

long solve1( vector<long> &barbers, long num )
{
   if (barbers.size() == 0)
      return 0;

   if (barbers.size() == 1)
      return 1;

   // Factor out cycles
   long lcm = mylcm( barbers );
   long full_cycle = 0;
   for (long barb = 0; barb < barbers.size(); barb++)
      full_cycle += (lcm / barbers[barb]);
   
   if (num % full_cycle == 0)
      num = full_cycle;
   else
      num = num % full_cycle;

   // The brute force method
   long time = 0;

   vector<long> barber_rem_time;
   barber_rem_time.resize( barbers.size() );
   for (long i = 0; i < barber_rem_time.size(); i++)
      barber_rem_time[i] = 0;

   for (long n = 1; n <= num; ++n) {
      // Find next barber
      long min_time_to_barber = -1;
      long min_barber = -1;
      bool found = false;

      for (long b = 0; b < barber_rem_time.size(); ++b) {
         long rem = barber_rem_time[b];
         if (rem <= time) {
            if (n == num)
               return b + 1;
            barber_rem_time[b] += barbers[b];
            found = true;
            break;
         }
         if (rem - time < min_time_to_barber || min_time_to_barber == -1) {
            min_time_to_barber = rem - time;
            min_barber = b;
         }
      }
      
      if (!found) {
         if (n == num)
            return min_barber + 1;
         time += min_time_to_barber;
         barber_rem_time[min_barber] += barbers[min_barber];
      }
   }
   return -1;
}

int main()
{
   std::ifstream in ("two.in", std::ifstream::in);
   std::ofstream out ("two.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {

      long num_barbers, num;
      in >> num_barbers >> num;

      vector<long> barbers;
      barbers.resize( num_barbers );
      for( long j = 0; j < num_barbers; ++j ) {
         long barber_time;
         in >> barber_time;
         barbers.at(j) = barber_time;
      }

      long r1 = solve1( barbers, num );

      out << "Case #" << i << ": " << r1 << endl;
   }
   return 0;
}
