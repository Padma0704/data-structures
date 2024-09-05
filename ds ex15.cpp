#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = key;
}
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            return -1;
        }
    }
    return -1;
}
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    printf("Hash Table:\n");
    display();
    int key = 20;
    int index = search(key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }
    return 0;
}

