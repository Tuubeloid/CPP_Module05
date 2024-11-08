#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;

        // Create a Form with grade requirements within range
        Form contract("Contract A", 45, 30);
        std::cout << contract << std::endl;

        // Attempt to have Alice sign the form
        try {
            contract.beSigned(alice);
        } catch (const Form::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Increment Alice's grade to meet the requirement
        alice.incrementGrade();
        std::cout << "After incrementing Alice's grade: " << alice << std::endl;

        // Attempt to have Alice sign the form again
        try {
            contract.beSigned(alice);
            std::cout << "Form signed status: " << (contract.getIsSigned() ? "Signed" : "Not signed") << std::endl;
        } catch (const Form::GradeTooLowException &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Bureaucrat exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException &e) {
        std::cerr << "Form exception: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException &e) {
        std::cerr << "Form exception: " << e.what() << std::endl;
    }

    // Test boundary cases for grades
    try {
        Bureaucrat bob("Bob", 1); // Minimum grade
        Form topSecret("Top Secret Document", 1, 1);
        bob.incrementGrade(); // Should throw an exception (GradeTooHigh)
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 150); // Maximum grade
        Form lowClearance("Low Clearance Form", 150, 150);
        charlie.decrementGrade(); // Should throw an exception (GradeTooLow)
    } catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Invalid Form grade (out of range)
    try {
        Form invalidForm("Invalid Form", 0, 150); // Should throw GradeTooHighException
    } catch (const Form::GradeTooHighException &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
