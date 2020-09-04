#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<tiffio.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //public slots:
        void My_Main();

    protected:
          void        mouseMoveEvent( QMouseEvent * );
          void        mousePressEvent( QMouseEvent * );
          void        wheelEvent(QWheelEvent *);
          void        mouseReleaseEvent(QMouseEvent *);
          void        mouseDoubleClickEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QByteArray filename, only_filename;
    unsigned short curX;
    unsigned short curY;
    unsigned short curZ;
    unsigned short Xdim1,Xdim;
    unsigned short Ydim1,Ydim;
    unsigned short Zdim1,Zdim;
    float sp[3];
    unsigned long hist[6000];
    unsigned long hmax;
    float scale;
    float maxFDTb;
    float maxFDTv;
    unsigned short Flag;
    unsigned short GITN;
    char DataID[100];
    short offset;
    int maxFDT;
    int mouseY=0,mousefp=0,mousefn=0;
    int recX=-1, recY=-1,recL=0,recW=0;
    int ROIindex=0;
    //short int *vol;
    struct ROI
    {
        int ta,tb,tbp,recX,recY,recW,recL,sizex,sizey,sizez,segment_flag=0,analysis_flag=0,iterate=0;
    }ROI;
  struct ROI listROI[150];
  int ROIflag=0;
  typedef signed short        InputPixelType;
  typedef unsigned char        OutputPixelType;
  void load_seeds();
  void load_GT();
  void draw_image();
  void draw_fullimage();
  void allocate_memory();
  void histogram();
  void readTiff();
  int bright_cont(int);
  void compute_FDT(unsigned short***);
  void pos_FDT(int,int,int);
  void neg_FDT(int,int,int);
  float get_mu(int,int,int);
  void local_scale();
  void local_maxima();
  void compute_MR( short***);
  void VTKdisplay();
  void core_vessel();
  void erosion(unsigned short***,int);
  void dialation(unsigned short***,int);
  void otsu();
  void sort(short *,int);
  void lowadaptivethreshold();
  void hiadaptivethreshold();
  // int get_orange(int);

  // For spine
  void FloodFill3d(int,int,int,int);
  void spine_DT(int);
  void compute_DT(int ***, int, int);
  void trace_back(int, int, int,int,int, int);
  void reset();
  void LMLS();
  void FCMR();
  void MR();
  void scaling(double,double,double);

  // Scaling and Kernel Dialog Box:
  bool opCancelled = false, opSuccessful = false;
  double scaleValue=1;
  int kernelSize = 3;

private slots:
//     void on_pushButton_EvPh_clicked();
//     void on_verticalSlider_valueChanged(int value);
//     void on_pushButton_EstAgr_clicked();
//     void on_pushButton_LU2_clicked();
//     void on_pushButton_LU1_clicked();
//       void on_pushButton_18_clicked();
//       void on_pushButton_16_clicked();
//       void on_checkBox_11_clicked();
//       void on_pushButton_15_clicked();
//       void on_pushButton_14_clicked();
//       void on_pushButton_13_clicked();
//       void on_pushButton_12_clicked();
//       void on_pushButton_11_clicked();
//       void on_pushButton_10_clicked();

//       void on_pushButton_19_clicked();

//       void on_pushButton_CH_clicked();//Shubhankar's Code

//       void on_checkBox_9_clicked();

//       void on_checkBox_8_clicked();
//       void on_checkBox_6_clicked();
//       void on_checkBox_5_clicked();
//       void on_pushButton_8_clicked();
//       void on_pushButton_7_clicked();
//       void on_pushButton_6_clicked();
//       void on_pushButton_5_clicked();
//       void on_checkBox_4_clicked();
//       void on_pushButton_4_clicked();
//       void on_checkBox_3_clicked();
//       void on_checkBox_2_clicked();
//       void on_pushButton_test_clicked();
//       void on_horizontalSlider_c_valueChanged(int value);
//       void on_horizontalSlider_b_valueChanged(int value);
//       void on_checkBox_clicked(bool checked);
       //void on_pushButton_clicked();
//    void on_pushButton_3_clicked();
//    void on_spinBox_z_valueChanged(int );
//    void on_spinBox_y_valueChanged(int );
//    void on_spinBox_x_valueChanged(int );
//    void on_pushButton_2_clicked();


//    void on_checkBox_sseedno_clicked();
//    void on_checkBox_dseedno_clicked();
//    void on_checkBox_sepseedno_clicked();
//    void on_deleteseed_clicked();
//    void on_SegSpineNo_clicked();
//    //void on_showgrpah_clicked();
//    void on_pushButton_clicked();
//    void on_savefeature_clicked();
//    void on_saveseed_clicked();
//    void on_spinBox_valueChanged(int arg1);
    void on_actionLoad_Image_triggered();
    void on_spinBox_curX_valueChanged(int x);
    void on_spinBox_curY_valueChanged(int y);
    void on_spinBox_curZ_valueChanged(int z);
    void on_actionShow_Gridlines_triggered();
    void on_actionFuzzy_Segment_triggered();
    void on_pushButton_5_clicked();
    void on_actionShow_Seed_Sep_triggered();
    void on_pushButton_test_clicked();
    void on_pushButton_CH_clicked();
    void on_actionSpine_triggered();
    void on_actionDendrite_triggered();
    void on_actionSeparator_triggered();
    void on_deleteseed_clicked();
    //void on_actionLoad_Seeds_triggered();
    void on_actionSave_Analysis_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
   // void on_pushButton_clicked();
    void on_spinBox_ta_valueChanged(int arg1);
    void on_spinBox_tb_valueChanged(int arg1);
    void on_spinBox_tbp_valueChanged(int arg1);
    void on_actionApply_3D_Median_triggered();
    void on_actionSelect_a_region_triggered();
    void on_crop_clicked();

    void on_showOriginal_stateChanged(int arg1);
    void on_actionScale_triggered();
    //void on_ROIList_itemDoubleClicked(QListWidgetItem *item);
    void on_ROIList_itemDoubleClicked();
    //void on_actionSave_ROIProfile_triggered();
    void on_actionShow_Segmented_Spine_Id_triggered();
    void on_pushButton_4_clicked();
    void on_actionSave_All_ROI_Profile_triggered();
    void on_actionLoad_All_ROI_Profile_triggered();
    void on_selectRegion_stateChanged(int arg1);
    void on_pushButton_clicked();
    void on_actionMorphological_Reconstruction_triggered();
    void getScaleAndKernelSize(double,int);
    void scalingChoseOperationCanceled();
};

#endif // MAINWINDOW_H
