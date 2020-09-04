#ifndef GLOBAL_H
#define GLOBAL_H

#define R2 1.41
#define R3 1.73
#define MAX 100//maximum nummber of spines in an image
#define MaxSeed 500
int isprofileloaded=0,ispreprocessed=0;
int sid=0,dspcount[100],dcount[100],sepcount[100],segspcount[100];
int maxInt=9999;
int start=0,totalseed=0;
short ***vol,***region,***temp,***output;
unsigned char ***vol1;
unsigned char ***SS;
unsigned char ***GT;
unsigned char ***NML;

unsigned short ***FDT;
unsigned short ***FDTv;
unsigned short ***FDTb;
unsigned short ***tFDT;

unsigned long ***LM;

unsigned short ***FCv;
unsigned short ***FCb;
unsigned short ***brightness;

 short ***MRv;
 short ***MRb;
 unsigned short ***out, ***img;

 int ***DT, ***DT1, ***DT2,zoomscale=1;

 void *hdr;

 unsigned short sM, sN, sD;


float D[26] =
        {R3,R2,R3,
         R2,1 ,R2,
         R3,R2,R3,

         R2,1 ,R2,
         1 ,   1 ,
         R2,1 ,R2,

         R3,R2,R3,
         R2,1 ,R2,
         R3,R2,R3};

short V[26][3] =
        {{-1,-1,-1},{ 0,-1,-1},{+1,-1,-1},
         {-1, 0,-1},{ 0, 0,-1},{+1, 0,-1},
         {-1,+1,-1},{ 0,+1,-1},{+1,+1,-1},

         {-1,-1, 0},{ 0,-1, 0},{+1,-1, 0},
         {-1, 0, 0},           {+1, 0, 0},
         {-1,+1, 0},{ 0,+1, 0},{+1,+1, 0},

         {-1,-1,+1},{ 0,-1,+1},{+1,-1,+1},
         {-1, 0,+1},{ 0, 0,+1},{+1, 0,+1},
         {-1,+1,+1},{ 0,+1,+1},{+1,+1,+1}};


struct points{
    unsigned short x;
    unsigned short y;
    unsigned short z;
};
typedef struct points point;

struct pointlist{
    point p;
    struct pointlist *next;
};

typedef struct pointlist vSeed;
vSeed *vShead;



struct spine_struct
{
    unsigned short spine_flag;
    unsigned int sp_id,pCGx,pCGy,pCGz,pArea,bCGx,bCGy,bCGz,bCnt;
    point seed;
    unsigned short seedX,seedY,x1,y1,z1,x2,y2,z2,xdim,ydim,zdim,headX,headY,headZ,majA,minA;
    unsigned char **data,type;
    float length, headW,headWmax, neck_length,avg_neckW,min_neckW,tA;

};
struct spine_struct spine[MAX];
int pID=0,dspID=1;
unsigned int trace_cnt,v_neck_cnt;

struct denspine_struct
{
    int dssx[MaxSeed],dssy[MaxSeed],dssz[MaxSeed];
};

struct denspine_struct dspine[MAX];

struct dendrite_struct
{
    int dsx[MaxSeed],dsy[MaxSeed],dsz[MaxSeed];
};

struct dendrite_struct den[MAX];

struct separator_struct
{
    int sepx[MaxSeed],sepy[MaxSeed],sepz[MaxSeed];
};

struct separator_struct sep[MAX];

unsigned short readShort(FILE *);
//void reset();
#endif // GLOBAL_H
