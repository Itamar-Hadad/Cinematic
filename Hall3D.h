#ifndef HALL3D_H
#define HALL3D_H

#include "Hall.h"

class Hall3D : virtual public Hall {
private:
    int glassesCount;

public:
    Hall3D(int hallNumber, const Movie& currentMovie, int glassesCount);
    Hall3D(const Hall3D& other) = delete;
    Hall3D& operator=(const Hall3D& other) = delete;
    ~Hall3D() override = default;

    int  getGlassesCount() const override;
    void setGlassesCount(int c);
    void addGlasses(int amount) override;
    void useGlass() override;

    bool isHall3D()      const override;
    void printHall()     const override;
};

#endif
