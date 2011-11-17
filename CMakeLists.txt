CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(CTKPluginTutorials)

FIND_PACKAGE(Qt4 REQUIRED)
FIND_PACKAGE(CTK REQUIRED)

INCLUDE(${QT_USE_FILE})

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

#> Extract all library names starting with org_mydomain_
MACRO(GetMyTargetLibraries all_target_libraries varname)
  SET(re_ctkplugin "^org_mydomain_[a-zA-Z0-9_]+$")
  SET(_tmp_list)
  LIST(APPEND _tmp_list ${all_target_libraries})
  ctkMacroListFilter(_tmp_list re_ctkplugin OUTPUT_VARIABLE ${varname})
ENDMACRO()
#>

SET(plugins
  Plugins/org.mydomain.serviceeventlistener:ON
)

ctkMacroSetupPlugins(${plugins})

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/Apps)

