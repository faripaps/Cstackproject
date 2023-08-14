
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to check if stack is full
bool isFull(struct Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an element to stack
void push(struct Stack* stack, int item)
{
    if (isFull(stack)) {
        printf("Stack is full\n");
    }
    else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// Function to remove an element from stack
int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        int item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// Function to display the elements of stack
void display(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements are:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->items[i]);
        }
    }
}

int main()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    // Push elements to stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Display the stack elements
    display(stack);

    // Pop element from stack
    printf("Popped element: %d\n", pop(stack));

    // Display the stack elements after popping
    display(stack);

    return 0;
}
