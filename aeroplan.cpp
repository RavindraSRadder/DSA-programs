#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGS 100

typedef struct {
    int bagID;
    int planeID;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
} BagQueue;

void initializeQueue(BagQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(BagQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isQueueFull(BagQueue* queue) {
    return ((queue->rear + 1) % MAX_BAGS == queue->front);
}

void enqueue(BagQueue* queue, Bag bag) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot add bag %d\n", bag.bagID);
    } else {
        if (isQueueEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_BAGS;
        queue->bags[queue->rear] = bag;
        printf("Bag %d with plane ID %d added to the queue\n", bag.bagID, bag.planeID);
    }
}

Bag dequeue(BagQueue* queue) {
    Bag emptyBag;
    emptyBag.bagID = -1;
    emptyBag.planeID = -1;

    if (isQueueEmpty(queue)) {
        printf("Queue is empty. No bag to dequeue\n");
        return emptyBag;
    } else {
        Bag dequeuedBag = queue->bags[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_BAGS;
        }
        printf("Bag %d with plane ID %d dequeued from the queue\n", dequeuedBag.bagID, dequeuedBag.planeID);
        return dequeuedBag;
    }
}

bool searchBag(BagQueue* queue, int bagID) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. No bag to search\n");
        return false;
    } else {
        int current = queue->front;
        while (current != queue->rear) {
            if (queue->bags[current].bagID == bagID) {
                printf("Bag %d found in the queue with plane ID %d\n", bagID, queue->bags[current].planeID);
                return true;
            }
            current = (current + 1) % MAX_BAGS;
        }
        if (queue->bags[current].bagID == bagID) {
            printf("Bag %d found in the queue with plane ID %d\n", bagID, queue->bags[current].planeID);
            return true;
        }
        printf("Bag %d not found in the queue\n", bagID);
        return false;
    }
}

int main() {
    BagQueue bagQueue;
    initializeQueue(&bagQueue);

    // Assume bags from Plane 1 and Plane 2 are enqueued in a mixed order
    Bag bag1 = {1, 1};
    Bag bag2 = {2, 1};
    Bag bag3 = {3, 2};
    Bag bag4 = {4, 2};

    enqueue(&bagQueue, bag1);
    enqueue(&bagQueue, bag2);
    enqueue(&bagQueue, bag3);
    enqueue(&bagQueue, bag4);

    // Search for a bag
    int searchBagID;
    printf("\nEnter the bag ID to search: ");
    scanf("%d", &searchBagID);
    searchBag(&bagQueue, searchBagID);

    return 0;
}

