#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;

pair <int,int> isi[1111];

int main() {

	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){
		printf("Case #%d:",tt++);

		memset(isi, 0, sizeof isi);

		int N;
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&isi[i].first);
			isi[i].second = i;
		}

		sort(isi,isi +N);
		while(isi[N-1].first > isi[N-2].first){
			printf(" %c",isi[N-1].second + 'A');
			isi[N-1].first--;
		}
		for (int i=0;i<N - 2;i++){
			for (int j=0;j<isi[i].first;j++)
				printf(" %c",isi[i].second + 'A');
		}

		for (int j=0;j<isi[N-1].first;j++)
			printf(" %c%c",isi[N-2].second + 'A', isi[N-1].second + 'A');

		printf("\n");

	}
}