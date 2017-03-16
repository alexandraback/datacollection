#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using std::size_t;

struct input_string {
	std::string base_string;
	std::vector<size_t> counts;
	input_string (const std::string& in):  base_string{},
	counts{} {
		size_t tempcounts = 0;
		for (size_t i = 0; i < in.size()-1; ++i) {
			++tempcounts;
			if(in[i]!=in[i+1]) {
				base_string += in[i];
				counts.push_back(tempcounts);
				tempcounts = 0;
			}
		}
		base_string += in.back();
		counts.push_back(tempcounts+1);
	}
};

bool is_winable (const std::vector<input_string>& str) {
	for(size_t i = 1; i < str.size(); ++i) {
		if (str[i].base_string!=str[0].base_string)
			return false;
	}
	return true;
}




int main (int argc, char* argv[]) {
	std::ifstream in {argv[1]};
	std::ofstream out {"outfile.out"};

	size_t numcases;
	in >> numcases;

	for (size_t i = 1; i <= numcases; ++i){
		size_t num_str;
		in >> num_str;
		std::vector<input_string> data;
		for (size_t j = 0; j < num_str; ++j) {
			std::string temp;
			in >> temp;
			data.emplace_back(temp);
		}

		if (!is_winable(data)) {
			out << "Case #" << i << ": Fegla Won\n";
		}
		else {
			size_t erg = 0;

			for (size_t j = 0; j < data[0].counts.size(); ++j) {
				std::nth_element(data.begin(),
					data.begin() + data.size()/2,
					data.end(),
					[&](const input_string& a1,
						const input_string& a2){
						return a1.counts[j] < a2.counts[j];
					});
				for (size_t k = 0; k < data.size(); ++k) {
					erg += abs(long(data[k].counts[j]) -
						long(data[data.size()/2].counts[j]));
				}
			}
			out << "Case #" << i
			 << ": " << erg << '\n';
		}

	}
}