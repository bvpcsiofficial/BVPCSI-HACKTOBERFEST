# Program to implement dequeue using python
class Queue(object):
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        return self.items.append(item)

    def addRear(self, item):
        self.items.insert(0, item)

    def removeFront(self):
        return self.items.pop()

    def removeRear(self):
        return self.items.pop(0)

    def size(self):
        return len(self.items)


q = Queue()
print(q.size())
print(q.isEmpty())
q.addFront(1)
q.addRear(True)
q.addFront('FSS')
print(q.size())
print(q.removeFront(),'', q.removeRear())
print(q.size())
