#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX], f, r;
} queue;

typedef struct {
    queue q1, q2;
    int active; // 1 => q1 active, 2 => q2 active
} stack;

void initqueue(queue *q) {
    q->f = 0;
    q->r = 0;
}

void initstack(stack *s) {
    initqueue(&s->q1);
    initqueue(&s->q2);
    s->active = 1;
}

void insert(queue *q, int val) {
    if (q->r == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    q->arr[q->r++] = val;
}

int delete(queue *q) {
    if (q->f == q->r) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q->arr[q->f++];
}

void displayqueues(stack *s) {
    queue *actq = (s->active == 1) ? &s->q1 : &s->q2;
    queue *inactq = (s->active == 1) ? &s->q2 : &s->q1;

    printf("\nActive Queue: %s\n", (s->active == 1) ? "q1" : "q2");
    for (int i = 0; i < MAX; i++) {
        if (i >= actq->f && i < actq->r)
            printf("| %d ", actq->arr[i]);
        else
            printf("| _ ");
    }
    printf("|\n");

    printf("Inactive Queue: %s\n", (s->active == 1) ? "q2" : "q1");
    for (int i = 0; i < MAX; i++) {
        if (i >= inactq->f && i < inactq->r)
            printf("| %d ", inactq->arr[i]);
        else
            printf("| _ ");
    }
    printf("|\n\n");
}

int push(stack *s, int val) {
    queue *actq = (s->active == 1) ? &s->q1 : &s->q2;
    insert(actq, val);
    printf("\nAfter pushing %d:\n", val);
    displayqueues(s);
    return 1;
}

int pop(stack *s, int *val) {
    queue *actq = (s->active == 1) ? &s->q1 : &s->q2;
    queue *inactq = (s->active == 1) ? &s->q2 : &s->q1;

    if (actq->f == actq->r) {
        printf("Stack Underflow!\n");
        return 0;
    }

    // Move all except last element to inactive queue
    while (actq->r - actq->f > 1) {
        int temp = delete(actq);
        insert(inactq, temp);
    }

    // Pop top element
    *val = delete(actq);

    // Store popped element in inactive queue
    insert(inactq, *val);

    printf("\nPopped: %d (stored in inactive queue)\n", *val);
    displayqueues(s);
    return 1;
}

void display(stack *s) {
    queue *actq = (s->active == 1) ? &s->q1 : &s->q2;

    if (actq->f == actq->r) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("\nCurrent Stack (top to bottom): ");
    for (int i = actq->r - 1; i >= actq->f; i--) {
        printf("%d ", actq->arr[i]);
    }
    printf("\n");
}

int main() {
    stack s;
    initstack(&s);
    int choice, val, d;

    do {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&s, val);
                break;

            case 2:
                pop(&s, &d);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}