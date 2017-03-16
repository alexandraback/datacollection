// Round 1B 2014 problem A
// Saurav Shekhar
#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7
#define INF 2000000000
#define P 1000000009

typedef unsigned int ui;
typedef unsigned long long llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 105; 
int size1;
int N;

int dist(int * count)
{
	sort(count, count+N);
	int median = count[ N / 2];
	int ans = 0;
	for(int i=0; i<N; i++)
		ans += abs(median - count[i]);

	return ans;
}

void solve(vector<string> s)
{
	int count[LIM];
	int ans = 0;
	int index[LIM] = {0};
	for(int i=0; i<size1; i++) {
		for(int j=0; j<N;j++) {
			index[j]++;
			count[j] = 1;
			while(index[j] < s[j].size() && s[j][index[j]] == s[j][index[j]-1]) { index[j]++; count[j]++; }
		}
		ans += dist(count);
	}
	cout << ans << "\n";
}

int main()
{
  ui T,qq;

  vector<string> comp;
  vector<string> strs;

  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
	cin >> N;
	strs.clear();
	comp.clear();
	for(int i=0; i<N; i++) {
		strs.push_back("");
		comp.push_back("");
		cin >> strs[i];
	}

	for(int i=0; i<N; i++) {
		// compress strs[i]
		int j = 0, k =0;
		comp[i] = "";
		comp[i] += strs[i][0];
		j=1;
		while(j<strs[i].size()) {
			while(j<strs[i].size() && strs[i][j] == comp[i][k]) j++;
			if(j < strs[i].size()) { comp[i] += strs[i][j]; k++; j++;} 
		}
	}

	bool flag = true;
	for(int i=1; i<N; i++)
		if(comp[i] != comp[i-1])
			flag = false;

	if(flag == false) cout << "Fegla Won\n";
	else {
		size1 = comp[0].size();
		solve( strs );
	}



  }
	
  return 0;
}
