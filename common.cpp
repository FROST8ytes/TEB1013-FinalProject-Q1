//
// Created by ammar on 15/3/2023.
//

#include <iostream>
#include <string>
#include "common.h"

namespace common {
    /**
     * This function is meant to be used when a string input is needed from the user.
     * The message is printed out first before accepting input.
     * It keeps asking for the input if the user types values outside of the input constraint(s).
     * @param message the message that is printed out before waiting for an input
     * @param func a function that accepts the input as its parameter and returns a bool, to check for input constraints.
     * @return returns a valid--well within constraint(s)--string.
     */
    std::string getStrInput(const char* message, bool (*func)(std::string)) {
        std::string input;
        bool isValid;
        do {
            std::cin.ignore();
            std::cout << message << ": ";
            std::getline(std::cin, input);
            std::cin.ignore();
            isValid = func(input);
        } while (!isValid);
        return input;
    }
}