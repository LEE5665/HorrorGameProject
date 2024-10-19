 /*
 * #####################################################################################
 *  Unity Vivox Plugin for Unreal Engine Copyright © 2024 Unity Technologies
 * #####################################################################################
 */

#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Delegates/Delegate.h"


namespace Moderation
{
	// THandler declaration 
#if ((ENGINE_MAJOR_VERSION == 4) && (ENGINE_MINOR_VERSION >= 26)) || (ENGINE_MAJOR_VERSION >= 5)
	template <typename T> using THandler = TDelegate<void(const T&)>;
#else
	template <typename T> using THandler = TBaseDelegate<void, const T&>;
#endif
}

