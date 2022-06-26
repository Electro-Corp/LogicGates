#include "designer.h"
#include "tree.h"
#include "gate.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QListWidget>
#include <QCheckBox>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QSignalMapper>
#include <QSplashScreen> 
#include <QtWidgets/QTreeView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene> 
#include <QMessageBox>
#include <QtWidgets/QListView>
#include <QToolBox>
#include <iostream>
#include <QLabel>
#include <QtWidgets/QLCDNumber>
#include <QGroupBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QString>
#include <QDebug>
#include <QProgressBar>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <QList>
#include <QInputDialog>
#include <list>
#include <QListWidgetItem>
#include <string>
using namespace std;
QGraphicsScene *m_graphicsScene;
//List<string> list = {};
QList<QString> objects;
int andcount;
int ors;
int nots;
GateDesigner::GateDesigner(QWidget *parent):QMainWindow(parent)
{
	QGraphicsView *graphicsView;
	countergates = 0;
	andcount = 0;
	ors = 0;
	nots = 0;
	 if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("designer"));
		this->resize(1115, 901);
        actionSave = new QAction(this);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(this);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAddition = new QAction(this);
        actionAddition->setObjectName(QString::fromUtf8("actionAddition"));
		actionNew = new QAction(this);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralwidget = new QWidget(this);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
		m_graphicsScene = new QGraphicsScene(this);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
		graphicsView->setGeometry(QRect(170, 10, 641, 841));
		graphicsView->setScene(m_graphicsScene);
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
		toolBox->setGeometry(QRect(10, 10, 131, 371));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 131, 281));
        and_gate = new QPushButton(page);
        and_gate->setObjectName(QString::fromUtf8("and_gate"));
		and_gate->setGeometry(QRect(0, 0, 101, 91));
        or_gate = new QPushButton(page);
        or_gate->setObjectName(QString::fromUtf8("or_gate"));
        or_gate->setGeometry(QRect(0, 100, 101, 91));
        not_gate = new QPushButton(page);
        not_gate->setObjectName(QString::fromUtf8("not_gate"));
        not_gate->setGeometry(QRect(0, 200, 101, 91));
        toolBox->addItem(page, QString::fromUtf8("Basic Gates"));
		groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
		groupBox->setGeometry(QRect(830, 630, 261, 211));
        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(60, 30, 71, 71));
        lcdNumber->setDigitCount(1);
		
		page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 131, 411));
        run_circut = new QPushButton(page_2);
        run_circut->setObjectName(QString::fromUtf8("run_circut"));
		run_circut->setGeometry(QRect(0, 10, 81, 24));
        toolBox->addItem(page_2, QString::fromUtf8("Run"));
		page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        inputBitOne = new QLineEdit(page_3);
        inputBitOne->setObjectName(QString::fromUtf8("inputBitOne"));
		inputBitOne->setGeometry(QRect(70, 30, 61, 24));
		inputBitOne->setValidator( new QIntValidator(0, 1, this));
        inputBitTwo = new QLineEdit(page_3);
        inputBitTwo->setObjectName(QString::fromUtf8("inputBitTwo"));
		inputBitTwo->setGeometry(QRect(70, 60, 61, 24));
		inputBitTwo->setValidator( new QIntValidator(0, 1, this));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
		label->setGeometry(QRect(0, 30, 61, 16));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 60, 61, 16));
        toolBox->addItem(page_3, QString::fromUtf8("Input"));
		
		percent_bar = new QProgressBar(groupBox);
        percent_bar->setObjectName(QString::fromUtf8("percent_bar"));
        percent_bar->setGeometry(QRect(10, 181, 231, 20));
        percent_bar->setAutoFillBackground(false);
        percent_bar->setValue(0);
        percent_bar->setOrientation(Qt::Horizontal);
		label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
		label_3->setGeometry(QRect(0, 50, 51, 16));
		listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
		listWidget->setGeometry(QRect(840, 10, 251, 371));
        this->setCentralWidget(centralwidget);
        menubar = new QMenuBar(this);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 656, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuExamples = new QMenu(menubar);
        menuExamples->setObjectName(QString::fromUtf8("menuExamples"));
        this->setMenuBar(menubar);
        statusbar = new QStatusBar(this);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        this->setStatusBar(statusbar);

		
		groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
		groupBox_2->setGeometry(QRect(840, 380, 251, 251));
		
		updates_bar = new QListWidget(centralwidget);
        updates_bar->setObjectName(QString::fromUtf8("updates_bar"));
        updates_bar->setGeometry(QRect(10, 521, 151, 321));
        updates_bar->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
		
		x_add = new QPushButton(groupBox_2);
        x_add->setObjectName(QString::fromUtf8("x_add"));
        x_add->setGeometry(QRect(160, 90, 31, 24));
        x_sub = new QPushButton(groupBox_2);
        x_sub->setObjectName(QString::fromUtf8("x_sub"));
        x_sub->setGeometry(QRect(190, 90, 31, 24));
        y_add = new QPushButton(groupBox_2);
        y_add->setObjectName(QString::fromUtf8("y_add"));
        y_add->setGeometry(QRect(160, 70, 61, 24));
        y_sub = new QPushButton(groupBox_2);
        y_sub->setObjectName(QString::fromUtf8("y_sub"));
        y_sub->setGeometry(QRect(160, 114, 61, 21));
		
		name_of_gate = new QLabel(groupBox_2);
        name_of_gate->setObjectName(QString::fromUtf8("name_of_gate"));
        name_of_gate->setGeometry(QRect(10, 30, 131, 16));
        input_list = new QListWidget(groupBox_2);
        input_list->setObjectName(QString::fromUtf8("input_list"));
        input_list->setGeometry(QRect(10, 90, 131, 51));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 61, 16));
		update_value = new QPushButton(groupBox_2);
        update_value->setObjectName(QString::fromUtf8("update_value"));
        update_value->setGeometry(QRect(160, 200, 81, 24));
        set_input_one = new QLineEdit(groupBox_2);
        set_input_one->setObjectName(QString::fromUtf8("set_input_one"));
        set_input_one->setGeometry(QRect(110, 160, 41, 20));
        set_input_two = new QLineEdit(groupBox_2);
        set_input_two->setObjectName(QString::fromUtf8("set_input_two"));
        set_input_two->setGeometry(QRect(110, 180, 41, 21));
		set_to = new QLabel(groupBox_2);
        set_to->setObjectName(QString::fromUtf8("set_to"));
        set_to->setGeometry(QRect(10, 160, 111, 16));
        set_to_2 = new QLabel(groupBox_2);
        set_to_2->setObjectName(QString::fromUtf8("set_to_2"));
        set_to_2->setGeometry(QRect(10, 180, 111, 16));
		id_of_gate = new QLabel(groupBox_2);
		id_of_gate->setObjectName(QString::fromUtf8("id_of_gate"));
        id_of_gate->setGeometry(QRect(10, 50, 151, 16));
        
		menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuExamples->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
		menuFile->addAction(actionNew);
        menuExamples->addAction(actionAddition);
		
		optional_input_box = new QGroupBox(page_3);
        optional_input_box->setObjectName(QString::fromUtf8("optional_input_box"));
        optional_input_box->setGeometry(QRect(0, 100, 131, 151));
        checkBox = new QCheckBox(optional_input_box);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 30, 90, 22));
        inputBitThree = new QLineEdit(optional_input_box);
        inputBitThree->setObjectName(QString::fromUtf8("inputBitThree"));
        inputBitThree->setGeometry(QRect(70, 70, 61, 24));
        bit_four_label = new QLabel(optional_input_box);
        bit_four_label->setObjectName(QString::fromUtf8("bit_four_label"));
        bit_four_label->setGeometry(QRect(0, 100, 61, 16));
        inputBitFour = new QLineEdit(optional_input_box);
        inputBitFour->setObjectName(QString::fromUtf8("inputBitFour"));
        inputBitFour->setGeometry(QRect(70, 100, 61, 24));
        bit_three_label = new QLabel(optional_input_box);
        bit_three_label->setObjectName(QString::fromUtf8("bit_three_label"));
        bit_three_label->setGeometry(QRect(0, 70, 61, 16));
		
		this->setWindowTitle(QCoreApplication::translate("designer", "Logic Gates Designer 0.1 Alpha", nullptr));
        actionSave->setText(QCoreApplication::translate("designer", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("designer", "Load", nullptr));
        actionAddition->setText(QCoreApplication::translate("designer", "Addition", nullptr));
		actionNew->setText(QCoreApplication::translate("designer", "New", nullptr));
        and_gate->setText(QCoreApplication::translate("designer", "And Gate", nullptr));
        or_gate->setText(QCoreApplication::translate("designer", "Or Gate", nullptr));
        not_gate->setText(QCoreApplication::translate("designer", "Not Gate", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("designer", "Basic Gates", nullptr));
        run_circut->setText(QCoreApplication::translate("designer", "Run", nullptr));
		toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("designer", "Run", nullptr));
        label->setText(QCoreApplication::translate("designer", "Bit One:", nullptr));
        label_2->setText(QCoreApplication::translate("designer", "Bit Two:", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("designer", "Input", nullptr));
		menuFile->setTitle(QCoreApplication::translate("designer", "File", nullptr));
        menuExamples->setTitle(QCoreApplication::translate("designer", "Examples", nullptr));
		groupBox->setTitle(QCoreApplication::translate("designer", "Output Data", nullptr));
        label_3->setText(QCoreApplication::translate("designer", "Out Bit:", nullptr));
		groupBox_2->setTitle(QCoreApplication::translate("designer", "Selected Gate", nullptr));
        name_of_gate->setText(QCoreApplication::translate("designer", "Name will go here...", nullptr));
        label_4->setText(QCoreApplication::translate("designer", "Inputs:", nullptr));
		set_to->setText(QCoreApplication::translate("designer", "Set Input One: ", nullptr));
        set_to_2->setText(QCoreApplication::translate("designer", "Set Input Two: ", nullptr));
        update_value->setText(QCoreApplication::translate("designer", "Update", nullptr));
		id_of_gate->setText(QCoreApplication::translate("designer", "Gate Id will go here", nullptr));
		x_add->setText(QCoreApplication::translate("designer", "X+", nullptr));
        x_sub->setText(QCoreApplication::translate("designer", "X-", nullptr));
        y_add->setText(QCoreApplication::translate("designer", "Y+", nullptr));
        y_sub->setText(QCoreApplication::translate("designer", "Y-", nullptr));
		optional_input_box->setTitle(QCoreApplication::translate("designer", "Optional Inputs (-2)", nullptr));
        checkBox->setText(QCoreApplication::translate("designer", "Enabled", nullptr));
        bit_four_label->setText(QCoreApplication::translate("designer", "Bit Four:", nullptr));
        bit_three_label->setText(QCoreApplication::translate("designer", "Bit Three", nullptr));
		
		connect(and_gate, SIGNAL(clicked()), this, SLOT(addAndGate()));
		connect(or_gate, SIGNAL(clicked()), this, SLOT(addOrGate()));
		connect(not_gate, SIGNAL(clicked()), this, SLOT(addNotGate()));
		connect(run_circut, SIGNAL(clicked()), this, SLOT(calculate()));
		connect(update_value, SIGNAL(clicked()), this, SLOT(update_values()));
		connect(actionNew, SIGNAL(triggered()), this, SLOT(newWindow()));
		QSignalMapper* signalMapper = new QSignalMapper (this) ;
		/*connect(x_add, SIGNAL(clicked()), signalMapper, SLOT(map()));
		connect(x_sub, SIGNAL(clicked()), signalMapper, SLOT(map()));
		connect(y_add, SIGNAL(clicked()), signalMapper, SLOT(map()));
		connect(y_sub, SIGNAL(clicked()), signalMapper, SLOT(map()));*/
		//bruh
		connect(x_add,  &QPushButton::clicked, this, [this]{ changePlace("xplus"); });
		connect(x_sub,  &QPushButton::clicked, this, [this]{ changePlace("xminus"); });
		connect(y_add,  &QPushButton::clicked, this, [this]{ changePlace("yplus"); });
		connect(y_sub,  &QPushButton::clicked, this, [this]{ changePlace("yminus"); });

		//connect(y_sub, SIGNAL(clicked()), signalMapper, SLOT(map()));
		//L
		signalMapper -> setMapping (x_add, "xplus") ;
		signalMapper -> setMapping (x_sub, "xminus") ;
		signalMapper -> setMapping (y_add, "yplus") ;
		signalMapper -> setMapping (y_sub, "yminus") ;
		//connect (signalMapper, SIGNAL(mapped(std::string)), this, SLOT(changePlace(std::string))) ;
		//connect (signalMapper, this, SLOT(changePlace(std::string))) ;
		connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(getCurrentSelected()));
		
		debugSend("[Notification] Messages will go here.");
		
}
int GateDesigner::checkAnd(int one,int two){
	debugSend("[Note] Calculating And..");
	int a;
	int b;
	if(one == 1 && two == 1){
		a = 1;
		return a;
	}else{
		b = 0;
		return b;
	}
}
int GateDesigner::checkOr(int one,int two){
	debugSend("[Note] Calculating Or..");
	if(one == 1 || two == 1){
		return 1;
	}else{
		return 0;
	}
}
int GateDesigner::checkNot(int bit){
	debugSend("[Note] Calculating Not..");
	if(bit == 1){return 0;}else{return 1;};
}
void GateDesigner::addAndGate(){
	countergates = countergates +1;
	andcount = andcount+1;
	std::string listname = "And_Gate_";
	listname = listname+to_string(andcount);
	char *charlistname = new char[listname.length()-1];
	strcpy(charlistname, listname.c_str());
	listWidget->addItem(charlistname);
	logicgate AndGateReal("And Gate",-1,-1,countergates,0,y);
	gates.append(AndGateReal);
	y = y+100;
	objects.append("And Gate");
	updateDisplay();
};
void GateDesigner::addOrGate(){
	ors = ors+1;
	countergates = countergates +1;
	std::string listname = "Or_Gate_";
	listname = listname+to_string(ors);
	char *charlistname = new char[listname.length()-1];
	strcpy(charlistname, listname.c_str());
	listWidget->addItem(charlistname);
	logicgate OrGateReal("Or Gate",-1,-1,countergates,0,y);
	gates.append(OrGateReal);
	y = y+100;
	objects.append("Or Gate");
	updateDisplay();	
}
void GateDesigner::addNotGate(){
	nots = nots+1;
	countergates = countergates +1;
	std::string listname = "Not_Gate_";
	listname = listname+to_string(nots);
	char *charlistname = new char[listname.length()-1];
	strcpy(charlistname, listname.c_str());
	listWidget->addItem(charlistname);
	logicgate NotGateReal("Not Gate",-1,-1,countergates,0,y);
	gates.append(NotGateReal);
	y = y+100;
	updateDisplay();	
}
void GateDesigner::calculate(){
	int i,output,percent,counts,inputone,inputtwo;
	QString ione = inputBitOne->text();
	QString itwo = inputBitTwo->text();
	QString ithree = inputBitThree->text();
	QString ifour = inputBitFour->text();
	//qDebug() << "Got text";
	int input = ione.toInt();
	int input2 = itwo.toInt();
	int input3 = ithree.toInt();
	int input4 = ifour.toInt();
	//qDebug() << "Converted to int";
	//qDebug() << counter;
	qDebug() << gates.length();
	qDebug() << "------";
	qDebug() << countergates;
	qDebug() << "------";
	for (i=0;i<countergates;i++){
		 counts = counts+1;
		 percent = (counts/countergates)*100;
		 percent_bar->setValue(percent);
		 percent_bar->show();
		if(gates[i].type == "And Gate"){
			if(gates[i].idconnectone == -1){
			inputone = input;
			}else if(gates[i].idconnectone == -2 && checkBox->isChecked()){
			inputone = input3;
			}
			if(gates[i].idconnecttwo == -1){
			inputtwo = input2;
			}else if(gates[i].idconnectone == -2 && checkBox->isChecked()){
			inputtwo = input4;
			}
			gates[i].output = checkAnd(inputone,inputtwo);
			
			
			
			/*if(gates[i].idconnectone == -1 && gates[i].idconnecttwo == -1){
			gates[i].output = checkAnd(input,input2);
			}else if(gates[i].idconnectone == -1 && gates[i].idconnecttwo != -1){
			gates[i].output = checkAnd(input,gates[gates[i].idconnecttwo-1].output);
			}else if(gates[i].idconnectone != -1 && gates[i].idconnecttwo == -1){
			gates[i].output = checkAnd(gates[gates[i].idconnectone-1].output,input2);
			}else if(gates[i].idconnectone != -1 && gates[i].idconnecttwo != -1){
			gates[i].output = checkAnd(gates[gates[i].idconnectone-1].output,gates[gates[i].idconnecttwo-1].output);
			}*/
		}
		if(gates[i].type == "Or Gate"){
			if(gates[i].idconnectone == -1 && gates[i].idconnecttwo == -1){
			gates[i].output = checkOr(input,input2);
			}else if(gates[i].idconnectone == -1 && gates[i].idconnecttwo != -1){
			gates[i].output = checkOr(input,gates[gates[i].idconnecttwo-1].output);
			}else if(gates[i].idconnectone != -1 && gates[i].idconnecttwo == -1){
			gates[i].output = checkOr(gates[gates[i].idconnectone-1].output,input2);
			}else if(gates[i].idconnectone != -1 && gates[i].idconnecttwo != -1){
			gates[i].output = checkOr(gates[gates[i].idconnectone-1].output,gates[gates[i].idconnecttwo-1].output);
			}
		}
		if(gates[i].type == "Not Gate"){
			qDebug() << "Not Gate";
			if(gates[i].idconnectone == -1){
			gates[i].output = checkNot(input);
			qDebug() << "-1";	
			}
			else if(gates[i].idconnectone != -1){
			gates[i].output = checkNot(gates[gates[i].idconnectone-1].output);
				qDebug() << "1";
			}
		}
	output = gates[i].output;
	}
	qDebug() << "trying to print";
	lcdNumber->display(output);
}
void GateDesigner::getCurrentSelected(){
	qDebug() << "Item selected";
	int index = listWidget->currentRow();
	if(index != -1){
	std::string currenttype = gates[index].type;
	char *ccurrenttype = new char[currenttype.length()-1];
	strcpy(ccurrenttype, currenttype.c_str());
	//both inputs
	std::string input1 = to_string(gates[index].idconnectone);
	char *input1char = new char[input1.length()-1];
	strcpy(input1char, input1.c_str());
	std::string input2 = to_string(gates[index].idconnecttwo);
	char *input2char = new char[input2.length()-1];
	strcpy(input2char, input2.c_str());
	//and the id
	std::string id = "ID: "+to_string(gates[index].id);
	char *idchar = new char[id.length()-1];
	strcpy(idchar, id.c_str());
	//input_list->removeRows( 0, input_list.rowCount() );
	input_list->clear();
	input_list->addItem(input1char);
	input_list->addItem(input2char);
	id_of_gate->setText(QCoreApplication::translate("designer",idchar, nullptr));
	name_of_gate->setText(QCoreApplication::translate("designer",ccurrenttype, nullptr));
	}else{
	QMessageBox msgBox;
	msgBox.setText("Fatal: No item has been selected.");
	msgBox.exec();
	}
}

void GateDesigner::update_values(){
	int index = listWidget->currentRow();
	if(index != -1){
	std::string id1 = set_input_one->text().toStdString();
	int intid2,intid1;
	intid1 = stoi(id1);
	if(gates[index].type != "Not Gate"){
	std::string id2 = set_input_two->text().toStdString();
	intid2 = stoi(id2);
	}
	if(gates[index].type != "Not Gate"){
	gates[index].idconnectone = intid1;
	gates[index].idconnecttwo = intid2;
	}
	else{
	gates[index].idconnectone = intid1;
	if(gates[index].idconnecttwo != -1){
	debugSend("[Warning] Not Gates only take one input.");
	}	
	}
	getCurrentSelected();
	updateDisplay();
}
else{
		QMessageBox msgBox;
	msgBox.setText("Fatal: No item has been selected.");
	msgBox.exec();
}
}
void GateDesigner::newWindow(){
	GateDesigner desg;
	desg.show();
	//this->close();
}
void GateDesigner::updateDisplay(){
	m_graphicsScene->clear();
	//graphicsView->viewport()->update(); 
	int i;
	for (i = 0; i<gates.length();i++){
		if(gates[i].type == "And Gate"){
			QImage image("images/andgate.png");
			QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			item->setPos(gates[i].x,gates[i].y);
			item->setScale(0.4);
			m_graphicsScene->addItem(item);
			if(gates[i].idconnectone != -1 ){
			if(gates[i].idconnectone != -2){
			if(gates.length()<(gates[i].idconnectone)-1){
			QMessageBox msgBox;
			msgBox.setText("Fatal: Input Gate does not exist, check IDs and try again.");
			msgBox.exec();
			}else{
			m_graphicsScene->addLine(gates[i].x+30,gates[i].y,gates[(gates[i].idconnectone)-1].x+60,gates[(gates[i].idconnectone)-1].y);
			}
			}
			}
			if(gates[i].idconnecttwo != -1 ){
			if(gates[i].idconnecttwo != -2)
			if(gates.length()<(gates[i].idconnecttwo)-1){
			QMessageBox msgBox;
			msgBox.setText("Fatal: Input Gate does not exist, check IDs and try again.");
			msgBox.exec();
			}else{
			m_graphicsScene->addLine(gates[i].x+60,gates[i].y,gates[(gates[i].idconnecttwo)-1].x+60,gates[(gates[i].idconnecttwo)-1].y);
			}
			}
		}
			
		}
		if(gates[i].type == "Not Gate"){
			QImage image("images/notgate.png");
			QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			item->setPos(gates[i].x-40,gates[i].y-40);
			item->setScale(0.4);
			m_graphicsScene->addItem(item);
			if(gates[i].idconnectone != -1){
			if(gates[i].idconnectone != -2){
			if(gates.length()<(gates[i].idconnectone)-1){
			QMessageBox msgBox;
			msgBox.setText("Fatal: Input Gate does not exist, check IDs and try again.");
			msgBox.exec();
			}else{
			m_graphicsScene->addLine(gates[i].x+30,gates[i].y,gates[(gates[i].idconnectone)-1].x+60,gates[(gates[i].idconnectone)-1].y);
			}
			}
		}
		}
		if(gates[i].type == "Or Gate"){
			QImage image("images/orgate.png");
			QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			item->setPos(gates[i].x-40,gates[i].y-40);
			item->setScale(0.4);
			m_graphicsScene->addItem(item);
			if(gates[i].idconnectone != -1){
			if(gates[i].idconnectone != -2){
			if(gates.length()<(gates[i].idconnectone)-1){
			QMessageBox msgBox;
			msgBox.setText("Fatal: Input Gate does not exist, check IDs and try again.");
			msgBox.exec();
			}else{
			m_graphicsScene->addLine(gates[i].x+30,gates[i].y,gates[(gates[i].idconnectone)-1].x+60,gates[(gates[i].idconnectone)-1].y);
			}
			}
			}
			if(gates[i].idconnecttwo != -1){
			if(gates[i].idconnecttwo != -2){
			if(gates.length()<(gates[i].idconnecttwo)-1){
				
			QMessageBox msgBox;
			msgBox.setText("Fatal: Input Gate does not exist, check IDs and try again.");
			msgBox.exec();
			}else{
			m_graphicsScene->addLine(gates[i].x+60,gates[i].y,gates[(gates[i].idconnecttwo)-1].x+60,gates[(gates[i].idconnecttwo)-1].y);
			}
			}
			}	
		}
	}


void GateDesigner::changePlace(std::string direction){
	int index = listWidget->currentRow();
	if(index != -1){
	if(direction == "xplus"){
		gates[index].x = gates[index].x-10;
	}
	if(direction == "xminus"){
		gates[index].x = gates[index].x+10;
	}
	if(direction == "yminus"){
		gates[index].y = gates[index].y+10;
	}
	if(direction == "yplus"){
		gates[index].y = gates[index].y-10;
	}
	updateDisplay();
}else{
	QMessageBox msgBox;
	msgBox.setText("Fatal: No Gate has been selected, cannot change Coordinates..");
	msgBox.exec();
}
}
void GateDesigner::debugSend(std::string message){

	char *cmessage = new char[message.length()-1];
	strcpy(cmessage, message.c_str());
	updates_bar->addItem(cmessage);
}


