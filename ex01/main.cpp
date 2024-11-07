#include "Bureaucrat.hpp"
#include <utility>

// int main(void)
// {
//     Bureaucrat Bureaucrat("Bob", 145);
//     std::cout << "Bureaucrat's name: " << Bureaucrat.getName() << "\n";
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
// }
//

// int main() {
//     try {
//         Bureaucrat bob("Bob", 1);
//         std::cout << bob << std::endl;
//         bob.incrementGrade(); // This should throw an exception
//     }
//     catch (std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat alice("Alice", 150);
//         std::cout << alice << std::endl;
//         alice.decrementGrade(); // This should throw an exception
//     }
//     catch (std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }

static void checkBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat	b(name, grade);

		std::cout << b;

        std::cout << std::endl;
        std::cout << "Incrementing the grade: ";
		b.incrementGrade();
        std::cout << b << std::endl;

        std::cout << "Decrementing the grade: ";
		b.decrementGrade();
        std::cout << b << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl <<std::endl;
	}
}

int main(void)
{
    std::string name;
    std::string gradeStr;
    int         grade;
    std::string formName;
    std::string formGradeStr;
    int         formGrade;
    std::string formExecGradeStr;
    int         formExecGrade;

    std::cout << "Name the bureaucrat: " << std::endl;
    getline(std::cin, name);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}

    std::cout << "Grade the bureaucrat: " << std::endl;
    getline(std::cin, gradeStr);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}
    try
    {
        grade = std::stoi(gradeStr);
    }
    catch (std::invalid_argument const& e)
    {
        std::cerr << "Error: Invalid input. Please enter a valid number for grade." << std::endl;
        return 1;
    }
    catch (std::out_of_range const& e)
    {
        std::cerr << "Error: Grade out of range." << std::endl;
        return 1;
    }

    checkBureaucrat(name, grade);

    std::cout << "Name the form: " << std::endl;
    getline(std::cin, formName);
    if (std::cin.eof() == true)
    {
        std::cin.clear();
        std::cout << std::endl;
    }

    std::cout << "Give grade needed to sign the form: " << std::endl;
    getline(std::cin, formGradeStr);
    if (std::cin.eof() == true)
    {
        std::cin.clear();
        std::cout << std::endl;
    }
    try
    {
        formGrade = std::stoi(formGradeStr);
    }
    catch (std::invalid_argument const& e)
    {
        std::cerr << "Error: Invalid input. Please enter a valid number for Form grade to sign." << std::endl;
        return 1;
    }
    catch (std::out_of_range const& e)
    {
        std::cerr << "Error: Grade out of range." << std::endl;
        return 1;
    }

    std::cout << "Give grade needed to execute the form: " << std::endl;
    getline(std::cin, formExecGradeStr);
    if (std::cin.eof() == true)
    {
        std::cin.clear();
        std::cout << std::endl;
    }
    try
    {
        formExecGrade = std::stoi(formExecGradeStr);
    }
    catch (std::invalid_argument const& e)
    {
        std::cerr << "Error: Invalid input. Please enter a valid number for Form grade to execute." << std::endl;
        return 1;
    }
    catch (std::out_of_range const& e)
    {
        std::cerr << "Error: Grade out of range." << std::endl;
        return 1;
    }

	return (0);
}
