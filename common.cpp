//
// Created by ammar on 15/3/2023.
//

#include <iostream>
#include <string>
#include "common.h"

namespace common {
    /**
     * This function is meant to handle accepting time input in 24-hour format.
     * It keeps asking for the input if hour is not 0 <= hour < 24,
     * and if minute is not 0 <= minute < 60,
     * and if the delimiter is not ':'.
     * @param message the message that is printed out before waiting for an input
     * @return a Time struct with valid hour and minute
     */
    Time getTimeInput(const char* message) {
        Time time{};
        char delimiter;
        bool validDelimiter, validHour, validMinute;

        do {
            std::cout << "[*] " << message << " (HH:MM 24-hour format): ";
            std::cin >> time.hour >> delimiter >> time.minute;
            std::cin.ignore();
            validDelimiter = delimiter == ':';
            validHour = time.hour >= 0 && time.hour < 24;
            validMinute = time.minute >= 0 && time.minute < 60;
        } while (!(validDelimiter && validHour && validMinute));
        return time;
    }

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
            std::cout << message << ": ";
            std::getline(std::cin, input);
            std::cin.ignore();
            isValid = func(input);
        } while (!isValid);
        return input;
    }
}

/**
 * This function enables the use of += operator for common::Expenses struct.
 * @param original lhs of Expenses
 * @param other rhs of Expenses
 * @return lhs = lhs + rhs
 */
common::Expenses& operator+=(common::Expenses& original, const common::Expenses& other) {
    original.allowableExpense += other.allowableExpense;
    original.excessExpense += other.excessExpense;

    return original;
}
