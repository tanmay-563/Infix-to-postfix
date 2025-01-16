#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int empty(struct stack *ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct stack*ptr){
    if(ptr ->top == ptr-> size-1 ){
        return 1;
    }
    else {
        return 0;
    }
}
int stacktop(struct stack*s){
    return( s-> arr[s->top]);
}
int stackbottom(struct stack*s){
    return(s->arr[0]);
}
void push(struct stack*ptr , char value){
    if(full(ptr)){
        printf("stack overflow \n");
    }
    else{
        ptr -> top ++;
        ptr -> arr[ptr->top]= value;
    }
}
char pop(struct stack*ptr){
    if(empty(ptr)){
        printf("stack underflow");
        return '\0';
    }
    else{
        char value = ptr->arr[ptr->top];
        ptr-> top--;
        return value;
    }
}
int peek(struct stack*s, char i){
    if(s->top - i+1 <0){
        printf("invalid position \n");
        return -1;
    }
    else{
        return (s-> arr[s->top - i +1]);
    }
}
int match (char a , char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;
}
int precedence(char ch){
    if(ch== '*' || ch == '/')
    return 3;
    else if(ch== '+' || ch == '-')
    return 2;
    else
    return 1;

}
int operator(char ch){
    
    if(ch== '*' || ch == '/' || ch== '+' || ch == '-')
    return 1;
    else
    return 0;
}
char * infixtopostfix(char*infix){
    struct stack*sp= (struct stack*)malloc(sizeof(struct stack));
    sp->size= 20;
    sp->top= -1;
    sp->arr = (char*)malloc(sp->size* sizeof(char));
    char*postfix = (char*)malloc((strlen(infix)+1) *sizeof(char));
    int i=0 , j=0;
    while(infix[i]!= '\0'){
        if(!operator(infix[i])){
            postfix[j]= infix[i];
            j++; i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stacktop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j]= pop(sp);
                j++;
            }
        }
    }
while (!empty(sp)){
    postfix[j]= pop(sp);
    j++;
    }
    postfix[j]= '\0';
    return postfix;
}
int main(){
    char* infix= "a-4+2*3/6-e+t";
    printf("postfix is %s",  infixtopostfix(infix));
    return 0;
}
