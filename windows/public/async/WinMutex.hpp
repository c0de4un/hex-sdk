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

#ifndef HEX_WIN_MUTEX_HPP
#define HEX_WIN_MUTEX_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::core::IMutex
#ifndef HEX_CORE_I_MUTEX_HXX
#include "../../../core/public/async/IMutex.hxx"
#endif // !HEX_CORE_I_MUTEX_HXX

// Include hex::atomic
#ifndef HEX_ATOMIC_HPP
#include "../../../core/public/cfg/hex_atomic.hpp"
#endif // !HEX_ATOMIC_HPP

// Include hex::numeric
#ifndef HEX_NUMERIC_HPP
#include "../../../core/public/cfg/hex_numeric.hpp"
#endif // !HEX_NUMERIC_HPP

// Include Windows API
#include <Windows.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::win::WinMutex
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * WinMutex - Mutex implementation for Windows
		 * 
		 * Base on Critical-Section from Windows API
		 * 
		 * @version 1.0
		**/
		HEX_API class WinMutex final : public hex_IMutex
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
			// TYPES
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			using win_mutex_t = CRITICAL_SECTION;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTANTS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			static constexpr const hex_uint8_t MAX_LOCK_TRIES = 255;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			hex_aflag mReadFlag;
			win_mutex_t mMutex;
			hex_atomic<hex_uint8_t> mWritersCounter;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Wait for all readers to stop
			 * 
			 * @thread_safety - atomic-flag used
			 * @return - 'true' if no readers left, 'false' if await-limit exceeded
			**/
			inline bool waitExclusive() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		protected:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			WinMutex( const WinMutex& ) = delete;
			WinMutex( WinMutex&& ) = delete;

			WinMutex& operator=( const WinMutex& ) = delete;
			WinMutex& operator=( WinMutex&& ) = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			explicit WinMutex();

			virtual ~WinMutex() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS: IMutex
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			* @brief
			* 
			* @thread_safety - 
			* @throws - no exceptions
			**/
			virtual bool isLocked() const HEX_NOEXCEPT final;

			/**
			* @brief
			* Returns native-handler
			* 
			* @thread_safety - 
			* @throws - no exceptions
			**/
			virtual void* native_handler() HEX_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: IMutex
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * 
			 * @throws - can throw exception
			**/
			virtual void lock() final;

			/**
			 * @brief
			 * 
			 * @throws - can throw exception
			**/
			virtual bool try_lock() final;

			/**
			* @brief
			 * 
			 * @throws - can throw exception
			**/
			virtual void unlock() HEX_NOEXCEPT final;

			/**
			 * @brief
			 * Lock only, if writing in on
			 * 
			 * @throws - can throw exception
			**/
			virtual void lock_shared() final;

			/**
			 * @brief
			 * Try to Lock only, if writing is on
			 * 
			 * @return - 'true' if locked, 'false'
			 * @throws - can throw exception
			**/
			virtual bool try_lock_shared() final;

			/**
			 * @brief
			 * Unlock
			 * 
			 * @throws - no exceptions
			**/
			virtual void unlock_shared() HEX_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::win::WinMutex

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::win

} /// hex

#define HEX_WIN_MUTEX_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_WIN_MUTEX_HPP
