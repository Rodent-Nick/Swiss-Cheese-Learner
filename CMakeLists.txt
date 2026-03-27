cmake_minimum_required(VERSION 3.16)

project(swiss-cheese-learner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(unofficial-webui CONFIG REQUIRED)

add_executable(cheese)

file(GLOB SRCCXX "src/*")
file(GLOB RESC RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "res/*")

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/res.o
    COMMAND ${CMAKE_LINKER} -r -b binary -o ${CMAKE_CURRENT_BINARY_DIR}/res.o ${RESC}
    DEPENDS ${RESC}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating res.o from binary resources"
)

target_sources(cheese PRIVATE ${SRCCXX} ${CMAKE_CURRENT_BINARY_DIR}/res.o)
target_include_directories(cheese PRIVATE include)
target_link_libraries(cheese PRIVATE unofficial::webui::webui ws2_32)