class Node {
    int val_;
    Node *left_;
    Node *right_;
    Node *parent_;

    public:
        Node(int val, Node* parent) {
            val_ = val;
            parent_ = parent;
        }

        int getValue() {
            return val_;
        }

        Node* getLeftChild() {
            return left_;
        }

        Node* getRightChild() {
            return right_;
        }

        void setLeftChild(Node* left) {
            left_ = left;
        }

        void setRightChild(Node* right) {
            right_ = right;
        }

        bool isLeftEmpty() {
            if (!left_) {
                return true;
            }
            return false;
        }
        
        bool isRightEmpty() {
            if (!right_) {
                return true;
            }
            return false;
        }
};