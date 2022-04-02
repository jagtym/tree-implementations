void debug_mode() {
    std::cout << "Debug mode running: " << std::endl;

    BinarySearchTree tree = BinarySearchTree();

    tree.addNode(15);
    tree.addNode(3);
    tree.addNode(7);
    tree.addNode(19);

    int smallest = tree.getSmallestValue();
    std::cout << "Smallest Value: " << smallest << std::endl;

    int largest = tree.getLargestValue();
    std::cout << "Largest Value: " << largest << std::endl;
}