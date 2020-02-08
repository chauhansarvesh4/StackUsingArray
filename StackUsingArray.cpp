#include <iostream>

struct STACK {
	int data[10];
	int head;
	int size;
};

STACK create();
void dummyInitilize(STACK*, int);
void display(STACK*);
void push(STACK*,int);
void pop(STACK*);
int isEmpty(STACK*);
int peek(STACK*);
int getLength(STACK*);
void clear(STACK*);


int main()
{
	struct STACK stack;
	stack = create();
	dummyInitilize(&stack, 7);
	//display(&stack);
	//pop(&stack);
	//printf("peek %d\n", peek(&stack));
	//display(&stack);
	//push(&stack, 50);
	//push(&stack, 98);
	//push(&stack, 12);
	//push(&stack, 24);
	display(&stack);
	return 0;
}

void clear(STACK* stack) {
	
	for (int i = 0; i < stack->head; i++) {
		stack->data[i] = -1;
		stack->head--;
	}
}

int getLength(STACK* stack) {
	return stack->head;
}

int peek(STACK* stack) {
	if (stack->head > 0) {
		return stack->data[stack->head - 1];
	}
	printf("StackUnderflow ");
	return -1;
}

int isEmpty(STACK* stack) {
	if (stack->head > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

void pop(STACK* stack) {
	if (stack->head > 0) {
		stack->data[stack->head-1] = -1;
		stack->head--;
	}
	else {
		printf("Stackunderflow\n");
	}
}

void push(STACK* stack,int data) {
	if (stack->head < stack->size) {
		stack->data[stack->head] = data;
		stack->head++;
	}
	else {
		printf("Stackoverflow\n");
	}
}


void dummyInitilize(STACK* stack,int numberOfData) {
	if (numberOfData < stack->size)
	{
		for (int i = 0; i < numberOfData; i++) {
			stack->data[i] = i%2==0 ? i + 3 * (i+1) : i * 3 - i;
			stack->head++;
		}
	}
	else {
		printf("stackOverflow condition! size must be less than or equalto 10\n");
	}
}

void display(STACK* stack) {
	for (int i = 0; i < stack->head; i++) {
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}

STACK create() {
	struct STACK stack;
	stack.head = 0;
	stack.size = 10;
	for (int i = 0; i < 10; i++) {
		stack.data[i] = -1;
	}
	return stack;
}
