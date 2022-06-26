#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCore/QVariant> 
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QPushButton>
#include <QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QCheckBox>
#include <QLCDNumber>
#include <QGroupBox>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
	QAction *actionAbout_this_program;
	QAction *actionOpen_Designer;
	QWidget *centralwidget;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLCDNumber *lcdNumber_2;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_5;
    QLCDNumber *lcdNumber_3;
	QPushButton *and_gate;
	QPushButton *or_gate;
	QPushButton *not_gate;
    QMenuBar *menuBar;
    QMenu *menuAbout;
	QStatusBar *statusbar;
	QMenu *menuFinished_Open_Designer;
private slots:
  void andgate();
  void orgate();
  void notgate();
  void about();
private:
  QPushButton *m_button;
};
#endif // MAINWINDOW_H
