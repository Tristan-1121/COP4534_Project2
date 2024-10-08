#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include "event.h"
#include <cstddef> // For size_t

class PriorityQueue {
public:
    PriorityQueue();                       // Constructor
    void push(const Event& event);         // Add an event to the queue
    Event pop();                           // Remove and return the highest priority event
    bool empty() const;                    // Check if the queue is empty
    std::vector<Event>::size_type size() const; // Get the size of the queue

private:
    std::vector<Event> heap;               // Vector to store events
    void heapifyUp(std::vector<Event>::size_type index); // Maintain the heap property after insertion
    void heapifyDown(std::vector<Event>::size_type index); // Maintain the heap property after removal
};

#endif // PRIORITY_QUEUE_H



