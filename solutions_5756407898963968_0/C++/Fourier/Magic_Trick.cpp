//============================================================================
// Name        : Magic_Trick.cpp
// Author      : von Bergen, Federico
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <fstream>
#include <ios>
#include <iostream>
using std::cerr;
using std::endl;
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include <vector>

#include "Magic_Trick.h"
#include "defines.h"

int main(void){
	std::ifstream input_file(INPUT_FILENAME,std::ifstream::in);
	std::ofstream output_file(OUTPUT_FILENAME,std::ifstream::out);
	std::string line;
	std::size_t substr_start = 0,substr_end = std::string::npos;
	std::vector< std::vector<std::string> > case_information(LINES_PER_CASE);
	std::vector< std::vector<int> > first_matrix(COLUMNS_PER_ROW,std::vector<int>(COLUMNS_PER_ROW)),second_matrix(COLUMNS_PER_ROW,std::vector<int>(COLUMNS_PER_ROW));
	char ** endptr = NULL;
	size_t case_number,quant_test_cases,first_answer_number,second_answer_number,quant_repeated_cards,i,j;
	int number_1,number_2,chosen_card,aux_matrix_number;

	try{
		if(input_file.fail())
			throw std::runtime_error("The input file couldn't be opened.");
		if(output_file.fail())
			throw std::runtime_error("The output file couldn't be opened.");
		getline(input_file,line);
		quant_test_cases = strtol(line.c_str(),endptr,10);
		if(endptr != NULL)
			throw std::runtime_error("The input file is incorrect.");
		if(quant_test_cases < MIN_QUANT_TEST_CASES || quant_test_cases > MAX_QUANT_TEST_CASES)
			throw std::runtime_error("The number of cases isn't within the limits.");
		for(case_number = 0;input_file.good() && case_number < quant_test_cases;case_number++){
			/*Read from input file.*/
			for(i = 0;i < LINES_PER_CASE;i++){
				getline(input_file,line);
				substr_start = 0;
				substr_end = line.find(INPUT_FILE_DELIMITER,substr_start);
				case_information[i].push_back(line.substr(substr_start,substr_end));
				while(substr_end != std::string::npos){
					substr_start = ++substr_end;
					substr_end = line.find(INPUT_FILE_DELIMITER,substr_start);
					case_information[i].push_back(line.substr(substr_start,substr_end-substr_start));
				}
			}
			/*Validate and load the answers.*/
			if(case_information[FIRST_ANSWER_POS].size() == 1 && case_information[SECOND_ANSWER_POS].size() == 1){
				first_answer_number = strtol(case_information[FIRST_ANSWER_POS][0].c_str(),endptr,10);
				if(endptr != NULL)
					throw std::runtime_error("The input file is incorrect.");
				if(first_answer_number < MIN_ANSWER_NUMBER || first_answer_number > MAX_ANSWER_NUMBER)
					throw std::runtime_error("The first answer number isn't within the limits.");
				second_answer_number = strtol(case_information[SECOND_ANSWER_POS][0].c_str(),endptr,10);
				if(second_answer_number < MIN_ANSWER_NUMBER || first_answer_number > MAX_ANSWER_NUMBER)
					throw std::runtime_error("The second answer number isn't within the limits.");
				if(endptr != NULL)
					throw std::runtime_error("The input file is incorrect.");
			}
			else
				throw std::runtime_error("The input file is incorrect.");
			/*Validate the card's matrix.*/
			for(i = 0;i < LINES_PER_CASE;i++){
				if(i == FIRST_ANSWER_POS || i == SECOND_ANSWER_POS)
					continue;
				if(case_information[i].size() != COLUMNS_PER_ROW)
					throw std::runtime_error("The input file is incorrect.");
			}
			/*Load matrices.*/
			for(i = 0;i < COLUMNS_PER_ROW;i++){
				for(j = 0;j < COLUMNS_PER_ROW;j++){
					aux_matrix_number = strtol(case_information[i + FIRST_MATRIX_START_POS][j].c_str(),endptr,10);
					if(endptr != NULL)
						throw std::runtime_error("The input file is incorrect.");
					if(aux_matrix_number < MIN_CARD_NUMBER || aux_matrix_number > MAX_CARD_NUMBER)
						throw std::runtime_error("There is a card number that isn't within limits.");
					first_matrix[i][j] = aux_matrix_number;
				}
			}
			for(i = 0;i < COLUMNS_PER_ROW;i++){
				for(j = 0;j < COLUMNS_PER_ROW;j++){
					aux_matrix_number = strtol(case_information[i + SECOND_MATRIX_START_POS][j].c_str(),endptr,10);
					if(endptr != NULL)
						throw std::runtime_error("The input file is incorrect.");
					if(aux_matrix_number < MIN_CARD_NUMBER || aux_matrix_number > MAX_CARD_NUMBER)
						throw std::runtime_error("There is a card number that isn't within limits.");
					second_matrix[i][j] = aux_matrix_number;
				}
			}
			/*Check the matrices.*/
			quant_repeated_cards = 0;
			for(i = 0;i < COLUMNS_PER_ROW;i++){
				number_1 = first_matrix[first_answer_number - 1][i];
				for(j = 0;j < COLUMNS_PER_ROW;j++){
					number_2 = second_matrix[second_answer_number - 1][j];
					if(number_1 == number_2){
						quant_repeated_cards++;
						chosen_card = number_1;
					}
				}
			}
			/*Write to output file.*/
			if(quant_repeated_cards == 0)
				output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << CHAR_SPACE << "Volunteer cheated!" << endl;
			else if(quant_repeated_cards == 1)
				output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << CHAR_SPACE << chosen_card << endl;
			else
				output_file << "Case" << CHAR_SPACE << CHAR_NUMBER_SIGN << case_number + 1 << CHAR_COLON << CHAR_SPACE << "Bad magician!" << endl;
			/*Clear information to use the information variable again.*/
			for(i = 0;i < LINES_PER_CASE;i++){
				case_information[i].clear();
			}
		}
		getline(input_file,line);	/*Read the last empty line.*/
		if(!input_file.eof())
			throw std::runtime_error("There was an error reading the input file.");
		input_file.close();
		output_file.close();
		if(quant_test_cases != case_number)
			throw std::runtime_error("The input file doesn't contain the amount of cases declared in the header.");
	}
	catch(std::runtime_error & exception){
		cerr << "Magic_Trick:" << CHAR_SPACE << exception.what() << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
