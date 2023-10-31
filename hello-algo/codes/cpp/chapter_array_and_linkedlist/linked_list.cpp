#include "../utils/common.hpp"

/* ������Ľڵ� n0 ֮�����ڵ� P */
void insert(ListNode* &n0,  ListNode *P) {//reference
	
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* ɾ������Ľڵ� n0 ֮����׸��ڵ� */
void remove(ListNode *n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    cout<<n0;
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // �ͷ��ڴ�
    delete P;
}

/* ��������������Ϊ index �Ľڵ� */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

/* �������в���ֵΪ target ���׸��ڵ� */
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

/* Driver Code */
int main() {
    /* ��ʼ������ */
    // ��ʼ�������ڵ�
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // ��������ָ��
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "��ʼ��������Ϊ" << endl;
    printLinkedList(n0);

    /* ����ڵ� */
    insert(n0, new ListNode(0));
    cout << "����ڵ�������Ϊ" << endl;
    printLinkedList(n0);

    /* ɾ���ڵ� */
    remove(n0);
    cout << "ɾ���ڵ�������Ϊ" << endl;
    printLinkedList(n0);

    /* ���ʽڵ� */
    ListNode *node = access(n0, 3);
    cout << "���������� 3 ���Ľڵ��ֵ = " << node->val << endl;

    /* ���ҽڵ� */
    int index = find(n0, 2);
    cout << "������ֵΪ 2 �Ľڵ������ = " << index << endl;

    // �ͷ��ڴ�
    freeMemoryLinkedList(n0);

    return 0;
}
