#include <iostream>
using namespace std;

int R, C, N;
int min_noise;
bool **used;

int check(int r, int c)
{
  int n = 0;
  if(r > 0 && used[r - 1][c])
    ++n;
  if(c > 0 && used[r][c - 1])
    ++n;
  if(r < R - 1 && used[r + 1][c])
    ++n;
  if(c < C - 1 && used[r][c + 1])
    ++n;
  
  return n;
}

void put(int r, int c, int n, bool **used, int noise)
{  
  for(int i = r; i < R; ++i)
    for(int j = 0; j < C; ++j)
    {      
      if(i == r && j == 0)
        j = c;
        
      if((R - i - 1) * C + (C - j) < n || noise >= min_noise)
        return;
        
      if(!used[i][j])
      {     
        used[i][j] = true;
        if(noise + check(i, j) < min_noise)
        {
          if(n == 1)
            min_noise = noise + check(i, j);
          else if(j == C - 1)
            put(i + 1, 0, n - 1, used, noise + check(i, j));
          else
            put(i, j + 1, n - 1, used, noise + check(i, j));
        }
          
        used[i][j] = false;
      }
    }
}

int main()
{
  int Case;
  cin >> Case;
  
  for(int c = 1; c <= Case; ++c)
  {
    cin >> R >> C >> N;
    
    used = new bool*[R];
    for(int i = 0; i < R; ++i)
      used[i] = new bool[C];
    
    for(int i = 0; i < R; ++i)
      for(int j = 0; j < C; ++j)
        used[i][j] = false;
    
    min_noise = 100000;
    if(N != 0)
      put(0, 0, N, used, 0);
    else
      min_noise = 0;
    
    for(int i = 0; i < R; ++i)
      delete [] used[i];
    delete [] used;
    
    cout << "Case #" << c << ": " << min_noise << endl;
  }
    
  return 0;
}
