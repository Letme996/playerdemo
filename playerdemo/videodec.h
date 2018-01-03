/**
 * @file
 * @brief   视频解码
 * @author  itisyang
 * @date    20171221
 * @note
 */

#ifndef VIDEODEC_H
#define VIDEODEC_H

#include <QObject>
#include <QImage>
#include "globalhelper.h"
#include "customthread.h"

class VideoDec : public CustomThread
{
    Q_OBJECT
public:
    explicit VideoDec();
    /**
     * @brief   线程入口
     * @param
     * @return
     * @note
     */
    void run();

    int video_stream;
    AVStream *video_st;
    AVCodecContext *video_avctx;


signals:
    void SigPlayMsg(QString strMsg);    ///< 播放信息信号

    void SigImage(QPixmap& img);
public slots:
    /**
     * @brief   开始解码
     * @param
     * @return  错误码
     * @note
     */
    void OnStartDec();


};

#endif // VIDEODEC_H
