#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long solve1( vector<pair<long,long> > &points, long origin )
{
   if (points.size() <= 3)
      return 0;
   // I have here an n-cubed algorithm, let's see if that's fast enough

   // For each other point,
   // FIRST create a line through this point and that point
   // then calculate how many points are above and below the line
   // the min of above/below over all such lines gives our answer
   long result = -1;

   long o_x = points[origin].first;
   long o_y = points[origin].second;

   for (long i = 0; i < points.size(); ++i) {
      if (i == origin)
         continue;

      // FIRST create a line through this point and that point
      double dx = (double)(o_x) - (double)(points[i].first);
      double dy = (double)(o_y) - (double)(points[i].second);
      double dydx;
      bool vertical = false;
      if (dx == 0) vertical = true;
      else dydx = dy / dx;

      // then calculate how many points are above and below the line
      long above = 0;
      long below = 0;

      for (long j = 0; j < points.size(); ++j) {
         if (j == origin || j == i)
            continue;

         long dif_x = points[j].first - o_x;
         if (!vertical) {
            double line_y = dydx * dif_x + o_y;
            if (line_y - points[j].second < -0.00000000001)
               below++;
            else if (line_y - points[j].second > 0.00000000001)
               above++;
         }
         else
         {
            if (dif_x > 0)
               above++;
            else if (dif_x < 0)
               below++;
         }
      }

      // the min of above/below over all such lines gives our answer
      if (above < result || result == -1)
         result = above;
      if (below < result)
         result = below;
   }

   cout << result << endl;
   return result;
}

int main()
{
   std::ifstream in ("three.in", std::ifstream::in);
   std::ofstream out ("three.out", std::ofstream::out);

   long count;

   in >> count;
   for (long i = 1; i <= count; ++i) {

      long num_points;
      in >> num_points;

      vector<pair<long,long> > points;
      points.resize( num_points );
      for( long j = 0; j < num_points; ++j ) {
         long x,y;
         in >> x >> y;
         points.at(j) = pair<long,long>( x, y );
      }

      out << "Case #" << i << ":" << endl;
      for( long j = 0; j < num_points; ++j ) {
         long r1 = solve1( points, j );
         out << r1 << endl;
      }
   }
   return 0;
}
