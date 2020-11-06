class Node:
    def __init__(self, data = 0, next = None):
        self.data = data
        self.next = next

def MergeList_New(Node1: Node, Node2: Node):

    Result_List = Node(0, None) #This node will be used to connect the nodes in the two lists
    Initial_Node = Node(-1, None) #This node will hold the start point

    if(Node1.data <= Node2.data):
        Initial_Node = Node1
    else:
        Initial_Node = Node2
    
    while Node1 != None and Node2 != None:
        if Node1.data <= Node2.data:
            Result_List.next = Node1
            Node1 = Node1.next
            

        else:
            Result_List.next = Node2
            Node2 = Node2.next

        Result_List = Result_List.next

    while Node1 != None:
        Result_List.next = Node1
        Node1 = Node1.next

    while Node2 != None:
        Result_List.next = Node2
        Node2 = Node2.next

    return Initial_Node
    
            
            

"""
#################################################################
Node1 = Node(2, None)
Node2 = Node(5, None)
Node3 = Node(7, None)

Node1.next = Node2
Node2.next = Node3


    
#L1 = LinkedList(Node1)

Node5 = Node(11, None)
Node4 = Node(3, Node5)

#L2 = LinkedList(Node4)

AnswerList = MergeList_New(Node1, Node4)

NodeHolder = AnswerList

while NodeHolder != None:
    print(NodeHolder.data, end = ' ')
    NodeHolder = NodeHolder.next
"""
####################################################################
Node1_5 = Node(10, None)
Node1_4 = Node(8, Node1_5)
Node1_3 = Node(6, Node1_4)
Node1_2 = Node(3, Node1_3)
Node1_1 = Node(2, Node1_2)

Node2_6 = Node(10, None)
Node2_5 = Node(7, Node2_6)
Node2_4 = Node(6, Node2_5)
Node2_3 = Node(5, Node2_4)
Node2_2 = Node(4, Node2_3)
Node2_1 = Node(2, Node2_2)

print('The first LinkedList Looks like:\n')
Node1 = Node1_1
while Node1 != None:
    print(Node1.data, end = ' ')
    Node1 = Node1.next

print('\n')

print('The second Linked List Looks like:\n')
Node2 = Node2_1
while Node2 != None:
    print(Node2.data, end = ' ')
    Node2 = Node2.next

MergedList = MergeList_New(Node1_1, Node2_1)

print('The result of the Merged lists is: \n')

while MergedList != None:
    print(MergedList.data, end = ' ')
    MergedList = MergedList.next
