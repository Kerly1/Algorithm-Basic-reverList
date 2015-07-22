#include<iostream>
#include<string>
#include<vector>
#include "head.h"
using namespace std;



node* arrayToList(vector<int>& array){
    if (!array.empty()){
        return NULL;
    }
    return arrayToListAux(array, array.begin());
}

node* arrayToListAux(vector<int>& array, vector<int>::iterator index){
    if (index < array.end()){
        node* listNode = new node;
        listNode->val = *index;
        listNode->next = arrayToListAux(array, index + 1);
        return listNode;
    }
    else{
        return NULL;
    }
}

void printList(node* list){
    while (list != NULL){
        cout << list->val << "";
        list = list->next;
    }
}

