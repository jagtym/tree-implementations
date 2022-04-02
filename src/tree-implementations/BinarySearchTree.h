class BinarySearchTree {
    Node *root_;
    std::vector<int> path_;
    std::vector<int> value_buffer_;

    void printValueBuffer() {
        for (int x : value_buffer_) {
                std::cout << x << " ";
            }
        std::cout << std::endl;
    }

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

    Node* valueSearch(int value, Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (value == root -> getValue()) {
            return root;
        }
        if (value > root -> getValue()) {
            return valueSearch(value, root -> getRightChild());
        } 
        return valueSearch(value, root -> getLeftChild());
    }

    Node* getElementOfValue(int value) {
        return valueSearch(value, root_);
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

    void inOrder(Node *currentNode) {
        if (!currentNode) {
            return;
        }
        inOrder(currentNode -> getLeftChild());
        value_buffer_.push_back(currentNode -> getValue());
        inOrder(currentNode -> getRightChild());
    }

    void getElementsInOrder(Node *parentNode) {
        value_buffer_.clear();
        inOrder(parentNode);
    }

    void preOrder(Node *currentNode) {
        if (!currentNode) {
            return;
        }
        value_buffer_.push_back(currentNode -> getValue());
        preOrder(currentNode -> getLeftChild());
        preOrder(currentNode -> getRightChild());
    }

    void getElementsPreOrder(Node *parentNode) {
        value_buffer_.clear();
        preOrder(parentNode);
    }
    
    void postOrder(Node *currentNode) {
        if (!currentNode) {
            return;
        }
        postOrder(currentNode -> getLeftChild());
        postOrder(currentNode -> getRightChild());
        value_buffer_.push_back(currentNode -> getValue());
    }

    void getElementsPostOrder(Node *parentNode) {
        value_buffer_.clear();
        postOrder(parentNode);
    }

    void postOrderDestroy(Node *currentNode) {
        if (!currentNode) {
            return;
        }
        postOrderDestroy(currentNode -> getLeftChild());
        postOrderDestroy(currentNode -> getRightChild());
        value_buffer_.push_back(currentNode -> getValue());
        delete currentNode;
    }

    void destroyTreePostOrder(Node *parentNode) {
        value_buffer_.clear();
        postOrderDestroy(parentNode);
        std::cout << "Removed: " << std::endl;
        printValueBuffer();
        std::cout << std::endl;
    }

    void repairTreeFromBuffer() {
        // Removes the last value which is the deleted root
        value_buffer_.pop_back();

        while(!value_buffer_.empty()) {
            addNode(value_buffer_.back());
            value_buffer_.pop_back();
        }
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

        void destroyTree() {
            std::cout << "Destroying tree!" << std::endl;
            destroyTreePostOrder(root_);
            root_ = nullptr;
        }

        void printInOrder() {
            if (root_) {
                getElementsInOrder(root_);
                printValueBuffer();
            }
        }

        void printPreOrder() {
            if (root_) {
                getElementsPreOrder(root_);
                printValueBuffer();
            }
        }

        void printPostOrder() {
            if (root_) {
                getElementsPostOrder(root_);
                printValueBuffer();
            }
        }

        void removeNodeFromTree(int val) {
            Node *currentNode = getElementOfValue(val);
            if (currentNode) {
                destroyTreePostOrder(currentNode);
                repairTreeFromBuffer();
            }
        }
};