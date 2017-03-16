/**
 * @file a.cpp
 *
 * @brief CodeJam problem A solution.
 *
 * @author apollyon <alejandro.claro@gmail.com>
 *
 * @copyright 2014 Alejandro Claro.
 */

/* PRAGMAS *******************************************************************/

// #pragma comment (linker, "/STACK:256000000")

/* INCLUDES ******************************************************************/

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

/* DECLARATIONS **************************************************************/

struct Input
{
  std::vector<std::string> words;
};

struct Output
{
  size_t moves;
};

/* PROTOTYPES ****************************************************************/

bool solve(const Input& input, Output& output);
void readInput(Input& input);
void writeOutput(const Output& output);
void writeInsoluble();

/* IMPLEMENTATION ************************************************************/

int
main(int argc, char** argv)
{
  size_t casesCount = 0;

  if (argc > 1)
    std::freopen(argv[1], "r", stdin);

  if (argc > 2)
    std::freopen(argv[2], "w", stdout);

  std::cin >> casesCount;

  for(size_t i = 1; i <= casesCount; ++i)
  {
    Input  input;
    Output output;

    readInput(input);

    std::cout << "Case #" << i << ": ";

    if (solve(input, output) == true)
      writeOutput(output);
    else
      writeInsoluble();

    std::cout << std::endl;
  }

  return 0;
}

std::vector<std::string>
splitWord(std::string str)
{
  std::vector<std::string> result;
  size_t last = 0;

  for (size_t i = 1; i < str.size(); ++i)
  {
    if (str[i] != str[i-1])
    {
      result.push_back(str.substr(last, i - last));
      last = i;
    }
  }

  result.push_back(str.substr(last, str.size() - last));

  return result;
}

bool
solve(const Input& input, Output& output)
{
  std::vector<std::string> words = input.words;

  std::sort(words.begin(), words.end());
  output.moves = 0;

  std::vector< std::vector<std::string> > splited;

  for (size_t i = 0; i < words.size(); ++i)
  {
    std::vector<std::string> splitedWord = splitWord(words[i]);

    if (i > 0)
    {
      if (splitedWord.size() != splited[0].size())
        return false;

      for (size_t k = 0 ; k < splitedWord.size(); ++k)
      {
        if (splitedWord[k][0] != splited[0][k][0])
          return false;
      }
    }

    splited.push_back(splitedWord);
  }

  for (size_t i = 0; i < splited[0].size(); ++i)
  {
    size_t sectionMoves = std::numeric_limits<size_t>::max();

    for (size_t j = 0; j < words.size(); ++j)
    {
      std::string reference = splited[j][i];
      size_t stepMoves = 0;

      for (size_t k = 0; k < words.size(); ++k)
        stepMoves += reference.size() > splited[k][i].size() ? reference.size() - splited[k][i].size() : splited[k][i].size() - reference.size();

      sectionMoves = std::min(sectionMoves, stepMoves);
    }

    output.moves += sectionMoves;
  }

  return true;
}

void
readInput(Input& input)
{
  size_t n;

  std::cin >> n;

  for (size_t i = 0; i < n;++i)
  {
    std::string word;

    std::cin >> word;
    input.words.push_back(word);
  }
}

void
writeOutput(const Output& output)
{
  std::cout << output.moves;
}

void
writeInsoluble()
{
  std::cout << "Fegla Won";
}
