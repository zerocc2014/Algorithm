//
//  main.cpp
//  LinkedList1
//
//  Created by zerocc on 2018/10/10.
//  Copyright © 2018年 zerocc. All rights reserved.
//

#include <iostream>
#include "LinkedList1.cpp"

void deleteNthNodeFromEnd();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    deleteNthNodeFromEnd();
    return 0;
}

void deleteNthNodeFromEnd() {
    int arr[] = {1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    
    ListNode *head = ListedList().createLinkedList(arr, n);
    ListedList().printLinkedList(head);
    
    ListNode *newHead = ListedList().deleteNthNodeFromEnd(head, k);
    ListedList().printLinkedList(newHead);
    
//    ListNode *newHead = ListedList().deleteNthNodeFromEnd1(head, k);
//    ListedList().printLinkedList(newHead);

}
