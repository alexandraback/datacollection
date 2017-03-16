#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct Point
{
  Point(long x, long y)
    : x(x)
    , y(y)
  {}

  long x, y;
};


bool operator==(Point const &a, Point const &b)
{
  return a.x == b.x && a.y == b.y;
}


long ccw(Point const &a, Point const &b, Point const &c)
{
  long ta = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
  return (ta < 0) - (ta > 0);
}


long d2(Point const &a, Point const &b)
{
  long dx = a.x - b.x;
  long dy = a.y - b.y;
  return dx*dx + dy*dy;
}

int sign(long a)
{
  return (a > 0) - (a < 0);
}


typedef vector<Point> Points;


Points graham(Points &pts)
{
  Points hull;
  size_t N = pts.size();
  if ( N < 3 )
    return hull;
  hull.reserve(N);
  size_t ly = 0;
  for ( size_t i = 1; i < N; ++i )
    if ( pts[i].y < pts[ly].y )
      ly = i;
    else if ( pts[i].y == pts[ly].y && pts[i].x < pts[ly].x )
      ly = i;
  swap(pts[0], pts[ly]);
  sort(pts.begin() + 1, pts.end(),
      [&](Point const &a, Point const &b){
        long o = ccw(pts[0], a, b);
        if ( o == 0 )
          return d2(pts[0], a) < d2(pts[0], b);
        return o == -1;
        });
  hull.push_back(pts[0]);
  hull.push_back(pts[1]);
  hull.push_back(pts[2]);
  for ( size_t i = 3; i < N; ++i )
  {
    Point t = hull.back();
    hull.pop_back();
    while ( !hull.empty() && ccw(hull.back(), t, pts[i]) != -1 )
    {
      t = hull.back();
      hull.pop_back();
    }
    hull.push_back(t);
    hull.push_back(pts[i]);
  }
  return hull;
}


bool on_boundary(Points const &tr, unsigned long cut_mask, unsigned sq_no)
{
  if ( (1UL<<sq_no) & cut_mask )
    return false;
  Points rem_tr;
  rem_tr.reserve(tr.size());
  for ( size_t i = 0; i != tr.size(); ++i )
    if ( ((1UL<<i) & cut_mask) == 0 )
      rem_tr.push_back(tr[i]);
  Points hull = graham(rem_tr);
  if ( hull.empty() )
    return true;
  for ( size_t i = 0; i < hull.size(); ++i )
  {
    size_t ni = i + 1;
    if ( ni >= hull.size() )
      ni = 0;
    if ( tr[sq_no] == hull[i] )
      return true;
    if ( (tr[sq_no].x - hull[i].x)*(hull[ni].y - hull[i].y) ==
        (tr[sq_no].y - hull[i].y)*(hull[ni].x - hull[i].x) )
    {
      if ( sign(tr[sq_no].x - hull[i].x) == sign(hull[ni].x - hull[i].x) &&
          labs(tr[sq_no].x - hull[i].x) <= labs(hull[ni].x - hull[i].x) )
        return true;
    }
  }
  return false;
}

int nbits(unsigned x)
{
  int r = 0;
  while ( x > 0 )
  {
    ++r;
    x &= x - 1;
  }
  return r;
}


int smallest(Points const &tr, unsigned sq_no)
{
  if ( tr.size() > 32 )
    return -1;
  int best = 32;
  for ( unsigned i = 0; i < (1U<<tr.size()); ++i )
  {
    int b = nbits(i);
    if ( b < best && on_boundary(tr, i, sq_no) )
    {
      best = b;
      if ( best == 0 )
        break;
    }
  }
  return best;
}



int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    cin >> N;
    Points tr;
    tr.reserve(N);
    for ( int i = 0; i < N; ++i )
    {
      int x, y;
      cin >> x >> y;
      tr.emplace_back(x, y);
    }
    cout << "Case #" << t << ":\n";
    for ( int i = 0; i < N; ++i )
    {
      cout << smallest(tr, i) << '\n';
    }
  }
  return 0;
}
