#include "page.hpp"

#include <iostream>
#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace Telegraph;

Page::Page(const std::string& path, const std::string& accessToken)
{
    std::string apiMethod("/getPage/");

    std::stringstream url;
    url << "https://" << HOST << apiMethod << path << "?access_token=" << accessToken;

    std::stringstream responce;
    curlpp::Easy request;
    request.setOpt(new curlpp::options::WriteStream(&responce));

    request.setOpt<curlpp::options::Url>(url.str());
    request.perform();

    boost::property_tree::ptree tree;
    boost::property_tree::json_parser::read_json(responce, tree);

    // If responce status ok then setup variables
    if(tree.get<bool>("ok"))
    {
        this->path = path;

        if(accessToken.empty())
            this->canEdit = false;
        else
            this->canEdit = true;

        this->url = tree.get<std::string>("result.url");
        this->title = tree.get_optional<std::string>("result.title").is_initialized()
            ? tree.get<std::string>("result.title") : "";
        this->description = tree.get_optional<std::string>("result.description").is_initialized()
            ? tree.get<std::string>("result.description") : "";
        this->authorName = tree.get_optional<std::string>("result.author_name").is_initialized()
            ? tree.get<std::string>("result.author_name") : "";
        this->authorUrl = tree.get_optional<std::string>("result.author_url").is_initialized()
            ? tree.get<std::string>("result.author_url") : "";
        this->imageUrl = tree.get_optional<std::string>("result.image_url").is_initialized()
            ? tree.get<std::string>("result.image_url") : "";
        this->views = tree.get<int>("result.views");
    }
}
Page::Page(const std::string& accessToken, const std::string& title,
           const Node::NodeElement& content)
{
}
Page::~Page()
{

}
