#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
int a[10000];
int t;

LL calc(int b, int *m, LL t){
	LL tot=0;
	for (int i=0;i<b;i++)
		tot += t / m[i] +1;
	return tot;
}

int main(){
	freopen("stdin","r",stdin);
	freopen("stdout","w",stdout);
	scanf("%d",&t);
	for (int time=0;time<t;time++){
		int n,b;
		int m[1010];
		LL lef = 101010, rig = 0;
		scanf("%d", &b);
		cin >> n;
		for (int i=0;i<b;i++){
			scanf("%d", &m[i]);
			lef = min(lef, LL(m[i]));
		}
		rig = lef * n; lef = 0;
		LL mid, ans;
		while (lef < rig){
			mid = (rig + lef) >> 1;
			ans = calc(b, m, mid);
			if (ans<n) lef = mid +1;
			else rig = mid;
		}
		ans = calc(b, m, rig) - n;
		int idx = b-1;
		while ((rig % m[idx]!=0) && (idx>0)) idx--;
		for (; ans>0 && idx>0;){
			idx--;
			if (rig % m[idx]==0)
				ans--;
		}
		printf("Case #%d: %d\n",time+1, idx+1);
	}
	return 0;
}
