#include <iostream>
#include <string>

std::string getUserInput() {
    std::string userInput;
    // if didnt get user input then error
    if (!std::getline(std::cin, userInput)) {
        std::cout << "error: failed to get user input" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    // confirm input is not empty
    if (userInput.empty()) {
        std::cout << "error: input can't be empty :)" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return userInput;
}

int main() {
    std::string inputString1;
    std::string inputString2;
    std::string concatenatedStrings;

    std::cout << "This program will ask for 2 strings then concatenate them. This process will be completed a total of 3 times." << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "Please enter the first string: ";
        inputString1 = getUserInput();
        std::cout << "Please enter the second string: ";
        inputString2 = getUserInput();

        concatenatedStrings = inputString1 + inputString2;
        std::cout << "here are the strings concatenated: " << concatenatedStrings << std::endl;
    }

    std::cout << "this is the end of the program :p" << std::endl;

    return 0;
}