# Queue Using LL
# Send Feedback
# You need to implement a Queue class using linked list.
# All the required data members should be private.
# Implement the following public functions :
# 1. Constructor -
# Initialises the data members.
# 2. enqueue :
# This function should take one argument of type T and has return type void. This function should insert an element in the queue. Time complexity should be O(1).
# 3. dequeue :
# This function takes no input arguments and has return type T. This should removes the first element which is entered and return that element as an answer. Time complexity should be O(1).
# 4. front :
# This function takes no input arguments and has return type T. This should return the first element which is entered and return that element as an answer. Time complexity should be O(1).
# 5. size :
# Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
# 6. isEmpty :
# Checks if the queue is empty or not. Return true or false.


class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
class QueueUsingLL:
  
    def __init__(self):
        self.__front=None
        self.__count=0
        self.__rear=None
        
    def enqueue(self,data):
        newnode=Node(data)
        if self.__front is None:
            self.__front=newnode
            self.__rear=newnode
        else:
            self.__rear.next=newnode
            self.__rear=self.__rear.next
        self.__count+=1
        
    def dequeue(self):
        if self.__front is None:
            return
        ele=self.__front.data
        self.__front=self.__front.next
        self.__count-=1
        return ele
    def front(self):
        if self.__front is not None: 
            return self.__front.data 
        else:
            return 0
    def isEmpty(self):
            if self.__count==0:
                return True
            else:
                return
    
    def getSize(self):
        return self.__count

    
q = QueueUsingLL()
li = [int(ele) for ele in input().split()]
i=0
while i<len(li):
    choice = li[i]
    if choice == -1:
        break
    elif choice == 1:
        q.enqueue(li[i+1])
        i+=1
    elif choice == 2:
        ans = q.dequeue()
        if ans!=0:
            print(ans)
        else:
            print(-1)
    elif choice == 3:
        ans = q.front()
        if ans!=0:
            print(ans)
        else:
            print(-1)
    elif choice == 4:
        print(q.getSize())
    elif choice == 5:
        if(q.isEmpty()):
            print('true')
        else:
            print('false')
    i+=1