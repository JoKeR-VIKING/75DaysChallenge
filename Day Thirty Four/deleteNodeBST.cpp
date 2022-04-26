Node *deleteNode(Node *root, int X) 
{
    if (root == NULL)
        return NULL;
        
    if (root -> data == X)
    {
        if (root -> left == NULL && root -> right == NULL)
            return NULL;
        if (root -> left == NULL)
            return root -> right;
        if (root -> right == NULL)
            return root -> left;
            
        Node* temp = root -> right;
        while (temp -> left != NULL)
            temp = temp -> left;
            
        temp -> left = root -> left;
        return root -> right;
    }
    
    if (root -> data > X)
        root -> left = deleteNode(root -> left, X);
    else
        root -> right = deleteNode(root -> right, X);
        
    return root;
}
