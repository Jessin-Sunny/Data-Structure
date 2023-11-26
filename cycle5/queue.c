#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a new element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate an error or an empty queue
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Function to display the contents of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Example Usage
int main() {
    struct Queue* myQueue = createQueue();

    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);

    printf("Queue after enqueue operations:\n");
    display(myQueue);  // Output: 1 2 3

    int dequeuedItem = dequeue(myQueue);
    if (dequeuedItem != -1) {
        printf("Dequeued item: %d\n", dequeuedItem);
    }

    printf("Queue after dequeue operation:\n");
    display(myQueue);  // Output: 2 3

    return 0;
}
