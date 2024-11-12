#ifndef Intern_HPP
# define Intern_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestform.hpp"
# include <iostream>
# include <string>

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(Intern const & other);
		~Intern();

		Aform *makeForm(const std::string name, const std::string target);
};

#endif
