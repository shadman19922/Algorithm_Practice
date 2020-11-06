#include <iostream>
#include <memory>

using namespace std;

struct Node{
  int Data;
  shared_ptr<Node> Next;

  Node(int DataField, shared_ptr<Node>NextNode = NULL){
    Data = DataField;
    Next = NextNode;
  }
};


void ReverseList(shared_ptr<Node> head, shared_ptr<Node> tail){
  shared_ptr<Node> L1, L2, L3;
  L3 = head->Next->Next;
  L2 = head->Next;
  L1 = head;

  L1->Next = NULL;
  while(L2->Next != tail){
    L2->Next = L1;
    L1 = L2;
    L2 = L3;
    L3 = L3->Next;
  }

  L2->Next = L1;

}

shared_ptr<Node> ReverseSubList(shared_ptr<Node> head, int s, int f){
  shared_ptr<Node> left, right;//Hold the left and right most nodes of the sublist to be reversed
  shared_ptr<Node> left_fixed, right_fixed;
  
  int counter = 0;
  for(shared_ptr<Node> tempNode = head; left != NULL && right != NULL && left_fixed != NULL && right_fixed != NULL;){
    if(counter == s) left = tempNode;
    else if(counter == f) right = tempNode;
    else if(counter == s - 1) left_fixed = tempNode;
    else if(counter == f + 1) right_fixed = tempNode;
    tempNode = tempNode->Next;
  }

  ReverseList(left, right_fixed);

  left_fixed->Next = right;
  left->Next = right_fixed;

  return head;
}


int main(){
  shared_ptr<Node> Node4 = make_shared<Node>(2);
  shared_ptr<Node> Node3 = make_shared<Node>(7, Node4);
  shared_ptr<Node> Node2 = make_shared<Node>(5, Node3);
  shared_ptr<Node> Node1 = make_shared<Node>(3, Node2);
  shared_ptr<Node> Node0 = make_shared<Node>(11, Node1);

  cout << "Let's see what the linked list looks like: ";
  for(shared_ptr<Node> currentnode = Node0; currentnode != NULL;){
    cout << currentnode->Data << " ";
    currentnode = currentnode->Next;
  }
  cout << "\n";

  ReverseSubList(Node0, 1, 3);

  cout << "Does the list reverse? ";
  for(shared_ptr<Node> currentnode = Node4; currentnode != NULL;){
    cout << currentnode->Data << " ";
    currentnode = currentnode->Next;
  }
  cout << "\n";
  
  
  
  return 0;
}


