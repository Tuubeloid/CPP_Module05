#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>

class ShrubberyCreationForm : public Aform
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

        void getExecuted(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif
