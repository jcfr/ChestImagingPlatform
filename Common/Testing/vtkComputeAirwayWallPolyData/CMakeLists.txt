set(TEST_NAME vtkComputeAirwayWallPolyData)
project (Test_${TEST_NAME})
add_executable(Test_${TEST_NAME} test.cxx)
target_link_libraries(Test_${TEST_NAME} ${CIP_LIBRARIES})
