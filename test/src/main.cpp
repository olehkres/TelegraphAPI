#include <iostream>
#include <memory>

#include "account.hpp"
#include "page.hpp"
#include "node.hpp"

enum COMMANDS
{
    TEST_SUM = 's',
    TEST_NODE_COPING = 'n',
    TEST_PAGE_CONSTRUCTION = 'p'
};

int main(int argc, char** argv)
{
    switch ((*(argv+1))[1])
    // switch(TEST_PAGE_CONSTRUCTION)
    {
    case TEST_SUM:
    {
        if (sum(2, 3) != 5)
            return 1;
        break;
    }
    case TEST_NODE_COPING:
    {
        try
        {
            Node::NodeElement* nodeElementOne = new Node::NodeElement("p", "some data");
            nodeElementOne->addChild(std::make_shared<Node::NodeElement>("a", "some data"));
            Node::NodeElement* nodeElementTwo = new Node::NodeElement(*nodeElementOne);
            delete nodeElementOne;
            if (nodeElementTwo->getChildren()[0]->getTag() != "a")
                return 1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        break;
    }
    case TEST_PAGE_CONSTRUCTION:
    {
        Telegraph::Page page("Sample-Page-12-15");
        return 1;
    }
    default:
        std::cout << (*(argv+1))[1] << '\n';
        return 1;
    }

    return 0;
}
