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

#ifndef HEX_PLATFORM_HPP
#define HEX_PLATFORM_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef HEX_PLATFORM_DEFINED

	#if defined( MINGW ) || defined( MINGW32 ) || defined( MINGW64 ) || defined( WIN ) || defined( WIN32 ) || defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN64 ) || defined( WINDOWS ) || defined( MSVC ) || defined( MSVC64 )

		// WINDOWS
		#define HEX_WINDOWS

	#elif defined( ANDROID ) || defined( _android_ ) || defined( __android__ ) || defined( _android ) || defined( __android )

		// ANDROID
		#define HEX_ANDROID

	#elif defined( __linux ) || defined( _linux ) || defined( _linux_ ) || defined( __linux__ ) || defined( LINUX )

		// LINUX
		#define HEX_LINUX

	#else
		#error "hex_platform.hpp - configuration required"
	#endif

#endif

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !HEX_PLATFORM_HPP
