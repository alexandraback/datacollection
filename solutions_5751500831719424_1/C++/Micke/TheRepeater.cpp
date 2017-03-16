#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace
{
	template<typename T>
	T getValue(std::istream& input)
	{
		T value;
		input >> value;
		return value;
	}

	template<typename T>
	std::string toString(const T& value)
	{
		std::stringstream stream;
		stream << value;
		return stream.str();
	}

	struct CaseData
	{
		std::vector<std::string> strings;
	};

	struct ResultData
	{
		int minimumMoves;
	};

	CaseData readCaseData(std::istream& input)
	{
		CaseData data;

		unsigned stringCount = getValue<unsigned>(input);

		data.strings = std::vector<std::string>(stringCount);

		for (unsigned stringIndex = 0; stringIndex < stringCount; ++stringIndex)
			data.strings[stringIndex] = getValue<std::string>(input);

		return data;
	}

	int countSubMoves(const unsigned modelCount, const unsigned itemCount)
	{
		if (itemCount <= 0)
			return -1;

		return abs(static_cast<int>(modelCount) - static_cast<int>(itemCount));
	}

	int smiliarizeString(const std::string& model, std::string item)
	{
		int count = 0;

		int itemIndex = 0;
		for (unsigned modelIndex = 0; modelIndex < model.size(); ++modelIndex)
		{
			unsigned charCount = 1;
			char modelChar = model[modelIndex];
			while (model[modelIndex + 1] == modelChar)
			{
				++charCount;
				++modelIndex;
			}

			unsigned itemCount = 0;
			while (item[itemIndex] == modelChar)
			{
				++itemCount; 
				++itemIndex;
			}

			int segmentCount = countSubMoves(charCount, itemCount);
			if (segmentCount < 0)
				return -1;

			count += segmentCount;
		}

		return count;
	}

	int totalSimilarizeStrings(const std::vector<std::string>& strings, const size_t& modelIndex)
	{
		int totalCount = 0;

		for (size_t index = 0; index < strings.size(); ++index)
		{
			if (index == modelIndex)
				continue;

			int count = smiliarizeString(strings[index], strings[modelIndex]);
			if (count < 0)
				return -1;

			totalCount += count;
		}

		return totalCount;
	}

	std::list<char> segmentChars(const std::string& value)
	{
		std::list<char> chars;

		char item = value[0];
		chars.push_back(item);

		for (size_t index = 0; index < value.size(); ++index)
		{
			if (value[index] != item)
			{
				item = value[index];
				chars.push_back(item);
			}
		}

		return chars;
	}

	bool equalLists(const std::list<char>& list1, const std::list<char>& list2)
	{
		if (list1.size() != list2.size())
			return false;

		std::list<char>::const_iterator it2 = list2.begin();
		for (std::list<char>::const_iterator it1 = list1.begin(); it1 != list1.end(); ++it1, ++it2)
			if (*it1 != *it2)
				return false;

		return true;
	}

	int findSegmentMoves(const std::vector<std::vector<int>>& stringSegments, const size_t modelStringIndex, const size_t segmentIndex)
	{
		int count = 0;

		for (size_t stringIndex = 0; stringIndex < stringSegments.size(); ++stringIndex)
		{
			if (stringIndex == modelStringIndex)
				continue;

			int stringMoves = countSubMoves(stringSegments[modelStringIndex][segmentIndex], stringSegments[stringIndex][segmentIndex]);
			if (stringMoves < 0)
				return -1;

			count += stringMoves;
		}

		return count;
	}

	int findMinimumSegmentMoves(const std::vector<std::vector<int>>& stringSegments, const size_t segmentIndex)
	{
		int minimumMoves = INT_MAX;

		for (size_t stringIndex = 0; stringIndex <stringSegments.size(); ++stringIndex)
		{
			int moves = findSegmentMoves(stringSegments, stringIndex, segmentIndex);
			if (moves < 0)
				return -1;

			if (minimumMoves > moves)
				minimumMoves = moves;
		}

		return minimumMoves;
	}

	int findMinimumMoves(const std::vector<std::string>& strings)
	{
		std::list<char> segments = segmentChars(strings[0]);

		std::vector<std::vector<int>> stringSegmentLengths(strings.size(), std::vector<int>(segments.size(), 0));
		for (size_t stringIndex = 0; stringIndex < strings.size(); ++stringIndex)
		{
			std::list<char> stringSegments = segmentChars(strings[stringIndex]);
			if (!equalLists(segments, stringSegments))
				return -1;

			size_t segmentIndex = 0;
			std::list<char>::const_iterator segmentChar = stringSegments.begin();
			for (size_t position = 0; position < strings[stringIndex].size(); ++position)
			{
				if (strings[stringIndex][position] != *segmentChar)
				{
					++segmentIndex;
					++segmentChar;
				}
				++stringSegmentLengths[stringIndex][segmentIndex];
			}
		}

		int moveCount = 0;

		for (size_t segmentIndex = 0; segmentIndex < segments.size(); ++segmentIndex)
		{
			int segmentMoves = findMinimumSegmentMoves(stringSegmentLengths, segmentIndex);
			if (segmentMoves < 0)
				return -1;

			moveCount += segmentMoves;
		}

		return moveCount;
	}

	ResultData processData(const CaseData& data)
	{
		ResultData result;
		result.minimumMoves = findMinimumMoves(data.strings);
		return result;
	}

	std::string writeResultData(const ResultData& result)
	{
		if (result.minimumMoves < 0)
			return "Fegla Won";
		else
			return toString(result.minimumMoves);
	}
}

int main(int argc, char** argv)
{
	std::ifstream input("a.in");
	std::ofstream output("a.out");

	unsigned cases = getValue<unsigned>(input);

	for (unsigned caseIndex = 0; caseIndex < cases; ++caseIndex)
		output << "Case #" << caseIndex + 1 << ": " << writeResultData(processData(readCaseData(input))) << std::endl;

	input.close();
	output.close();

	return 0;
}

