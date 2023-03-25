//
// Created by ammar on 15/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q1_COMMON_H
#define TEB1013_FINALPROJECT_Q1_COMMON_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include "common.inl"

namespace common {
    /**
     * Stores hour and minute.
     * Used to represent time.
     */
    struct Time {
        unsigned int hour;
        unsigned int minute;
    };

    struct Expenses {
        float allowableExpense;
        float excessExpense;
    };

    /**
     * This function is meant to handle accepting time input in 24-hour format.
     * It keeps asking for the input if hour is not 0 <= hour < 24,
     * and if minute is not 0 <= minute < 60,
     * and if the delimiter is not ':'.
     * @param message the message that is printed out before waiting for an input
     * @return a Time struct with valid hour and minute
     */
    Time getTimeInput(const char* message);

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

common::Expenses& operator+=(common::Expenses& original, const common::Expenses& other);

#endif //TEB1013_FINALPROJECT_Q1_COMMON_H
