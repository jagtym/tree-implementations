class Node {
    int val_;
    Node *left_;
    Node *right_;
    Node *parent_;


    public:
        Node(int val, Node* parent) {
            val_ = val;
            parent_ = parent;
            left_ = nullptr;
            right_ = nullptr;
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

        Node* getParent() {
            return parent_;
        }

        void setLeftChild(Node* left) {
            left_ = left;
        }

        void setRightChild(Node* right) {
            right_ = right;
        }

        void setParent(Node* parent) {
            parent_ = parent;
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

        void replaceParentChild(Node *newNode) {
            if (parent_) {
                if (this == parent_ -> getLeftChild()) {
                    parent_ -> setLeftChild(newNode);
                } else {
                    parent_ -> setRightChild(newNode);
                }
            }
        }
};