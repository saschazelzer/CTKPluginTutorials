cmake_minimum_required(VERSION 2.8.4)

project(CTKPluginTutorials)

find_package(Qt4 REQUIRED)
find_package(CTK REQUIRED)

include(${QT_USE_FILE})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

#> Extract all library names starting with org_mydomain_
macro(GetMyTargetLibraries all_target_libraries varname)
  set(re_ctkplugin "^org_mydomain_[a-zA-Z0-9_]+$")
  set(_tmp_list)
  list(APPEND _tmp_list ${all_target_libraries})
  ctkMacroListFilter(_tmp_list re_ctkplugin OUTPUT_VARIABLE ${varname})
endmacro()
#>

#> Create a list of available plug-ins and make them known to the build system
set(plugins
  Plugins/org.mydomain.serviceeventlistener:ON
)

ctkMacroSetupPlugins(${plugins})
#>

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Apps)

