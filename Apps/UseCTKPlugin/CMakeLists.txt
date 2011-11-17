project(UseCTKPluginMain)

set(SRCS
  UseCTKPluginMain.cpp
)

#> Include dirs
set(my_includes
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CTK_INCLUDE_DIRS} # CTK include dirs for enabled libraries
)
#>

set(my_libs
  CTKPluginFramework
)

include_directories(${my_includes})

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${my_libs})
