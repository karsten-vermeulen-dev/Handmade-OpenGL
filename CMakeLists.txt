cmake_minimum_required(VERSION 3.10)

project(Handmade)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_FILES ${CMAKE_SOURCE_DIR}/src/Background.h 
${CMAKE_SOURCE_DIR}/src/BoxCollider.h


set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/Background.cpp 
${CMAKE_SOURCE_DIR}/src/BoxCollider.cpp


add_executable(Handmade ${SOURCE_FILES} ${INCLUDE_FILES})


target_link_libraries(Handmade 
${CMAKE_SOURCE_DIR}/lib/SDL2.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2main.lib 
${CMAKE_SOURCE_DIR}/lib/SDL2_image.lib)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets
$<TARGET_FILE_DIR:Handmade>/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets 
${CMAKE_BINARY_DIR}/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Data
$<TARGET_FILE_DIR:Handmade>/Data)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Data 
${CMAKE_BINARY_DIR}/Data)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Shaders
$<TARGET_FILE_DIR:Handmade>/Shaders)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Shaders 
${CMAKE_BINARY_DIR}/Shaders)