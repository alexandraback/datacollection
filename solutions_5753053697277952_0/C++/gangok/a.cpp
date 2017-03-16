#include <fstream>

using namespace std;

int N;
int num[26];

string run() {
	int count = 0;
	int biggest, biggest2;
	int biggest_value;
	char a, b;
	bool same;
	string ret = "";
	for (int i = 0; i < N; i++)
		count += num[i];
	while (count > 0) {
		biggest_value = -1;
		same = false;
		for (int i = 0; i < N; i++) {
			if (biggest_value < num[i]) {
				biggest_value = num[i];
				biggest = i;
				same = false;
			}
			else if (biggest_value == num[i]) {
				biggest2 = i;
				same = true;
			}
		}
		a = biggest + 'A';
		num[biggest]--;
		ret += a;
		count -= 1;
		if (same && (num[biggest2] > (count / 2))) {
			b = biggest2 + 'A';
			num[biggest2]--;
			ret += b;
			count -= 1;
			ret += ' ';
		}
		else {
			ret += ' ';
		}			
	}
	return ret;
}

int main() {
	int T;
	ifstream in("A-small-attempt0.in");
	ofstream out("output_a.txt");
	in >> T;
	for (int t = 0; t < T; t++) {
		in >> N;
		for (int i = 0; i < N; i++)
			in >> num[i];
		string temp = run();
		//read file
		//run
		//output
		out << "Case #" << t + 1 << ": " << temp.c_str() << endl;
	}
	in.close();
	out.close();
	return 0;
}