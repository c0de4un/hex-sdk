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

#ifndef HEX_ECS_I_SYSTEM_HXX
#define HEX_ECS_I_SYSTEM_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::api
#ifndef HEX_API_HPP
#include "../../cfg/hex_api.hpp"
#endif // !HEX_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace ecs
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::ecs::ISystem
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * ISystem - system behavior contract
		 * 
		 * @version 1.0
		**/
		HEX_API class ISystem
		{

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// META
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			HEX_INTERFACE

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * ISystem destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~ISystem() HEX_NOEXCEPT = default;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Start system
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual bool Start() = 0;

			/**
			 * @brief
			 * Pause system
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual void Pause() = 0;

			/**
			 * @brief
			 * Stop system
			 * Causes resouces release
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual void Stop() = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::ecs::ISystem

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::ecs

} /// hex

using hex_ISystem = hex::ecs::ISystem;

#define HEX_ECS_I_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_ECS_I_SYSTEM_HXX
