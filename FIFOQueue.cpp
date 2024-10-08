#include <queue>
#include "customer.h"

class FIFOQueue {
private:
    std::queue<Customer*> q;

public:
    void enqueue(Customer* customer) {
        q.push(customer);
    }

    Customer* dequeue() {
        Customer* front = q.front();
        q.pop();
        return front;
    }

    bool empty() const {
        return q.empty();
    }
};
