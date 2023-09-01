#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    std::string copy = str; // Make a copy of the original string
    std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower); // Convert to lowercase
    
    // Remove non-alphanumeric characters
    copy.erase(std::remove_if(copy.begin(), copy.end(), [](char c) {
        return !std::isalnum(c);
    }), copy.end());
    
    // Compare the string with its reverse
    return copy == std::string(copy.rbegin(), copy.rend());
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
