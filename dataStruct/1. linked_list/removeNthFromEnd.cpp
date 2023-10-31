//Ë«Ö¸Õë
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0£¬head);
        
        ListNode*p = dummyHead;
        ListNode*q = dummyHead;
        
        for(int i = 0; i < n + 1; i++)
            q = q -> next;
        
        while(q != NULL){
            p = p -> next;
            q = q -> next;
        }
        
        ListNode* delNode = p -> next;
        p -> next = delNode -> next;
        delete delNode;
        
        ListNode* returnHead =  dummyHead -> next;
        delete dummyHead;
        return returnHead;
    }
};
*/
    void getLength(ListNode* head,int &length) {
        
        while (head) {
            ++length;
            head = head->next;
        }
        
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode(0,head);
        int length=0;
        getLength(head,length);
        ListNode* n0=dummy;

        for(int i=1;i<length-n+1;i++){
            n0=n0->next;
        }
        n0->next=n0->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    } 
