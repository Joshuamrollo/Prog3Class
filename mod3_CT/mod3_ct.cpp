#include <iostream>
#include <string>
#include <stdexcept>

bool parseInput(std::string& input, int& output) {
    try{
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

int getUserInput() {
    std::string input;
    int output;

    getline(std::cin, input);

    while (!parseInput(input, output)) {
        std::cout << "invalid integer. Please try again: ";
        getline(std::cin, input);
    }
    return output;
}

int main() {
    // get 3 integers as input store in 3 variables
    std::cout << "This program will prompt you for 3 integer values." << std::endl;
    std::cout << "Enter 1st integer: ";
    int int1 = getUserInput();

    std::cout << "Enter 2nd integer: ";
    int int2 = getUserInput();

    std::cout << "Enter 3rd integer: ";
    int int3 = getUserInput();

    // create pointers
    int* int1_ptr = new int;
    int1_ptr = &int1;

    int* int2_ptr = new int;
    int2_ptr = &int2;

    int* int3_ptr = new int;
    int3_ptr = &int3;

    // print values
    std::cout << "integer 1" << std::endl;
    std::cout << "value: " << int1 << std::endl;
    std::cout << "address: " << int1_ptr << std::endl;

    std::cout << "integer 2" << std::endl;
    std::cout << "value: " << int2 << std::endl;
    std::cout << "address: " << int2_ptr << std::endl;

    std::cout << "integer 3" << std::endl;
    std::cout << "value: " << int3 << std::endl;
    std::cout << "address: " << int3_ptr << std::endl;

    // delete and null
    delete int1_ptr;
    int1_ptr = nullptr;

    delete int2_ptr;
    int2_ptr = nullptr;

    delete int3_ptr;
    int3_ptr = nullptr;

    return 0;
}