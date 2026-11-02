#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>


#include <filesystem>
#include <string>
#include "../src/index.hpp"


TEST_CASE("Text Benchmarks") {
    BENCHMARK("1k test") {
        Index index;
        return(index.readFile("../Texts/1k.txt"));
    };
    BENCHMARK("2k test") {
        Index index;
        return(index.readFile("../Texts/2k.txt"));
    };
    BENCHMARK("3k test") {
        Index index;
        return(index.readFile("../Texts/3k.txt"));
    };
    BENCHMARK("5k test") {
        Index index;
        return(index.readFile("../Texts/5k.txt"));
    };
    BENCHMARK("10k test") {
        Index index;
        return(index.readFile("../Texts/10k.txt"));
    };
    BENCHMARK("15k test") {
        Index index;
        return(index.readFile("../Texts/15k.txt"));
    };
    BENCHMARK("20k test") {
        Index index;
        return(index.readFile("../Texts/20k.txt"));
    };

}
