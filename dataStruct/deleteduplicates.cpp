/*    if (head == nullptr || head->next == nullptr) {
        return head; // ��������Ϊ�ջ�ֻ��һ���ڵ�����
    }

    std::stack<ListNode*> stack;
    ListNode* curr = head;
    stack.push(curr); // ����һ���ڵ���ջ

    while (curr->next != nullptr) {
        ListNode* nextNode = curr->next;
        if (curr->val != nextNode->val) {
            stack.push(nextNode); // ���ظ��ڵ���ջ
        }
        curr = nextNode;
    }

    // ���¹�������
    ListNode* newHead = nullptr;
    ListNode* prev = nullptr;
    while (!stack.empty()) {
        ListNode* node = stack.top();
        stack.pop();

        if (prev == nullptr) {
            newHead = node;
            prev = node;
        } else {
            prev->next = node;
            prev = node;
        }
    }
    prev->next = nullptr; // �������һ���ڵ��nextΪnullptr

    return newHead;*/ 
     if (head == nullptr || head->next == nullptr) {
        return head; // ��������Ϊ�ջ�ֻ��һ���ڵ�����
    }

    std::unordered_set<int> uniqueValues; // ���ڴ洢�Ѿ����ֵ�Ψһֵ
    ListNode* prev = head;
    ListNode* curr = head->next;
    uniqueValues.insert(prev->val); // ����һ���ڵ��ֵ�����ϣ��

    while (curr != nullptr) {
        if (uniqueValues.count(curr->val) > 0) {
            // ��ǰ�ڵ��ֵ�Ѿ��ڹ�ϣ���г��ֹ���ɾ����ǰ�ڵ�
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // ��ǰ�ڵ��ֵΪ��ֵ����������ϣ��������prev��currָ��
            uniqueValues.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;

