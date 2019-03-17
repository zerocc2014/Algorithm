//
//  LinkedList4.cpp
//  LinkedList4
//
//  Created by zerocc on 2018/12/4.
//  Copyright © 2018年 zerocc. All rights reserved.
//

/*************************** 4. leetcode 148 题解 *************************
 
 题目链接：https://leetcode-cn.com/problems/sort-list/
 题意：在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 
 示例：
 输入：-1->5->3->4->0
 输出：-1->0->3->4->5
 
 解题思路：
常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等。。它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，而根据单链表的特点，最适于用归并排序

 ******************************** 排序链表 **********************************/

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
    
public:
    
    ListNode *reverseSingleListBetween(ListNode *head) {
        
        if(head == NULL || head -> next == NULL)
            return head;
        //找到链表的中间结点，然后对前半部分和后半部分排序
        //通过快慢指针找到中间结点
        ListNode *slow = head, *fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //slow即中间结点
        //断开中间结点的连接
        ListNode *midnext = slow -> next;
        slow -> next = NULL;
        
        ListNode * l1 = sortList(head);
        ListNode * l2 = sortList(midnext);
        
        return mergeTwoLists(l1, l2);
    }
    
    
    
    //合并两个有序链表
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode *dummy_head = new ListNode(-1);//避免讨论head是不是空
        ListNode *tail = dummy_head;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                tail -> next = l1;
                l1 = l1 -> next;
            }
            else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;
            tail -> next = NULL;//不要忘了
        }
        if(l1 != NULL){
            tail -> next = l1;
        }
        if(l2 != NULL){
            tail -> next = l2;
        }
        ListNode *newhead = dummy_head -> next;
        delete [] dummy_head;
        return newhead;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
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

















