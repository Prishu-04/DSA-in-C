#include <stdio.h>
#include <stdlib.h>
#define MAX 5
// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;
// Queue structure using two stacks
typedef struct {
    Stack s1, s2;
} Queue;
// Initialize a stack
void initStack(Stack *s) {
    s->top = -1;
}
// Initialize queue
void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}
// Push element
void push(Stack *s, int value) {
    if (s->top==MAX-1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}
// Pop element
int pop(Stack *s) {
    if (s->top==-1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}
// Enqueue (push into s1)
void enqueue(Queue *q, int value) {
    if ((&q->s1)->top == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    push(&q->s1, value);
    printf("%d enqueued to queue\n", value);
}
// Dequeue (pop from s2)
int dequeue(Queue *q) {
    int val;
    if (((&q->s1)->top==-1) && ((&q->s2)->top==-1)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    // If s2 is empty, transfer all elements from s1
    if ((&q->s2)->top == -1) {
        while ((&q->s1)->top != -1) {
            push(&q->s2, pop(&q->s1));
        }
    }
    val = pop(&q->s2);
    printf("%d dequeued from queue\n", val);
    return val;
}
// Display queue contents
void display(Queue *q) {
     if (((&q->s1)->top==-1) && ((&q->s2)->top==-1)) {
          printf("Queue is empty\n");
          return;
     }
     printf("Queue elements (front to rear): ");
     // If s2 has elements, print them first (they’re reversed)
     for (int i = q->s2.top; i >= 0; i--)
          printf("%d ", q->s2.data[i]);
     // Then print elements of s1 in normal order
     for (int i = 0; i <= q->s1.top; i++)
          printf("%d ", q->s1.data[i]);
     printf("\n");
     printf("\n[Internal State of Two Stacks]\n");
     printf("Index | Insertion Stack | Deletion Stack\n");
     printf("----------------------------------------\n");

     int maxTop = (q->s1.top > q->s2.top) ? q->s1.top : q->s2.top;

     for (int i = maxTop; i >= 0; i--) {
     printf("  %2d  |", i);

     // Insertion stack (left column)
     if (i <= q->s1.top)
          printf("     %2d     |", q->s1.data[i]);
     else
          printf("     _      |");

     // Deletion stack (right column)
     if (i <= q->s2.top)
          printf("     %2d\n", q->s2.data[i]);
     else
          printf("     _\n");
     }

     printf("----------------------------------------\n");
     printf("     ^Top s1=%d           ^Top s2=%d\n", q->s1.top, q->s2.top);

}
// Main function
int main() {
    Queue q;
    initQueue(&q);
    int choice, val;
    do {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}