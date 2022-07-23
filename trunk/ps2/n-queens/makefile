EXE = queens
CC = g++
UTILS = ../../util
CFLAGS = -g -I. -I$(UTILS)
SRCS = $(wildcard *.cc $(UTILS)/*.cc)
OBJS = $(SRCS:.cc=.o)

.cc.o:
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean
all: $(EXE)

clean:
	-rm -f $(OBJS) $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
