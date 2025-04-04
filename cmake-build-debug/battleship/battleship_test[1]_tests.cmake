add_test([=[SOLVER_TEST.BasicAssertions]=]  /Users/snead/documents/cpp_one_assignments/cmake-build-debug/battleship/battleship_test [==[--gtest_filter=SOLVER_TEST.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[SOLVER_TEST.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /Users/snead/documents/cpp_one_assignments/cmake-build-debug/battleship SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  battleship_test_TESTS SOLVER_TEST.BasicAssertions)
