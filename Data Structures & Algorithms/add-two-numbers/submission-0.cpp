/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumhead = nullptr;
        ListNode* sumtail = nullptr;

        ListNode* t1 = l1 ;
        ListNode* t2 = l2 ;

        int carry = 0;
        while( t1 && t2){
            int digit =0;
            
            digit = t1->val + t2->val;
            digit += carry ;

            if(digit>9){
                digit = digit%10 ;
                carry = 1;
            } else{
                carry =0;
            }

            if (sumhead == nullptr){
                sumhead = new ListNode(digit);
                sumtail = sumhead;
            } else {
                ListNode* newnode = new ListNode(digit);
                sumtail->next =newnode;
                sumtail = newnode;

            }
            
                t1 =t1->next;
                t2 =t2->next;
        }
        while( t1 ){
             int digit = t1->val;
            
           
            digit += carry ;

            if(digit>9){
                digit = digit%10;
                carry = 1;
            } else{
                carry =0;
            }

            if (sumhead == nullptr){
                sumhead = new ListNode(digit);
                sumtail = sumhead;
            } else {
                ListNode* newnode = new ListNode(digit);
                sumtail->next =newnode;
                sumtail = newnode;
                t1 =t1->next;

            }
        }

    while( t2 ){
         int digit =t2->val;
        
            digit += carry ;

            if(digit>9){
                digit = digit%10;
                carry = 1;
            } else{
                carry =0;
            }

            if (sumhead == nullptr){
                sumhead = new ListNode(digit);
                sumtail = sumhead;
            } else {
                ListNode* newnode = new ListNode(digit);
                sumtail->next =newnode;
                sumtail = newnode;
            }
            
                t2 =t2->next;
    }


    if (carry == 1){
        if (sumhead == nullptr){
                sumhead = new ListNode(1);
                sumtail = sumhead;
            } else {
                ListNode* newnode = new ListNode(1);
                sumtail->next =newnode;
                sumtail = newnode;
            }
    }
return sumhead;
    }
};