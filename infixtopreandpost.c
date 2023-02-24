#include<string.h> 
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
# define MAX 100
struct Stack { 
    int top; 
    int maxSize;
    int* array; 
}; 
struct Stack* create(int max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack; 
} 
int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    return stack->top == stack->maxSize - 1; 
} 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}
void push(struct Stack* stack, char item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 
int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 
int getPostfix(char* expression) 
{ 
    int i, j; 
    struct Stack* stack = create(strlen(expression)); 
    if(!stack)   
        return -1 ; 

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
         if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 
        else if (expression[i] == '(') 
            push(stack, expression[i]); 
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                expression[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1;              
            else
                pop(stack); 
        } 
        else 
        { 
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
                expression[++j] = pop(stack); 
            push(stack, expression[i]); 
        } 
    } 
    while (!isEmpty(stack)) 
        expression[++j] = pop(stack); 
        expression[++j] = '\0'; 
    }

void reverse(char *exp)
{
    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];
    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *exp)
{
    int size = strlen(exp);
    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}
int covertInfixToPostfix(char* expr) 
{ 
    int i, j; 
    struct Stack* stack = create(strlen(expr)); 
    if(!stack) 
        return -1 ; 
    for (i = 0, j = -1; expr[i]; ++i) 
    { 
        if (checkIfOperand(expr[i])) 
            expr[++j] = expr[i]; 
        else if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') 
            push(stack, expr[i]); 
        else if (expr[i]==')' || expr[i]=='}'  || expr[i]==']') 
        {
            if(expr[i]==')')
            {   
                while (!isEmpty(stack) && peek(stack) != '(') 
                    expr[++j] = pop(stack); 
                pop(stack);
            }
            if(expr[i]==']')
            {   
                while (!isEmpty(stack) && peek(stack) != '[') 
                    expr[++j] = pop(stack); 
                pop(stack);
            }
           if(expr[i]=='}')
            {  
                while (!isEmpty(stack) && peek(stack) != '{') 
                    expr[++j] = pop(stack); 
                pop(stack);
            }
        }
        else 
        { 
            while (!isEmpty(stack) && precedence(expr[i]) <= precedence(peek(stack))) 
                expr[++j] = pop(stack); 
            push(stack, expr[i]); 
        }

    } 
    while (!isEmpty(stack)) 
        expr[++j] = pop(stack); 

    expr[++j] = '\0'; 
    } 
int main()
{ 
    char expr[100];
    int a;
    printf("\n\tEnter the Expression:");
    scanf("%s",expr);
    printf("\n\t--------------------------------");
    printf("\n\t 1.PREFIX\n\t 2.POSTFIX\n\t");
    printf("Enter the choice of Expression convert:");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        {
             printf("\n\tThe infix is: ");
             printf("%s\n",expr);
             InfixtoPrefix(expr);
             printf("\n\tThe prefix is: ");
             printf("%s\n",expr);
             break;
        }
        case 2:
        {
             printf("\n\tThe infix is: ");
             printf("%s\n",expr);
             covertInfixToPostfix(expr);
             printf("\n\tThe postfix is: ");
             printf("%s\n",expr);
             break; 
        }
        default:
            {
                printf("Please Enter a Valid Choice");
            }
    }
     
    return 0; 
}