#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <numeric>

std::string eval(std::vector<uint16_t> P)
{
    auto result = std::string{};

    auto n_parties_in_room = std::count_if(P.begin(), P.end(), [](const uint16_t& pi) { return pi > 0;});
    auto n_senators_in_room = std::accumulate(P.begin(), P.end(), 0);

    while (n_parties_in_room > 0)
    {
        auto maxIt = std::max_element(P.begin(), P.end());

        auto maxIt1 = std::find(P.begin(), P.end(), *maxIt);
        auto maxIt2 = std::find(maxIt1 + 1, P.end(), *maxIt);

        auto party_character_1 = std::string{ static_cast<char>('A' + std::distance(P.begin(), maxIt1)) };

        if (maxIt2 == P.end())
        {
            if (*maxIt1 > 1)
            {
                if (n_senators_in_room != 3 && n_parties_in_room != 2)
                {
                    *maxIt1 -= 2;
                    n_senators_in_room -= 2;
                    result += party_character_1 + party_character_1 + " ";
                } 
                else
                {
                    *maxIt1 -= 1;
                    n_senators_in_room -= 1;
                    result += party_character_1 + " ";
                }
            } 
            else if (*maxIt1 == 1)
            {
                *maxIt1 -= 1;
                n_senators_in_room -= 1;
                result += party_character_1 + " ";
            }

            if (*maxIt1 == 0)
                n_parties_in_room -= 1;
        } 
        else
        {
            auto party_character_2 = std::string{ static_cast<char>('A' + std::distance(P.begin(), maxIt2)) };

            if (n_senators_in_room != 3 && n_parties_in_room != 3)
            {
                *maxIt1 -= 1;
                *maxIt2 -= 1;
                n_senators_in_room -= 2;

                if (*maxIt1 == 0)
                    n_parties_in_room -= 1;

                if (*maxIt2 == 0)
                    n_parties_in_room -= 1;

                result += party_character_1 + party_character_2 + " ";
            }
            else
            {
                *maxIt1 -= 1;
                n_senators_in_room -= 1;
                result += party_character_1 + " ";

                if (*maxIt1 == 0)
                    n_parties_in_room -= 1;
            }
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <test_file> <output_file>" << std::endl;
        return 1;
    }

    auto inputFilename = argv[1];
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open())
    {
        std::cerr << "File not found: '" << inputFilename << "'" << std::endl;
        return 2;
    }

    auto outputFilename = argv[2];
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open())
    {
        std::cerr << "Could not open file '" << outputFilename << "' for writing." << std::endl;
        return 2;
    }

    uint16_t T;
    inputFile >> T;

    for (uint16_t t = 1; t <= T; ++t)
    {
        uint16_t N;
        inputFile >> N;

        auto P = std::vector<uint16_t>(N, 0);

        for (auto& pi : P)
            inputFile >> pi;

        auto result = eval(P);

        outFile << "Case #" << t << ": " << result << std::endl;
    }
}