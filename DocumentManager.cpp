#include "DocumentManager.h"

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    Document doc{name, id, license_limit, 0, {}};
    documents[id] = doc;
    name_to_id[name] = id;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) const {
    auto it = name_to_id.find(name);
    return (it != name_to_id.end()) ? it->second : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) return false;

    auto it = documents.find(docid);
    if (it == documents.end()) return false;

    Document& doc = it->second;

    if (doc.borrowed_count >= doc.license_limit) return false;

    if (doc.borrowers.find(patronID) != doc.borrowers.end()) return false;

    doc.borrowed_count++;
    doc.borrowers.insert(patronID);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto it = documents.find(docid);
    if (it == documents.end()) return;

    Document& doc = it->second;

    if (doc.borrowers.erase(patronID)) {
        if (doc.borrowed_count > 0)
            doc.borrowed_count--;
    }
}
