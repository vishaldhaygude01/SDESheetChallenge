Node* mergeList(Node* x , Node* y){
    if(x == NULL){
        return y;
    }
    if(y == NULL){
        return x;
    }
    Node* answer;
    if(x->data < y->data){
        answer = x;
        answer->bottom = mergeList(x->bottom,y);
    }
    else{
        answer = y;
        answer->bottom = mergeList(x,y->bottom);
    }   
    return answer;
   
}    
Node *flatten(Node *root){
   // Your code here
    Node* temp = root;
    while(temp){
        root = mergeList(root,temp->next);
        temp = temp->next;
    }
    return root;

}
