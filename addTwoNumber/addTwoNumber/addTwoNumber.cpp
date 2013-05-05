/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = new ListNode(0);
        ListNode *now = head;
        int CarryBit = 0;
        int val = 0;
        while(l1)
        {
            if(!l2)
            {
                break;
            }
            val = (l1->val + l2->val + CarryBit) % 10;
            CarryBit = (l1->val + l2->val + CarryBit) / 10;
            ListNode *newnode = new ListNode(val);
            now->next = newnode;
            now = now->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            val = (l1->val + CarryBit) % 10;
            CarryBit = (l1->val + CarryBit) / 10;
            ListNode *newnode = new ListNode(val);
            now->next = newnode;
            now = now->next;
            l1 = l1->next;   
        }
        while(l2)
        {
            val = (l2->val + CarryBit) % 10;
            CarryBit = (l2->val + CarryBit) / 10;
            ListNode *newnode = new ListNode(val);
            now->next = newnode;
            now = now->next;
            l2 = l2->next;          
        }
        if(CarryBit == 1)
        {
            ListNode *newnode = new ListNode(1);
            now->next = newnode;
        }
        return head->next;
        
    }
};