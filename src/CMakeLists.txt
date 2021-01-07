set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_run PUBLIC ${CMAKE_PROJECT_NAME}_lib fmt::fmt)
target_link_libraries(${BINARY}_run PUBLIC ${CMAKE_PROJECT_NAME}_lib spdlog::spdlog)

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
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wnull-dereference
        -Wuseless-cast
        -Wdouble-promotion
        -Wformat=2
    )