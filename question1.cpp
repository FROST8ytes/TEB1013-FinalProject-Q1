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
     * This function acts as the menu that lists the options that the user can choose to give more info about the trip
     * for the day.
     * @param dayNum trip day number
     * @return option listed in the menu
     */
    int menu(int dayNum) {
        std::cout << "+-------------------------------------------------------------+" << std::endl;
        std::cout << "                       DAY " << dayNum << std::endl;
        std::cout << "+-------------------------------------------------------------+" << std::endl;
        std::cout << "0. ENTER ROUND-TRIP AIRFARE FOR THE DAY" << std::endl;
        std::cout << "1. ENTER CAR RENTALS FOR THE DAY" << std::endl;
        std::cout << "2. ENTER MILES DRIVEN USING A PRIVATE VEHICLE FOR THE DAY" << std::endl;
        std::cout << "3. ENTER PARKING FEES FOR THE DAY" << std::endl;
        std::cout << "4. ENTER TAXI FEES FOR THE DAY" << std::endl;
        std::cout << "5. ENTER CONFERENCE OR SEMINAR REGISTRATION FEES FOR THE DAY" << std::endl;
        std::cout << "6. ENTER HOTEL EXPENSES FOR THE DAY" << std::endl;
        std::cout << "7. ENTER MEALS FOR THE DAY" << std::endl;
        std::cout << "8. ENTER EXPENSES FOR THE NEXT DAY OR CALCULATE TOTAL EXPENSES" << std::endl;
        auto option = common::getNumInput<int>("Choose one option listed above",
                                               [](int input) { return input >= 0 && input <= 8; });
        std::cout << "+-------------------------------------------------------------+" << std::endl;
        return option;
    }

    // TODO: write docs for this function
    float roundTripAirfare() {
        // TODO: implement the function
        return 0.0f;
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

    /**
     * This function asks for the miles driven using a private vehicle.
     * Then, it calculates the total expense, which is RM0.27 per mile driven.
     * @return cost for driving using a private vehicle (RM0.27 / miles)
     */
    float milesDrivenUsingPrivateVehicle() {
        auto miles = common::getNumInput<float>("Enter the number of miles driven using a private car",
                                                [](float input) { return input >= 0; });
        return miles * 0.27f;
    }

    /**
     * This function asks for the number of parking fees needed to be paid.
     * Then, it asks for the fee for each parking.
     * Then, it calculates the total allowable expense (RM6.00 / day).
     * Anything in excess has to be covered by the businessperson.
     * @return allowable (RM6.00 / day) and excess costs for parking fees
     */
    common::Expenses parkingFees() {
        int numberOfParkingFees;
        float total = 0.0f;
        common::Expenses result{};

        numberOfParkingFees = common::getNumInput<int>("Enter the number of times parking is needed to be paid",
                                                       [](int input) { return input >= 0; });

        for (int i = 0; i < numberOfParkingFees; i++) {
            std::string prompt = "Enter the fee for parking " + std::to_string(i);
            total += common::getNumInput<float>(prompt.c_str(), [](float input) { return input > 0.0f; });
        }

        if (total > MAX_PARKING_FEE_COVERED) {
            result.allowableExpense = MAX_PARKING_FEE_COVERED;
            result.excessExpense = total - MAX_PARKING_FEE_COVERED;
        } else {
            result.allowableExpense = total;
            result.excessExpense = 0.0f;
        }

        return result;
    }

    common::Expenses taxiFees() {
        common::Expenses result{};
        float total = 0.0f;
        auto numberOfTaxiRides = common::getNumInput<int>("Enter the number of taxi rides used",
                                                          [](int input) { return input >= 0; });
        for (int i = 0; i < numberOfTaxiRides; i++) {
            std::string prompt = "Enter the fee for taxi ride " + std::to_string(i);
            total += common::getNumInput<float>(prompt.c_str(), [](float input) { return input > 0.0f; });
        }

        if (total > MAX_TAXI_FEE_COVERED) {
            result.allowableExpense = MAX_TAXI_FEE_COVERED;
            result.excessExpense = total - MAX_TAXI_FEE_COVERED;
        } else {
            result.allowableExpense = total;
        }

        return result;
    }

    float registrationFees() {
        float total = 0.0f;

        auto numberOfRegistrationFees = common::getNumInput<int>(
                "Enter the number of conference/seminar registration fees", [](int input) { return input >= 0; });

        for (int i = 0; i < numberOfRegistrationFees; i++) {
            std::string prompt = "Enter the registration fee " + std::to_string(i);
            total += common::getNumInput<float>(prompt.c_str(), [](float input) { return input > 0; });
        }

        return total;
    }

    common::Expenses hotelExpenses(int numOfDays) {
        common::Expenses result{};
        float total = 0.0f;
        auto option = common::getNumInput<int>(
                "Did you stay in a hotel throughout the entire trip? (1 for yes | 0 for no)",
                [](int input) { return input == 0 || input == 1; });

        if (option) {
            result.allowableExpense = MAX_HOTEL_COVERED;
        } else {
            while (true) {
                option = common::getNumInput<int>("Enter the number of nights in a hotel",
                                                  [](int input) { return input > 0; });
                if (option > numOfDays) {
                    std::cout << "[-] Number of nights cannot be greater than number of days spent on the trip."
                              << std::endl;
                } else {
                    break;
                }
            }

            for (int i = 0; i < option; i++) {
                std::string prompt = "Enter the hotel expenses for night " + std::to_string(i);
                total = common::getNumInput<float>(prompt.c_str(), [](float input) { return input > 0; });

                if (total > MAX_HOTEL_COVERED) {
                    result.allowableExpense += MAX_HOTEL_COVERED;
                    result.excessExpense += total - MAX_HOTEL_COVERED;
                } else {
                    result.allowableExpense += total;
                }
            }
        }

        return result;
    }

    common::Expenses mealExpenses(int numOfDays, DepartArriveTimes departArriveTimes) {
        common::Expenses result{};
        float totalBreakfast = 0.0f;
        float totalLunch = 0.0f;
        float totalDinner = 0.0f;

        for (int i = 0; i < numOfDays; i++) {
            std::string breakfastPrompt = "Enter the expense for breakfast on day " + std::to_string(i);
            std::string lunchPrompt = "Enter the expense for lunch on day " + std::to_string(i);
            std::string dinnerPrompt = "Enter the expense for dinner on day " + std::to_string(i);

            bool notFirstAndLastDay = i != 0 && i != (numOfDays - 1);
            bool breakfastOnFirstDay = i == 0 && (departArriveTimes.departure.hour < BREAKFAST_DEPART_TIME ||
                                                  (departArriveTimes.departure.hour == BREAKFAST_DEPART_TIME &&
                                                   departArriveTimes.departure.minute == 0));
            bool breakfastOnLastDay = i == (numOfDays - 1) && (departArriveTimes.arrival.hour > BREAKFAST_ARRIVE_TIME ||
                                                               (departArriveTimes.arrival.hour ==
                                                                BREAKFAST_ARRIVE_TIME &&
                                                                departArriveTimes.arrival.minute == 0));
            bool lunchOnFirstDay = i == 0 && (departArriveTimes.departure.hour < LUNCH_DEPART_TIME ||
                                              (departArriveTimes.departure.hour == LUNCH_DEPART_TIME &&
                                               departArriveTimes.departure.minute == 0));
            bool lunchOnLastDay = i == (numOfDays - 1) && (departArriveTimes.arrival.hour > LUNCH_ARRIVE_TIME ||
                                                           (departArriveTimes.arrival.hour == LUNCH_ARRIVE_TIME &&
                                                            departArriveTimes.arrival.minute == 0));
            bool dinnerOnFirstDay = i == 0 && (departArriveTimes.departure.hour < DINNER_DEPART_TIME ||
                                               (departArriveTimes.departure.hour == DINNER_DEPART_TIME &&
                                                departArriveTimes.departure.minute == 0));
            bool dinnerOnLastDay = i == (numOfDays - 1) && (departArriveTimes.arrival.hour > DINNER_ARRIVE_TIME ||
                                                            (departArriveTimes.arrival.hour == DINNER_ARRIVE_TIME &&
                                                             departArriveTimes.arrival.minute == 0));
            if (notFirstAndLastDay || breakfastOnFirstDay || breakfastOnLastDay) {
                totalBreakfast = common::getNumInput<float>(breakfastPrompt.c_str(),
                                                            [](float input) { return input >= 0.0f; });
                if (totalBreakfast > MAX_BREAKFAST_COVERED) {
                    result.allowableExpense += MAX_BREAKFAST_COVERED;
                    result.excessExpense += totalBreakfast - MAX_BREAKFAST_COVERED;
                } else {
                    result.allowableExpense += totalBreakfast;
                }
            }

            if (notFirstAndLastDay || lunchOnFirstDay || lunchOnLastDay) {
                totalLunch = common::getNumInput<float>(lunchPrompt.c_str(), [](float input) { return input >= 0.0f; });
                if (totalLunch > MAX_LUNCH_COVERED) {
                    result.allowableExpense += MAX_LUNCH_COVERED;
                    result.excessExpense += totalLunch - MAX_LUNCH_COVERED;
                } else {
                    result.allowableExpense += totalLunch;
                }
            }

            if (notFirstAndLastDay || dinnerOnFirstDay || dinnerOnLastDay) {
                totalDinner = common::getNumInput<float>(dinnerPrompt.c_str(),
                                                         [](float input) { return input >= 0.0f; });
                if (totalDinner > MAX_DINNER_COVERED) {
                    result.allowableExpense += MAX_DINNER_COVERED;
                    result.excessExpense += totalDinner - MAX_DINNER_COVERED;
                } else {
                    result.allowableExpense += totalDinner;
                }
            }
        }
        return result;
    }
}
