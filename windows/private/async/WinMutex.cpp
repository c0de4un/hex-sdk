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
#ifndef HEX_WIN_MUTEX_HPP
#include "../../public/async/WinMutex.hpp"
#endif // !HEX_WIN_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		WinMutex::WinMutex()
			:
			mReadFlag(),
			mMutex(),
			mWritersCounter( 0 )
		{
			mReadFlag.clear();

			InitializeCriticalSection( &mMutex );
		}

		WinMutex::~WinMutex() HEX_NOEXCEPT
		{
			DeleteCriticalSection( &mMutex );
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// METHODS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		bool WinMutex::waitExclusive() HEX_NOEXCEPT
		{
			hex_uint8_t lockTriesCounter( 0 );
			while ( mReadFlag.test_and_set() )
			{
				if ( lockTriesCounter > MAX_LOCK_TRIES )
					return false;
			}

			return true;
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// GETTERS & SETTERS: IMutex
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		bool WinMutex::isLocked() const HEX_NOEXCEPT
		{
			const hex_uint8_t writersCount( mWritersCounter );
			return writersCount > 0;
		}

		void* WinMutex::native_handler() HEX_NOEXCEPT
		{ return static_cast<void*>( &mMutex ); }

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// OVERRIDE: IMutex
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void WinMutex::lock()
		{
			waitExclusive();
			mWritersCounter++;

			EnterCriticalSection( &mMutex );

			mReadFlag.test_and_set();
		}

		bool WinMutex::try_lock()
		{
			if ( isLocked() )
				return false;

			lock();

			return true;
		}

		void WinMutex::unlock() HEX_NOEXCEPT
		{
			if ( mWritersCounter > 0 )
				LeaveCriticalSection( &mMutex );

			mWritersCounter--;
		}

		void WinMutex::lock_shared()
		{
			mReadFlag.test_and_set();

			if ( isLocked() )
				EnterCriticalSection( &mMutex );
		}

		bool WinMutex::try_lock_shared()
		{
			if ( isLocked() )
				return false;

			lock_shared();

			return true;
		}

		void WinMutex::unlock_shared() HEX_NOEXCEPT
		{
			mReadFlag.clear();
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::win

} /// hex

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
