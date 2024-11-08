#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestform.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat alice("Alice", 136);
        Bureaucrat bob("Bob", 46);
        Bureaucrat charlie("Charlie", 1);
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;

        // Create a Aform with grade requirements within range
        ShrubberyCreationForm contract("Shrubbery Creation Contract");
        RobotomyRequestForm contract2("Robotomy Request Contract");
        PresidentialPardonForm contract3("Presidential Pardon Contract");
        std::cout << contract << std::endl;
        std::cout << contract2 << std::endl;
        std::cout << contract3 << std::endl;

        // Attempt to have Alice sign the ShrubberyCreationForm
        try {
            contract.beSigned(alice);
        } catch (const Aform::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Attempt to have Alice sign the RobotomyRequestForm
        try {
            contract2.beSigned(alice);
        } catch (const Aform::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Attempt to have Bob sign the RobotomyRequestForm
        try {
            contract2.beSigned(bob);
        } catch (const Aform::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Attempt to have Charlie sign the PresidentialPardonForm
        try {
            contract3.beSigned(charlie);
        } catch (const Aform::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Increment Alice's grade to meet the requirement
        alice.incrementGrade();
        std::cout << "After incrementing Alice's grade: " << alice << std::endl;

        // Attempt to have Alice sign the Aform again
        try {
            contract.beSigned(alice);
            std::cout << "Aform signed status: " << (contract.getIsSigned() ? "Signed" : "Not signed") << std::endl;
        } catch (const Aform::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        contract.getExecuted(alice);
        contract2.getExecuted(bob);
        contract3.getExecuted(charlie);

    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    } catch (const Aform::GradeTooHighException &e) {
        std::cerr << "Aform exception: " << e.what() << std::endl;
    } catch (const Aform::GradeTooLowException &e) {
        std::cerr << "Aform exception: " << e.what() << std::endl;
    }

    return 0;
}
