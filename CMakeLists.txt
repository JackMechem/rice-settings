cmake_minimum_required(VERSION 3.29)
project(rice-settings VERSION 1.0.0)

# yes I use neovim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
find_package(yaml-cpp REQUIRED)

include_directories(${YAML_CPP_INCLUDE_DIRS})

include(${wxWidgets_USE_FILE})

add_executable(rice-settings main.cpp main.h configFile.cpp configFile.h)

target_link_libraries(rice-settings ${wxWidgets_LIBRARIES}
                      ${YAML_CPP_LIBRARIES})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

  # Install bin
  install(TARGETS ${PROJECT_NAME} DESTINATION bin)

  # Install desktop entry
  install(FILES data/Rice\ Settings.desktop DESTINATION /usr/share/applications)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
