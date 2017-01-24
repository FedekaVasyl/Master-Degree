#ifndef COVERAGEAREA_H
#define COVERAGEAREA_H

#include <QObject>
#include <QWidget>

class CoverageArea : public QObject
{
    Q_OBJECT
signals:
    void Draw();
public:
    CoverageArea();
    virtual ~CoverageArea() {};
    int GetWidth() const;
    int GetHeight() const;
    void SetWidth(int _width);
    void SetHeight(int _height);
private:
    int width;
    int height;
};

#endif // COVERAGEAREA_H
