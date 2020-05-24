#include "airport.h"

struct abc empty={"",00,00}; //representing an empty flight object  

// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (struct abc*) malloc(queue->capacity * sizeof(struct abc)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void flightEnqueue(struct Queue* queue, struct abc item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    //printf("%s enqueued to queue\n", item.planeID); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
struct abc flightDequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return empty ; 
    struct abc item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

//function to get size of the queue
int qsize(struct Queue* queue)
{
    return(queue->size);
}
  
// Function to get front of queue 
struct abc front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return empty; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
struct abc rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return empty; 
    return queue->array[queue->rear]; 
} 
  
// Driver program to test above functions./ 
/*
int main() 
{ 
    struct Queue* queue = createQueue(1000); 
    struct abc t1={"plane1",1400,00};
    flightEnqueue(queue,t1);
    strcpy(t1.planeID,"plane2");
    t1.timeIN=1401;
    t1.timeOUT=00;
    flightEnqueue(queue,t1);
    strcpy(t1.planeID,"plane3");
    t1.timeIN=1405;
    t1.timeOUT=00;
    flightEnqueue(queue, t1);
    strcpy(t1.planeID,"plane4");
    t1.timeIN=1407;
    t1.timeOUT=00; 
    flightEnqueue(queue,t1);

    struct abc t2=flightDequeue(queue); 
  
    printf("%s %d %d\n dequeued from queue\n\n", t2.planeID,t2.timeIN,t2.timeOUT); 
  
    printf("Front item is %s\n", front(queue).planeID); 
    printf("Rear item is %s\n", rear(queue).planeID); 
  
    return 0; 
} 
*/