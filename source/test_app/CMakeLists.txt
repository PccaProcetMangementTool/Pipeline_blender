
project(app_test)
set(Core_DIR "${PROJECT_BINARY_DIR}/../Core")
message(STATUS "Core_Path ist ${Core_Path}")
find_package(Core)
add_executable(App_Test test_app.cpp)
target_link_libraries(App_Test 
$<BUILD_INTERFACE:Core::Core>)