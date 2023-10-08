#include <boost/test/unit_test.hpp>
#include <dec_to_bin.h>

BOOST_AUTO_TEST_CASE(dec_to_bin) 
{
    BOOST_CHECK_EQUAL(DecToBin(0), "0");
    BOOST_CHECK_EQUAL(DecToBin(1), "1");
    BOOST_CHECK_EQUAL(DecToBin(1024), "10000000000");
    BOOST_CHECK_EQUAL(DecToBin(-1024), "11111111111111111111110000000000");
}