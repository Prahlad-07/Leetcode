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

 /*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        while(head != nullptr){
            int val = head -> val;
            head  = head -> next;
            s+=to_string(val);
        }
        int cnt = 0;
        int ans = 0;
        int idx = s.size()-1;
        while(idx >= 0){
            int dig = s[idx]-'0';
            idx--;
            ans+=(pow(2,cnt)*dig);
            cnt++;
        }
        
        return ans;
        
    }
};
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        int ans = 0;
        int cnt = 0;
        while(prev != NULL){
            int value = prev -> val;
            prev = prev->next;
            ans += (pow(2,cnt)*value);
            cnt++;
        }
        return ans;
    }
};