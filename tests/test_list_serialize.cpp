#include <boost/test/unit_test.hpp>
#include <list_node.h>

BOOST_AUTO_TEST_CASE(list_serialize) 
{
    const std::string FIRST = "First string";
    const std::string SECOND = "Second string";
    const std::string THIRD = "Third string";



    List list;
    list.Append(FIRST);
    list.Append(SECOND);
    list.Append(THIRD);

    BOOST_CHECK_EQUAL(list.Head()->data, FIRST);
    BOOST_CHECK_EQUAL(list.Head()->next->data, SECOND);
    BOOST_CHECK_EQUAL(list.Tail()->data, THIRD);
}