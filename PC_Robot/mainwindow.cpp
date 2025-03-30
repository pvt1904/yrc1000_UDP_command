#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include "udp.h"
#include "yrc1000micro_com.h"
#include "yrc1000micro_command.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_connect_clicked()
{
    if(ui->btn_connect->text() == "Connect"){
        QHostAddress udp_address;
        quint16 udp_port;
        QString ip_string = ui->txt_ip->text();
        QStringList ip_list = ip_string.split(".");
        quint32 ip_int32 = (ip_list.at(0).toUInt() << 24) | (ip_list.at(1).toUInt() << 16) | (ip_list.at(2).toUInt() << 8) | ip_list.at(3).toUInt();
        udp_address.setAddress(ip_int32);
        udp_port = ui->txt_port->text().toUShort();
        yrc1000micro_com.YRC1000microSetConnection(udp_address,udp_port);
        yrc1000micro_com.YRC1000microConnect();
        ui->btn_connect->setText("Disconnect");
    }
    else if(ui->btn_connect->text() == "Disconnect"){
        ui->btn_connect->setText("Connect");
        yrc1000micro_com.YRC1000microDisConnect();
    }
}


void MainWindow::on_btn_servo_clicked()
{
    if(ui->btn_servo->text() == "Servo On"){
        yrc1000micro_com.YRC1000microOnServo();
        ui->btn_servo->setText("Servo Off");
    }
    else if(ui->btn_servo->text() == "Servo Off"){
        yrc1000micro_com.YRC1000microOffServo();
        ui->btn_servo->setText("Servo On");
    }
}

void MainWindow::on_btn_set_pos_clicked()
{
    double set_speed = ui->txt_setSpeed->text().toDouble();
    QVector<double> set_position;
    // get position at xyz
    set_position.append(ui->txt_setX->text().toDouble());
    set_position.append(ui->txt_setY->text().toDouble());
    set_position.append(ui->txt_setZ->text().toDouble());
    set_position.append(ui->txt_setRoll->text().toDouble());
    set_position.append(ui->txt_setPitch->text().toDouble());
    set_position.append(ui->txt_setYaw->text().toDouble());
    if(ui->movj->isChecked()){
        yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_LINK_ABSOLUTE,
                                                   CMD_DATA_MOVE_SPEED_TYPE_LINK, set_speed, &set_position);
    }else if(ui->movl->isChecked()){
        yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_ABSOLUTE,
                                                   CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position);
    }else{
        yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                                   CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position);
    }
}

void MainWindow::on_btn_go_home_clicked()
{
    double set_speed = ui->txt_setSpeed->text().toDouble();
    QVector<double> set_position;
    // get position at xyz
    set_position.append(185);
    set_position.append(0);
    set_position.append(80);
    set_position.append(180);
    set_position.append(0);
    set_position.append(0);
    if(ui->btn_go_home->text() == "Go Home"){
        yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_LINK_ABSOLUTE,
                                                   CMD_DATA_MOVE_SPEED_TYPE_LINK, set_speed, &set_position);
    }
}


void MainWindow::on_X_minus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(-(ui->distance_mm_value->value()));
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_X_plus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(ui->distance_mm_value->value());
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Y_minus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(-(ui->distance_mm_value->value()));
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Y_plus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(ui->distance_mm_value->value());
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Z_minus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(-(ui->distance_mm_value->value()));
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Z_plus_clicked()
{
    double set_speed = ui->speed_mm_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(ui->distance_mm_value->value());
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_V_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Roll_minus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(-(ui->distance_deg_value->value()));
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Roll_plus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(ui->distance_deg_value->value());
    set_position_.append(0);
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Pitch_minus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(-(ui->distance_deg_value->value()));
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Pitch_plus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(ui->distance_deg_value->value());
    set_position_.append(0);
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Yaw_minus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(-(ui->distance_deg_value->value()));
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


void MainWindow::on_Yaw_plus_clicked()
{
    double set_speed = ui->speed_deg_value->value();
    QVector<double> set_position_;
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(0);
    set_position_.append(ui->distance_deg_value->value());
    yrc1000micro_com.YRC1000microMoveCartesian(CMD_DATA_MOVE_COORDINATE_ROBOT, CMD_HEADER_MOVE_INSTANCE_STRAIGHT_INCREMENT,
                                               CMD_DATA_MOVE_SPEED_TYPE_VR_SPEED, set_speed, &set_position_);
}


//get position x,y,z,roll,pitch,yaw
void MainWindow:: data_signal_x_y_z(){
    disconnect(&yrc1000micro_com, SIGNAL(dataUIRecieveSiUIgnal()),this,SLOT(data_signal_x_y_z()));
    QVector<double> position_ = yrc1000micro_com.updateRobotPosition();
    ui->position_x->setText(QString::number(position_[0]));
    ui->position_y->setText(QString::number(position_[1]));
    ui->position_z->setText(QString::number(position_[2]));
    ui->roll_value->setText(QString::number(position_[3]));
    ui->pitch_value->setText(QString::number(position_[4]));
    ui->yaw_value->setText(QString::number(position_[5]));
}
void MainWindow::on_btn_get_pos_clicked()
{
    connect(&yrc1000micro_com, SIGNAL(dataUIRecieveSiUIgnal()),this,SLOT(data_signal_x_y_z()));
    yrc1000micro_com.YRC1000microReadPosition();
}

// get position pulse
void MainWindow:: data_signal_pulse(){
    disconnect(&yrc1000micro_com, SIGNAL(dataUIRecieveSiUIgnal()),this,SLOT(data_signal_pulse()));
    QVector<double> position_ = yrc1000micro_com.updateRobotPulse();
    ui->txt_J1->setText(QString::number(position_[0]/1160.5));
    ui->txt_J2->setText(QString::number(position_[1]/1137.7));
    ui->txt_J3->setText(QString::number(position_[2]/568.8));
    ui->txt_J4->setText(QString::number(position_[3]/340.13));
    ui->txt_J5->setText(QString::number(position_[4]/340.13));
    ui->txt_J6->setText(QString::number(position_[5]/340.13));
}

void MainWindow::on_btn_get_joints_clicked()
{
    connect(&yrc1000micro_com, SIGNAL(dataUIRecieveSiUIgnal()),this,SLOT(data_signal_pulse()));
    yrc1000micro_com.YRC1000microReadPulse();
}


void MainWindow::on_distance_mm_value_valueChanged(int value)
{
    ui->linear_distance_txt->setText(QString::number(value));
}


void MainWindow::on_distance_deg_value_valueChanged(int value)
{
    ui->rot_distance_txt->setText(QString::number(value));
}


void MainWindow::on_speed_mm_value_valueChanged(int value)
{
    ui->linear_speed_txt->setText(QString::number(value));
}


void MainWindow::on_speed_deg_value_valueChanged(int value)
{
    ui->rot_speed_txt->setText(QString::number(value));
}


void MainWindow::on_btn_cal_FK_clicked()
{
    QVector<QString> J_string(6);
    QVector<double> J(6);
    QVector<double> output(6);
    J_string[0] = ui->txt_J1->text();
    J[0] = J_string[0].toDouble();
    J_string[1] = ui->txt_J2->text();
    J[1] = J_string[1].toDouble();
    J_string[2] = ui->txt_J3->text();
    J[2] = J_string[2].toDouble();
    J_string[3] = ui->txt_J4->text();
    J[3] = J_string[3].toDouble();
    J_string[4] = ui->txt_J5->text();
    J[4] = J_string[4].toDouble();
    J_string[5] = ui->txt_J6->text();
    J[5] = J_string[5].toDouble();
    output = yrc1000micro_com.Forward(J);
    ui->txt_X->setText(QString::number(output[0], 'f', 4));
    ui->txt_Y->setText(QString::number(output[1], 'f', 4));
    ui->txt_Z->setText(QString::number(output[2], 'f', 4));
    ui->txt_Roll->setText(QString::number(output[3], 'f', 4));
    ui->txt_Pitch->setText(QString::number(output[4], 'f', 4));
    ui->txt_Yaw->setText(QString::number(output[5], 'f', 4));
}

