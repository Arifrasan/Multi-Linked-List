#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   Node* next;
};
void insertNewNode(Node** root, int item) {
   Node *ptr, *temp;
   temp = new Node;
   temp->data = item;
   temp->next = NULL;
   if (*root == NULL) {
      *root = temp;
   }
   else {
      ptr = *root;
      while (ptr->next != NULL) {
         ptr = ptr->next;
      }
      ptr->next = temp;
   }
}
void printLinkedList(Node* root) {
   while (root != NULL) {
      cout << root->data << " -> ";
      root = root->next;
   }
   cout << "NULL" << endl;
}
Node* generateNewLinkedList(Node* root1, Node* root2) {
   Node *ptr1 = root1, *ptr2 = root2;
   Node* root = NULL;
   while (ptr1 != NULL) {
      int currentMax = ((ptr1->data < ptr2->data) ? ptr2->data : ptr1->data);
      if (root == NULL) {
         Node* temp = new Node;
         temp->data = currentMax;
         temp->next = NULL;
         root = temp;
      }
      else {
         insertNewNode(&root, currentMax);
      }
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }
   return root;
}
int main() {
   Node *root1 = NULL, *root2 = NULL, *root = NULL;
   insertNewNode(&root1, 1);
   insertNewNode(&root1, 2);
   insertNewNode(&root1, 3);
   insertNewNode(&root1, 4);
   insertNewNode(&root2, 1);
   insertNewNode(&root2, 3);
   insertNewNode(&root2, 4);
   insertNewNode(&root2, 2);
   root = generateNewLinkedList(root1, root2);
   printLinkedList(root);
   return 0;
}
