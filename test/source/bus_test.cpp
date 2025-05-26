#include <gmock/gmock.h>
#include <gsl/span_ext>
#include <gtest/gtest.h>

#include <Bus.hpp>
#include <BusClient.hpp>

class MockClient : public Tricore::BusClient {

public:
    MOCK_METHOD(void, read, (gsl::span<byte>, u32), (override));
    MOCK_METHOD(void, write, (gsl::span<const byte>, u32), (override));
};

class BusTestFixture : public ::testing::Test {

protected:
    Tricore::Bus main_bus;
};

TEST_F(BusTestFixture, RegisterClient)
{
    MockClient sample_client {};
    byte buffer[] = { 8, 9, 10, 11 };

    EXPECT_CALL(sample_client, read(::testing::_, 0xABBADEDE)).Times(1);

    {
        auto handler = main_bus.register_device(sample_client);
        main_bus.read(gsl::make_span(buffer), 0xABBADEDE);

        // destructor called, device is unregistered
    }

    // this will thr
    EXPECT_ANY_THROW(main_bus.read(gsl::make_span(buffer), 0xABBADEDE));
}
