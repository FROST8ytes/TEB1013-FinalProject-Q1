//
// Created by ammar on 15/3/2023.
//

#include <iostream>
#include "question1.h"
#include "common.h"

namespace question1 {
    /**
     * This function asks for the number of days the businessperson spent on the trip,
     * checks the validity of the input (non-negative int), and returns it.
     * @return number of days spent on the trip
     */
    int numOfTripDays() {
        int input;
        input = common::getNumInput<int>("Enter the number of days spent on the trip",
                                         [](int input) -> bool { return input >= 1; });
        return input;
    }

    /**
     * This function asks for the departure and arrival times for the businessperson's trip.
     * @return a struct containing valid departure and arrival times
     */
    DepartArriveTimes departureAndArrivalTimes() {
        DepartArriveTimes departArriveTimes{};
        common::Time input{};

        input = common::getTimeInput("Enter the departure time");
        departArriveTimes.departure = input;

        input = common::getTimeInput("Enter the arrival time (back to the original departure place)");
        departArriveTimes.arrival = input;

        return departArriveTimes;
    }

    /**
     * This function asks for the number of car rentals ordered during the trip, then asks for the fare for each
     * rental, and returns the total fare for all car rentals (combined).
     * @return total fare for all car rentals combined.
     */
    float carRentals() {
        float total = 0.0f;
        int numOfCarRentals;
        numOfCarRentals = common::getNumInput<int>("Enter the number of car rentals",
                                                   [](int input) { return input >= 0; });

        if (numOfCarRentals > 0) {
            for (int i = 0; i < numOfCarRentals; i++) {
                std::string message = "Enter the fare for car rental " + std::to_string(i);
                total += common::getNumInput<float>(message.c_str(), [](float input) { return input >= 0.0f; });
            }

        }
        return total;
    }

}
