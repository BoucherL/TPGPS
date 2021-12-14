#pragma once

#include <QtWidgets/QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "ui_TPGPS.h"
#include <QObject>
#include <QTimer>

class TPGPS : public QMainWindow
{
    Q_OBJECT

public:
    TPGPS(QWidget *parent = Q_NULLPTR);

private:
    Ui::TPGPSClass ui;

	QSerialPort *port;
	QString trameBuff;
	QTimer *timer;
	QString trame;
	QString trameBuff2;
	int num = 0;

public slots: 
	void serialPortRead();
	void afficheMemo();
	void boucleTime();
};
