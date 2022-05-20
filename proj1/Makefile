###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Caroline Chin 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++14
LDFLAGS  = -g3

### for compiling and running the CalcYouLater
CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o 
	$(CXX) $(CXXFLAGS) main.o RPNCalc.o DatumStack.o Datum.o -o CalcYouLater

### rules for other files .o
parser.o: parser.cpp 
	$(CXX) $(CXXFLAGS) -c parser.cpp 
	
DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp 

RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp

### unit testing compiling
unit_test: unit_test_driver.o DatumStack.o Datum.o 
	$(CXX) $(CXXFLAGS) $^

##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^
