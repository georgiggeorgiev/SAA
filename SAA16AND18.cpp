#include <iostream>

using namespace std;

typedef struct S_Tree
{
    int data;
    struct S_Tree* left;
    struct S_Tree* right;
}Tree;

void insert(int value, Tree** t)
{
    if(*t == NULL){
        *t = new Tree; // (Tree*)malloc(sizeof(Tree))
        (*t)->left = (*t)->right = NULL;
        (*t)->data = value;
    }
    else if(value <= (*t)->data){
        insert(value, &(*t)->left);
    }
    else if(value > (*t)->data){
        insert(value, &(*t)->right);
    }
}

void print_tree(Tree* t)
{
    if(t != NULL){
        //cout << t->data << endl;
        cout << t->data << "\t" << t->left << "\t" << t->right << endl;
        print_tree(t->left);
        print_tree(t->right);
    }
}

void free_memory(Tree* t)
{
    if(t != NULL){
        free_memory(t->right);
        free_memory(t->left);
        delete(t); // free(t)
    }
}

int pos_neg(Tree* t)
{
    int neg = 0;
    if(t != NULL){
        if(t->data > 0){
            cout << "Positive point found: " << t->data << endl;
        }
        neg = pos_neg(t->right);
        if(neg < 0){
            cout << "Negative point found: " << neg << endl;
        }
        neg = pos_neg(t->left);
        if(neg < 0){
            cout << "Negative point found: " << neg << endl;
        }
        return t->data;
    }
    return 0;
}

int evens_sum(Tree* t)
{
    int sum = 0;
    if(t != NULL){
        if(t->data % 2 == 0){
            sum += t->data;
        }
        sum += evens_sum(t->right);
        sum += evens_sum(t->left);
    }
    return sum;
}

int main()
{
    Tree* t = NULL;
    int data[10] = {-5,4,-3,12,-1,0,1,-2,3,-4};
    for(int i=0;i<10;i++){
        insert(data[i],&t);
    }
    cout << "Tree: " << endl;
    print_tree(t);
    cout << endl;

    pos_neg(t);
    cout << "Sum of even points: " << evens_sum(t) << endl;

    free_memory(t);
    return 0;
}
