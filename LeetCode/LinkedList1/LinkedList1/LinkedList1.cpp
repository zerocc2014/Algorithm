//
//  LinkedList1.cpp
//  LinkedList1
//
//  Created by zerocc on 2018/10/10.
//  Copyright © 2018年 zerocc. All rights reserved.
//

/*************************** 1. leetcode 19 题解 *************************
 
 题目链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 题意：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 
 示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.
 
 解题思路：
    1. 利用双指针法解题。首先指针 headNode 指向头节点，然后让其后移 n 步；
    2. 接着让指针 behindNode 指向头节点，与 headNode 一起向后移动；
    3. 当 headNode 的 next 指针为 NULL 时，behindNode 即指向了要删除结点的前一个节点；
    4. 再让 headNode 指向的 next 指针指向要删除节点的下一个节点即可。
 
 
 ***/

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class ListedList {
    public :
    
    // 1. 删除链表的倒数第N个节点
    ListNode *deleteNthNodeFromEnd(ListNode *head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *headNode = head;
        ListNode *behindNode = head;
        
        for (int i=0; i<n; i++) {
            headNode = headNode->next;
        }
        if (headNode == NULL) {
            return head->next;
        }
        
        while (headNode->next != NULL) {
            headNode = headNode->next;
            behindNode = behindNode->next;
        }
        
        behindNode->next = behindNode->next->next;
        
        return head;
        
    }
    
    ListNode *deleteNthNodeFromEnd1(ListNode *head, int n) {

        ListNode *first = head;
        while (n--!=0) {
            first = first->next;
        }
        
        if (!first) {
            return head->next;
        }
        ListNode *sec = head;
        while (first->next != NULL) {
            sec=sec->next;
            first=first->next;
        }
        sec->next=sec->next->next;
        
        return head;
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
