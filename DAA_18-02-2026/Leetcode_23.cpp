//UID:24BCS10773

class Solution {
public:
    ListNode* f(ListNode* list1, ListNode* list2) {     
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val < list2->val) {
            list1->next = f(list1->next, list2);
            return list1;
        } else {
            list2->next = f(list1, list2->next);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (lists.size() == 0)
        return NULL;
        ListNode* res=lists[0];
        for (int i = 1; i <k; i++) {
            res = f(res, lists[i]);
        }
        return res;
    }
};
