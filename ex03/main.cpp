#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestform.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    Aform* rrf;
    Aform* wrongform;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    wrongform = someRandomIntern.makeForm("crap form", "Zoidberg");

    Bureaucrat b("Bender", 150);
    Bureaucrat c("Zoidberg", 1);
    Bureaucrat d("Fry", 1);

    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::cout << *rrf << std::endl;

    try {
        rrf->beSigned(b);
        rrf->getExecuted(b);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        rrf->beSigned(c);
        rrf->getExecuted(c);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        rrf->beSigned(d);
        rrf->getExecuted(d);
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
