#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern &Intern::operator=(const Intern &rhs) {
    if (this != &rhs) {
        (void)rhs;
    }
    return *this;
}

Intern::~Intern() {}

Aform *Intern::makeForm(std::string formName, std::string target) {
    Aform *form = nullptr;

    if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    } else if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    } else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << formName << std::endl;
    } else {
        std::cout << "Intern cannot create " << formName << std::endl;
    }
    return form;
}
