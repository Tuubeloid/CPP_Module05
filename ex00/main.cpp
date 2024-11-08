#include "Bureaucrat.hpp"
#include <utility>

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        // Attempt to increment grade to go out of bounds
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.incrementGrade(); // This should throw GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane", 149);
        std::cout << jane << std::endl;

        // Attempt to decrement grade to go out of bounds
        jane.decrementGrade();
        std::cout << "After decrement: " << jane << std::endl;

        jane.decrementGrade(); // This should throw GradeTooLowException
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Attempt to create a Bureaucrat with a grade too high
        Bureaucrat invalidHigh("InvalidHigh", 0);
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception when creating InvalidHigh: " << e.what() << std::endl;
    }

    try {
        // Attempt to create a Bureaucrat with a grade too low
        Bureaucrat invalidLow("InvalidLow", 151);
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception when creating InvalidLow: " << e.what() << std::endl;
    }

    return 0;
}
