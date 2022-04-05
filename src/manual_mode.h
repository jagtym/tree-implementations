void load(std::vector<int> &numbers) {
    std::cout << "enter numbers (integers)" << std::endl;
    std::string input;

    std::cin.ignore();
    std::getline(std::cin, input); 

    std::istringstream is(input);
    int number;
    while(is >> number) {
        numbers.push_back(number);
    }
}

void manual_mode() {
    std::cout << "Manual mode running: " << std::endl;

    AVLTree avl_tree = AVLTree();
    BinarySearchTree bst_tree = BinarySearchTree();

    while (true) {
        std::string command;
        std::cout << "$ ";
        std::cin >> command;

        if (command == "help") {
            std::cout << "available commands: " << std::endl;
            std::cout << "load-{type}, smallest-{type}, \nbiggest-{type}, remove-keys-{type}, \ninorder-{type}, preorder-{type}, \npreorder-key-{type}, destroy-{type}, \nbalance-{type}" << std::endl;
        }
        else if (command == "load-bst") {
            std::vector<int> vec;
            load(vec);
            bst_tree.buildTree(vec);
        }
        else if (command == "load-avl") {
            std::vector<int> vec;
            load(vec);
            avl_tree.buildTree(vec);
        }
        else if (command == "smallest-bst") {
            if (bst_tree.ok()) {
                int smallest = bst_tree.getSmallestValue();
                std::cout << "smallest: " << smallest << std::endl;
                bst_tree.printSearchPath();
            }
        }
        else if (command == "smallest-avl") {
            if (avl_tree.ok()) {
                int smallest = bst_tree.getSmallestValue();
                std::cout << "smallest: " << smallest << std::endl;
                avl_tree.printSearchPath();
            }
        }
        else if (command == "biggest-bst") {
            if (bst_tree.ok()) {
                int biggest = bst_tree.getLargestValue();
                std::cout << "biggest: " << biggest << std::endl;
                bst_tree.printSearchPath();
            }
        }
        else if (command == "biggest-avl") {
            if (avl_tree.ok()) {
                int biggest = avl_tree.getSmallestValue();
                std::cout << "biggest: " << biggest << std::endl;
                avl_tree.printSearchPath();
            }
        }
        else if (command == "remove-keys-bst") {
            if (bst_tree.ok()) {
                std::vector<int> vec;
                load(vec);
                for (int x: vec) {
                    bst_tree.removeNodeFromTree(x);
                }
            }
        }
        else if (command == "remove-keys-avl") {
            if (avl_tree.ok()) {
                std::vector<int> vec;
                load(vec);
                for (int x: vec) {
                    avl_tree.removeNodeFromTree(x);
                }
            }
        }
        else if (command == "inorder-bst") {
            if (bst_tree.ok()) {
                bst_tree.printInOrder();
            }
        }
        else if (command == "inorder-avl") {
            if (avl_tree.ok()) {
                avl_tree.printInOrder();
            }
        }
        else if (command == "preorder-bst") {
            if (bst_tree.ok()) {
                bst_tree.printPreOrder();
            }
        }
        else if (command == "preorder-avl") {
            if (avl_tree.ok()) {
                avl_tree.printPreOrder();
            }
        }
        else if (command == "destroy-bst") {
            if (bst_tree.ok()) {
                bst_tree.destroyTree();
            }
        }
        else if (command == "destroy-avl") {
            if (avl_tree.ok()) {
                avl_tree.destroyTree();
            }
        }
        else if (command == "preorder-key-bst") {
            if (bst_tree.ok()) {
                int key;
                std::cout << "key: ";
                std::cin >> key;
                std::cout << std::endl;
                bst_tree.printPreOrderByKey(key);
            }
        }
        else if (command == "preorder-key-avl") {
            if (avl_tree.ok()) {
                int key;
                std::cout << "key: ";
                std::cin >> key;
                std::cout << std::endl;
                avl_tree.printPreOrderByKey(key);
            }
        }
        else if (command == "balance-bst") {
            if (bst_tree.ok()) {
                bst_tree.printPreOrder();
                bst_tree.balanceTree();
                bst_tree.printPreOrder();
            }
        }
        else if (command == "balance-avl") {
            if (avl_tree.ok()) {
                avl_tree.printPreOrder();
                avl_tree.balanceTree();
                avl_tree.printPreOrder();
            }
        }
        else if (command == "height-bst") {
            if (bst_tree.ok()) {
                bst_tree.printTreeDepth();
            }
        }
        else if (command == "height-avl") {
            if (avl_tree.ok()) {
                avl_tree.printTreeDepth();
            }
        }
        else if (command == "clear") {
            std::cout << "\033[H\033[J";   
        }
        else if (command == "exit") {
            return;
        }
        else {
            std::cout << "unknown command! " << std::endl;
        }
    }
}