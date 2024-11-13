#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName() + "_copy")
{
    *this = copy;
}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &source)
{
    if (this != &source)
        this->grade = source.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void signForm(bool isSigned, std::string formName)
{
    if (isSigned)
        std::cout << formName << " signs " << formName << std::endl;
    else
        std::cout << formName << " cannot sign " << formName << " because grade is too low" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int::Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
