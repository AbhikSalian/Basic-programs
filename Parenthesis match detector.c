// C Program to detect mismatched parenthesis
//({[}])
#include <stdio.h>
void push(char a);
char pop();
char stck[10];
int top=-1;
int main() {
    char s[20];
    char p;
    int count=0;
    printf("Enter the expression :");
    scanf("%s",s);
    //([{]})
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            push(s[i]);
            printf("\nElement %d in stack : %c",top,stck[top]);
            count++;
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(s[i]==')' && stck[top]=='(')
            {
                p=pop();
                printf("\nPopped element: %c",p);
                count--;
            }
            else if(s[i]=='}' && stck[top]=='{')
            {
                p=pop();
                printf("\nPopped element: %c",p);
                count--;
            }
            else if(s[i]==']' && stck[top]=='[')
            {
                p=pop();
                printf("\nPopped element: %c",p);
                count--;
            }
            else
            {
                printf("\nMismatched parenthesis at position %d!",i+1);
            }
           if(count==0)
            {
                printf("\nParenthesis match!");
            }
        }
    }
    return 0;
}
void push(char a)
{
        top++;
        stck[top]=a;
}
char pop()
{
    if(top==-1)
    {
        //printf("\nParenthesis match!");
        exit(0);
    }
    else
    {
        return stck[top--];
    }
    return stck[top--];
}
