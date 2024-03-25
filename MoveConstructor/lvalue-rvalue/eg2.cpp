/*
&(ampersand) operator can only be applied to locator value operand 
because lvalue type object can be referenced, rvalue doesn't have memory location 
that's why this code is not getting compiled.
*/
int main()
{
int x=20;
int *p, *q;
p=&x;
q=&120;	// lvalue required as unary '&' operand
}