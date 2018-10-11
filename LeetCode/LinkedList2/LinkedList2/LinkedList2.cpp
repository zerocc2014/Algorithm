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
 
 解题思路：
  方法一：递归法
    1. 判断l1和l2是否存在空链表，有空链表就可以直接返回；
    2. 首先找到新链表头结点，两个链表头结点比较大小；
    3. 再递归传入取小链表下一个结点与另一个链表原来比较的节点相比较取小插入对应位置；
 
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
    
    // 递归法合并两个有序链表
    ListNode *mergeTwoListsMethod1(ListNode *l1, ListNode *l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        
        ListNode* temp;
        if (l1->val < l2->val) {
            temp=l1;
            temp->next=mergeTwoListsMethod1(l1->next,l2);
        }else {
            temp=l2;
            temp->next=mergeTwoListsMethod1(l1,l2->next);
        }
        return temp;

    }
    
    ListNode *mergeTwoListsMethod2(ListNode *l1, ListNode *l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;

        ListNode head = NULL;
        ListNode *temp = &head;
        while(l1 && l2){
            if (l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        if (l1) temp->next=l1;
        if (l2) temp->next=l2;
        
        return head.next;
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
