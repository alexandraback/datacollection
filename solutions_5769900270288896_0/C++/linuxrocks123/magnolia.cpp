#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
     int test_cases;
     cin >> test_cases;
     for(int z=1; z<=test_cases; z++)
     {
          int R, C, N;
          cin >> R >> C >> N;

          bool occupied[R][C];
          for(int r=0; r<R; r++)
               for(int c=0; c<C; c++)
                    occupied[r][c]=false;
          
          auto occupied_neighbors = [&](int r, int c) -> int
          {
               int to_return = 0;
               if(r!=0)
                    to_return+=occupied[r-1][c];
               if(r!=R-1)
                    to_return+=occupied[r+1][c];
               if(c!=0)
                    to_return+=occupied[r][c-1];
               if(c!=C-1)
                    to_return+=occupied[r][c+1];
               return to_return;
          };

          auto total_unhappiness = [&]() -> int
          {
               int unhappiness = 0;
               for(int r=0; r<R; r++)
                    for(int c=0; c<C; c++)
                    {
                         //Handle right and lower internal walls
                         if(r!=R-1)
                              unhappiness += (occupied[r][c] && occupied[r+1][c]);
                         if(c!=C-1)
                              unhappiness += (occupied[r][c] && occupied[r][c+1]);
                    }

               return unhappiness;
          };
          
          //Initial placement
          for(int i=0; i<N; i++)
          {
               int x=-1, y=-1, neighbors=4;
               for(int r=0; r<R; r++)
                    for(int c=0; c<C; c++)
                         if(!occupied[r][c] && occupied_neighbors(r,c) < neighbors)
                         {
                              x = r; y = c; neighbors = occupied_neighbors(r,c);
                         }
               occupied[x][y]=true;
          }

          //Shuffle
          bool keep_shuffling = true;
          while(keep_shuffling)
          {
               keep_shuffling = false;
               for(int r=0; r<R; r++)
                    for(int c=0; c<C; c++)
                         if(!occupied[r][c])
                         {
                              int v_r = -1, v_c = -1, new_unhappiness = total_unhappiness();
                              for(int s=0; s<R; s++)
                                   for(int d=0; d<C; d++)
                                        if((s!=r || d!=c) && occupied[s][d])
                                        {
                                             occupied[r][c] = true;
                                             occupied[s][d] = false;
                                             if(total_unhappiness() < new_unhappiness)
                                             {
                                                  v_r = s;
                                                  v_c = d;
                                                  new_unhappiness = total_unhappiness();
                                             }
                                             occupied[r][c] = false;
                                             occupied[s][d] = true;
                                        }
                              
                              if(new_unhappiness!=total_unhappiness())
                              {
                                   occupied[r][c] = true;
                                   occupied[v_r][v_c] = false;
                                   keep_shuffling = true;
                              }
                         }
          }

          // for(int r=0; r<R; r++)
          // {
          //      for(int c=0; c<C; c++)
          //           cout << occupied[r][c] << ' ';
          //      cout << endl;
          // }
          
          cout << "Case #" << z << ": " << total_unhappiness() << endl;
     }

     return 0;
}
