#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int data;
    node* left = NULL;
    node* right = NULL;
};


Node *deleteNode(Node *root,  int x)
{

    Node* par = root;
    Node* temp = root;
    while(temp){
        if(temp->data == x){
            break;
        }else if(x < temp->data){
            par = temp;
            temp = temp->left;
        }else{
            par = temp;
            temp = temp->right;
        }
    }

    if(temp == NULL){
        return root;
    }

    if(temp->left == NULL && temp->right == NULL){
        if(temp == root){
            return NULL;
        }
        if(par->left == temp){
            par->left = NULL;
        }else{
            par->right = NULL;
        }
        delete temp;
    }

    if(temp->left == NULL && temp->right != NULL){
        if(temp == root){
            return temp->right;
        }
        if(par->left == temp){
            par->left = temp->right;
        }else{
            par->right = temp->right;
        }
        delete temp;
    }

    if(temp->left != NULL && temp->right == NULL){
        Node* lefte = temp->left;
        Node* par2  = temp->left;
        while(lefte->right){
            par2 = lefte;
            lefte = lefte->right;
        }
        if(par2 != lefte){
            par2->right = lefte->left;
        }

        if(lefte != temp->left){
            lefte->left = temp->left;
        }
        if(temp == root){
            return lefte;
        }
        if(par->left == temp){
            par->left = lefte;
        }else{
            par->right = lefte;
        }
        delete temp;
    }

    if(temp->left != NULL && temp->right != NULL){
        Node* lefte = temp->left;
        Node* par2  = temp->left;
        while(lefte->right){
            par2 = lefte;
            lefte = lefte->right;
        }
        if(par2 != lefte){
            par2->right = lefte->left;
        }

        if(lefte != temp->left){
            lefte->left = temp->left;
        }
        if(temp == root){
            lefte->right = temp->right;
            return lefte;
        }
        if(par->left == temp){
            lefte->right = temp->right;
            par->left = lefte;
        }else{
            lefte->right = temp->right;
            par->right = lefte;
        }
        delete temp;
    }
    return root;
}

int32_t main()
{

    return 0;
}
