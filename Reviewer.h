#ifndef REVIEWER_H
#define REVIEWER_H

#include "Guest.h"
#include <string>

class Reviewer : public Guest {
private:
    std::string publicationName;

public:
    Reviewer(const std::string& name, int id, const std::string& publicationName, int visitCount = 0);
    Reviewer(const Reviewer& other) = delete;
    Reviewer& operator=(const Reviewer& other) = delete;
    ~Reviewer() override = default;

    const std::string& getPublicationName() const;
    void setPublicationName(const std::string& name);

    void printDetails() const override;
};

#endif
