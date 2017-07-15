#include	"error.hpp"

MyError::MyError(const std::string &msg) : runtime_error(msg)
{
}

MyError::~MyError(void)
{
}

