CC = g++

CFLAGS = -c -Wall

LDFLAGS =

SRCS = testRectangularMatrix.cpp

OBJS = $(SRCS:.c=.o)

EXE = prog

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXE)