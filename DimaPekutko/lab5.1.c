#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

//variant 24

typedef struct node {
    struct node *next;
    struct node *prev;
    int digit;
} Node;

typedef struct number {
    Node *head;
    Node *tail;
    int isNeg;
    int length;
} Number;

Number longSumLong(Number firstNum, Number secondNum, int fromFunc);
Number longSubLong(Number firstNum, Number secondNum, int fromFunc);
Number longMulLong(Number firstNum, Number secondNum, int fromFunc);
Number longDivLong(Number firstNum, Number secondNum, int fromFunc);
void clearNumber(Number number);
void addDigit(Number *number, int numberValue);
Number createNumber(char numberValue[]);
void printNumber(Number number);
void flushInput();
int getInt();

int main() {
	printf("First number: ");
	int fnum = getInt();
	printf("Second number: ");
	int snum = getInt();
	char fnBuffer[50], snBuffer[50];
	sprintf(fnBuffer, "%d", fnum);
	sprintf(snBuffer, "%d", snum);

    Number firstNumber = createNumber(fnBuffer);
    Number secondNumber = createNumber(snBuffer);
    Number sum = longSumLong(firstNumber, secondNumber, 0);
    Number sub = longSubLong(firstNumber, secondNumber, 0);
    Number mul = longMulLong(firstNumber, secondNumber, 0);
    Number div = longDivLong(firstNumber, secondNumber, 0);
    printf("sum=");
    printNumber(sum);
    printf("sub=");
    printNumber(sub);
    printf("mul=");
   	printNumber(mul);
    printf("div=");
    printNumber(div);
    clearNumber(firstNumber);
    clearNumber(secondNumber);
    clearNumber(sum);
    clearNumber(sub);
    clearNumber(mul);
    clearNumber(div);
    return 0;
}

void flushInput()
{
    int c;
    do
    {
        if ((c = getchar()) == EOF) exit(1);
    } while (c != '\n');
}

int getInt()
{
    int n;
    char c;
    while(1)
    {
        if (scanf("%d%c", &n, &c) == 2 && c == '\n') return n;
        flushInput();
    }
}

void addDigit(Number *number, int numberValue) {
    Node *element = (Node*)malloc(sizeof(Node));
    element->digit = numberValue;
    element->next = NULL;
    element->prev = NULL;
    if(!number->length) {
        number->head = element;
        number->tail = element;
    }
    else {
        number->tail->next = element;
        element->prev = number->tail;
        number->tail = element;
    }
    number->length++; 
}

Number createNumber(char numberValue[]) {
    Number number = {NULL, NULL, 0, 0};
    if(numberValue[0] == '-') {
        number.isNeg = 1;
        for(int i = strlen(numberValue)-1; i >= 1; i--) {
            addDigit(&number, numberValue[i]-'0');
        }    
        return number;
    }
    for(int i = strlen(numberValue)-1; i >= 0; i--) {
        addDigit(&number, numberValue[i]-'0');
    }
    return number;
}

void clearNumber(Number number) {
	Node *element = number.tail;
	Node *prevElement = element->prev;
	while(prevElement != NULL) {
		free(element);
		element = prevElement;
		prevElement = element->prev;
		number.length--;
	}
	free(element);
	number.head = NULL;
	number.tail = NULL;
	number.isNeg = 0;
	number.length--;
}

void printNumber(Number number) {
    Node *tail = number.tail;
    if(number.isNeg)
        printf("-");
    while(tail) {
        printf("%d", tail->digit);
        tail = tail->prev;
    }
    printf("\n");
}

Number longSumLong(Number firstNum, Number secondNum, int fromFunc) {
    Node *first = firstNum.head;
    Node *second = secondNum.head;
    Number sum = {NULL, NULL, 0, 0};
    int sumValue = 0, firstValue = 0, secondValue = 0, remainder = 0;
    if(!firstNum.isNeg && secondNum.isNeg && !fromFunc) {
        sum = longSubLong(firstNum, secondNum, 1);
        return sum;
    }
    if(firstNum.isNeg && !secondNum.isNeg && !fromFunc) {
        sum = longSubLong(secondNum, firstNum, 1);
        // sum.isNeg = 1;
        return sum;    
    }
    if(firstNum.isNeg && secondNum.isNeg) {
    	sum.isNeg = 1;
    }

    while(first || second) {
        if(first) {
            firstValue = first->digit;
            first = first->next;
        }
        else {
            firstValue = 0;
        }
        if(second) {
            secondValue = second->digit;
            second = second->next;
        }
        else {
            secondValue = 0;
        }
        sumValue = (firstValue + secondValue + remainder) % 10;
        remainder = (firstValue + secondValue + remainder) / 10;
        addDigit(&sum, sumValue);
    }
    if(remainder) {
        addDigit(&sum, remainder);
    }
    return sum;
}

Number longSubLong(Number firstNum, Number secondNum, int fromFunc) {
    Node *first = firstNum.head;
    Node *second = secondNum.head;
    Number sub = {NULL, NULL, 0, 0};
    int subValue = 0, firstValue = 0, secondValue = 0, remainder = 0;
    if(!firstNum.isNeg && secondNum.isNeg && !fromFunc) {
        sub = longSumLong(firstNum, secondNum, 1);
        return sub;
    }
    if(firstNum.isNeg && !secondNum.isNeg && !fromFunc) {
        sub = longSumLong(firstNum, secondNum, 1);
        sub.isNeg = 1;
        return sub;    
    }
    
    int firstIsBigger;

    //check for which number is large
    if(firstNum.length > secondNum.length) {
        firstIsBigger = 1;
    }
    else if(firstNum.length < secondNum.length) {
        firstIsBigger = 0;
    }
    else {
    	first = firstNum.tail;
    	second = secondNum.tail;
    	for(int i = 0; i < firstNum.length; i++) {
    		if(first->digit > second->digit) {
	            firstIsBigger = 1;
	            break;
	        }
	        else if(first->digit < second->digit) {
	            firstIsBigger = 0;
	            break;
	        }
	        first = first->prev;
	        second = second->prev;
    	}
    }

    if(firstIsBigger) {
    	first = firstNum.head;
    	second = secondNum.head;
    	sub.isNeg = 0;
    	if(firstNum.isNeg && secondNum.isNeg)
    		sub.isNeg = 1;
    }
    else {
    	first = secondNum.head;
    	second = firstNum.head;
    	sub.isNeg = 1;
    	if(firstNum.isNeg && secondNum.isNeg)
    		sub.isNeg = 0;
    }

    while(first || second) {
        if(first) {
            firstValue = first->digit;
            first = first->next;
        }
        else {
            firstValue = 0;
        }
        if(second) {
            secondValue = second->digit;
            second = second->next;
        }
        else {
            secondValue = 0;
        }   

        firstValue -= remainder;
        if(firstValue < secondValue) {
            firstValue += 10;
            remainder = 1;
        }
        else {
            remainder = 0;
        }
    
        subValue = (firstValue-secondValue);
        addDigit(&sub, subValue);
    }
    return sub;
}

Number longMulLong(Number firstNum, Number secondNum, int fromFunc) {
    Node *first = firstNum.head;
    Node *second = secondNum.head;
    Number mul = createNumber("0");
    int mulValue = 0, firstValue = 0, secondValue = 0, remainder = 0;
    for(int i = 0; i < secondNum.length; i++) {
        Number number = {NULL, NULL, 0, 0}; 
        if(i) {
            for(int j = 0; j < i; j++) {
                addDigit(&number, 0);
            }
        }
        while(first) {
            mulValue = first->digit*second->digit+remainder;
            if(mulValue >= 10) {
                if(!first->next) {
                    addDigit(&number, mulValue%10);
                    addDigit(&number, mulValue/10);
                }
                else {
                    remainder = mulValue/10;
                    addDigit(&number, mulValue%10);
                }
            } else {
                remainder = mulValue/10;
                addDigit(&number, mulValue%10);
                remainder = 0;
            }
            first = first->next;
        }
        remainder = 0;
        first = firstNum.head;
        second = second->next;
        mul = longSumLong(number, mul, 0);
    }

    if((firstNum.isNeg && !secondNum.isNeg) || (!firstNum.isNeg && secondNum.isNeg)) {
        mul.isNeg = 1;
    }
    else {
        mul.isNeg = 0;
    }

    return mul; 
}

Number longDivLong(Number firstNum, Number secondNum, int fromFunc) {
	Node *first = firstNum.head;
    Node *second = secondNum.head;
    int divValue = 0, firstValue = 0, secondValue = 0, remainder = 0;

    int factor = 1;
    while(first || second) {
    	if(first) {
            firstValue += first->digit*factor;
            first = first->next;
        }
        if(second) {
            secondValue += second->digit*factor;
            second = second->next;
        }
    	factor *= 10;
    }

    divValue = firstValue/secondValue;

    char buffer[50];
    sprintf(buffer, "%d", divValue);

    Number div = createNumber(buffer);

    if((firstNum.isNeg && !secondNum.isNeg) || (!firstNum.isNeg && secondNum.isNeg)) {
        div.isNeg = 1;
    }
    else {
        div.isNeg = 0;
    }
    return div;
}

