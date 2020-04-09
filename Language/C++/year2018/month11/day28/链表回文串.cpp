#include <iostream>
#include <stack>
using namespace::std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        bool flag=true;
        ListNode* P=A;
        stack<int> s;
        while(P){
        	s.push(P->val);
        	P=P->next;
        }
        P=A;
        while(P){
        	if(s.top()==P->val){
        		P=P->next;
        		s.pop();
        	}else{
        		flag=false;
        	}
        }
        return flag;
    }
};
int main(){
	return 0;
}

