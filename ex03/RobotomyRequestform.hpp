#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Aform
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

        void getExecuted(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif
