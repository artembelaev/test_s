#include <string.h>
#include <boost/test/unit_test.hpp>
#include <remove_dups.h>

BOOST_AUTO_TEST_CASE(remove_dups)
{
    char * zero_length = "";
    RemoveDups(zero_length);
    BOOST_CHECK(strcmp(zero_length, "") == 0);

    char data[] = "AAA BBB   AAA";
    RemoveDups(data);
    BOOST_CHECK(strcmp(data, "A B A") == 0);
}