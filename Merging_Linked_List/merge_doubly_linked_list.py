class Node:
    def __init__(self, data = 0, next = None, previous = None):
        self.data = data
        self.previous = previous
        self.next = next


def MergeList(List1: Node, List2: Node):
    InitialNode = Node(-1)
    if List1.data <= List2.data:
        InitialNode = List1
    else:
        InitialNode = List2

    ResultList = Node(0, None, None)

    while List1 != None and List2 != None:
        #print('Value on current node is: ', ResultList.data, '\n')
        print('Value on L1 is: ', List1.data, '\n')
        print('Value on L2 is: ', List2.data, '\n')

        if List1.data <= List2.data:
            ResultList.next = List1
            List1.previous = ResultList
            List1 = List1.next
            
        else:
            ResultList.next = List2
            List2.previous = ResultList
            List2 = List2.next


            
        ResultList = ResultList.next
        print('Merged Another node in')
        
        
    while List1 != None:
        #List1 = List1.next
        ResultList.next = List1
        List1.previous = ResultList
        List1 = List1.next
        ResultList = ResultList.next
        
    while List2 != None:
        ResultList.next = List2
        List2.previous = ResultList
        List2 = List2.next
        ResultList = ResultList.next
        
    EndNodes = list()
    EndNodes.append(InitialNode)
    EndNodes.append(ResultList)
    return EndNodes


Node1_3 = Node(7)
Node1_2 = Node(5, Node1_3)
Node1_1 = Node(2, Node1_2)

Node1_3.previous = Node1_2
Node1_2.previous = Node1_1

Node2_2 = Node(11)
Node2_1 = Node(3, Node2_2)

Node2_2.previous = Node2_1
"""
print('Here is the first linked list forwards: \n')
Node1 = Node1_1
while Node1 != None:
    print(Node1.data, end=' ')
    Node1 = Node1.next

print('And here is the same list, but backwards: \n')
Node1 = Node1_3
while Node1 != None:
    print(Node1.data, end = ' ')
    Node1 = Node1.previous

print('Here is the second linked list forwards: \n')
Node1 = Node2_1
while Node1 != None:
    print(Node1.data, end=' ')
    Node1 = Node1.next

print('And here is the same list, but backwards: \n')
Node1 = Node2_2
while Node1 != None:
    print(Node1.data, end = ' ')
    Node1 = Node1.previous

"""

EndNodes_MergedList = MergeList(Node1_1, Node2_1)
Node1 = EndNodes_MergedList[0]

print('Here is the result of the Merge, forwards:\n')
while Node1 != None:
    print(Node1.data, end = ' ')
    Node1 = Node1.next

Node1 = EndNodes_MergedList[1]

print('And here is the same, but backwards:\n')
while Node1 != None:
    print(Node1.data, end = ' ')
    Node1 = Node1.previous

