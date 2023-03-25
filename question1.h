//
// Created by ammar on 15/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q1_QUESTION1_H
#define TEB1013_FINALPROJECT_Q1_QUESTION1_H

#include "common.h"

namespace question1 {
    /**
     * Stores departure Time struct and arrival Time struct.
     */
    struct DepartArriveTimes {
        common::Time departure;
        common::Time arrival;
    };

    /**
     * This function asks for the number of days the businessperson spent on the trip,
     * checks the validity of the input (non-negative int), and returns it.
     * @return number of days spent on the trip
     */
    int numOfTripDays();

    /**
     * This function asks for the departure and arrival times for the businessperson's trip.
     * @return a struct containing valid departure and arrival times
     */
    DepartArriveTimes departureAndArrivalTimes();

    /**
     * This function asks for the number of car rentals ordered during the trip, then asks for the fare for each
     * rental, and returns the total fare for all car rentals (combined).
     * @return total fare for all car rentals combined.
     */
    float carRentals();
}

#endif //TEB1013_FINALPROJECT_Q1_QUESTION1_H
