// variant 17
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

typedef struct Stack             //stack struct
{
	struct Stack *prev;
	struct Stack *next;
	int data;
} Stack;

Stack* push(Stack *stack_, int n) {              //stack push function
	Stack *node = (Stack*)malloc(sizeof(Stack));
	if (!node) {
		exit(1);
	}
	node->data = n;
	if (stack_) {
		stack_->next = node;
	}
	node->prev = stack_;
	node->next = NULL;
	return node;
}

int top(Stack *stack_) {        //stack top function
	if (!stack_) {
		return NULL;
	}

	return stack_->data;
}

Stack* pop(Stack *stack_) {           //stack pop function
	if (!stack_) {
	}
	else {
        if (stack_->prev) {
			stack_->prev->next = NULL;
		}
		Stack *temp = stack_;
		stack_ = stack_->prev;
		free(temp);
	}
	return stack_;
}

int main()                    //start
{
	int *arr, i, sorted, arrmemory;                       //variables decl.
	Stack *stack1 = NULL, *stack2 = NULL, *stack3 = NULL;
									  //stack1 + stack2 -> stack3
	srand(time(0));
	for (i = 0; i < 10 + rand() % 5; i++) {
		stack1 = push(stack1, rand() % 100 + 1);     //filling stack1 with random
	}

	for (i = 0; i < 15 + rand() % 5; i++) {
		stack2 = push(stack2, rand() % 100 + 1);     //filling stack2
	}

	arr = (int*)malloc(40 * sizeof(int));           //array initializing

	i = 0;
	while(top(stack1)) {
		arr[i] = top(stack1);
		stack1 = pop(stack1);               // filling array with elements from stack1
		i++;
	}
	while(top(stack2)) {
		arr[i] = top(stack2);
		stack2 = pop(stack2);              //... from stack2
		i++;
	}
	arrmemory = i;

/*  for (i = 0; i < arrmemory; i++) {
		printf("%d ", arr[i]);             // take a look on array here
	}
	putchar('\n');     */

	sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (i = 0; i < arrmemory - 1; i++) {
			if (arr[i] < arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];               // array sort
				arr[i+1] = temp;
				sorted = 0;
			}
		}
	}

   /*	for (i = 0; i < arrmemory; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');      */             //take a look on array here

	stack3 = push(stack3, arr[0]);
	for (i = 1; i < arrmemory; i++) {
		if (arr[i] == arr[i-1]) {
			continue;                // pushing stack3 from array
		}
		stack3 = push(stack3, arr[i]);
	}

	while(top(stack3)) {
		printf("%d ", top(stack3));      //results
		stack3 = pop(stack3);
	}

	free(arr);

	getchar();
	return 0;
}
