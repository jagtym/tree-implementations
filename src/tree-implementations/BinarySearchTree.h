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

    Node* getLeftmostElement(Node *root) {
        path_.clear();
        Node *current_node = root;
        while(!current_node -> isLeftEmpty()) {
            path_.push_back(current_node -> getValue());
            current_node = current_node -> getLeftChild();
        }
        return current_node;
    }

    Node* getRightmostElement(Node *root) {
        path_.clear();
        Node *current_node = root;
        while(!current_node -> isRightEmpty()) {
            path_.push_back(current_node -> getValue());
            current_node = current_node -> getRightChild();
        }
        return current_node;
    }

    int getTreeDepth(Node *root) {
        if (!root) {
            return -1;
        }
        int leftDepth = getTreeDepth(root -> getLeftChild());
        int rightDepth = getTreeDepth(root -> getRightChild());

        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        }
        return rightDepth + 1;
    }

    Node* getNeighbour(Node* node) {
        inOrder(root_);
        std::vector<int>::iterator i = std::find(value_buffer_.begin(), value_buffer_.end(), node -> getValue());
        int position = std::distance(value_buffer_.begin(), i);

        return getElementOfValue(value_buffer_[position + 1]);
    }

    void removeNode(Node *removedNode) {
        bool leftEmpty = removedNode -> isLeftEmpty();
        bool rightEmpty = removedNode -> isRightEmpty();

        if (leftEmpty && rightEmpty) {
            removedNode -> replaceParentChild(nullptr);
        } else if (!leftEmpty && rightEmpty) {
            if (removedNode -> getParent()) {
                removedNode -> replaceParentChild(removedNode -> getLeftChild());
            } else {
                root_ = removedNode -> getLeftChild();
                root_ -> setParent(nullptr);
            }
        } else if (!rightEmpty && leftEmpty) {
            if (removedNode -> getParent()) {
                removedNode -> replaceParentChild(removedNode -> getRightChild());
            } else {
                root_ = removedNode -> getRightChild();
                root_ -> setParent(nullptr);
            }
        } else {
            Node *newParent = getNeighbour(removedNode);
            int newParentValue = newParent -> getValue();
            removeNode(newParent);

            Node *leftChild = removedNode -> getLeftChild();
            Node *rightChild = removedNode -> getRightChild();
            newParent = new Node(newParentValue, removedNode -> getParent());

            if (leftChild) {
                leftChild -> setParent(newParent);
            }
            if (rightChild) {
                rightChild -> setParent(newParent);
            }
            newParent -> setLeftChild(leftChild);
            newParent -> setRightChild(rightChild);
            removedNode -> replaceParentChild(newParent);

            if (removedNode == root_) {
                root_ = newParent;
            }
        }
        delete removedNode;
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

    bool balanceTreeBFS() {
        std::queue<Node*> nodeQueue;
        nodeQueue.push(root_);
        bool balanced = true;

        while(!nodeQueue.empty()) {
            Node *current = nodeQueue.front();
            Node *left = current -> getLeftChild();
            Node *right = current -> getRightChild();

            int leftHeight = getTreeDepth(left) + 1;
            int rightHeight = getTreeDepth(right) + 1;

            if (abs(leftHeight - rightHeight) > 1) {
                int val = current -> getValue();
                removeNode(current);
                assignNode(val);
                balanced = false;
                break;
            }

            if (left) {
                nodeQueue.push(left);
            }
            if (right) {
                nodeQueue.push(right);
            }
            nodeQueue.pop();
        }
        return balanced;
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
                return getLeftmostElement(root_) -> getValue();
            }
            std::cout << "Tree has no root element. Returning -1" << std::endl;
            return -1; 
        }

        int getLargestValue() {
            if (root_) {
                return getRightmostElement(root_) -> getValue();
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

        void printPreOrderByKey(int key) {
            Node *current = getElementOfValue(key);
            if (current) {
                getElementsPreOrder(current);
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
                removeNode(currentNode);
            }
        }

        void printTreeDepth() {
            std::cout << "Tree depth: " << getTreeDepth(root_) << std::endl;
        }

        void balanceTree() {
            bool balanced = false;
            while (!balanced) {
                balanced = balanceTreeBFS();
            }
        }

        bool ok() {
            if (getTreeDepth(root_) < 0) {
                return false;
            }
            return true;
        }

        virtual void buildTree(std::vector<int> &inputBuffer) {
            for (int x: inputBuffer) {
                addNode(x);
            }
        }
};