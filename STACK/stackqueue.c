#include <stdio.h>
#include <stdlib.h>
#define MAX 5
// Queue structure
typedef struct {
     int data[MAX];
     int front, rear, size;
} Queue;
// Stack structure using one queue
typedef struct {
     Queue q;
} Stack;
// Initialize queue
void initQueue(Queue *q) {
     q->front = 0;
     q->rear = -1;
     q->size = 0;
}
// Initialize stack
void initStack(Stack *s) {
     initQueue(&s->q);
}
// Enqueue
void enqueue(Queue *q, int value) {
     if (q->size == MAX) {
          printf("Queue Overflow\n");
          return;
     }
     q->rear = (q->rear + 1) % MAX;
     q->data[q->rear] = value;
     q->size++;
}
// Dequeue
int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}
// Push operation
void push(Stack *s, int x) {
    if ((&s->q)->size == MAX) {
        printf("Stack Overflow\n");
        return;
    }
    // Enqueue the new element
    enqueue(&s->q, x);
    // Rotate the queue to bring new element to the front
    for (int i = 0; i < s->q.size - 1; i++) {
        enqueue(&s->q, dequeue(&s->q));
    }

    printf("%d pushed to stack\n", x);
}
// Pop operation
int pop(Stack *s) {
     if ((&s->q)->size == 0) {
          printf("Stack Underflow\n");
          return -1;
     }
     int val = dequeue(&s->q);
     printf("%d popped from stack\n", val);
     return val;
}
// Display stack elements
void display(Stack *s) {
     if ((&s->q)->size==0) {
          printf("Stack is empty\n");
          return;
     }
     printf("Stack elements (top to bottom): ");
     int i, index = s->q.front;
     for (i = 0; i < s->q.size; i++) {
          printf("%d ", s->q.data[(index + i) % MAX]);
     }
     printf("\n");
     printf("\n[Queue internal state]\n");
     printf("Front = %d, Rear = %d, Size = %d\n", s->q.front, s->q.rear, s->q.size);

     for (int i = 0; i < MAX; i++) {
          if (s->q.size == 0) {
               printf("| _ "); // empty
          } 
          else if ((s->q.front <= s->q.rear && i >= s->q.front && i <= s->q.rear) ||
                    (s->q.front > s->q.rear && (i >= s->q.front || i <= s->q.rear))) {
               // inside active elements
               printf("| %d ", s->q.data[i]);
          } 
          else {
               printf("| _ "); // blank (unused slot)
          }
     }
     printf("|\n");
}
// Main function
int main() {
     Stack s;
     initStack(&s);
     int choice, val;

     do {
          printf("\n--- Stack Using One Queue ---\n");
          printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
          printf("Enter your choice: ");
          scanf("%d", &choice);

          switch (choice) {
               case 1:
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    push(&s, val);
                    break;
               case 2:
                    pop(&s);
                    break;
               case 3:
                    display(&s);
                    break;
               case 4:
                    exit(0);
               default:
                    printf("Invalid choice!\n");
          }
     }while(choice != 4);
     return 0;
}