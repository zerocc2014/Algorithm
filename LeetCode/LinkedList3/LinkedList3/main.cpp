//
//  main.cpp
//  LinkedList3
//
//  Created by zerocc on 2018/10/12.
//  Copyright © 2018年 zerocc. All rights reserved.
//

#include <iostream>
#include "LinkedList3.cpp"

void reversSingleListMethod1Test();
void reversSingleListMethod2Test();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    reversSingleListMethod1Test();
    reversSingleListMethod2Test();
    return 0;
}

void reversSingleListMethod1Test() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode *head = Solution().createLinkedList(arr, n);
    printf("\nLinkedList Method1:\n");
    Solution().printLinkedList(head);
    
    ListNode *newHead = Solution().reversSingleListMethod1(head);
    Solution().printLinkedList(newHead);
}

void reversSingleListMethod2Test() {
    int arr[] = {1,2,3,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    ListNode *head = Solution().createLinkedList(arr, n);
    printf("\nLinkedList Method1:\n");
    Solution().printLinkedList(head);
    
    ListNode *newHead = Solution().reversSingleListMethod2(head);
    Solution().printLinkedList(newHead);
}
