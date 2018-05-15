#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct S_Data
{
    int data; //placeholder data
}Data;

typedef struct S_Node
{
    Data data;
    struct S_Node* next;
    struct S_Node* prev;
}Node;

Node* head; //global head

// get_data and print_data can change based on what is stored in the structure
Data get_data()
{
    Data data;
    cout << "Enter data: " << endl;
    cin >> data.data;
    return data;
}

void print_data(Node* node)
{
    if(node == NULL){
        cout << "No data" << endl;
        return;
    }
    cout << node->data.data << "\t";
}

void free_memory();
Node* get_new_node()
{
    Node* new_node = new Node; // (Node*)malloc(sizeof(Node))
    if(new_node == NULL){
        cout << "MEMORY ERROR" << endl;
        free_memory();
        exit(EXIT_FAILURE);
    }
    new_node->data = get_data();
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void insert_at_head()
{
    Node* new_node = get_new_node();
    if(head == NULL){
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void insert_at_tail()
{
    Node* temp = head;
    Node* new_node = get_new_node();
    if(head == NULL){
        head = new_node;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void print_list()
{
    Node* temp = head;
    cout << "List: " << endl;
    while(temp != NULL){
        print_data(temp);
        temp = temp->next;
    }
    cout << endl;
}

Node* get_node_by_index(unsigned int index)
{
    if(!index){
        return head;
    }
    unsigned int counter = 0;
    Node* temp = head;

    while(1){
        temp = temp->next;
        counter++;
        if(temp == NULL){
            cout << "Index out of bounds" << endl;
            return NULL;
        }
        if(counter == index){
            return temp;
        }
    }
}

void insert_at_index(unsigned int index)
{
    Node* prev_node = get_node_by_index(index);
    Node* new_node = NULL;
    if (prev_node == NULL)
    {
        cout << "Previous node is NULL, cannot insert" << endl;
        return;
    }
    new_node = get_new_node();
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

void reverse_list()
{
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL )
        head = temp->prev;
    cout << "List reversed" << endl;
}

int is_empty()
{
    if(head == NULL){
        return 1;
    }
    return 0;
}

int size()
{
    if(head == NULL){
        return 0;
    }
    int size = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}

void delete_node(unsigned int index)
{
  Node* temp = get_node_by_index(index);
  if(head == NULL || temp == NULL){
    cout << "Cannot delete at this index" << endl;
    return;
  }

  if(head == temp){
    head = temp->next;
  }

  if(temp->next != NULL){
    temp->next->prev = temp->prev;
  }

  if(temp->prev != NULL){
    temp->prev->next = temp->next;
  }

  cout << "Deleted node at index " << index << endl;
  delete(temp); // free(temp)
  return;
}

void free_memory()
{
    if(head == NULL){
        cout << "List is empty, cannot free" << endl;
        return;
    }
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        delete(current); // free(current)
        current = next;
    }
    head = NULL;
    cout << "List freed" << endl;
}

int main()
{
    /*** TESTING ***/
    //print is empty (1)
    cout << is_empty() << endl;
    //initialize list
    head = get_new_node();
    //insert data
    insert_at_head();
    insert_at_tail();
    insert_at_tail();
    //print data in node 1
    print_data(get_node_by_index(1));
    cout << endl;
    //print data in node 4 (out of bounds)
    print_data(get_node_by_index(4));
    cout << endl;
    //print is empty (0)
    cout << is_empty() << endl;
    //print size
    cout << "List size: " << size() << endl;
    //print list
    print_list();
    //reverse list
    reverse_list();
    //delete node 1
    delete_node(1);
    //insert after node 0
    insert_at_index(0);
    //insert after node 10 (out of bounds)
    insert_at_index(10);
    //print list
    print_list();

    //free list
    free_memory();
    return 0;
}
