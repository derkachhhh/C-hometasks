CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -g
TARGET = main_program
TEST_TARGET = test_program
SRCS = 8main.c 8c_list.c
TEST_SRCS = 8c_list_test.cpp 8c_list.c
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CFLAGS) -lgtest -lpthread -o $@ $^

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)
