#include <QCoreApplication>
#include <QDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include <service/event/ctkEventAdmin.h>

int main(int argc, char** argv)
{
  QCoreApplication app(argc, argv);

  app.setOrganizationName("MyOrganization");
  app.setOrganizationDomain("mydomain.org");
  app.setApplicationName("UseCTKPluginMain");

  ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

  ctkPluginContext* pluginContext = ctkPluginFrameworkLauncher::getContext();
  ctkServiceReference eventAdminRef = pluginContext->getServiceReference<ctkEventAdmin>();
  ctkEventAdmin* eventAdmin = pluginContext->getService<ctkEventAdmin>(eventAdminRef);

  eventAdmin->sendEvent(ctkEvent("mydomain/tutorial/CustomEvent"));

  return 0;
}
