include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB tests_src ./*.cpp)
include_directories(../src)

add_executable(tests ${sources};${tests_src})

target_link_libraries(
  tests
  GTest::gtest_main
)
target_link_libraries(raytracing  )

include(GoogleTest)
gtest_discover_tests(tests)
