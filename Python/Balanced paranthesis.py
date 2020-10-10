# Balanced Paranthesis

# Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
# You need to return true if it is balanced, false otherwise.
# Note: This problem was asked in initial rounds in Facebook
# Sample Input 1 :
# { a + [ b+ (c + d)] + (e + f) }
# Sample Output 1 :
# true
# Sample Input 2 :
# { a + [ b - c } ]
# Sample Output 2 :
# false


def checkBalanced(expr):

    s=[]
    for ele in expr:
        if ele in '({[':
            s.append(ele)
        elif ele =='}':
            if (not s or s[-1]!='{'):
                return
            s.pop()
        elif ele ==")":
            if(not s or s[-1]!='('):
                return
            s.pop()
        elif ele=="]":
            if(not s or s[-1]!='['):
                return
            s.pop()
    if(not s):
        return True
    else:
        return

exp=input()
if checkBalanced(exp):
    print('true')
else:
    print('false')