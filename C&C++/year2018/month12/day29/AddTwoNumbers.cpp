#include <iostream>
#include <malloc.h>
using namespace::std;


struct ListNode {
    int val;
    ListNode *next;    
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int arrays = 0;//进位
        ListNode * l3 = (ListNode*)malloc(sizeof(ListNode));
        while(l1&&l2){
            l3->val=(l1->val+l2->val+arrays)%10;
            arrays=(l1->val+l2->val)/10;
            
        }    
    }
};
int main(){

    return 0;
}