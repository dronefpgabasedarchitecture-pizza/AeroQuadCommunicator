#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QMainWindow>
#include <QSettings>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QDebug>
#include <QMap>
#include "communication/communication_serial.h"

namespace Ui {
class Communicator;
}

class Communicator : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Communicator(QWidget *parent = 0);
    ~Communicator();

public slots:
    void updateStatusBar(QString message);
    void loadPanel(QString panelName);
    void getConnectionError(QString error);
    void updateConfig(QMap<QString, QString> configuration) {config = configuration;}

signals:
    void panelMessage(QByteArray);
    void panelStatus(QString);
    void initializePanel(QMap<QString, QString>);
    void messageOut(QByteArray);
    void autoConnect();

    void open(QString);
    void write(QByteArray);
    void close();
    
private:
    Ui::Communicator *ui;
    QSettings settings;
    QWidget *panel;
    Communication *comm;
    QByteArray connectionStop;
    QMap<QString, QString> config;

    void initToolBar();
};

#endif // COMMUNICATOR_H
