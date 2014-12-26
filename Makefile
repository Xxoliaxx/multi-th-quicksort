testharness: testharness.c sort.h sort.c
	gcc -g -std=c99 testharness.c sort.h sort.c -o testharness -pthread
