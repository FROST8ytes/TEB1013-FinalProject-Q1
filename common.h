//
// Created by ammar on 15/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q1_COMMON_H
#define TEB1013_FINALPROJECT_Q1_COMMON_H

#include <iostream>
#include <string>

namespace common {

    /**
     * This function is meant to be used when a non-string input is needed from the user.
     * The message is printed out first before accepting input.
     * It keeps asking for the input if the user types a value outside of the input constraint(s).
     * @tparam T data-type of the input
     * @param message the message that is printed out before waiting for an input
     * @param func a function that accepts the input as its parameter and returns a bool, to check for input constraints.
     * @return returns valid input
     * @note The function definition is needed in the header file to avoid suffering from missing a valid instantiation.
     * @note The above only applies to templates.
     */
    template<typename T>
    inline T getNumInput(const char* message, bool (*func)(T)) {
        T input;
        bool isValid;
        do {
            std::cout << message << ": ";
            std::cin >> input;
            isValid = func(input);
        } while (!isValid);
        return input;
    }

    /**
     * This function is meant to be used when a string input is needed from the user.
     * The message is printed out first before accepting input.
     * It keeps asking for the input if the user types values outside of the input constraint(s).
     * @param message the message that is printed out before waiting for an input
     * @param func a function that accepts the input as its parameter and returns a bool, to check for input constraints.
     * @return returns a valid--well within constraint(s)--string.
     */
    std::string getStrInput(const char* message, bool (*func)(std::string));
}

#endif //TEB1013_FINALPROJECT_Q1_COMMON_H
