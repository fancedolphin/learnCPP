#include "../utils/common.hpp"

/* Driver Code */
int main() {
    vector<int> nums = {1, 3, 2, 5, 4};//list
    cout << "�б� nums = ";
    printVector(nums);


    int x = nums[1];
    cout << "�������� 1 ����Ԫ�أ��õ� x = " << x << endl;

    nums[1] = 0;
    cout << "������ 1 ����Ԫ�ظ���Ϊ 0 ���õ� nums = ";
    printVector(nums);

    nums.clear();
    cout << "����б�� nums = ";
    printVector(nums);

    /* β�����Ԫ�� */
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    cout << "���Ԫ�غ� nums = ";
    printVector(nums);

    nums.insert(nums.begin() + 3, 6);
    cout << "������ 3 ���������� 6 ���õ� nums = ";
    printVector(nums);

    /* ɾ��Ԫ�� */
    nums.erase(nums.begin() + 3);
    cout << "ɾ������ 3 ����Ԫ�أ��õ� nums = ";
    printVector(nums);

    /* ͨ�����������б� */
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count++;
    }

    /* ֱ�ӱ����б�Ԫ�� */
    count = 0;
    for (int n : nums) {
        count++;
    }

    /* ƴ�������б� */
    vector<int> nums1 = {6, 8, 7, 10, 9};
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    cout << "���б� nums1 ƴ�ӵ� nums ֮�󣬵õ� nums = ";
    printVector(nums);

    /* �����б� */
    sort(nums.begin(), nums.end());
    cout << "�����б�� nums = ";
    printVector(nums);

    return 0;
}
