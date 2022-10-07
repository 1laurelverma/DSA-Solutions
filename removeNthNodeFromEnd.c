struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len=0;
    struct ListNode * temp= head;
    struct ListNode * ptr;
    while(temp!= NULL){
        len++;
        temp=temp->next;
    }
    struct ListNode * temp2= head;
    for(int i=0; i<len-n-1; i++){
        head = head->next;
    }
    if (len==0||len==1){
        return NULL;
    }
    else if (len==n)
    {
        temp2=temp2->next;
        return temp2;
    }
    else{
        ptr=head->next;
        head->next= ptr->next;
        return temp2;
    }
}
