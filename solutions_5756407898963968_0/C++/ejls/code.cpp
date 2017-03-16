#include <iostream>
#include <bitset>

typedef std::bitset<16> cs;

cs read_cs(int col){
	cs r;
	for(char y=0; y<4; ++y)
		for(char x=0; x<4; ++x){
			int c;
			std::cin >> c;
			if(y==col)
				r.set(c-1);
		}
	return r;
}

int cs2col(cs x){
	for(int i=0; i<16; ++i)
		if(x.test(i))
			return i+1;
}

int main(){
	int T;
	std::cin >> T;
	for(int t=1; t<=T; ++t){
		int col;
		std::cin >> col;
		cs c1=read_cs(col-1);
		std::cin >> col;
		cs c2=read_cs(col-1);
		c1&=c2;
		std::cout << "Case #" << t << ": ";
		if(c1.count()==0)
			std::cout << "Volunteer cheated!";
		else if(c1.count()>1)
			std::cout << "Bad magician!";
		else
			std::cout << cs2col(c1);
		std::cout << "\n";
	}
}
