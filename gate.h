#ifndef GATE_H
#define GATE_H
#include <iostream>
#include <list>
#include <QGraphicsPixmapItem>
#include <string>
#include <QImage>
class logicgate{
	public:
		std::string type;
		signed int idconnectone;
		signed int idconnecttwo;
		int x;
		int y;
		int output;
		int id;
		logicgate(std::string gottype,signed int gotidconnect,signed int gotidconnecttwo,int gotid,int x,int y){
			type = gottype;
			idconnectone = gotidconnect;
			idconnecttwo = gotidconnecttwo;
			id = gotid;
			this->x = x;
			this->y = y;
		}
		
};
#endif