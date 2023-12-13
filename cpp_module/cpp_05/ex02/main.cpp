#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	{
		try
		{
			std::cout << "-------------RobotomyRequestForm Test-------------" << std::endl;
			Bureaucrat jimpark("jimpark", 1);
			RobotomyRequestForm successRoboto("successRoboto");
			jimpark.signForm(successRoboto);
			jimpark.executeForm(successRoboto);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "\n-------------RobotomyRequestForm Grade To Low Test-------------" << std::endl;
			Bureaucrat jimpark("jimpark", 140);
			RobotomyRequestForm failRoboto("failRoboto");
			jimpark.signForm(failRoboto);
			jimpark.executeForm(failRoboto);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "\n---------------ShrubberyCreationForm Test---------------" << std::endl;
			Bureaucrat jimpark("jimpark", 1);
			ShrubberyCreationForm successShrubbery("successShrubbery");
			jimpark.signForm(successShrubbery);
			jimpark.executeForm(successShrubbery);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "\n---------------ShrubberyCreationForm Grade To LowTest---------------" << std::endl;
			Bureaucrat jimpark("jimpark", 146);
			ShrubberyCreationForm failShruberry("failShruberry");
			jimpark.signForm(failShruberry);
			jimpark.executeForm(failShruberry);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "\n---------------PresidentialPardonForm Test---------------" << std::endl;
			Bureaucrat jimpark("jimpark", 1);
			PresidentialPardonForm successPardon("successPardon");
			jimpark.signForm(successPardon);
			jimpark.executeForm(successPardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "\n---------------PresidentialPardonForm Grade To LowTest---------------" << std::endl;
			Bureaucrat jimpark("jimpark", 24);
			PresidentialPardonForm failPardon("failPardon");
			jimpark.signForm(failPardon);
			jimpark.executeForm(failPardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
