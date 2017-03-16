#include<iostream>
#include<fstream>
using std::cout;
using std::endl;
int arr[1024];
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("B-small-attempt0.in", std::ios_base::in);
	fout.open("B-0.out", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		int R,C,N;
		fin >> R>>C>>N;
		int size = R*C;
		int ans = 987654321;
		int bm = (1 << size) - 1;
		//do ALL
		if (R*C > N * 2){
			ans = 0;
			
		}
		else for (int subset = bm; subset; subset = (subset - 1)&bm){
			//calc num
			int p = __popcnt(subset);
			if (p != N)continue;
			//calc unhappy
			int uh = 0;
			for (int i = 0; i < C; i++){
				for (int j = 1; j < R; j++){
					if (((subset & (1 << (i*R + j))) != 0) && (((subset & (1 << (i*R + j - 1)))) != 0)){
						uh++;
						//printf("%d,%d uh right\n", i, j);
					}
				}
			}
			for (int i = 1; i < C; i++){
				for (int j = 0; j < R; j++){
					if (((subset & (1 << (i*R + j))) != 0) && (((subset & (1 << (i*R + j - R)))) != 0)){
						uh++;
						//printf("%d,%d uh left\n", i, j);
					}
				}
			}
			//
			if (uh < ans){
				ans = uh;
				
			}
			if (ans == 0)break;
		}
		//

		fout << "Case #" << times << ": " << ans  << "\n";
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}