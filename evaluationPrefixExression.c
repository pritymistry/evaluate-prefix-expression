#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int stack[25],top=-1;
void push(int num)
{
    stack[++top]=num;
}
int pop()
{
    return stack[top--];
}

int evaluatePrefix(char str[],int n)
{
    int a,b,c;
    for(int i=n-1;i>=0;i--)
    {
            if(isdigit(str[i]))
            {
                push(str[i]-'0');
            }
            else
            {
                a=pop();
                b=pop();
                if(str[i]=='+')
                {
                    c=a+b;
                    push(c);
                }
                else if(str[i]=='-')
                {
                    c=a-b;
                    push(c);
                }
                else if(str[i]=='*')
                {
                    c=a*b;
                    push(c);
                }
                else if(str[i]=='/')
                {
                    c=a/b;
                    push(c);
                }
                else if(str[i]=='^')
                {
                    c=pow(a,b);
                    push(c);
                }
            }

    }
    if(top==0)
    return (pop());
}
int main()
{
    char expn[25];
    int l,result;
    printf("enter a prefix expression :\n");
    scanf("%s",&expn);
    l=strlen(expn);
    result=evaluatePrefix(expn,l);
    printf("answer is :%d",result);
    return 0;
}
