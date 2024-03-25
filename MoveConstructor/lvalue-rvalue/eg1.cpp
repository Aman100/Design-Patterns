/*
Code won't compile as left side of operand should be lvalue
lvalue: means locator value though which object can located. It means
object will be having some memory location.
rvalue: which is not lvalue. These values will be stored in registers (CPU memory)
for calculation purpose.

Line 1: int x=20, y=30;	//20,40 will be stored in registers (rvalue)
Line 2: int z=x*y;	 value of x which is 20 will be stored in register, 
			   value of y which 30 will be stored in register then operation
			   will be performed. It means that lvalue will be converted to
			   rvalue for calculation purpose then final value which is 50
			   will be assigned to lvalue(z) 

rvalue does not have memory location.
*/
int main()
{
int x;
20=x;	// Error: lvalue required as left operand of assignment
}
