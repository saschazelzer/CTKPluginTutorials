PROJECT(UseCTKPluginMain)

SET(SRCS
  UseCTKPluginMain.cpp
)

#> Include dirs
SET(my_includes
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CTK_INCLUDE_DIRS} # CTK include dirs for enabled libraries
)
#>

SET(my_libs
  CTKPluginFramework
)

INCLUDE_DIRECTORIES(${my_includes})

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${my_libs})
