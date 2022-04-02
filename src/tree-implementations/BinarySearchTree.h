class BinarySearchTree {
    Node *root_;

    void assignNode(int value) {
        Node *current_node = root_;
        bool found_place = false;

        while (!found_place) {
            if (value > current_node -> getValue()) {
                if (current_node -> isRightEmpty()) {
                    current_node -> setRightChild(new Node(value));
                    found_place = true;
                } else {
                    current_node = current_node -> getRightChild();
                }
            } else if (value < current_node -> getValue()) {
                if (current_node -> isLeftEmpty()) {
                    current_node -> setLeftChild(new Node(value));
                    found_place = true;
                } else {
                    current_node = current_node -> getLeftChild();
                }
            } else {
                std::cout << "(" << value << ") - " << "Value already in tree!" << std::endl;
                break;
            }
        }
    }

    Node* getLeftmostElement() {
        Node *current_node = root_;
        while(!current_node -> isLeftEmpty()) {
            current_node = current_node -> getLeftChild();
        }
        return current_node;
    }

    Node* getRightmostElement() {
        Node *current_node = root_;
        while(!current_node -> isRightEmpty()) {
            current_node = current_node -> getRightChild();
        }
        return current_node;
    }
    
    public:
        void addNode(int value) {
            if (!root_) {
                root_ = new Node(value);
            } else {
                assignNode(value);
            }
        }

        int getSmallestValue() {
            return getLeftmostElement() -> getValue();
        }

        int getLargestValue() {
            return getRightmostElement() -> getValue();
        }
    
};