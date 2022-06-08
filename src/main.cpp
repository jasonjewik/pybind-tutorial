// Standalone C++ program that is not called from Python

#include <iostream>
#include <string>

#include "example.h"
#include "pet.h"

int main() {
    int i, j;
    std::string name;
    int age;

    // Add two numbers    
    std::cout << "Enter a number: ";
    std::cin >> i;

    std::cout << "Enter another number: ";
    std::cin >> j;

    std::cout << "Sum: " << add(i, j) << "\n";

    // Create a pet
    std::cout << "Enter a name: ";
    std::cin >> name;
    std::cout << "Enter an age: ";
    std::cin >> age;
    Pet p = Pet(name, age);
    std::cout << "You created a pet whose name is '" << p.getName() << "'\n";
    std::cout << "Your pet's age is " << age << " years old\n";

    return 0;
}
