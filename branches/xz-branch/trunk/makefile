#EXE = 
CC = g++
DS = ../../ds
UTILS = ../../util
CFLAGS = -g -I. -I$(UTILS) -I$(DS)
SRCS = $(wildcard *.cc $(UTILS)/*.cc $(DS)/*.cc)
OBJS = $(SRCS:.cc=.o)

.cc.o:
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean

all: $(EXE)

clean:
	-rm -f $(OBJS) $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
