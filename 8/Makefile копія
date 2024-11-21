CC = gcc
CXX = g++
CFLAGS = -Wall -g
GTEST_LIB = -lgtest -lgtest_main -pthread

# Виконувані файли
TARGET_LIST_MAIN = 7main
TARGET_GETLINE = getline_test
TARGET_POLYGON = polygon
TARGET_TEST_LIST = test_c_list

# Об'єкти
OBJ_LIST_MAIN = 7_c_list.o 7main.o
OBJ_GETLINE = getline.o 7.2main.o
OBJ_POLYGON = polygon.o
OBJ_TEST_LIST = 8c_list.o 8c_list_test.o

# Правило для збірки всіх компонентів
all: $(TARGET_LIST_MAIN) $(TARGET_GETLINE) $(TARGET_POLYGON) $(TARGET_TEST_LIST)

# Збірка списку (основна програма)
$(TARGET_LIST_MAIN): $(OBJ_LIST_MAIN)
	$(CC) $(CFLAGS) -o $(TARGET_LIST_MAIN) $(OBJ_LIST_MAIN)

# Збірка getline (основна програма)
$(TARGET_GETLINE): $(OBJ_GETLINE)
	$(CC) $(CFLAGS) -o $(TARGET_GETLINE) $(OBJ_GETLINE)

# Збірка багатокутників
$(TARGET_POLYGON): $(OBJ_POLYGON)
	$(CC) $(CFLAGS) -o $(TARGET_POLYGON) $(OBJ_POLYGON)

# Збірка модульних тестів для списків
$(TARGET_TEST_LIST): $(OBJ_TEST_LIST)
	$(CXX) $(CFLAGS) -o $(TARGET_TEST_LIST) $(OBJ_TEST_LIST) $(GTEST_LIB)

# Об'єкти
7_c_list.o: 7_c_list.c 7_c_list.h
	$(CC) $(CFLAGS) -c 7_c_list.c

7main.o: 7main.c 7_c_list.h
	$(CC) $(CFLAGS) -c 7main.c

getline.o: getline.c
	$(CC) $(CFLAGS) -c getline.c

7.2main.o: 7.2main.c
	$(CC) $(CFLAGS) -c 7.2main.c

polygon.o: polygon.c polygon.h
	$(CC) $(CFLAGS) -c polygon.c

8c_list.o: 8c_list.c 8c_list.h
	$(CC) $(CFLAGS) -c 8c_list.c

8c_list_test.o: 8c_list_test.cpp 8c_list.h
	$(CXX) $(CFLAGS) -c 8c_list_test.cpp

# Очищення
clean:
	rm -f *.o $(TARGET_LIST_MAIN) $(TARGET_GETLINE) $(TARGET_POLYGON) $(TARGET_TEST_LIST)
