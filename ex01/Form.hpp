#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Form {
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExec;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form(Form const & src);
        Form& operator=(Form const & src);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(Bureaucrat & bureaucrat);
        void execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, Form const & src);

#endif
