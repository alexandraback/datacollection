#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 100005
#define INF (ll)1e18
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int cnt[26];

int main(){
	ios_base::sync_with_stdio(false);
	int t, T=1;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		for(int i=0 ; i<26 ; i++)
			cnt[i] = 0;

		for(int i=0 ; i<n ; i++){
			int a;
			cin>>a;
			cnt[i] = a;
		}

		bool flag = true;

		vector<string> answer;

		while(flag){
			int num = 0, temp = 0, total = 0;
			for(int i=0 ; i<26 ; i++){
				temp = max(temp, cnt[i]);
				if(temp == cnt[i])
					num = i;
				total += cnt[i];
			}

			if(temp == 0)
				break;

			cnt[num]--;
			total--;

			string ans;
			ans.pb('A' + num);

			num = temp = 0;

			for(int i=0 ; i<26 ; i++){
				temp = max(temp, cnt[i]);
				if(temp == cnt[i])
					num = i;
			}

			if(temp != 0){
				total--;
				cnt[num]--;
				bool flag = true;
				for(int i=0 ; i<26 ; i++){
					if(cnt[i]>total/2)
						flag = false;
				}

				if(flag){
					ans.pb('A' + num);
				} else {
					total++;
					cnt[num]++;
				}
			}

			answer.pb(ans);
		}

		cout<<"Case #"<<T++<<": ";

		for(int i=0 ; i<answer.size() ; i++)
			cout<<answer[i]<<" ";
		cout<<"\n";
	}

	return 0;
}