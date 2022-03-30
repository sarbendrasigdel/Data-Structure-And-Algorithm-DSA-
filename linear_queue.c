#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100 // Queue capacity
int queue[CAPACITY];  // Global queue declaration
unsigned int size  = 0;
unsigned int rear  = CAPACITY - 1;   // Initally assumed that rear is at end
unsigned int front = 0;
/* Function declaration for various operations on queue */
int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();
/* Driver function */
int main()
{   int ch, data;
        while (1)  /* Run indefinitely until user manually terminates */
    {     /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");
        scanf("%d", &ch);
        switch (ch)        /* Menu control switch */
                 {   case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                                if (enqueue(data))   // Enqueue function returns 1 on success otherwise 0
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");
                break;
            case 2:
                data = dequeue();
                    if (data == INT_MIN)  // on success dequeue returns element removed otherwise returns INT_MIN
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);
                break;
            case 3:
                if (isEmpty())                // isEmpty() function returns 1 if queue is emtpy  otherwise returns 0
                    printf("Queue is empty.");
                else
                    printf("Queue size => %d", size);
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Rear => %d", getRear());
                break;
            case 5:
                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Front => %d", getFront());
                break;
            case 0:
                printf("Exiting from app.\n");
                exit(0);
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }   printf("\n\n");  }   }
int enqueue(int data)   // Enqueue/Insert an element to the queue.
{  	// Queue is full throw Queue out of capacity error.
        if (isFull())
    {	return 0;   }
    rear = (rear + 1) % CAPACITY;       // Ensure rear never crosses array bounds
    size++;      // Increment queue size
        queue[rear] = data;  // Enqueue new element to queue
    return 1;   }     // Successfully enqueued element to queue
int dequeue()  // Dequeue/Remove an element from the queue.
{  int data = INT_MIN;
        if (isEmpty())// Queue is empty, throw Queue underflow error
    {  return INT_MIN;}
       data = queue[front]; // Dequeue element from queue
    front = (front + 1) % CAPACITY;      // Ensure front never crosses array bounds
    size--;     // Decrease queue size
    return data; }
int isFull ( ) // Checks if queue is full or not. It returns 1 if queue is full,  overwise returns 0.
{	return (size == CAPACITY);}
int isEmpty()    //Checks if queue is empty or not. It returns 1 if queue is empty, otherwise returns 0
{	return (size == 0); }
int getFront()// Gets, front of the queue. If queue is empty return INT_MAX otherwise returns front of queue.
{  return (isEmpty())
            ? INT_MIN
            : queue[front]; }


int getRear()  // Gets, rear of the queue. If queue is empty return INT_MAX otherwise returns rear of queue.
  {  return (isEmpty())
            ? INT_MIN
            : queue[rear]; }

