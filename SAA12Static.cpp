#include <iostream>

#define D_SIZE 10

using namespace std;

typedef struct S_Data
{
    int data; //placeholder data
}Data;

typedef struct S_Deque
{
    Data data[D_SIZE];
    int head;
    int tail;
    int size;
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
    deque->head = -1;
    deque->tail = 0;
    deque->size = D_SIZE;

    return deque;
}

int is_full()
{
    return ((deque->head == 0 && deque->tail == deque->size-1)|| deque->head == deque->tail+1);
}

int is_empty()
{
    return (deque->head == -1);
}

void push_front()
{
    if(is_full()){
        cout << "Deque is full, cannot insert" << endl;
        return;
    }
    if(deque->head == -1){
        deque->head = deque->tail = 0;
    }
    else if(deque->head == 0){
        deque->head = deque->size-1;
    }
    else{
        deque->head--;
    }
    deque->data[deque->head] = get_data();
}

void push_back()
{
    if(is_full()){
        cout << "Deque is full, cannot insert" << endl;
        return;
    }
    if(deque->head == -1){
        deque->head = deque->tail = 0;
    }
    else if(deque->tail == deque->size-1){
        deque->tail = 0;
    }
    else{
        deque->tail++;
    }
    deque->data[deque->tail] = get_data();
}

void pop_front()
{
    if(is_empty()){
        cout << "Deque is empty, cannot delete" << endl;
        return;
    }
    if(deque->head == deque->tail){
        deque->head = deque->tail = -1;
    }
    else{
        if(deque->head == deque->size-1){
            deque->head = 0;
        }
        else{
            deque->head++;
        }
    }
}

void pop_back()
{
    if(is_empty()){
        cout << "Deque is empty, cannot delete" << endl;
        return;
    }
    if(deque->head == deque->tail){
        deque->head = deque->tail = -1;
    }
    else if(deque->tail == 0){
        deque->tail = deque->size-1;
    }
    else{
        deque->tail--;
    }
}

Data peek_front()
{
    return deque->data[deque->head];
}

Data peek_back()
{
    return deque->data[deque->tail];
}

int main()
{
    deque = get_new_deque();

    push_front();
    push_front();

    cout << endl;
    cout << peek_front().data << endl;
    cout << peek_back().data << endl;
    pop_back();
    pop_front();

    delete(deque); // free(deque)
    return 0;
}
