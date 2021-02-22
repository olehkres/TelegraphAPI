cmake_minimum_required(VERSION 3.0.0)
project(TelegraphAPI VERSION 0.1.0)

find_package(Boost REQUIRED)
find_package(CURL REQUIRED)

add_library(TelegraphAPI SHARED
    node.cpp
    page.cpp
    account.cpp
)

# Include cURL/cURLpp libraries
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(TelegraphAPI ${CURL_LIBRARIES})
target_link_libraries(TelegraphAPI curlpp)

# target_link_libraries(TelegraphAPI pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
