#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(150), gradeToExec(150)
{
    this->isSigned = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    this->isSigned = false;
}

Form::Form(Form const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
    *this = src;
}

Form &Form::operator=(Form const &src)
{
    this->isSigned = src.isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExec() const
{
    return this->gradeToExec;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
        std::cout << bureaucrat.getName() << " cannot sign " << this->name << " because his grade is too low" << std::endl;
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
    std::cout << bureaucrat.getName() << " signs " << this->name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &Form) {
    os << "Form InFormation:\n"
       << "Name: " << Form.getName() << "\n"
       << "Signed: " << (Form.getIsSigned() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << Form.getGradeToSign() << "\n"
       << "Grade Required to Execute: " << Form.getGradeToExec() << std::endl;
    return os;
}