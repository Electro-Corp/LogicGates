#ifndef ABOUT_H
#define ABOUT_H
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
  class Ui_Dialog;
}
 
class Ui_Dialog : public QDialog
{
  Q_OBJECT
public:
	explicit Ui_Dialog(QDialog *Dialog = nullptr);
	QLabel *label;
    QLabel *label_2;
private slots:

private:
  
};
#endif