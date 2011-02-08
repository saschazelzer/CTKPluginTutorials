SET(APPS
  UseCTKPlugin
)

FOREACH(app ${APPS})
  OPTION(APP_${app} "Build the ${app} application" ON)
  ADD_SUBDIRECTORY(${app})
ENDFOREACH()
