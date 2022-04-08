int get_random_in_range(int start, int end) {
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(start, end);
    return distr(gen);
}

void generate(std::vector<int> &numbers, int size) {
    for (int i = 0; i < size; i++) {
        int random = get_random_in_range(1, size * 10);
        if (!std::count(numbers.begin(), numbers.end(), random)) {
            // std::cout << random << " ";
            numbers.push_back(random);
        } else {
            i--;
        }
    }
    // std::cout << std::endl;
}

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
            auto start = std::chrono::high_resolution_clock::now();
            bst_tree.buildTree(vec);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "time: " << duration.count() << std::endl;
        }
        else if (command == "generate-bst") {
            std::vector<int> vec;
            int size;
            std::cout << "size: ";
            std::cin >> size;
            std::cout << std::endl;
            generate(vec, size);
            auto start = std::chrono::high_resolution_clock::now();
            bst_tree.buildTree(vec);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "time: " << duration.count() << std::endl;
        }
        else if (command == "generate-avl") {
            std::vector<int> vec;
            int size;
            std::cout << "size: ";
            std::cin >> size;
            std::cout << std::endl;
            generate(vec, size);
            auto start = std::chrono::high_resolution_clock::now();
            avl_tree.buildTree(vec);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "time: " << duration.count() << std::endl;
        }
        else if (command == "load-avl") {
            std::vector<int> vec;
            load(vec);
            auto start = std::chrono::high_resolution_clock::now();
            avl_tree.buildTree(vec);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "time: " << duration.count() << std::endl;
        }
        else if (command == "smallest-bst") {
            if (bst_tree.ok()) {
                auto start = std::chrono::high_resolution_clock::now();
                int smallest = bst_tree.getSmallestValue();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "smallest: " << smallest << std::endl;
                bst_tree.printSearchPath();
                std::cout << "time: " << duration.count() << std::endl;
            }
        }
        else if (command == "smallest-avl") {
            if (avl_tree.ok()) {
                int smallest = avl_tree.getSmallestValue();
                std::cout << "smallest: " << smallest << std::endl;
                avl_tree.printSearchPath();
            }
        }
        else if (command == "biggest-bst") {
            if (bst_tree.ok()) {
                auto start = std::chrono::high_resolution_clock::now();
                int biggest = bst_tree.getLargestValue();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "biggest: " << biggest << std::endl;
                bst_tree.printSearchPath();
                std::cout << "time: " << duration.count() << std::endl;
            }
        }
        else if (command == "biggest-avl") {
            if (avl_tree.ok()) {
                int biggest = avl_tree.getLargestValue();
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
                auto start = std::chrono::high_resolution_clock::now();
                bst_tree.printInOrder();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "time: " << duration.count() << std::endl;
            }
        }
        else if (command == "inorder-avl") {
            if (avl_tree.ok()) {
                auto start = std::chrono::high_resolution_clock::now();
                avl_tree.printInOrder();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                std::cout << "time: " << duration.count() << std::endl;
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
                try {
                    std::cin >> key;
                    std::cout << std::endl;
                    bst_tree.printPreOrderByKey(key);
                } catch (...) {
                    std::cout << "error when entering number!" << std::endl;
                }
            }
        }
        else if (command == "preorder-key-avl") {
            if (avl_tree.ok()) {
                int key;
                std::cout << "key: ";
                try {
                    std::cin >> key;
                    std::cout << std::endl;
                    avl_tree.printPreOrderByKey(key);
                } catch (...) {
                    std::cout << "error when entering number!" << std::endl;
                }
            }
        }
        else if (command == "balance-bst") {
            if (bst_tree.ok()) {
                // bst_tree.printPreOrder();
                auto start = std::chrono::high_resolution_clock::now();
                bst_tree.balanceTree();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                // bst_tree.printPreOrder();
                std::cout << "time: " << duration.count() << std::endl;
            }
        }
        else if (command == "balance-avl") {
            if (avl_tree.ok()) {
                // avl_tree.printPreOrder();
                auto start = std::chrono::high_resolution_clock::now();
                avl_tree.balanceTree();
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
                // avl_tree.printPreOrder();
                std::cout << "time: " << duration.count() << std::endl;
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
