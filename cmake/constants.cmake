# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED ZERO_CMAKE_VERSION )
	set( ZERO_CMAKE_VERSION 3.20 )
endif ( NOT DEFINED ZERO_CMAKE_VERSION )

if ( NOT DEFINED PROJECT_ROOT_DIR )
	message( FATAL_ERROR "${PROJECT_NAME} - project dir is not set !" )
endif ( NOT DEFINED PROJECT_ROOT_DIR )

# C++ Version
if ( NOT DEFINED PROJECT_CXX_VERSION )
	set( PROJECT_CXX_VERSION 14 )
endif ( NOT DEFINED PROJECT_CXX_VERSION )
message( STATUS "${PROJECT_NAME} - C++ version is '${PROJECT_CXX_VERSION}'" )

# Src Dir
if ( NOT DEFINED HEX_DIR )
	set( HEX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/" )
endif ( NOT DEFINED HEX_DIR )
message( STATUS "${PROJECT_NAME} - source dir is '${HEX_DIR}'" )

# Build Mode
if ( NOT DEFINED HEX_BUILD_MODE )
	set( HEX_BUILD_MODE "static" )
	add_definitions( -DHEX_STATIC=1 )
endif ( NOT DEFINED HEX_BUILD_MODE )
message( STATUS "${PROJECT_NAME} - build mode is '${HEX_BUILD_MODE}'" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
