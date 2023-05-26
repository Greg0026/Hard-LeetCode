class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<vector<ListNode*>> v;
        int j {0};
        // creating the node group
        while (head!=NULL) {
            v.push_back({});
            for (int i (0); i<k; ++i) {
                v[j].push_back(head);
                if (head->next!=nullptr) head = head->next; else {
                    head = head->next;
                    break;
                }
            }
            ++j;
        }
        ListNode* lastNodes = nullptr;
        if (v[v.size()-1].size()!=v[0].size()) {
            lastNodes = v[v.size()-1][0];
            v.pop_back();
        }
        // inverting the group
        for (auto& group : v) {
            for (int i (0); i<group.size(); ++i) {
                if (i==0) group[i]->next = nullptr; else {
                    group[i]->next = group[i-1];
                }
            }
        }
        for (int i (0); i<v.size()-1; ++i) {
            v[i][0]->next = v[i+1][k-1];
        }
        v[v.size()-1][0]->next = lastNodes;
        return v[0][v[0].size()-1];
    }
};
