#ifndef DESIGNER_H
#define DESIGNER_H
#include <QtCore/QVariant>
#include "gate.h"
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
 #include <QSplashScreen> 
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QProgressBar>
#include <QPen>
#include <iostream>
#include <string>
#include <QtWidgets/QListView>
#include <QToolBox>
#include <QGraphicsView>
#include <QtWidgets/QLCDNumber>
//#include <QGraphicsScene>
#include <QLabel>
#include <QDebug>
#include <QtWidgets/QLineEdit>
#include <QListWidget>
#include <QtWidgets/QWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QList>
namespace Ui{
	class GateDesigner;
}
class GateDesigner: public QMainWindow{
	Q_OBJECT
	public:
	explicit GateDesigner(QWidget *parent = nullptr);
	QAction *actionSave;
    QAction *actionLoad;
    QAction *actionAddition;
	QAction *actionNew;
    
	QWidget *centralwidget;
    
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *and_gate;
    QPushButton *or_gate;
    QPushButton *not_gate;
    QWidget *page_3;
    QLineEdit *inputBitOne;
    QLineEdit *inputBitTwo;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_2;
    QPushButton *run_circut;
    QGroupBox *groupBox;
    QLCDNumber *lcdNumber;
    QLabel *label_3;
    //QListView *listView;
	QListWidget *listWidget;
	QMenuBar *menubar;
    QMenu *menuFile;
	QGraphicsView *graphicsView;
    QMenu *menuExamples;
    QStatusBar *statusbar;
	QGroupBox *groupBox_2;
    QLabel *name_of_gate;
	QLabel *label_4;
    QListWidget *input_list;
	QLabel *set_to;
    QLabel *set_to_2;
    QPushButton *update_value;
    QLineEdit *set_input_one;
    QLineEdit *set_input_two;
	QList<logicgate> gates;
	QLabel *id_of_gate;
	QProgressBar *percent_bar;
	QListWidget *updates_bar;
	
	//x and y
	QPushButton *x_add;
    QPushButton *x_sub;
    QPushButton *y_add;
    QPushButton *y_sub;
	//optional inputs
	QGroupBox *optional_input_box;
    QCheckBox *checkBox;
    QLineEdit *inputBitThree;
    QLabel *bit_four_label;
    QLineEdit *inputBitFour;
    QLabel *bit_three_label;
	//QPainter painter;
	//QPen pen;

	//GateDesigner::update()
	//QGraphicsView *graphicsView;
	
	//not directly connected to the UI
	int y;
	int countergates;
	
	
	//int nots;
	
	/*
	private:
	*/private slots:
		void addAndGate();
		void addOrGate();
		void calculate();
		void getCurrentSelected();
		void update_values();
		void addNotGate();
		void newWindow();
		void updateDisplay();
		void changePlace(std::string direction);
		void debugSend(std::string message);
		int checkAnd(int one,int two);
		int checkOr(int one,int two);
		int checkNot(int bit);
	
		
		//void itemInserted(DiagramItem *item);*/
};

#endif