#include <cstdio>
#include <set>
#include <string>
//#include <algorithm>
#include <vector>

using namespace std;
//--common
#define forr(i,f,t) for (int i = (f); i <= (t); i++)
#define fori(i,t) for (int i = 0; i < (t); i++)
#define forc(i,c) for (int i = 0; i < (c).size(); i++)
#define forit(it,c) for (auto it = (c).begin(), end = (c).end(); it != end; ++it)

template <typename C> void rerase(C& s, const typename C::const_reverse_iterator &it ) { s.erase(s.find(*it)); }
template <typename T> vector<T>& operator<<(vector<T>& v, const T& t) { v.push_back(t); return v; }
template <typename T> set<T>& operator<<(set<T>& v, const T& t) { v.insert(t); return v; }
//--end common

bool isoccupied(int mask, int r, int c, int i, int j){
     if (i < 0 || j < 0 || i >= r || j >= c) return false;
     return mask & ( (1 << (i * c + j)) );
}

bool occ(bool field[], int r, int c, int i, int j){
     if (i < 0 || j < 0 || i >= r || j >= c) return false;
     return field[i * c + j];
}

int greedyAdd(int r, int c, int n, int patternMode) {
     if (n < (r*c) / 2) return 0;
     bool map[r*c] = {false};
     for (int i=0;i<r;i++)
          for (int j=(i+patternMode)&1;j<c;j+=2,n--)
               map[i*c + j] = true;
     if (n <= 0) return 0;
     int unhappiness = 0;
     for (int add = 0; add<n;add++) {
          int best = 10, besti = 0, bestj = 0;
          fori (i, r) fori (j, c) {
               if (occ(map, r, c, i,j)) continue;
               int score = 0;
               if (occ(map, r, c, i+1,j)) score++;
               if (occ(map, r, c, i,j+1)) score++;
               if (occ(map, r, c, i-1,j)) score++;
               if (occ(map, r, c, i,j-1)) score++;
               if (score <best) best = score, besti = i, bestj = j;
          }
          map[besti * c+bestj] = true;
          unhappiness += best;
     }
     return unhappiness;
}

int main(int argc, char *argv[])
{
     int T;
     scanf("%i", &T);
     forr (tt, 1, T) {
          int r,c,N;
          scanf("%i %i %i\n", &r, &c, &N);
          //for (int N = (r*c)/2; N <= r*c; N ++ ) {
          /*int M = 1 << (r*c);
          int unhappiness = 4 * r * c;
          int best = 0;

          for (int cur = 0; cur < M; cur++) {
               int n = 0;
               int d = cur;
               while (d) {
                    n += d & 1;
                    d = d >> 1;
               }
               if (n != N) continue;
               int uh = 0;
               fori(i,r) fori(j,c) {
                   if (!isoccupied(cur,r,c,i,j) ) continue;
                   if (isoccupied(cur,r,c,i+1,j) ) uh++;
                   if (isoccupied(cur,r,c,i,j+1) ) uh++;
               }
               if (uh < unhappiness) { unhappiness = uh; best = cur;}
          }*/
          int unhappiness = min(greedyAdd(r,c,N, 1),greedyAdd(r,c,N, 0));

          int res = unhappiness ;


          printf("Case #%i: %i\n", tt, res);
          //printf("Case #%i: %i %i\n", tt, N, res);


          //printf("%i %i\n", deceiveScore, warScore);
/*
                         //printf("%i: %i\n",tt,best);
                         fori(i,r) {
                              fori(j,c) {
                                   if (isoccupied(best,r,c,i,j)) printf("x");
                                   else printf("_");
                              }
                              printf("\n");
                         }//*/
          //}
     }
}
