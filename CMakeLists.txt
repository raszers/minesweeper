cmake_minimum_required(VERSION 3.10)
project(Minesweeper)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all your source files
set(SOURCES
    src/Board.cpp
    src/Cell.cpp
    src/main.cpp
    src/Runner.cpp
    src/Settings.cpp
)

# Add all your header files
set(HEADERS
    include/Board.hpp
    include/Cell.hpp
    include/InputMode.hpp
    include/Result.hpp
    include/Runner.hpp
    include/Settings.hpp
)

# Include directories
include_directories(include)

# Create executable
add_executable(mines ${SOURCES} ${HEADERS})

install(TARGETS mines DESTINATION bin)
