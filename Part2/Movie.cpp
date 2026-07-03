#include "Movie.h"
#include <cstring>

Movie::Movie(const char* title, const Date& premiereDate, int lengthMinutes, bool is3D)
    : premiereDate(premiereDate), lengthMinutes(lengthMinutes), is3D(is3D) {
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

Movie::Movie(const Movie& other)
    : premiereDate(other.premiereDate), lengthMinutes(other.lengthMinutes), is3D(other.is3D) {
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);
}

Movie::Movie(Movie&& other) noexcept
    : title(other.title),
      premiereDate(other.premiereDate),
      lengthMinutes(other.lengthMinutes),
      is3D(other.is3D) {
    other.title = nullptr;
}

Movie& Movie::operator=(const Movie& other) {
    if (this != &other) {
        delete[] title;
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        premiereDate  = other.premiereDate;
        lengthMinutes = other.lengthMinutes;
        is3D          = other.is3D;
    }
    return *this;
}

Movie::~Movie() {
    delete[] title;
}

const char* Movie::getTitle()         const { return title;         }
const Date& Movie::getPremiereDate()  const { return premiereDate;  }
int         Movie::getLengthMinutes() const { return lengthMinutes; }
bool        Movie::getIs3D()          const { return is3D;          }

void Movie::setTitle(const char* newTitle) {
    delete[] title;
    title = new char[strlen(newTitle) + 1];
    strcpy(title, newTitle);
}
void Movie::setLengthMinutes(int minutes) { lengthMinutes = minutes; }
void Movie::setIs3D(bool flag)            { is3D = flag;             }

std::ostream& operator<<(std::ostream& os, const Movie& m) {
    os << "Title: "     << m.title
       << " | Date: "   << m.premiereDate
       << " | Length: " << m.lengthMinutes << " min"
       << " | 3D: "     << (m.is3D ? "Yes" : "No");
    return os;
}
