#ifndef __LEGENDRE_EXCEPTIONS_H__
#define __LEGENDRE_EXCEPTIONS_H__

#include <string>
#include <stdexcept>

namespace LegendreException
{
	class InvalidIndex : public std::runtime_error
	{
	public:
		explicit InvalidIndex() : std::runtime_error("ERROR - Invalid Index")
		{
		}

		explicit InvalidIndex(std::string const& msg) : std::runtime_error("ERROR - Invalid Index: " + msg)
		{		
		}
	};

	class InputOutOfRange : public std::runtime_error
	{
	public:
		explicit InputOutOfRange() : std::runtime_error("ERROR - Input is out of range. Can only evaluate values in the range -1 <= x <= 1")
		{
		}
	};
}


#endif
