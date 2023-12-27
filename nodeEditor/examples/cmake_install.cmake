# Install script for directory: C:/Users/weilong.wu/Desktop/QT/nodeeditor-master/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/QtNodesLibrary")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/simple_graph_model/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/vertical_layout/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/calculator/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/text/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/resizable_images/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/styles/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/connection_colors/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/dynamic_ports/cmake_install.cmake")
  include("C:/Users/weilong.wu/Desktop/QT/nodeEditor/examples/lock_nodes_and_connections/cmake_install.cmake")

endif()

