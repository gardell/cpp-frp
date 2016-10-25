#include <frp/push/sink.h>
#include <frp/push/source.h>
#include <gtest/gtest.h>

TEST(source, immediate_value) {
	auto source(frp::push::source(5));
	auto sink(frp::push::sink(std::ref(source)));
	ASSERT_TRUE(source);
	ASSERT_TRUE(sink);
	ASSERT_EQ(*sink, 5);
}

TEST(source, set_value) {
	auto source(frp::push::source<int>());
	ASSERT_FALSE(source);
	auto sink(frp::push::sink(std::ref(source)));
	source = 5;
	ASSERT_TRUE(source);
	ASSERT_TRUE(sink);
	ASSERT_EQ(*sink, 5);
}

TEST(source, undefined_access) {
	auto source(frp::push::source<int>());
	ASSERT_FALSE(source);
	ASSERT_THROW(*source, std::domain_error);
	auto sink(frp::push::sink(std::ref(source)));
	ASSERT_FALSE(sink);
	ASSERT_THROW(*sink, std::domain_error);
}
