#include <iostream>
#include <cstdlib>
#include "question1.h"

int main() {
    common::Expenses expenses{};

    std::system(CLEAR);

    std::cout << "+=====================+" << std::endl;
    std::cout << "    TRIP CALCULATOR    " << std::endl;
    std::cout << "+=====================+" << std::endl;

    int numberOfDays = question1::numOfTripDays();
    question1::DepartArriveTimes departArriveTimes = question1::departureAndArrivalTimes();
    expenses.allowableExpense += question1::roundTripAirfare();

    std::system(CLEAR);

    for (int i = 0; i < numberOfDays; i++) {
        bool continueMenu = true;
        while (continueMenu) {
            int option = question1::menu(i);

            switch (option) {
                case 0:
                    expenses.allowableExpense += question1::carRentals();
                    break;
                case 1:
                    expenses.allowableExpense += question1::milesDrivenUsingPrivateVehicle();
                    break;
                case 2:
                    expenses += question1::parkingFees();
                    break;
                case 3:
                    expenses += question1::taxiFees();
                    break;
                case 4:
                    expenses.allowableExpense += question1::registrationFees();
                    break;
                case 5:
                    expenses += question1::hotelExpenses(numberOfDays);
                    break;
                case 6:
                    expenses += question1::mealExpenses(i, numberOfDays, departArriveTimes);
                    break;
                case 7:
                    continueMenu = false;
                    break;
                default:
                    std::cerr << "[-] This shouldn't happen. Good job for breaking the program." << std::endl;
                    return 1;
            }
            std::system(CLEAR);
        }
    }

    std::cout << "+=============================================================+" << std::endl;
    std::cout.precision(2);
    std::cout << std::fixed << "[+] Allowable expenses (covered by the company) = " << expenses.allowableExpense << std::endl;
    std::cout << std::fixed << "[+] Excess expenses (cover personally) = " << expenses.excessExpense << std::endl;

    return 0;
}
