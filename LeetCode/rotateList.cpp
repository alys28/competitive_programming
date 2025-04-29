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
        int getLength(ListNode* head){
            ListNode *curr = head;
            int count = 0;
            while (curr){
                ++count;
                curr = curr->next;
            }
            return count;
        }
        ListNode* rotateRight(ListNode* head, int k) {
            int length = getLength(head);
            if (length == 0) return head;
            int realK = k % length;
            // Find pivot
            if (realK == 0) return head;
            ListNode* pivot = head;
            int it = length - realK;
            ListNode* prev = head;
            while (it > 0){
                prev = pivot;
                pivot = pivot->next;
                --it;
            }
            prev->next = nullptr;
            ListNode* oldHead = head;
            head = pivot;
            while (pivot->next != nullptr){
                pivot = pivot->next;
            }
            pivot->next = oldHead;
            return head;
        }
    };