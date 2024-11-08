#ifndef AAform_HPP
# define AAform_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Aform {
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExec;
    public:
        Aform();
        Aform(std::string name, int gradeToSign, int gradeToExec);
        Aform(Aform const & src);
        Aform& operator=(Aform const & src);
        ~Aform();

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

std::ostream & operator<<(std::ostream & o, Aform const & src);

#endif
