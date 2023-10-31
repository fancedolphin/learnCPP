#include <iostream>
//链表只能一个节点一个节点创建 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // 创建一个虚拟头节点
    ListNode* current = dummy;
    int carry = 0; // 进位标志

    while (l1 != nullptr && l2 != nullptr ) {
        int sum = carry;

if(l1!=nullptr){
	 sum += l1->val;
            l1 = l1->next;
}
           


if(l1!=nullptr){
	  sum += l2->val;
            l2 = l2->next;
}
           

        carry = sum / 10;
        sum = sum % 10;
        
        ListNode* newNode = new ListNode(sum);
        current->next = newNode;
        current = current->next;
    }

    ListNode* result = dummy->next;//dummy开头为0，0的下一位才是真正的开始 
    delete dummy;
    return result;
}

