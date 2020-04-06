#include "Interpreter.h"

Interpreter Interpreter::compile(std::string code)
{
	Interpreter interpreter;
	interpreter.input = code;
	return interpreter;
}

Interpreter Interpreter::run()
{
    Interpreter interpreter;
    for (unsigned int i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
        case '+':
            cells[pointer]++;
            break;
        case '-':
            cells[pointer]--;
            break;
        case '>':
            pointer++;
            break;
        case '<':
            pointer--;
            break;
        case '[':
            stack.push(i);
            break;
        case ']':
            if (cells[pointer] != 0)
            {

                if (stack.empty())
                {
                    std::cout << "Ошибка: различное количество скобок" << std::endl;
                    break;
                }
                i = stack.top();
            }
            else
                stack.pop();
            break;
        case '.':
            interpreter.output.push_back(cells[pointer]);
            break;
        }
    }
	return interpreter;
}

std::string Interpreter::getOutput()
{
    return output;
}

std::string Interpreter::getProgram()
{
    return input;
}
