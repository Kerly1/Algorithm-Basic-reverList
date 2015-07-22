#ifndef _HEAD_H
#define _HEAD_H

#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

struct node
{
    int val;
    node* next;
};

node* arrayToList(vector<int>& array);
node* arrayToListAux(vector<int>& array, vector<int>::iterator index);
void printList(node* list);

#endif