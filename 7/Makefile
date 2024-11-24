CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = list_program
SRCS = 7main.c 7_c_list.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
