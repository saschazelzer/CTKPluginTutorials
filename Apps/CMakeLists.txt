SET(APPS
  UseCTKPlugin
)

FOREACH(app ${APPS})
  OPTION(BUILD_APP_${app} "Build the ${app} application" ON)
  ADD_SUBDIRECTORY(${app})
ENDFOREACH()
