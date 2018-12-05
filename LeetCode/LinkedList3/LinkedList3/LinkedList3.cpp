//
//  LinkedList3.cpp
//  LinkedList3
//
//  Created by zerocc on 2018/10/12.
//  Copyright © 2018年 zerocc. All rights reserved.
//

/*************************** 3. leetcode 206 题解 *************************
 
 题目链接：https://leetcode-cn.com/problems/reverse-linked-list/
 题意：反转一个单链表。可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 
 示例：
 输入：1->2->3->4->5->NULL
 输出：5->4->3->2->1->NULL
 
 解题思路：
 方法一：迭代法
    1. 设置三个指针分别指向当前结点，当前结点的前一结点和当前结点的后一结点；
    2. 遍历整个链表，每次遍历到其中一个节点时，将它链表指向改变，使当前结点指向上一结点，并依次将三个指针向下一结点移动。链表的首节点比较特殊，需要将它的下一个指向 NULL；
    3. 反转遍历的当前节点指针后断链，无法遍历后面节点问题，解决思路在断链之前，提前保存之前的状态

 方法二：递归法
    1. 对当前结点的下一结点做递归，返回倒置后的链表;
    2. 使当前结点的下一结点指向当前结点，当前结点指向NULL;
 
 ******************************** 反转一个单链表 **********************************/

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
    
public:
    
    // 迭代法反转
    ListNode *reversSingleListMethod1(ListNode *head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *currentNode = head;      // 当前节点
        ListNode *previousNode = NULL;     // 前驱指针
        ListNode *nextNode = head->next;   // 后继指针
        while (nextNode != NULL) {
            currentNode->next = previousNode;  // 进行反转,此时发生了断链
            previousNode = currentNode;        // 断链的情形，前驱指针保存状态，也就是pre后移一个结点
            currentNode = nextNode;            // 当前节点后移一个结点
            nextNode = currentNode->next;      // 将当前节点指针域赋给 next 指针
        }
        currentNode->next = previousNode;
        
        return currentNode;
    }
    
    ListNode *reversSingleListMethod2(ListNode *head) {
        
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *tail = head->next;
        ListNode *reversed = reversSingleListMethod2(head->next);
        
        // 前后翻转tail和head
        tail->next = head;
        head->next = NULL;
        
        return reversed;
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



















