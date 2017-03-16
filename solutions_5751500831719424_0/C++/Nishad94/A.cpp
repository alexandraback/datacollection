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
    ll ans=0, sizeA = s[0].size(), sizeB = s[1].size();
    string pureA , pureB ;
    pureA += s[0][0]; pureB += s[1][0];
    for(int i = 0; i < sizeA; ++i)
      if(pureA[pureA.size()-1] != s[0][i])
	pureA += s[0][i];
 
    for(int i = 0; i < sizeB; ++i)
      if(pureB[pureB.size()-1] != s[1][i])
	pureB += s[1][i];

    if(pureA == pureB){
      vector<ll> countA(pureA.size(),1), countB(pureB.size(),1);
      int current=0;
      for(int i = 0; i < sizeA; ){
	int j = i+1;
	char c = s[0][i];
	while(j < sizeA && (s[0][j] == c))
	  ++j;
	countA[current] = j - i;
	current++;
	i = j;
      }

      current=0;
      for(int i = 0; i < sizeB; ){
	int j = i+1;
	char c = s[1][i];
	while(j < sizeB && (s[1][j] == c))
	  ++j;
	countB[current] = j - i;
	current++;
	i = j;
      }
      int pureSize = pureA.size();
      for(int i = 0; i < pureSize ; ++i){
	int diff = countA[i] - countB[i];
	if(diff < 0)
	  diff *= -1;
	ans += diff;
      }
    }
    else
      ans = -1;
    if(ans == -1)
      cout << "Case #" << t << ": " << "Fegla Won" << endl;
    else
      cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
