#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct deque {
    int front, rear;
    int arr[MAX_SIZE];
} Deque;

void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int is_empty(Deque *dq) {
    return dq->front == -1;
}

int is_full(Deque *dq) {
    return (dq->rear + 1) % MAX_SIZE == dq->front;
}

void push_back(Deque *dq, int val) {
    if (is_full(dq)) {
        printf("Deque penuh!\n");
        exit(1);
    }
    if (is_empty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->arr[dq->rear] = val;
}

void pop_front(Deque *dq) {
    if (is_empty(dq)) {
        printf("Deque kosong!\n");
        exit(1);
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
}

int front(Deque *dq) {
    if (is_empty(dq)) {
        printf("Deque kosong!\n");
        exit(1);
    }
    return dq->arr[dq->front];
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else if (n < 0) {
            printf("Mana ada kartu minus!\n");
            break;
        }

        Deque cards, discarded;
        init(&cards);
        init(&discarded);
        for (int i = 1; i <= n; i++) {
            push_back(&cards, i);
        }

        int i = 0;
        while (n > 1) {
            push_back(&discarded, cards.arr[i]);
            pop_front(&cards);
            n--;
            i = (i+1) % n;
        }

        printf("Urutan kartu yang dibuang:\n");
        for (int i = 0; i < discarded.rear; i++) {
            printf("%d ", discarded.arr[i]);
        }
        printf("\nKartu terakhir yang tersisa: %d\n", front(&cards));
    }

    return 0;
}
