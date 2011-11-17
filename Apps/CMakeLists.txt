set(APPS
  UseCTKPlugin
)

foreach(app ${APPS})
  option(BUILD_APP_${app} "Build the ${app} application" ON)
  add_subdirectory(${app})
endforeach()
