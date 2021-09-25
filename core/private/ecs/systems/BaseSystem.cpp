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

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef HEX_CORE_BASE_SYSTEM_HPP
#include "../../../public/ecs/systems/BaseSystem.hpp"
#endif // !HEX_CORE_BASE_SYSTEM_HPP

// DEBUG
#if defined( HEX_DEBUG ) || defined( DEBUG )

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../../../public/cfg/hex_debug.hpp"
#endif // !HEX_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// hex::core::BaseSystem
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		BaseSystem::BaseSystem()
			:
			mState( ESystemStates::NONE )
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::construct", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		BaseSystem::~BaseSystem() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::destruct", hex_ELogLevel::INFO );
#endif // DEBUG

			if ( isStarted() )
				Stop();
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// GETTERS & SETTERS: ISystem
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		bool BaseSystem::isStarted() const HEX_NOEXCEPT
		{ return mState > ESystemStates::NONE && mState < ESystemStates::STOPPING; }

		bool BaseSystem::isPaused() const HEX_NOEXCEPT
		{ return mState > ESystemStates::RUNNING && mState < ESystemStates::RESUMING; }

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
		bool BaseSystem::onStart()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onStart", hex_ELogLevel::INFO );
#endif // DEBUG

			return true;
		}

		/**
		* @brief
		* Called to Resume System
		* 
		* @thread_safety - atomics used
		* @return - 'true' if OK
		* @throws - can throw exception
		**/
		bool BaseSystem::onResume()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onResume", hex_ELogLevel::INFO );
#endif // DEBUG

			return true;
		}

		/**
		* @brief
		* Called to Pause System
		* 
		* @thread_safety - atomics used
		* @throws - can throw exception
		**/
		void BaseSystem::onPause()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onPause", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		/**
		* @brief
		* Called to Stop System
		* 
		* @thread_safety - atomics used
		* @throws - no exceptions
		**/
		void BaseSystem::onStop() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onStop", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// OVERRIDE: ISystem
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void BaseSystem::onInitialized()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onInitialize", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		void BaseSystem::onTerminate() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::onTerminate", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		bool BaseSystem::Start()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::Start", hex_ELogLevel::INFO );
#endif // DEBUG

			if ( isPaused() )
				return onResume();

			if ( isStarted() )
				return true;

			return onStart();
		}

		void BaseSystem::Pause()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::Pause", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		void BaseSystem::Stop()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "BaseSystem::Stop", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
