#include "RobotomyRequestform.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Aform("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Aform("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Aform(src) {
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::getExecuted(Bureaucrat const &executor) const {
    srand(static_cast<unsigned int>(time(0)));

    int success = rand() % 2;

    std::cout << "*drilling noises* ";
    if (success == 1) {
        std::cout << this->_target << " has been robotomized successfully " << "by " << executor.getName() << std::endl;
    } else {
        std::cout << this->_target << " robotomization failed" << "by " << executor.getName() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &src) {
    o << "RobotomyRequestForm " << src.getName() << " with grade to sign " << src.getGradeToSign() << " and grade to execute " << src.getGradeToExec();
    return o;
}
