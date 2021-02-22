#pragma once

#include <string>
#include <vector>
#include <memory>

namespace Node
{
    class NodeElement
    {
    private:
        std::string tag;
        std::string data;
        std::vector<std::shared_ptr<NodeElement>> children;
    public:
        NodeElement();
        NodeElement(const std::string& tag, const std::string& data);
        NodeElement(const NodeElement& nodeElement);
        ~NodeElement();

        void addChild(std::shared_ptr<NodeElement> child);

        std::string getTag();
        std::string getData();
        std::vector<std::shared_ptr<NodeElement>> getChildren();

        void setTag(const std::string& tag);
        void setData(const std::string& data);
    };
}
