#define BOOST_TEST_MODULE Parsim
#include <boost/test/included/unit_test.hpp>

#include "parsimus.h"
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <sstream>


using namespace std;


BOOST_AUTO_TEST_CASE( primitive )
{
    {
      int result;
      BOOST_REQUIRE(parsimus::parse("123", result));
      BOOST_CHECK_EQUAL(result, 123);
    }

    {
      int result;
      BOOST_REQUIRE(parsimus::parse("123", result));
      BOOST_CHECK_EQUAL(result, 123);
    }

  {
      std::string result;
      BOOST_REQUIRE(parsimus::parse("'\u00F6'", result));
      BOOST_CHECK(result == "\u00F6");
    }

    /*{
      std::wstring result;
      BOOST_REQUIRE(parsimus::parse(L"'Hello'", result));
      BOOST_CHECK_EQUAL(result, "Hello");
    }*/
    {
      long result;
      string number;
      
      stringstream strstream;
      strstream << LONG_MAX;
      strstream >> number;
      BOOST_CHECK(parsimus::parse(number, result));
      BOOST_CHECK_EQUAL(result, LONG_MAX);
    }

    {
      unsigned long result;
      string number;
      
      stringstream strstream;
      strstream << ULONG_MAX;
      strstream >> number;
      BOOST_CHECK(parsimus::parse(number, result));
      BOOST_CHECK_EQUAL(result, ULONG_MAX);
    }    

    {
      double result;
      BOOST_CHECK(parsimus::parse("123.1", result));
      BOOST_CHECK_EQUAL(result, 123.1);
    }
    // Fails
    {
      int result;
      parsimus::parse_error err;
      BOOST_REQUIRE(!parsimus::parse("123.4", result, &err));
      BOOST_CHECK_EQUAL(err.tag, "eoi");
      BOOST_CHECK_EQUAL(err.found, ".4");
    }

}


/*BOOST_AUTO_TEST_CASE( lists )
{
    {
      std::vector<int> result;
      BOOST_REQUIRE(parsimus::parse("[1,2,3]", result));
      BOOST_REQUIRE(result.size() == 3);
      BOOST_CHECK_EQUAL(result[0], 1);
      BOOST_CHECK_EQUAL(result[1], 2);
      BOOST_CHECK_EQUAL(result[2], 3);
    }

    {
      std::vector<int> result;
      parsimus::parseerror err;
      BOOST_REQUIRE(!parsimus::parse("[1,2,3", result, &err));
      BOOST_CHECK_EQUAL(err.tag, "] or )");
      BOOST_CHECK_EQUAL(err.found, "");        
    }  
}


BOOST_AUTO_TEST_CASE( maps )
{
    {
      std::map<int,string> result;
      BOOST_REQUIRE(parsimus::parse("{1:'hello', 2:'world'}", result));
      BOOST_REQUIRE(result.size() == 2);
      BOOST_REQUIRE_EQUAL(result.count(1), 1);
      BOOST_REQUIRE_EQUAL(result.count(2), 1);
      
      BOOST_CHECK_EQUAL(result[1], "hello");
      BOOST_CHECK_EQUAL(result[2], "world");
    }

    {
      std::map<int, vector<string> > result;
      BOOST_REQUIRE(parsimus::parse("{1:['hello','world'], 2:['red']}", result));
      BOOST_REQUIRE(result.size() == 2);
      BOOST_REQUIRE_EQUAL(result.count(1), 1);
      BOOST_REQUIRE_EQUAL(result.count(2), 1);

      BOOST_REQUIRE_EQUAL(result[1].size(), 2);
      BOOST_REQUIRE_EQUAL(result[2].size(), 1);
      
      BOOST_CHECK_EQUAL(result[1][0], "hello");
      BOOST_CHECK_EQUAL(result[1][1], "world");
      BOOST_CHECK_EQUAL(result[2][0], "red");
    }    

    {
      std::map<int,string> result;
      parsimus::parseerror err;
      BOOST_REQUIRE(!parsimus::parse("{1:'hello', 2:, 3:'world'}", result, &err));
      BOOST_CHECK_EQUAL(err.tag, "string");
      BOOST_CHECK_EQUAL(err.found, ", 3:'world'}");      
    }
}*/
