#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <string.h>
#include "global.h"
#include<QFileDialog>
#include<QString>
#include <iostream>
#include<cmath>
#include<QScrollBar>
#include<QMessageBox>
#include<QDesktopWidget>
#include<MedianFilterAndScallingProperties.h>
#define TRUE true
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3dSpAn:Dendritic Spine Segmentation and Analysis Tool");
   // ui->comboBox->addItem("Type");
    ui->comboBox->addItem("Spine");
    ui->comboBox->addItem("Dendrite");
    ui->comboBox->addItem("Separator");
    ui->sliceLabel->setAlignment(Qt::AlignTop);
    ui->actionSelect_a_region->setVisible(false);
    ui->actionScale->setVisible(false);
    ui->scrollArea->horizontalScrollBar()->setDisabled(true);
    ui->scrollArea->verticalScrollBar()->setDisabled(true);
    ui->actionFuzzy_Distance_Transform->setEnabled(false);
    ui->actionFuzzy_Connectivity->setEnabled(false);
    ui->actionMorphological_Reconstruction->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->showOriginal->setEnabled(false);
    ui->pushButton_CH->setEnabled(false);
    ui->actionAdvance_Preprocessing->setEnabled(false);
   //ui->actionSave_Seeds_2->setEnabled(false);
    ui->actionSave_ROIProfile->setEnabled(false);
    //this->setFixedSize(this->geometry().width(),this->geometry().height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString temp;

    temp=QFileDialog::getOpenFileName(this,tr("Open File"), "",
                                      tr("MultiPage tiff Images (*.tif);;Analyze Images (*.hdr)"));
    if(QString::compare(temp,QString())==0)return;
    start=1;
    QByteArray qb = temp.toLatin1();
    filename =  qb.data();
    short c1=filename.lastIndexOf("/");
    short c2=filename.lastIndexOf(".");
    only_filename=filename.mid(c1+1,c2-c1-1);
    strcpy(DataID,only_filename);
    setWindowTitle("3dSpAn: "+only_filename);
    if(filename.endsWith(".hdr"))histogram();
    if(filename.endsWith(".tif")) readTiff();
    qDebug()<<"outoffunc";
    ui->scrollArea->horizontalScrollBar()->setEnabled(true);
    ui->scrollArea->verticalScrollBar()->setEnabled(true);
    ui->spinBox_curX->setMaximum(Xdim-1);
    ui->spinBox_curY->setMaximum(Ydim-1);
    ui->spinBox_curZ->setMaximum(Zdim-1);
    curX=Xdim/2;
    curY=Ydim/2;
    curZ=Zdim/2;
//    reset();
//    allocate_memory();
    draw_fullimage();
    ui->spinBox_curX->setValue(curX);
    ui->spinBox_curY->setValue(curY);
    ui->spinBox_curZ->setValue(curZ);
    for(int i=0;i<MAX;i++)
    {
        listROI[i].recL=0;
        listROI[i].recW=0;
        listROI[i].recX=-1;
        listROI[i].recY=-1;
        listROI[i].ta=0;
        listROI[i].tb=0;
        listROI[i].tbp=0;
        listROI[i].sizex=0;
        listROI[i].sizey=0;
        listROI[i].sizez=0;
        listROI[i].segment_flag=0;
        listROI[i].analysis_flag=0;
        listROI[i].iterate=0;
    }
    for(int i=1;i<MAX;i++)
    {
        dspcount[i]=1;
        dcount[i]=1;
        sepcount[i]=1;
    }
}

void MainWindow::allocate_memory()
{

    FDT  = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    FDTb = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    FDTv = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    tFDT = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    LM   = (unsigned long ***)calloc(sizeof(unsigned long **) , Xdim1);
    FCv  = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    FCb  = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    MRv  = (short ***)calloc(sizeof(short **) , Xdim1);
    MRb  = (short ***)calloc(sizeof(short **) , Xdim1);
    out  = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
// //  img  = (unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);
    SS   = (unsigned char ***)calloc(sizeof(unsigned char **) , Xdim1);
  // GT   = (unsigned char ***)calloc(sizeof(unsigned char **) , Xdim1);
  // NML   = (unsigned char ***)calloc(sizeof(unsigned char **) , Xdim1);
 //  brightness=(unsigned short ***)calloc(sizeof(unsigned short **) , Xdim1);


    for (int i = 0 ;  i < Xdim1; i++) {
          FDT[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          FDTb[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          FDTv[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          tFDT[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          LM[i] = (unsigned long **)calloc(sizeof(unsigned long *) , Ydim1);
          FCv[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          FCb[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          MRv[i] = (short **)calloc(sizeof(short *) , Ydim1);
          MRb[i] = (short **)calloc(sizeof(short *) , Ydim1);
          out[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
//       //img[i] = (unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);
          SS[i] = (unsigned char **)calloc(sizeof(unsigned char *) , Ydim1);
       // GT[i] = (unsigned char **)calloc(sizeof(unsigned char *) , Ydim1);
       // NML[i] = (unsigned char **)calloc(sizeof(unsigned char *) , Ydim1);
      // brightness[i]=(unsigned short **)calloc(sizeof(unsigned short *) , Ydim1);

        for (int j = 0; j < Ydim1; j++){
            FDT[i][j] = (unsigned short *)calloc(sizeof(unsigned short),Zdim1);
            FDTb[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            FDTv[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            tFDT[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            LM[i][j] = (unsigned long *)calloc(sizeof(unsigned long) , Zdim1);
            FCv[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            FCb[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            MRv[i][j] = (short *)calloc(sizeof(short) , Zdim1);
            MRb[i][j] = (short *)calloc(sizeof(short) , Zdim1);
            out[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
//        //  img[i][j] = (unsigned short *)calloc(sizeof(unsigned short) , Zdim1);
            SS[i][j] = (unsigned char *)calloc(sizeof(unsigned char) , Zdim1);
//        // GT[i][j] = (unsigned char *)calloc(sizeof(unsigned char) , Zdim1);
//        // NML[i][j] = (unsigned char *)calloc(sizeof(unsigned char) , Zdim1);
//       //  brightness[i][j]=(unsigned short *)calloc(sizeof(unsigned short) ,Zdim1);

        }
    }


}

void MainWindow::histogram()
{

    offset=0;//for bioimaging data

    //ConstIteratorType inputIt(   image, image->GetRequestedRegion());
    // IteratorType      outputIt(  outputImage,         outputRegion );

    Xdim=0;//size[0];
    Ydim=0;//size[1];
    Zdim=0;//size[2];

    FILE *fo;
//    char buffer[100];
//    hdr=malloc(480);

    fo = fopen(filename, "rb");

    unsigned short uns[3];

    if(fo)
    {

//        fread(hdr,348,1,fo);
//        char *s=(char *)hdr;
//        std::cerr<<s;
        fseek(fo,42,SEEK_SET);
        Xdim=readShort(fo);
        Ydim=readShort(fo);
        Zdim=readShort(fo);
       // std::cerr<<Xdim<<" "<<Ydim<<" "<<Zdim;
        //      sprintf(buffer,"Xdim1= %d Ydim1=%d Zdim1=%d",Xdim1,Ydim1,Zdim1);
        //      QMessageBox::information(this, "Header Info:", buffer, QMessageBox::Ok);
    }
    fclose(fo);


    free(vol);//Free vol memory, if already alloted, before fresh allocation
    free(vol1);
    free(output);
    vol = (short ***)calloc(sizeof(short **) , Xdim);
    output =(short ***)calloc(sizeof(short **) , Xdim);
    vol1=(unsigned char ***)calloc(sizeof(unsigned char **) , Xdim);
    for (int i = 0 ;  i < Xdim; i++) {
        vol[i] = (short **)calloc(sizeof(short *) , Ydim);
        output[i]=(short **)calloc(sizeof(short *),Ydim);
        vol1[i]=(unsigned char **)calloc(sizeof(unsigned char *),Ydim);
        for (int j = 0; j < Ydim; j++)
        {
            vol[i][j] = (short *)calloc(sizeof(short) , Zdim);
            output[i][j]=(short *)calloc(sizeof(short ),Zdim);
            vol1[i][j]=(unsigned char *)calloc(sizeof(unsigned char), Zdim);
        }
    }



    unsigned short ret;
    unsigned char lowByte, hiByte;

    filename.replace("hdr","img");
    fo = fopen(filename, "rb");
    if(fo)
    {
        for(int k=0;k<Zdim;k++)
            for(int j=0;j<Ydim;j++)
                for(int i=0;i<Xdim;i++)
                {
                    short val=(short)fgetc(fo);
                    vol[i][j][k] = val;
                    output[i][j][k]=val;
                }//readShort(fo);
    }
    fclose(fo);
    for(int k=0;k<Zdim;k++)
        for(int j=0;j<Ydim;j++)
            for(int i=0;i<Xdim;i++)
                vol1[i][j][k] =0;

    long count=0,max=-9999;//,hist[4000],min=9999,hmax=0;
    short val,x=0,y=0,z=0;


}

unsigned short readShort( FILE* inff )     // read a 16 bit integer
{
    //std::cout<<"readShort() called"<<std::endl;


    unsigned short ret;
    unsigned char lowByte, hiByte;

    hiByte = fgetc(inff);          // Read the high order byte
    lowByte = fgetc(inff);         // Read the low order byte (little endian form)


    // Pack together
    ret = hiByte;
    ret <<= 8;
    ret |= lowByte;

    return ret;

    //std::cout<<"readShort() ended"<<std::endl;
}

void MainWindow::readTiff()
{
    uint32* raster;
    TIFF* tif = TIFFOpen(filename, "r");
    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &Xdim);           // uint32 width;
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &Ydim);// uint32 height;
    int dircount = 1;
    while (TIFFReadDirectory(tif))  dircount++;
    Zdim=dircount;
    raster = (uint32*)_TIFFmalloc(Xdim*Ydim* sizeof(uint32));

   free(vol);//Free vol memory, if already alloted, before fresh allocation
   free(vol1);
   free(output);
    vol = (short ***)calloc(sizeof(short **) , Xdim);
    vol1=(unsigned char ***)calloc(sizeof(unsigned char **),Xdim);
    output =(short ***)calloc(sizeof(short **) , Xdim);
    for (int i = 0 ;  i < Xdim; i++) {
        vol[i] = (short **)calloc(sizeof(short *),Ydim);
        vol1[i]=(unsigned char **)calloc(sizeof(unsigned char *),Ydim);
        output[i] = (short **)calloc(sizeof(short *),Ydim);
        for (int j = 0; j < Ydim; j++)
        {
            vol[i][j] = (short *)calloc(sizeof(short),Zdim);
            vol1[i][j]=(unsigned char *)calloc(sizeof(unsigned char),Zdim);
            output[i][j] = (short *)calloc(sizeof(short),Zdim);
        }
    }

    int k=1;
    while(k<=Zdim){
      TIFFSetDirectory(tif,k);
      TIFFReadRGBAImage(tif,Xdim,Ydim, raster, 0);
      for (int j = 0; j <Ydim; j++){
          for (int i = 0; i < Xdim; i++){
                  uint32& TiffPixel = raster[j*Xdim+i];
                  short B=(short)TIFFGetB(TiffPixel);
                  short G=(short)TIFFGetG(TiffPixel);
                  short R=(short)TIFFGetR(TiffPixel);
                  short max=B;
                  if(G>max)max=G;
                  if(R>max)max=R;
                  vol[i][j][k-1]=max;
                  output[i][j][k-1]=max;
                  }
            }
       k++;
      }

    for(int k=0;k<Zdim;k++)
        for(int j=0;j<Ydim;j++)
            for(int i=0;i<Xdim;i++)
                vol1[i][j][k] =0;

}

void MainWindow::reset()
{
    GITN=0;

    free(FDT);FDT=NULL;
    free(FDTv);FDTv=NULL;
    free(FDTb);FDTb=NULL;
    free(tFDT);tFDT=NULL;
    free(LM);LM=NULL;
    free(FCv);FCv=NULL;
    free(FCb);FCb=NULL;
    free(MRv);MRv=NULL;
    free(MRb);MRb=NULL;
    free(out);out=NULL;
    free(SS);SS=NULL;
    free(GT);GT=NULL;
    free(NML);NML=NULL;
}

void MainWindow::draw_image()//Refresh
{
    //return;
    if(start==0)return;
    int roindex=ui->ROIList->currentRow()+1;
    QImage imagez(Xdim1,Ydim1,QImage::Format_RGB32);
    QRgb value = qRgb(0, 0, 0);
    int pixelValue,pixelValue1;



    QRgb B = qRgb(0, 255,0);
    //QRgb fuzzy = qRgb(255,255,0);
    QRgb artery = qRgb(255,0,0);

    QRgb bg = qRgb(0,0,0);

    int ta=ui->spinBox_ta->value();
    int tb=ui->spinBox_tb->value();
    //int tap=ui->spinBox_tap->value();
    int tbp=ui->spinBox_tbp->value();

    float mu;
    //       float factor=255.0/maxFDTb;



    ////////////////////////ZZZZZZZZZZZZZZZZZZZZZZ
    for(int i=0;i<Xdim1;i++)
        for(int j=0;j<Ydim1;j++)
        {

            pixelValue =out[i][j][curZ];
            pixelValue1=region[i][j][curZ];
           // else pixelValue=brightness[i][j][k];
            imagez.setPixel(QPoint(i,j), qRgb(pixelValue1,pixelValue1,pixelValue1));
            if(ui->actionFuzzy_Segment->isChecked()==TRUE)//Fuzzy segment
            {
                mu=(float)(pixelValue1-ta)/(tb-ta);
                if(pixelValue1 >=tb&&pixelValue1<=tbp)// && pixelValue <=2048
                    imagez.setPixel(i,j,B );
                else if(pixelValue1<ta)
                        imagez.setPixel(i,j,bg);
                else if(pixelValue1==ta)imagez.setPixel(i,j,artery);
                else if(pixelValue1 >ta && pixelValue1<tb)
                            //imagez.setPixel(i,j, fuzzy);
                            imagez.setPixel(i,j, qRgb(255*(1-mu),255*mu,0));

            }
            else if(ui->actionFuzzy_Distance_Transform->isChecked()==TRUE && (FDT[i][j][curZ]!=0 || FDTv[i][j][curZ]!=0))//FDT
            {

                            int b= FDTb[i][j][curZ];
                            int v= FDTv[i][j][curZ];



                            //if(b==0 && v==0) imagez.setPixel(i,j, qRgb(255,255,255));;

                            //     int index=curZ*Xdim1*Ydim1+j*Xdim1+i;
                            unsigned long count=LM[i][j][curZ];
                            int x=count%Xdim1;
                            int z=count/(Xdim1*Ydim1);
                            int y=(count/Xdim1)-(z*Ydim1);

                            if(FDT[x][y][z]>0)
                            {
                                b= (b*255)/FDT[x][y][z];if(b>255) b=255;
                                v= (v*255)/FDT[x][y][z];if(v>255) v=255;
                            }



                            if(b>v)
                            {
                                if(tFDT[i][j][curZ]==0)//index)//>0)//==maxInt)
                                {
                                    imagez.setPixel(i  ,j  , qRgb(255,0,255));
                                }
                                else
                                {


                                    //if(FDT[x][y][z]>0)
                                    //{
                                    //b= (b*255)/FDT[x][y][z];
                                    //if(b>255) b=255;
                                    imagez.setPixel(i,j, qRgb(0,b,0));
                                    //}
                                }
                            }
                            else
                            {
                                if(tFDT[i][j][curZ]==0)//==maxInt)
                                    //if(LM[i][j][curZ]==index)
                                {
                                    imagez.setPixel(i,j, qRgb(0,255,255));
                                }
                                else
                                {
                                    imagez.setPixel(i,j, qRgb(v,0,0));
                                }
                            }

              }//checkbox if
                        else if(ui->actionFuzzy_Connectivity->isChecked()==TRUE)//FC
                            {

                                if(abs(FCv[i][j][curZ]-FCb[i][j][curZ])<=10)//originally 10
                                {
                                }
                                else
                                {
                                    if(FCv[i][j][curZ]>FCb[i][j][curZ])
                                    {
                                        int v= (FCv[i][j][curZ]*2.55);
                                        imagez.setPixel(i,j, qRgb(v,0,0));
                                    }
                                    else
                                    {
                                        int b= (FCb[i][j][curZ]*2.55);
                                        imagez.setPixel(i,j, qRgb(0,b,0));
                                    }

                                }


                            }
                            else if(ui->actionMorphological_Reconstruction->isChecked()==TRUE)//MR
                                {
                                    if(MRv[i][j][curZ]<MRb[i][j][curZ])
                                    {
                                        //int v= (-MRv[i][j][curZ]*2.55);
                                        imagez.setPixel(i,j, qRgb(255,0,0));
                                    }
                                    else
                                        if(MRv[i][j][curZ]>MRb[i][j][curZ] /*&& ui->checkBox_8->isChecked()==FALSE*/)
                                        {
                                            //int b= (-MRb[i][j][curZ]*2.55);
                                            imagez.setPixel(i,j, qRgb(0,255,0));
                                        }
//                                    else
//                                      imagez.setPixel(i,j, qRgb(255,255,255));
                                }
                                else if(ui->actionShow_Seed_Sep->isChecked()==TRUE)//Seeds and Sep
                                    {
                                        if(SS[i][j][curZ]==1)
                                        {
                                            imagez.setPixel(i,j, qRgb(255,0,0));
                                        }
                                        else
                                            if(SS[i][j][curZ]==2)
                                            {
                                                imagez.setPixel(i,j, qRgb(0,255,0));
                                            }
                                            else if(SS[i][j][curZ]==3)
                                                {
                                                    imagez.setPixel(i,j, qRgb(0,0,255));
                                                }
                                    }

        }//for loop

    if(ui->actionShow_Gridlines->isChecked()==TRUE)//Gridlines
    {
        value = qRgb(0, 0, 255);
        for(int i=0;i<Ydim1;i++)
        {
            imagez.setPixel(curX,i, value );
        }
        value = qRgb(255, 0, 0);
        for(int i=0;i<Xdim1;i++)
        {
            imagez.setPixel(i,curY, value );
        }
    }
    ui->sliceLabel->setMinimumHeight(zoomscale*(Ydim1-1));
    ui->sliceLabel->setMinimumWidth(zoomscale*(Xdim1-1));
    ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
    /////////////////////////////////////////////////////////////

    ui->label_12->setNum(region[curX][curY][curZ]);



    ////////////////////////////Overlay text

    if (ui->actionShow_Segmented_Spine_Id->isChecked())
    {
        int rindex=ui->ROIList->currentRow()+1;
        if(!listROI[rindex].analysis_flag)return;
        QPainter painter(&imagez);
        painter.setPen(Qt::yellow);
        painter.setFont(QFont("Arial", 10,75));
        char buffer[10];
        //spcount[ui->ROIList->currentRow()+1]=0;
        //spcount[ui->ROIList->currentRow()+1]+=spcount[i];
       // spcount[ui->ROIList->currentRow()+1]=spcount[ui->ROIList->currentRow()+1]+sid-1;

        int spc=0;
        for(int i=1;i<rindex;i++)
        {
            spc=spc+segspcount[i];
        }
        segspcount[rindex]=sid-1;
        for(int i=1;i<sid;i++)
        {

            if(spine[i].spine_flag=='1')
            {
                sprintf(buffer,"%d",(spine[i].sp_id+spc));
                painter.drawText((spine[i].x1+spine[i].x2)/2-4,(spine[i].y1+spine[i].y2)/2+4,buffer);
            }
        }
        ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
    }

    if(ui->actionDendrite->isChecked())
    {

        QPainter painter(&imagez);
        painter.setPen(Qt::green);
        painter.setFont(QFont("Arial", 10,75));
        char buffer[10];

        for(int i=1;i<dcount[roindex];i++)
        {
            sprintf(buffer,"%d",i);
            if(den[roindex].dsz[i]==curZ||den[roindex].dsz[i]==curZ-1||den[roindex].dsz[i]==curZ+1)
            painter.drawText(den[roindex].dsx[i]+4,den[roindex].dsy[i]+4,buffer);
        }
        ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
    }

    if(ui->actionSeparator->isChecked())
    {

        QPainter painter(&imagez);
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 10,75));
        char buffer[10];
        for(int i=1;i<sepcount[roindex];i++)
        {
            sprintf(buffer,"%d",i);
            if(sep[roindex].sepz[i]==curZ||sep[roindex].sepz[i]==curZ-1||sep[roindex].sepz[i]==curZ+1)
            painter.drawText(sep[roindex].sepx[i]+4,sep[roindex].sepy[i]+4,buffer);
        }
        ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
    }

    if(ui->actionSpine->isChecked())
    {

        int spc=0;
        QPainter painter(&imagez);
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 10,75));
        char buffer[10];
        for(int i=1;i<dspcount[roindex];i++)
        {
            spc++;
            sprintf(buffer,"%d",i);
            if(dspine[roindex].dssz[i]==curZ||dspine[roindex].dssz[i]==curZ-1||dspine[roindex].dssz[i]==curZ+1)
            painter.drawText(dspine[roindex].dssx[i]+4,dspine[roindex].dssy[i]+4,buffer);
        }
        ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
       // qDebug()<<"no of spine seed::"<<spc;;
    }
}

void MainWindow::on_spinBox_curX_valueChanged(int x)
{
    if(ui->showOriginal->isChecked())
    {
        curX=x;
        draw_fullimage();
    }
    else
    {
        curX=x;
        draw_image();
    }
}

void MainWindow::on_spinBox_curY_valueChanged(int y)
{
    if(ui->showOriginal->isChecked())
    {
        curY=y;
        draw_fullimage();
    }
    else
    {
        curY=y;
        draw_image();
    }
}

void MainWindow::on_spinBox_curZ_valueChanged(int z)
{
    if(ui->showOriginal->isChecked())
    {
        curZ=z;
        draw_fullimage();
    }
    else
    {
        curZ=z;
        draw_image();
    }
}

void MainWindow::wheelEvent(QWheelEvent *e)
{
    int t,v;
    if(ui->showOriginal->isChecked())
    {
        if(e->orientation() == Qt::Vertical/*&&e->modifiers()==Qt::CTRL*/)
        {
            t= (int)(e->delta())/120;
            v=ui->spinBox_curZ->value();

            if (v>=0 && v<=Zdim-1)
            {
                if(v==0 && t<0) return;
                if(v==Zdim-1 && t>0) return;

                ui->spinBox_curZ->setValue(v+t);
            }
        }
    }
    else
    {
        if(e->orientation() == Qt::Vertical)
        {
            t= (int)(e->delta())/120;
            v=ui->spinBox_curZ->value();

            if (v>=0 && v<=Zdim1-1)
            {
                if(v==0 && t<0) return;
                if(v==Zdim1-1 && t>0) return;

                ui->spinBox_curZ->setValue(v+t);
            }
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
if(e->buttons()==Qt::RightButton)
{
  if(ui->showOriginal->isChecked())
  {
      QMessageBox msgBox;
      msgBox.setIcon(QMessageBox::Warning);
      msgBox.setWindowTitle("3dSpAn");
      msgBox.setText("Selct a Region first to Zoom");
      msgBox.exec();
      return;
  }
  if(e->pos().y()>mouseY)
  {
   mouseY=e->pos().y();
   mousefp++;
   if(mousefp>10)
   {
       mousefp=0;
       if(zoomscale>1)
       zoomscale=zoomscale-1;
       draw_image();
   }
  }
  else if(e->pos().y()<mouseY)
  {
    mouseY=e->pos().y();
    mousefn++;
    if(mousefn>10)
    {
        mousefn=0;
        zoomscale=zoomscale+1;
        draw_image();
    }
  }
}

if(e->buttons()==Qt::LeftButton)
{

    if(!ui->showOriginal->isChecked()&&ui->selectRegion->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Select a region from original image to crop");
        msgBox.exec();
        return;
    }
    if(ui->actionSelect_a_region->isChecked())
    {

        //qDebug()<<"Inside mouse movement and region checked\n";
        int qx=(e->x()-ui->scrollArea->x()+ui->scrollArea->horizontalScrollBar()->value())-ui->sliceLabel->x()-1;
        int qy=(e->y()-ui->scrollArea->y()-ui->mainToolBar->height()-ui->menuBar->height()+ui->scrollArea->verticalScrollBar()->value())-ui->sliceLabel->y()-1;
        if(qx<Xdim && qy<Ydim && qx>recX && qy>recY)
         {
            recL=abs((qy-recY));
            recW=abs((qx-recX));
         }
         if(recX!=-1&&recY!=-1&&recL&&recW)
         draw_fullimage();
    }
}
}

void MainWindow::mousePressEvent(QMouseEvent *e )
{

    /*if(e->button()==Qt::RightButton)
    {
        mouseY=0;mousefp=0,mousefn=0;
    }*/
    if(start==0)return;
    QPoint pt,pt1;
    char name[200];
    int x,y;
   // pt=e->pos();
    int q;
    if(e->buttons()==Qt::RightButton)return;
    q=(e->x()-ui->scrollArea->x()+ui->scrollArea->horizontalScrollBar()->value());
    x=q-ui->sliceLabel->x()-1;

    q=(e->y()-ui->scrollArea->y()-ui->mainToolBar->height()-ui->menuBar->height()+ui->scrollArea->verticalScrollBar()->value());
    y=q-ui->sliceLabel->y()-1;

   // x=pt.x()-ui->scrollArea->x()+ui->scrollArea->horizontalScrollBar()->value();
    //y=pt.y()-ui->scrollArea->y()-ui->mainToolBar->height()+ui->scrollArea->verticalScrollBar()->value();
    x=x/zoomscale;
    y=y/zoomscale;

    if(ui->showOriginal->isChecked())
        {

            if(Xdim==0 ||Ydim==0 ||Zdim==0) return;


            if(x>0 && y>0&&
                    x<(Xdim) &&
                    y<(Ydim))

            {
                //qDebug()<<"Value x................."<<x;
                curX=x;
                curY=y;
                if(ui->actionSelect_a_region->isChecked())
                {
                    recX=curX;
                    recY=curY;
                }
                qDebug()<<"Value curX"<<curX;
                qDebug()<<"Value of curY"<<curY;
                ui->label_12->setNum(vol[curX][curY][curZ]);
                ui->spinBox_curX->setValue(curX);//me->globalX());
                ui->spinBox_curY->setValue(curY);//me->globalX());
              //  qDebug()<<"Value recX"<<recX;
                //qDebug()<<"Value of recY"<<recY<<","<<y;
                if(ui->actionShow_Gridlines->isChecked()==TRUE)
                {
                    draw_fullimage();
                }
             }
        }
        else
        {

            if(Xdim1==0 ||Ydim1==0 ||Zdim1 ==0) return;


            if(x>0 && y>0&&
                    x<(Xdim1) &&
                    y<(Ydim1))

            {
                //qDebug()<<"Value x................."<<x;
                curX=x;
                curY=y;
//                recX=curX;
//                recY=curY;
                //qDebug()<<"Value curX"<<curX;
                ui->label_12->setNum(region[curX][curY][curZ]);
                ui->spinBox_curX->setValue(curX);//me->globalX());
                ui->spinBox_curY->setValue(curY);//me->globalX());

                if(ui->actionShow_Gridlines->isChecked()==TRUE)
                {
                    draw_image();
                }
             }
        }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(ui->actionSelect_a_region->isChecked())
    {
//              qDebug()<<"value of recX after release"<<recX<<"\n";
//              qDebug()<<"value of recY after release"<<recY<<"\n";

    }
}

void MainWindow::on_actionShow_Gridlines_triggered()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())draw_fullimage();
    else draw_image();
}

void MainWindow::on_actionFuzzy_Segment_triggered()
{
    if(start!=0)
    {
        if(ui->showOriginal->isChecked())draw_fullimage();
        else
        {
            draw_image();
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->showOriginal->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Crop a region to add seed");
        msgBox.exec();
        return;
    }
    int rindex=ui->ROIList->currentRow()+1;
    if(ui->comboBox->currentText()=="Spine")
    {
        if(start==0)return;
//        spine[dspcount[rindex]].seed.x=curX;
//        spine[dspcount[rindex]].seed.y=curY;
//        spine[dspcount[rindex]].seed.z=curZ;
        dspine[rindex].dssx[dspcount[rindex]]=curX;
        dspine[rindex].dssy[dspcount[rindex]]=curY;
        dspine[rindex].dssz[dspcount[rindex]]=curZ;
        dspcount[rindex]++;
        //dspID++;
        ui->actionShow_Seed_Sep->setChecked(true);
        on_actionShow_Seed_Sep_triggered();
    }
    else if(ui->comboBox->currentText()=="Dendrite")
    {
        if(start==0)return;
        den[rindex].dsx[dcount[rindex]]=curX;
        den[rindex].dsy[dcount[rindex]]=curY;
        den[rindex].dsz[dcount[rindex]]=curZ;
        dcount[rindex]++;
        ui->actionShow_Seed_Sep->setChecked(true);
        on_actionShow_Seed_Sep_triggered();
    }
    else if(ui->comboBox->currentText()=="Separator")
    {
        if(start==0)return;
        sep[rindex].sepx[sepcount[rindex]]=curX;
        sep[rindex].sepy[sepcount[rindex]]=curY;
        sep[rindex].sepz[sepcount[rindex]]=curZ;
        sepcount[rindex]++;
        ui->actionShow_Seed_Sep->setChecked(true);
        on_actionShow_Seed_Sep_triggered();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Select a seed type");
        msgBox.exec();
        return;
    }
}

void MainWindow::on_actionShow_Seed_Sep_triggered()
{
    if(start!=0)
    {
        if(ui->showOriginal->isChecked())
        {
            return;
        }
        if(ui->actionShow_Seed_Sep->isChecked())
        {
            load_seeds();
            draw_image();
        }
        else
        {
            ui->actionSpine->setChecked(false);
            ui->actionDendrite->setChecked(false);
            ui->actionSeparator->setChecked(false);
            draw_image();
        }
    }
}

void MainWindow::load_seeds()
{
    int z,y,x;


    for(int i=0;i<Xdim1;i++)
        for(int j=0;j<Ydim1;j++)
            for(int k=0;k<Zdim1;k++)
                SS[i][j][k]=0;


    int rindex=ui->ROIList->currentRow()+1;
    for(int i=1;i<dspcount[rindex];i++)
    {
        z=dspine[rindex].dssz[i];
        y=dspine[rindex].dssy[i];
        x=dspine[rindex].dssx[i];
        SS[x][y][z]=1;
        SS[x-1][y][z]=1;
        SS[x+1][y][z]=1;
        SS[x][y-1][z]=1;
        SS[x][y+1][z]=1;
        SS[x][y][z+1]=1;
        SS[x][y][z-1]=1;

    }

    for(int i=1;i<dcount[rindex];i++)
    {
        x=den[rindex].dsx[i];
        y=den[rindex].dsy[i];
        z=den[rindex].dsz[i];
        SS[x][y][z]=2;
        SS[x-1][y][z]=2;
        SS[x+1][y][z]=2;
        SS[x][y-1][z]=2;
        SS[x][y+1][z]=2;
        SS[x][y][z+1]=2;
        SS[x][y][z-1]=2;

    }

    for(int i=1;i<sepcount[rindex];i++)
    {
        x=sep[rindex].sepx[i];
        y=sep[rindex].sepy[i];
        z=sep[rindex].sepz[i];
        SS[x][y][z]=3;
        SS[x-1][y][z]=3;
        SS[x+1][y][z]=3;
        SS[x][y-1][z]=3;
        SS[x][y+1][z]=3;
        SS[x][y][z+1]=3;
        SS[x][y][z-1]=3;

    }
}

void MainWindow::on_pushButton_test_clicked()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Crop a region to run segmentation");
        msgBox.exec();
        return;
    }
    if(start!=0)
    {

        ui->actionFuzzy_Segment->setChecked(Qt::Unchecked);
        listROI[ui->ROIList->currentRow()+1].ta=ui->spinBox_ta->value();
        listROI[ui->ROIList->currentRow()+1].tb=ui->spinBox_tb->value();
        listROI[ui->ROIList->currentRow()+1].tbp=ui->spinBox_tbp->value();
        listROI[ui->ROIList->currentRow()+1].segment_flag=1;
        if(ui->actionSpine->isChecked())
        {
            ui->actionSpine->setChecked(false);
            draw_image();
        }
        if(ui->actionDendrite->isChecked())
        {
            ui->actionDendrite->setChecked(false);
            draw_image();
        }
        if(ui->actionSeparator->isChecked())
        {
            ui->actionSeparator->setChecked(false);
            draw_image();
        }
        if(ui->actionShow_Seed_Sep->isChecked())
        {
            ui->actionShow_Seed_Sep->setChecked(false);
            draw_image();
        }
        load_seeds();

       // ui->spinBox_ta->setValue(ui->spinBox_tap->value());

        short pixelValue ;
        int ta=ui->spinBox_ta->value();
        int tb=ui->spinBox_tb->value();
        //int tap=ui->spinBox_tap->value();
        int tbp=ui->spinBox_tbp->value();


        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                {
                    pixelValue = region[i][j][k];

                    if(pixelValue>tb||pixelValue<ta)
                        FDTv[i][j][k]=0;
                    else
                        FDTv[i][j][k]=65000;



                    //              if(i==0 ||j==0||k<=ui->spinBox_TA->value()//Ignore slices causing Tooth Artifacts
                    //                  ||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) FDTv[i][j][k]=0;

                }

        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                    if(SS[i][j][k]==2)//B
                        FDTv[i][j][k]=0;



        Flag=2;//0;//2;
        ui->Plabel->setText("Computing FDT for Spine...");
        compute_FDT(FDTv);


        /*

     for(int i=0;i<Xdim1;i++)
     for(int j=0;j<Ydim1;j++)
         for(int k=0;k<Zdim1;k++)
                 FDTb[i][j][k]=0;

     FDT=FDTv;


     ///////////////////////////////
     maxFDT=0;
     for(int i=0;i<Xdim1;i++)
     for(int j=0;j<Ydim1;j++)
         for(int k=0;k<Zdim1;k++)
             if(FDT[i][j][k]==65000) continue;
             else
             if(FDT[i][j][k]>maxFDT)
                 maxFDT=FDT[i][j][k];
     std::cout<<"maxFDT:"<<maxFDT<<std::endl;
     ////////////////////////////////
    */



        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                {
                    pixelValue =region[i][j][k];

                    if(pixelValue <ta || pixelValue > tbp)//B
                        FDTb[i][j][k]=0;
                    else
                        FDTb[i][j][k]=65000;


                    //             if(i==0 ||j==0||k<=ui->spinBox_TA->value()//Ignore slices causing Tooth Artifacts
                    //                ||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) FDTb[i][j][k]=0;

                }


        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                    if(SS[i][j][k]==1)//Vessel Seeds
                        FDTb[i][j][k]=0;

        /*for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                    //if(FCv[i][j][k]>0)
                    if(out[i][j][k]==5)//core vessel
                    {
                        FDTb[i][j][k]=0;
                    }*/



        Flag=2;//1;//2;
        ui->Plabel->setText("Computing FDT for Dendrite...");
        compute_FDT(FDTb);


        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                {
                    pixelValue =region[i][j][k];

                    if(pixelValue > tbp||pixelValue<ta)//Outside Dendrite and Spine
                        FDT[i][j][k]=0;
                    else
                        FDT[i][j][k]=65000;

                    //              if(i==0 ||j==0||k<=ui->spinBox_TA->value()//Ignore slices causing Tooth Artifacts
                    //                  ||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) FDT[i][j][k]=0;

                }

        Flag=2;
        ui->Plabel->setText("Computing FDT for Dendrite-Spine ...");
        compute_FDT(FDT);
        ui->actionFuzzy_Distance_Transform->setChecked(true);
        LMLS();//LM-LS

        GITN=0;
        ui->Plabel->setText("Completed LM-LS ...");
        FCMR();
        ui->Plabel->setText("FCMR Completed...");
    }
    ui->actionSave_ROIProfile->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->actionFuzzy_Distance_Transform->setEnabled(true);
    ui->actionFuzzy_Connectivity->setEnabled(true);
    ui->actionMorphological_Reconstruction->setEnabled(true);
    ui->pushButton_CH->setEnabled(true);
}

void MainWindow::LMLS()
{
    for(int i=0;i<Xdim1;i++)
        for(int j=0;j<Ydim1;j++)
            for(int k=0;k<Zdim1;k++)
            {
                tFDT[i][j][k]=65000;
                LM[i][j][k]=0;
            }

    ui->Plabel->setText("Computing LM for Spine and Dendrite...");
    ui->label_itn->setText("");

    local_maxima();
    draw_image();
    ////end of local maxima
    ui->Plabel->setText("Computing Local Scale for Spine and Dendrite...");
    local_scale();
    draw_image();
}

void MainWindow::FCMR()
{
    //qDebug()<<"\n In FCMR";
    if(start==0)return;
    if(ui->actionSpine->isChecked())
    {
        ui->actionSpine->setChecked(true);
        draw_image();
    }
    if(ui->actionDendrite->isChecked())
    {
        ui->actionDendrite->setChecked(true);
        draw_image();
    }
    if(ui->actionSeparator->isChecked())
    {
        ui->actionSeparator->setChecked(true);
        draw_image();
    }
    if(ui->actionShow_Seed_Sep->isChecked())
    {
        ui->actionShow_Seed_Sep->setChecked(true);
        draw_image();
    }

    unsigned short min=0,temp;
    long F_countv=0,F_countb=0;//,max=0;
    //int itn=0;
    int newCnt;

    point tp;
    QQueue<point> VQ;
    QQueue<point> BQ;


    if(GITN==0)
    {
        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                {
                    FCb[i][j][k]=FCv[i][j][k]=0;
                    MRb[i][j][k]=MRv[i][j][k]=0;
                }
    }

    //    int tb =ui->spinBox_tb->value();
    do//Big Loop
    {

        ui->actionFuzzy_Distance_Transform->setChecked(false);
        ui->actionFuzzy_Connectivity->setChecked(true);
        std::cout<<"Computing FC-MR...Itn::"<<GITN<<std::endl;
        ui->label_itn->setNum(GITN);
        Flag=0;
        F_countv=0;
        F_countb=0;
        if(GITN>0)
        {
            for(int i=0;i<Xdim1;i++)
                for(int j=0;j<Ydim1;j++)
                    for(int k=0;k<Zdim1;k++)
                    {


                        if(MRv[i][j][k]<MRb[i][j][k])//Vessel Seed
                            //if((FCv[i][j][k]-FCb[i][j][k])>=10)
                        {

                            if(FCv[i][j][k]!=100)//risky step..not pushing all seeds
                            {

                                tp.x=i;tp.y=j;tp.z=k;
                                VQ.enqueue(tp);

                                FCv[i][j][k]=100;
                                FCb[i][j][k]=0;
                                FDTb[i][j][k]=0;

                                F_countv++;
                            }


                        }
                        else
                            //if((FCb[i][j][k]-FCv[i][j][k])>=10)
                            if(MRb[i][j][k]<MRv[i][j][k])//B Seed
                            {

                                if(FCb[i][j][k]!=100)//risky step
                                {
                                    tp.x=i;tp.y=j;tp.z=k;
                                    BQ.enqueue(tp);
                                    FCb[i][j][k]=100;
                                    FCv[i][j][k]=0;
                                    FDTv[i][j][k]=0;
                                    F_countb++;
                                }
                            }
                            else
                            {
                                if(MRb[i][j][k] < 0) ////// Here: MRb[i][j][k] == MRv[i][j][k]
                                {
                                    FDTb[i][j][k]=0;
                                    FDTv[i][j][k]=0;
                                }
                                MRb[i][j][k]=MRv[i][j][k]=0;
                                FCb[i][j][k]=FCv[i][j][k]=0;
                            }


                        /*
                    if((FCv[i][j][k]-FCb[i][j][k])>=10)
                        FCv[i][j][k]=100;
                    else
                    if((FCb[i][j][k]-FCv[i][j][k])>=10)
                        FCb[i][j][k]=100;
                    else
                    {
                        FCb[i][j][k]=FCv[i][j][k]=0;
                    }
                    */

                    }
        }


        if(GITN==0)
        {
            /*
for(int i=0;i<Xdim1;i++)
      for(int j=0;j<Ydim1;j++)
          for(int k=0;k<Zdim1;k++)
              if(FCv[i][j][k]>0)
              {
                  FCv[i][j][k]=100;
                  tp.x=i;tp.y=j;tp.z=k;
                  VQ.enqueue(tp);
                  FDTb[i][j][k]=0;
                  FCb[i][j][k]=0;

              }

  FILE *fpvs;
  fpvs=fopen("vseed","r");
  if(fpvs != NULL){
  while(!feof(fpvs))
  {
      int x,y,z;
      fscanf(fpvs,"%d%d%d",&x,&y,&z);
      tp.x=x;tp.y=y;tp.z=z;
      VQ.enqueue(tp);
      FCv[x][y][z]=100;
      FDTb[x][y][z]=0;
      FCb[x][y][z]=0;
  }
  fclose(fpvs);
 }
*/

            for(int i=0;i<Xdim1;i++)
                for(int j=0;j<Ydim1;j++)
                    for(int k=0;k<Zdim1;k++)
                        if(SS[i][j][k]==1)//Spine Seeds
                        {

                            FCv[i][j][k]=100;
                            tp.x=i;tp.y=j;tp.z=k;
                            VQ.enqueue(tp);
                            FDTb[i][j][k]=0;
                            FCb[i][j][k]=0;

                        }


            for(int i=0;i<Xdim1;i++)
                for(int j=0;j<Ydim1;j++)
                    for(int k=0;k<Zdim1;k++)
                        //if(FCv[i][j][k]>0)
                        if(out[i][j][k]==5)//core vessel
                        {
                            FCv[i][j][k]=100;
                            tp.x=i;tp.y=j;tp.z=k;
                            VQ.enqueue(tp);
                            FDTb[i][j][k]=0;
                            FCb[i][j][k]=0;

                        }


        }

       // ui->Plabel->setText("Computing F-C for Spine...");
        //std::cout<<"Computing F-C for Spine..."<<std::endl;

        //std::cout<<std::endl;

        //max=VQ.size();
        std::cout<<"FC_Spine: Q Size:"<<VQ.size()<<std::endl;

        //F_count=0;

        while(!VQ.isEmpty())
        {
            tp=VQ.dequeue();
            int i=tp.x;int j=tp.y;int k=tp.z;
            if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) continue;

            min=FCv[i][j][k];
            for(int l=0;l<26;l++)
            {
                if (FDTv[i+V[l][0]][j+V[l][1]][k+V[l][2]] <=0) continue;
                if(FCv[i+V[l][0]][j+V[l][1]][k+V[l][2]]==100) continue;



                //if(NML[i+V[l][0]][j+V[l][1]][k+V[l][2]]==1 && GITN==0) continue;//ui->checkBox_10->isChecked()==TRUE) continue;


                unsigned long count=LM[i+V[l][0]][j+V[l][1]][k+V[l][2]];
                int x=count%Xdim1;
                int z=count/(Xdim1*Ydim1);
                int y=(count/Xdim1)-(z*Ydim1);

                if(FDT[x][y][z]==0) continue;

                temp=100*FDTv[i+V[l][0]][j+V[l][1]][k+V[l][2]]/FDT[x][y][z];
                //temp=ceil(temp-0.5);

                if(temp<min) min=temp;

                if(min>FCv[i+V[l][0]][j+V[l][1]][k+V[l][2]])
                {
                    FCv[i+V[l][0]][j+V[l][1]][k+V[l][2]]=min;

                    //if(NML[i+V[l][0]][j+V[l][1]][k+V[l][2]]==1 && GITN==0) continue;

                    tp.x=i+V[l][0];
                    tp.y=j+V[l][1];
                    tp.z=k+V[l][2];
                    VQ.enqueue(tp);

                    //F_count++;
                }
            }

            //if(VQ.size()>max) max=Q.size();
            //ui->progressBar->setValue(100*(1-(Q.size()/max)));
            //printf("\rFC_Vessel:Updated points: %ld",F_count);
            //std::cout<<"FC_Vessel:"<<"Q Size:"<<Q.size()<<std::endl;
            //fflush(stdout);

        }

        //////////////////////

        std::cout<<"Updated FC points for Spine::"<<F_countv<<std::endl;

       // ui->Plabel->setText("Computing F-C for Dendrite...");
        //std::cout<<"Computing F-C for Dendrite..."<<std::endl;




        if(GITN==0)
        {


            int tb =ui->spinBox_tb->value();
            for(int i=0;i<Xdim1;i++)
                for(int j=0;j<Ydim1;j++)
                    for(int k=0;k<Zdim1;k++)
                        if(region[i][j][k]>tb || SS[i][j][k]==2)//B seeds
                        {
                            FCb[i][j][k]=100;
                            tp.x=i;tp.y=j;tp.z=k;
                            BQ.enqueue(tp);
                            FDTv[i][j][k]=0;
                            FCv[i][j][k]=0;
                        }

            /*
  FILE *fpbs;
  fpbs=fopen("bseed","r");
  if(fpbs != NULL){
  while(!feof(fpbs))
  {
      int x,y,z;
      fscanf(fpbs,"%d%d%d",&x,&y,&z);
      tp.x=x;tp.y=y;tp.z=z;
      if(FCb[x][y][z]!=100)
      {
      BQ.enqueue(tp);
      FCb[x][y][z]=100;
      FDTv[x][y][z]=0;
      }
  }
  fclose(fpbs);
}
*/

        }


        //std::cout<<"FC_B: Q Size:"<<BQ.size()<<std::endl;
        //F_count=0;
        while(!BQ.isEmpty())
        {
            tp=BQ.dequeue();
            int i=tp.x;int j=tp.y;int k=tp.z;
            if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) continue;

            min=FCb[i][j][k];
            for(int l=0;l<26;l++)
            {
                if(FDTb[i+V[l][0]][j+V[l][1]][k+V[l][2]] <=0) continue;
                if(FCb[i+V[l][0]][j+V[l][1]][k+V[l][2]]==100) continue;
                if(FCv[i+V[l][0]][j+V[l][1]][k+V[l][2]]==100) continue;
                //if(NML[i+V[l][0]][j+V[l][1]][k+V[l][2]]==1 && GITN==0) continue;//&& ui->checkBox_10->isChecked()==TRUE) continue;



                unsigned long count=LM[i+V[l][0]][j+V[l][1]][k+V[l][2]];
                int x=count%Xdim1;
                int z=count/(Xdim1*Ydim1);
                int y=(count/Xdim1)-(z*Ydim1);

                if(FDT[x][y][z]==0) continue;

                temp=100*FDTb[i+V[l][0]][j+V[l][1]][k+V[l][2]]/FDT[x][y][z];
                //temp=ceil(temp-0.5);

                if(temp<min) min=temp;

                if(min>FCb[i+V[l][0]][j+V[l][1]][k+V[l][2]])
                {
                    FCb[i+V[l][0]][j+V[l][1]][k+V[l][2]]=min;

                    //if(NML[i+V[l][0]][j+V[l][1]][k+V[l][2]]==1 && GITN==0) continue;

                    tp.x=i+V[l][0];
                    tp.y=j+V[l][1];
                    tp.z=k+V[l][2];
                    BQ.enqueue(tp);

                    //F_count++;
                }
            }

            //ui->progressBar->setValue(100*(Q.size()/)

            //printf("\rFC_B:Updated points: %ld",F_count);
            //std::cout<<"FC_B:"<<"Q Size:"<<Q.size()<<std::endl;
            //fflush(stdout);
        }

        //NML consideration for GITN==0
        /*
  if(ui->checkBox_4->isChecked()==TRUE)//NML consideration
  {
     for(int i=0;i<Xdim1;i++)
      for(int j=0;j<Ydim1;j++)
        for(int k=0;k<Zdim1;k++)
           if(NML[i][j][k]==1)
               FCb[i][j][k]=FCv[i][j][k]=0;

  }
*/


        //std::cout<<std::endl;

        /////////////////////




        std::cout<<"Updated FC points for Dendrite::"<<F_countb<<std::endl;

        draw_image();

        MR();//MR
        draw_image();
        GITN++;


        //populate output
        newCnt=0;
        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                {
                    if(MRv[i][j][k]<MRb[i][j][k])
                    {
                        if(out[i][j][k]==0)
                        {
                            out[i][j][k]=5+(3*GITN);
                            qDebug()<<"New count increased\n";
                            newCnt++;
                        }
                    }

                }

        std::cout<<"New Spine points in this iteration::"<<newCnt<<std::endl;

        ////////////////////




        //if(ui->checkBox_7->isChecked()==FALSE) break;

    }while(newCnt>0);

    int r=ui->ROIList->currentRow()+1;
    int value;
    for (int slice=0;slice<Zdim1;slice++)
    {
        for (int column=0;column<Ydim1;column++)
        {
            for (int row=0; row<Xdim1;row++)
            {
                value=0;
                if(MRv[row][column][slice]<MRb[row][column][slice])
                {
                    value=50;//spine
                }
                else if(MRv[row][column][slice]>MRb[row][column][slice])
                {
                        value=100;//dendrite
                }
                out[row][column][slice]=value;
                output[row+listROI[r].recX][column+listROI[r].recY][slice]=value;
            }
        }
    }

}

void MainWindow::local_maxima()
{
    std::cout<<"\nInside Local Maxima";
    unsigned short max=0,temp;
    int l=2,BG=0;
    unsigned long F_count1=0,index;


    for(int i=l;i<Xdim1-l;i++)
    {
        for(int j=l;j<Ydim1-l;j++)
            for(int k=l;k<Zdim1-l;k++)
            {
                if(FDT[i][j][k]<=0) continue;
                //if(NML[i][j][k]==1) continue;//No LM in No Mans Land

                max=FDT[i-l][j-l][k-l];

                BG=0;
                for(int x=-l;x<=l;x++)
                {
                    for(int y=-l;y<=l;y++)
                    {
                        for(int z=-l;z<=l;z++)

                        {
                            //               temp=FDT[i+V[l][0]][j+V[l][1]][k+V[l][2]];
                            if(x==-l && y==-l && z==-l) continue;
                            if(x==0 && y==0 && z==0) continue;

                            temp=FDT[i+x][j+y][k+z];

                            //                     if(temp<=0) {BG=1; break;}

                            if(temp>max)
                                max=temp;
                        }
                        //          if (BG==1) break;
                    }
                    //      if (BG==1) break;
                }
               if (max<200) continue; //Noisy LM within 2 voxel of boundary
                if(abs(FDT[i][j][k]-max)<=10 && BG==0)
                {
                    index=k*Xdim1*Ydim1+j*Xdim1+i;
                    LM[i][j][k]=index;
                    tFDT[i][j][k]=0;
                    //LM[i][j][k]=++F_count;//maxInt;
                    F_count1++;
                }

            }
        ui->progressBar->setValue((100*i)/(Xdim1-2)+1);
    }

    std::cout<<"\nLM points for Dendrite and Spine:"<<F_count1<<std::endl;

}

void MainWindow::local_scale()
{
    unsigned short min,temp;
    int i,j,k,d;
    float mu_p,mu_q;
    short pixelValue;

    int ta=ui->spinBox_ta->value();
    int tb=ui->spinBox_tb->value();
    //int tap=ui->spinBox_tap->value();
    //int tbp=ui->spinBox_tbp->value();


    int itn=0;
    long F_count=0;
    //do
    {

        ui->label_itn->setNum(++itn);

        F_count=0;
        for(i=1;i<Xdim1-1;i++)//Pos FDT
        {
            for(j=1;j<Ydim1-1;j++)
                for(k=1;k<Zdim1-1;k++)
                {
                    if(FDT[i][j][k]==0) continue;
                    if(tFDT[i][j][k]==0) continue;

                    mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
                    if (Flag==2 && mu_p<0.5) mu_p=1-mu_p;
                    //    if (Flag==0) mu_p=1-mu_p;

                    if(Flag==5)
                    {
                        pixelValue = region[i][j][k];

//                        if(pixelValue <ta)
//                        {
//                            mu_p=0;
//                        }
//                        else
                            if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                            {
                                mu_p=(float)(tb-pixelValue)/(tb-ta);
                            }

                    }

                    if (mu_p>1) mu_p=1;

                    min = tFDT[i][j][k];
                    for(d=0;d<13;d++)
                    {
                        if(FDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]==0) continue;

                        mu_q=(float)(region[i+V[d][0]][j+V[d][1]][k+V[d][2]]-ta)/(tb-ta);
                        if (Flag==2 && mu_q<0.5) mu_q=1-mu_q;
                        //        if (Flag==0) mu_q=1-mu_q;
                        if(Flag==5)
                        {
                            pixelValue = region[i][j][k];

//                            if(pixelValue <ta)
//                            {
//                                mu_q=0;
//                            }
//                            else
                                if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                                {
                                    mu_q=(float)(tb-pixelValue)/(tb-ta);
                                }

                        }

                        if (mu_q>1) mu_q=1;

                        temp=tFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];

                        temp=ceil(temp-0.5);
                        //temp*=100;

                        if(temp<0) temp=0;


                        if(temp<min)
                        {tFDT[i][j][k] = temp; min = temp; LM[i][j][k] = LM[i+V[d][0]][j+V[d][1]][k+V[d][2]];F_count++;}
                    }

                }
            ui->progressBar->setValue((50*i)/(Xdim1-2)+1);
        }//Outer for loop pos FDT


        for(i=Xdim1-2;i>0;i--)//Neg FDT
        {
            for(j=Ydim1-2;j>0;j--)
                for(k=Zdim1-2;k>0;k--)
                {
                    if(FDT[i][j][k]==0) continue;
                    if(tFDT[i][j][k]==0) continue;

                    mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
                    if (Flag==2 && mu_p<0.5) mu_p=1-mu_p;
                    //    if (Flag==0) mu_p=1-mu_p;

                    if(Flag==5)
                    {
                        pixelValue = region[i][j][k];

//                        if(pixelValue <ta)
//                        {
//                            mu_p=0;
//                        }
//                        else
                            if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                            {
                                mu_p=(float)(tb-pixelValue)/(tb-ta);
                            }

                    }


                    if (mu_p>1) mu_p=1;

                    min = tFDT[i][j][k];
                    for(d=13;d<26;d++)
                    {
                        if(FDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]==0) continue;

                        mu_q=(float)(region[i+V[0][0]][j+V[0][1]][k+V[0][2]]-ta)/(tb-ta);
                        if (Flag==2 && mu_q<0.5) mu_q=1-mu_q;
                        //        if (Flag==0) mu_q=1-mu_q;

                        if(Flag==5)
                        {
                            pixelValue = region[i][j][k];

//                            if(pixelValue<ta)
//                            {
//                                mu_q=0;
//                            }
//                            else
                                if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                                {
                                    mu_q=(float)(tb-pixelValue)/(tb-ta);
                                }

                        }

                        if (mu_q>1) mu_q=1;

                        temp=tFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];

                        temp=ceil(temp-0.5);
                        //temp*=100;

                        if(temp<0) temp=0;

                        if(temp<min)
                        {tFDT[i][j][k] = temp; min = temp; LM[i][j][k] = LM[i+V[d][0]][j+V[d][1]][k+V[d][2]];F_count++;}
                    }

                }

            ui->progressBar->setValue(51+((Xdim1-2-i)*50/(Xdim1-2)));
        }//Outer for loop Neg FDT


        std::cout<<"LM-FDT Iteration:"<<itn<<", Updated points:"<<F_count<<std::endl;
        //  ui->label_12->setNum(F_count);
        //  draw_image();
    }//while(F_count>0);

}

void MainWindow::MR()
{

    short temp;
    int d;
    float mu_p,mu_q;
    long F_count=0;//,cnt=0;

    int ta=ui->spinBox_ta->value();
    int tb=ui->spinBox_tb->value();

    point tp;
    QQueue<point> Q;



    ui->actionFuzzy_Connectivity->setChecked(false);
    ui->actionMorphological_Reconstruction->setChecked(true);
    for(int i=1;i<Xdim1-1;i++)
        for(int j=1;j<Ydim1-1;j++)
            for(int k=1;k<Zdim1-1;k++)
            {
                //pixelValue = vol[i][j][k];

                //if(FCv[i][j][k]>FCb[i][j][k])//pixelValue <=tap || pixelValue > tb)//Vessel

                /*
            for(d=0,cnt=0;d<26;d++)
                if(FCv[i+V[d][0]][j+V[d][1]][k+V[d][2]]==100) cnt++;
            if(cnt==26) continue;//Working only with the peripheral seeds
*/
                //if(NML[i][j][k]==1 && GITN==0) continue;

                if((FCv[i][j][k]-FCb[i][j][k])>0)//originally 10
                {
                    MRv[i][j][k]=(-1)*FDTv[i][j][k];
                    tp.x=i;tp.y=j;tp.z=k;
                    Q.enqueue(tp);
                }
                else
                    MRv[i][j][k]=0;

                //              if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) FDTv[i][j][k]=0;

            }
    /*
  FILE *fpbs;
  fpbs=fopen("bseed","r");
  while(!feof(fpbs))
  {
      int x,y,z;
      fscanf(fpbs,"%d%d%d",&x,&y,&z);
      FDTv[x][y][z]=0;
  }
  fclose(fpbs);
*/

    //Flag=1;
    ui->Plabel->setText("Computing MR for Spine... Iteration:");
    // compute_MR(MRv);
    F_count=0;
    while(!Q.isEmpty())
    {
        tp=Q.dequeue();
        int i=tp.x;int j=tp.y;int k=tp.z;
        if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) continue;

        mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
        //if (Flag==0) mu_p=1-mu_p;

        if (mu_p<0.5) mu_p=1-mu_p;
        if (mu_p>1) mu_p=1;


        for(d=0;d<26;d++)
        {
            if(FDTv[i][j][k]<=FDTv[i+V[d][0]][j+V[d][1]][k+V[d][2]]) continue;

          //  if(NML[i+V[d][0]][j+V[d][1]][k+V[d][2]]==1 && GITN==0) continue;//ui->checkBox_10->isChecked()==TRUE) continue;

            mu_q=(float)(region[i+V[d][0]][j+V[d][1]][k+V[d][2]]-ta)/(tb-ta);

            if (mu_q<0.5) mu_q=1-mu_q;
            if (mu_q>1) mu_q=1;

            //temp=lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];
            temp=MRv[i][j][k]+50*(mu_p+mu_q)*D[d];

            //temp=ceil(temp-0.5);
            //temp*=100;

            //if(temp<0) temp=0;

            //printf("\r Here\n");

            if(MRv[i+V[d][0]][j+V[d][1]][k+V[d][2]]>temp && FCb[i+V[d][0]][j+V[d][1]][k+V[d][2]]!=100)//>=1.0)
            {
                MRv[i+V[d][0]][j+V[d][1]][k+V[d][2]]=temp;

                F_count++;

                tp.x=i+V[d][0];
                tp.y=j+V[d][1];
                tp.z=k+V[d][2];
                Q.enqueue(tp);
            }

        }

        //printf("\rMRv Q Size:%ld",Q.size());
        //printf("\rMRv:Updated points: %ld",F_count);
    }

    std::cout<<"Updated MR points for Spine  ::"<<F_count<<std::endl;
    //std::cout<<std::endl;
//    ui->Plabel->setText("Completed MRv once");
//    return;

    for(int i=1;i<Xdim1-1;i++)
        for(int j=1;j<Ydim1-1;j++)
            for(int k=1;k<Zdim1-1;k++)
            {
                //             pixelValue = vol[i][j][k];

                /*
            for(d=0,cnt=0;d<26;d++)
                if(FCb[i+V[d][0]][j+V[d][1]][k+V[d][2]]==100) cnt++;
            if(cnt==26) continue;//Working only with the peripheral seeds
*/

               // if(NML[i][j][k]==1 && GITN==0) continue;

                if((FCb[i][j][k]-FCv[i][j][k])>10)//originally 10  //pixelValue <ta || pixelValue >= tbp)//B
                {
                    MRb[i][j][k]=(-1)*FDTb[i][j][k];
                    tp.x=i;tp.y=j;tp.z=k;
                    Q.enqueue(tp);
                }
                else
                    MRb[i][j][k]=0;

                //             if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) FDTb[i][j][k]=0;

            }
    /*
  FILE *fpvs;
  fpvs=fopen("vseed","r");
  while(!feof(fpvs))
  {
      int x,y,z;
      fscanf(fpvs,"%d%d%d",&x,&y,&z);
      FDTb[x][y][z]=0;
  }
  fclose(fpvs);
*/

    //Flag=2;
    ui->Plabel->setText("Computing MR for Dendrite... Iteration:");
    //compute_MR(MRb);
    F_count=0;
    while(!Q.isEmpty())
    {


        tp=Q.dequeue();
        int i=tp.x;int j=tp.y;int k=tp.z;

        if(i==0 ||j==0||k==0||i==Xdim1-1||j==Ydim1-1||k==Zdim1-1) continue;

        mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
        //if (Flag==0) mu_p=1-mu_p;

        //if (mu_p<0) mu_p=0;
        if (mu_p<0.5) mu_p=1-mu_p;
        if (mu_p>1) mu_p=1;


        for(d=0;d<26;d++)
        {
            if(FDTb[i][j][k]<=FDTb[i+V[d][0]][j+V[d][1]][k+V[d][2]]) continue;

           //if(NML[i+V[d][0]][j+V[d][1]][k+V[d][2]]==1 && GITN==0) continue;//ui->checkBox_10->isChecked()==TRUE) continue;


            mu_q=(float)(region[i+V[d][0]][j+V[d][1]][k+V[d][2]]-ta)/(tb-ta);

            //if (mu_q<0) mu_q=0;
            if (mu_q>1) mu_q=1;
            if (mu_q<0.5) mu_q=1-mu_q;


            //temp=lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];
            temp=MRb[i][j][k]+50*(mu_p+mu_q)*D[d];

            //temp=ceil(temp-0.5);
            //temp*=100;

            //if(temp<0) temp=0;

            //printf("\r Here\n");

            if(MRb[i+V[d][0]][j+V[d][1]][k+V[d][2]]>temp  && FCv[i+V[d][0]][j+V[d][1]][k+V[d][2]]!=100)//>=1.0)
            {
                MRb[i+V[d][0]][j+V[d][1]][k+V[d][2]]=temp;

                F_count++;

                tp.x=i+V[d][0];
                tp.y=j+V[d][1];
                tp.z=k+V[d][2];
                Q.enqueue(tp);
            }

        }

        //printf("\rMRb Q Size:%ld",Q.size());
        //printf("\rMRb:Updated points: %ld",F_count);
    }

    std::cout<<"Updated MR points for Dendrite  ::"<<F_count<<std::endl;
    //std::cout<<std::endl;

    /*
  for(int i=0;i<Xdim1;i++)
      for(int j=0;j<Ydim1;j++)
          for(int k=0;k<Zdim1;k++)
          {
            if(abs(FCb[i][j][k]-FCv[i][j][k])<=10)
            {
                if(FDTb[i][j][k]<FDTv[i][j][k])
                    FCv[i][j][k]=0;
                else
                    FCb[i][j][k]=0;

            }
        }
*/


    draw_image();
}

void MainWindow::compute_FDT(unsigned short ***lFDT)
{

    float min,temp;
    int i,j,k,d;
    float mu_p,mu_q;
    short pixelValue;

    //int tap=ui->spinBox_tap->value();
    int ta=ui->spinBox_ta->value();
    int tb=ui->spinBox_tb->value();


    //  if(Flag==5)
    {
        for(int i=0;i<Xdim1;i++)
            for(int j=0;j<Ydim1;j++)
                for(int k=0;k<Zdim1;k++)
                    if(SS[i][j][k]==3)//Sep
                        lFDT[i][j][k]=0;
    }



    int itn=0,F_count=0;
    //do


        ui->label_itn->setNum(++itn);

        F_count=0;
        for(i=1;i<Xdim1-1;i++)//Pos FDT
        {
            for(j=1;j<Ydim1-1;j++)
                for(k=1;k<=Zdim1-1;k++)
                {
                    if(lFDT[i][j][k]==0) continue;


                    mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
                    if (Flag==0) mu_p=1-mu_p;
                    if (Flag==2 && mu_p<0.5) mu_p=1-mu_p;

                    if(Flag==5)
                    {
                        pixelValue = region[i][j][k];

//                        if(pixelValue<ta)
//                        {
//                            mu_p=0;
//                        }
//                        else
                            if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                            {
                                mu_p=(float)(tb-pixelValue)/(tb-ta);
                            }

                    }


                    if (mu_p>1) mu_p=1;
                    if (mu_p<0) mu_p=0;

                    min= lFDT[i][j][k];
                    for(d=0;d<13;d++)
                    {
                        if(lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]==0)
                            mu_q=0;
                        else
                        {

                            mu_q=(float)(region[i+V[d][0]][j+V[d][1]][k+V[d][2]]-ta)/(tb-ta);
                            if (Flag==0) mu_q=1-mu_q;
                            if (Flag==2 && mu_q<0.5) mu_q=1-mu_q;


                            if(Flag==5)
                            {
                                pixelValue = region[i][j][k];

//                                if(pixelValue<ta)
//                                {
//                                    mu_q=0;
//                                }
//                                else
                                    if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                                    {
                                        mu_q=(float)(tb-pixelValue)/(tb-ta);
                                    }

                            }




                            if (mu_q>1) mu_q=1;
                            if (mu_q<0) mu_q=0;

                        }

                        temp=lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];

                        temp=ceil(temp-0.5);
                        //temp*=100;

                        //if(temp<0) temp=0;

                        if(temp<min)//>=1.0)
                        {
                            lFDT[i][j][k]=temp;
                            min=temp;
                            F_count++;
                        }
                    }
                }
            ui->progressBar->setValue((50*i)/(Xdim1-2)+1);
        }//Outer for loop pos FDT


        for(i=Xdim1-2;i>0;i--)//Neg FDT
        {
            for(j=Ydim1-2;j>0;j--)
                for(k=Zdim1-2;k>=0;k--)
                {
                    if(lFDT[i][j][k]==0) continue;

                    mu_p=(float)(region[i][j][k]-ta)/(tb-ta);
                    if (Flag==0) mu_p=1-mu_p;
                    if (Flag==2 && mu_p<0.5) mu_p=1-mu_p;

                    if(Flag==5)
                    {
                        pixelValue =region[i][j][k];

//                        if(pixelValue<ta)
//                        {
//                            mu_p=0;
//                        }
//                        else
                            if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                            {
                                mu_p=(float)(tb-pixelValue)/(tb-ta);
                            }

                    }


                    if (mu_p>1) mu_p=1;
                    if (mu_p<0) mu_p=0;

                    min= lFDT[i][j][k];

                    for(d=13;d<26;d++)
                    {
                        if(lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]==0)
                            mu_q=0;
                        else
                        {

                            mu_q=(float)(region[i+V[0][0]][j+V[0][1]][k+V[0][2]]-ta)/(tb-ta);
                            if (Flag==0) mu_q=1-mu_q;
                            if (Flag==2 && mu_q<0.5) mu_q=1-mu_q;

                            if(Flag==5)
                            {
                                pixelValue = region[i][j][k];
/*
                                if(pixelValue<ta)
                                {
                                    mu_q=0;
                                }
                                else*/ if(pixelValue >=ta && pixelValue <=tb  && (tb-ta)>0)
                                    {
                                        mu_q=(float)(tb-pixelValue)/(tb-ta);
                                    }

                            }

                            if (mu_q>1) mu_q=1;
                            if (mu_q<0) mu_q=0;

                        }

                        temp=lFDT[i+V[d][0]][j+V[d][1]][k+V[d][2]]+50*(mu_p+mu_q)*D[d];

                        temp=ceil(temp-0.5);
                        //temp*=100;

                        if(temp<0) temp=0;

                        if(temp<min)//>=1.0)
                        {
                            lFDT[i][j][k]=temp;
                            min=temp;
                            F_count++;
                        }

                    }
                }
            ui->progressBar->setValue(51+((Xdim1-2-i)*50/(Xdim1-2)));
        }//Outer for loop Neg FDT


        std::cout<<"Iteration:"<<itn<<", Updated points:"<<F_count<<std::endl;
        //  ui->label_12->setNum(F_count);
    //while(F_count>0);

}

void MainWindow::on_pushButton_CH_clicked()
{
    if(start==0)return;
    int reindex=ui->ROIList->currentRow()+1;
    listROI[reindex].analysis_flag=1;
    if(ui->actionSpine->isChecked())
    {
        ui->actionSpine->setChecked(false);
        draw_image();
    }
    if(ui->actionDendrite->isChecked())
    {
        ui->actionDendrite->setChecked(false);
        draw_image();
    }
    if(ui->actionSeparator->isChecked())
    {
        ui->actionSeparator->setChecked(false);
        draw_image();
    }
    if(ui->actionShow_Seed_Sep->isChecked())
    {
        ui->actionShow_Seed_Sep->setChecked(false);
        draw_image();
    }
    int badSpine, acc=1;
    //////////Start of Feature comuptation
    pID=0;
    /*load_seeds();*/
    pID=dspcount[reindex]-1;
    std::cout<<"Total Spine seeds="<<pID<<std::endl;
    sid=1;
    for(int id=1;id<=pID;id++)
    {

        spine[sid].pArea=0;
        spine[sid].pCGx=0;//spine CG
        spine[sid].pCGy=0;//spine CG
        spine[sid].pCGz=0;//spine CG

        spine[sid].bCGx=0;//base CG
        spine[sid].bCGy=0;//base CG
        spine[sid].bCGz=0;//base CG

        spine[sid].bCnt=0;//base pixel count
        spine[sid].x1=Xdim1;
        spine[sid].y1=Ydim1;
        spine[sid].z1=Zdim1;

        spine[sid].x2=0;
        spine[sid].y2=0;
        spine[sid].z2=0;

        badSpine=0;
        int p=dspine[reindex].dssx[id];
        int q=dspine[reindex].dssy[id];
        int r=dspine[reindex].dssz[id];
        if(out[p][q][r]==50)
        {
            FloodFill3d(p,q,r,sid);
        }
        else
        {
            continue;
        }
        if(spine[sid].pArea==0)
        {
            badSpine=1;
            std::cout<<"BAD-Spine ID:"<<sid<<std::endl;
            spine[sid].spine_flag=0;
            spine[sid].sp_id=sid;
        }

        if(badSpine==0)
        {
            qDebug()<<"\n Inside BAD Spine 0";
            spine[sid].pCGx=spine[sid].pCGx/(float)spine[sid].pArea;
            spine[sid].pCGy=spine[sid].pCGy/(float)spine[sid].pArea;
            spine[sid].pCGz=spine[sid].pCGz/(float)spine[sid].pArea;

            spine[sid].bCGx=spine[sid].bCGx/(float)spine[sid].bCnt;
            spine[sid].bCGy=spine[sid].bCGy/(float)spine[sid].bCnt;
            spine[sid].bCGz=spine[sid].bCGz/(float)spine[sid].bCnt;

            //out[spine[id].bCGx][spine[id].bCGy][spine[id].bCGz]=180;
            //out[spine[id].pCGx][spine[id].pCGy][spine[id].pCGz]=180;

            spine[sid].x1-=2;
            spine[sid].y1-=2;
            spine[sid].z1-=2;
            spine[sid].x2+=2;
            spine[sid].y2+=2;
            spine[sid].z2+=2;
            spine[sid].spine_flag='1';//good spine
            spine[sid].sp_id=sid;

            //std::cout<<spine[sid].x1<<" "<<spine[sid].x2<<" "<<spine[sid].y1<<" "<<spine[sid].y2<<" "<<spine[sid].z1<<" "<<spine[sid].z2<<std::endl;
            //std::cout<<"Spine ID:"<<spine[sid].sp_id<<std::endl;
            //std::cout<<"Area="<<spine[sid].pArea<<" Base Cnt="<<spine[sid].bCnt<<std::endl;


            //    char buffer[200];
            //    sprintf(buffer,"tx=%d ,ty=%d",tx,ty);
            //    QMessageBox::information(this, "2dSpAn", buffer, QMessageBox::Ok);


            spine[sid].xdim=abs(spine[sid].x1-spine[sid].x2+1);
            spine[sid].ydim=abs(spine[sid].y1-spine[sid].y2+1);
            spine[sid].zdim=abs(spine[sid].z1-spine[sid].z2+1);

            //connecting base and spine CG, when separated
            //int base_len=Bresenham(spine[id].bCGx,spine[id].bCGy, spine[id].pCGx,spine[id].pCGy, 'p');


            //analysing spine data//MAIN DT based Spine features
            spine_DT(sid);//sometimes commented for testing


            ///////////Write Feature file
           /* fprintf(fp,"%d,%d,%d,%d,%d,%f,%f,%f,%c\n",
                    spine[sid].sp_id,spine[sid].pCGx,spine[sid].pCGy,spine[sid].pCGz,
                    spine[sid].pArea,spine[sid].length,spine[sid].headW,spine[sid].neck_length,
                    spine[sid].type
                    );*/
        }

    sid++;
    }//end of id loop
    qDebug()<<sid;
    ui->actionShow_Segmented_Spine_Id->setChecked(true);
    //fclose(fp);

    for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
               // if(vol1[recX][recY][k]!=1)
                //if(k<Zdim)
                vol1[listROI[reindex].recX+i][listROI[reindex].recY+j][k]=(unsigned char)out[i][j][k];
                output[listROI[reindex].recX+i][listROI[reindex].recY+j][k]=(unsigned char)out[i][j][k];
            }
        }
    }
    draw_image();
}

void MainWindow::FloodFill3d(int ii,int jj,int kk, int id)
{

    point tp;
    QQueue<point> VQ;
    if(out[ii][jj][kk]==50)//segmented spine
    {
        tp.x=ii;tp.y=jj;tp.z=kk;
        VQ.enqueue(tp);
        //std::cout<<"Here: x:"<<tp.x<<std::endl;
    }
    else
    {
        //std::cout<<"Out "<<std::endl;

        return;
    }


    while(!VQ.isEmpty())
    {
        tp=VQ.dequeue();
        int i=tp.x;int j=tp.y;int k=tp.z;

        if(i<=1 ||j<=1||k<=1||i>=Xdim1-2||j>=Ydim1-2||k>=Zdim1-2) continue;

        //std::cout<<"Here: x:"<<tp.x<<" value ="<<std::endl;
        if(out[i][j][k]!=50) continue;

        out[i][j][k]=60;//relabelling spines with value 60..


        spine[id].pCGx+=i;
        spine[id].pCGy+=j;
        spine[id].pCGz+=k;
        spine[id].pArea++;

        if(i<spine[id].x1) spine[id].x1=i;
        if(j<spine[id].y1) spine[id].y1=j;
        if(k<spine[id].z1) spine[id].z1=k;

        if(i>spine[id].x2) spine[id].x2=i;
        if(j>spine[id].y2) spine[id].y2=j;
        if(k>spine[id].z2) spine[id].z2=k;


        for(int l=0;l<26;l++)
        {
            if(out[i+V[l][0]][j+V[l][1]][k+V[l][2]] <=0) continue;

            if(out[i+V[l][0]][j+V[l][1]][k+V[l][2]]==100) //base point
            {
                spine[id].bCnt++;
                spine[id].bCGx+=i;
                spine[id].bCGy+=j;
                spine[id].bCGz+=k;

                //out[i+V[l][0]][j+V[l][1]][k+V[l][2]]=150;
                continue;
            }

            if(out[i+V[l][0]][j+V[l][1]][k+V[l][2]]==50) //Actual spine voxel
            {
                tp.x=i+V[l][0];
                tp.y=j+V[l][1];
                tp.z=k+V[l][2];
                VQ.enqueue(tp);
            }

        }
    }
}

void MainWindow::spine_DT(int id)
{
    int i,j,min,temp,change=0,maxDT=0, neck_len,len1,basex,basey;


    sM=spine[id].xdim+4;//for outside padding
    sN=spine[id].ydim+4;//for outside padding
    sD=spine[id].zdim+4;//for outside padding



    DT   = ( int ***)calloc(sizeof( int **) , sM);
    DT1  = ( int ***)calloc(sizeof( int **) , sM);
    DT2  = ( int ***)calloc(sizeof( int **) , sM);

    for (int i = 0 ;  i < sM; i++) {
        DT[i]  = ( int **)calloc(sizeof( int *) , sN);
        DT1[i] = ( int **)calloc(sizeof( int *) , sN);
        DT2[i] = ( int **)calloc(sizeof( int *) , sN);

        for (int j = 0 ;  j < sN; j++) {
            DT[i][j]  = ( int *)calloc(sizeof( int) , sD);
            DT1[i][j] = ( int *)calloc(sizeof( int) , sD);
            DT2[i][j] = ( int *)calloc(sizeof( int) , sD);
        }
    }

    //std::cout<<"SpineID:"<<id<<std::endl;


    //for finding spine DT

    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
                DT[ii][jj][kk]=0;

    int cnt=0;

    for(int ii=0,i=spine[id].x1;i<=spine[id].x2;ii++,i++)
        for(int jj=0,j=spine[id].y1;j<=spine[id].y2;jj++,j++)
            for(int kk=0,k=spine[id].z1;k<=spine[id].z2;kk++,k++)
            {
                //                if(i==spine[id].bCGy && j==spine[id].bCGx)
                //                {
                //                    basex=jj;basey=ii;
                //                }

                if(out[i][j][k]==60)
                {
                    DT[ii][jj][kk]=9999;
                    cnt++;
                }

            }

    //    std::cout<<"Voxel cnt:"<<cnt<<std::endl;
    //    std::cout<<sM<<":"<<sN<<":"<<sD<<std::endl;
    compute_DT(DT,0,0);



    //    //write_skel(id);


    int maxi,maxj,maxk;

    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
            {
                if(DT[ii][jj][kk]==9999) continue;

                if (DT[ii][jj][kk]>maxDT)
                {
                    maxDT=DT[ii][jj][kk];
                    maxi=ii;
                    maxj=jj;
                    maxk=kk;
                }
            }

    int maxDTcnt=0, minDTx=999,minDTy=999,minDTz=999, maxDTx=-999,maxDTy=-999,maxDTz=-999, CGDTx=0,CGDTy=0,CGDTz=0;

    float maxDT_Th=10;//ui->doubleSpinBox_DT_Th->value()*10;

    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
            {
                if(DT[ii][jj][kk]==9999) continue;
                if(DT[ii][jj][kk]==0)continue;
                if (abs(DT[ii][jj][kk]-maxDT)<maxDT_Th)
                {
                    if(ii>maxDTx) maxDTx=ii;
                    if(jj>maxDTy) maxDTy=jj;
                    if(kk>maxDTz) maxDTz=kk;

                    if(ii<minDTx) minDTx=ii;
                    if(jj<minDTy) minDTy=jj;
                    if(kk<minDTz) minDTz=kk;

                    CGDTx+=ii;
                    CGDTy+=jj;
                    CGDTz+=kk;
                    maxDTcnt++;

                    //out[spine[id].x1+ii][spine[id].y1+jj][spine[id].z1+kk]=190;
                }
            }

    maxi=(CGDTx/(float)maxDTcnt);
    maxj=(CGDTy/(float)maxDTcnt);
    maxk=(CGDTz/(float)maxDTcnt);

    //out[spine[id].x1+maxi][spine[id].y1+maxj][spine[id].z1+maxk]=180;
    //out[spine[id].x1][spine[id].y1][spine[id].z1]=180;

    //spine DT with true background

    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
                DT2[ii][jj][kk]=8888;

    for(int ii=0,i=spine[id].x1;i<=spine[id].x2;ii++,i++)          //for DT2 matrix x2,x1 changed
        for(int jj=0,j=spine[id].y1;j<=spine[id].y2;jj++,j++)
            for(int kk=0,k=spine[id].z1;k<=spine[id].z2;kk++,k++)
            {
                if(out[i][j][k]==60)
                {
                    DT2[ii][jj][kk]=9999;
                }
                else if(out[i][j][k]==100)
                {
                    DT2[ii][jj][kk]=0;
                }

            }

    compute_DT(DT2,1,0);


    //for finding farthest spine point
    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
            {

                DT1[ii][jj][kk]=9999;
            }

    cnt=0;
    for(int ii=0,i=spine[id].x1;i<=spine[id].x2;ii++,i++)             //for DT2 matrix x2,x1 changed
        for(int jj=0,j=spine[id].y1;j<=spine[id].y2;jj++,j++)
            for(int kk=0,k=spine[id].z1;k<=spine[id].z2;kk++,k++)
            {
                //if(symbol[i][j]=='y')
                if(i==spine[id].bCGx && j==spine[id].bCGy && k==spine[id].bCGz)
                {
                    DT1[ii][jj][kk]=0;
                    //std::cout<<"base CG: r= "<<i<<" c= "<<j<<" s= "<<k<<" startDT="<<DT1[ii][jj][kk]<<std::endl;
                    cnt++;

                    //dilating the base CG
                    for(int l=0;l<26;l++)
                      DT1[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]=0;

                }

                if(out[i][j][k]==60)
                {
                    //DT[ii][jj]=9998;
                    DT1[ii][jj][kk]=9998;

                }
            }

        //compute_DT1(maxDT+10);
    //std::cout<<"Third DT base cnt:"<<cnt<<std::endl;
    compute_DT(DT1, 2, maxDT+10);

    int maxi1=0,maxj1=0,maxk1=0;
    int maxDT1=0;
    for(int ii=0;ii<sM;ii++)
        for(int jj=0;jj<sN;jj++)
            for(int kk=0;kk<sD;kk++)
        {
            if(DT1[ii][jj][kk]==9999 || DT1[ii][jj][kk]==9998) continue;

            if (DT1[ii][jj][kk]>maxDT1)
            {
                maxDT1=DT1[ii][jj][kk];
                maxi1=ii;
                maxj1=jj;
                maxk1=kk;
            }
        }

        int maxi2=0,maxj2=0,maxk2=0;
        int maxDT2=0;
        for(int ii=0;ii<sM;ii++)
            for(int jj=0;jj<sN;jj++)
                for(int kk=0;kk<sD;kk++)
            {
                if(DT2[ii][jj][kk]==9999 || DT2[ii][jj][kk]==8888) continue;

                if (DT2[ii][jj][kk]>maxDT2)
                {
                    maxDT2=DT2[ii][jj][kk];
                    maxi2=ii;
                    maxj2=jj;
                    maxk2=kk;
                }
            }

        std::cout<<"Far Point: r= "<<maxi2<<" c= "<<maxj2<<" s= "<<maxk2<<" MaxDT at Far= "<<maxDT2<<std::endl;

         out[spine[id].bCGx][spine[id].bCGy][spine[id].bCGz]=190;
         out[spine[id].x1+maxi][spine[id].y1+maxj][spine[id].z1+maxk]=191;
         out[spine[id].x1+maxi2][spine[id].y1+maxj2][spine[id].z1+maxk2]=192;
        // out[spine[id].bCGx+maxi2][spine[id].bCGy+maxj2][spine[id].bCGz+maxk2]=230;
          /* out[maxi2][maxj2][maxk2]=200;
          out[spine[id].x1][spine[id].y1][spine[id].z1]=220;*/

        //Feature and shortest path estimation
//        std::cout<<"DT: r= "<<maxi<<" c= "<<maxj<<" s= "<<maxk<<" startDT="<<DT[maxi][maxj][maxk]<<std::endl;
//        std::cout<<"DT1: r= "<<maxi<<" c= "<<maxj<<" s= "<<maxk<<" startDT="<<DT1[maxi][maxj][maxk]<<std::endl;

        //neck_len=Bresenham(spine[id].bCGx,spine[id].bCGy, spine[id].x1+maxj-1,spine[id].y1+maxi-1,'p');

        spine[id].headX=spine[id].x1+maxi;
        spine[id].headY=spine[id].y1+maxj;
        spine[id].headZ=spine[id].z1+maxk;

        spine[id].headW=(float)(DT[maxi][maxj][maxk]/5.0);

        //spine[id].headWmax=spine[id].headW+radial_dist;

        //spine[id].length=neck_len+len1+((float)DT[maxi1][maxj1]/10);
        std::cout<<" Head_W="<<spine[id].headW<<std::endl;


        neck_len=0;
        v_neck_cnt=0;
        spine[id].avg_neckW=0;
        spine[id].min_neckW=9999;//large value


        trace_cnt=0;
        trace_back(id,maxi,maxj,maxk,0,0);//center of head to base_CG
        std::cout<<" Tracecnt 1:"<<trace_cnt<<std::endl;

        neck_len=trace_cnt-(float)spine[id].headW/2.0;

        if(v_neck_cnt==0) neck_len=0;

        std::cout<<" Neck_len="<<neck_len<<std::endl;

        if(neck_len>0)
        {
            //Regular spines (Mushroom or Filopodia)

            spine[id].type='r';
            spine[id].neck_length=neck_len;
            spine[id].avg_neckW=(float)spine[id].avg_neckW/(float)(v_neck_cnt*5);
            spine[id].min_neckW/=5.0;
        }
        else
        {
            //STUBBY spines with 0 neck length

            spine[id].type='s';
            spine[id].neck_length=0;
            spine[id].avg_neckW=0;
            spine[id].min_neckW=0;
            spine[id].length=(float)(DT2[maxi][maxj][maxk]/10.0);
        }



        std::cout<<" Avg_Neckwidth="<<spine[id].avg_neckW<<std::endl;
        std::cout<<" Min_Neckwidth="<<spine[id].min_neckW<<std::endl;



    //    if(neck_len>spine[id].bCnt/2)

        //Regular spines

        //DT1[spine[id].bCGx][spine[id].bCGy][spine[id].bCGz]=1;

        if(neck_len>0)
        {
            trace_cnt=0;
            trace_back(id,maxi2,maxj2,maxk2,0,1);//Farthest point to base_CG
            std::cout<<" Tracecnt 2:"<<trace_cnt<<std::endl;


            if(trace_cnt>spine[id].headW) //&& trace_cnt>(float)spine[id].bCnt/2)
            {
                spine[id].length=trace_cnt;

                if (trace_cnt>(1.5*(spine[id].headW+neck_len)))
                    spine[id].type='f';//FILOPODIA
                else
                    spine[id].type='m';//MUSHROOM
            }
            else
            {
                //STUBBY
                spine[id].type='s';
            }
            //neck_len+len1+(DT[maxi1][maxj1]/10);
        }



    //        //symbol[spine[id].y1+maxi1-1][spine[id].x1+maxj-1]='y';

        std::cout<<" Spine Length:"<<spine[id].length<<std::endl;
        std::cout<<" Spine Type:"<<spine[id].type<<std::endl;

    //    //write_skel(id);

    //    ///////////Circle


    //    ///////////


        free(DT);
        free(DT1);
        free(DT2);


}

void MainWindow::compute_DT(int ***DD, int DT_Flag, int maxdt)
{
    int min,temp,change=0,cnt=0;


    do{

        change=0;
        cnt=0;

        //Positive DT
        for(int ii=1;ii<sM-1;ii++)
            for(int jj=1;jj<sN-1;jj++)
                for(int kk=1;kk<sD-1;kk++)
                {
                    if (DD[ii][jj][kk]==0) {
                        /*if (DT_Flag==2) std::cout<<"Here is ZERO="<<change<<std::endl;*/
                        continue;}

                    if (DT_Flag==1 && DD[ii][jj][kk]==8888) continue;
                    if (DT_Flag==2 && DD[ii][jj][kk]==9999) continue;

                    min=DD[ii][jj][kk];
                    for(int l=0;l<13;l++)
                    {
                        if (DT_Flag==2&&DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]!=9999)
                        {


                            temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+
                                   maxdt-DT[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];

//                            if (DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]==0)
//                                std::cout<<"Here temp="<<temp<<" min="<<min<<std::endl;;
                        }
                        else if(DT_Flag==1&&DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]!=8888)
                        {
                            temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];
                        }
                        else temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];

                        if(temp<min)
                        {
                            DD[ii][jj][kk]=temp;
                            min=temp;
                            change++;
                            //if(DT_Flag==2)
                            //std::cout<<"NirmalDas"<<std::endl;
                        }

                        //std::cout<<"Here="<<change<<std::endl;
                    }
                }



        //Negative DT
        for(int ii=sM-2;ii>0;ii--)
            for(int jj=sN-2;jj>0;jj--)
                for(int kk=sD-2;kk>0;kk--)
                {
                    if (DD[ii][jj][kk]==0) continue;
                    if (DT_Flag==1 && DD[ii][jj][kk]==8888) continue;
                    if (DT_Flag==2 && DD[ii][jj][kk]==9999) continue;

                    min=DD[ii][jj][kk];

                    for(int l=13;l<26;l++)
                    {

                        if (DT_Flag==2&&DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]!=9999)
                        {
                            //if (DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]==9999) continue;

                            temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+
                                   maxdt-DT[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];
                        }
                        else if(DT_Flag==1&&DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]!=8888)
                        {
                            temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];
                        }
                        else
                            temp=DD[ii+V[l][0]][jj+V[l][1]][kk+V[l][2]]+(int)10*D[l];

                        if(temp<min)
                        {
                            DD[ii][jj][kk]=temp;
                            min=temp;
                            change++;
                            //if(DT_Flag==2)
                            //std::cout<<"NirmalDas"<<std::endl;
                        }
                    }
                }

        //if(DT_Flag==2)
          //  std::cout<<"change="<<change<<std::endl;
    }while(change);
}

void MainWindow::trace_back(int id, int r, int c, int s, int StopDT, int flag)
//searching minimum value around
{
    int minDT=0, mini=0,minj=0,mink=0;
    //std::cout<<"NirmalDas"<<std::endl;
    //std::cout<<"trace: r= "<<r<<" c= "<<c<<" s= "<<s<<" startDT="<<DT1[r][c][s]<<std::endl;

    if(DT1[r][c][s]<=0) return;
    if(DT1[r][c][s]==9999)return;//culprit line
    if(DT1[r][c][s]==8888)return;
    if(DT1[r][c][s]==StopDT)return;
    if(r<1 || r>sM-2 || c<1 || c>sN-2|| s<1 || s>sD-2) return;

    //if(r==spine[id].bCGy && c==spine[id].bCGx) return;

    minDT=DT1[r][c][s];
    DT1[r][c][s]=minDT*2;//to avoid backtracking

//    std::cout<<"1: r= "<<r<<" c= "<<c<<" MaxDT="<<minDT<<std::endl;

    for(int l=0;l<26;l++)
    {
        //std::cout<<"NirmalDas"<<std::endl;
      //  if(DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]]<=0||DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]]==0)continue;

        if (DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]]<=minDT/*&&DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]]!=0&&DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]]!=9999*/)
        {
            minDT=DT1[r+V[l][0]][c+V[l][1]][s+V[l][2]];
            mini=r+V[l][0];
            minj=c+V[l][1];
            mink=s+V[l][2];
        }
    }

    //std::cout<<"2: r= "<<r<<" c= "<<c<<" MinDT="<<minDT<<std::endl;

    trace_cnt++;

    if((flag==0)&&trace_cnt>=spine[id].headW/2.0)//center of head to base_CG
    {
        out[spine[id].x1+mini][spine[id].y1+minj][spine[id].z1+mink]=180;//neck
        if(DT1[mini][minj][mink]<spine[id].headW)
        {

            spine[id].avg_neckW+=DT1[mini][minj][mink];
            //std::cout<<"NirmalDas-"<<spine[id].avg_neckW<<std::endl;
            if(DT1[mini][minj][mink]<spine[id].min_neckW)
            {
                spine[id].min_neckW=(float)DT1[mini][minj][mink];
                //std::cout<<"NirmalDas-"<<DT1[mini][minj][mink]<<std::endl;
            }
            v_neck_cnt++;
        }
    }
    if(flag==1)
    {
        out[spine[id].x1+mini][spine[id].y1+minj][spine[id].z1+mink]=185;
        qDebug()<<"for stubby 185::"<<spine[id].sp_id<<"\n";

    }


    trace_back(id,mini,minj,mink, StopDT,flag);
}

void MainWindow::on_actionSpine_triggered()
{
    if(start!=0)
    {
     if(ui->showOriginal->isChecked())
     {
         return;
     }
     if(!ui->actionShow_Seed_Sep->isChecked())
         ui->actionShow_Seed_Sep->setChecked(true);
     on_actionShow_Seed_Sep_triggered();
    }
}

void MainWindow::on_actionDendrite_triggered()
{
    if(start!=0)
    {
        if(ui->showOriginal->isChecked())
        {
            return;
        }
     if(!ui->actionShow_Seed_Sep->isChecked())
         ui->actionShow_Seed_Sep->setChecked(true);
     on_actionShow_Seed_Sep_triggered();
    }
}

void MainWindow::on_actionSeparator_triggered()
{
    if(start!=0)
    {
        if(ui->showOriginal->isChecked())
        {
            return;
        }
     if(!ui->actionShow_Seed_Sep->isChecked())
         ui->actionShow_Seed_Sep->setChecked(true);
     on_actionShow_Seed_Sep_triggered();
    }
}

void MainWindow::on_deleteseed_clicked()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Crop a region to the perform the operation");
        msgBox.exec();
        return;
    }
    int rnindex=ui->ROIList->currentRow()+1;
    int seed_number=ui->lineEdit->text().toInt();
    if(ui->comboBox->currentText()=="Spine")
    {
        if(seed_number>dspcount[rnindex]-1)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("3dSpAn");
            msgBox.setText("Invalid spine seed Id");
            msgBox.exec();
            return;
        }
        for(int i=seed_number;i<dspcount[rnindex]-1;i++)
        {

            dspine[i]=dspine[i+1];
            spine[i]=spine[i+1];
        }
        if(dspcount[rnindex]>1)dspcount[rnindex]--;
        load_seeds();
        on_actionSpine_triggered();
    }

    if(ui->comboBox->currentText()=="Dendrite")
    {
        if(seed_number>dcount[rnindex]-1)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("3dSpAn");
            msgBox.setText("Invalid dendrite seed Id");
            msgBox.exec();
            return;
        }
        for(int i=seed_number;i<dcount[rnindex]-1;i++)
        {
            den[i]=den[i+1];
        }
        if(dcount[rnindex]>1)dcount[rnindex]--;
        load_seeds();
        on_actionDendrite_triggered();
    }

    if(ui->comboBox->currentText()=="Separator")
    {
        if(seed_number>sepcount[rnindex]-1)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("3dSpAn");
            msgBox.setText("Invalid separator Id");
            msgBox.exec();
            return;
        }
        for(int i=seed_number;i<sepcount[rnindex]-1;i++)
        {
            sep[i]=sep[i+1];
        }
        if(sepcount[rnindex]>1)sepcount[rnindex]--;
        load_seeds();
        on_actionSeparator_triggered();
    }
}

//void MainWindow::on_actionLoad_Seeds_triggered()
//{
//    if(start==0)return;
//    if(ui->showOriginal->isChecked())
//    {
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setWindowTitle("3dSpAn");
//        msgBox.setText("Crop a region to add seed");
//        msgBox.exec();
//        return;
//    }
//    QString temp;
//    QByteArray seedfilename;
//    FILE *fp;
//    int x,y,z,type,ta,tb,tbp,reindex;
//    reindex=ui->ROIList->currentRow()+1;
//    temp=QFileDialog::getOpenFileName(this,tr("Open File"), " ",
//                                      tr("Text(*.txt)"));
//    if(QString::compare(temp,QString())==0)return;
//    QByteArray qb = temp.toLatin1();
//    seedfilename =  qb.data();
//    fp=fopen(seedfilename,"r");
//    if(!fp)return;
//    for(int i=0;i<MAX;i++)
//    {
//        dspine[reindex].dssx[i]=0;
//        dspine[reindex].dssy[i]=0;
//        dspine[reindex].dssz[i]=0;
//        den[reindex].dsx[i]=0;
//        den[reindex].dsy[i]=0;
//        den[reindex].dsz[i]=0;
//        sep[reindex].sepx[i]=0;
//        sep[reindex].sepy[i]=0;
//        sep[reindex].sepz[i]=0;
//        spine[i].seed.x=0;
//        spine[i].seed.y=0;
//        spine[i].seed.z=0;
//    }

//    dspcount[reindex]=1;
//    dcount[reindex]=1;
//    sepcount[reindex]=1;
//    dspID=1;
//    pID=0;
//    int i=1;
//    fscanf(fp,"%d%d%d",&ta,&tb,&tbp);
//    fscanf(fp,"%d",&totalseed);
//    while(i<=totalseed)
//    {
//        fscanf(fp,"%d%d%d%d",&x,&y,&z,&type);
//        if(type==0)
//        {
//            dspine[reindex].dssx[dspID]=x;
//            dspine[reindex].dssy[dspID]=y;
//            dspine[reindex].dssz[dspID]=z;
//            spine[dspID].seed.x=x;
//            spine[dspID].seed.y=y;
//            spine[dspID].seed.z=z;
//            dspcount[reindex]++;
//            dspID++;
//        }
//        else if(type==1)
//        {
//            den[reindex].dsx[dcount[reindex]]=x;
//            den[reindex].dsy[dcount[reindex]]=y;
//            den[reindex].dsz[dcount[reindex]]=z;
//            dcount[reindex]++;
//        }
//        else if(type==2)
//        {
//            sep[reindex].sepx[sepcount[reindex]]=x;
//            sep[reindex].sepy[sepcount[reindex]]=y;
//            sep[reindex].sepz[sepcount[reindex]]=z;
//            sepcount[reindex]++;
//        }
//        i++;
//    }
//    load_seeds();
//    ui->spinBox_ta->setValue(ta);
//    ui->spinBox_tb->setValue(tb);
//    ui->spinBox_tbp->setValue(tbp);
//}

void MainWindow::on_actionSave_Analysis_triggered()
{
    if(start==0)return;
    int rindex=ui->ROIList->currentRow()+1;
    if(rindex<1)return;
    if(!listROI[rindex].analysis_flag)return;
    int spc=0;
    for(int i=1;i<rindex;i++)
    {
        spc=spc+segspcount[i];
    }
    FILE *fp;

    char ROIname[100];
    sprintf(ROIname,"ROI_%d_featurefile",rindex);
    QByteArray onlyfilename1=only_filename;
    onlyfilename1.prepend(ROIname);
    const char *feature=onlyfilename1.data();
    QString savefilepath=QFileDialog::getSaveFileName(this, "Save as",feature,"CSV(*.csv)");
    if(savefilepath==NULL)return;
    QByteArray ba = savefilepath.toLatin1();
    const char *name = ba.data();
    float resolution=ui->lineEditResolution->text().toFloat();
    fp=fopen(name,"w");
    if(!fp)return;

    fprintf(fp,"Spine_ID,CGx,CGy,CG_z,Volume,Length,HeadW,Neck Length,Type\n");
    for(int id=1;id<sid;id++)
    {

        spine[id].pArea=(float)spine[id].pArea;
        spine[id].headW=(float)spine[id].headW*resolution;
        spine[id].length=(float)spine[id].length*resolution;
        spine[id].neck_length=(float)spine[id].neck_length*resolution;
        /*spine[id].min_neckW=(float)spine[id].min_neckW;
        spine[id].avg_neckW=(float)spine[id].avg_neckW;*/
        fprintf(fp,"%d,%d,%d,%d,%f,%f,%f,%f,%c\n",
                spine[id].sp_id+spc,spine[id].pCGx,spine[id].pCGy,spine[id].pCGz,
                spine[id].pArea*resolution*resolution*resolution,spine[id].length,spine[id].headW,spine[id].neck_length,
                spine[id].type
                );
    }
    fclose(fp);
}

void MainWindow::on_actionSave_triggered()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())return;
    char ROIname[20];
    sprintf(ROIname,"ROI_%d_%d_%d_%d_uchar_",ui->ROIList->currentRow()+1,Xdim1,Ydim1,Zdim1);
    QByteArray onlyfilename1=only_filename;
    onlyfilename1.prepend(ROIname);
    qDebug()<<onlyfilename1;
    unsigned char value;
    QByteArray outputfilename;
    QString savefilepath=QFileDialog::getSaveFileName(this,tr("Save as"),onlyfilename1,tr("Analyze Images (*.img);;MultiPage tiff Images (*.tif)"));
    if(savefilepath==NULL)return;
    outputfilename=savefilepath.toLatin1();
    if(outputfilename.endsWith(".img"))
    {
            FILE *fp;
//            char *name1=outputfilename.data();
//            fp=fopen(name1,"w");
//            fwrite(hdr,348,1,fp);
//            fclose(fp);

            //outputfilename.replace(".hdr",".img");
            char *name2=outputfilename.data();
        //    strcat(ROIname,name2);
        //    qDebug()<<ROIname;
            qDebug()<<name2;
            fp=fopen(name2,"wb");
            if(!fp) return;

            for (int slice=0;slice<Zdim1;slice++)
            {
                for (int column=0;column<Ydim1;column++)
                {
                    for (int row=0; row<Xdim1;row++)
                    {

                        value=out[row][column][slice];//testing
                        fputc(value,fp);
                        //img[row][column][slice]=value;
                    }
                }
            }

            fclose(fp);
            outputfilename.replace(".img",".hdr");
            char *name3=outputfilename.data();
            fp=fopen(name3,"wb");
            fseek(fp,42,SEEK_SET);
            fprintf(fp,"%d%d%d\n",Xdim,Ydim,Zdim);
            fclose(fp);

    }
    if(outputfilename.endsWith(".tif"))
    {
        TIFF *tif;
            tsize_t linebytes =4*Xdim1;
            unsigned char *buf = NULL;
            buf =(unsigned char *)_TIFFmalloc(linebytes);

            for (int page = 0; page < Zdim1;page++){

                if (page == 0)  tif = TIFFOpen(outputfilename, "w");
                else  tif = TIFFOpen(outputfilename, "a");

                TIFFSetField(tif,TIFFTAG_IMAGEWIDTH,Xdim1);
                TIFFSetField(tif,TIFFTAG_IMAGELENGTH,Ydim1);
                TIFFSetField(tif,TIFFTAG_SAMPLESPERPIXEL,4);
                TIFFSetField(tif,TIFFTAG_BITSPERSAMPLE,8);
                TIFFSetField(tif,TIFFTAG_SAMPLEFORMAT,SAMPLEFORMAT_UINT);
                TIFFSetField (tif, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
                TIFFSetField (tif, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
                TIFFSetField(tif, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
                TIFFSetField(tif, TIFFTAG_COMPRESSION, COMPRESSION_NONE) ;

                TIFFSetField(tif, TIFFTAG_ROWSPERSTRIP, TIFFDefaultStripSize(tif,4*Xdim));
                for(int j=0;j<Ydim1;j++){
                   int k=0;
                   for(int i=0;i<Xdim1;i++){
                       buf[k]=(unsigned char)out[i][j][page];
                       buf[k+1]=(unsigned char)out[i][j][page];
                       buf[k+2]=(unsigned char)out[i][j][page];
                       buf[k+3]=(unsigned char)1;
                       k+=4;
                   }
                   TIFFWriteScanline(tif,buf,j,0);
                }
                TIFFWriteDirectory(tif);
            }
           TIFFClose(tif);

    }


}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_spinBox_ta_valueChanged(int arg1)
{
    if(ui->showOriginal->isChecked())
    {
        draw_fullimage();
    }
    else
    {
        draw_image();
    }
}

void MainWindow::on_spinBox_tb_valueChanged(int arg1)
{
    if(ui->showOriginal->isChecked())
    {
        draw_fullimage();
    }
    else
    {
        draw_image();
    }
}

void MainWindow::on_spinBox_tbp_valueChanged(int arg1)
{
    if(ui->showOriginal->isChecked())
    {
        draw_fullimage();
    }
    else
    {
        draw_image();
    }
}

void MainWindow::on_actionApply_3D_Median_triggered()
{
    opCancelled = false;
    opSuccessful = false;
    if(start==0)return;
    MedianFilterAndScallingProperties *mfasp = new MedianFilterAndScallingProperties();
    connect(mfasp,SIGNAL(scalingAndKernelSize(double,int)),this,SLOT(getScaleAndKernelSize(double,int)));
    connect(mfasp,SIGNAL(operationCanceled()),this,SLOT(scalingChoseOperationCanceled()));
    mfasp->exec();

    if(opCancelled || (!opSuccessful)){
        qDebug()<<"INside here"<<opCancelled<<" "<<opSuccessful;
        return;
    }
    qDebug()<<"Outside here";
    if(!ui->showOriginal->isChecked())return;
    if(ispreprocessed)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Already preprocessed!!");
        msgBox.exec();
        return;
    }
    ispreprocessed++;
    on_actionScale_triggered();
    qDebug()<<"Returned from on scale triggered";
    int i,j,k,ws=kernelSize/2,pixcount=0;
    short median[kernelSize*kernelSize*kernelSize];
    qDebug()<<"Kernel size="<<ws;
    for(i=0;i<kernelSize*kernelSize*kernelSize;i++)median[i]=0;
    for(k=0;k<Zdim;k++)
    {
        for(j=0;j<Ydim;j++)
        {
            for(i=0;i<Xdim;i++)
            {
                pixcount=0;
                if(!vol[i][j][k])continue;
                     for(int r=k-ws;r<=k+ws;r++)
                     {
                         for(int q=j-ws;q<=j+ws;q++)
                         {
                             for(int p=i-ws;p<=i+ws;p++)
                             {
                                       if(r>=0&&r<Zdim&&q>=0&&q>=0&&q<Ydim&&p>=0&&p<Xdim)
                                       {
                                           median[pixcount++]=vol[p][q][r];
                                       }
                             }
                         }
                     }
                     //sort(median,kernelSize*kernelSize*kernelSize);
                     //qDebug()<<"returned form sort function";
                     vol[i][j][k]=median[(kernelSize*kernelSize*kernelSize)/2];
                     output[i][j][k]=median[(kernelSize*kernelSize*kernelSize)/2];
            }
        }
    }
    qDebug()<<"Outside filter";
    draw_fullimage();
    //ui->actionApply_3D_Median->setEnabled(false);
}

void MainWindow::sort(short *median,int index)
{
    int i,j,min;
    short temp;
    for(i=0;i<index;i++)
    {
        min=i;
          for(j=i+1;j<index;j++)
          {
              if(median[j]<median[min])
              {
                  min=j;
              }
          }
          temp=median[min];
          median[min]=median[i];
          median[i]=temp;
    }

}

void MainWindow::on_actionSelect_a_region_triggered()
{
    if(start==0)return;
    if(!ui->showOriginal->isChecked()&&ui->actionSelect_a_region->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("Select a region from original image");
        msgBox.exec();
        return;
    }
    recL=0;
    recW=0;
    recX=-1;
    recY=-1;
    if(ui->showOriginal->isChecked())
    draw_fullimage();
}

void MainWindow::on_crop_clicked()
{
       if(recL<=0&&recW<=0)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("3dSpAn");
            msgBox.setText("Select a region");
            msgBox.exec();
            return;
        }
       if(ispreprocessed==0)
       {
           QMessageBox msgBox;
           msgBox.setIcon(QMessageBox::Warning);
           msgBox.setWindowTitle("3dSpAn");
           msgBox.setText("First preprocess the image");
           msgBox.exec();
           return;
       }
       if((!listROI[ROIindex].segment_flag||!listROI[ROIindex].analysis_flag)&&ROIindex>0)
       {
           QMessageBox msgBox;
           msgBox.setIcon(QMessageBox::Warning);
           msgBox.setWindowTitle("3dSpAn");
           msgBox.setText("First complete the segmentation & feature extraction of cropped ROI");
           msgBox.exec();
           return;
       }

        char ROIname[50];
        ROIindex++;
        sprintf(ROIname,"ROI_%d",ROIindex);
        reset();
//        for(int k=0;k<Zdim;k++)
//        {
//                for(int i=recX;i<=recX+recW;i++)
//                {
//                    vol1[i][recY][k]=1;
//                    vol1[i][recY+recL][k]=1;
//                }
//                for(int j=recY;j<=recY+recL;j++)
//                {
//                    vol1[recX][j][k]=1;
//                    vol1[recX+recW][j][k]=1;
//                }
//        }
        Xdim1=recW;
        Ydim1=recL;
        Zdim1=Zdim;
        free(region);
        region= (short ***)calloc(sizeof(short **),Xdim1);
        for (int i =0;i<Xdim1;i++) {
            region[i] = (short **)calloc(sizeof(short *),Ydim1);
            for (int j = 0; j < Ydim1; j++)
                region[i][j] = (short *)calloc(sizeof(short),Zdim1);
        }

        for(int k=0;k<Zdim1;k++)
        {
            for(int j=0;j<Ydim1;j++)
            {
                for(int i=0;i<Xdim1;i++)
                {
                       region[i][j][k]=vol[i+recX][j+recY][k];
                }
            }
        }
        lowadaptivethreshold();
        hiadaptivethreshold();
        ui->spinBox_curX->setMaximum(Xdim1-1);
        ui->spinBox_curY->setMaximum(Ydim1-1);
        ui->spinBox_curZ->setMaximum(Zdim1-1);
        curX=Xdim1/2;
        curY=Ydim1/2;
        curZ=Zdim1/2;
        for(int i=0;i<MaxSeed;i++)
        {
            dspine[ROIindex].dssx[i]=0;
            dspine[ROIindex].dssy[i]=0;
            dspine[ROIindex].dssz[i]=0;
            den[ROIindex].dsx[i]=0;
            den[ROIindex].dsy[i]=0;
            den[ROIindex].dsz[i]=0;
            sep[ROIindex].sepx[i]=0;
            sep[ROIindex].sepy[i]=0;
            sep[ROIindex].sepz[i]=0;
//            spine[ROIindex].seed.x=0;
//            spine[ROIindex].seed.y=0;
//            spine[ROIindex].seed.z=0;
        }

        dspcount[ROIindex]=1;dcount[ROIindex]=1;sepcount[ROIindex]=1;pID=0;
        allocate_memory();
        for(int k=0;k<Zdim1;k++)
        {
            for(int j=0;j<Ydim1;j++)
            {
                for(int i=0;i<Xdim1;i++)
                {
                       out[i][j][k]=region[i][j][k];
                }
            }
        }
        ui->spinBox_curX->setValue(curX);
        ui->spinBox_curY->setValue(curY);
        ui->spinBox_curZ->setValue(curZ);
        ui->showOriginal->setEnabled(true);
        ui->showOriginal->setCheckState(Qt::Unchecked);

        ui->actionShow_Segmented_Spine_Id->setChecked(Qt::Unchecked);
        draw_image();
        ui->ROIList->addItem(ROIname);
        ui->ROIList->item(ROIindex-1)->setSelected(true);
        ui->ROIList->setCurrentRow(ROIindex-1);
        ui->ROIList->setFocus();
        listROI[ROIindex].recL=recL;
        listROI[ROIindex].recW=recW;
        listROI[ROIindex].recX=recX;
        listROI[ROIindex].recY=recY;
        listROI[ROIindex].sizex=Xdim1;
        listROI[ROIindex].sizey=Ydim1;
        listROI[ROIindex].sizez=Zdim1;
        ui->selectRegion->setCheckState(Qt::Unchecked);
}

void  MainWindow::draw_fullimage()
{
    if(start==0)return;
    ui->actionMorphological_Reconstruction->setChecked(Qt::Unchecked);
    QImage imagez(Xdim,Ydim,QImage::Format_RGB32);
    int pixelValue,pixelValue1;
    float mu;
    int ta=ui->spinBox_ta->value();
    int tb=ui->spinBox_tb->value();
    int tbp=ui->spinBox_tbp->value();
    for(int j=0;j<Ydim;j++)
    {
        for(int i=0;i<Xdim;i++)
        {
            pixelValue=output[i][j][curZ];
            pixelValue1=vol[i][j][curZ];
                imagez.setPixel(QPoint(i,j), qRgb(pixelValue1,pixelValue1,pixelValue1));
            if((pixelValue==50||pixelValue==60)&&vol1[i][j][curZ]&&vol1[i][j][curZ]!=200)
                    imagez.setPixel(QPoint(i,j), qRgb(255,0,0));
            //else if(pixelValue==100&&vol1[i][j][curZ]&&vol1[i][j][curZ]!=200)
                    //imagez.setPixel(QPoint(i,j), qRgb(0,255,0));
            else if(vol1[i][j][curZ]==200&&isprofileloaded)
                    imagez.setPixel(QPoint(i,j), qRgb(0,0,255));
            if(ui->actionFuzzy_Segment->isChecked())
            {
                mu=(float)(pixelValue1-ta)/(tb-ta);
                if(pixelValue1>=tb&&pixelValue1<=tbp)// && pixelValue <=2048
                    imagez.setPixel(i,j,qRgb(0,255,0));
                else if(pixelValue <ta)
                        imagez.setPixel(i,j,qRgb(0,0,0));
                else if(pixelValue1==ta)imagez.setPixel(i,j,qRgb(255,0,0));
                else if(pixelValue1 >ta && pixelValue <tb)
                            //imagez.setPixel(i,j, fuzzy);
                            imagez.setPixel(i,j, qRgb(255*(1-mu),255*mu,0));

            }
        }
    }

    if(ui->actionShow_Gridlines->isChecked()==TRUE)//Gridlines
    {

        for(int i=0;i<Ydim;i++)
        {
            imagez.setPixel(curX,i,qRgb(0, 0, 255) );
        }
        for(int i=0;i<Xdim;i++)
        {
            imagez.setPixel(i,curY,qRgb(255, 0, 0));
        }
    }
    ui->label_12->setNum(vol[curX][curY][curZ]);
    if(ui->actionSelect_a_region->isChecked())
    {
         if(recX>0&&recY>0&&recW>0&&recL>0)
          {
             for(int i=recY;i<=recY+recL;i++)
             {
                 if(i<Ydim)
                 {
                  imagez.setPixel(recX,i,qRgb(255,255,0));
                  if(recX+recW<Xdim)
                  imagez.setPixel(recX+recW,i,qRgb(255,255,0));
                 }
             }
             for(int i=recX;i<=recX+recW;i++)
             {
                 if(i<Xdim)
                 {
                    imagez.setPixel(i,recY,qRgb(255,255,0));
                    if(recY+recL<Ydim)
                    imagez.setPixel(i,recY+recL,qRgb(255,255,0));
                 }
             }
          }
     }
    ui->sliceLabel->setMinimumHeight(zoomscale*(Ydim-1));
    ui->sliceLabel->setMinimumWidth(zoomscale*(Xdim-1));
    ui->sliceLabel->setPixmap(QPixmap::fromImage(imagez).scaled(imagez.width()*zoomscale,imagez.height()*zoomscale));
}

void MainWindow::on_showOriginal_stateChanged(int arg1)
{
    if(ui->showOriginal->isChecked())
    {
        //ui->actionSelect_a_region->setChecked(Qt::Unchecked);
        zoomscale=1;
        ui->sliceLabel->resize(QSize(Xdim,Ydim));
        ui->spinBox_curX->setMaximum(Xdim-1);
        ui->spinBox_curY->setMaximum(Ydim-1);
        ui->spinBox_curZ->setMaximum(Zdim-1);
        curX=Xdim/2;
        curY=Ydim/2;
        curZ=Zdim/2;
        ui->scrollArea->horizontalScrollBar()->setEnabled(true);
        ui->scrollArea->verticalScrollBar()->setEnabled(true);
        draw_fullimage();
    }
    else
    {     

                curX=Xdim1/2;
                curY=Ydim1/2;
                curZ=Zdim1/2;
                ui->spinBox_curX->setMaximum(Xdim1-1);
                ui->spinBox_curY->setMaximum(Ydim1-1);
                ui->spinBox_curZ->setMaximum(Zdim1-1);
                ui->spinBox_curX->setValue(curX);
                ui->spinBox_curY->setValue(curY);
                ui->spinBox_curZ->setValue(curZ);
                int rn=ui->ROIList->currentRow()+1;
                if(listROI[rn].segment_flag)ui->actionMorphological_Reconstruction->setChecked(true);
                if(listROI[rn].analysis_flag)ui->actionShow_Segmented_Spine_Id->setChecked(true);
                draw_image();
     }
}

void MainWindow::on_actionScale_triggered()
{
     qDebug()<<"Inside action scale triggered";
     if(!ui->showOriginal->isChecked())return;
     double Zdimnew=Zdim*scaleValue;
     Zdim=round(Zdimnew);
     double sfx=1.0,sfy=1.0,sfz=1/scaleValue;
     scaling(sfx,sfy,sfz);
     free(output);
     free(vol);
     free(vol1);
     output=NULL;
     vol=NULL;
     vol1=NULL;
     output =(short ***)calloc(sizeof(short **) , Xdim);
     vol =(short ***)calloc(sizeof(short **) , Xdim);
     vol1 =(unsigned char ***)calloc(sizeof(unsigned char **) , Xdim);
     for (int i = 0 ;  i < Xdim; i++) {
         output[i]=(short **)calloc(sizeof(short *),Ydim);
         vol[i]=(short **)calloc(sizeof(short *),Ydim);
         vol1[i]=(unsigned char **)calloc(sizeof(unsigned char *),Ydim);
         for (int j = 0; j < Ydim; j++)
         {
             output[i][j]=(short *)calloc(sizeof(short),Zdim);
             vol[i][j]=(short *)calloc(sizeof(short),Zdim);
             vol1[i][j]=(unsigned char *)calloc(sizeof(unsigned char),Zdim);
         }
     }
     qDebug()<<"After memory allocation";
     for(int k=0;k<Zdim;k++)
     {
         for(int j=0;j<Ydim;j++)
         {
             for(int i=0;i<Xdim;i++)
             {
                vol[i][j][k]=temp[i][j][k];
                output[i][j][k]=temp[i][j][k];
             }
         }
     }
     free(temp);
     temp=NULL;
     ui->spinBox_curX->setMaximum(Xdim-1);
     ui->spinBox_curY->setMaximum(Ydim-1);
     ui->spinBox_curZ->setMaximum(Zdim-1);
     curX=Xdim/2;
     curY=Ydim/2;
     curZ=Zdim/2;
     ui->spinBox_curX->setValue(curX);
     ui->spinBox_curY->setValue(curY);
     ui->spinBox_curZ->setValue(curZ);
}

void MainWindow::scaling(double sfx,double sfy,double sfz)
{

    double px,py,pz;
    free(temp);
    temp=NULL;
    temp=(short ***)calloc(sizeof(short **),Xdim);
    for (int i = 0 ;  i < Xdim; i++) {
        temp[i]=(short **)calloc(sizeof(short *),Ydim);
        for (int j = 0; j < Ydim; j++)
            temp[i][j]=(short *)calloc(sizeof(short),Zdim);
    }
    qDebug()<<"Inside scaling computation";
    for(int k=0;k<Zdim;k++)
    {
        for(int j=0;j<Ydim;j++)
        {
            for(int i=0;i<Xdim;i++)
            {
               px=floor(i*sfx);
               py=floor(j*sfy);
               pz=floor(k*sfz);
               temp[i][j][k]=vol[(int)px][(int)py][(int)pz];
            }
        }
    }

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
//    if(start==0)return;
//    qDebug()<<"\n Mouse Double click event occurred";
//      if(ui->showOriginal->isChecked())
//      {
//          int x,y;
//          int q;
//          if(e->buttons()==Qt::RightButton)return;
//          q=(e->x()-ui->scrollArea->x()+ui->scrollArea->horizontalScrollBar()->value());
//          x=q-ui->sliceLabel->x()-1;
//          q=(e->y()-ui->scrollArea->y()-ui->mainToolBar->height()-ui->menuBar->height()+ui->scrollArea->verticalScrollBar()->value());
//          y=q-ui->sliceLabel->y()-1;
//          x=x/zoomscale;
//          y=y/zoomscale;
//          for(int i=1;i<=ROii)
//          {

//          }
//      }
}

void MainWindow::on_ROIList_itemDoubleClicked()
{
    if(start==0)return;
    if(ROIindex<=1)return;
    isprofileloaded=0;
    ui->actionShow_Segmented_Spine_Id->setChecked(false);
    ui->showOriginal->setCheckState(Qt::Unchecked);
    int rindex=ui->ROIList->currentIndex().row()+1;
    // qDebug()<<"Current ROI index="<<rindex;
     Xdim1=listROI[rindex].sizex;
     Ydim1=listROI[rindex].sizey;
     Zdim1=listROI[rindex].sizez;
     recX=listROI[rindex].recX;
     recY=listROI[rindex].recY;
     recL=listROI[rindex].recL;
     recW=listROI[rindex].recW;
     free(region);
     region=NULL;
     reset();
     allocate_memory();
     region=(short ***)calloc(sizeof(short **),Xdim1);
     for (int i = 0 ;  i < Xdim1; i++) {
         region[i]=(short **)calloc(sizeof(short *),Ydim1);
         for (int j = 0; j < Ydim1; j++)
             region[i][j]=(short *)calloc(sizeof(short),Zdim1);
     }

     for(int k=0;k<Zdim1;k++)
     {
         for(int j=0;j<Ydim1;j++)
         {
             for(int i=0;i<Xdim1;i++)
             {
                  region[i][j][k]=vol[i+recX][j+recY][k];
             }
         }
     }

     curX=Xdim1/2;
     curY=Ydim1/2;
     curZ=Zdim1/2;
     ui->spinBox_curX->setMaximum(Xdim1-1);
     ui->spinBox_curY->setMaximum(Ydim1-1);
     ui->spinBox_curZ->setMaximum(Zdim1-1);


     ui->spinBox_curX->setValue(curX);
     ui->spinBox_curY->setValue(curY);
     ui->spinBox_curZ->setValue(curZ);
     ui->spinBox_ta->setValue(listROI[rindex].ta);
     ui->spinBox_tb->setValue(listROI[rindex].tb);
     ui->spinBox_tbp->setValue(listROI[rindex].tbp);

   /*  for(int i=0;i<MAX;i++)
     {
         dspine[rindex].dssx[i]=0;
         dspine[rindex].dssy[i]=0;
         dspine[rindex].dssz[i]=0;
         den[rindex].dsx[i]=0;
         den[rindex].dsy[i]=0;
         den[rindex].dsz[i]=0;
         sep[rindex].sepx[i]=0;
         sep[rindex].sepy[i]=0;
         sep[rindex].sepz[i]=0;
         spine[i].seed.x=0;
         spine[i].seed.y=0;
         spine[i].seed.z=0;
     }

     dspID=1;dpID=1;sepID=1;pID=0;*/
     ui->pushButton_4->setEnabled(false);
     if(listROI[rindex].segment_flag)
     {
         zoomscale=1;

         on_pushButton_test_clicked();
//         for(int i=1;i<=listROI[rindex].iterate;i++)
//         {
//             on_pushButton_4_clicked();
//         }
     }
     if(listROI[rindex].segment_flag&&listROI[rindex].analysis_flag)
     {
         zoomscale=1;
         on_pushButton_CH_clicked();
     }
     zoomscale=1;
     draw_image();
}

//void MainWindow::on_actionSave_ROIProfile_triggered()
//{
//    if(start==0)return;
//    if(ui->showOriginal->isChecked())return;
//    FILE *fp;
//    char ROIname[100];
//    int rindex=ui->ROIList->currentRow()+1;
//    sprintf(ROIname,"ROI_%d_seedfile_",rindex);
//    QByteArray onlyfilename1=only_filename;
//    onlyfilename1.prepend(ROIname);
//    const char *seedfile=onlyfilename1.data();
//    QString savefilepath =  QFileDialog::getSaveFileName(this,"Save as",seedfile,"Text(*.txt)");
//    if(savefilepath==NULL)return;
//    QByteArray ba = savefilepath.toLatin1();
//    const char *name = ba.data();
//    fp=fopen(name,"w");
//    if(!fp)return;
//    totalseed=dspcount[rindex]+dcount[rindex]+sepcount[rindex]-3;
//    fprintf(fp,"%d %d %d\n",listROI[rindex].ta,listROI[rindex].tb,listROI[rindex].tbp);
//    fprintf(fp,"%d\n",totalseed);
//    for(int i=1;i<dspcount[rindex];i++)
//    {
//        fprintf(fp,"%d %d %d %d\n",dspine[i].dssx,dspine[i].dssy,dspine[i].dssz,0);
//    }

//    for(int i=1;i<dcount[rindex];i++)
//    {
//        fprintf(fp,"%d %d %d %d\n",den[i].dsx,den[i].dsy,den[i].dsz,1);
//    }

//    for(int i=1;i<sepcount[rindex];i++)
//    {
//        fprintf(fp,"%d %d %d %d\n",sep[i].sepx,sep[i].sepy,sep[i].sepz,2);
//    }
//    fclose(fp);
//}

void MainWindow::on_actionShow_Segmented_Spine_Id_triggered()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())return;
    draw_image();
}

void MainWindow::on_pushButton_4_clicked()
{
    listROI[ui->ROIList->currentRow()+1].iterate++;
    FCMR();
}

void MainWindow::on_actionSave_All_ROI_Profile_triggered()
{
    if(start==0)return;
    //if(!ui->showOriginal->isChecked())return;
    if(ROIindex<1)return;
    int rX,rY,rL,rW,sx,sy,sz,ta,tb,tbp;
    FILE *fp;
    char ROIname[100];
    QByteArray onlyfilename1=only_filename;
    onlyfilename1.prepend("ROI_");
    const char *seedfile=onlyfilename1.data();
    QString savefilepath =  QFileDialog::getSaveFileName(this,"Save as",seedfile,"Text(*.txt)");
    if(savefilepath==NULL)return;
    QByteArray ba = savefilepath.toLatin1();
    const char *name = ba.data();
    fp=fopen(name,"w");
    if(!fp)return;
    fprintf(fp,"%d\n",ROIindex);
    for(int i=1;i<=ROIindex;i++)
    {
         rX=listROI[i].recX;
         rY=listROI[i].recY;
         rL=listROI[i].recL;
         rW=listROI[i].recW;
         sx=listROI[i].sizex;
         sy=listROI[i].sizey;
         sz=listROI[i].sizez;
         ta=listROI[i].ta;
         tb=listROI[i].tb;
         tbp=listROI[i].tbp;
         fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",rX,rY,rL,rW,sx,sy,sz,ta,tb,tbp);
         fprintf(fp,"%d\n",dspcount[i]);
         for(int j=1;j<dspcount[i];j++)
         {
             fprintf(fp,"%d %d %d %d\n",dspine[i].dssx[j],dspine[i].dssy[j],dspine[i].dssz[j],0);
         }
         fprintf(fp,"%d\n",dcount[i]);
         for(int j=1;j<dcount[i];j++)
         {
             fprintf(fp,"%d %d %d %d\n",den[i].dsx[j],den[i].dsy[j],den[i].dsz[j],1);
         }
         fprintf(fp,"%d\n",sepcount[i]);
         for(int j=1;j<sepcount[i];j++)
         {
             fprintf(fp,"%d %d %d %d\n",sep[i].sepx[j],sep[i].sepy[j],sep[i].sepz[j],2);
         }
    }

    fclose(fp);
}

void MainWindow::on_actionLoad_All_ROI_Profile_triggered()
{
    if(start==0)return;

    if(!ui->showOriginal->isChecked())
    {
        return;
    }
    isprofileloaded++;
    if(!ispreprocessed)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("3dSpAn");
        msgBox.setText("First preprocess the image");
        msgBox.exec();
        return;
    }
    QString temp;
    QByteArray seedfilename;
    FILE *fp;
    int rx,ry,rL,rW,sx,sy,sz,ta,tb,tbp,type=-1;
    char ROIname[100];
    temp=QFileDialog::getOpenFileName(this,tr("Open File"), " ",
                                      tr("Text(*.txt)"));
    if(QString::compare(temp,QString())==0)return;
    QByteArray qb = temp.toLatin1();
    seedfilename =  qb.data();
    fp=fopen(seedfilename,"r");
    if(!fp)return;
    int i=1;
    fscanf(fp,"%d",&ROIindex);
    qDebug()<<ROIindex;
    for(int slice=0;slice<Zdim;slice++)
    {
        for(int row=0;row<Ydim;row++)
        {
            for(int col=0;col<Xdim;col++)
            {
                vol1[col][row][slice]=0;
            }
        }
    }

    while(i<=ROIindex)
    {
        fscanf(fp,"%d%d%d%d%d%d%d%d%d%d",&rx,&ry,&rL,&rW,&sx,&sy,&sz,&ta,&tb,&tbp);
        qDebug()<<rx<<" "<<ry<<" "<<rL<<" "<<rW<<" "<<sx<<" "<<sy<<" "<<sz<<" "<<ta<<" "<<tb<<" "<<tbp<<"\n";
        listROI[i].recL=rL;
        listROI[i].recW=rW;
        listROI[i].recX=rx;
        listROI[i].recY=ry;
        listROI[i].sizex=sx;
        listROI[i].sizey=sy;
        listROI[i].sizez=sz;
        listROI[i].ta=ta;
        listROI[i].tb=tb;
        listROI[i].tbp=tbp;
        fscanf(fp,"%d",&dspcount[i]);
        qDebug()<<dspcount[i]<<"\n";
        for(int j=1;j<dspcount[i];j++)
        {
            fscanf(fp,"%d%d%d%d",&dspine[i].dssx[j],&dspine[i].dssy[j],&dspine[i].dssz[j],&type);

        }
        fscanf(fp,"%d",&dcount[i]);
        for(int j=1;j<dcount[i];j++)
        {
            fscanf(fp,"%d%d%d%d",&den[i].dsx[j],&den[i].dsy[j],&den[i].dsz[j],&type);

        }
        fscanf(fp,"%d",&sepcount[i]);
        for(int j=1;j<sepcount[i];j++)
        {
            fscanf(fp,"%d%d%d%d",&sep[i].sepx[j],&sep[i].sepy[j],&sep[i].sepz[j],&type);

        }

        for(int slice=0;slice<Zdim;slice++)
        {
            for(int row=ry;row<=ry+rL;row++)
            {
                 vol1[rx][row][slice]=200;
                 vol1[rx+rW][row][slice]=200;
            }
            for(int col=rx;col<=rx+rW;col++)
            {
                 vol1[col][ry][slice]=200;
                 vol1[col][ry+rL][slice]=200;
            }
        }
        i++;
    }
    qDebug()<<"\n Inside All ROI_Profile--<<"<<i;
    fclose(fp);
    draw_fullimage();
   for(int i=1;i<=ROIindex;i++)
    {
      sprintf(ROIname,"ROI_%d",i);
      ui->ROIList->addItem(ROIname);
    }
    ui->showOriginal->setEnabled(true);
    Xdim1=listROI[1].sizex;
    Ydim1=listROI[1].sizey;
    Zdim1=listROI[1].sizez;
    recX=listROI[1].recX;
    recY=listROI[1].recY;
    free(region);
    region= (short ***)calloc(sizeof(short **),Xdim1);
    for (int i =0;i<Xdim1;i++) {
        region[i] = (short **)calloc(sizeof(short *),Ydim1);
        for (int j = 0; j < Ydim1; j++)
            region[i][j] = (short *)calloc(sizeof(short),Zdim1);
    }

   for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
                   region[i][j][k]=vol[i+recX][j+recY][k];
            }
        }
    }
   reset();
   allocate_memory();
   ui->ROIList->item(0)->setSelected(true);
   ui->ROIList->setCurrentRow(0);
   ui->ROIList->setFocus();
    /*ui->spinBox_curX->setMaximum(Xdim1-1);
    ui->spinBox_curY->setMaximum(Ydim1-1);
    ui->spinBox_curZ->setMaximum(Zdim1-1);
    curX=Xdim1/2;
    curY=Ydim1/2;
    curZ=Zdim1/2;*/

}

void MainWindow::on_selectRegion_stateChanged(int arg1)
{
    if(start==0)return;
    if(ui->selectRegion->isChecked())
    {
        ui->actionSelect_a_region->setChecked(true);
    }
    else
    {
        ui->actionSelect_a_region->setChecked(false);
        on_actionSelect_a_region_triggered();
    }
}

void MainWindow::lowadaptivethreshold()
{
    double mean=0,var=0;
    double sd;
    int th;
    for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
                 mean=mean+region[i][j][k];
            }
        }
    }

    mean=mean/(double)(Xdim1*Ydim1*Zdim1);
    for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
                 var=var+(mean-region[i][j][k])*(mean-region[i][j][k]);
            }
        }
    }
    var=var/(double)(Xdim1*Ydim1*Zdim1);
    sd=sqrt(var);
    th=(int)(round(mean+sd));
    ui->spinBox_ta->setValue(th);
}

void MainWindow::hiadaptivethreshold()
{
    int max=0,th;
    for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
                 if(region[i][j][k]>max)max=region[i][j][k];
            }
        }
    }

    th=(ui->spinBox_ta->value()+max)/2.0;
    th=(int)round(th);
    ui->spinBox_tb->setValue(th);
}

void MainWindow::on_pushButton_clicked()
{
    if(start==0)return;
    char ch[20];
    int rn=ui->ROIno->text().toInt();
    if(rn>ROIindex||rn==0)return;
    ui->actionShow_Segmented_Spine_Id->setChecked(false);
    if(ROIindex==1)
    {
        start=1;
        int rx=listROI[rn].recX;
        int ry=listROI[rn].recY;
        int x=listROI[rn].sizex;
        int y=listROI[rn].sizey;
        int z=Zdim1;
        for(int i=1;i<=ROIindex;i++)
           {
               segspcount[i]=0;
               dspcount[i]=1;
               dcount[i]=1;
               sepcount[i]=1;
               dspID=1;
               for(int j=0;j<MAX;j++)
               {
                   dspine[i].dssx[j]=0;
                   dspine[i].dssy[j]=0;
                   dspine[i].dssz[j]=0;
                   den[i].dsx[j]=0;
                   den[i].dsy[j]=0;
                   den[i].dsz[j]=0;
                   sep[i].sepx[j]=0;
                   sep[i].sepy[j]=0;
                   sep[i].sepz[j]=0;
               }
               listROI[i].analysis_flag=0;
               listROI[i].segment_flag=0;
           }
           free(region);
           region=NULL;
           reset();
           for(int k=0;k<z;k++)
           {
               for(int j=0;j<y;j++)
               {
                   for(int i=0;i<x;i++)
                   {
                       vol1[i+rx][j+ry][k]=0;
                       output[i+rx][j+ry][k]=vol[i+rx][j+ry][k];
                   }
               }
           }
           ROIindex=0;
           ui->ROIList->model()->removeRow(0);
           ui->showOriginal->setEnabled(false);
           ui->showOriginal->setCheckState(Qt::Checked);
           return;
    }
    int rx=listROI[rn].recX;
    int ry=listROI[rn].recY;
    int x=listROI[rn].sizex;
    int y=listROI[rn].sizey;
    int z=Zdim1;
    for(int k=0;k<z;k++)
    {
        for(int j=0;j<y;j++)
        {
            for(int i=0;i<x;i++)
            {
                vol1[i+rx][j+ry][k]=0;
            }
        }
    }

    for(int i=rn;i<ROIindex;i++)
    {

        listROI[i]=listROI[i+1];
        //spcount[i]=spcount[i+1];
         //sprintf(ch,"ROI_%d",i);
         //ui->ROIList->item(rn)->setText(ch);
        dspine[i]=dspine[i+1];
        den[i]=den[i+1];
        sep[i]=sep[i+1];
        dspcount[i]=dspcount[i+1];
        dcount[i]=dcount[i+1];
        sepcount[i]=sepcount[i+1];
        segspcount[i]=segspcount[i+1];
    }

    ui->ROIList->model()->removeRow(rn-1);
    ROIindex--;
    for(int i=1;i<=ROIindex;i++)
    {
        sprintf(ch,"ROI_%d",i);
        ui->ROIList->item(i-1)->setText(ch);
    }

    free(region);
    ui->ROIList->item(0)->setSelected(true);
    ui->ROIList->setCurrentRow(0);
    ui->ROIList->setFocus();
    Xdim1=listROI[1].sizex;
    Ydim1=listROI[1].sizey;
    Zdim1=Zdim;
    curX=Xdim1/2;
    curY=Ydim1/2;
    curZ=Zdim1/2;
    recX=listROI[1].recX;
    recY=listROI[1].recY;
    recL=listROI[1].recL;
    recW=listROI[1].recW;
    int ta=listROI[1].ta;
    int tb=listROI[1].tb;
    int tbp=listROI[1].tbp;
    region= (short ***)calloc(sizeof(short **),Xdim1);
    for (int i =0;i<Xdim1;i++) {
        region[i] = (short **)calloc(sizeof(short *),Ydim1);
        for (int j = 0; j < Ydim1; j++)
            region[i][j] = (short *)calloc(sizeof(short),Zdim1);
    }

    for(int k=0;k<Zdim1;k++)
    {
        for(int j=0;j<Ydim1;j++)
        {
            for(int i=0;i<Xdim1;i++)
            {
                   region[i][j][k]=vol[i+recX][j+recY][k];
            }
        }
    }
    reset();
    allocate_memory();
    ui->spinBox_ta->setValue(ta);
    ui->spinBox_tb->setValue(tb);
    ui->spinBox_tbp->setValue(tbp);
    ui->spinBox_curX->setValue(curX);
    ui->spinBox_curY->setValue(curY);
    ui->spinBox_curZ->setValue(curZ);
    ui->actionShow_Segmented_Spine_Id->setChecked(false);

}

void MainWindow::on_actionMorphological_Reconstruction_triggered()
{
    if(start==0)return;
    if(ui->showOriginal->isChecked())return;
    draw_image();
}

void MainWindow::getScaleAndKernelSize(double scale, int kernelVal)
{   opSuccessful = true;
    scaleValue = scale;
    kernelSize = kernelVal;
}

void MainWindow::scalingChoseOperationCanceled()
{
    opCancelled = true;
}
