#include <stdio.h>
#include <stdlib.h>

// ---------------- STACK ADT USING LINKED LIST -------------------

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return (s->top == NULL);
}

// Push data into stack
void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop data from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

// ---------------------- DFS FUNCTION ----------------------------

void DFS(int graph[][20], int n, int start) {
    int visited[20] = {0};
    Stack s;
    initStack(&s);

    push(&s, start);
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (!isEmpty(&s)) {
        int node = pop(&s);
        printf("%d ", node);

        // push all adjacent nodes (in reverse to maintain proper order)
        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                push(&s, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// ---------------------- MAIN PROGRAM ----------------------------

int main() {
    int n, start;
    int graph[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    DFS(graph, n, start);

    return 0;
}
