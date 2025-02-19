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
        int getLength(ListNode *head){
            int i = 0;
            while (head){
                head = head->next;
                ++i;
            }
            return i;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            int len = getLength(head);
            ListNode* curr = head;
            ListNode *parent = nullptr;
            ListNode *toReturn = nullptr;
            for (int i = 0; i + (k - 1) < len; i += k){
                ListNode* first = curr;
                ListNode* acc = curr;
                curr = curr->next;
                for (int j = 1; j < k; ++j){
                    ListNode* tmp = curr;
                    curr = curr->next;
                    tmp->next = acc;
                    acc = tmp;
                }
                first->next = curr;
                ListNode *tmp = acc;
                if (parent != nullptr){
                    parent->next = acc;
                } else {
                    toReturn = acc;
                }
                parent = first;
            }
            return toReturn;
        }
    };
