/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        bool isN1Max = n1>n2;
        int max = isN1Max?n1:n2;
        // ListNode* answer = (ListNode*) malloc(max+1);
        
        ListNode answer;

        
        ListNode head1 = *l1;
        ListNode prev1;
        ListNode next1;
        while(head1.next != nullptr){
            next1 = *head1.next;
            head1.next = &prev1;
            prev1 = head1;
            head1 = next1;
            n1++;
        }
        head1 = prev1;
        
        ListNode head2 = *l2;
        ListNode prev2;
        ListNode next2;
        while(head2.next != nullptr) {
            next2 = *head2.next;
            head2.next = &prev2;
            prev2 = head2;
            head2 = next2;
            n2++;
        }

        // cout<<"n1"<<n1<<"n2"<<n2<<endl;
        while(head1.next != nullptr){
            cout<<head1.val<<endl;
        }

        int count, carry =0;
        bool isList1End = false;
        bool isList2End = false;
        ListNode heada = answer;
        while(max != 0){
            int valueL1 =0;
            if(!isList1End){
                valueL1 = head1.val;
            }

            int valueL2 =0;
            if(!isList2End){
                valueL2 = head2.val;
            }
            
            int sum = valueL1 + valueL2 + carry;
            int carry = sum/10;
            if(carry>0){
                sum = sum %10;
            }
            heada.val = sum;

            heada = *heada.next;
            cout<<"val"<<heada.val<<endl;
            //post
            if(head1.next != nullptr){
                head1 = *head1.next;
            } else {
                isList1End = true;
            }

            if(head2.next != nullptr){
                head2 = *head2.next;
            } else {
                isList2End = true;
            }

            max--;
        }


        return answer.next;
    }


};