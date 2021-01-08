set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cc)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_run PUBLIC fmt::fmt)
target_link_libraries(${BINARY}_run PUBLIC spdlog::spdlog)

target_link_libraries(${BINARY}_lib PUBLIC fmt::fmt)
target_link_libraries(${BINARY}_lib PUBLIC spdlog::spdlog)

target_compile_options(${BINARY}_run PRIVATE 
        -Wall -Wextra -Wpedantic
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wcast-align
        -Wunused
        -Wconversion
        -Wsign-conversion
        -Wmisleading-indentation
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2
    )