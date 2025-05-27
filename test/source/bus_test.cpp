#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <Bus.hpp>
#include <IBusClient.hpp>

class MockClient : public Tricore::IBusClient {

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

    main_bus.register_device(sample_client);
    auto request_handler = main_bus.create_request_handler();

    EXPECT_NO_THROW(request_handler.read(gsl::make_span(buffer), 0xABBADEDE));
}
