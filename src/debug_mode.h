void debug_mode() {
    std::cout << "Debug mode running: " << std::endl;

    BinarySearchTree tree = BinarySearchTree();

    // Check tree add method
    tree.addNode(15);
    tree.addNode(3);
    tree.addNode(7);
    tree.addNode(19);
    tree.addNode(2);
    tree.addNode(22);
    tree.addNode(23);

    // Check duplicate adding
    tree.addNode(17);
    tree.addNode(17);
    
    // Check finding smallest and largest value

    int smallest = tree.getSmallestValue();
    std::cout << "Smallest Value: " << smallest << std::endl;
    tree.printSearchPath();

    int largest = tree.getLargestValue();
    std::cout << "Largest Value: " << largest << std::endl;
    tree.printSearchPath();

    // Check in order print
    
    std::cout << "In order: " << std::endl;
    tree.printInOrder();

    std::cout << "Pre order: " << std::endl;
    tree.printPreOrder();

    std::cout << "Post order: " << std::endl;
    tree.printPostOrder();

    // Check removing element

    std::cout << "Before removing: " << std::endl;
    tree.printInOrder();
    tree.removeNodeFromTree(3);
    std::cout << "Removed element of value 3" << std::endl;
    tree.printInOrder();

    // Check printing tree depth

    tree.printTreeDepth();

    // Check removing root element
    tree.removeNodeFromTree(15);

    // Check tree destruction
    tree.destroyTree();

    // Check if possible to print empty tree
    tree.printInOrder();
    tree.printPostOrder();
    tree.printPreOrder();

    // Check protection against empty trees

    BinarySearchTree tree2 = BinarySearchTree();
    tree2.getLargestValue();
    tree2.getSmallestValue();
    tree2.printSearchPath();

    // Check balancing the tree
    
    BinarySearchTree tree3 = BinarySearchTree();
    std::vector<int> numbers = {18, 69, 66, 42, 53, 37, 15, 23, 38, 6};
    tree3.buildTree(numbers);

    tree3.printTreeDepth();
    tree3.balanceTree();
    tree3.printTreeDepth();

    BinarySearchTree tree4 = BinarySearchTree();
    std::vector<int> loaded = {6, 3, 1, 19, 8, 5};
    tree4.buildTree(loaded);
    tree4.printInOrder();
    tree4.balanceTree();
    tree4.printTreeDepth();

    AVLTree atree = AVLTree();
    atree.buildTree(loaded);
    atree.printInOrder();
    atree.printTreeDepth();
}