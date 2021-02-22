#include "node.hpp"

using namespace Node;

NodeElement::NodeElement()
{
}
NodeElement::NodeElement(const std::string& tag, const std::string& data)
{
    this->tag = tag;
    this->data = data;
}
NodeElement::NodeElement(const NodeElement& nodeElement)
    : NodeElement(nodeElement.tag, nodeElement.data)
{
    this->children = nodeElement.children;
}
NodeElement::~NodeElement()
{
}

void NodeElement::addChild(std::shared_ptr<NodeElement> child)
{
    this->children.push_back(child);
}

std::string NodeElement::getTag()
{
    return this->tag;
}
std::string NodeElement::getData()
{
    return this->data;
}
std::vector<std::shared_ptr<NodeElement>> NodeElement::getChildren()
{
    return this->children;
}

void NodeElement::setTag(const std::string& tag)
{
    this->tag = tag;
}
void NodeElement::setData(const std::string& data)
{
    this->data = data;
}
