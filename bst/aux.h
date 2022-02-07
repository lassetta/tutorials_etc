using namespace std;

/* Extremely basic node
 * data structure */
struct node{
  int val;
  struct node* left;
  struct node* right;
};

/* initialize a node
 * the left node gets null
 * the right node gets null
 * the values gets whatever value is input
 * return pointer
 * */
struct node* init_node(int val){
  struct node* new_node;
  new_node = (struct node*) malloc(sizeof(struct node*));
  new_node->left = (struct node*) malloc(sizeof(struct node*));
  new_node->right = (struct node*) malloc(sizeof(struct node*));
  new_node->val = val;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}
/* insert a new node into the BST
 * the new node will have the input values
 * and the root will be the root of the graph
 * */
struct node* insert(struct node* curr, int val){
  // get new node

  // if NULL, input the node
  if (curr == NULL){
    struct node* new_node;
    new_node = init_node(val);
    return new_node;
  }
  // if less than val, go left
  if (val < curr->val){
    curr->left = insert(curr->left, val);
  }
  // if greater than val, go right
  else if (val > curr->val){
    curr->right = insert(curr->right, val);
  }
  return curr;
}
/* basic traversal of the tree */
// recursively go left, then print, the recursively go right
void traverse(struct node* curr){
  if (curr->left != NULL){
    traverse(curr->left);
  }
  cout << curr->val << " ";
  if (curr->right != NULL){
    traverse(curr->right);
  }
}
