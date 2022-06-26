#include "mainwindow.h"
//#include "about.h"
#include <QtCore/QVariant> 
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QPushButton>
#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <memory>
#include <stdexcept>
#include <array>
#include <QMessageBox>
#include <QCheckBox>
#include <QMenuBar>
#include <QLCDNumber>
#include <QWizardPage>
#include <QDialog>
#include <QGroupBox>
#include <QtWidgets/QAction>
#include <QWizard>
#include <QVBoxLayout>
#define WINDOW_WIDTH 630
#define WINDOW_HEIGHT 206
using namespace std;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
	if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainWindow"));
        this->resize(630, 206);
        this->setCursor(QCursor(Qt::PointingHandCursor));
		//this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		//this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
        centralwidget = new QWidget(this);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		actionAbout_this_program = new QAction(this);
        actionAbout_this_program->setObjectName(QString::fromUtf8("actionAbout_this_program"));
		actionOpen_Designer = new QAction(this);
        actionOpen_Designer->setObjectName(QString::fromUtf8("actionOpen_Designer"));    
		groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 241, 151));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 30, 90, 22));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 60, 90, 22));
        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
		lcdNumber->setDigitCount(1);
        lcdNumber->setGeometry(QRect(130, 32, 101, 111));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(250, 10, 241, 151));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 30, 90, 22));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 60, 90, 22));
        lcdNumber_2 = new QLCDNumber(groupBox_2);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(130, 32, 101, 111));
		lcdNumber_2->setDigitCount(1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(500, 10, 101, 151));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 30, 90, 22));
        lcdNumber_3 = new QLCDNumber(groupBox_3);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
		lcdNumber_3->setGeometry(QRect(10, 60, 71, 41));
		lcdNumber_3->setDigitCount(1);
		//menubar
		
        statusbar = new QStatusBar(this);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
		menuBar = new QMenuBar(this);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 21));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
		menuFinished_Open_Designer = new QMenu(menuBar);
        menuFinished_Open_Designer->setObjectName(QString::fromUtf8("menuFinished_Open_Designer"));
        this->setMenuBar(menuBar);

		menuBar->addAction(menuAbout->menuAction());
        menuBar->addAction(menuFinished_Open_Designer->menuAction());
        menuAbout->addAction(actionAbout_this_program);
        menuFinished_Open_Designer->addAction(actionOpen_Designer);

		//buttons
		not_gate = new QPushButton(groupBox_3);
        not_gate->setObjectName(QString::fromUtf8("not_gate"));
        not_gate->setGeometry(QRect(10, 120, 81, 24));
		or_gate = new QPushButton(groupBox_2);
        or_gate->setObjectName(QString::fromUtf8("or_gate"));
        or_gate->setGeometry(QRect(0, 120, 81, 24));
		and_gate = new QPushButton(groupBox);
        and_gate->setObjectName(QString::fromUtf8("and_gate"));
        and_gate->setGeometry(QRect(10, 120, 81, 24));
		//
        this->setCentralWidget(centralwidget);
		//connect buttons
		connect(and_gate, SIGNAL(clicked()), this, SLOT(andgate()));
		connect(or_gate, SIGNAL(clicked()), this, SLOT(orgate()));
		connect(not_gate, SIGNAL(clicked()), this, SLOT(notgate()));
		connect(actionAbout_this_program, SIGNAL(triggered()), this, SLOT(about()));
		//connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(play()));
		//connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(play()));
		this->setStatusBar(statusbar);
		//text
		
		this->setWindowTitle(QCoreApplication::translate("MainWindow", "Logic Gates", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "And Gate", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Bit 1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Bit 2", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Or Gate", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Bit 1", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Bit 2", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Not Gate", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Bit 1", nullptr));
		and_gate->setText(QCoreApplication::translate("MainWindow", "Calculate ->", nullptr));
		or_gate->setText(QCoreApplication::translate("MainWindow", "Calculate ->", nullptr));
		not_gate->setText(QCoreApplication::translate("MainWindow", "Calculate ->", nullptr));
		actionAbout_this_program->setText(QCoreApplication::translate("MainWindow", "About this program...", nullptr));
		menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
		menuFinished_Open_Designer->setTitle(QCoreApplication::translate("MainWindow", "Finished? Open Designer", nullptr));
}

void MainWindow::andgate(){
	if(checkBox->isChecked() && checkBox_2->isChecked()){
	lcdNumber->display(1);
	}else{
		lcdNumber->display(0);
	}
};

void MainWindow::orgate(){
	if(checkBox_3->isChecked() || checkBox_4->isChecked()){
	lcdNumber_2->display(1);
	}else{
		lcdNumber_2->display(0);
	}};

void MainWindow::notgate(){
		if(checkBox_5->isChecked()){
	lcdNumber_3->display(0);
	}else{
		lcdNumber_3->display(1);
	}
};

	
void MainWindow::about(){
	QMessageBox msgBox;
	msgBox.setText("<html><head/><body><p>Logic Gates is a educational design program to create and learn about diffrent types of logic gates and the arrangments they can be placed in. It is fully open source and free and the code can be found at <a href=\"github.com/electro-corp/\"><span style=\" text-decoration: underline; color:#0000ff;\">[insert url here].</span></a></p></body></html>");
	msgBox.exec();
	/*
	QWizard wizard;
    wizard.addPage(createIntroPage());
	wizard.setWindowTitle("About");
    wizard.show();*/
}
