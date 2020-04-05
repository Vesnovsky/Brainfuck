#include <map>
#include <stack>
#include <string>
#include <iostream>
#include "Interpreter.h"

int main()
{
    
    std::string input;
    std::cin >> input;
    std::cout << Interpreter::compile(input).run().getOutput() << std::endl;;
   
    return 0;
}