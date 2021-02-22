#pragma once

#include <string>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "node.hpp"

namespace Telegraph
{
    class Page
    {
    private:
        const char* HOST = "api.telegra.ph";
        const char* PORT = "80";

        curlpp::Cleanup cleanup;

        std::string path;
        std::string url;

        bool canEdit;

        std::string title;
        std::string description;
        std::string authorName;
        std::string authorUrl;
        std::string imageUrl;
        Node::NodeElement content;

        int views;

        std::string accessToken;
    public:
        Page(const std::string& path, const std::string& accessToken = "");
        Page(const std::string& accessToken, const std::string& title,
             const Node::NodeElement& content);
        ~Page();

        int getViewsByDate(const int& year, const int& month, const int& day, const int& hour);

        std::string getPath();
        std::string getUrl();

        bool isEditable();

        std::string getTitle();
        std::string getDescription();
        std::string getAuthorName();
        std::string getAuthorUrl();
        std::string getImageUrl();
        Node::NodeElement getContent();

        void setTitle(const std::string& title);
        void setDescription(const std::string& description);
        void setAuthorName(const std::string& authorName);
        void setAuthorUrl(const std::string& authorUrl);
        void setImageUrl(const std::string& imageUrl);
        void setContent(const Node::NodeElement& content);
    };
}
