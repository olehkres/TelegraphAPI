#pragma once

#include <string>
#include <vector>

#include <page.hpp>
#include <node.hpp>

namespace Telegraph
{
    class Account
    {
    private:
        std::string shortName;
        std::string authorName;
        std::string authorUrl;

        std::string accessToken;
        std::string authUrl;
        int pageCount;
        std::vector<Page> pageList;

        bool autoRemove;
    public:
        Account(const std::string& accessToken);
        Account(const std::string& shortName, const std::string& authorName,
                const std::string& authorUrl);
        ~Account();

        Page createPage(std::string title, Node::NodeElement content);

        void setAutoRemove(const bool& autoRemove);

        std::string getShortName();
        std::string getAuthorName();
        std::string getAuthorUrl();

        std::string getAccessToken();
        std::string getAuthUrl();
        int getPageCount();
        std::vector<Page> getPageList();

        void setShortName(std::string shortName);
        void setAuthorName(std::string authorName);
        void setAuthorUrl(std::string authorUrl);
    };
}

int sum(int a, int b);