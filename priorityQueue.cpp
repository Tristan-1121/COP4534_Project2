#include "priorityQueue.h"

void PriorityQueue::enqueue(const Event& event) {
    heap.push_back(event); // Add the new event at the end
    heapifyUp(heap.size() - 1); // Restore the heap property
}

Event PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("PriorityQueue is empty");
    }
    Event root = heap.front(); // Get the root element
    heap.front() = heap.back(); // Move the last element to the root
    heap.pop_back(); // Remove the last element
    heapifyDown(0); // Restore the heap property
    return root; // Return the root event
}

bool PriorityQueue::isEmpty() const {
    return heap.empty(); // Check if the heap is empty
}

size_t PriorityQueue::size() const {
    return heap.size(); // Return the size of the heap
}

void PriorityQueue::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2; // Get the parent index
        if (heap[index].eventTime < heap[parentIndex].eventTime) {
            std::swap(heap[index], heap[parentIndex]); // Swap if the child is less than the parent
            index = parentIndex; // Move up to the parent
        } else {
            break; // The heap property is satisfied
        }
    }
}

void PriorityQueue::heapifyDown(size_t index) {
    size_t leftChild = 2 * index + 1; // Get the left child index
    size_t rightChild = 2 * index + 2; // Get the right child index
    size_t smallest = index; // Assume the current index is the smallest

    // Compare with the left child
    if (leftChild < heap.size() && heap[leftChild].eventTime < heap[smallest].eventTime) {
        smallest = leftChild;
    }
    // Compare with the right child
    if (rightChild < heap.size() && heap[rightChild].eventTime < heap[smallest].eventTime) {
        smallest = rightChild;
    }
    // If the smallest is not the current index, swap and continue heapifying down
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}








