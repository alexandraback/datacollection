#include <iostream>

int main(){
	int arr[2][4];
	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++){
		for(int i = 0; i < 2; i++){
			int row, t;
			std::cin >> row;
			for(int j = 1; j <= 4; j++)
				for (int k = 0; k < 4; k++)
					if (j == row)
						std::cin >> arr[i][k];
					else std::cin >> t;
		}
		bool good = true;
		int card = 0;
		for(int i = 0; good && i < 4; i++)
			for(int j = 0; good && j < 4; j++)
				if(arr[0][i] == arr[1][j])
					if (card == 0) card = arr[0][i];
					else good = false;
		std::cout << "Case #" << cas << ": ";
		if(good && card > 0)
			std::cout << card;
		else 
			std::cout << (good ? "Volunteer cheated!" : "Bad magician!");
		std::cout << std::endl;
	}
	return 0;
}