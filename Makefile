CC = gcc
CFLAGS = -g -Wall
PROG = main
SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
LIBS += -luuid

$(PROG): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -rf $(PROG) 
