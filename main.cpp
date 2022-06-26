#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include <QPixmap>
#include <QSplashScreen>
#include "designer.h"
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  /*MainWindow mainWindow;
  mainWindow.show();*/
  QPixmap pixmap("images/splash.png");
  QSplashScreen splash(pixmap);
  splash.show();
  GateDesigner desg;
  desg.show();
  return app.exec();
}