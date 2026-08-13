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

    ListNode* mergetwolist(ListNode* L1 ,ListNode* L2){
    if( !L1){
        return L2;
    }
    if(!L2){return L1;}

    if(L1->val <= L2->val ){

        L1->next = mergetwolist(L1->next,L2);
        return L1;
    }

    else { 
        L2->next = mergetwolist(L1,L2->next);
        return L2;
        }

        return NULL;
    }

    ListNode* partitionandmerge(int l , int r ,vector<ListNode*>& lists){
        if(l>r){
            return NULL;
        }
        if( l == r){
            return lists[l];
        }

        int mid  = l + (r-l)/2;

        ListNode* L1 = partitionandmerge(l,mid, lists);
        ListNode* L2 = partitionandmerge(mid+1,r , lists);

        return mergetwolist(L1,L2);

    }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n =lists.size();

        if(n==0){
            return NULL;
        }

        return partitionandmerge(0 , n-1,lists);

    }
};