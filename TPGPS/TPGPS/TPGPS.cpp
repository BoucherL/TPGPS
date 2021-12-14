#include "TPGPS.h"
#include "qdebug.h"
#include <QRegExp>

TPGPS::TPGPS(QWidget *parent)
    : QMainWindow(parent)
{
    
	ui.setupUi(this);
	


	port = new QSerialPort(this);
	QObject::connect(port, SIGNAL(readyRead()), this, SLOT(serialPortRead()));

	port->setPortName("COM1");
	port->open(QIODevice::ReadWrite);
	port->setBaudRate(QSerialPort::Baud4800);
	port->setDataBits(QSerialPort::DataBits::Data8);
	port->setParity(QSerialPort::Parity::NoParity);
	port->setStopBits(QSerialPort::StopBits::OneStop);
	port->setFlowControl(QSerialPort::NoFlowControl);

	if (port->isOpen())
	{
		ui.portStatus->setText("Port: Connecter");
	}
	else
	{
		ui.portStatus->setText("Port: Deconnecter");
	}

	TPGPS::boucleTime();


}

void TPGPS::serialPortRead() {
	QByteArray data = port->readAll();
	QString str(data);

	trameBuff += str;


	QRegExp startMatch("GPGGA(.+)")
		, stopMatch("(\\*)");

	int startByte = startMatch.indexIn(trameBuff);

	if (startByte > -1 && startByte > 0 && stopMatch.indexIn(trameBuff, startByte + 1) > -1) {

		qDebug() << trameBuff;
		QRegExp regex("GPGGA,(.+)(\\*)");
		int test = regex.indexIn(trameBuff);

		qDebug() << trameBuff;

		QStringList list = regex.capturedTexts();

		trameBuff.replace(0, stopMatch.indexIn(trameBuff, startByte + 1), "");

		// -- Decoupe de la chaine chaque virgules
		QStringList data = list.at(1).split(',', Qt::SkipEmptyParts);

		QString Longitude = data.at(1)
			, Latitude = data.at(3)
			, Timestamp = data.at(0);

		// -- Conversion
		int LongitudeDot = Longitude.indexOf(".")
			, LatitudeDot = Latitude.indexOf(".");

		Longitude.insert(LongitudeDot - 2, ",");
		Latitude.insert(LatitudeDot - 2, ",");

		QStringList LatitudeSplit = Latitude.split(",");
		double LatitudeDivide = LatitudeSplit.at(1).toDouble() / 60;
		double LatitudePDivide = LatitudeSplit.at(0).toDouble();
		double VraiLatitude = LatitudeDivide + LatitudePDivide;

		QStringList LongitudeSplit = Longitude.split(",");

		double LongitudeDivide = LongitudeSplit.at(1).toDouble() / 60;
		double LongitudePDivide = LongitudeSplit.at(0).toDouble();
		double VraiLongitude = LongitudeDivide + LongitudePDivide;

		QString LongitudeString = QString::number(VraiLongitude);

		QString LatitudeString = QString::number(VraiLatitude);

		ui.Longitude->setText("Longitude :"+LongitudeString);
		ui.Latitude->setText("Latitude :"+LatitudeString);
	}
}

void TPGPS::afficheMemo(){
	ui.Memo1->setText(trameBuff);
	if (int num = 1){
		ui.Memo2->setText(trameBuff2);
		QString trameBuff2 = trameBuff;
	}
	else {
		int i = 1;
		QString trameBuff2 = trameBuff;
	}
}

void TPGPS::boucleTime() {
	TPGPS::afficheMemo();
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &TPGPS::afficheMemo);
	timer->start(150);
}