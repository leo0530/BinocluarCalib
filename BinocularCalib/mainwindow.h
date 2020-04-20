#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QTextCodec>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void handleTimeout();  //超时处理函数
private slots:
    void on_saveButton_clicked();

    void on_calibButton_clicked();

private:
    Ui::MainWindow *ui;
     QTimer *timer;          //定时器
     bool m_bSaveImage;
};

extern const char* imageName_L;// = "1.jpg"; // 用于检测深度的图像
extern const char* imageName_R;// = "26.jpg";
extern const char* imageList_L;// = "caliberationpics_L.txt"; // 左相机的标定图片名称列表
extern const char* imageList_R;// = "caliberationpics_R.txt"; // 右相机的标定图片名称列表
extern const char* singleCalibrate_result_L;// = "calibrationresults_L.txt"; // 存放左相机的标定结果
extern const char* singleCalibrate_result_R;// = "calibrationresults_R.txt"; // 存放右相机的标定结果
extern const char* stereoCalibrate_result_L;// = "stereocalibrateresult_L.txt"; // 存放立体标定结果
extern const char* stereoCalibrate_result_R;// = "stereocalibrateresult_R.txt";
extern const char* stereoRectifyParams;// = "stereoRectifyParams.txt"; // 存放立体校正参数
extern vector<vector<Point2f>> corners_seq_L; // 所有角点坐标
extern vector<vector<Point2f>> corners_seq_R;
extern vector<vector<Point3f>> objectPoints_L; // 三维坐标
extern vector<vector<Point3f>> objectPoints_R;
extern Mat cameraMatrix_L;// = Mat(3, 3, CV_32FC1, Scalar::all(0)); // 相机的内参数
extern Mat cameraMatrix_R;// = Mat(3, 3, CV_32FC1, Scalar::all(0)); // 初始化相机的内参数
extern Mat distCoeffs_L;// = Mat(1, 5, CV_32FC1, Scalar::all(0)); // 相机的畸变系数
extern Mat distCoeffs_R;// = Mat(1, 5, CV_32FC1, Scalar::all(0)); // 初始化相机的畸变系数
extern Mat R, T, E, F; // 立体标定参数
extern Mat R1, R2, P1, P2, Q; // 立体校正参数
extern Mat mapl1, mapl2, mapr1, mapr2; // 图像重投影映射表
extern Mat img1_rectified, img2_rectified, disparity, result3DImage; // 校正图像 视差图 深度图
extern Size patternSize;// = Size(9, 6); // 行列内角点个数
extern Size chessboardSize;// = Size(41, 41); // 棋盘上每个棋盘格的大小30mm
extern Size imageSize; // 图像尺寸
extern Rect validRoi[2];


#endif // MAINWINDOW_H
