CFLAGS = -std=c++11 -Wall

PROGRAM = MarkovDecision
OBJS  =  MDP.o  state.o DecisionSource.o

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	g++ $(OBJS) -o $(PROGRAM)

DecisionSource.o:  DecisionSource.cpp
	g++ -c $(CFLAGS) DecisionSource.cpp

state.o: state.cpp state.h
	g++ -c $(CFLAGS) state.cpp

MDP.o: MDP.cpp MDP.h
	g++ -c $(CFLAGS) MDP.cpp

clean:
	rm -f core $(PROGRAM) $(OBJS)
