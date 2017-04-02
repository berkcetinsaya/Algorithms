//
//  Libs.cpp
//  Basic Functionalities
//
//  Created by Fatih Baloglu on 02/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include "Libs.hpp"

using namespace std;

#ifdef LIST
template<class List>
LinkedList<List>::LinkedList() : head(NULL), tail(NULL), next(NULL), prev(NULL), length(0) {}

template<class List>
LinkedList<List>::~LinkedList()
{
    LinkedList<List> *temp = head, *temp2;
    while(temp != NULL)
    {
        temp2 = temp;
        delete temp2;
        temp = temp->next;
    }
}

template<class List>
void LinkedList<List>::adddata(List value)
{
    LinkedList *temp = new LinkedList;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    length++;
}

template<class List>
void LinkedList<List>::addfromhead(List value)
{
    LinkedList *temp = new LinkedList;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    length++;
}

template<class List>
void LinkedList<List>::insertafter(List after, List value)
{
    LinkedList *temp = new LinkedList;
    LinkedList *temp2 = head, *temp3;
    temp->data = value;
    while(temp2 != NULL)
    {
        if(temp2->data == after)
        {
            temp3 = temp2->next;
            temp2->next = temp;
            temp->prev = temp2;
            temp->next = temp3;
            temp3->prev = temp;
        }
        temp2 = temp2->next;
    }
    length++;
}

template<class List>
void LinkedList<List>::deletefromhead(string type)
{
    if(head == NULL) cout << type << " is empty!!";
    else
    {
        LinkedList *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class List>
void LinkedList<List>::deletefromtail(string type)
{
    if(head == NULL) cout << type << " is empty!!";
    else
    {
        LinkedList *temp = tail;
        tail = tail->prev;
        delete temp;
    }
}

template<class List>
void LinkedList<List>::showlast(string type)
{
    if(head == NULL) cout << type << " is empty!!";
    else
    {
        cout << "Top is :" << head->data << endl;
    }
}

template<class List>
void LinkedList<List>::removedata(List value)
{
    LinkedList *temp = head, *temp2;
    bool flag = false;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            flag = true;
            temp2 = temp;
            temp = temp->prev;
            temp->next = temp2->next;
            temp = temp2->next;
            temp->prev = temp2->prev;
            delete temp2;
        }
        temp = temp->next;
    }
    if(!flag) cout << "There is not such a value of : " << value << endl;
    else length--;
}

template<class List>
void LinkedList<List>::printdata()
{
    LinkedList *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

#ifdef SORT
template<class List>
LinkedList<List>* LinkedList<List>::partition(LinkedList *a, LinkedList *b)
{
    int x  = b->data;
    LinkedList *c = a->prev;
    for (LinkedList *d = a; d != b; d = d->next)
    {
        if (d->data <= x)
        {
            c = (c == NULL)? a : c->next;
            swap(c, d);
        }
    }
    c = (c == NULL)? a : c->next;
    swap(c, b);
    return c;
}

template<class List>
void LinkedList<List>::_quickSort(LinkedList* a, LinkedList *b)
{
    if (b != NULL && a != b && a != b->next)
    {
        LinkedList *c = partition(a, b);
        _quickSort(a, c->prev);
        _quickSort(c->next, b);
    }
}

template<class List>
void LinkedList<List>::quickSort()
{
    _quickSort(head, tail);
}

template<class List>
LinkedList<List>* LinkedList<List>::merge(LinkedList *first, LinkedList *second)
{
    if (!first)
        return second;
    
    if (!second)
        return first;
    
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

template<class List>
LinkedList<List>* LinkedList<List>::mergesort(LinkedList *temp)
{
    if (!temp || !temp->next)
        return temp;
    LinkedList *second = split(temp);
    temp = mergesort(temp);
    second = mergesort(second);
    
    return merge(temp,second);
}

template<class List>
LinkedList<List>* LinkedList<List>::split(LinkedList *temp)
{
    LinkedList *fast = temp, *slow = temp;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    LinkedList *temp2 = slow->next;
    slow->next = NULL;
    return temp2;
}

template<class List>
void LinkedList<List>::mergeSort()
{
    mergesort(head);
}
#endif /* SORT */

#ifdef STRING_SORT
template<class List>
void LinkedList<List>::ascendingsort()
{
    if(head == NULL) cout << "List is empty!!" << endl;
    else ascsort();
}

template<class List>
void LinkedList<List>::ascsort()
{
    LinkedList *temp = head;
    while(temp->next != NULL)
    {
        LinkedList *temp2 = temp->next;
        while(temp2 != NULL)
        {
            if (isbefore(temp->data, temp2->data))
                stringswap(temp, temp2);
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

template<class List>
inline bool LinkedList<List>::isbefore(List first, List second)
{
    if(strcmp(first.c_str(), second.c_str()) > 0) return true;
    else return false;
}
#endif /* STRING_SORT */

#ifdef FILE
template<class List>
void LinkedList<List>::ReadFileasINT(string filename)
{
    string line;
    int x;
    ifstream myfile (filename.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::istringstream ss(line);
            ss >> x;
            adddata(x);
        }
        myfile.close();
    }
    else
    {
        cout << "Can not Open the File Named : " << filename << endl;
    }
}

template<class List>
void LinkedList<List>::ReadFile(string filename)
{
    string line;
    ifstream myfile (filename.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            adddata(line);
        }
        myfile.close();
    }
    else
    {
        cout << "Can not Open the File Named : " << filename << endl;
    }
}

template<class List>
void LinkedList<List>::WriteFile(string filename)
{
    LinkedList *temp = head;
    int leng = 0;
    ofstream file(filename.c_str());
    if(file.is_open())
    {
        while(temp != NULL)
        {
            leng++;
            file << temp->data << endl;
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    cout << "Leng :" << leng << endl;
    file.flush();
    file.close();
}

template<class List>
void LinkedList<List>::randomGenerator(string filename, int count, int until)
{
    srand(time(NULL));
    int num;
    ofstream myfile(filename.c_str());
    for (int i = 0; i < count; ++i)
    {
        num = rand()%until;
        myfile << num << endl;
    }
    myfile.close();
}
#endif /* FILE */
#endif /* LIST */

#ifdef STACK
template<class stack>
Stack<stack>::Stack() : head(NULL), next(NULL) {}

template<class stack>
Stack<stack>::~Stack() {}

template<class stack>
void Stack<stack>::push(stack value)
{
    Stack *temp = new Stack;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

template<class stack>
void Stack<stack>::pop()
{
    if(head == NULL) cout << "Stack is empty!!";
    else
    {
        Stack *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class stack>
stack Stack<stack>::top()
{
    if(head == NULL) return NULL;
    else return head->data;
}

template<class stack>
void Stack<stack>::printstack()
{
    if(head == NULL) cout << "Stack is empty!!";
    else
    {
        Stack *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}

template<class stack>
bool Stack<stack>::empty()
{
    if(head == NULL) return true;
    else return false;
}
#endif /* STACK */

#ifdef QUEUE
template<class queue>
Queue<queue>::Queue() : head(NULL), next(NULL) {}

template<class queue>
Queue<queue>::~Queue() {}

template<class queue>
void Queue<queue>::enqueue(queue value)
{
    Queue *temp = new Queue;
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Queue *temp2 = head;
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

template<class queue>
void Queue<queue>::dequeue()
{
    if(head == NULL) cout << "Queue is empty!!";
    else
    {
        Queue *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class queue>
void Queue<queue>::printqueue()
{
    if(head == NULL) cout << "Queue is empty!!";
    else
    {
        Queue *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
#endif /* QUEUE */

#ifdef HASH
template<class hashkey, class hashdata>
HashMap<hashkey, hashdata>::HashMap(int size)
{
    TABLE_SIZE = size;
    table = new Hash<hashkey, hashdata>*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

template<class hashkey, class hashdata>
hashdata HashMap<hashkey, hashdata>::get(hashkey key)
{
    hashkey hashvar = (key % TABLE_SIZE);
    while (table[hashvar] != NULL && table[hashvar]->getKey() != key)
        hashvar = (hashvar + 1) % TABLE_SIZE;
    if (table[hashvar] == NULL)
        return "";
    else
        return table[hashvar]->getData();
}

template<class hashkey, class hashdata>
void HashMap<hashkey, hashdata>::put(hashkey key, hashdata value)
{
    hashkey hashvar = (key % TABLE_SIZE);
    while (table[hashvar] != NULL && table[hashvar]->getKey() != key)
        hashvar = (hashvar + 1) % TABLE_SIZE;
    if (table[hashvar] != NULL)
        delete table[hashvar];
    table[hashvar] = new Hash<hashkey, hashdata>(key, value);
}

template<class hashkey, class hashdata>
HashMap<hashkey, hashdata>::~HashMap()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL)
            delete table[i];
    delete[] table;
}

template<class hashkey, class hashdata>
void HashMap<hashkey, hashdata>::ReadFile(string filename)
{
    string line;
    int keys;
    ifstream myfile (filename.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            istringstream iss(line);
            string first, second;
            while ( getline( iss, first, '\t' ) && getline(iss, second, '\t') )
            {
                keys = atoi(first.c_str());
                put(keys, second);
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Can not Open the File Named : " << filename << endl;
    }
}
#endif /* HASH */





