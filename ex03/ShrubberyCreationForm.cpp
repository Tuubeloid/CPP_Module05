#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Aform("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Aform("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Aform(src) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::getExecuted(Bureaucrat const &executor) const {
    std::ofstream file;
    file.open(this->_target + "_shrubbery");
    if (file.is_open()) {
        file << "                                               ." << std::endl;
        file << "                                   .         ;  " << std::endl;
        file << "      .              .              ;%     ;;   " << std::endl;
        file << "        ,           ,                :;%  %;   " << std::endl;
        file << "         :         ;                   :;%;'     .,   " << std::endl;
        file << " ,.        %;     %;            ;        %;'    ,;   " << std::endl;
        file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl;
        file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        file << "    ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
        file << "     `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
        file << "      `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
        file << "         `:%;.  :;bd%;          %;@%;' " << std::endl;
        file << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
        file << "             `@%.  `;@%.      ;@@%;         " << std::endl;
        file << "               `@%%. `@%%    ;@@%;        " << std::endl;
        file << "                 ;@%. :@%%  %@@%;       " << std::endl;
        file << "                   %@bd%%%bd%%:;     " << std::endl;
        file << "                     #@%%%%%:;; " << std::endl;
        file << "                     %@@%%%::; " << std::endl;
        file << "                     %@@@%(o);  . '         " << std::endl;
        file << "                     %@@@o%;:(.,'         " << std::endl;
        file << "                 `.. %@@@o%::;         " << std::endl;
        file << "                    `)@@@o%::;         " << std::endl;
        file << "                     %@@(o)::;        " << std::endl;
        file << "                    .%@@@@%::;         " << std::endl;
        file << "                    ;%@@@@%::;.          " << std::endl;
        file << "                   ;%@@@@%%:;;;. " << std::endl;
        file << "               ...;%@@@@@%%:;;;;,.. " << std::endl;
        std::cout << "ShrubberyCreationForm " << this->getName() << " has been executed by " << executor.getName() << std::endl;
        file.close();
    }
    else {
        std::cout << "Error: file could not be opened" << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & src) {
    o << "ShrubberyCreationForm " << src.getName() << " with grade to sign " << src.getGradeToSign() << " and grade to execute " << src.getGradeToExec();
    return o;
}
