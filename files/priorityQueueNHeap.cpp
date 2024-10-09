Node* findInsertionNode() {

    Node* curr = lastInsert;

    // Step 1: Traverse up until a left child or the root is reached
    while (curr->parent && curr == curr->parent->rChild) {
        curr = curr->parent;
    }

    // Step 2: If a left child is reached, go to the right child
    if (curr->parent && curr == curr->parent->lChild) {
        curr = curr->parent->rChild;
    }

    // Step 3: Go down the left until a leaf is reached
    while (curr->lChild) {
        curr = current->lChild;
    }

    return curr;
}
