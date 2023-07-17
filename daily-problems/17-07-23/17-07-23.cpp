class Solution {
    ListNode* ReverseList(ListNode* head){
        ListNode *prev = NULL;
        ListNode* curr= head;
        while(curr ){
            ListNode* next= curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *newhead = new ListNode((curr1->val+curr2->val)%10);
        ListNode *curr3 = newhead;
        int carry=0;
         carry = (curr1->val+ curr2->val) / 10;
        curr1= curr1->next;
        curr2= curr2->next;
        while(curr1 && curr2) {
            ListNode* temp = new ListNode((curr1->val+curr2->val+carry)%10);
            carry  = (curr1->val+curr2->val +carry)/10;
            curr3->next = temp;
            curr3 = curr3->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        while(curr1) {
            ListNode* temp = new ListNode((curr1->val+carry)%10);
            carry = (curr1->val +carry) / 10;
            curr3->next = temp;
            curr1= curr1->next;
            curr3= curr3->next;
        }
        while(curr2) {
            ListNode* temp = new ListNode((curr2->val+carry)%10);
            carry = (curr2->val +carry) / 10;
            curr3->next = temp;
            curr2 = curr2->next;
            curr3= curr3->next;
            
        }
        if(carry > 0){
            ListNode *temp = new ListNode(carry);
            curr3->next = temp;
        }
        return newhead;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         l1 = ReverseList(l1);
         l2 = ReverseList(l2);
         ListNode* res = AddTwoNumbers(l1,l2);
         return ReverseList(res);
    }
};