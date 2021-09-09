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

#ifndef HEX_CORE_I_LOG_HXX
#define HEX_CORE_I_LOG_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include hex::cpre::ELogLevel
#ifndef HEX_CORE_E_LOG_LEVEL_HPP
#include "ELogLevel.hpp"
#endif // !HEX_CORE_E_LOG_LEVEL_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// hex::core::ILog
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/**
		 * @brief
		 * ILog - log contract
		 * 
		 * @version 1.0
		**/
		HEX_API class ILog
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
			 * ILog destructor
			 * 
			 * @throws - no exceptions
			**/
			virtual ~ILog() HEX_NOEXCEPT = default;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/**
			 * @brief
			 * Print log-message
			 * 
			 * @param pMessage - message in c-string
			 * @param pLevel - log-level @see hex::core::ELogLevel
			 * 
			 * @throws - can throw exception
			**/
			virtual void onPrint( const char* const pMessage, const hex_ELogLevel pLevel ) = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// hex::core::ILog

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// hex::core

} /// hex

using hex_ILog = hex::core::ILog;
#define HEX_CORE_I_LOG_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_CORE_I_LOG_HXX
