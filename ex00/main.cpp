#include "Bureaucrat.hpp"

// int main(void)
// {
//     Bureaucrat Bureaucrat("Bob", 145);
//     std::cout << "Bureaucrat's name: " << Bureaucrat.getName() << "\n";
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     Bureaucrat.decrementGrade();
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
//     std::cout << "Bureaucrat's grade: " << Bureaucrat.getGrade() << "\n";
//     Bureaucrat.decrementGrade();
// }
//

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl;
        bob.incrementGrade(); // This should throw an exception
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        alice.decrementGrade(); // This should throw an exception
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
