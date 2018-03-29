class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)




if __name__ == '__main__':
    s = Stack()

    s.push(1)
    print(s.peek())

    s.push('ozge')
    print(s.peek())

    s.push(1.0)
    print(s.peek())

    print("Stack Size",s.size())

    print(s.pop())
    print(s.peek())
    print("Stack Size", s.size())