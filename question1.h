//
// Created by ammar on 15/3/2023.
//

#ifndef TEB1013_FINALPROJECT_Q1_QUESTION1_H
#define TEB1013_FINALPROJECT_Q1_QUESTION1_H

#define MAX_PARKING_FEE_COVERED 6.0f
#define MAX_TAXI_FEE_COVERED 10.0f
#define MAX_HOTEL_COVERED 90.0f
#define MAX_BREAKFAST_COVERED 9.0f
#define MAX_LUNCH_COVERED 12.0f
#define MAX_DINNER_COVERED 16.0f

#define BREAKFAST_DEPART_TIME 7
#define BREAKFAST_ARRIVE_TIME 8

#define LUNCH_DEPART_TIME 12
#define LUNCH_ARRIVE_TIME 13

#define DINNER_DEPART_TIME 18
#define DINNER_ARRIVE_TIME 19

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
     * This function acts as the menu that lists the options that the user can choose to give more info about the trip
     * for the day.
     * @param dayNum trip day number
     * @return option listed in the menu
     */
    int menu(int dayNum);

    // TODO: write docs for this function
    float roundTripAirfare();

    /**
     * This function asks for the number of car rentals ordered during the trip, then asks for the fare for each
     * rental, and returns the total fare for all car rentals (combined).
     * @return total fare for all car rentals combined.
     */
    float carRentals();

    /**
     * This function asks for the miles driven using a private vehicle.
     * Then, it calculates the total expense, which is RM0.27 per mile driven.
     * @return cost for driving using a private vehicle (RM0.27 / miles)
     */
    float milesDrivenUsingPrivateVehicle();

    /**
     * This function asks for the number of parking fees needed to be paid.
     * Then, it asks for the fee for each parking.
     * Then, it calculates the total allowable expense (RM6.00 / day).
     * Anything in excess has to be covered by the businessperson.
     * @return allowable (RM6.00 / day) and excess costs for parking fees
     */
    common::Expenses parkingFees();

    common::Expenses taxiFees();

    float registrationFees();

    common::Expenses hotelExpenses(int numOfDays);

    common::Expenses mealExpenses(int numOfDays, DepartArriveTimes departArriveTimes);
}

#endif //TEB1013_FINALPROJECT_Q1_QUESTION1_H
