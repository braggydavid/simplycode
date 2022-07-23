UTIL = ../../util
EXE = lis

$(EXE) : $(EXE)-main.cc $(EXE).o 
	g++ -I$(UTIL) $(EXE)-main.cc $(EXE).o \
	$(UTIL)/inputman.o $(UTIL)/print.o -o $(EXE)

$(EXE).o : $(EXE).cc $(EXE).h
	g++ -c $(EXE).cc

.PHONY : clean

clean :
	rm -rf *.o $(EXE)
