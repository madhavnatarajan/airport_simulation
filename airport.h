#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define QSIZE 5
#define LANDINGHOLDINGTIME 5
#define TAKEOFFHOLDINGTIME 5



// A structure to represent a details of the flight 
struct abc
{
    char planeID[10];
    int timeIN;
    int timeOUT;
};



struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    struct abc * array;

}; 

  enum RUNWAYSTATES{IDLE,LANDING,TAKEOFF};
  struct runway //main structure
{
    int startTime;
    int landingHoldingTime;
    int takeoffHoldingTime;
    enum RUNWAYSTATES currentState; 
    int Tc; //time counter which contains timetick in which next instruction has to be executed
    struct Queue *landingQ; //pointer to landing queue
    struct Queue *takeOffQ;
    int flightsLanded;
    int flightsTakenoff;
    int flightsDiverted;
    int flightsRejected;
    int idlestateCount;
    int landingPeakTime;
    int takeoffPeakTime;
};

//functions given extern so that they can be called in other files.
extern struct Queue* createQueue(unsigned capacity);
extern int isFull(struct Queue* queue);
extern int isEmpty(struct Queue* queue);
extern void flightEnqueue(struct Queue* queue, struct abc item);
extern struct abc flightDequeue(struct Queue* queue);
extern struct abc front(struct Queue* queue);
extern struct abc rear(struct Queue* queue);
extern int qsize(struct Queue* queue);