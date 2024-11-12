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

static Aform *makeShrubberyCreationForm(const std::string target) {
    return new ShrubberyCreationForm(target);
}

static Aform *makeRobotomyRequestForm(const std::string target) {
    return new RobotomyRequestForm(target);
}

static Aform *makePresidentialPardonForm(const std::string target) {
    return new PresidentialPardonForm(target);
}

Aform *Intern::makeForm(std::string formName, std::string trgt) {
    Aform *form = nullptr;
    const std::string formtypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    // create array that points to functions that create the forms
    Aform *(*formfunctions[])(std::string trgt) = { &makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm };
    size_t size = sizeof(formtypes) / sizeof(formtypes[0]);

    for (size_t i = 0; i < size; i++) {
        if (formName == formtypes[i]) {
            form = formfunctions[i](trgt);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cout << "Intern could not create " << formName << std::endl;
    return form;
}
