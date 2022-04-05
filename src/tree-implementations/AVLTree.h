class AVLTree: public BinarySearchTree {
    void assignNumbers(std::vector<int> &inputBuffer, int start, int end) {
        if (start > end) {
            return;
        }
        int mid = start + (end - start) / 2;

        addNode(inputBuffer[mid]);
        assignNumbers(inputBuffer, start, mid - 1);
        assignNumbers(inputBuffer, mid + 1, end);
    }

    public:
        virtual void buildTree(std::vector<int> &inputBuffer) {
            std::sort(inputBuffer.begin(), inputBuffer.end());
            assignNumbers(inputBuffer, 0, inputBuffer.size() - 1);
        }
};