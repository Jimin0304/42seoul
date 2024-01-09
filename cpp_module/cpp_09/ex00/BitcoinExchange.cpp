#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

void BitcoinExchange::ParsingCsvFile()
{
	try {
        std::ifstream file("data.csv");
        if (!file.is_open())
            throw std::runtime_error("Failed to open the file.");

		// 진행 중
		std::string line;
    	while (std::getline(file, line)) {
			std::vector<std::string> result = splitString(line, ',');

			std::string key = result[0];
			std::string value = result[1];

			// map에 데이터 추가
			dataMap.insert(std::make_pair(key, value));
		}

        file.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// 문자열을 구분자(delimiter)로 나누는 함수
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}