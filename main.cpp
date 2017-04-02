//
//  main.cpp
//  Basic Functionalities
//
//  Created by Fatih Baloglu on 02/04/2017.
//  Copyright © 2017 Fatih Baloglu. All rights reserved.
//

#include "Libs.hpp"
#include "Libs.cpp"
#include <iostream>
#include <string>

#define RANDOMFILE "random.txt"
#define NAMES "names.txt"
#define OUTPUTFILE "output.txt"
#define HASHFILE "hash.txt"

#define intlinkedlistusage
#define intquicksortusage
#define intmergesortusage
#define intquicksortrandomusage
#define intmergesortrandomusage
#define stringlinkedlistusage
#define stackusage
#define checkbalanceusage
#define queueusage
#define hashusage

using namespace std;

int main(int argc, const char * argv[])
{
#ifdef intlinkedlistusage
    LinkedList<int> list;
    list.adddata(30);
    list.adddata(8);
    list.addfromhead(5);
    list.adddata(20);
    list.printdata();
    list.adddata(4);
    list.removedata(20);
    list.printdata();
    list.addfromhead(2);
    list.adddata(10);
    list.printdata();
    list.insertafter(30, 35);
    list.printdata();
    cout << "Length : " << list.getlength() << endl;
    list.printdata();
#endif /* intlinkedlistusage */
    
#ifdef intquicksortusage
    LinkedList<int> quick;
    quick.adddata(30);
    quick.adddata(8);
    quick.addfromhead(5);
    quick.adddata(20);
    quick.printdata();
    quick.adddata(4);
    quick.removedata(20);
    quick.printdata();
    quick.addfromhead(2);
    quick.adddata(10);
    quick.printdata();
    quick.insertafter(30, 35);
    quick.printdata();
    cout << "Length : " << quick.getlength() << endl;
    quick.quickSort();
    quick.printdata();
#endif /* intquicksortusage */
    
#ifdef intmergesortusage
    LinkedList<int> merge;
    merge.adddata(30);
    merge.adddata(8);
    merge.addfromhead(5);
    merge.adddata(20);
    merge.printdata();
    merge.adddata(4);
    merge.removedata(20);
    merge.printdata();
    merge.addfromhead(2);
    merge.adddata(10);
    merge.printdata();
    merge.insertafter(30, 35);
    merge.printdata();
    cout << "Length : " << merge.getlength() << endl;
    merge.mergeSort();
    merge.printdata();
#endif /* intmergesortusage */
    
#ifdef intquicksortrandomusage
    LinkedList<int> quicks;
    quicks.randomGenerator(RANDOMFILE, 10000, 1000000);
    quicks.ReadFileasINT(RANDOMFILE);
    quicks.printdata();
    quicks.quickSort();
    cout << "Length : " << quicks.getlength() << endl;
    quicks.WriteFile(OUTPUTFILE);
    quicks.printdata();
    cout << "Length : " << quicks.getlength() << endl;
#endif /* intquicksortrandomusage */

#ifdef intmergesortrandomusage
    LinkedList<int> merges;
    merges.randomGenerator(RANDOMFILE, 10000, 1000000);
    merges.ReadFileasINT(RANDOMFILE);
    merges.printdata();
    merges.mergeSort();
    cout << "Length : " << merges.getlength() << endl;
    merges.WriteFile(OUTPUTFILE);
    merges.printdata();
    cout << "Length : " << merges.getlength() << endl;
#endif /* intmergesortrandomusage */
    
#ifdef stringlinkedlistusage
    LinkedList<string> slist;
    slist.ReadFile(NAMES);
    slist.printdata();
    slist.ascendingsort();
    slist.printdata();
    slist.WriteFile(OUTPUTFILE);
#endif /* stringlinkedlistusage */
    
#ifdef stackusage
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.printstack();
    stack.pop();
    stack.printstack();
#endif /* stackusage */
    
#ifdef checkbalanceusage
    CheckBalance balanced;
    if(balanced.Balanced("(10x20)-10/30"))    cout << "Balanced :" << "(10x20)-10/30" << endl;
    else    cout << "Not Balanced :" << "(10x20)-10/30" << endl;
    if(balanced.Balanced("(10x20)-([10/30]"))    cout << "Balanced :" << "(10x20)-([10/30]" << endl;
    else    cout << "Not Balanced :" << "(10x20)-([10/30]" << endl;
#endif /* checkbalanceusage */
    
#ifdef queueusage
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.printqueue();
    queue.dequeue();
    queue.printqueue();
#endif /* queueusage*/
    
#ifdef hashusage
    HashMap<int, string> shash(10000);
    shash.ReadFile(HASHFILE);
    string value = shash.get(417);
    cout << "Value : " << value << endl;
#endif /* hashusage */
}
