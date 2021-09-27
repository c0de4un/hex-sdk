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
#ifndef HEX_CORE_DEFAULT_MEMORY_HPP
#include "../../public/memory/DefaultMemory.hpp"
#endif // !HEX_CORE_DEFAULT_MEMORY_HPP

// DEBUG
#ifdef HEX_DEBUG

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../../public/cfg/hex_debug.hpp"
#endif

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// hex::core::DefaultMemory
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		DefaultMemory::DefaultMemory()
			:
			mMutex( hex_MutexFactory::Build() )
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "DefaultMemory::construct", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		DefaultMemory::~DefaultMemory() HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_Log::Print( "DefaultMemory::construct", hex_ELogLevel::INFO );
#endif // DEBUG
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// OVERRIDE: IMemoryManager
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void DefaultMemory::onReference( void* const pAddress, const hex_size_t pBytes )
		{

		}

		void DefaultMemory::onUnreference( void* const pAddress, const hex_size_t pBytes )
		{

		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
