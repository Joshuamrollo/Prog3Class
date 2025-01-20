#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

std::string TARGET_FILE = "../CSC450_CT5_mod5.txt";
std::string TARGET_FILE_REVERSED = "../CSC450-mod5-reverse.txt";

std::string getUserInput() {
    std::string userInput;

    if (!std::getline(std::cin, userInput)) {
        std::cout << "error: failed to get user input" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    if (userInput.empty()) {
        std::cout << "error: input can't be empty :)" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return userInput;
}

void reverse_file(std::string inputFileName, std::string outputFileName) {
    std::ifstream inputFile(inputFileName, std::ios_base::binary);
    std::ofstream outputFile(outputFileName, std::ios_base::binary);
    std::istreambuf_iterator<char> inputBegin(inputFile);
    std::istreambuf_iterator<char> inputEnd;
    std::ostreambuf_iterator<char> outputBegin(outputFile);
    std::vector<char> inputData(inputBegin, inputEnd);

    std::reverse_copy(inputData.begin(), inputData.end(), outputBegin);
}

int main() {
    // get user input 
    std::string userInput;
    std::cout << "input some text!" << std::endl;
    userInput = getUserInput();

    // store it in txt file append style
    std::ofstream targetFile;
    targetFile.open(TARGET_FILE, std::ios_base::app);
    targetFile << userInput;
    targetFile.close();
    std::cout << "your input has been appended to the data in CSC450_CT5_mod5.txt" << std::endl;

    // make reversed version
    reverse_file(TARGET_FILE, TARGET_FILE_REVERSED);
    std::cout << "CSC450_CT5_mod5.txt's data has been reversed and stored in CSC450-mod5-reverse.txt" << std::endl;

    // end!
    std::cout << "this is the end of the program :)" << std::endl;
    return 0;
}