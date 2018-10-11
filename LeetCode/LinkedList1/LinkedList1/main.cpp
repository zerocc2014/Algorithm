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
    int arr[] = {1,2,3,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    
    ListNode *head = Solution().createLinkedList(arr, n);
    Solution().printLinkedList(head);
    
    ListNode *newHead = Solution().deleteNthNodeFromEnd(head, k);
    Solution().printLinkedList(newHead);

}
