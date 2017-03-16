#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		int n,b;
		vector <int> barber;
		scanf("%d %d",&b,&n);
		barber.reserve(b);
		for (int i=0;i<b;i++) {
			int tmp;
			scanf("%d",&tmp);
			barber.push_back(tmp);
		}
		long long int min=0;
		long long int max=1000000000001;
		while (max-min>1) {
			long long int mid=(max+min)/2;
			long long int sum=0;
			for (int i=0;i<b;i++) {
				sum+=mid/barber[i]+1;
			}
			if (sum>=n) {
				max=mid;
			} else {
				min=mid;
			}
		}
		//cout << min << " " << max << endl;
		priority_queue < pair < long long int, int > > bar;
		long long int sum=0;
		if (min!=0) {
			for (int i=0;i<b;i++) {
				sum+=min/barber[i]+1;
				bar.push(pair < long long int, int >(-(min/barber[i]+1)*barber[i],-i-1));
			}
		} else {
			for (int i=0;i<b;i++) {
				bar.push(pair < long long int, int >(-barber[i],-i-1));
			}
		}
		int diff=n-sum;
		for (int i=1;i<diff;i++) {
			pair < long long int, int > akt=bar.top();
			bar.pop();
			//cout << akt.first << endl;
			bar.push(pair < long long int, int > ((akt.first)-barber[-(akt.second)],akt.second));
		}
		pair < long long int, int > akt2=bar.top();
		printf("Case #%d: %d\n",r,-(akt2.second));
	}
	return 0;
}
