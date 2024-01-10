#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		void ParsingCsvFile();
		std::vector<std::string> splitString(const std::string& input, char delimiter);
		void CheckDateFormat(std::string date);
		double CheckValue(std::string value);
		void PrintBitcoin(char *inputFile);

	private:
		std::map<std::string, double> dataMap;
};

#endif