cmake_minimum_required(VERSION 3.10)

project(Handmade)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_FILES ${CMAKE_SOURCE_DIR}/src/App.h 
${CMAKE_SOURCE_DIR}/src/Audio.h
${CMAKE_SOURCE_DIR}/src/Axes.h
${CMAKE_SOURCE_DIR}/src/BoxCollider.h
${CMAKE_SOURCE_DIR}/src/Buffer.h
${CMAKE_SOURCE_DIR}/src/Camera.h
${CMAKE_SOURCE_DIR}/src/Capsule.h
${CMAKE_SOURCE_DIR}/src/Circle.h
${CMAKE_SOURCE_DIR}/src/Cuboid.h
${CMAKE_SOURCE_DIR}/src/Design.h
${CMAKE_SOURCE_DIR}/src/FreeCamera.h
${CMAKE_SOURCE_DIR}/src/Grid.h
${CMAKE_SOURCE_DIR}/src/Input.h
${CMAKE_SOURCE_DIR}/src/Light.h
${CMAKE_SOURCE_DIR}/src/Line.h
${CMAKE_SOURCE_DIR}/src/LineSegment.h
${CMAKE_SOURCE_DIR}/src/Material.h
${CMAKE_SOURCE_DIR}/src/Model.h
${CMAKE_SOURCE_DIR}/src/OBBCollider.h
${CMAKE_SOURCE_DIR}/src/Object.h
${CMAKE_SOURCE_DIR}/src/OrbitCamera.h
${CMAKE_SOURCE_DIR}/src/Plane.h
${CMAKE_SOURCE_DIR}/src/Point.h
${CMAKE_SOURCE_DIR}/src/Quad.h
${CMAKE_SOURCE_DIR}/src/Raycast.h
${CMAKE_SOURCE_DIR}/src/RigidBody.h
${CMAKE_SOURCE_DIR}/src/Screen.h
${CMAKE_SOURCE_DIR}/src/Shader.h
${CMAKE_SOURCE_DIR}/src/Sphere.h
${CMAKE_SOURCE_DIR}/src/SphereCollider.h
${CMAKE_SOURCE_DIR}/src/State.h
${CMAKE_SOURCE_DIR}/src/Text.h
${CMAKE_SOURCE_DIR}/src/Texture.h
${CMAKE_SOURCE_DIR}/src/Tile.h
${CMAKE_SOURCE_DIR}/src/Transform.h
${CMAKE_SOURCE_DIR}/src/Utility.h)

set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/App.cpp 
${CMAKE_SOURCE_DIR}/src/Audio.cpp
${CMAKE_SOURCE_DIR}/src/Axes.cpp
${CMAKE_SOURCE_DIR}/src/BoxCollider.cpp
${CMAKE_SOURCE_DIR}/src/Buffer.cpp
${CMAKE_SOURCE_DIR}/src/Camera.cpp
${CMAKE_SOURCE_DIR}/src/Capsule.cpp
${CMAKE_SOURCE_DIR}/src/Circle.cpp
${CMAKE_SOURCE_DIR}/src/Cuboid.cpp
${CMAKE_SOURCE_DIR}/src/Design.cpp
${CMAKE_SOURCE_DIR}/src/FreeCamera.cpp
${CMAKE_SOURCE_DIR}/src/Grid.cpp
${CMAKE_SOURCE_DIR}/src/Input.cpp
${CMAKE_SOURCE_DIR}/src/Light.cpp
${CMAKE_SOURCE_DIR}/src/Line.cpp
${CMAKE_SOURCE_DIR}/src/LineSegment.cpp
${CMAKE_SOURCE_DIR}/src/Main.cpp
${CMAKE_SOURCE_DIR}/src/Material.cpp
${CMAKE_SOURCE_DIR}/src/Model.cpp
${CMAKE_SOURCE_DIR}/src/OBBCollider.cpp
${CMAKE_SOURCE_DIR}/src/Object.cpp
${CMAKE_SOURCE_DIR}/src/OrbitCamera.cpp
${CMAKE_SOURCE_DIR}/src/Plane.cpp
${CMAKE_SOURCE_DIR}/src/Point.cpp
${CMAKE_SOURCE_DIR}/src/Quad.cpp
${CMAKE_SOURCE_DIR}/src/Raycast.cpp
${CMAKE_SOURCE_DIR}/src/RigidBody.cpp
${CMAKE_SOURCE_DIR}/src/Screen.cpp
${CMAKE_SOURCE_DIR}/src/Shader.cpp
${CMAKE_SOURCE_DIR}/src/Sphere.cpp
${CMAKE_SOURCE_DIR}/src/SphereCollider.cpp
${CMAKE_SOURCE_DIR}/src/Text.cpp
${CMAKE_SOURCE_DIR}/src/Texture.cpp
${CMAKE_SOURCE_DIR}/src/Tile.cpp
${CMAKE_SOURCE_DIR}/src/Transform.cpp
${CMAKE_SOURCE_DIR}/src/Utility.cpp
${CMAKE_SOURCE_DIR}/src/GLAD/gl.c
${CMAKE_SOURCE_DIR}/src/imgui/imgui.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_demo.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_draw.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_tables.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_widgets.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_opengl3.cpp
${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_sdl.cpp)

add_executable(Handmade ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/FMOD)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/FreeType)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/GLAD)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/GLM)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/imgui)
target_include_directories(Handmade PRIVATE ${CMAKE_SOURCE_DIR}/src/SDL)

target_link_libraries(Handmade 
${CMAKE_SOURCE_DIR}/lib/SDL/SDL2.lib 
${CMAKE_SOURCE_DIR}/lib/SDL/SDL2main.lib 
${CMAKE_SOURCE_DIR}/lib/SDL/SDL2_image.lib
${CMAKE_SOURCE_DIR}/lib/FMOD/fmod_vc.lib
${CMAKE_SOURCE_DIR}/lib/FMOD/fmodL_vc.lib
${CMAKE_SOURCE_DIR}/lib/FreeType/freetype.lib)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin/FMOD 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin/FreeType 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/bin/SDL 
$<TARGET_FILE_DIR:Handmade>)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets
$<TARGET_FILE_DIR:Handmade>/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Data
$<TARGET_FILE_DIR:Handmade>/Data)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Shaders
$<TARGET_FILE_DIR:Handmade>/Shaders)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Assets 
${CMAKE_BINARY_DIR}/Assets)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Data 
${CMAKE_BINARY_DIR}/Data)

add_custom_command(TARGET Handmade POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/Shaders 
${CMAKE_BINARY_DIR}/Shaders)