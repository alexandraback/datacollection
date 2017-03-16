#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void){

	freopen("A-large.in","r",stdin);
	freopen("al.out","w",stdout);

	int t;
	int freq[100][100];
	char letter[100][100];
	int len[100];
	cin>>t;
	double aver[100];
	int aver_i[100];
	int sortArr[100];

	for(int test=0;test<t;test++){
		int n;
		int i,j,k;
		cin>>n;
		vector<string> strs;
		for(i=0;i<n;i++){
			string str;
			cin>>str;
			strs.push_back(str);
		}
		for(i=0;i<n;i++){
			j = 1;
			k = 0;
			freq[i][0] = 1;
			letter[i][k] = strs[i][0];
			
			while(j<strs[i].length()){
				if(strs[i][j]!=strs[i][j-1]){
					k++;
					letter[i][k] = strs[i][j];
					freq[i][k] = 0;
				}
				freq[i][k]++;
				j++;
			}
			len[i] = k;

		}
		
		bool check = false;
		
		

		for(i=1;i<n;i++){
			if(len[i]!=len[i-1])check = true;
		}
		
		
		if(check){
			printf("Case #%d: Fegla Won\n",test+1);
		}else {

			

			for(i=0;i<=len[0];i++){
				for(j=1;j<n;j++){
					if(letter[j][i]!=letter[j-1][i]){
						check = true;
					}
				}
			}
			if(check){
				printf("Case #%d: Fegla Won\n",test+1);
			}else {

				

				for(i=0;i<=len[0];i++){
					for(j=0;j<n;j++){
						sortArr[j] = freq[j][i];
					}
					sort(sortArr,sortArr+n);
					aver_i[i] = sortArr[n/2];
				}

				

				int sum = 0;
				for(i=0;i<=len[0];i++){
					for(j=0;j<n;j++){
						sum+=abs(freq[j][i]-aver_i[i]);
					}
				}

				printf("Case #%d: %d\n",test+1,sum);
			}
		}

		
		
	}


}