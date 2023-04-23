cmake_minimum_required(VERSION "3.14.0")

project("CW3_Threading")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable("${PROJECT_NAME}" "Main.cpp" "fileProcessor.cpp" "longerTask.cpp" "shortTask.cpp" "taskAllocator.cpp" "fileProcessor.h" "longerTask.h" "shortTask.h" "taskAllocator.h"
"player.cpp" "player.h" "masterDraw.cpp" "masterDraw.h" "gameOn.cpp" "gameOn.h")

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

#look for SFML and add it
find_package (SFML 2.5.1 REQUIRED system window graphics network audio)

target_link_libraries(CW3_Threading PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)

#include_directories(${SFML_INCLUDE_DIR})

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "Main.cpp" DESTINATION src)

# Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
      set(GROUP "src${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
      set(GROUP "include${GROUP}")
    endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CW3_Threading)

set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)