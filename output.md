 ## MADHAV NATARAJAN H ##
 ## PES2UG19EC064 SECTION H ##

 
 The program reads input from a file.The runway exhibits three states viz. IDLE,LANDING and TAKEOFF. There are two events viz. takeoff request and landing request. There is also a timetick event which moves the clock forward.
 On any type of request received, the planes are added to the respective queues of size (lqs,tqs)landing or takeoff. The runway is occupied for certain time which is controlled by the holdingtime parameters(lht,tht).
 Time counter Tc signifies the time when the next event can be handled by the runway.
 https://github.com/madhavnatarajan/airport_simulation. This code is checked into this repository.
 <pre>
 ./runway -lht 5 -tht 5 -lqs 4 -tqs 3
argc is 9
Program Name Is: ./runway
Number Of Arguments Passed: 9
argv[1]: -lht
argv[3]: -tht
argv[5]: -lqs
argv[7]: -tqs
FileName is string.txt
 takeoffqsize is 3
 landingqSize is 4
 landingHoldingTime is 5
 TakeoffHoldingTime is 5 

Time is 1400
handle time tick event  for IDLE

Time is 1401
handle TREvent for IDLE
Flight plane1 Queued at 1401 for takeoff 
Flight plane8 Queued at 1401 for landing
Stil within TAKEOFFHOLDINGTIME 1406
Flight plane9 Queued at 1401 for landing
Stil within TAKEOFFHOLDINGTIME 1406

Time is 1402
Flight plane2 Queued at 1402 for takeoff
still within takeoff holding time 1406 
 Flight plane3 Queued at 1402 for takeoff
still within takeoff holding time 1406 
 Flight plane4 Queued at 1402 for takeoff
still within takeoff holding time 1406 
 takeoff queue is full. Rejecting plane5 at 1402
takeoff queue is full. Rejecting plane6 at 1402
takeoff queue is full. Rejecting plane7 at 1402

Time is 1403
Stil within TAKEOFFHOLDINGTIME 1406

Time is 1404
Stil within TAKEOFFHOLDINGTIME 1406

Time is 1405
Stil within TAKEOFFHOLDINGTIME 1406

Time is 1406
Flight plane8 Landing . Queued at 1401 . DeQueued at 1406 . In Queue for 5
Flight plane10 Queued at 1406 for landing
Stil within LANDInGHOLDINGTIME 1411
takeoff queue is full. Rejecting plane11 at 1406

Time is 1407
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1411

Time is 1408
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1411

Time is 1409
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1411

Time is 1410
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1411

Time is 1411
handle time tick event for LANDING
Flight plane9 Landing . Queued at 1401 . DeQueued at 1411 . In Queue for 10

Time is 1412
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1416

Time is 1413
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1416

Time is 1414
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1416

Time is 1415
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1416
Flight plane12 Queued at 1415 for landing
Stil within LANDInGHOLDINGTIME 1416

Time is 1416
handle time tick event for LANDING
Flight plane10 Landing . Queued at 1406 . DeQueued at 1416 . In Queue for 10

Time is 1417
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1421

Time is 1418
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1421

Time is 1419
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1421

Time is 1420
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1421

Time is 1421
handle time tick event for LANDING
Flight plane12 Landing . Queued at 1415 . DeQueued at 1421 . In Queue for 6

Time is 1422
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1426

Time is 1423
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1426

Time is 1424
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1426

Time is 1425
handle time tick event for LANDING
Stil within LANDInGHOLDINGTIME 1426

Time is 1426
handle time tick event for LANDING
Flight plane2 TakeOff . Queued at 1402 . DeQueued at 1426 . In Queue for 24

Time is 1427
Stil within TAKEOFFHOLDINGTIME 1431

Time is 1428
Stil within TAKEOFFHOLDINGTIME 1431

Time is 1429
Stil within TAKEOFFHOLDINGTIME 1431

Time is 1430
Stil within TAKEOFFHOLDINGTIME 1431

Time is 1431
Flight plane3 TakeOff . Queued at 1402 . DeQueued at 1431 . In Queue for 29

Time is 1432
Stil within TAKEOFFHOLDINGTIME 1436

Time is 1433
Stil within TAKEOFFHOLDINGTIME 1436

Time is 1434
Stil within TAKEOFFHOLDINGTIME 1436

Time is 1435
Stil within TAKEOFFHOLDINGTIME 1436

Time is 1436
Flight plane4 TakeOff . Queued at 1402 . DeQueued at 1436 . In Queue for 34

Time is 1437
Stil within TAKEOFFHOLDINGTIME 1441

Time is 1438
Stil within TAKEOFFHOLDINGTIME 1441

Time is 1439
Stil within TAKEOFFHOLDINGTIME 1441

Time is 1440
Stil within TAKEOFFHOLDINGTIME 1441

Time is 1441
current state returned to idle
Time is 1442
handle time tick event  for IDLE

Time is 1443
handle time tick event  for IDLE

Time is 1444
handle time tick event  for IDLE

Time is 1445
handle time tick event  for IDLE

Time is 1446
handle time tick event  for IDLE

Time is 1447
handle time tick event  for IDLE

Time is 1448
handle time tick event  for IDLE

Time is 1449
handle time tick event  for IDLE

Time is 1450
handle time tick event  for IDLE

Time is 1451
handle time tick event  for IDLE

Time is 1452
handle time tick event  for IDLE

Time is 1453
handle time tick event  for IDLE

Time is 1454
handle time tick event  for IDLE

Time is 1455
handle time tick event  for IDLE

Time is 1456
handle time tick event  for IDLE

Time is 1457
handle time tick event  for IDLE

Time is 1458
handle time tick event  for IDLE

Time is 1459
handle time tick event  for IDLE


			REPORT



total time taken:60

number of flights landed:4

number of flights taken off:4

number of flights diverted from the runway:0

number of flights rejected for takeoff:4

total idle (free) runway time:19

max waiting time in queue to takeoff:34

max waiting time in queue to land:10

no of planes yet to land 0

no of planes yet to takeoff 0
</pre>
Documentation :
![handletimetick](handletimetick.jpg)
handle time tick event

![handleTR](handleTR.jpg)
handle takeoff request event

![handleLR](handleLR.jpg)
handle landing request event

