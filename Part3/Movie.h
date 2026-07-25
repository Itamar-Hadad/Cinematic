#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "Date.h"

class Movie {
private:
    std::string title;
    Date premiereDate;
    int lengthMinutes;
    bool is3D;

public:
    Movie(const std::string& title, const Date& premiereDate, int lengthMinutes, bool is3D);
    Movie(const Movie& other)            = default;
    Movie(Movie&& other) noexcept        = default;
    Movie& operator=(const Movie& other) = default;
    Movie& operator=(Movie&& other) noexcept = default;
    ~Movie()                             = default;

    const std::string& getTitle() const;
    const Date& getPremiereDate() const;
    int getLengthMinutes() const;
    bool getIs3D() const;

    void setTitle(const std::string& newTitle);
    void setLengthMinutes(int minutes);
    void setIs3D(bool flag);

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
};

#endif
