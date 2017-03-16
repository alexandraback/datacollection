#include<iostream>
#include<fstream>
using std::cout;
using std::endl;
int arr[1024];
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("A-small-attempt0.in", std::ios_base::in);
	fout.open("a-small0.out", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		int N;
		fin >> N;
		
		for (int i = 0; i <
			N; i++){
			fin >> arr[i];
		}
		//do
		int ans = 0, ans2 = 0;
		int maxDiff = 0;
		for (int i = 1; i < N; i++){
			//get max diff
			int diff =arr[i-1] - arr[i];
			if (diff>maxDiff)maxDiff = diff;
			if (diff > 0)ans += diff;
		}
		cout << "maxdiff:" <<maxDiff << endl;
		for (int i = 1; i < N; i++){
			//calc for second method
			if (arr[i - 1] < maxDiff)ans2 += arr[i - 1];
			else ans2 += maxDiff;
		}
		fout << "Case #" << times << ": " << ans<< " " << ans2 << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}