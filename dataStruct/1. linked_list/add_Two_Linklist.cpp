#include <iostream>
//����ֻ��һ���ڵ�һ���ڵ㴴�� 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // ����һ������ͷ�ڵ�
    ListNode* current = dummy;
    int carry = 0; // ��λ��־

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

    ListNode* result = dummy->next;//dummy��ͷΪ0��0����һλ���������Ŀ�ʼ 
    delete dummy;
    return result;
}

