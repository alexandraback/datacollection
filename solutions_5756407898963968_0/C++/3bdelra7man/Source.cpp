#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	int T;
	scanf("%d" , &T);
	for(int h=0 ; h<T ; h++){
		printf("Case #%d: " , h+1);		
		int r;
		vector<int> vec1(4) , vec2(4);
		scanf("%d" , &r);
		r--;
		for(int i=0 ; i<4 ; i++){
			for(int j=0 ; j<4 ; j++){
				int x;
				scanf("%d" , &x);
				if(i == r){
					vec1[j] = x;	
				}
			}
		}
		scanf("%d" , &r);
		r--;
		for(int i=0 ; i<4 ; i++){
			for(int j=0 ; j<4 ; j++){
				int x;
				scanf("%d" , &x);
				if(i == r){
					vec2[j] = x;	
				}
			}
		}
		sort(vec2.begin() , vec2.end());
		int c = 0 , index = -1;
		for(int i=0 ; i<4 ; i++){

			if( binary_search(vec2.begin() , vec2.end() , vec1[i]) ) {
				c++;
				index = i;
			}
		}
		if(c == 1){
			printf("%d\n" , vec1[index]);
		}		
		else if(c == 0){
			printf("Volunteer cheated!\n");
		}
		else printf("Bad magician!\n");
	}
	return 0;
}