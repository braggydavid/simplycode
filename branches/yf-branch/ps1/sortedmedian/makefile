UTIL = ../../util
EXE = sortedmedian

$(EXE) : $(EXE)-main.cc $(EXE).o 
	g++ -I$(UTIL) $(EXE)-main.cc $(EXE).o \
	$(UTIL)/inputman.o -o $(EXE)

$(EXE).o : $(EXE).cc $(EXE).h
	g++ -c $(EXE).cc

.PHONY : clean

clean :
	rm -rf *.o $(EXE)