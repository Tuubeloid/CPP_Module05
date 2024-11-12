#include "AForm.hpp"

Aform::Aform() : name("default"), gradeToSign(150), gradeToExec(150)
{
    this->isSigned = false;
}

Aform::Aform(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Aform::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Aform::GradeTooLowException();
    this->isSigned = false;
}

Aform::Aform(Aform const &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
    *this = src;
}

Aform &Aform::operator=(Aform const &src)
{
    this->isSigned = src.isSigned;
    return *this;
}

Aform::~Aform() {}

std::string Aform::getName() const
{
    return this->name;
}

int Aform::getGradeToSign() const
{
    return this->gradeToSign;
}

int Aform::getGradeToExec() const
{
    return this->gradeToExec;
}

bool Aform::getIsSigned() const
{
    return this->isSigned;
}

void Aform::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
        std::cout << bureaucrat.getName() << " cannot sign " << this->name << " because his grade is too low" << std::endl;
        throw Aform::GradeTooLowException();
    }
    this->isSigned = true;
    std::cout << bureaucrat.getName() << " signs " << this->name << std::endl;
}

const char* Aform::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Aform::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Aform &Aform) {
    os << "Aform InAformation:\n"
       << "Name: " << Aform.getName() << "\n"
       << "Signed: " << (Aform.getIsSigned() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << Aform.getGradeToSign() << "\n"
       << "Grade Required to Execute: " << Aform.getGradeToExec() << std::endl;
    return os;
}

void Aform::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned)
    {
        std::cout << "Form is not signed" << std::endl;
        return;
    }
    if (executor.getGrade() > this->gradeToExec)
        throw Aform::GradeTooLowException();
    this->getExecuted(executor);
}
