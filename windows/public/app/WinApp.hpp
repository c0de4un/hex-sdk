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

#ifndef HEX_WIN_APP_HPP
#define HEX_WIN_APP_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::core::BaseApplication
#ifndef HEX_CORE_BASE_SYSTEM_HPP
#include "../../../core/public/app/BaseApplication.hpp"
#endif // !HEX_CORE_BASE_SYSTEM_HPP

// Include hex::core::ApplicationManager
#ifndef HEX_CORE_APPLICATION_MANAGER_HPP
#include "../../../core/public/app/ApplicationManager.hpp"
#endif // !HEX_CORE_APPLICATION_MANAGER_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::win::WinApp
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * WinApp
		 * 
		 * @version 1.0
		**/
		HEX_API class WinApp final : public hex_BaseApplication
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

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		protected:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: BaseApplication
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Called to Start System
			 * 
			 * @thread_safety - atomics used
			 * @return - 'true' if OK
			 * @throws - can throw exception
			**/
			virtual bool onStart() final;

			/**
			 * @brief
			 * Called to Resume System
			 * 
			 * @thread_safety - atomics used
			 * @return - 'true' if OK
			 * @throws - can throw exception
			**/
			virtual bool onResume() final;

			/**
			 * @brief
			 * Called to Pause System
			 * 
			 * @thread_safety - atomics used
			 * @throws - can throw exception
			**/
			virtual void onPause() final;

			/**
			 * @brief
			 * Called to Stop System
			 * 
			 * @thread_safety - atomics used
			 * @throws - no exceptions
			**/
			virtual void onStop() HEX_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			WinApp( const WinApp& ) = delete;
			WinApp( WinApp&& )      = delete;

			WinApp& operator=( const WinApp& ) = delete;
			WinApp& operator=( WinApp&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * WinApp constructor
			 * 
			 * @throws - can throw exception
			**/
			explicit WinApp();

			/**
			 * @brief
			 * WinApp destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~WinApp() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: BaseSystem
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

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::win::WinApp

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::win

} /// hex

using hex_WinApp = hex::win::WinApp;
#define HEX_WIN_APP_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_WIN_APP_HPP
