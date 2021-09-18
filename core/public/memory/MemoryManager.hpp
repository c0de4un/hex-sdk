/**
* All rights reserved.
* License: see LICENSE.txt
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
* in the credits of the application, if such credits exist.
* The authors of this work must be notified via email (code4un@yandex.ru) in
* this case of redistribution.
* 3. Neither the name of copyright holders nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef HEX_CORE_MEMORY_MANAGER_HPP
#define HEX_CORE_MEMORY_MANAGER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::api
#ifndef HEX_CORE_API
#include "../cfg/hex_api.hpp"
#endif // !HEX_CORE_API

// Include hex::numeric
#ifndef HEX_NUMERIC_HPP
#include "../cfg/hex_numeric.hpp"
#endif // !HEX_NUMERIC_HPP

// DEBUG
#ifdef HEX_MEMORY_DEBUG

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../cfg/hex_debug.hpp"
#endif // !HEX_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-Declare hex::core::IMemoryResource
#ifndef HEX_CORE_I_MEMORY_RESOURCE_DECL
#define HEX_CORE_I_MEMORY_RESOURCE_DECL
namespace hex { namespace core { class IMemoryResource; } }
using hex_IMemoryResource = hex::core::IMemoryResource;
#endif // !HEX_CORE_I_MEMORY_RESOURCE_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::core::MemoryManager
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * MemoryManager - memory management facade
		 * 
		 * @version 1.0
		**/
		HEX_API class MemoryManager final
		{

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// META
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			HEX_CLASS

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		protected:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static MemoryManager* mInstance;

			hex_IMemoryResource* mMemoryResource;

			hex_size_t mBytesAllocated;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * MemoryManager constructor
			 * 
			 * @param pResource - IMemoryResource implementation
			 * 
			 * @throws - no exceptions
			**/
			explicit MemoryManager( hex_IMemoryResource* const pResource );

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			MemoryManager( const MemoryManager& ) = delete;
			MemoryManager( MemoryManager&& )      = delete;

			MemoryManager& operator=( const MemoryManager& ) = delete;
			MemoryManager& operator=( MemoryManager&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * MemoryManager destructor
			 * 
			 * @throws - no exceptions
			**/
			~MemoryManager() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Initialize MemoryManager
			 * 
			 * @param pResource - IMemoryResource implementation
			 * 
			 * @thread_safety - main-thread only
			 * @throws - can throw exception
			**/
			static void Initialize( hex_IMemoryResource* const pResource );

			/**
			 * @brief
			 * Terminate MemoryManager
			 * 
			 * @thread_safety - main-thread only
			 * @throws - no exceptions
			**/
			static void Terminate() HEX_NOEXCEPT;

			template <typename T>
			static T* New()
			{ return new T(); }

			template <typename T, typename... _Types>
			static T* New( _Types&&... _Args )
			{ return new T( _Args... ); }

			template <typename T>
			static void Delete( T* const pInstance )
			{ delete pInstance; }

			template <typename T = void>
			static void Delete( const T* const pInstance )
			{ delete pInstance; }

			template <typename T>
			static T* NewArray( const size_t pSize )
			{ return new T[pSize]; }

			template <typename T = void>
			static void DeleteArray( T* const pArray )
			{ delete[] pArray; }

			template <typename T = void>
			static void DeleteArray( const T* const pArray )
			{ delete[] pArray; }

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::MemoryManager

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

using hex_MemoryManager = hex::core::MemoryManager;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_MEMORY_MANAGER_HPP
