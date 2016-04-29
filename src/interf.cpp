#include "interf.h"
#include <QDebug>

using namespace std;

Interf::Interf() {
    SP_run = QSharedPointer<Run>(new Run());
    th = new TThread(SP_run);
    QObject::connect(th, SIGNAL(finished()), this, SLOT(SLOT_loaded_saved()));
}

Interf::~Interf() {
    delete th;
}

QWidget *Interf::getwidget() {
    return SP_run->getwidget();
}

void Interf::receiveFromQml_fbt(QString val) {

    std::istringstream v_l(val.toStdString().c_str());
    int val_i;
    v_l >> val_i;
    sendToQml_fbs(val_i);
    filter_blue = val_i;
}

void Interf::receiveFromQml_fgt(QString val) {

    std::istringstream v_l(val.toStdString().c_str());
    int val_i;
    v_l >> val_i;
    sendToQml_fgs(val_i);
    filter_green = val_i;
}

void Interf::getrun(QSharedPointer<Run> &r) {
        SP_run = r;
}

void Interf::receiveFromQml_fbs(int val) {
    sendToQml_fbt(QString::number(val));
    filter_blue = val;
}

void Interf::receiveFromQml_fgs(int val) {
    sendToQml_fgt(QString::number(val));
    filter_green = val;
}

void Interf::receiveFromQml_loadFile(QString file_name) {
    th->load(file_name);
    th->start();
}

void Interf::receiveFromQml_saveFile(QString file_name) {
    th->save(file_name);
    th->start();
}

void Interf::receiveFromQml_play_pause() {
    SP_run->change_play_pause() ? sendToQml_play_pause(true) : sendToQml_play_pause(false);
}

void Interf::receiveFromQml_preview() {
    SP_run->preview(filter_green, filter_blue);
}

void Interf::receiveFromQml_connectKinect() {
    try {
        SP_run->connect_kinect();
        sendToQml_kinectOn();
    }
    catch (const char* strException) {
        cerr << "Exception caught !!" << endl;
        cerr << strException << endl;
        sendToQml_message(QString("Kinect is not connected"));
    }
}

void Interf::receiveFromQml_startCapture() {
    try {
        SP_run->run_kinect();
        sendToQml_stopWatch();
    }
    catch (const char* strException) {
        cerr << "Exception caught !!" << endl;
        cerr << strException << endl;
        sendToQml_message(QString("Kinect is not connected"));
    }
}

void Interf::receiveFromQml_recordCapture() {
    try {
        SP_run->recordCapture();
    }
    catch (const char* strException) {
        cerr << "Exception caught !!" << endl;
        cerr << strException << endl;
        throw;
    }
}

void Interf::receiveFromQml_runKinect() {
    if(SP_run->run_kinect())
        sendToQml_message(QString("Kinect is not connected"));
}

void Interf::receiveFromQml_getMemInfo() {
    QString mem_total, mem_free, mem_ratio;
    SP_run->memory_info(mem_total, mem_free, mem_ratio);
    sendToQml_memInfo(mem_total, mem_free, mem_ratio);
}

void Interf::receiveFromQml_play() {
    SP_run->play();
}

void Interf::receiveFromQml_stop() {
    SP_run->stop();
}

void Interf::receiveFromQml_createSkeleton() {
    if(!SP_run->createSkeleton())
        sendToQml_loadFile();
    SP_run->createSkeleton();
}

void Interf::SLOT_loaded_saved() {
    sendToQml_loaded_saved();
}

void Interf::init_values(int fb, int fg, int wt) {
    sendToQml_fbs(fb);
    sendToQml_fgs(fg);
    sendToQml_wt(wt);
    filter_blue = fb;
    filter_green = fg;
}
