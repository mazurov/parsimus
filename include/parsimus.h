#ifndef PASRSIMUS_INCLUDE_PARSIMUS_H
#define PASRSIMUS_INCLUDE_PARSIMUS_H 1

#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

namespace parsimus {

  struct parse_error {
    int pos;
    std::string tag;
    std::string found;
  };

#define PARSERS_DECL_FOR_SINGLE(Type)\
    bool parse(const std::string& input, Type& result, \
      parse_error* err = NULL)

#define PARSERS_DECL_FOR_VECTOR(InnerType)\
    bool parse(const std::string& input,\
      std::vector<InnerType>& result,\
      parse_error* err = NULL)


  PARSERS_DECL_FOR_SINGLE(bool);
  PARSERS_DECL_FOR_SINGLE(char);
  PARSERS_DECL_FOR_SINGLE(unsigned char);
  PARSERS_DECL_FOR_SINGLE(signed char);
  PARSERS_DECL_FOR_SINGLE(int);
  PARSERS_DECL_FOR_SINGLE(short);
  PARSERS_DECL_FOR_SINGLE(unsigned short);
  PARSERS_DECL_FOR_SINGLE(unsigned int);
  PARSERS_DECL_FOR_SINGLE(long);
  PARSERS_DECL_FOR_SINGLE(unsigned long);
  PARSERS_DECL_FOR_SINGLE(long long);
  PARSERS_DECL_FOR_SINGLE(unsigned long long);

  PARSERS_DECL_FOR_SINGLE(double);
  PARSERS_DECL_FOR_SINGLE(float);
  PARSERS_DECL_FOR_SINGLE(long double);

  PARSERS_DECL_FOR_SINGLE(std::string);

  PARSERS_DECL_FOR_VECTOR(bool);
  PARSERS_DECL_FOR_VECTOR(char);
  PARSERS_DECL_FOR_VECTOR(unsigned char);
  PARSERS_DECL_FOR_VECTOR(signed char);

  PARSERS_DECL_FOR_VECTOR(int);
  PARSERS_DECL_FOR_VECTOR(short);
  PARSERS_DECL_FOR_VECTOR(unsigned short);
  PARSERS_DECL_FOR_VECTOR(unsigned int);
  PARSERS_DECL_FOR_VECTOR(long);
  PARSERS_DECL_FOR_VECTOR(unsigned long);
  PARSERS_DECL_FOR_VECTOR(long long);
  PARSERS_DECL_FOR_VECTOR(unsigned long long);

  PARSERS_DECL_FOR_VECTOR(double);
  PARSERS_DECL_FOR_VECTOR(float);
  PARSERS_DECL_FOR_VECTOR(long double);

  PARSERS_DECL_FOR_VECTOR(std::string);  
}


#endif