#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
#include <ostream>
# include <string>

class PresidentialPardonForm : public Aform
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

        void getExecuted(Bureaucrat const & executor) const;
};

std::ostream &  operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif
