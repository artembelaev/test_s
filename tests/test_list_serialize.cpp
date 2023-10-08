#include <boost/test/unit_test.hpp>
#include <list_node.h>

const std::string FIRST = "First string";
const std::string SECOND = "Second string";
const std::string THIRD = "Third string";

void Fill(List & list)
{
    auto first = list.Append(FIRST);
    auto second = list.Append(SECOND);
    auto third = list.Append(THIRD);

    first->rand = third;
    third->rand = first;
}

BOOST_AUTO_TEST_CASE(list_fill)
{
    List list;
   
    Fill(list);
    BOOST_CHECK_EQUAL(list.Head()->data, FIRST);
    BOOST_CHECK_EQUAL(list.Head()->next->data, SECOND);
    BOOST_CHECK_EQUAL(list.Tail()->data, THIRD);

    char * path = "serialized_list.bin";

    BOOST_CHECK(list.Head() != nullptr);
    BOOST_CHECK_EQUAL(list.Head()->rand, list.Tail());
    BOOST_CHECK_EQUAL(list.Tail()->rand, list.Head());
    BOOST_CHECK_EQUAL(list.Head()->next->rand, nullptr);
}

BOOST_AUTO_TEST_CASE(list_serialize_deserialize)
{
    List out_list;
    Fill(out_list);

    char * path = "serialized_list.bin";

    // Serialize

    FILE * out_file = fopen(path, "wb");
    BOOST_CHECK(out_file != nullptr);
    out_list.Serialize(out_file);
    fclose(out_file);

    // Deserialize

    List in_list;
    FILE * in_file = fopen("serialized_list.bin", "rb");
    BOOST_CHECK(in_file != nullptr);
    in_list.Deserialize(in_file);
    fclose(in_file);

    // Check equals

    BOOST_CHECK_EQUAL(in_list.Count(), 3);
    BOOST_CHECK_EQUAL(in_list.Count(), out_list.Count());
    BOOST_CHECK_EQUAL(in_list.Head()->data, out_list.Head()->data);
    BOOST_CHECK_EQUAL(in_list.Head()->next->data, out_list.Head()->next->data);
    BOOST_CHECK_EQUAL(in_list.Tail()->data, out_list.Tail()->data);

    BOOST_CHECK_EQUAL(in_list.Head()->rand, in_list.Tail());
    BOOST_CHECK_EQUAL(in_list.Tail()->rand, in_list.Head());
    BOOST_CHECK_EQUAL(in_list.Head()->next->rand, nullptr);
}