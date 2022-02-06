using namespace std;


struct node{
  int val1;
  int val2;
  struct node* next;
  struct node* prev;
};

struct Linked_List{
  struct node* head;
  struct node* tail;
};

void put_node(struct Linked_List* LL, struct node* new_node){
  if (LL->head->next == NULL && LL->tail->prev == NULL){
    LL->head->next = new_node;
    LL->tail->prev = new_node;
    new_node->next = LL->tail;
    new_node->prev = LL->head;
  }
  else{
    struct node *iterator;
    iterator = LL->head;


    while (iterator != NULL){
      if (iterator == LL->tail){
        cout << "yay" << endl;
        new_node->next = LL->tail;
        new_node->prev = LL->tail->prev;
        LL->tail->prev->next = new_node;
        LL->tail->prev = new_node;
      }

      else if(iterator->next->val1 >= new_node->val1){
        if (iterator == LL->head){
          new_node->prev = LL->head;
          new_node->next = LL->head->next;
          LL->head->next->prev = new_node;
          LL->head->next = new_node;
        }
        else{
          new_node->next = iterator->next;
          new_node->prev = iterator;
          iterator->next->prev = new_node;
          iterator->next = new_node;
        }
        break;
      }
      iterator = iterator->next;
    }
  }
}


void init_LL( struct Linked_List* LL){
  LL->head = (struct node*) malloc(sizeof(struct node));
  LL->tail = (struct node*) malloc(sizeof(struct node));
  LL->head->next = NULL;
  LL->head->prev = NULL;
  LL->tail->next = NULL;
  LL->tail->prev = NULL;
}

struct node* make_node(int val1, int val2){
  struct node *new_node;
  new_node = (struct node*) malloc(sizeof(struct node));
  new_node->val1 = val1;
  new_node->val2 = val2;
  new_node->prev = (struct node*) malloc(sizeof(struct node));
  new_node->next = (struct node*) malloc(sizeof(struct node));
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;

}

void print_forward(struct node* curr){
  struct node *node_i;
  node_i = curr->next;
  while (node_i->next != NULL){
    cout << node_i->val1 << ",";
    node_i = node_i->next;
  }
  cout << "\n";
}

void print_backward(struct node* curr){
  struct node *node_i;
  node_i = curr->prev;
  while (node_i->prev != NULL){
    cout << node_i->val1 << ",";
    node_i = node_i->prev;
  }
  cout << "\n";
}

void add_node(struct Linked_List* LL, int val1, int val2){
  struct node* new_node = make_node(val1, val2);
  put_node(LL, new_node);
  print_forward(LL->head);
  print_backward(LL->tail);
}

