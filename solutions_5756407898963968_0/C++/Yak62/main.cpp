#include <fstream>
#include <string>
using namespace std;

void readline(int line[4], istream& is){
	is >> line[0] >> line[1] >> line[2] >> line[3];
}

void read(int arr[4], istream& is){
	int nrow;
	is >> nrow;

	int _[4];
	int r = 0;
	while (++r < nrow)
		readline(_, is);
	readline(arr, is);
	while (r++ < 4)
		readline(_, is);
}

int main(int argc, char** argv){
	if (argc != 3)
		return -1;

	ifstream ifs;
	ifs.open(argv[1]);

	ofstream ofs;
	ofs.open(argv[2]);

	int T;
	ifs >> T;

	for (int i = 0; i < T; i++){
		ofs << "Case #" << i + 1 << ": ";
		int first[4], second[4];
		read(first, ifs);
		read(second, ifs);

		int res = -1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (first[i] == second[j])
					if (res < 0)
						res = first[i];
					else{
						ofs << "Bad magician!" << endl;
						goto NextCase;
					}

		if (res < 0)
			ofs << "Volunteer cheated!" << endl;
		else
			ofs << res << endl;

	NextCase:
		;
	}

	ifs.close();
	ofs.close();
}