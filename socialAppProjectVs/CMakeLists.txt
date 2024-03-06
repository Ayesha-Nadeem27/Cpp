cmake_minimum_required(VERSION 3.10)
project(socialAppProjectVs)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(socialAppProjectVs src/main.cpp src/user.cpp src/post.cpp src/admin.cpp src/userManager.cpp src/postManager.cpp src/instagramConsole.cpp)
