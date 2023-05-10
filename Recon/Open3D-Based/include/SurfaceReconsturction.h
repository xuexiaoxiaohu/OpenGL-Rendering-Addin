#ifndef SURFACERECONSTURCTION_H
#define SURFACERECONSTURCTION_H

//#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "math.h"
#include <QFile>
#include <QFileDialog>

#include "surfaceConsturction_global.h"


//点的类型的头文件
#include <pcl/point_types.h>
//点云文件IO（pcd文件和ply文件）
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
//kd树
#include <pcl/kdtree/kdtree_flann.h>
//特征提取
#include <pcl/features/normal_3d_omp.h>
#include <pcl/features/normal_3d.h>
//重构
#include <pcl/surface/gp3.h>
#include <pcl/surface/poisson.h>
//可视化
#include <pcl/visualization/pcl_visualizer.h>
//多线程
#include <boost/thread/thread.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/crop_box.h>
#include <pcl/common/geometry.h>
#include <pcl/common/common.h>


#include <pcl/surface/concave_hull.h>
#include <pcl/surface/convex_hull.h>
#include <pcl/conversions.h>

using namespace pcl;
using namespace std;




#include <QVector3D>
#include <iostream>
#include <fstream>
#include <vector>

#define FAILURE_XYZ			-1
#define FAILURE_NORM		-2
#define FAILURE_RGB			-3
#define FAILUTE_FUNCTION	-4

#define BUFFER_MAX_SIZE		1000
#define BUFFER_SIZE			300

#define  Paratmeter           5

struct MeshModelData
{
    std::vector<float> vecTemPoints;
    std::vector<float> vecPoints;
    std::vector<float> vecFaceTriangles;
    std::vector<float> vecFaceTriangleColors;
    std::vector<float> vecNormals;
};



struct Node
{
    double x;
    double y;
    double z;
  //  float i;
  //  float j;
  //  float k;
};


class SURFACECONSTURCTION_EXPORT SurfaceReconsturction
{
public:

    SurfaceReconsturction();//(std::vector<QVector3D> pointData);

  void construction(std::vector<QVector3D> pointData);

public:
  pcl::PolygonMesh mesh ;

//  PointCloud<Normal>::Ptr cloud_normals ;//(new (PointCloud<Normal>()));

  std::vector<QVector3D>cloudNormal;

  ~SurfaceReconsturction(){};


public:
    //--------------------------------
        //		 PointCloud
        // -------------------------------
        //
        // Read the point cloud data from the fileand map it proportionally
        // to the range of - 1.0 -- 1.0.
        bool PointCloudRead(const char* path);
        // Normalize point cloud data, and map to the range of - 1.0 -- 1.0
        void PointCloudHandlePointDate(std::vector<QVector3D> data);
        // The maximum values of x, y and z are calculated respectively
        // and combined into a point.
        void PointCloudGetMaxCoordinate();
        // The minimum values of x, y and z are calculated respectively
        // and combined into a point.
        void PointCloudGetMinCoordinate();
        // Get center point
        void PointCloudGetCenterPoint(QVector3D& vec);
        //
        float PointCloudGetFactor();
        //max coordinate of point cloud data.
        QVector3D pointCloudMaxCoordinate;
        //min coordinate of point cloud data.
        QVector3D pointCloudMinCoordinate;
        //point cloud data.
        std::vector<QVector3D> pointData;

        //--------------------------------
        //		 Mesh
        // -------------------------------
        // load mesh
        int LoadMeshData(char* filename);
        // coordinate of vertex
        float* meshVertexXYZ;
        // normal of vertex
        float* meshVertexNorm;
        // color of vertex
        float* meshVertexRGB;
        //total vertex
        int meshTotalConnectedPoints;
        //total faces of mesh
        int meshTotalFaces;
        //mesh model
        MeshModelData meshModelData;
        // The index of Vertex
        std::vector<int> meshVecFaceIndex;




};

#endif // SURFACERECONSTURCTION_H
