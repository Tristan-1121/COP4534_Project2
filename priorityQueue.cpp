#include "priorityQueue.h"
#include <stdexcept> // For std::out_of_range

PriorityQueue::PriorityQueue() {}

void PriorityQueue::push(const Event& event) {
    heap.push_back(event);
    heapifyUp(heap.size() - 1); // Maintain the heap property
}

Event PriorityQueue::pop() {
    if (empty()) {
        throw std::out_of_range("Priority queue is empty");
    }

    Event topEvent = heap.front(); // Get the highest priority event
    heap.front() = heap.back();     // Move the last element to the front
    heap.pop_back();                // Remove the last element
    heapifyDown(0);                // Maintain the heap property
    return topEvent;
}

bool PriorityQueue::empty() const {
    return heap.empty();
}

std::vector<Event>::size_type PriorityQueue::size() const {
    return heap.size();
}

void PriorityQueue::heapifyUp(std::vector<Event>::size_type index) {
    while (index > 0) {
        std::vector<Event>::size_type parentIndex = (index - 1) / 2;
        if (heap[index].eventTime < heap[parentIndex].eventTime) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        } else {
            break; // The heap property is satisfied
        }
    }
}

void PriorityQueue::heapifyDown(std::vector<Event>::size_type index) {
    std::vector<Event>::size_type heapSize = heap.size();
    
    while (index < heapSize) {
        std::vector<Event>::size_type left = 2 * index + 1;
        std::vector<Event>::size_type right = 2 * index + 2;
        std::vector<Event>::size_type smallest = index;

        if (left < heapSize && heap[left].eventTime < heap[smallest].eventTime) {
            smallest = left;
        }
        if (right < heapSize && heap[right].eventTime < heap[smallest].eventTime) {
            smallest = right;
        }
        if (smallest == index) {
            break; // The heap property is satisfied
        }
        std::swap(heap[index], heap[smallest]);
        index = smallest;
    }
}




