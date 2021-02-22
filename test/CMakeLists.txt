project(tests)

enable_testing()

add_executable(tests
    src/main.cpp
)
target_link_libraries(tests TelegraphAPI)

add_test(NAME TestSum COMMAND "tests" "-s")
add_test(NAME TestNodeCoping COMMAND "tests" "-n")
add_test(NAME TestPageConstruction COMMAND "tests" "-p")
