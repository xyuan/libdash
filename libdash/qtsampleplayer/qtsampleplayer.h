#ifndef QTSAMPLEPLAYER_H
#define QTSAMPLEPLAYER_H

#include <QtWidgets/QMainWindow>
#include "ui_qtsampleplayer.h"

class DashPlayerObserver;

class QtSamplePlayer : public QMainWindow
{
	Q_OBJECT

public:
	QtSamplePlayer(QWidget *parent = 0);
	~QtSamplePlayer();

    void setGuiFields(std::map<std::string, std::vector<std::string> > video, std::map<std::string, std::vector<std::string> > audio);

    virtual void updateKeyValue(const std::string& key, const std::string& value);
    virtual void removeAllKeyValues();

    virtual void setBufferFillState(int percentage);

    virtual void addWidgetObserver(DashPlayerObserver* observer);
    virtual void removeWidgetObserver(DashPlayerObserver* observer);
    
private slots:
    void on_cb_video_adaption_currentIndexChanged(const QString &arg1);

    void on_cb_video_representation_currentIndexChanged(const QString &arg1);

    void on_cb_audio_adaption_currentIndexChanged(const QString &arg1);

    void on_cb_audio_representation_currentIndexChanged(const QString &arg1);

    void on_lineEdit_returnPressed();

private:
        std::map<std::string, std::string> keyValues;
        std::map<std::string, int> keyIndices;

        std::map<std::string, std::vector<std::string> > video;
        std::map<std::string, std::vector<std::string> > audio;

        Ui::QtSamplePlayerClass *ui;

        std::vector<DashPlayerObserver*> observer;

        void settingsChanged();
        void lockUI();
        void unlockUI();
};

#endif // QTSAMPLEPLAYER_H