#include <boost/test/unit_test.hpp>
#include <lib_init/Dummy.hpp>

using namespace lib_init;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    lib_init::DummyClass dummy;
    dummy.welcome();
}
