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

#ifndef HEX_CORE_DEFAULT_MEMORY_HPP
#define HEX_CORE_DEFAULT_MEMORY_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::core::IMemoryManager
#ifndef HEX_CORE_I_MEMORY_MANAGER_HXX
#include "IMemoryManager.hxx"
#endif // !HEX_CORE_I_MEMORY_MANAGER_HXX

// Include hex::mutex
#ifndef HEX_MUTEX_HPP
#include "../cfg/hex_mutex.hpp"
#endif // !HEX_MUTEX_HPP

// Include hex::vector
#ifndef HEX_VECTOR_HPP
#include "../cfg/hex_vector.hpp"
#endif // !HEX_VECTOR_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD-DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-Declare hex::core::MemoryBlock
#ifndef HEX_CORE_MEMORY_BLOCK_DECL
#define HEX_CORE_MEMORY_BLOCK_DECL
namespace hex { namespace core { class MemoryBlock; } }
using hex_MemoryBlock = hex::core::MemoryBlock;
#endif // !HEX_CORE_MEMORY_BLOCK_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::core::DefaultMemory
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * DefaultMemory - simple base memory manager
		 * 
		 * @version 1.0
		**/
		HEX_API class DefaultMemory final : public hex_IMemoryManagr
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

			hex_IMutex* mMutex;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			DefaultMemory( const DefaultMemory& ) = delete;
			DefaultMemory( DefaultMemory&& )      = delete;

			DefaultMemory& operator=( const DefaultMemory& ) = delete;
			DefaultMemory& operator=( DefaultMemory&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * DefaultMemory constructor
			 * 
			 * @throws - can throw exception
			**/
			explicit DefaultMemory();

			/**
			 * @brief
			 * DefaultMemory destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~DefaultMemory() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: IMemoryManager
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Called to add reference to Object
			 * 
			 * @param pAddress - Object address
			 * @param pBytes - Object length in bytes
			 * 
			 * @throws - can throw exception
			 * @thread_safety - thread-locks used
			**/
			virtual void onReference( void* const pAddress, const hex_size_t pBytes ) final;

			/**
			 * @brief
			 * Called to remove reference to Object
			 * 
			 * @throws - can throw exception
			 * @thread_safety - thread-locks used
			**/
			virtual void onUnreference( void* const pAddress, const hex_size_t pBytes ) final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::DefaultMemory

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

using hex_DefaultMemory = hex::core::DefaultMemory;

#define HEX_CORE_DEFAULT_MEMORY_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_DEFAULT_MEMORY_HPP
