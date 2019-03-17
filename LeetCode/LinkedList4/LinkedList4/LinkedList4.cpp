//
//  LinkedList4.cpp
//  LinkedList4
//
//  Created by zerocc on 2018/12/4.
//  Copyright © 2018年 zerocc. All rights reserved.
//

/*************************** 4. leetcode 92 题解 *************************
 
 题目链接：https://leetcode-cn.com/problems/reverse-linked-list-ii/
 题意：翻转链表中指定区间的结点。反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。1 ≤ m ≤ n ≤ 链表长度。
 
 示例：
 输入：1->2->3->4->5->NULL, m = 2, n = 4
 输出：1->4->3->2->5->NULL
 
 解题思路：
 方法一：迭代法
 总共需要4个指针，其中1个是添加一个虚拟的头指针（主要是防止需要翻转的是头节点）
 剩下的3个指针，分别代表：找到起始位置的前一个指针pre，起始指针start，结尾指针tail
 pre和start在找到后都不需要在移动，原因是pre只需要指向区间的最后一个指针即可，start只需要指向区间外的第一个指针，所以都不需要移动
 所以只需要移动tail指针，那么tail指针怎么移动的，用start指针的next记录tail指针的下一个位置

 ******************************** 反转链表 II **********************************/

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
    
public:
    
    ListNode *reverseSingleListBetween(ListNode *head, int m, int n) {
        
        if (head == NULL || head->next == NULL || m == n) {
            return head;
        }
        
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* preNode = dummyNode;
        for (int i = 1; i < m; i++) {
            preNode = preNode->next;
        }
        
        ListNode* startNode = preNode->next;
        ListNode* tailNode = startNode->next;
        for (int i = m; i < n; i++) {
            startNode->next = tailNode->next;
            tailNode->next = preNode->next;
            preNode->next = tailNode;
            tailNode = startNode->next;
        }
        
        return dummyNode->next;
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

















