#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;
#define INPFILE "input.in"
#define OUTFILE "output.out"

ifstream inp;
ofstream out;

class Linker {
public:
	Linker(int num, string nm) :mNum(num), name(nm), mParent(nullptr) {

	}
	void join(shared_ptr<Linker> par) {
		//par = par->GetParent();
		while (par->mParent) 
			par = par->mParent;
		if (mParent == nullptr)
			mParent = par;
		else {
			shared_ptr<Linker> npar = GetParent();
			npar->mParent = par;
		}
	}
	int getnum() {
		if(mParent == nullptr)
			return mNum;
		shared_ptr<Linker> npar = GetParent();
		return npar->mNum;
	}
protected:
	shared_ptr<Linker> GetParent() {
		if (mParent == nullptr)
			return nullptr;
		shared_ptr<Linker> npar = mParent;
		while (npar->mParent)
			npar = npar->mParent;
		return npar;
	}
	shared_ptr<Linker> mParent;
	int mNum;
	string name;
};

template <typename T>
struct DLLNode {
	T mVal;
	shared_ptr<DLLNode> prev, next;
	DLLNode(T val):mVal(val), prev(nullptr), next(nullptr){}
};


void calculate(int t) {

	int N;
	inp >> N;
	vector<int> P(N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int a;
		inp >> a;
		P[i] = a;
		sum += a;
	}
	int max = 1;
	out << "Case #" << t + 1 << ":";
	bool isFirst = false;
	if (sum & 1)
		isFirst = true;
	while (max > 0) {
		max = 0;
		int id = 0;
		for (int i = 0; i < N; i++) {
			if (P[i] > max) {
				max = P[i];
				id = i;
			}
		}
		if (max == 0)
			break;
		out << " ";
		char ch = 'A' + id;
		out << ch;
		P[id]--;
		if (isFirst) {
			isFirst = false;
			continue;
		}

		max = 0;
		id = 0;
		for (int i = 0; i < N; i++) {
			if (P[i] > max) {
				max = P[i];
				id = i;
			}
		}
		if (max == 0)
			break;
		ch = 'A' + id;
		out << ch;
		P[id]--;
	}
	out << endl;
}


int main() {
	int T;
	inp.open(INPFILE);
	out.open(OUTFILE);
	inp >> T;
	for (int t = 0; t < T; t++) {
		calculate(t);
	}
}
