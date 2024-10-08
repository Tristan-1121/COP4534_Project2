#include "customer.h"

Customer::Customer(float arrivalTime) : arrivalTime(arrivalTime), startOfServiceTime(0.0), departureTime(0.0), nextCust(nullptr) {}

float Customer::getArrivalTime() const {
    return arrivalTime;
}

float Customer::getStartOfServiceTime() const {
    return startOfServiceTime;
}

float Customer::getDepartureTime() const {
    return departureTime;
}

void Customer::setStartOfServiceTime(float time) {
    startOfServiceTime = time;
}

void Customer::setDepartureTime(float time) {
    departureTime = time;
}
