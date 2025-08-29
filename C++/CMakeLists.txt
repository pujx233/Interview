cmake_minimum_required(VERSION 3.10)
project(MyLeetCode)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------
#  核心配置: 在这里指定你想要编译和运行的题目文件
#  只需要修改下面这一行的文件名即可
# ------------------------------------------------------------------
set(TARGET_SOURCE "lc/lc76_minWindow.cpp")
set(TARGET_SOURCE "lc/lc240_searchMatrix.cpp")
set(TARGET_SOURCE "lc/lc129_sumNumbers.cpp")


# 根据上面指定的文件名，创建一个可执行文件
# 可执行文件的名字就是你的项目名 (MyLeetCode)
add_executable(${CMAKE_PROJECT_NAME} ${TARGET_SOURCE})

# 如果未来需要链接其他库，可以在这里添加
# target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE some_library)