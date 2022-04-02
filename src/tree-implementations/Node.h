class Node {
    int val_;
    Node *left_;
    Node *right_;

    Node(int val) {
        val_ = val;
    }

    public:
        int getValue() {
            return val_;
        }

        Node* getLeftChild() {
            return left_;
        }

        Node* getRightChild() {
            return right_;
        }

        Node* setLeftChild(Node* left) {
            left_ = left;
        }

        Node* setRightChild(Node* right) {
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