#include <iostream>

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

typedef struct S_Deque
{
    Node* head;
    Node* tail;
}Deque;

Deque* deque = NULL; //global

// get_data can change based on what is stored in the structure
Data get_data()
{
    Data data;
    cout << "Enter data: " << endl;
    cin >> data.data;
    return data;
}

Deque* get_new_deque()
{
    Deque* deque = new Deque; //(Deque*)malloc(sizeof(Deque))
    deque->head = deque->tail = NULL;
    return deque;
}

Node* get_new_node()
{
    Node* new_node = new Node; // (Node*)malloc(sizeof(Node))
    new_node->data = get_data();
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void push_front()
{
    Node* new_node = get_new_node();
    new_node->next = deque->head;
    if(deque->tail == NULL){
        deque->head = deque->tail = new_node;
    }
    else{
        deque->head->prev = new_node;
        deque->head = new_node;
    }
}

void push_back()
{
    Node* new_node = get_new_node();
    new_node->prev = deque->tail;
    if(deque->head == NULL){
        deque->head = deque->tail = new_node;
    }
    else{
        deque->tail->next = new_node;
        deque->tail = new_node;
    }
}

Data pop_front()
{
    Data data = deque->head->data;
    Node* temp = deque->head;
    if(deque->head == deque->tail){
        deque->head = deque->tail = NULL;
    }
    else{
        deque->head = temp->next;
    }
    delete(temp); // free(temp)
    return data;
}

Data pop_back()
{
    Data data = deque->tail->data;
    Node* temp = deque->tail;
    if(deque->head == deque->tail){
        deque->head = deque->tail = NULL;
    }
    else{
        deque->tail = temp->prev;
    }
    delete(temp); // free(temp)
    return data;
}

Data peek_front()
{
    return deque->head->data;
}

Data peek_back()
{
    return deque->tail->data;
}

int is_empty()
{
    if(deque->head == NULL || deque == NULL){
        return 1;
    }
    else return 0;
}

void free_memory()
{
    while(!is_empty()){
        pop_front();
    }
    if(deque != NULL){
        delete(deque); // free(deque)
        deque = NULL;
    }
    cout << "Deque freed" << endl;
}

int main()
{
    deque = get_new_deque();

    push_front();
    push_front();
    push_front();

    cout << endl;
    cout << pop_back().data << endl;
    cout << pop_front().data << endl;
    cout << pop_back().data << endl;

    free_memory();
    return 0;
}
