# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_WIN_DIR "${HEX_DIR}windows/" )
set( HEX_WIN_PUBLIC "${HEX_WIN_DIR}public/" )
set( HEX_WIN_PRIVATE "${HEX_WIN_DIR}private/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake-Version
cmake_minimum_required( VERSION ${HEX_CMAKE_VERSION} FATAL_ERROR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "hexEngine.Windows" )

# Project Version
set( PROJECT_VERSION 0.1.1 )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_WIN_HEADERS "" )

# DEBUG
if ( HEX_DEBUG )
	set( HEX_WIN_HEADERS ${HEX_WIN_HEADERS} 
		"${HEX_WIN_PUBLIC}metrics/WinLog.hpp" )
endif ( HEX_DEBUG )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_WIN_SOURCES "" )

# DEBUG
if ( HEX_DEBUG )
	set( HEX_WIN_SOURCES ${HEX_WIN_SOURCES} 
		"${HEX_WIN_PRIVATE}metrics/WinLog.cpp" )
endif ( HEX_DEBUG )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Create STATIC-Library Object
add_library( hexEngine_Windows_Lib STATIC ${HEX_WIN_HEADERS} ${HEX_WIN_SOURCES} )

# Configure Library Object
set_target_properties( hexEngine_Windows_Lib PROPERTIES
    LIBRARY_OUTPUT_NAME "${PROJECT_NAME}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
