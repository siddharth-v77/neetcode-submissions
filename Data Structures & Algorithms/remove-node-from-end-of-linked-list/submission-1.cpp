// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* fast = head;
//         ListNode* slow = head;

//         for (int i = 1; i<=n ;i++){
//             fast= fast->next;
//         }

//         if(fast == NULL){
//             ListNode* temp = head;
//             head = head->next;
//             delete temp;
//             return head;
//         }

//         while(fast != NULL &&fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next;
//         }
//         ListNode* delnode = slow->next;
//          slow->next = slow->next->next;
//         delete delnode;

//         return head;
//     }
// };



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count =0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(count == n){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int res = count-n;
        temp = head;
        while(temp !=NULL){
           

            if (res == 1) {
                ListNode* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                break;
            }
             res--;
            
            temp = temp->next;
        }
        return head;
    }
};