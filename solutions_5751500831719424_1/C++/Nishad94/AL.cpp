#include<string>
#include<vector>
#include<iostream>
#define ll long long


using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t){
    int N;
    cin >> N;
    vector<string> s(N);
    for(int i = 0; i < N; ++i){
      cin >> s[i];
    }
    vector<string> pure(N);
    vector<ll> sizes(N), puresize(N);
    vector< vector<ll> > count;  // count of each pure chracter in each string
    for(int i = 0; i < N; ++i){
      sizes[i] = s[i].size();
      //int current = 0;
      vector<ll> c_count;
      for(int j = 0; j < sizes[i]; ){
	int k = j + 1;
	char c = s[i][j];
	pure[i] += c;
	while(k < sizes[i] && (s[i][k] == c))
	  ++k;
	c_count.push_back(k - j);
	j = k;
      }
      puresize[i] = pure[i].size();
      count.push_back(c_count);
    }
    ll ans = 0;
    int p;
    for(p = 1; p < N; ++p){
      if(pure[p] != pure[0])
	break;
    }
    if(p != N)
      ans = -1;
    else{
      for(int i = 0; i < puresize[0]; ++i){
	ll min_char_ops = 100000000;
	for(int j = 1; j <= 100; ++j){
	  ll current_ans = 0;
	  for(int k = 0; k < N; ++k){
	    ll lol = count[k][i] - j;
	    if(lol < 0)
	      lol *= -1;
	    current_ans += lol;
	  }
	  if(current_ans < min_char_ops)
	    min_char_ops = current_ans;
	}
	ans += min_char_ops;
      }
    }
    if(ans == -1)
      cout << "Case #" << t << ": " << "Fegla Won" << endl;
    else
      cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
