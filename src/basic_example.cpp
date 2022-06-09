// Standalone C++ program that is not called from Python

#include <iostream>
#include <string>

#include "basic_math.h"
#include "person.h"

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

    // Create a person
    std::cout << "Enter a name: ";
    std::cin >> name;
    std::cout << "Enter an age: ";
    std::cin >> age;
    Person p = Person(name, age);
    std::cout << "You created a person whose name is '" << p.getName() << "'\n";
    std::cout << "Your person's age is " << age << " years old\n";

    return 0;
}
