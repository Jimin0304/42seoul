#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ): dataMap(src.dataMap) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->dataMap = rhs.dataMap;
	}
	return *this;
}

void BitcoinExchange::ParsingCsvFile()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("failed to open the file.");

	std::string line;
	std::getline(file, line);	// 첫 줄 제외
	while (std::getline(file, line)) {
		if (line.empty()) { continue; }
		size_t index = line.std::string::find(",");
		std::string key = line.std::string::substr(0, index);
		std::string value = line.std::string::substr(index + 1);

		CheckDateFormat(key);				// valid date 검사
		
		char *tmp;
		double dvalue = std::strtod(value.c_str(), &tmp);
		if (*tmp != '\0')	// strtod 예외처리
			throw std::logic_error("invalid argument in csv file.");
		dataMap.insert(std::make_pair(key, dvalue));
	}

	file.close();
}

void BitcoinExchange::CheckDateFormat(std::string date)
{
	if (date.length() != 10)
		throw std::logic_error("bad input => " + date);
		
	int year, month, day;
	size_t firstIndex = date.std::string::find("-");
	size_t SecondIndex = date.std::string::find("-", firstIndex + 1);
	if (firstIndex == std::string::npos || SecondIndex == std::string::npos)
		throw std::logic_error("bad input => " + date);
	std::istringstream(date.std::string::substr(0, firstIndex)) >> year;
	std::istringstream(date.std::string::substr(firstIndex + 1, SecondIndex - (firstIndex + 1))) >> month;
	std::istringstream(date.std::string::substr(SecondIndex + 1)) >> day;

	if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		throw std::logic_error("bad input => " + date);
	if ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))
		throw std::logic_error("bad input => " + date);
	if (month == 2) {	// 윤년 검사
		if (year % 400 == 0 && day > 29)		// 윤년
			throw std::logic_error("bad input => " + date);
		else if (year % 100 == 0 && day > 28)	// 평년
			throw std::logic_error("bad input => " + date);
		else if (year % 4 == 0 && day > 29)		// 윤년
			throw std::logic_error("bad input => " + date);
		else if (day > 28)						// 평년
			throw std::logic_error("bad input => " + date);
	}
}

double BitcoinExchange::CheckValue(std::string value)
{
	char *tmp;
	double dvalue = std::strtod(value.c_str(), &tmp);
	if (*tmp != '\0')	// strtod 예외처리
		throw std::logic_error("bad input => " + value);
	if (dvalue < 0.0)
		throw std::logic_error("not a positive number.");
	if (dvalue > 1000.0)
		throw std::logic_error("too large a number.");
	return dvalue;
}

std::string BitcoinExchange::DoubleToString(double value)
{
	std::ostringstream out;
    out << std::fixed << std::setprecision(10) << value;
    std::string str = out.str();
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	str.erase(str.find_last_not_of('.') + 1, std::string::npos);
	return str;
}

void BitcoinExchange::PrintBitcoin(char *inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << "Error: failed to open the file." << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty()) { continue; }
		try {
			size_t index = line.std::string::find("|");
			if (index == std::string::npos)
				throw std::logic_error("invalid format. [date | value]");
			std::string date = line.std::string::substr(0, index - 1);
			std::string value = line.std::string::substr(index + 2);

			if (line != "date | value")	// 첫 줄 예외처리
			{
				CheckDateFormat(date);				// valid date 검사
				double dvalue = CheckValue(value);	// valid value 검사

				std::map<std::string, double>::iterator iter;
				iter = dataMap.find(date);
				if (iter != dataMap.end())	// dataMap에 날짜가 존재하는 경우
					std::cout << date << " => " << value << " = " << DoubleToString(iter->second * dvalue) << std::endl;
				else {
					iter = dataMap.upper_bound(date);	// date보다 큰 첫번째 값
					if (iter == dataMap.begin())	// 직전 날짜가 없는 경우
						throw std::logic_error("invalid date.");
					--iter;
					std::cout << date << " => " << value << " = " << DoubleToString(iter->second * dvalue) << std::endl;
				}
			}
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
}