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

/*
Node* merge(Node* a, Node* b) {
    Node* res = new Node(0);
    Node* temp = res;
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
        temp->next = NULL;
    }
    if(a != NULL) {
        temp->child = a;
    }
    else {
        temp->child = b;
    }
    temp->next = NULL;
    return res->child;
}
Node* flattenLinkedList(Node* root) {
    if(root == NULL || root->next == NULL) {
        return root;
    }
    root->next = flattenLinkedList(root->next);
    root = merge(root, root->next);
    return root;

}

*/