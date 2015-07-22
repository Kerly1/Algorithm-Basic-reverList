#include<iostream>
#include<vector>
#include<string>
#include<list>
#include "head.h"
using namespace std;

//recursive
node* reverseList(node* list){
    if (list == NULL || list->next == NULL){
        return list;
    }
    else{
        node* head = list;
        node* newHead= reverseList(list->next);
        list->next->next = head;
        head->next = NULL;
        return newHead;
    }
}

int main(){
    vector<int> a = { 1, 3, 4, 5, 6, 7, 8 };
    node* result = reverseList(arrayToList(a));
    printList(result);
    return 0;
}


