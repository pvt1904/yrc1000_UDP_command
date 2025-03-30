#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHostAddress>
#include <QMainWindow>
#include <yrc1000micro_com.h>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_connect_clicked();

    void on_btn_servo_clicked();

    void on_btn_cal_FK_clicked();

    void on_btn_set_pos_clicked();

    void on_btn_go_home_clicked();

    void on_X_minus_clicked();

    void on_X_plus_clicked();

    void on_Y_minus_clicked();

    void on_Y_plus_clicked();

    void on_Z_minus_clicked();

    void on_Z_plus_clicked();

    void on_Roll_minus_clicked();

    void on_Roll_plus_clicked();

    void on_Pitch_minus_clicked();

    void on_Pitch_plus_clicked();

    void on_Yaw_minus_clicked();

    void on_Yaw_plus_clicked();

    void on_btn_get_pos_clicked();

    void on_btn_get_joints_clicked();

    void on_distance_mm_value_valueChanged(int value);

    void on_distance_deg_value_valueChanged(int value);

    void on_speed_mm_value_valueChanged(int value);

    void on_speed_deg_value_valueChanged(int value);

public slots:
    void data_signal_x_y_z();
    void data_signal_pulse();

private:
    Ui::MainWindow *ui;
    YRC1000micro_com yrc1000micro_com;
};
#endif // MAINWINDOW_H
