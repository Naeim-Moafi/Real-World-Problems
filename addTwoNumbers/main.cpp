#include <iostream>

/*
2 4 3
5 6 4
carry = 0
2 + 5 + carry --> 7 and carry --> 0 udate = 7%10 = 7;
4 + 6 + carry --> 10 and carry --> 1 = 10 / 10 update = 10%10 = 0;
4 + 3 + carry --> 8 and carry --> 0 update 8%10 = 8
7 0 8
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *ans = new ListNode(0);
    ListNode* current = ans;
    int sum = 0;
    int carry = 0; // the amount it carries for the next node
    
    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        auto x1 = l1 ? l1->val : 0;
        auto x2 = l2 ? l2->val : 0;

        sum = x1 + x2 + carry;
        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;

    }


    return ans->next;
}

int main()
 {
//     ListNode* l1 = new ListNode(2,new ListNode(4, new ListNode(3)));
//     ListNode* l2 = new ListNode(5,new ListNode(6, new ListNode(4)));

    // ListNode* l1 = new ListNode(0);
    // ListNode* l2 = new ListNode(0);

    ListNode* l1 = new ListNode(9,new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9,new ListNode(9, new ListNode(9,new ListNode(9))));

    auto l3 = addTwoNumbers(l1, l2);
    
    while(l3 != NULL)
    {
        std::cout << l3->val;
        l3 = l3->next;
    }
    std::cout << std::endl;

    return 0;
}