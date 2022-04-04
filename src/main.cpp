#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "tree-implementations/Node.h"
#include "tree-implementations/BinarySearchTree.h"

#include "testing_mode.h"
#include "manual_mode.h"
#include "debug_mode.h"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cout << "usage: TreeImplementations <mode>" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "testing") {
        std::cout << "Starting testing mode..." << std::endl;
        testing_mode();
    } else if (std::string(argv[1]) == "manual") {
        std::cout << "Starting manual mode..." << std::endl;
        manual_mode();
    } else if (std::string(argv[1]) == "debug") {
        std::cout << "Starting debug mode..." << std::endl;
        debug_mode();
    }
}