#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

struct Document {
    std::string name;
    int id;
    int license_limit;
    int borrowed_count = 0;
    std::unordered_set<int> borrowers;
};

class DocumentManager {
private:
    std::unordered_map<std::string, int> name_to_id;
    std::unordered_map<int, Document> documents;
    std::unordered_set<int> patrons;

public:
    void addDocument(const std::string& name, int id, int license_limit);

    void addPatron(int patronID);

    int search(const std::string& name) const;

    bool borrowDocument(int docid, int patronID);

    void returnDocument(int docid, int patronID);
};

#endif
