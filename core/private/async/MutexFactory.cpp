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
#ifndef HEX_CORE_MUTEX_FACTORY_HPP
#include "../../public/async/MutexFactory.hpp"
#endif // !HEX_CORE_MUTEX_FACTORY_HPP

// Include hex::core::IMutexFactory
#ifndef HEX_CORE_I_MUTEX_FACTORY_HXX
#include "../../public/async/IMutexFactory.hxx"
#endif // !HEX_CORE_I_MUTEX_FACTORY_HXX

// Include hex::core::IMutex
#ifndef HEX_CORE_I_MUTEX_HXX
#include "../../public/async/IMutex.hxx"
#endif // !HEX_CORE_I_MUTEX_HXX

// DEBUG
#ifdef HEX_DEBUG

// Include hex::debug
#ifndef HEX_DEBUG_HPP
#include "../../public/cfg/hex_debug.hpp"
#endif

#endif
// DEBUG

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// hex::core::MutexFactory
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace hex
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// FIELDS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		IMutexFactory* MutexFactory::mInstance( nullptr );

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		MutexFactory::MutexFactory() HEX_NOEXCEPT  = default;

		MutexFactory::~MutexFactory() HEX_NOEXCEPT = default;

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// GETTERS & SETTERS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		hex_IMutexFactory* MutexFactory::getInstance() HEX_NOEXCEPT
		{ return mInstance; }

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// METHODS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void MutexFactory::Initialize( hex_IMutexFactory* const pInstance ) HEX_NOEXCEPT
		{
#ifdef HEX_DEBUG // DEBUG
			hex_assert( !mInstance && "MutexFactory::Initialize: instance is already set !" );
#endif // DEBUG

			mInstance = pInstance;
		}

		void MutexFactory::Terminate() HEX_NOEXCEPT
		{
			delete mInstance;
			mInstance = nullptr;
		}

		hex_IMutex* MutexFactory::Build()
		{ return mInstance->Build(); }

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
