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

#ifndef HEX_CORE_SHARED_POINTER_HPP
#define HEX_CORE_SHARED_POINTER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::api
#ifndef HEX_API_HPP
#include "../cfg/hex_api.hpp"
#endif // !HEX_API_HPP

// Include hex::core::MemoryManager
#ifndef HEX_CORE_MEMORY_MANAGER_HPP
#include "../memory/MemoryManager.hpp"
#endif // !HEX_CORE_MEMORY_MANAGER_HPP

// DEBUG
#ifdef HEX_DEBUG

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../cfg/hex_debug.hpp"
#endif // !HEX_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::core::SharedPointer
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * SharedPointer - simple shared pointer implementation
		 * 
		 * @version 1.0
		**/
		template <typename T>
		HEX_API class SharedPointer final
		{

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// META
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			HEX_CLASS

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static constexpr const hex_size_t LENGTH = sizeof(T);

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			T* mAddress;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTORS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * SharedPointer constructor
			 * 
			 * @param pAddress - address for pointer
			 * 
			 * @throws - can throw exception
			**/
			explicit SharedPointer( T* const pAddress = nullptr )
				: mAddress( pAddress )
			{
				if ( mAddress )
					hex_Memory::addReference( mAddress, LENGTH );
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * SharedPointer destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~SharedPointer() HEX_NOEXCEPT
			{
				if ( mAddress )
					hex_Memory::removeReference( mAddress, LENGTH );
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Reset pointer
			 * 
			 * @throws - can throw exception
			**/
			T* Reset( T* const pAddress = nullptr )
			{
#ifdef HEX_MEMORY_DEBUG // DEBUG
#endif // DEBUG
				T* const output( mAddress );

				if ( mAddress )
					hex_Memory::removeReference( mAddress, LENGTH );

				mAddress = pAddress;

				return output;
			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OPERATORS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::SharedPointer

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

template <typename T>
using hex_SharedPointer = hex::core::SharedPointer<T>;

#define HEX_CORE_SHARED_POINTER_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_SHARED_POINTER_HPP
