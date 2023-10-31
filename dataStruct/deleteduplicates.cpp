/*    if (head == nullptr || head->next == nullptr) {
        return head; // 处理链表为空或只有一个节点的情况
    }

    std::stack<ListNode*> stack;
    ListNode* curr = head;
    stack.push(curr); // 将第一个节点入栈

    while (curr->next != nullptr) {
        ListNode* nextNode = curr->next;
        if (curr->val != nextNode->val) {
            stack.push(nextNode); // 非重复节点入栈
        }
        curr = nextNode;
    }

    // 重新构建链表
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
    prev->next = nullptr; // 设置最后一个节点的next为nullptr

    return newHead;*/ 
     if (head == nullptr || head->next == nullptr) {
        return head; // 处理链表为空或只有一个节点的情况
    }

    std::unordered_set<int> uniqueValues; // 用于存储已经出现的唯一值
    ListNode* prev = head;
    ListNode* curr = head->next;
    uniqueValues.insert(prev->val); // 将第一个节点的值加入哈希表

    while (curr != nullptr) {
        if (uniqueValues.count(curr->val) > 0) {
            // 当前节点的值已经在哈希表中出现过，删除当前节点
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // 当前节点的值为新值，将其加入哈希表，并更新prev和curr指针
            uniqueValues.insert(curr->val);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;

