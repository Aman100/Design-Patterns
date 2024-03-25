/*
if variable p is declared with const keyword then only code will compile.
P is not going to reference rvalue type. It won't happen as rvalue don't have
a memory location, instead "A new variable will be introduced by the compiler
which will hold value 50 and p will refer to newly introduced lvalue type variable."
Variable p is not modifiable.
*/
int main()
{
const int &p=50;
}