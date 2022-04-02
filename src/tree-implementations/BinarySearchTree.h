class BinarySearchTree {
    Node *root_;
    std::vector<int> path_;

    void assignNode(int value) {
        Node *current_node = root_;
        bool found_place = false;

        while (!found_place) {
            if (value > current_node -> getValue()) {
                if (current_node -> isRightEmpty()) {
                    current_node -> setRightChild(new Node(value, current_node));
                    found_place = true;
                } else {
                    current_node = current_node -> getRightChild();
                }
            } else if (value < current_node -> getValue()) {
                if (current_node -> isLeftEmpty()) {
                    current_node -> setLeftChild(new Node(value, current_node));
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
        path_.clear();
        Node *current_node = root_;
        while(!current_node -> isLeftEmpty()) {
            path_.push_back(current_node -> getValue());
            current_node = current_node -> getLeftChild();
        }
        return current_node;
    }

    Node* getRightmostElement() {
        path_.clear();
        Node *current_node = root_;
        while(!current_node -> isRightEmpty()) {
            path_.push_back(current_node -> getValue());
            current_node = current_node -> getRightChild();
        }
        return current_node;
    }
    
    public:
        void addNode(int value) {
            if (!root_) {
                root_ = new Node(value, nullptr);
            } else {
                assignNode(value);
            }
        }

        int getSmallestValue() {
            if (root_) {
                return getLeftmostElement() -> getValue();
            }
            std::cout << "Tree has no root element. Returning -1" << std::endl;
            return -1; 
        }

        int getLargestValue() {
            if (root_) {
                return getRightmostElement() -> getValue();
            }
            std::cout << "Tree has no root element. Returning -1" << std::endl;
            return -1; 
        }

        void printSearchPath() {
            std::cout << "path: ";
            for (int x: path_) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
};