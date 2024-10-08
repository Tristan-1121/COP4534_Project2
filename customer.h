#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
    float arrivalTime;
    float startOfServiceTime;
    float departureTime;
    Customer *nextCust; // for linked FIFO

    Customer(float arrivalTime);
    float getArrivalTime() const;
    float getStartOfServiceTime() const;
    float getDepartureTime() const;
    void setStartOfServiceTime(float time);
    void setDepartureTime(float time);
};

#endif // CUSTOMER_H
