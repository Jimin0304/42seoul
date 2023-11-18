#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat jimpark("jimpark", 1);
		Form form("success form", 50, 50);
		jimpark.signForm(form);
	} catch(std::exception& e) {
		std::cerr << e.what();
	}

	try {
		Bureaucrat jimpark("jimpark", 51);
		Form form("failed form", 50, 50);
		jimpark.signForm(form);
	} catch(std::exception& e) {
		std::cerr << e.what();
	}

}
