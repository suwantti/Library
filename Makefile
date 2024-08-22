CC = gcc
CFLAGS = -g
SRCS = book.c member.c main.c
PROG = library_system
OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG)