#include "Kokoro/EventPipeline.hh"

#include "Kokoro/EventPipeline/EventPipeline.hh"

#include <gtest/gtest.h>

class TestEvent : public Kokoro::BaseEvent
{
public:
    void Execute(std::vector<void*> pData) override
    {
        auto number = GetDataValue<0, uint32_t*>(pData);
        auto string = GetDataValue<1, const char*>(pData);

        ASSERT_EQ(*number, 42);
        ASSERT_EQ(string, "Hello World!");

        *number = 13;
    }

private:
    ImplementEventStuff(TestEvent);
};

RegisterEvent(TestEvent);

TEST(EventPipeline, Execute)
{
    Kokoro::EventPipeline eventPipeline;

    uint32_t iVal = 42;
    const char* szString = "Hello World!";

    eventPipeline.Execute("TestEvent", &iVal, szString);

    ASSERT_EQ(iVal, 13);
}
