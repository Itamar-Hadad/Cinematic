#include "Movie.h"

Movie::Movie(const std::string& title, const Date& premiereDate, int lengthMinutes, bool is3D)
    : title(title), premiereDate(premiereDate), lengthMinutes(lengthMinutes), is3D(is3D) {}

const std::string& Movie::getTitle() const
{
    return title;
}

const Date& Movie::getPremiereDate() const
{
    return premiereDate;
}

int Movie::getLengthMinutes() const
{
    return lengthMinutes;
}

bool Movie::getIs3D() const
{
    return is3D;
}

void Movie::setTitle(const std::string& newTitle)
{
    title = newTitle;
}

void Movie::setLengthMinutes(int minutes)
{
    lengthMinutes = minutes;
}

void Movie::setIs3D(bool flag)
{
    is3D = flag;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << "Title: "     << movie.title
       << " | Date: "   << movie.premiereDate
       << " | Length: " << movie.lengthMinutes << " min"
       << " | 3D: "     << (movie.is3D ? "Yes" : "No");
    return os;
}
