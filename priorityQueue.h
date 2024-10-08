#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <cstddef> // Include for size_t
#include <stdexcept> // Include for std::out_of_range
#include "event.h"

class PriorityQueue {
public:
    void enqueue(const Event& event); // Enqueue an event
    Event dequeue(); // Dequeue an event
    bool isEmpty() const; // Check if the queue is empty
    size_t size() const; // Return the size of the queue

private:
    std::vector<Event> heap; // Vector to store events

    void heapifyUp(int index); // Maintain heap property when adding
    void heapifyDown(size_t index); // Maintain heap property when removing

};

#endif // PRIORITYQUEUE_H








