"""
We can use Dijkstra's two stack algorithm to solve an equation
such as: (5 + ((4 * 2) * (2 + 3)))
"""


import operator as op


class Stack:

    def __init__(self, limit=10):
        self.stack = []
        self.limit = limit

    def __bool__(self):
        return bool(self.stack)

    def __str__(self):
        return str(self.stack)

    def push(self, data):
        if len(self.stack) >= self.limit:
            raise IndexError('stack is fully filled')
        self.stack.append(data)

    def pop(self):
        if self.stack:
            return self.stack.pop()
        else:
            raise IndexError("pop from an empty stack")

    def peek(self):
        if self.stack:
            return self.stack[-1]

    def is_empty(self):
        return not bool(self.stack)

    def size(self):
        return len(self.stack)

    def __contains__(self, item) -> bool:
        return item in self.stack


def dijkstras_two_stack_algorithm(equation: str) -> int:
    operators = {"*": op.mul, "/": op.truediv, "+": op.add, "-": op.sub}

    operand_stack = Stack()
    operator_stack = Stack()

    for i in equation:
        if i.isdigit():
            # RULE 1
            operand_stack.push(int(i))
        elif i in operators:
            # RULE 2
            operator_stack.push(i)
        elif i == ")":
            # RULE 4
            opr = operator_stack.peek()
            operator_stack.pop()
            num1 = operand_stack.peek()
            operand_stack.pop()
            num2 = operand_stack.peek()
            operand_stack.pop()

            total = operators[opr](num2, num1)
            operand_stack.push(total)

    # RULE 5
    return operand_stack.peek()


if __name__ == "__main__":
    equation = "(5 + ((4 * 2) * (2 + 3)))"
    # answer = 45
    print(f"{equation} = {dijkstras_two_stack_algorithm(equation)}")
