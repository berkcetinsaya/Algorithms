//
//  Libs.hpp
//  Basic Functionalities
//
//  Created by Fatih Baloglu on 02/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#ifndef Libs_hpp
#define Libs_hpp

#include <string> // For string manipulation
#include <iostream> // General cout cin usage etc.
#include <fstream> // For file manipulation
#include <sstream> // String int conversion
#include <stdio.h>
#include <time.h> // Srand usage
#include <stdlib.h>
#include <cctype>

using namespace std;

#define LIST
#define SORT
#define STRING_SORT
#define STACK
#define QUEUE
#define HASH
#define FILE

#ifdef LIST
template <class List>
class LinkedList
{
private:
    List data;
    int length;
    LinkedList<List>* head;
    LinkedList<List>* tail;
    LinkedList<List>* next;
    LinkedList<List>* prev;
#ifdef SORT
    LinkedList* partition(LinkedList *, LinkedList *);
    void _quickSort(LinkedList* , LinkedList *);
    
    LinkedList* merge(LinkedList* , LinkedList*);
    LinkedList* mergesort(LinkedList*);
    LinkedList* split(LinkedList*);
#endif /* SORT */
public:
    LinkedList();
    ~LinkedList();
    void adddata(List);
    void insertafter(List, List);
    void addfromhead(List);
    void printdata();
    void removedata(List);
    void deletefromhead(string);
    void deletefromtail(string);
    void showlast(string);
#ifdef FILE
    void ReadFileasINT(string);
    void ReadFile(string);
    void WriteFile(string);
    void randomGenerator(string, int, int);
#endif /* FILE */
    inline int getlength() { return length; }
    inline void swap(LinkedList *first, LinkedList *second) { second->data = (first->data + second->data) - (first->data = second->data); }
#ifdef SORT
    void quickSort();
    void mergeSort();
#endif /* SORT */
    
#ifdef STRING_SORT
    void ascendingsort();
    void ascsort();
    inline bool isbefore(List, List);
    inline void stringswap(LinkedList *first, LinkedList *second) { List temp; temp = first->data; first->data = second->data; second->data = temp; }
#endif /* STRING_SORT */
};
#endif /* LIST */

#ifdef STACK
template<class stack>
class Stack
{
private:
    stack data;
    Stack<stack> *next;
    Stack<stack> *head;
public:
    Stack();
    ~Stack();
    void push(stack);
    void pop();
    stack top();
    void printstack();
    bool empty();
};

class CheckBalance : public Stack<char>
{
public:
    CheckBalance() {}
    ~CheckBalance() {}
    bool ArePair(char opening, char closing)
    {
        if(opening == '(' && closing == ')') return true;
        else if(opening == '{' && closing == '}') return true;
        else if(opening == '[' && closing == ']') return true;
        return false;
    }
    
    bool Balanced(string exp)
    {
        Stack<char>  S;
        for(int i =0;i<exp.length();i++)
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                S.push(exp[i]);
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if(S.empty() || !ArePair(S.top(),exp[i]))
                    return false;
                else
                    S.pop();
            }
        }
        return S.empty() ? true:false;
    }
};
#endif /* STACK */

#ifdef QUEUE
template<class queue>
class Queue
{
private:
    queue data;
    Queue<queue> *head;
    Queue<queue> *next;
public:
    Queue();
    ~Queue();
    void enqueue(queue);
    void dequeue();
    void printqueue();
};
#endif /* QUEUE */

#ifdef HASH
template<class hashkey, class hashdata>
class Hash
{
private:
    hashkey key;
    hashdata data;
public:
    Hash(hashkey first, hashdata second) : key (first), data(second) { }
    inline hashkey getKey() { return key; }
    inline hashdata getData() { return data; }
};

template<class hashkey, class hashdata>
class HashMap
{
private:
    int TABLE_SIZE;
    Hash<hashkey, hashdata> **table;
public:
#ifdef FILE
    void ReadFile(string);
#endif /* FILE */
    HashMap(int);
    ~HashMap();
    hashdata get(hashkey);
    void put(hashkey, hashdata);
};
#endif /* HASH */


#endif /* Libs_hpp */
