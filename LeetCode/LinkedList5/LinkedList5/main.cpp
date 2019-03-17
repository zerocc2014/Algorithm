//
//  main.cpp
//  LinkedList5
//
//  Created by zerocc on 2018/12/10.
//  Copyright © 2018年 zerocc. All rights reserved.
//

#include <iostream>
#include "LinkedList5.cpp"

void sortListTest();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    sortListTest();
    
    return 0;
}

void sortListTest() {
    int arr[] = {-1,5,3,4,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    ListNode *head = Solution().createLinkedList(arr, n);
    printf("\nLinkedList Method1:\n");
    Solution().printLinkedList(head);
    
    ListNode *newHead = Solution().sortList(head);
    Solution().printLinkedList(newHead);
}
