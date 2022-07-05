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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp1=l1,*tmp2=l2,*tmp_node,*prev_node=NULL,*head;
        int remainder=0,tmp_sum;
        while(tmp1||tmp2||remainder){
            if(tmp1&&tmp2){
                tmp_sum=tmp1->val+tmp2->val+remainder;
                remainder=tmp_sum/10;
                tmp_sum%=10;
                tmp_node=new ListNode(tmp_sum);
                if(prev_node)
                    prev_node->next=tmp_node;
                else
                    head=tmp_node;
                prev_node=tmp_node;
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
            else if(tmp1){
                tmp_sum=tmp1->val+remainder;
                remainder=tmp_sum/10;
                tmp_sum%=10;
                tmp_node=new ListNode(tmp_sum);
                if(prev_node)
                    prev_node->next=tmp_node;
                else
                    head=tmp_node;
                prev_node=tmp_node;
                tmp1=tmp1->next;
            }
            else if(tmp2){
                tmp_sum=tmp2->val+remainder;
                remainder=tmp_sum/10;
                tmp_sum%=10;
                tmp_node=new ListNode(tmp_sum);
                if(prev_node)
                    prev_node->next=tmp_node;
                else
                    head=tmp_node;
                prev_node=tmp_node;
                tmp2=tmp2->next;
            }
            else{
                tmp_node=new ListNode(remainder);
                remainder=0;
                if(prev_node)
                    prev_node->next=tmp_node;
                else
                    head=tmp_node;
                prev_node=tmp_node;
            }
        }
        return head;
    }
};