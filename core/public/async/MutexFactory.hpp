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

#ifndef HEX_CORE_MUTEX_FACTORY_HPP
#define HEX_CORE_MUTEX_FACTORY_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::api
#ifndef HEX_API_HPP
#include "../cfg/hex_api.hpp"
#endif // !HEX_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// FORWARD_DECLARATIONS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Forward-Declare hex::core::IMutexFactory
#ifndef HEX_CORE_I_MUTEX_FACTORY_DECL
#define HEX_CORE_I_MUTEX_FACTORY_DECL
namespace hex { namespace core { class IMutexFactory; } }
using hex_IMutexFactory = hex::core::IMutexFactory;
#endif // !HEX_CORE_I_MUTEX_FACTORY_DECL

// Forward-Declare hex::core::IMutex
#ifndef HEX_CORE_I_MUTEX_DECL
#define HEX_CORE_I_MUTEX_DECL
namespace hex { namespace core { class IMutex; } }
using hex_IMutex = hex::core::IMutex;
#endif // !HEX_CORE_I_MUTEX_DECL

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * MutexFactory - facade-factory for platform-specific mutex
		 * 
		 * @version 1.0
		**/
		HEX_API class MutexFactory final
		{

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// META
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			HEX_CLASS

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static hex_IMutexFactory* mInstance;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			explicit MutexFactory() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			MutexFactory( const MutexFactory& ) = delete;
			MutexFactory(MutexFactory&&)        = delete;

			MutexFactory& operator=( const MutexFactory& ) = delete;
			MutexFactory& operator=( MutexFactory&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			~MutexFactory() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Returns IMutexFactory instance
			 * 
			 * @thread_safety - not required
			 * @throws - no exceptions
			**/
			static hex_IMutexFactory* getInstance() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Initialize IMutexFactory instance
			 * 
			 * @thread_safety - main-thread only
			 * @throws - no exceptions
			**/
			static void Initialize( hex_IMutexFactory* const pInstance ) HEX_NOEXCEPT;

			/**
			 * Terminate IMutexFactory instance
			 * 
			 * @thred_sfaty - main-thread only
			 * @throws - no exceptions
			**/
			static void Terminate() HEX_NOEXCEPT;

			/**
			 * @brief
			 * Build IMutex implementator-instance
			 * 
			 * @thread_safety - not required
			 * @throws - can throw exception
			**/
			static hex_IMutex* Build();

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::MutexFactory

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

using hex_MutexFactory = hex::core::MutexFactory;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_MUTEX_FACTORY_HPP
