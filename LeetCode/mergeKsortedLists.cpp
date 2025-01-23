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
#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(nullptr) {}
};


class Solution {
    public:
        ListNode* reverse(ListNode* node){
            if (node){
                ListNode* rest = node->next;
                node->next = nullptr;
                while (rest){
                    ListNode *tmp = rest->next;
                    rest->next = node;
                    node = rest;
                    rest = tmp;
                }
                return node;
            }
            return nullptr;
            
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            vector<ListNode*> newLists = lists;
            ListNode* output = nullptr;
            int leftToEmpty = newLists.size();
            for (int i = 0; i < newLists.size(); ++i){
                if (!newLists[i]){
                    --leftToEmpty;
                }
            }
            while (leftToEmpty){
                int curr_min_idx = 0;
                int curr_min = 0;
                for (int i = 0; i < newLists.size(); ++i){
                    if (newLists[i]){
                        if (!newLists[curr_min_idx] || (newLists[i]->val < newLists[curr_min_idx]->val)){
                            curr_min_idx = i;
                            cout << newLists[i]->val << endl;
                        }
                    }
                }
                curr_min = newLists[curr_min_idx]->val;
                newLists[curr_min_idx] = newLists[curr_min_idx]->next;
                if (!newLists[curr_min_idx]){
                    --leftToEmpty;
                }
                cout << "This one: " << curr_min << endl;
                output = new ListNode(curr_min, output);
            }
            return reverse(output);
        }
};
