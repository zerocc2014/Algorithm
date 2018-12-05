//
//  main.cpp
//  LinkedList4
//
//  Created by zerocc on 2018/12/4.
//  Copyright © 2018年 zerocc. All rights reserved.
//

#include <iostream>
#include "LinkedList4.cpp"

void reverseSingleListBetweenMethod1Test();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    reverseSingleListBetweenMethod1Test();
    return 0;
}

void reverseSingleListBetweenMethod1Test() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    ListNode *head = Solution().createLinkedList(arr, n);
    printf("\nLinkedList Method1:\n");
    Solution().printLinkedList(head);
    
    ListNode *newHead = Solution().reverseSingleListBetween(head, 2, 5);
    Solution().printLinkedList(newHead);
}
