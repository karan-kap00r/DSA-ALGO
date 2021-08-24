// C++ program to evaluate value of a postfix expression  
#include <iostream>  
#include <string.h>  
 #include<malloc.h> 
using namespace std; 
 

// Stack type  
struct ArrayStack  
{  
    int top;  
    unsigned capacity;  
    int* array;  
};  
  
// Stack Operations  
 struct ArrayStack* createStack(unsigned cap)
{
	struct ArrayStack* stack ;
	stack=(ArrayStack*)malloc(sizeof(struct ArrayStack));
	stack->top=-1;
	stack->capacity=cap;
	stack->array=(int*)malloc(sizeof(int)*stack->capacity);
	return (stack);
}
  
 int isEmpty(struct ArrayStack* stack)
{
	(stack->top==-1);
	return(0);
}

char pop(struct ArrayStack* stack)  
{  
    if (!isEmpty(stack))  
       return stack->array[stack->top--] ;  
      
} 
void push(struct ArrayStack* stack, char op)  
{  
    stack->array[stack->top++];  
    stack->array[stack->top]=op;
}  

int evaluatePostfix(char* exp)
{
struct ArrayStack* stack = createStack(strlen(exp));
	int i;
	if (!stack) return(-1);
	for(i=0;exp[i];++i)
	{
		if(isdigit(exp[i]))
		push(stack,exp[i]-'0');
  
// The main function that returns value of a given postfix expression  

          // If the scanned character is an operator, pop two  
        // elements from stack apply the operator  
       	else
	{
		int val1=pop(stack);
		int val2=pop(stack);
		switch(exp[i])
         	{
         		
			case '+': push(stack, val2 + val1);	break;                                       
	
			case '-': push(stack, val2 - val1);	break;
		
			case '*': push(stack, val2 * val1);	break;
		
			case '/': push(stack, val2 / val1);	break;
		
		}
        }  
    }  
    return pop(stack);  
}  
// Driver program to test above functions  
int main()  
{  
    char exp[] = "472*-5+";  
    cout<<"postfix evaluation: "<< evaluatePostfix(exp);  
    return 0;  
}  













