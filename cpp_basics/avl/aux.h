using namespace std;

/* Extremely basic node
 * data structure */
struct node{
  int val;
  struct node* left;
  struct node* right;
  int height;
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
  new_node->height = 1;
  return new_node;
}


/* helper function to return node's height
 * if the node->left/node->right is null,
 * return a height of zero to avoid seg fault*/
int get_height(struct node* node){
  if (node != NULL){
    return node->height;
  }
  return 0;
}

/* Simple right rotation */
struct node* rr(struct node* nodeA){
  struct node* nodeB = nodeA->left;
  struct node* nodeC = nodeB->right;

  nodeB->right = nodeA;
  nodeA->left = nodeC;

  nodeA->height = max(get_height(nodeA->left), get_height(nodeA->right))+1;
  nodeB->height = max(get_height(nodeB->left), get_height(nodeB->right))+1;
  return nodeB;
}

/* Simple left rotation */
struct node* rl(struct node* nodeA){
  struct node* nodeB = nodeA->right;
  struct node* nodeC = nodeB->left;

  nodeB->left = nodeA;
  nodeA->right = nodeC;

  nodeA->height = max(get_height(nodeA->left), get_height(nodeA->right))+1;
  nodeB->height = max(get_height(nodeB->left), get_height(nodeB->right))+1;
  return nodeB;
}

int height_diff(struct node* node){
  if (node != NULL){
    return (get_height(node->left) - get_height(node->right));
  }
  return 0;
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
  // return current node if equal (avl cant have equal)
  else if (val == curr->val){
    return curr;
  }
  curr->height = 1+max(get_height(curr->left), get_height(curr->right));

  int diff = height_diff(curr);

  // if the tree is skewed to the left and the value
  // will skew the tree further left, rotate right
  if (diff > 1 && val < curr->left->val){
    return rr(curr);
  }

  // if the tree is skewed to the right and the value
  // will skew the tree further right, rotate left
  if (diff < -1 && val > curr->right->val){
    return rl(curr);
  }
  // if the tree is skewed to the left and the value
  // is to be put on the right, then the left curr
  // will be rotated left and then the curr will be 
  // rotated right
  if (diff > 1 && val < curr->left->val){
    curr->left = rl(curr->left);
    return rr(curr);
  }

  if (diff < -1 && val > curr->right->val){
    curr->right = rr(curr->right);
    return rl(curr);
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
