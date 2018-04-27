#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}


Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

int findLargestSmallerKey(Node *rootNode, int num) 
{ 
    
  if(rootNode->left==nullptr && rootNode->right==nullptr && rootNode->key>num)
    return -1;
  if((rootNode->key<num && rootNode->right==nullptr) || (rootNode->key<num and rootNode->right->key>=num))
        return rootNode->key;
  if(rootNode->key>=num)
        return findLargestSmallerKey(rootNode->left, num);
   else 
     return findLargestSmallerKey(rootNode->right, num);
  
  
    
}

int main() {
 Node* n =  newNode (20);
  int a[6]={9,5, 12, 11, 14, 25};
  for(int i=0;i<6;i++)
  {
    insert(n, a[i]);
  }
  cout << findLargestSmallerKey(n, 21) << endl;
  cout << findLargestSmallerKey(n, 17) << endl;
  cout << findLargestSmallerKey(n, 25) << endl;
  cout << findLargestSmallerKey(n, 26) << endl;
  cout << findLargestSmallerKey(n, 4) << endl;
  
  return 0;
}
/**
preorder traversal
level order traversal
**/