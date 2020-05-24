default: runway

runway: airport.c flightqueue.c airport.h
	gcc  -o runway airport.c flightqueue.c

clean veryclean:
	rm  -f runway

