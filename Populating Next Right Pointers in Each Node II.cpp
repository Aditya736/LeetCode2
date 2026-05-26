class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL)
            return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                Node* curr = q.front();
                q.pop();

                // next pointer set karo
                if(i < size - 1)
                    curr->next = q.front();
                else
                    curr->next = NULL;

                // children push karo
                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
};