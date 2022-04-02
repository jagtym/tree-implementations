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

        ~Node() {
            if (val_ == parent_ -> getLeftChild() -> getValue()) {
                parent_ -> setLeftChild(nullptr);
            } else if (val_ == parent_ -> getRightChild() -> getValue()) {
                parent_ -> setRightChild(nullptr);
            } else {
                std::cout << "Node already removed!" << std::endl;
            }
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