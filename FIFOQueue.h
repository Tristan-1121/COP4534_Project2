#ifndef FIFOQUEUE_H
#define FIFOQUEUE_H

#include <queue>
#include "customer.h"

class FIFOQueue {
private:
    std::queue<Customer*> queue;

public:
    void push(Customer* customer) {
        queue.push(customer);
    }

    Customer* pop() {
        Customer* customer = queue.front();
        queue.pop();
        return customer;
    }

    bool empty() const {
        return queue.empty();
    }
};

#endif // FIFOQUEUE_H
