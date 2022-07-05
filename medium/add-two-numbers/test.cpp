#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode * kthelement(ListNode* head,int k){
    if(k)
        return kthelement(head->next,k-1);
    else 
        return head;
}
int findlen(ListNode* head){
    int len=0;
    for(;head->next;len++,head=head->next);
    return len+1;
}
ListNode* reverse(ListNode* head){
    ListNode *tmphead=head,*tmp,*tmp_prev=NULL;
    int len=findlen(head);
    for(int i=0;i<len;i++){
        tmp=kthelement(head,len-i-1);
        if(tmp_prev)    
            tmp_prev->next=tmp;
        else
            tmphead=tmp;
        tmp_prev=tmp;
    }
    tmp->next=NULL;
    return tmphead;
}
int main(){
    ListNode *node3=new ListNode(3),*node2=new ListNode(2,node3),*node1=new ListNode(1,node2),*head=node1;
    head=reverse(node1);
    while(head){
        cout<<(head->val)<<endl;
        head=head->next;
    }
}