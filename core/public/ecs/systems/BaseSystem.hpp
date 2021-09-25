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

#ifndef HEX_CORE_BASE_SYSTEM_HPP
#define HEX_CORE_BASE_SYSTEM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::core::ISystem
#ifndef HEX_ECS_I_SYSTEM_HXX
#include "ISystem.hxx"
#endif // !HEX_ECS_I_SYSTEM_HXX

// Include hex::atomic
#ifndef HEX_ATOMIC_HPP
#include "../../cfg/hex_atomic.hpp"
#endif // !HEX_ATOMIC_HPP

// Include hex::numeric
#ifndef HEX_NUMERIC_HPP
#include "../../cfg/hex_numeric.hpp"
#endif // !HEX_NUMERIC_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::core::BaseSystem
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * BaseSystem - base system class
		 * 
		 * @version 1.0
		**/
		HEX_API class BaseSystem : public hex_ISystem
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
			// TYPES
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * ESystemStates
			 * 
			 * @version 1.0
			**/
			enum class ESystemStates : hex_uint8_t
			{

				// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

				// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				// CONSTANTS
				// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

				NONE     = 0,
				STARTING = 1,
				RUNNING  = 2,
				PAUSING  = 3,
				PAUSED   = 4,
				RESUMING = 5,
				STOPPING = 6,
				STOPPED  = 7

				// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			}; /// hex::core::BaseSystem::ESystemStates

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			hex_atomic<ESystemStates> mState;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * BaseSystem constructor
			 * 
			 * @throws - can throw exception
			**/
			explicit BaseSystem();

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Called to Start System
			 * 
			 * @thread_safety - atomics used
			 * @return - 'true' if OK
			 * @throws - can throw exception
			**/
			virtual bool onStart();

			/**
			* @brief
			* Called to Resume System
			* 
			* @thread_safety - atomics used
			* @return - 'true' if OK
			* @throws - can throw exception
			**/
			virtual bool onResume();

			/**
			* @brief
			* Called to Pause System
			* 
			* @thread_safety - atomics used
			* @throws - can throw exception
			**/
			virtual void onPause();

			/**
			* @brief
			* Called to Stop System
			* 
			* @thread_safety - atomics used
			* @throws - no exceptions
			**/
			virtual void onStop() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			BaseSystem( const BaseSystem& ) = delete;
			BaseSystem( BaseSystem&& )      = delete;

			BaseSystem& operator=( const BaseSystem& ) = delete;
			BaseSystem& operator=( BaseSystem&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * BaseSystem destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~BaseSystem() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS: ISystem
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Is System started
			 * 
			 * @thread_safety - atomics used
			 * @throws - no exceptions
			**/
			virtual bool isStarted() const HEX_NOEXCEPT final;

			/**
			 * @brief
			 * Is System paused
			 * 
			 * @thread_safety - atomics used
			 * @throws - no exceptions
			**/
			virtual bool isPaused() const HEX_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: ISystem
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Called when instance set as current
			 * 
			 * @thread_safety - main-thread only
			 * @throws - can throw exception
			**/
			virtual void onInitialized() override;

			/**
			 * @brief
			 * 
			 * @thread_safety - main-thread only
			 * @throws - no exceptions
			**/
			virtual void onTerminate() HEX_NOEXCEPT override;

			/**
			 * @brief
			 * Start system
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual bool Start() final;

			/**
			 * @brief
			 * Pause system
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual void Pause() final;

			/**
			 * @brief
			 * Stop system
			 * Causes resouces release
			 * 
			 * @thread_safety - thread-locks & atomics
			 * @throws - can throw exception
			**/
			virtual void Stop() final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::BaseSystem

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

using hex_BaseSystem = hex::core::BaseSystem;
#define HEX_CORE_BASE_SYSTEM_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_BASE_SYSTEM_HPP
