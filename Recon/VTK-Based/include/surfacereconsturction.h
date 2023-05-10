#ifndef SURFACERECONSTURCTION_H
#define SURFACERECONSTURCTION_H


#include "SurfaceReconsturction_global.h"

#include <QVector>
#include <QVector3D>
using namespace std;



class SURFACERECONSTURCTION_EXPORT SurfaceReconsturction
{
public:

    SurfaceReconsturction();

    void construction(std::vector<QVector3D> pointData);
   // vtkNew<vtkPolyData> polyData;
   // vtkNew<vtkPoints> points;
     QVector3D data;

public:

  //  vtkNew<vtkPolyDataWriter> writer;

    std::vector<QVector3D> originalCellNumber;
    std::vector<QVector3D> originalPointData;

    ~SurfaceReconsturction();
};

#endif // SURFACERECONSTURCTION_H
