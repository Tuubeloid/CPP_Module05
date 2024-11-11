#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Aform("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Aform("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Aform(src) {
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src) {
        _target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::getExecuted(const Bureaucrat &executor) const {
    std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &src) {
    o << src.getName() << " form with sign grade " << src.getGradeToSign() << " and execute grade " << src.getGradeToExec() << " is ";
    return o;
}
