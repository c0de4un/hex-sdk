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
#ifndef HEX_WIN_APP_HPP
#include "../../public/app/WinApp.hpp"
#endif // !HEX_WIN_APP_HPP

// Include hex::core::DefaultMemory
#ifndef HEX_CORE_DEFAULT_MEMORY_HPP
#include "../../../core/public/memory/DefaultMemory.hpp"
#endif // !HEX_CORE_DEFAULT_MEMORY_HPP

// Include hex::core::MemoryManager
#ifndef HEX_CORE_MEMORY_MANAGER_HPP
#include "../../../core/public/memory/MemoryManager.hpp"
#endif // !HEX_CORE_MEMORY_MANAGER_HPP

// Include hex::mutex
#ifndef HEX_MUTEX_HPP
#include "../../../core/public/cfg/hex_mutex.hpp"
#endif // !HEX_MUTEX_HPP

// Include hex::win::WinMutexFactory
#ifndef HEX_WIN_MUTEX_FACTORY_HPP
#include "../../public/async/WinMutexFactory.hpp"
#endif // !HEX_WIN_MUTEX_FACTORY_HPP

// DEBUG
#if defined( HEX_DEBUG ) || defined( DEBUG )

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../../../core/public/cfg/hex_debug.hpp"
#endif // !HEX_DEBUG_HPP

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// hex::win::WinApp
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		WinApp::WinApp()
			:
			BaseApplication()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::construct", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		WinApp::~WinApp() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::destruct", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// OVERRIDE: BaseSystem
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void WinApp::onInitialized()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onInitialized", hex_ELogLevel::INFO );
#endif // DEBUG

			// Initialize WinMutexFactory
			hex_MutexFactory::Initialize( static_cast<hex_IMutexFactory*>(new hex_WinMutexFactory()) );

			// Initialize DefaultMemory
			hex_DefaultMemory* const defaultMemory_ptr( new hex_DefaultMemory() );
			hex_IMemoryManagr* const memory_ptr( static_cast<hex_IMemoryManagr*>(defaultMemory_ptr) );
			hex_Memory::Initialize( memory_ptr );

			BaseApplication::onInitialized();
		}

		void WinApp::onTerminate() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onTerminate", hex_ELogLevel::INFO );
#endif // DEBUG

			BaseApplication::onTerminate();
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// OVERRIDE: BaseApplication
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		bool WinApp::onStart()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onStart", hex_ELogLevel::INFO );
#endif // DEBUG

			return BaseApplication::onStart();
		}

		bool WinApp::onResume()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onResume", hex_ELogLevel::INFO );
#endif // DEBUG

			return BaseApplication::onResume();
		}

		void WinApp::onPause()
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onPause", hex_ELogLevel::INFO );
#endif // DEBUG

			BaseApplication::onPause();
		}

		void WinApp::onStop() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "WinApp::onStop", hex_ELogLevel::INFO );
#endif // DEBUG

			BaseApplication::onStop();
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
