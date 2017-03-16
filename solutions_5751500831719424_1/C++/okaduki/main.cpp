#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
  int Test;
  cin >> Test;

  for(int test=1;test<=Test;++test){
	int N;
	cin >> N;
	vector<string> input(N);
	for(int i=0;i<N;++i){
	  cin >> input[i];
	}

	int res = 0;
	vector<vector<int>> memo(N);
	for(int idx=0;idx<N;++idx){
	  for(int s1=0;s1<input[idx].length();){
		int beg = s1;
		char ch = input[idx][s1];
		++s1;
		for(;s1<input[idx].length();++s1){
		  if(ch != input[idx][s1])
			break;
		}
		memo[idx].push_back(s1 - beg);
	  }
	}

	bool failed = false;
	int sz = memo[0].size();
	for(int i=0;i<N;++i){
	  if(memo[i].size() != sz){
		failed = true;
		break;
	  }
	}

	if(!failed){
	  res = 0;
	  char ch;
	  vector<int> cnt(N, 0);
	  for(int i=0;i<sz;++i){
		ch = input[0][cnt[0]];
		for(int idx=0;idx<N;++idx){
		  if(ch != input[idx][cnt[idx]]){
			failed = true;
			break;
		  }
		}
		if(failed) break;

		int min_val = INT_MAX;
		for(int k=1;k<=100;++k){
		  int expect = 0;
		  for(int idx=0;idx<N;++idx){
			expect += abs(k - memo[idx][i]);
		  }
		  min_val = min(min_val, expect);
		}
		res += min_val;

		for(int idx=0;idx<N;++idx){
		  cnt[idx] += memo[idx][i];
		}
	  }
	}

	if(!failed){
	  cout << "Case #" << test << ": " << res << endl;
	}else{
	  cout << "Case #" << test << ": Fegla Won" << endl;
	}
  }
  return 0;
}
