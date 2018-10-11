//
//  main.cpp
//  LinkedList2
//
//  Created by zerocc on 2018/10/11.
//  Copyright © 2018年 zerocc. All rights reserved.
//

#include <iostream>
#include "LinkedList2.cpp"

void mergeTwoorderedListsMethod1Test();
void mergeTwoorderedListsMethod2Test();


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    mergeTwoorderedListsMethod1Test();

    mergeTwoorderedListsMethod2Test();
    
    return 0;
}

void mergeTwoorderedListsMethod1Test() {
    int arr1[] = {1,2,4,15};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int arr2[] = {3,7,10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    ListNode *headL1 = Solution().createLinkedList(arr1, n1);
    ListNode *headL2 = Solution().createLinkedList(arr2, n2);
    
    printf("\nLinkedList 1:\n");
    Solution().printLinkedList(headL1);
    
    printf("\nLinkedList 2:\n");
    Solution().printLinkedList(headL2);
    
    ListNode *newHead = Solution().mergeTwoListsMethod1(headL1, headL2);
    Solution().printLinkedList(newHead);

}

void mergeTwoorderedListsMethod2Test() {
    int arr1[] = {1,2,4,10};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int arr2[] = {2,5,7,10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    ListNode *headL1 = Solution().createLinkedList(arr1, n1);
    ListNode *headL2 = Solution().createLinkedList(arr2, n2);
    
    printf("\nLinkedList 1:\n");
    Solution().printLinkedList(headL1);
    
    printf("\nLinkedList 2:\n");
    Solution().printLinkedList(headL2);
    
    ListNode *newHead = Solution().mergeTwoListsMethod2(headL1, headL2);
    Solution().printLinkedList(newHead);

}

