#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> read_row(std::ifstream& ifile)
{
    int volunteer, tmp;
    ifile >> volunteer;
    std::vector<int> vec;
    for (int irow = 0; irow < 4; ++ irow)
    {
	for (int jrow = 0; jrow < 4; ++ jrow)
	{
	    ifile >> tmp;
	    if (volunteer == irow + 1)
	    {
		vec.push_back(tmp);
	    }
	}
    }
    std::sort(vec.begin(), vec.end());
    return vec;
}
void solve_trick(int icase, std::ifstream& ifile)
{
    auto val1 = read_row(ifile);
    auto val2 = read_row(ifile);
    std::vector<int> res(8);
    auto resend = std::set_intersection(val1.begin(), val1.end(), val2.begin(), val2.end(), res.begin());
    res.resize(static_cast<size_t>(std::distance(res.begin(), resend)));
    std::cout << "Case #" << icase << ": ";
    int i = res.empty() ? -2 : (res.size() > 1 ? -1 : res[0]);
    if (i < 0) {
	std::cout << (i == -1 ? "Bad magician!\n" : "Volunteer cheated!\n");
    } 
    else 
	std::cout << i << std::endl;
}

void all_tricks(std::ifstream& ifile)
{
    int ncases;
    ifile >> ncases;
    for (int i = 0; i < ncases; ++ i)
    {
	solve_trick(i+1, ifile);
    }
}

int main(int argv, char** argc)
{
    if (argv < 2)
    {
	std::cerr << "Usage: " << std::string(argc[0]) << " inputfile\n";
	return -1;
    }
    std::ifstream infile(argc[1]);
    all_tricks(infile);
}
