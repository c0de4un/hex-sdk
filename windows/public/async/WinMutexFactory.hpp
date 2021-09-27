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

#ifndef HEX_WIN_MUTEX_FACTORY_HPP
#define HEX_WIN_MUTEX_FACTORY_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::core::IMutexFactory
#ifndef HEX_CORE_I_MUTEX_FACTORY_HXX
#include "../../../core/public/async/IMutexFactory.hxx"
#endif // !HEX_CORE_I_MUTEX_FACTORY_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::win::WinMutexFactory
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * WinMutexFactory - mutex factory for Windows platform
		 * 
		 * @version 1.0
		**/
		HEX_API class WinMutexFactory final : public hex_IMutexFactory
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
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			WinMutexFactory( const WinMutexFactory& ) = delete;
			WinMutexFactory( WinMutexFactory&& )      = delete;

			WinMutexFactory& operator=( const WinMutexFactory& ) = delete;
			WinMutexFactory& operator=( WinMutexFactory&& )      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * WinMutexFactory
			 * 
			 * @throws - no exception
			**/
			explicit WinMutexFactory() HEX_NOEXCEPT;

			/**
			 * @brief
			 * WinMutexFactory destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~WinMutexFactory() HEX_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// OVERRIDE: IMutexFactory
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Build IMutex implementor instance
			 * 
			 * @thread_safety - not required
			 * @throws - can throw exception
			**/
			virtual hex_IMutex* Build() const final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::win::WinMutexFactory

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::win

} /// hex

using hex_WinMutexFactory = hex::win::WinMutexFactory;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_WIN_MUTEX_FACTORY_HPP
