#ifndef CLNT_GPRH_ERROR_HPP
#define CLNT_GPRH_ERROR_HPP

# include <stdexcept>

class		MyError : public std::runtime_error
{
public:
  MyError(const std::string &);
  virtual ~MyError(void);
};

#endif /* !CLNT_GPRH_ERROR_HPP_ */
