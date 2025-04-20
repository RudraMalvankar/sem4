#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int val) {
    if (top < SIZE - 1)
        stack[++top] = val;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return -1;
}

void display() {
    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements to push into stack: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }
    display();
    printf("Popping top element...\n");
    pop();
    display();
    return 0;
}
