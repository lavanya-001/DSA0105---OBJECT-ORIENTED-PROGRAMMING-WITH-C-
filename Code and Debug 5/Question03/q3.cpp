#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseError : public exception {
protected:
    string errorDetails;

public:
    DatabaseError(string msg) : errorDetails(msg) {}

    const char* what() const noexcept override {
        return errorDetails.c_str();
    }
};

class TimeoutError : public DatabaseError {
public:
    int timeoutMs;

    TimeoutError(string msg, int ms)
        : DatabaseError(msg), timeoutMs(ms) {}
};

void executeQuery() {
    throw TimeoutError(
        "Query timed out connecting to shard 3", 5000
    );
}

void intermediateAuditor() {
    try {
        executeQuery();
    }
    catch (const DatabaseError& e) {
        cout << "[AUDIT LOG]: Intercepted DB error."
             << endl;

        throw;  // Correct rethrow
    }
}

int main() {
    try {
        intermediateAuditor();
    }
    catch (const TimeoutError& te) {
        cout << "Client caught TimeoutError! Duration: "
             << te.timeoutMs << " ms" << endl;
    }
    catch (const DatabaseError& de) {
        cout << "Client caught generic DatabaseError: "
             << de.what() << endl;
    }

    return 0;
}
