#include "airport.h"

void handleTimeTickEvent(struct runway *r, int cTime)
{

    switch (r->currentState)
    {
    case IDLE:
        printf("handle time tick event  for IDLE\n");
        r->currentState = IDLE;
        r->Tc = cTime + 1;
        r->idlestateCount++;
        break;
    case LANDING:
        printf("handle time tick event for LANDING\n");
        if (r->Tc == cTime)
        {
            if (isEmpty(r->landingQ))
            {
                if (isEmpty(r->takeOffQ))
                {
                    r->currentState = IDLE;
                    printf(" Setting runway state to IDLE \n");
                }
                else
                {
                    struct abc t1 = flightDequeue(r->takeOffQ);
                    t1.timeOUT = cTime;
                    r->Tc = cTime + r->takeoffHoldingTime;
                    r->currentState = TAKEOFF;
                    r->flightsTakenoff++;
                    printf("Flight %s TakeOff . Queued at %d . DeQueued at %d . In Queue for %d\n", t1.planeID, t1.timeIN, t1.timeOUT, (t1.timeOUT - t1.timeIN));
                    if((t1.timeOUT-t1.timeIN)>r->takeoffPeakTime)
                    {
                        r->takeoffPeakTime=t1.timeOUT-t1.timeIN;
                    }
                } 
            }
            else
            {
                struct abc t1 = flightDequeue(r->landingQ);
                t1.timeOUT = cTime;
                r->Tc = cTime + r->landingHoldingTime;
                r->currentState = LANDING;
                r->flightsLanded++;
                printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t1.planeID, t1.timeIN, t1.timeOUT, (t1.timeOUT - t1.timeIN));
                if((t1.timeOUT-t1.timeIN)>r->landingPeakTime)
                {
                    r->landingPeakTime=(t1.timeOUT-t1.timeIN);
                }
            }
        }
        else
        {
            printf("Stil within LANDInGHOLDINGTIME %d\n", r->Tc);
        }
        break;
    case TAKEOFF:
        //printf("handle time tick event for TAKEOFF . Code to be written \n");
        //printf(" Code to be written ");
        if (cTime == r->Tc)
        {
            if (isEmpty(r->landingQ))
            {
                if (isEmpty(r->takeOffQ))
                {
                    r->currentState = IDLE;
                    printf("current state returned to idle");
                }
                else
                {
                    struct abc t1 = flightDequeue(r->takeOffQ);
                    t1.timeOUT = cTime;
                    r->Tc = cTime + r->takeoffHoldingTime;
                    r->currentState = TAKEOFF;
                    r->flightsTakenoff++;
                    printf("Flight %s TakeOff . Queued at %d . DeQueued at %d . In Queue for %d\n", t1.planeID, t1.timeIN, t1.timeOUT, (t1.timeOUT - t1.timeIN));
                    if((t1.timeOUT-t1.timeIN)>r->takeoffPeakTime)
                    {
                        r->takeoffPeakTime=t1.timeOUT-t1.timeIN;
                    }
                }
            }
            else
            {
                struct abc t1 = flightDequeue(r->landingQ);
                t1.timeOUT = cTime;
                r->Tc = cTime + r->landingHoldingTime;
                r->currentState = LANDING;
                r->flightsLanded++;
                printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t1.planeID, t1.timeIN, t1.timeOUT, (t1.timeOUT - t1.timeIN));
            }
        }
        else
        {
            r->currentState = TAKEOFF;
            printf("Stil within TAKEOFFHOLDINGTIME %d\n", r->Tc);
        }

        break;
    }
}
void handleTREvent(struct runway *r, int cTime, char *flight)
{
    struct abc t1;
    //printf("handle TR\n");
    switch (r->currentState)
    {
    case IDLE:
        printf("handle TREvent for IDLE\n");
        strcpy(t1.planeID, flight);
        t1.timeIN = cTime;
        t1.timeOUT = 00;
        flightEnqueue(r->takeOffQ, t1);
        printf("Flight %s Queued at %d for takeoff \n", t1.planeID, t1.timeIN);
        t1 = flightDequeue(r->takeOffQ);
        t1.timeOUT = cTime;
        r->currentState = TAKEOFF;
        r->flightsTakenoff++;
        r->Tc = cTime + r->takeoffHoldingTime;
        break;
    case LANDING:
        //printf(" Handle TREvent for LANDING. Code to be written \n");
        if (isFull(r->takeOffQ))
        {
            printf("takeoff queue is full. Rejecting %s at %d\n", flight, cTime);
            r->flightsRejected++;
        }
        else
        {
            flightEnqueue(r->takeOffQ, t1);
            printf("Flight %s Queued at %d for takeoff\n", t1.planeID, t1.timeIN);
            if (cTime == r->Tc)
            {
                if (isEmpty(r->landingQ))
                {
                    struct abc t2 = flightDequeue(r->takeOffQ);
                    r->Tc = cTime + r->takeoffHoldingTime;
                    r->currentState = TAKEOFF;
                    r->flightsTakenoff++;
                    printf("Flight %s taking off . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));
                    if((t2.timeOUT-t2.timeIN)>r->takeoffPeakTime)
                    {
                        r->takeoffPeakTime=t2.timeOUT-t2.timeIN;
        
                    }
                }
                else
                {
                    struct abc t2 = flightDequeue(r->landingQ);
                    r->Tc = cTime + r->landingHoldingTime;
                    r->currentState = LANDING;
                    r->flightsLanded++;
                    printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));
                    if((t2.timeOUT-t2.timeIN)>r->landingPeakTime)
                    {
                        r->landingPeakTime=t2.timeOUT-t2.timeIN;
                    }

                }

                //r->Tc=cTime+r->landingHoldingTime;
            }
            else
            {
                r->currentState = LANDING;
                printf("Stil within LANDINGHOLDINGTIME %d\n", r->Tc);
            }
        }
        break;
    case TAKEOFF:
        if (isFull(r->takeOffQ))
        {
            printf("takeoff queue is full. Rejecting %s at %d\n", flight, cTime);
            r->flightsRejected++;
        }
        else
        {
            strcpy(t1.planeID, flight);
            t1.timeIN = cTime;
            t1.timeOUT = 00;
            flightEnqueue(r->takeOffQ, t1);
            printf("Flight %s Queued at %d for takeoff\n", t1.planeID, t1.timeIN);
            if (cTime == r->Tc)
            {
                if (isEmpty(r->landingQ))
                {
                    
                    struct abc t2 = flightDequeue(r->takeOffQ);
                    cTime = r->Tc + r->takeoffHoldingTime;

                    r->currentState = TAKEOFF;
                    r->flightsTakenoff++;
                    printf("Flight %s taking off . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));
                    if((t2.timeOUT-t2.timeIN)>r->takeoffPeakTime)
                    {
                        r->takeoffPeakTime=t2.timeOUT-t2.timeIN;
                    }

                }
                else
                {
                    struct abc t2 = flightDequeue(r->landingQ);
                    r->Tc = cTime + r->landingHoldingTime;
                    r->currentState = LANDING;
                    r->flightsLanded++;
                    printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));

                    if((t2.timeOUT-t2.timeIN)>r->landingPeakTime)
                    {
                        r->landingPeakTime=t2.timeOUT-t1.timeIN;
                    }
                }
            }
            else
            {
                r->currentState = TAKEOFF;
                printf("still within takeoff holding time %d \n ", r->Tc);
            }
        }

        break;
    }
}
void handleLREvent(struct runway *r, int cTime, char *flight)
{
    struct abc t1;

    switch (r->currentState)
    {
    case IDLE:
        printf("handle LREvent for IDLE \n");
        strcpy(t1.planeID, flight);
        t1.timeIN = cTime;
        //t1.timeOUT = 00;
        //flightEnqueue(r->landingQ, t1);
        //printf("Flight %s Queued at %d for landing\n",t1.planeID,t1.timeIN);
        //t1 = flightDequeue(r->landingQ);
        t1.timeOUT = cTime;
        r->currentState = LANDING;
        r->Tc = cTime + r->landingHoldingTime;
        r->flightsLanded++;
        printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t1.planeID, t1.timeIN, t1.timeOUT, (t1.timeOUT - t1.timeIN));
        if((t1.timeOUT-t1.timeIN)>r->landingPeakTime)
                    {
                        r->landingPeakTime=t1.timeOUT-t1.timeIN;
                    }

        break;
    case LANDING:
        // printf(" handle LREvent for LANDING. Code to be written \n");
        strcpy(t1.planeID, flight);
        t1.timeIN = cTime;
        t1.timeOUT = 00;
        if (isFull(r->landingQ))
        {
            printf("landing queue is full. Diverting %s at %d\n", flight, cTime);
            r->flightsDiverted++;
        }
        else
        {
            flightEnqueue(r->landingQ, t1);
            printf("Flight %s Queued at %d for landing\n", t1.planeID, t1.timeIN);
            if (cTime == r->Tc)
            {
                struct abc t2;
                t2 = flightDequeue(r->landingQ);
                r->flightsLanded++;
                printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));
                if((t2.timeOUT-t2.timeIN)>r->landingPeakTime)
                    {
                        r->landingPeakTime=t2.timeOUT-t2.timeIN;
                    }


                r->Tc = cTime + r->landingHoldingTime;
            }
            else
            {
                r->currentState = LANDING;
                printf("Stil within LANDInGHOLDINGTIME %d\n", r->Tc);
            }
        }
        break;
    case TAKEOFF:
        //printf(" handle LREvent for TAKEOFF. Code to be written ");
        if (!isFull(r->landingQ))
        {
            strcpy(t1.planeID, flight);
            t1.timeIN = cTime;
            t1.timeOUT = 00;
            flightEnqueue(r->landingQ, t1);
            printf("Flight %s Queued at %d for landing\n", t1.planeID, t1.timeIN);
            if (cTime == r->Tc)
            {
                r->Tc = cTime + r->landingHoldingTime;
                struct abc t2 = flightDequeue(r->landingQ);
                printf("Flight %s Landing . Queued at %d . DeQueued at %d . In Queue for %d\n", t2.planeID, t2.timeIN, t2.timeOUT, (t2.timeOUT - t2.timeIN));
                if((t2.timeOUT-t2.timeIN)>r->landingPeakTime)
                    {
                        r->landingPeakTime=t2.timeOUT-t2.timeIN;
                    }

                r->currentState = LANDING;
                r->flightsLanded++;
            }
            else
            {
                r->currentState = TAKEOFF;
                printf("Stil within TAKEOFFHOLDINGTIME %d\n", r->Tc);
            }
        }
        else
        {
            printf("landing queue is full. Diverting %s at %d\n", flight, cTime);
            r->flightsDiverted++;
        }

        break;
    }
}
void printReport(struct runway r)
{
    printf("\n\n\t\t\tREPORT\n\n\n");
    printf("\n");
    printf("total time taken:%d\n", r.Tc - r.startTime);
    printf("\n");
    printf("number of flights landed:%d\n", r.flightsLanded);
    printf("\n");
    printf("number of flights taken off:%d\n", r.flightsTakenoff);
    printf("\n");
    printf("number of flights diverted from the runway:%d\n", r.flightsDiverted);
    printf("\n");
    printf("number of flights rejected for takeoff:%d\n", r.flightsRejected);
    printf("\n");
    printf("total idle (free) runway time:%d\n", r.idlestateCount);
    printf("\n");
    printf("max waiting time in queue to takeoff:%d\n",r.takeoffPeakTime);
    printf("\n");
    printf("max waiting time in queue to land:%d\n",r.landingPeakTime);
    printf("\n");
    printf("no of planes yet to land %d\n",r.landingQ->size);
    printf("\n");
    printf("no of planes yet to takeoff %d\n",r.takeOffQ->size);
    printf("\n");
}


void simulate(char *fileName, int takeoffqSize, int landingqSize, int landingHoldingTime, int takeoffHoldingTime)
{
    FILE *fp;
    char ch;
    char line[4096];
    char *token;
    int tokenposition = 0;
    int lineposition = 0;
    struct runway r;
    r.landingHoldingTime = landingHoldingTime;
    r.takeoffHoldingTime = takeoffHoldingTime;
    struct Queue *queue = createQueue(landingqSize);
    r.landingQ = queue;
    struct Queue *queue1 = createQueue(takeoffqSize);
    r.takeOffQ = queue1;
    int currentTime;

    fp = fopen(fileName, "r");
    while (fgets(line, 4096, fp) != NULL)
    {
        //printf("%s\n",line);
        tokenposition = 0;
        token = strtok(line, ","); //split the line based on commas
        //line[strcspn(line,"\n")]=0;
        printf("\nTime is %s\n", token);
        currentTime = atoi(token);
        if (lineposition == 0)
            r.startTime = currentTime;

        while (token != NULL)
        {

            //printf("Token is %s\n", token);
            char stateofEvent[3];
            char *flight;

            if (strcmp(token, "timetick") == 0)
            {
                handleTimeTickEvent(&r, currentTime);
            }
            else if (strcmp(token, "LR") == 0)
            {
                strcpy(stateofEvent, "LR");
                //handleLR(r);
            }
            else if (strcmp(token, "TR") == 0)
            {
                strcpy(stateofEvent, "TR");
                //handleTR(r);
            }
            else
            {
                if (strcmp(stateofEvent, "TR") == 0)
                {
                    flight = token;
                    handleTREvent(&r, currentTime, flight);
                    strcpy(stateofEvent, "");
                }
                else if (strcmp(stateofEvent, "LR") == 0)
                {
                    flight = token;
                    handleLREvent(&r, currentTime, flight);
                    strcpy(stateofEvent, "");
                }
            }
            token = strtok(NULL, ",");
            lineposition++;
        }
    }
    printReport(r);
}

void main(int argc, char *argv[])
{
    char flag[20];
    char flagarg[20];
    char fileName[20];
    int landingHoldingTime = 0;
    int takeoffHoldingTime = 0;
    int landingqSize = 0;
    int takeoffqSize = 0;
    //strcpy(fileName,NULL);

    fileName[0] = '\0';
    printf("argc is %d\n", argc);
    printf("Program Name Is: %s\n", argv[0]);
    int i;
    if (argc == 1)
    {
        printf("\nUsing defaults \n ");
    }
    else
    {
        printf("Number Of Arguments Passed: %d\n", argc);
        i = 1;
        while (i < argc)
        {
            strcpy(flag, argv[i]);
            printf("argv[%d]: %s\n", i, flag);

            if (strcmp(flag, "-f") == 0)
            {
                //strcpy(tmp,argv[i+1]);
                strcpy(fileName, argv[i + i]);
                i += 2;
            }
            else if (strcmp(flag, "-lht") == 0)
            {
                landingHoldingTime = atoi(argv[i + 1]);
                i += 2;
            }
            else if (strcmp(flag, "-tht") == 0)
            {
                takeoffHoldingTime = atoi(argv[i + 1]);
                i += 2;
            }
            else if (strcmp(flag, "-lqs") == 0)
            {
                landingqSize = atoi(argv[i + 1]);
                i += 2;
            }
            else if (strcmp(flag, "-tqs") == 0)
            {
                takeoffqSize = atoi(argv[i + 1]);
                i += 2;
            }
            else if (strcmp(flag, "-h") == 0)
            {
                printf("Usage : %s -f <filename> -lqs <landing q size> -tqs <takeoff q size> -lht < landing holding time> -tht <takeoff holding time> -h \n",argv[0]);
                exit(0);
            }
        }
    }
    if (strlen(fileName) <= 0)
        strcpy(fileName, "string.txt");
    if (landingqSize == 0)
        landingqSize = QSIZE;
    if (takeoffqSize == 0)
        takeoffqSize = QSIZE;
    if (landingHoldingTime == 0)
        landingHoldingTime = LANDINGHOLDINGTIME;
    if (takeoffHoldingTime == 0)
        takeoffHoldingTime = TAKEOFFHOLDINGTIME;

    printf("FileName is %s\n takeoffqsize is %d\n landingqSize is %d\n landingHoldingTime is %d\n TakeoffHoldingTime is %d \n", fileName, takeoffqSize, landingqSize, landingHoldingTime, takeoffHoldingTime);
    simulate(fileName, takeoffqSize, landingqSize, landingHoldingTime, takeoffHoldingTime);
}