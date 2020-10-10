# Check redundant brackets
# Send Feedback
# Given a string mathematical expression, return true if redundant brackets are present in the expression. Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
# Assume the given string expression is balanced and contains only one type of bracket i.e. ().
# Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.
# Input Format :
# String s (Expression)
# Output Format :
# true or false
# Sample Input 1:
# ((a + b)) 
# Sample Output 1:
# true
# Sample Input 2:
# (a+b) 
# Sample Output 2:
# false

def checkRedundant(string):
  st=[]
  c=0
  for s in string:
    if s is not ')':
      st.append(s)
    else:
      j=len(st)-1
      while st[j]!='(':
        st.pop()
        c+=1
        j-=1
      st.pop()
      if c==0:
        return True
      c=0
   
  if not st:
    return True
                
        
string = input()
ans = checkRedundant(string)
if ans is True:
    print('true')
else:
    print('false')
