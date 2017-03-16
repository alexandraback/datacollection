#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

size_t get_result_non_const(const std::vector<size_t>& vals)
{
    size_t result = 0;

    for (size_t idx = 1; idx < vals.size(); ++idx)
    {
        if (vals[idx] < vals[idx - 1])
        {
            result += vals[idx - 1] - vals[idx];
        }
    }

    return result;
}

size_t get_result_const(const std::vector<size_t>& vals)
{
    size_t max_diff = 0;
    for (size_t idx = 1; idx < vals.size(); ++idx)
    {
        if (vals[idx] < vals[idx - 1])
        {
            max_diff = std::max(max_diff, vals[idx - 1] - vals[idx]);
        }
    }

    if (0 == max_diff)
    {
        return 0;
    }
    
    size_t count = vals[0];
    size_t result = 0;

    for (size_t idx = 1; idx < vals.size(); ++idx)
    {
        result += std::min(count, max_diff);
        count = vals[idx];
    }

    return result;
}

int main(int argc, char** argv)
{
    if (2 > argc)
    {
        std::cerr << argv[0] << " inputfile [outputfile]" << std::endl;
        return 1;
    }
    std::string infile{argv[1]};
    std::string outfile{infile};
    if (2 < argc)
    {
        outfile = argv[2];
    }
    else
    {
        outfile += ".out";
    }

    std::ifstream in(infile);
    std::ofstream out(outfile);
    if (!in.good())
    {
        std::cerr << "Bad input file" << std::endl;
        return 2;
    }

    if (!out.good())
    {
        std::cerr << "Bad output file" << std::endl;
        return 3;
    }

    int cases;
    in >> cases;

    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        size_t total;
        in >> total;

        std::vector<size_t> counts(total);
        for (size_t i = 0; i < total; ++i)
        {
            in >> counts[i];
        }
        
        out << "Case #" << caseno << ": " << get_result_non_const(counts) << ' ' << get_result_const(counts) << '\n';
    }
    out.flush();
}
