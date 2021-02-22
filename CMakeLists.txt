cmake_minimum_required(VERSION 3.0.0)
project(AutoUnitTests)

include(CPack)
enable_testing()

include_directories(include)

add_subdirectory(test)
add_subdirectory(src)
