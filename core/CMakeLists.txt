# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_CORE_DIR "${HEX_DIR}core/" )
set( HEX_CORE_PUBLIC "${HEX_CORE_DIR}public/" )
set( HEX_CORE_PRIVATE "${HEX_CORE_DIR}private/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake-Version
cmake_minimum_required( VERSION ${HEX_CMAKE_VERSION} FATAL_ERROR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "hexEngine.Core" )

# Project Version
set( PROJECT_VERSION 0.1.1 )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_CORE_HEADERS 
	# CONFIGS
	"${HEX_CORE_PUBLIC}cfg/hex_api.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_assert.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_atomic.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_debug.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_memory.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_numeric.hpp"
	"${HEX_CORE_PUBLIC}cfg/hex_platform.hpp"
	# APPLICATION
	"${HEX_CORE_PUBLIC}app/IApplication.hxx"
	"${HEX_CORE_PUBLIC}app/BaseApplication.hpp"
	"${HEX_CORE_PUBLIC}app/ApplicationManager.hpp"
	# ECS
	"${HEX_CORE_PUBLIC}ecs/systems/ISystem.hxx"
	# MEMORY
	"${HEX_CORE_PUBLIC}memory/IAllocator.hxx"
	"${HEX_CORE_PUBLIC}memory/Allocator.hpp"
	"${HEX_CORE_PUBLIC}memory/IMemoryManager.hxx"
	"${HEX_CORE_PUBLIC}memory/MemoryManager.hpp"
	"${HEX_CORE_PUBLIC}memory/IMemoryResource.hxx"
	"${HEX_CORE_PUBLIC}memory/MemoryResource.hpp"
	"${HEX_CORE_PUBLIC}memory/MemoryBlock.hpp"
	"${HEX_CORE_PUBLIC}memory/SharedPointer.hpp"
	# ASYNC
	"${HEX_CORE_PUBLIC}async/IMutex.hxx"
	"${HEX_CORE_PUBLIC}async/IMutexFactory.hxx"
	"${HEX_CORE_PUBLIC}async/MutexFactory.hpp"
	# RENDER
	# LOGIC
	# ASSETS
	# PHYSICS
	# AUDIO
	# INPUT
	# GAME
	"${HEX_CORE_PUBLIC}game/Game.hpp"
	# ENGINE
	"${HEX_CORE_PUBLIC}engine/IEngine.hxx"
	"${HEX_CORE_PUBLIC}engine/Engine.hpp" )

# DEBUG
if ( HEX_DEBUG )
	set( HEX_CORE_HEADERS ${HEX_CORE_HEADERS} 
		"${HEX_CORE_PUBLIC}metrics/ELogLevel.hpp"
		"${HEX_CORE_PUBLIC}metrics/ILog.hxx"
		"${HEX_CORE_PUBLIC}metrics/Log.hpp" )
endif ( HEX_DEBUG )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( HEX_CORE_SOURCES 
	# APPLICATION
	"${HEX_CORE_PRIVATE}app/BaseApplication.cpp"
	"${HEX_CORE_PRIVATE}app/ApplicationManager.cpp"
	# MEMORY
	"${HEX_CORE_PRIVATE}memory/Allocator.cpp"
	"${HEX_CORE_PRIVATE}memory/MemoryManager.cpp"
	"${HEX_CORE_PRIVATE}memory/MemoryResource.cpp"
	"${HEX_CORE_PRIVATE}memory/MemoryBlock.cpp"
	"${HEX_CORE_PRIVATE}memory/SharedPointer.cpp"
	# ASYNC
	"${HEX_CORE_PRIVATE}async/MutexFactory.cpp"
	# RENDER
	# LOGIC
	# ASSETS
	# PHYSICS
	# AUDIO
	# INPUT
	# METRICS
	# GAME
	"${HEX_CORE_PRIVATE}game/Game.cpp"
	# ENGINE
	"${HEX_CORE_PRIVATE}engine/Engine.cpp" )

# DEBUG
if ( HEX_DEBUG )
	set( HEX_CORE_SOURCES ${HEX_CORE_SOURCES} 
		"${HEX_CORE_PRIVATE}metrics/Log.cpp" )
endif ( HEX_DEBUG )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Create STATIC-Library Object
add_library( hexEngine_Core_Lib STATIC ${HEX_CORE_HEADERS} ${HEX_CORE_SOURCES} )

# Configure Library Object
set_target_properties( hexEngine_Core_Lib PROPERTIES
    LIBRARY_OUTPUT_NAME "${PROJECT_NAME}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
