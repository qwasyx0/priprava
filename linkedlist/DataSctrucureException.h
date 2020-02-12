#ifndef _DATASTRUCTUREEXCEPTION_H
#define _DATASTRUCTUREEXCEPTION_H

#include <exception>
#include <string>
class DataStructureException : public std::exception
{
	std::string m_error;
public:
	DataStructureException(std::string error)
		: m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); } // C++11 version
};

#endif
