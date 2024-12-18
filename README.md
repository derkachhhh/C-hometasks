# Інструкції для компіляції та запуску

## 2. `simple_xor.c`

```bash
gcc simple_xor.c -o simple_xor
./simple_xor
```

---

## 2. `bagatosliv.c`

```bash
gcc bagatosliv.c -o bagatosliv
./bagatosliv
```

---

## 2. `IEEE754.c`

**Компіляція:**
```bash
gcc IEEE754.c -o ieee754 -lm
./ieee754
```

---

## 3. `ceasar.c`

**Компіляція:**
```bash
gcc ceasar.c -o ceasar
./ceasar
```

---

## 3. `masiv3.c`

**Компіляція:**
```bash
gcc masiv3.c -o masiv3
./masiv3
```

---

## 4. `substring.c`

**Компіляція:**
```bash
gcc substring.c -o substring
./substring
```

---

## 4. `advanced_4.c`

**Компіляція:**
```bash
gcc advanced_4.c -o advanced4
./advanced4
```

---

## 5. `bisection.h`, `main.c`, `bisection.c`

**Компіляція:**
```bash
gcc main.c bisection.c -o main -lm
./main
```

---

**Тести:**
```bash
gcc test.c bisection.c -o test -lm
./test
```

---

## 6. `c_list.h`, `6main.c`, `c_list.c`

**Компіляція:**
```bash
gcc 6main.c c_list.c -o c_list
./c_list
```

---

## 6. `advanced_6.c`

**Компіляція:**
```bash
gcc advanced_6.c -o advanced6
./advanced6
```

---

## 7. `7_c_list.h`, `7main.c`, `7_c_list.c`

**Компіляція:**
```bash
make
./test_list
gcc -Wall -g -o test_list 7_c_list.c 7main.c
valgrind ./test_list
```

---

## 7. `getline.c, 7.2main.c`

**Компіляція:**
```bash
make
./getline_test
gcc -Wall -g -o getline_test getline.c 7.2main.c
valgrind ./getline_test
```

---

## 8. `8c_list.h`, `8main.c`, `8c_list.c`

**Компіляція:**
```bash
make
./test_list
g++ -Wall -g -o test_list 8c_list.c 8c_list_test.cpp -lgtest -lgtest_main -lpthread
valgrind ./test_list
```

---

## 8. `polygon.c, polygon.h, polygon.txt`

**Компіляція:**
```bash
make
./polygon_test
gcc -Wall -g -o polygon_test polygon.c
valgrind ./polygon_test
```
