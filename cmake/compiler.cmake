# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# COMPILER
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# C++ Version
set( CMAKE_CXX_STANDARD ${PROJECT_CXX_VERSION} )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

# Flags
if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
    set( CMAKE_CXX_FLAGS "-fexceptions -fcxx-exceptions" ${CMAKE_CXX_FLAGS} )
endif ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )

# Enable Position Independent Code
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# Tests
if ( HEX_TESTS_ENABLED )
    enable_testing()
endif ( HEX_TESTS_ENABLED )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_COMPILER_SET ON )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
