#include <iostream>
#include <string>

using namespace std;

int main(void){
  int T;
  cin >> T;
  for(int c = 0; c < T; ++c){
    int N;
    cin >> N;

    string* ss;
    ss = new string[N];
    for(int i = 0; i < N; ++i){
      cin >> ss[i];
      //      cout << ss[i] << endl;
    }
    int pos[N];
    int cnt[N];
    fill_n(pos, N, 0);
    fill_n(cnt, N, 0);

    int ans = 0;
    while(true){
      bool end = true;
      for(int i = 0; i < N; ++i){
        pos[i] += cnt[i];
        end &= pos[i] == ss[i].size();
      }

      if(end)
        break;

      for(int i = 0; i < N; ++i)
        if(pos[i] == ss[i].size()){
          ans = -1;
          goto lose;
        }

      for(int i = 1; i < N; ++i){
        //        cout <<  ss[i][pos[i]] << " != " << ss[i-1][pos[i-1]] << endl;
        if(ss[i][pos[i]] != ss[i-1][pos[i-1]]){
          ans = -1;
          goto lose;
        }
      }

      for(int i = 0; i < N; ++i){
        cnt[i] = 1;
        for(int j = pos[i]+1; j < ss[i].size(); ++j)
          if(ss[i][j] == ss[i][j-1])
            ++cnt[i];
          else
            break;
      }

      // for(int i = 0; i < N; ++i)
      //   cout << pos[i] << ' ';
      // cout << endl;
      // for(int i = 0; i < N; ++i)
      //   cout << "  " << cnt[i] << ' ';
      // cout << endl;

      int add = INT_MAX;
      for(int l = 1; l <= 100; ++l){
        int sum = 0;
        for(int i = 0; i < N; ++i)
          sum += abs(l - cnt[i]);
        add = min(add, sum);
      }

      ans += add;

    }
  lose:

    cout << "Case #" << c+1 << ": ";
    if(ans == -1)
      cout << "Fegla Won" << endl;
    else
      cout << ans << endl;

    delete [] ss;
  }

  return 0;
}
