struct Node {
  int move;
  int value;
  struct LinkedList* next;
};


int pop_move(Node* list);
void push_move(Node* list, int thing, int value);
