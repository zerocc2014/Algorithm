//
//  LinkedList2.cpp
//  LinkedList2
//
//  Created by zerocc on 2018/10/11.
//  Copyright © 2018年 zerocc. All rights reserved.
//

/*************************** 2. leetcode 21 题解 *************************
 
 题目链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/
 题意：将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
 示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
 
 解题思路(前提n有效)：
 1. 利用双指针法解题。首先指针 headNode 指向头节点，然后让其后移 n 步；
 2. 接着让指针 behindNode 指向头节点，与 headNode 一起向后移动；
 3. 当 headNode 的 next 指针为 NULL 时，behindNode 即指向了要删除结点的前一个节点；
 4. 再让 headNode 指向的 next 指针指向要删除节点的下一个节点即可。
 
 时间复杂度：
 
 ******************************** 合并两个有序链表 **********************************/
#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    
    ListNode *mergeTwoLists(ListNode *headL1, ListNode *headL2) {
        ListNode *mergedNode = NULL;
        
        if (headL1->val < headL2->val) {
            mergedNode = headL1;
            mergedNode->next = mergeTwoLists(mergedNode->next, headL2);
        }else {
            mergedNode = headL2;
            mergedNode->next = mergeTwoLists(headL1, mergedNode->next);
        }
        
        return mergedNode;
    }
    
    // 生成链表
    ListNode* createLinkedList(int array[],int n) {
        if (n==0) {
            return NULL;
        }
        
        ListNode *headNode = new ListNode(array[0]);
        ListNode *curNode = headNode;
        for (int i=1; i<n; i++) {
            curNode->next = new ListNode(array[i]);
            curNode = curNode->next;
        }
        
        return headNode;
    }
    
    // 打印链表
    void printLinkedList(ListNode *head) {
        ListNode *curNode = head;
        while (curNode != NULL) {
            std::cout << curNode->val << "->";
            curNode = curNode->next;
        }
        
        std::cout << "Null" << std::endl;
    }

};
