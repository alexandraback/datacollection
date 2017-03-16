#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
#include<stdlib.h>

using namespace std;


int main(void){

	FILE *pFile = fopen("A-large.txt", "r");
	FILE *oFile = fopen("A_out.txt", "w");

	int testcase;
	fscanf(pFile, "%d", &testcase);

	for(int test = 1; test <= testcase; test++){
		
		int num;
		fscanf(pFile, "%d", &num);

		vector<pair<int, int> > arr;

		arr.resize(num);

		for (int i = 0; i < num; i++){
			fscanf(pFile, "%d", &arr[i].first);
			arr[i].second = i;
		}
		//입력 완료

		fprintf(oFile, "Case #%d: ", test);

		while (true){

			sort(arr.begin(), arr.end(), greater<pair<int, int>>());

			int flag = -1;
			for (int i = 0; i < num; i++){
				if (arr[i].first > 0){
					flag = 0;
					break;
				}
			}
			if (flag == -1){
				break;				
			}
		
			int first = arr[0].second;
			arr[0].first--;


			sort(arr.begin(), arr.end(), greater<pair<int, int>>());

			int sum = 0;
			for (int i = 0; i < num; i++){
				sum += arr[i].first;
			}
			
			if (sum == 2){
				
				fprintf(oFile, "%c ", first+'A');
				//출력하고
				continue;
			}
			else{
				int second = arr[0].second;
				arr[0].first--;

				fprintf(oFile, "%c%c ", first + 'A', second+'A');

			}
		}

		fprintf(oFile, "\n");
	}

	return 0;

}