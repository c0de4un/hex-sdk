# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#
# @about
# hexSDK - interactive applications developments framework & tools
#
# @license
# see LICENSE file
#
# @requirements
# - C++ 14+;
# - OpenGL 3+;
# - SSE 3+;
#
# @build
# - MSVC, GCC & Clang are supported;
#
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "cmake/constants.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake-Version
cmake_minimum_required( VERSION ${HEX_CMAKE_VERSION} FATAL_ERROR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "hexSDK" )

# Project Version
set( PROJECT_VERSION 0.1.1 )

# Project Description
set( PROJECT_DESCRIPTION "interactive applications developments framework & tools" )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# Include Compiler Config
if ( NOT DEFINED HEX_COMPILER_SET )
    include( "cmake/compiler.cmake" )
endif ( NOT DEFINED HEX_COMPILER_SET )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# hexEngine.Core
add_subdirectory( "${HEX_DIR}core" )

# hexEngine.{Platform}
if ( HEX_WINDOWS ) # WINDOWS
    add_subdirectory( "${HEX_DIR}windows" )
elseif ( HEX_ANDROID ) # ANDROID
    add_subdirectory( "${HEX_DIR}android" )
elseif ( HEX_LINUX ) # LINUX
    add_subdirectory( "${HEX_DIR}linux" )
else ( HEX_WINDOWS )
    message( FATAL_ERROR "${PROJECT_NAME} - undefined platform, configuration required" )
endif ( HEX_WINDOWS )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
