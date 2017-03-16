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

	//suppose N=2
	int res = 0;
	vector<int> memo[2];
	for(int idx=0;idx<2;++idx){
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
	if(memo[0].size() == memo[1].size()){
	  res = 0;
	  int cnt0 = 0, cnt1 = 0;
	  char ch0, ch1;
	  for(int i=0;i<memo[0].size();++i){
		ch0 = input[0][cnt0];
		ch1 = input[1][cnt1];
		if(ch0 != ch1){
		  failed = true;
		  break;
		}
		int num0 = memo[0][i];
		int num1 = memo[1][i];
		res += abs(num0 - num1);
		cnt0 += num0;
		cnt1 += num1;
	  }
	}
	else{
	  failed = true;
	}

	if(!failed){
	  cout << "Case #" << test << ": " << res << endl;
	}else{
	  cout << "Case #" << test << ": Fegla Won" << endl;
	}
  }
  return 0;
}
